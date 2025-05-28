#include <stdafx.h>
#include "mutant.h"


uint32_t reblue::kernel::Mutant::Wait(uint32_t timeout)
{
    uint32_t currentThread = g_ppcContext->r13.u32;

    if (timeout == 0)
    {
        uint32_t owner = owningThread.load();
        if (owner == 0)
        {
            if (owningThread.compare_exchange_strong(owner, currentThread))
            {
                recursionCount = 1;
                bool wasAbandoned = abandoned.exchange(false);
                return wasAbandoned ? STATUS_ABANDONED_WAIT_0 : STATUS_SUCCESS;
            }
        }
        else if (owner == currentThread)
        {
            recursionCount++;
            return STATUS_SUCCESS;
        }
        return STATUS_TIMEOUT;
    }
    else if (timeout == INFINITE)
    {
        while (true)
        {
            uint32_t owner = owningThread.load();
            if (owner == 0)
            {
                if (owningThread.compare_exchange_weak(owner, currentThread))
                {
                    recursionCount = 1;
                    bool wasAbandoned = abandoned.exchange(false);
                    return wasAbandoned ? STATUS_ABANDONED_WAIT_0 : STATUS_SUCCESS;
                }
            }
            else if (owner == currentThread)
            {
                recursionCount++;
                return STATUS_SUCCESS;
            }
            else
            {
                owningThread.wait(owner);
            }
        }
    }
    else
    {
        std::unique_lock<std::mutex> lock(mutex);

        if (!cv.wait_for(lock, std::chrono::milliseconds(timeout), [this, currentThread] {
            uint32_t owner = owningThread.load();
            if (owner == 0)
            {
                if (owningThread.compare_exchange_weak(owner, currentThread))
                {
                    recursionCount = 1;
                    return true;
                }
            }
            else if (owner == currentThread)
            {
                recursionCount++;
                return true;
            }
            return false;
            }))
            return STATUS_TIMEOUT;

        bool wasAbandoned = abandoned.exchange(false);
        return wasAbandoned ? STATUS_ABANDONED_WAIT_0 : STATUS_SUCCESS;
    }
}

uint32_t reblue::kernel::Mutant::Release()
{
    uint32_t currentThread = g_ppcContext->r13.u32;
    uint32_t owner = owningThread.load();

    if (owner != currentThread)
    {
        return STATUS_MUTANT_NOT_OWNED;
    }

    uint32_t count = --recursionCount;
    if (count == 0)
    {
        {
            std::lock_guard<std::mutex> lock(mutex);
            owningThread = 0;
        }
        cv.notify_one();
        owningThread.notify_one();
    }

    return STATUS_SUCCESS;
}

void reblue::kernel::Mutant::Abandon()
{
    {
        std::lock_guard<std::mutex> lock(mutex);
        abandoned = true;
        recursionCount = 0;
        owningThread = 0;
    }
    cv.notify_all();
    owningThread.notify_all();
}

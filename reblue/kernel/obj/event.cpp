#include <stdafx.h>
#include "event.h"

uint32_t reblue::kernel::Event::Wait(uint32_t timeout)
{
    if (timeout == 0)
    {
        if (manualReset)
        {
            if (!signaled)
                return STATUS_TIMEOUT;
        }
        else
        {
            bool expected = true;
            if (!signaled.compare_exchange_strong(expected, false))
                return STATUS_TIMEOUT;
        }
    }
    else if (timeout == INFINITE)
    {
        if (manualReset)
        {
            signaled.wait(false);
        }
        else
        {
            while (true)
            {
                bool expected = true;
                if (signaled.compare_exchange_weak(expected, false))
                    break;

                signaled.wait(expected);
            }
        }
    }
    else
    {
        std::unique_lock<std::mutex> lock(mutex);
        if (manualReset)
        {
            if (!cv.wait_for(lock, std::chrono::milliseconds(timeout), [this] { return signaled.load(); }))
                return STATUS_TIMEOUT;
        }
        else
        {
            if (!cv.wait_for(lock, std::chrono::milliseconds(timeout), [this] {
                bool expected = true;
                return signaled.compare_exchange_strong(expected, false);
                }))
                return STATUS_TIMEOUT;
        }
    }

    return STATUS_SUCCESS;
}

bool reblue::kernel::Event::Set()
{
    {
        std::lock_guard<std::mutex> lock(mutex);
        signaled = true;
    }

    cv.notify_all();

    if (manualReset)
        signaled.notify_all();
    else
        signaled.notify_one();

    return TRUE;
}

bool reblue::kernel::Event::Reset()
{
    std::lock_guard<std::mutex> lock(mutex);
    signaled = false;
    return TRUE;
}

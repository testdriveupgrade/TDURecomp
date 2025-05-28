#include <stdafx.h>
#include "semaphore.h"

uint32_t reblue::kernel::Semaphore::Wait(uint32_t timeout)
{
    if (timeout == 0)
    {
        uint32_t currentCount = count.load();
        if (currentCount != 0)
        {
            if (count.compare_exchange_weak(currentCount, currentCount - 1))
                return STATUS_SUCCESS;
        }

        return STATUS_TIMEOUT;
    }
    else if (timeout == INFINITE)
    {
        uint32_t currentCount;
        while (true)
        {
            currentCount = count.load();
            if (currentCount != 0)
            {
                if (count.compare_exchange_weak(currentCount, currentCount - 1))
                    return STATUS_SUCCESS;
            }
            else
            {
                count.wait(0);
            }
        }

        return STATUS_SUCCESS;
    }
    else
    {
        std::unique_lock<std::mutex> lock(mutex);

        if (!cv.wait_for(lock, std::chrono::milliseconds(timeout), [this] {
            uint32_t currentCount = count.load();
            if (currentCount != 0)
            {
                if (count.compare_exchange_weak(currentCount, currentCount - 1))
                    return true;
            }
            return false;
            }))
            return STATUS_TIMEOUT;

        return STATUS_SUCCESS;
    }
}

void reblue::kernel::Semaphore::Release(uint32_t releaseCount, uint32_t* previousCount)
{
    if (previousCount != nullptr)
        *previousCount = count;

    assert(count + releaseCount <= maximumCount);

    {
        std::lock_guard<std::mutex> lock(mutex);
        count += releaseCount;
    }

    cv.notify_all();
    count.notify_all();
}

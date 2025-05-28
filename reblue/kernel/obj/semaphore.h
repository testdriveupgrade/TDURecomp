#pragma once
#include <kernel/obj/kernel_object.h>

namespace reblue {
namespace kernel {
    struct Semaphore final : KernelObject, HostObject<XKSEMAPHORE>
    {
        std::atomic<uint32_t> count;
        uint32_t maximumCount;
        std::mutex mutex;
        std::condition_variable cv;

        Semaphore(XKSEMAPHORE* semaphore)
            : count(semaphore->Header.SignalState), maximumCount(semaphore->Limit)
        {
        }

        Semaphore(uint32_t count, uint32_t maximumCount)
            : count(count), maximumCount(maximumCount)
        {
        }

        uint32_t Wait(uint32_t timeout) override;

        void Release(uint32_t releaseCount, uint32_t* previousCount);
    };
}
}

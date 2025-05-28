#pragma once

#include <kernel/obj/kernel_object.h>
namespace reblue {
    namespace kernel {
    struct Event final : KernelObject, HostObject<XKEVENT>
    {
        bool manualReset;
        std::atomic<bool> signaled;
        std::mutex mutex;
        std::condition_variable cv;

        Event(XKEVENT* header)
            : manualReset(!header->Type), signaled(!!header->SignalState)
        {
        }

        Event(bool manualReset, bool initialState)
            : manualReset(manualReset), signaled(initialState)
        {
        }

        uint32_t Wait(uint32_t timeout) override;

        bool Set();

        bool Reset();
    };
}
}

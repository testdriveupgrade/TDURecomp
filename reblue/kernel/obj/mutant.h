#pragma once
#include <kernel/obj/kernel_object.h>
#include <cpu/ppc_context.h>

#ifdef _WIN32
#include <ntstatus.h>
#endif

namespace reblue {
namespace kernel {
    struct XKMUTANT
    {
        XDISPATCHER_HEADER Header;
    };
    struct Mutant final : KernelObject, HostObject<XKMUTANT>
    {
        std::atomic<uint32_t> owningThread;
        std::atomic<uint32_t> recursionCount;
        std::atomic<bool> abandoned;
        std::mutex mutex;
        std::condition_variable cv;

        Mutant(XKMUTANT* mutant)
            : owningThread(mutant->Header.SignalState ? 0 : g_ppcContext->r13.u32),
            recursionCount(mutant->Header.SignalState ? 0 : 1),
            abandoned(false)
        {
        }

        Mutant(bool initialOwner)
            : owningThread(initialOwner ? g_ppcContext->r13.u32 : 0),
            recursionCount(initialOwner ? 1 : 0),
            abandoned(false)
        {
        }

        uint32_t Wait(uint32_t timeout) override;

        uint32_t Release();

        void Abandon();
    };
}
}

#include <stdafx.h>
#include "guest_heap.h"
#include <kernel/function.h>
#include <kernel/obj/guest_memory.h>

constexpr size_t RESERVED_BEGIN = 0x7FEA0000;
constexpr size_t RESERVED_END = 0xA0000000;

using namespace reblue::kernel;

void GuestHeap::Init()
{
    heap = o1heapInit(g_memory.Translate(0x20000), RESERVED_BEGIN - 0x20000);
    physicalHeap = o1heapInit(g_memory.Translate(RESERVED_END), 0x100000000 - RESERVED_END);
}

void* GuestHeap::Alloc(size_t size)
{
    std::lock_guard lock(mutex);

    return o1heapAllocate(heap, std::max<size_t>(1, size));
}

void* GuestHeap::AllocPhysical(size_t size, size_t alignment)
{
    size = std::max<size_t>(1, size);
    alignment = alignment == 0 ? 0x1000 : std::max<size_t>(16, alignment);

    std::lock_guard lock(physicalMutex);

    void* ptr = o1heapAllocate(physicalHeap, size + alignment);
    size_t aligned = ((size_t)ptr + alignment) & ~(alignment - 1);

    *((void**)aligned - 1) = ptr;
    *((size_t*)aligned - 2) = size + O1HEAP_ALIGNMENT;

    return (void*)aligned;
}

void GuestHeap::Free(void* ptr)
{
    if (ptr >= physicalHeap)
    {
        std::lock_guard lock(physicalMutex);
        o1heapFree(physicalHeap, *((void**)ptr - 1));
    }
    else
    {
        std::lock_guard lock(mutex);
        o1heapFree(heap, ptr);
    }
}

size_t GuestHeap::Size(void* ptr)
{
    if (ptr)
        return *((size_t*)ptr - 2) - O1HEAP_ALIGNMENT; // relies on fragment header in o1heap.c

    return 0;
}

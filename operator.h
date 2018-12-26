#pragma once

#include "std.h"
#include "types.h"
#include "sead/heap.h"

void* operator new(u64 size);
void* operator new[](u64 size);
void* operator new(u64 size, std::nothrow_t const &);
void* operator new[](u64 size, std::nothrow_t const &);
void* operator new(u64 size, s32);
void* operator new[](u64 size, s32);
void* operator new(u64 size, s32, std::nothrow_t const &);
void* operator new[](u64 size, s32, std::nothrow_t const &);
void* operator new(u64 size, sead::Heap *, s32);
void* operator new[](u64 size, sead::Heap *, s32);
void* operator new(u64 size, sead::Heap *, std::nothrow_t const &);
void* operator new[](u64 size, sead::Heap *, std::nothrow_t const &);
void* operator new(u64 size, sead::Heap *, s32, std::nothrow_t const &);
void* operator new[](u64 size, sead::Heap *, s32, std::nothrow_t const &);
void operator delete(void *);
void operator delete[](void *);
void operator delete(void *, std::nothrow_t const &);
void operator delete[](void *, std::nothrow_t const &);
void operator delete(void *, s32);
void operator delete[](void *, s32);
void operator delete(void *, s32, std::nothrow_t const &);
void operator delete[](void *, s32, std::nothrow_t const &);
void operator delete(void *, sead::Heap *, s32);
void operator delete[](void *, sead::Heap *, s32);
void operator delete(void *, sead::Heap *, std::nothrow_t const &);
void operator delete[](void *, sead::Heap *, std::nothrow_t const &);
void operator delete(void *, sead::Heap *, s32, std::nothrow_t const &);
void operator delete[](void *, sead::Heap *, s32, std::nothrow_t const &);
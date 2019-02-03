/**
 * @file operator.h
 * @brief Common operators, and new implementations with Heaps.
 */

#pragma once

#include <cstddef>
#include <std.h>
#include "types.h"
#include "sead/heap.h"

void* operator new(std::size_t size);
void* operator new[](std::size_t size);
void* operator new(std::size_t size, std::nothrow_t const &);
void* operator new[](std::size_t size, std::nothrow_t const &);
void* operator new(std::size_t size, s32);
void* operator new[](std::size_t size, s32);
void* operator new(std::size_t size, s32, std::nothrow_t const &);
void* operator new[](std::size_t size, s32, std::nothrow_t const &);
void* operator new(std::size_t size, sead::Heap *, s32);
void* operator new[](std::size_t size, sead::Heap *, s32);
void* operator new(std::size_t size, sead::Heap *, std::nothrow_t const &);
void* operator new[](std::size_t size, sead::Heap *, std::nothrow_t const &);
void* operator new(std::size_t size, sead::Heap *, s32, std::nothrow_t const &);
void* operator new[](std::size_t size, sead::Heap *, s32, std::nothrow_t const &);
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
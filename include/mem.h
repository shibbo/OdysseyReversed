/**
 * @file mem.h
 * @brief Memory functions.
 */

#pragma once

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

void* memset_0(void *src, int val, s32 num);
void* memcpy_0(void *dest, void const *src, u64 count);
void* memmove_0( void* dest, const void* src, u64 count);

#ifdef __cplusplus
}
#endif
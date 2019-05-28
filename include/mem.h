/**
 * @file mem.h
 * @brief Memory functions.
 */

#pragma once

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

void* memset(void *src, int val, s32 num);
void* memcpy(void *dest, void const *src, u64 count);
void* memmove( void* dest, const void* src, u64 count);

#ifdef __cplusplus
}
#endif
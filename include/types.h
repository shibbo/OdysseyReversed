/**
 * @file types.h
 * @brief Defines common types.
 */

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdalign.h>

#pragma once

typedef int8_t              s8;
typedef int16_t             s16;
typedef int32_t             s32;
typedef int64_t             s64;
typedef __int128_t          s128;
typedef uint8_t             u8;
typedef uint16_t            u16;
typedef uint32_t            u32;
typedef uint64_t            u64;
typedef __uint128_t         u128;
typedef float               f32;
typedef double              f64;

// stores a result on a lot of OS-related functions
typedef u32 Result;

// printing declarations
typedef __builtin_va_list va_list;
#define va_start(v,l) __builtin_va_start(v,l)
#define va_end(v) __builtin_va_end(v)
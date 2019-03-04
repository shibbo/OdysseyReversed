/**
 * @file types.h
 * @brief Defines common types.
 */

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

#ifndef BIT
#define BIT(n) (1U<<(n))
#endif

#ifndef NORETURN
#define NORETURN   __attribute__((noreturn))
#endif
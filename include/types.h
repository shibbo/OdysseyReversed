/**
 * @file types.h
 * @brief Defines common types.
 */

#pragma once

typedef signed char         s8;
typedef signed short        s16;
typedef signed int          s32;
typedef signed long         s64;
typedef signed long long    s128;
typedef unsigned char       u8;
typedef unsigned short      u16;
typedef int                 u32;
typedef long                u64;
typedef long long           u128;
typedef float               f32;
typedef double              f64;

// stores a result on a lot of OS-related functions
typedef u32 Result;

#ifndef BIT
#define BIT(n) (1U<<(n))
#endif
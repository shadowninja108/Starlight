/**
 * @file types.h
 * @brief Defines common types.
 */

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdalign.h>

#pragma once

#define __int8 char
#define __int16 short
#define __int32 int
#define __int64 long long
#define _QWORD __int64
#define _DWORD __int32
#define _WORD __int16
#define _BYTE char

#define ushort unsigned short
#define uchar unsigned char
#define ulong unsigned long
#define uint unsigned int

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
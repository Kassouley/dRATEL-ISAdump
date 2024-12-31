#ifndef TYPES_H
#define TYPES_H

#include <stdint.h>

// Basic types typedef
typedef __int128 b128;
typedef uint64_t b64;
typedef uint32_t b32;
typedef uint16_t b16;
typedef b16 b8;
typedef uint64_t u64;
typedef uint32_t u32;
typedef uint16_t u16;
typedef u16 u8;
typedef u16 u4; // Assuming 4-bit packed into 8 bits
typedef int64_t i64;
typedef int32_t i32;
typedef int16_t i16;
typedef i16 i8;
typedef i16 i4; // Assuming 4-bit packed into 8 bits
typedef double f64;
typedef float f32;
typedef uint16_t f16;
typedef uint16_t bf16;
typedef uint32_t b96 __attribute__((ext_vector_type(3)));
typedef uint32_t b256 __attribute__((ext_vector_type(8)));  // 256 bits = 32 bytes
typedef uint32_t b512 __attribute__((ext_vector_type(16)));  // 512 bits = 64 bytes

typedef b32 b16x2;
typedef b64 b16x3;
typedef b64 b16x4;

typedef f64 f16x4;
typedef f64 f64x4 __attribute__((ext_vector_type(4)));
typedef f32 f16x2;
typedef f32 f32x4 __attribute__((ext_vector_type(4)));
typedef f32 f32x16 __attribute__((ext_vector_type(16)));
typedef f32 f32x32 __attribute__((ext_vector_type(32)));

typedef bf16 bf16x2 __attribute__((ext_vector_type(2)));
typedef bf16 bf16x4 __attribute__((ext_vector_type(4)));

typedef b64 b32x2;
typedef b128 b64x2;

typedef i32 i16x2;
typedef i32 i8x4;
typedef i32 i4x8;
typedef i32 i32x4 __attribute__((ext_vector_type(4)));
typedef i32 i32x16 __attribute__((ext_vector_type(16)));
typedef i32 i32x32 __attribute__((ext_vector_type(32)));

typedef u32 u32x4 __attribute__((ext_vector_type(4)));
typedef u64 u16x4;
typedef u32 u16x2;
typedef u64 u8x8;
typedef u32 u8x4;
typedef u32 u4x8;

#define CREATE_ARR_TYPE(type) \
    typedef type type##x2 __attribute__((ext_vector_type(2))); \
    typedef type type##x4 __attribute__((ext_vector_type(4))); \
    typedef type type##x8 __attribute__((ext_vector_type(8))); \
    typedef type type##x16 __attribute__((ext_vector_type(16))); \
    typedef type type##x32 __attribute__((ext_vector_type(32)));

#endif

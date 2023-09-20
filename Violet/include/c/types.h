#ifndef TYPES_H_
#define TYPES_H_

#include "stdbool.h"
#include "stddef.h"

#if defined(__GNUC__) && __GNUC__ >= 7
 #define FALL_THROUGH __attribute__((fallthrough))
#else
 #define FALL_THROUGH ((void)0)
#endif /* __GNUC__ >= 7 */

#define EWRAM __attribute__((section("free_ewram")))

#define ALIGNED(n) __attribute__((aligned(n)))

#define LOW 0
#define HIGH 1

typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned int u32;
typedef unsigned long long int u64;
typedef u8 LZ77COMPRESSED[]; 

typedef u8 UNALIGNED_16[2];
typedef u8 UNALIGNED_32[4];

#define UNALIGNED_16_GET(arr)((u16)((arr)[0] | ((arr)[1] << 8)))
#define UNALIGNED_32_GET(arr)((int)((arr)[0] | ((arr)[1] << 8) | ((arr)[2] << 16) | ((arr)[3] << 24)))

typedef signed char s8;
typedef signed short int s16;
typedef signed int s32;
typedef signed long long int s64;

typedef volatile u8   vu8;
typedef volatile u16 vu16;
typedef volatile u32 vu32;
typedef volatile u64 vu64;
typedef volatile s8   vs8;
typedef volatile s16 vs16;
typedef volatile s32 vs32;
typedef volatile s64 vs64;

typedef float f32;
typedef double f64;

typedef struct {
    u16 id;
    u16 value;
} short_pair;

typedef struct {
    int id;
    int value;
} int_pair;

#define ARRAY_COUNT(array) (size_t)(sizeof(array) / (size_t)sizeof((array)[0]))

#define MIN(x,y) ((x) < (y) ? (x) : (y))
#define MAX(x,y) ((x) > (y) ? (x) : (y))
#define ABS(x) ((x) < 0 ? (-(x)) : (x))
#define SGN(x) ((x < 0 ? -1 : (x > 0 ? 1 : 0)))

typedef s32 FIXED;
#define FIXED_SHIFT 16

#define INT_MAX 0x7FFFFFFF
#define INT_MIN -0x7FFFFFF

/**
 * Adds fixed point numbers
 * @param a the first value
 * @param b the second value
 * @return a + b as FIXED type
 */
static inline FIXED FIXED_ADD(FIXED a, FIXED b) {
  return a + b;
}

/**
 * Subtracts fixed point numbers
 * @param a the first value
 * @param b the second value
 * @return a - b as FIXED type
 */
static inline FIXED FIXED_SUB(FIXED a, FIXED b) {
  return a - b;
}

/**
 * Multiplies fixed point numbers
 * @param a the first value
 * @param b the second value
 * @return a * b as FIXED type
 */
static inline FIXED FIXED_MUL(FIXED a, FIXED b) {
  return (a >> (FIXED_SHIFT >> 1)) * (b >> (FIXED_SHIFT >> 1));
}

/**
 * Divides fixed point numbers (with enormous loss of precision)
 * @param a the first value
 * @param b the second value
 * @return a / b as FIXED type
 */
static inline FIXED FIXED_DIV(FIXED a, FIXED b) {
  int scale_a = FIXED_SHIFT >> 2;
  int scale_b = FIXED_SHIFT - scale_a;
  return (a << scale_a) / (b >> scale_b);
}

/**
 * Transforms a fixed point value to an integer (correctly rounding)
 * @param a the fixed point value
 * @return the integer value
 */
static inline int FIXED_TO_INT(FIXED a) {
  return (int)((a + (1 << (FIXED_SHIFT - 1))) >> FIXED_SHIFT);
}

/**
 * Transforms an integer into a fixed point value
 */
static inline FIXED INT_TO_FIXED(int a) {
  return a << FIXED_SHIFT;
}

extern const u32 int_bitmasks[32];

/**
 * @brief Counts the number of zero bits that are trailing (i.e. the size of the largest zero sequence in `i` starting at the lsb)
 * 
 * @param i the number to check
 * @return u8 how many trailing zeros are in `i`
 */
u8 count_trailing_zero_bits(int i);


#endif

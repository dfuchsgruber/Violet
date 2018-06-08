#ifndef TYPES_H_
#define TYPES_H_

#include "stdbool.h"
#include "stddef.h"

#define LOW 0
#define HIGH 1


typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned int u32;
typedef unsigned long long int u64;

typedef u8 MISALIGNED_32[4];
typedef u8 MISALIGNED_16[4];

#define GET_MISALIGNED_16(arr)((arr[0]) | (arr[1] << 8))
#define GET_MISALIGNED_32(arr)((arr[0]) | (arr[1] << 8) | (arr[2] << 16) | (arr[3] << 24))

typedef signed char s8;
typedef signed short int s16;
typedef signed int s32;
typedef signed long long int s64;

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
  int scale_a = FIXED_SHIFT >> 1;
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



#endif

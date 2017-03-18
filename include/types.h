#ifndef TYPES_H_
#define TYPES_H_

#define NULL 0
#define LOW 0
#define HIGH 1


typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned int u32;
typedef unsigned long long int u64;

typedef u8 MISALIGNED_32[4];
typedef u8 MISALIGNED_16[4];

typedef signed char s8;
typedef signed short int s16;
typedef signed int s32;
typedef signed long long int s64;

typedef float f32;
typedef double f64;

typedef struct pair {
    u16 id;
    u16 value;
} pair;

typedef u8* script;
typedef u8* pstring;

#endif

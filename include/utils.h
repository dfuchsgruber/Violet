#ifndef H_MATH
#define H_MATH

#include "types.h"
#include "stdbool.h"
#include "oams.h"


typedef struct {
    u32 affects;
    u16 scale;
    u16 color : 15;
    u16 active : 1;
    u8 field_8;
    u8 field_9;
    u8 field_A;
    u8 field_B;
    
} stru_fading_cntrl;

stru_fading_cntrl *fading_cntrl = (stru_fading_cntrl*) 0x02037AB8;

int abs(int i);
int signum(int i);
int sin_16(int x);
int cos_16(int x);
int tan_16(int x);
int hwt(int x, int th, int n0);
u32 __aeabi_uidivmod(u32 dividend, u32 divisor);
int ggt(int a, int b);
int kgv(int a, int b);

/**
 * Sine function for a given value between [0; period - 1]
 * @param x 
 * @param period the period of the sine function
 * @param amplitude output will be between [-amplitude; amplitude]
 * @return returns amplitude * sin(x * 2 * pi / period)
 */
int __sin(int x, int period, int amplitude);
/**
 * Cosine function for a given value between [0; period - 1]
 * @param x 
 * @param period the period of the cosine function
 * @param amplitude output will be between [-amplitude; amplitude]
 * @return returns amplitude * cos(x * 2 * pi / period)
 */
int __cos(int x, int period, int amplitude);

/**
 * Tagens function for given value between [0; period - 1]
 * @param x
 * @param period period of the tangens function
 * @return 0 if tagens is not defined, tan(2pi / period * x) else
 */
int __tan(int x, int period);
int linear_cos_16(int x);

int linear_sin_16(int x);


/**
 * Sine function for a given value between [0; period - 1] approximated by two linear functions
 * @param x 
 * @param period the period of the sine function
 * @param amplitude output will be between [-amplitude; amplitude]
 * @return returns amplitude * sin(x * 2 * pi / period)
 */
int linear_sin(int x, int period, int amplitude);

/**
 * Cosine function for a given value between [0; period - 1] approximated by two linear functions
 * @param x 
 * @param period the period of the sine function
 * @param amplitude output will be between [-amplitude; amplitude]
 * @return returns amplitude * sin(x * 2 * pi / period)
 */
int linear_cos(int x, int period, int amplitude);


/**
 * Tagens function for given value between [0; period - 1] approximated by four linear functions
 * @param x
 * @param period period of the tangens function
 * @return 0 if tagens is not defined, tan(2pi / period * x) else
 */
int linear_tan(int x, int period);

bool is_fading();

void nullsub();

#endif
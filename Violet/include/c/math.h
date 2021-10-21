#ifndef H_MATH
#define H_MATH

#include "stdbool.h"
#include "types.h"

#define SIN_LUT_BITS 9

u16 sin_lut[1 << SIN_LUT_BITS];

/**
 * Returns the sin(2pi * theta) (sine with period 1.0)
 * @param theta the angle
 * @return the sine of 2pi * theta
 */
FIXED FIXED_SIN(FIXED theta);

/**
 * Returns the cos(2pi * theta) (cosine with period 1.0)
 * @param theta the angle
 * @return the cosine of 2pi * theta
 */
FIXED FIXED_COS(FIXED theta);

/**
 * Retruns the tan(2pi * theta) (tangens with period 1.0)
 * Locks the game state and prints an error for unedefined values
 * @param theta the angle
 * @return the tanges of 2pi * theta
 */
FIXED FIXED_TAN(FIXED theta);

/**
 * Returns the linear intepolation of a sine function (triangle function) with period 1.0
 * @param theta the angle
 * @return triange(theta)
 */
FIXED FIXED_TRIANGLE_SIN(FIXED theta);

/**
 * Returns the linear intepolation of a cosine function (triangle function) with period 1.0
 * @param theta the angle
 * @return triange(theta)
 */
FIXED FIXED_TRIANGLE_COS(FIXED theta);

/**
 * Returns the linear intepolation of a tagens function (triangle function) with period 1.0
 * @param theta the angle
 * @return triange(theta)
 */
FIXED FIXED_TRIANGLE_TAN(FIXED theta);

#define FIXED_SQRT_MAX_ITERATIONS 100

/**
 * Returns the square root of x
 */
FIXED FIXED_SQRT(FIXED x);

/**
 * Evaluates a polynomial at a given point using the horner scheme
 * @param x the point to evaluate the polynomial at
 * @param coefs pointer to the coefficients a_0, a_1, ... a_{n-1}
 * @param num_coefs the number of coefficients (degree + 1)
 * @return p(x)
 */
FIXED FIXED_HORNER_SCHEME(FIXED x, FIXED *coefs, int num_coefs);

#define FIXED_LOG2 45426

/**
 * Natural logarithm of a number x
 * @param x the number > 0
 * @return log(x)
 */
FIXED FIXED_LOG(FIXED x);

/**
 * Returns the inverse of the error function
 * @param x x in [-1; 1] (inf and -inf approximated by INT_MAX and INT_MIN)
 * @return erfinv(x)
 */
FIXED FIXED_ERFINV(FIXED x);

#define FIXED_SQRT2 92681

/**
 * Returns the inverse of the normal cdf
 * @param p the probabiltiy in [0;1]
 * @return phi^-1(p)
 */
FIXED FIXED_PROBIT_INV(FIXED p);

/**
 * Decay of value n0 at time step t with hwt th
 * @param x the current time value
 * @param th time step amount for the value to half
 * @param n0 the start value for t = 0
 * @return n0 / 2^(t/th)
 *
 */
int hwt(int t, int th, int n0);

/**
 * Greatest common divisor (gcd) of a and b
 * @param a a
 * @param b b
 * @return gcd of a and b
 */
int ggt(int a, int b);

/**
 * Least common multiple (lcm) of a and b
 * @param a a
 * @param b b
 * @return lcm of a and b
 */
int kgv(int a, int b);

/**
 * Sinusoid function from the bprd engine.
 * @param
 * @param
 * @return
 */
s16 sine(s16 x, s16 amplitude);

/**
 * Returns the index of the most significant bit, a.k.a calculates floor(log2(x))
 * @param value the value to calculate the msb index of
 * @return floor(log2(x))
 */
int msb_index(u32 value);

#endif

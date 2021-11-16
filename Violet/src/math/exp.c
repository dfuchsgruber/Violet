/*
 * exp.c
 *
 *  Created on: Jun 8, 2018
 *      Author: dominik
 *
 *  Exponential functions and logarithms
 */
#include "types.h"
#include "math.h"
#include "debug.h"

/**
 * Coefficients for a polynomial to approximate log(x) for x in [1;2]
 */
FIXED log_polynomial_coefs[5] = {-114150, 184890, -96335, 29306, -3707};

FIXED FIXED_LOG(FIXED x) {
  if(x < 0) {
    ERROR("Logarithm of negative numbers not defined %d\n", x);
    return 0;
  }
  if (x == 0) {
    DEBUG("Warning, logarithm of 0 called (likely due to inaccuracy errors)\n");
    return INT_MIN;
  }
  // Get the msb of x
  int msb = -1;
  FIXED xx = x;
  while(xx) {
    xx >>= 1;
    msb += 1;
  }

  msb -= FIXED_SHIFT;
  if(msb >= 0) {
    // Value is >= 1, scale into interval [1;2]
    x >>= msb;
  } else {
    // Value is < 1, scale into interval [1;2]
    x <<= -msb;
  }
  FIXED result = FIXED_HORNER_SCHEME(x, log_polynomial_coefs, 5);
  // Revert scaling by adding n*ld(2)
  return FIXED_ADD(result, FIXED_MUL(FIXED_LOG2, INT_TO_FIXED(msb)));
}



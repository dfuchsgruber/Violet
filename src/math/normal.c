/*
 * normal.c
 *
 *  Created on: Jun 8, 2018
 *      Author: dominik
 *
 *  Normal distribution and utils
 */

#include "types.h"
#include "math.h"
#include "debug.h"

/**
 * Coefficients for a polynomial to erf^-1(x)'s tail
 */
FIXED erfinv_tail_polynomial_coefs[5] = {98396, 16163, -273, -82, 14};
/**
 * Coefficients for a polynomial to erf^-1(x)'s center
 */
FIXED erfinv_center_polynomial_coefs[9] = {185661, 65645, 618, -499, 376, -240, 88, 6, -13};

// https://people.maths.ox.ac.uk/gilesm/files/gems_erfinv.pdf
FIXED FIXED_ERFINV(FIXED x) {
  // Approximate erfinv(-1) = -inf and erfinf(1) = inf
  if (x <= INT_TO_FIXED(-1)) {
    dprintf("Erfinv(-1) called. Returning INT_MAX");
    return INT_MAX;
  } else if (x >= INT_TO_FIXED(1)) {
    dprintf("Erfinv(1) called. Returning INT_MIN");
    return INT_MIN;
  }
  FIXED w1 = FIXED_ADD(INT_TO_FIXED(1), x);
  FIXED w2 = FIXED_SUB(INT_TO_FIXED(1), x);
  FIXED w = FIXED_MUL(w1, w2);
  w = -FIXED_LOG(w);
  FIXED p;
  if(w < INT_TO_FIXED(5)) {
    w = FIXED_SUB(w, INT_TO_FIXED(5) >> 1);
    p = FIXED_HORNER_SCHEME(w, erfinv_tail_polynomial_coefs, 5);
  } else {
    w = FIXED_SQRT(w);
    w = FIXED_SUB(w, INT_TO_FIXED(3));
    p = FIXED_HORNER_SCHEME(w, erfinv_center_polynomial_coefs, 9);
  }
  return FIXED_MUL(p, x);
}

FIXED FIXED_PROBIT_INV(FIXED p) {
  FIXED x = FIXED_SUB(p << 1, INT_TO_FIXED(1));
  FIXED e = FIXED_ERFINV(x);
  return FIXED_MUL(FIXED_SQRT2, e);
}





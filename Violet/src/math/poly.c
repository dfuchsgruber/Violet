/*
 * poly.c
 *
 *  Created on: Jun 8, 2018
 *      Author: dominik
 *
 *  Polynomial functions
 */

#include "types.h"
#include "math.h"

FIXED FIXED_HORNER_SCHEME(FIXED x, FIXED *coefs, int num_coefs) {
  FIXED result = 0;
  for(int i = 0; i < num_coefs; i++) {
    result = FIXED_MUL(result, x);
    result = FIXED_ADD(result, coefs[num_coefs - i - 1]);
  }
  return result;
}





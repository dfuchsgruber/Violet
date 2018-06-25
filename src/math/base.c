/*
 * base.c
 *
 *  Created on: Jun 8, 2018
 *      Author: dominik
 *
 * Basic functionality that operates on ints and FIXED
 */

#include "types.h"
#include "debug.h"
#include "math.h"
#include "bios.h"

FIXED FIXED_SQRT(FIXED x) {
  if(x < 0) {
    derrf("Sqrt not defined for negative values %d\n", x);
    return 0;
  } else {
    u16 rem = sqrt32((u32)x);
    FIXED result = rem << 8;
    return result;
  }
}

int max(int a, int b) {
  if (a > b) return a;
  return b;
}

int min(int a, int b) {
  if (a < b) return a;
  return b;
}

int abs(int i) {
    if (i < 0) {
        return -i;
    }
    return i;
}

int sign(int i) {
    if (i < 0) {
        return -1;
    } else if (i > 0) {
        return 1;
    }
    return 0;
}

int hwt(int x, int th, int n0){
    int ex = x / th;
    int div = 1 << ex;
    if(!div) return 0;
    return n0 / div;

}

int ggt(int a, int b){
    if(a == 0) return b;
    while(b != 0){
        if (a > b){
            a = a - b;
        }else{
            b = b - a;
        }
    }
    return a;
}

int kgv(int a, int b){
    if(a == 0 || b == 0) return -1;
    return a / ggt(a, b) * b;
}

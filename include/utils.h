#ifndef H_MATH
#define H_MATH

#include "types.h"
#include "stdbool.h"
#include "oams.h"

int abs(int i);
int signum(int i);
int sin_16(int x);
int cos_16(int x);
int tan_16(int x);
int hwt(int x, int th, int n0);

bool is_fading();

#endif
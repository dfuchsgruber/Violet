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
u32 __aeabi_uidivmod(u32 dividend, u32 divisor);
int ggt(int a, int b);
int kgv(int a, int b);

bool is_fading();

#endif
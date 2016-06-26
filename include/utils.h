#ifndef H_MATH
#define H_MATH

#include "types.h"
#include "stdbool.h"
#include "oams.h"

int abs (int i);
int signum (int i);

bool is_fading();

void oam_null_callback(oam_object *self);

#endif
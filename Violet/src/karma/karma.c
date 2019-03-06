#include "types.h"
#include "karma.h"
#include "math.h"
#include "constants/vars.h"
#include "vars.h"

s16 karma_get() {
	return (s16)(*var_access(KARMA_VALUE));
}

s16 karma_add(s16 *value) {
	int amount = *value + (s16)(*var_access(KARMA_POINTS));
	amount = MIN(200, MAX(-200, amount));
	*var_access(KARMA_POINTS) = (u16)amount;
	karma_calculate();
	return (s16)(*var_access(KARMA_POINTS));
}

void karma_calculate() {
	// To transform the karma points in (-200, 200) to (-127, 127) we use a
	// square-root-function. k(x) = sqrt(80 * x) with threshold at -127, 127
    s16 karma_points = (s16) (*var_access(KARMA_POINTS));
    s16 karma;
    if (ABS(karma_points) < 200) {
        karma = (s16) FIXED_TO_INT(
        		(FIXED_SQRT(INT_TO_FIXED(80 * ABS(karma_points))) * SGN(karma_points)));

    } else {
        karma = (s16) (127 * SGN(karma_points));
    }
    *var_access(KARMA_VALUE) = (u16) karma;

}


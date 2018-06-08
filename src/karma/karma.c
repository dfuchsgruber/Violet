#include "types.h"
#include "karma.h"
#include "math.h"
#include "constants/vars.h"
#include "vars.h"

u16 addkarma(u16 *value) {
    s16 v = (s16) (*value);
    s16 karma_points = (s16) (*var_access(KARMA_POINTS) + v);
    if (karma_points > 200) {
        karma_points = 200;
    } else if (karma_points < -200) {
        karma_points = -200;
    }
    *var_access(KARMA_POINTS) = (u16) karma_points;

    recalculate_karma();

    return (u16) v;

}

void recalculate_karma() {

    s16 karma_points = (s16) (*var_access(KARMA_POINTS));
    s16 karma;
    if (abs(karma_points) < 200) {
        karma = (s16) (FIXED_SQRT(INT_TO_FIXED(80 * abs(karma_points))) * sign(karma_points));
        //80 is numeric constant that provides a approximation
    } else {
        karma = (s16) (127 * sign(karma_points));
    }
    *var_access(KARMA_VALUE) = (u16) karma;

}


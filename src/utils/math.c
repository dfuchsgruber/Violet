#include "types.h"

int abs(int i) {
    if (i < 0) {
        return -i;
    }
    return i;
}

int signum(int i) {
    if (i < 0) {
        return -1;
    } else if (i > 0) {
        return 1;
    }
    return 0;
}


#include "types.h"
#include "vars.h"
#include "constants/difficulties.h"

int modify_exp(int exp) {
    int new_exp = exp;
    switch (*var_access(DIFFICULTY)) {
        case DIFFICULTY_EASY:
            new_exp += new_exp / 2;
            break;
        case DIFFICULTY_HARD:
            new_exp = MAX(1, new_exp - new_exp / 2);
            break;
    }
    return new_exp;
}

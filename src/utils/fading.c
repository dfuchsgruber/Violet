/* 
 * File:   fading.c
 * Author: Domi
 *
 * Created on 24. Juni 2016, 15:21
 */

#include "types.h"
#include "stdbool.h"
#include "utils.h"

/*
 * 
 */
bool is_fading() {
    if ((*((u8*) (0x02037AB8 + 7))) & 0x80) {
        return true;
    }
    return false;
}


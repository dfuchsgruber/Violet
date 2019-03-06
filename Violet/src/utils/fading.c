/* 
 * File:   fading.c
 * Author: Domi
 *
 * Created on 24. Juni 2016, 15:21
 */

#include "types.h"
#include "stdbool.h"
#include "fading.h"

/*
 * 
 */
bool fading_is_active() {
    if ((*((u8*) (0x02037AB8 + 7))) & 0x80) {
        return true;
    }
    return false;
}


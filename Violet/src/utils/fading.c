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
    return fading_control.active;
}


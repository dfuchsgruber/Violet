/*
 * init.c
 *
 *  Created on: Jul 4, 2018
 *      Author: dominik
 */

#include "types.h"
#include "bios.h"
#include "save.h"
#include "flags.h"
#include "constants/flags.h"
#include "pokepad/incubator.h"
#include "debug.h"
#include "vars.h"
#include "rtc.h"
#include "agbmemory.h"
#include "data_structures.h"
#include "berry.h"
#include "overworld/misc.h"

void fmem_init(){
    memset(&fmem, 0, sizeof(fmem));
    gp_stack_init();
}





/*
 * init.c
 *
 *  Created on: Jul 4, 2018
 *      Author: dominik
 */

#include "agbmemory.h"
#include "berry.h"
#include "bios.h"
#include "constants/flags.h"
#include "data_structures.h"
#include "debug.h"
#include "flags.h"
#include "overworld/misc.h"
#include "pokepad/incubator.h"
#include "rtc.h"
#include "save.h"
#include "types.h"
#include "vars.h"

void custom_memory_init() {
    memset(&cmem, 0, sizeof(custom_memory));
    setflag(POKERADAR_POKEMON_SPAWNED); // set corresponds to a pokemon already spawned
    incubator_clear();
    overworld_misc_intialize();
    berry_trees_initialize_all();
}

u8 *dma0_dump = ((floating_memory *)0x0203CEC4)->dma0_dump;

void fmem_init() {
    memset(&fmem, 0, sizeof(fmem));
    gp_stack_init();
}

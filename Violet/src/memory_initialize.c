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

void custom_memory_init() {
  memset(&cmem, 0, sizeof(custom_memory));
  setflag(POKERADAR_POKEMON_SPAWNED);  // set corresponds to a pokemon already spawned
  incubator_clear();
}


u8 *dma0_dump = ((floating_memory*) 0x0203CEC4)->dma0_dump;

void fmem_init(){
    memset(&fmem, 0, sizeof(fmem));
    gp_stack_init();
}





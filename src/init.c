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

void custom_memory_init() {
  int zero = 0;
  cpuset(&zero, cmem, CPUSET_FILL | CPUSET_SIZE(sizeof(custom_memory) >> 2) | CPUSET_WORD);
  setflag(POKERADAR_POKEMON_SPAWNED);  // set corresponds to a pokemon already spawned
}





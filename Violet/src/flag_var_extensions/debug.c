/*
 * debug.c
 *
 *  Created on: Sep 26, 2018
 *      Author: dominik
 */
#include "types.h"
#include "vars.h"
#include "flags.h"
#include "constants/vars.h"
#include "constants/flags.h"
#include "debug.h"

void debug_vars() {
	for (u16 var = 0x4050; var < 0x4060; var++) {
		DEBUG("%x   : %x\n", var, *var_access(var));
	}
	for (u16 var = 0x5000; var < 0x5100; var++) {
		DEBUG("%x   : %x\n", var, *var_access(var));
	}
}

void debug_flags() {
	for (u16 flag = 0x1E0; flag < 0x280; flag++) {
		DEBUG("%x   : %x\n", flag, checkflag(flag));
	}
	for (u16 flag = 0x900; flag < 0xA00; flag++) {
		DEBUG("%x   : %x\n", flag, checkflag(flag));
	}
}

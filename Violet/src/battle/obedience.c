/*
 * obedience.c
 *
 *  Created on: Sep 18, 2018
 *      Author: dominik
 */

#include "types.h"
#include "flags.h"
#include "constants/flags.h"
#include "math.h"

int battle_obedience_get_max_level() {
	int max_level = 20;
	if (checkflag(FRBADGE_1)) {
		max_level = MAX(max_level, 30);
	}
	if (checkflag(FRBADGE_2)) {
		max_level = MAX(max_level, 40);
	}
	if (checkflag(FRBADGE_3)) {
		max_level = MAX(max_level, 50);
	}
	if (checkflag(FRBADGE_4)) {
		max_level = MAX(max_level, 60);
	}
	if (checkflag(FRBADGE_5)) {
		max_level = MAX(max_level, 70);
	}
	if (checkflag(FRBADGE_6)) {
		max_level = MAX(max_level, 80);
	}
	if (checkflag(FRBADGE_7)) {
		max_level = MAX(max_level, 90);
	}
	if (checkflag(FRBADGE_8)) {
		max_level = MAX(max_level, 100);
	}
	return max_level;
}


/*
 * trainer_builds.c
 *
 *  Created on: Feb 21, 2019
 *      Author: dominik
 */

#include "types.h"
#include "trainer/build.h"
#include "constants/trainer_builds.h"
#include "constants/natures.h"
#include "constants/pokemon_attributes.h"
#include "constants/pokemon_stat_names.h"
#include "pokemon/virtual.h"

trainer_build_t trainer_builds [NUM_TRAINER_BUILDS] = {
	[TRAINER_BUILD_PHYSICAL_SWEEPER_ATTACK_PREFERENCE] = {
			.evs = {[STAT_HP] = 4, [STAT_ATTACK] = 255, [STAT_SPEED] = 255}, .nature = NATURE_HART},
	[TRAINER_BUILD_PHYSICAL_SWEEPER_SPEED_PREFERENCE] = {
			.evs = {[STAT_HP] = 4, [STAT_ATTACK] = 255, [STAT_SPEED] = 255}, .nature = NATURE_FROH},
	[TRAINER_BUILD_SPECIAL_SWEEPER_SPECIAL_ATTACK_PREFERENCE] = {
			.evs = {[STAT_HP] = 4, [STAT_SPECIAL_ATTACK] = 255, [STAT_SPEED] = 255},
			.nature = NATURE_MAESSIG},
	[TRAINER_BUILD_SPECIAL_SWEEPER_SPEED_PREFERENCE] = {
			.evs = {[STAT_HP] = 4, [STAT_SPECIAL_ATTACK] = 255, [STAT_SPEED] = 255},
			.nature = NATURE_SCHEU},
	[TRAINER_BUILD_PHYSICAL_WALL_SPECIAL_ATTACK_PREFERENCE] = {
			.evs = {[STAT_HP] = 255, [STAT_DEFENSE] = 255, [STAT_SPECIAL_ATTACK] = 4},
			.nature = NATURE_KUEHN},
	[TRAINER_BUILD_PHYSICAL_WALL_ATTACK_PREFERENCE] = {
			.evs = {[STAT_HP] = 255, [STAT_DEFENSE] = 255, [STAT_ATTACK] = 4},
			.nature = NATURE_PFIFFIG},
	[TRAINER_BUILD_SPECIAL_WALL_SPECIAL_ATTACK_PREFERENCE] = {
			.evs = {[STAT_HP] = 255, [STAT_SPECIAL_DEFENSE] = 255, [STAT_SPECIAL_ATTACK] = 4},
			.nature = NATURE_STILL},
	[TRAINER_BUILD_SPECIAL_WALL_ATTACK_PREFERENCE] = {
			.evs = {[STAT_HP] = 255, [STAT_SPECIAL_DEFENSE] = 255, [STAT_ATTACK] = 4},
			.nature = NATURE_SACHT},
	[TRAINER_BUILD_MIXED_SWEEPER] = {
			.evs = {[STAT_ATTACK] = 255, [STAT_SPECIAL_ATTACK] = 255, [STAT_SPEED] = 4},
			.nature = NATURE_NAIV},
	[TRAINER_BUILD_PHYSICAL_TANK] = {
			.evs = {[STAT_ATTACK] = 255, [STAT_HP] = 255, [STAT_SPEED] = 4},
			.nature = NATURE_HART},
	[TRAINER_BUILD_SPECIAL_TANK] = {
			.evs = {[STAT_SPECIAL_ATTACK] = 255, [STAT_HP] = 255, [STAT_SPEED] = 4},
			.nature = NATURE_MAESSIG},
	[TRAINER_BUILD_SPECIAL_SWEEPER_SPECIAL_ATTACK_PREFERENCE_FEMALE] = {
			.evs = {[STAT_HP] = 4, [STAT_SPECIAL_ATTACK] = 255, [STAT_SPEED] = 255},
			.nature = NATURE_MAESSIG, .use_gender = true, .gender = GENDER_FEMALE},
	[TRAINER_BUILD_NONE] = {0}
};


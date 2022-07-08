/*
 * trainer_builds.c
 *
 *  Created on: Feb 21, 2019
 *      Author: dominik
 */

#include "types.h"
#include "trainer/build.h"
#include "map/wild_pokemon.h"
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
	[TRAINER_BUILD_UNOWN_LETTER_A] = {.unown_letter = UNOWN_LETTER('A')},
	[TRAINER_BUILD_UNOWN_LETTER_B] = {.unown_letter = UNOWN_LETTER('B')},
	[TRAINER_BUILD_UNOWN_LETTER_C] = {.unown_letter = UNOWN_LETTER('C')},
	[TRAINER_BUILD_UNOWN_LETTER_D] = {.unown_letter = UNOWN_LETTER('D')},
	[TRAINER_BUILD_UNOWN_LETTER_E] = {.unown_letter = UNOWN_LETTER('E')},
	[TRAINER_BUILD_UNOWN_LETTER_F] = {.unown_letter = UNOWN_LETTER('F')},
	[TRAINER_BUILD_UNOWN_LETTER_G] = {.unown_letter = UNOWN_LETTER('G')},
	[TRAINER_BUILD_UNOWN_LETTER_H] = {.unown_letter = UNOWN_LETTER('H')},
	[TRAINER_BUILD_UNOWN_LETTER_I] = {.unown_letter = UNOWN_LETTER('I')},
	[TRAINER_BUILD_UNOWN_LETTER_J] = {.unown_letter = UNOWN_LETTER('J')},
	[TRAINER_BUILD_UNOWN_LETTER_K] = {.unown_letter = UNOWN_LETTER('K')},
	[TRAINER_BUILD_UNOWN_LETTER_L] = {.unown_letter = UNOWN_LETTER('L')},
	[TRAINER_BUILD_UNOWN_LETTER_M] = {.unown_letter = UNOWN_LETTER('M')},
	[TRAINER_BUILD_UNOWN_LETTER_N] = {.unown_letter = UNOWN_LETTER('N')},
	[TRAINER_BUILD_UNOWN_LETTER_O] = {.unown_letter = UNOWN_LETTER('O')},
	[TRAINER_BUILD_UNOWN_LETTER_P] = {.unown_letter = UNOWN_LETTER('P')},
	[TRAINER_BUILD_UNOWN_LETTER_Q] = {.unown_letter = UNOWN_LETTER('Q')},
	[TRAINER_BUILD_UNOWN_LETTER_R] = {.unown_letter = UNOWN_LETTER('R')},
	[TRAINER_BUILD_UNOWN_LETTER_S] = {.unown_letter = UNOWN_LETTER('S')},
	[TRAINER_BUILD_UNOWN_LETTER_T] = {.unown_letter = UNOWN_LETTER('T')},
	[TRAINER_BUILD_UNOWN_LETTER_U] = {.unown_letter = UNOWN_LETTER('U')},
	[TRAINER_BUILD_UNOWN_LETTER_V] = {.unown_letter = UNOWN_LETTER('V')},
	[TRAINER_BUILD_UNOWN_LETTER_W] = {.unown_letter = UNOWN_LETTER('W')},
	[TRAINER_BUILD_UNOWN_LETTER_X] = {.unown_letter = UNOWN_LETTER('X')},
	[TRAINER_BUILD_UNOWN_LETTER_Y] = {.unown_letter = UNOWN_LETTER('Y')},
	[TRAINER_BUILD_UNOWN_LETTER_Z] = {.unown_letter = UNOWN_LETTER('Z')},
	[TRAINER_BUILD_UNOWN_LETTER_EXCLAMATION] = {.unown_letter = POKEMON_ICOGNITO_EXCLAMATION - POKEMON_EGG},
	[TRAINER_BUILD_UNOWN_LETTER_QUESTION] = {.unown_letter = POKEMON_ICOGNITO_QUESTION - POKEMON_EGG},
	[TRAINER_BUILD_NONE] = {0}
};


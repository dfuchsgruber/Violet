#ifndef H_TRAINER_PARTIES_RIVAL
#define H_TRAINER_PARTIES_RIVAL

#include "types.h"
#include "constants/pokemon_stat_names.h"
#include "constants/items.h"
#include "constants/attacks.h"
#include "constants/species.h"
#include "constants/natures.h"
#include "constants/pokemon_types.h"
#include "trainer/party.h"
#include "trainer/nickname.h"
#include "map/wild_pokemon.h"

// Trainer School

const trainer_pokemon trainer_party_xb3[] = {
	{.level = 5, .species = POKEMON_WELUNO, .evs = {[STAT_SPECIAL_ATTACK] = 0, [STAT_SPEED] = 0, [STAT_HP] = 0}, .nature_set = true, .evs_set = true, .pid = {.fields = {.nature = NATURE_MAESSIG}}},
	//{.level = 5, .species = POKEMON_SCHIGGY, .evs = {[STAT_HP] = 252, [STAT_SPECIAL_ATTACK] = 252, [STAT_SPEED] = 4}, .nature_set = true, .evs_set = true, .pid = {.fields = {.nature = NATURE_MAESSIG}}},
};

const trainer_pokemon trainer_party_xb4[] = {
	{.level = 5, .species = POKEMON_SEEKID, .evs = {[STAT_SPECIAL_ATTACK] = 0, [STAT_SPEED] = 0, [STAT_HP] = 0}, .nature_set = true, .evs_set = true, .pid = {.fields = {.nature = NATURE_MAESSIG}}},
	//{.level = 5, .species = POKEMON_BISASAM, .evs = {[STAT_HP] = 252, [STAT_SPECIAL_ATTACK] = 252, [STAT_SPEED] = 4}, .nature_set = true, .evs_set = true, .pid = {.fields = {.nature = NATURE_MAESSIG}}},
};

const trainer_pokemon trainer_party_xb5[] = {
	{.level = 5, .species = POKEMON_LOCKSCHAL, .evs = {[STAT_HP] = 0, [STAT_ATTACK] = 0, [STAT_SPEED] = 0}, .nature_set = true, .evs_set = true, .pid = {.fields = {.nature = NATURE_HART}}},
	//{.level = 5, .species = POKEMON_GLUMANDA, .evs = {[STAT_SPECIAL_ATTACK] = 252, [STAT_SPEED] = 252, [STAT_HP] = 4}, .nature_set = true, .evs_set = true, .pid = {.fields = {.nature = NATURE_SCHEU}}},
};


// Tag Team Fight

const trainer_pokemon trainer_party_x15f_route_2_rival_plant_starter[] = {
	{.ivs_set = true, .ivs = {20, 20, 20, 20, 20, 20}, .moves_set = true, .moves = {ATTACK_ABSORBER, ATTACK_WACHSTUM, ATTACK_SAEURE}, .level = 10, .species = POKEMON_MYRAPLA, .evs = {[STAT_HP] = 32, [STAT_SPECIAL_ATTACK] = 32, [STAT_SPEED] = 4}, .nature_set = true, .evs_set = true, .pid = {.fields = {.nature = NATURE_MAESSIG}}},
	{.ivs_set = true, .ivs = {20, 20, 20, 20, 20, 20}, .held_item = ITEM_SINELBEERE, .moves_set = true, .moves = {ATTACK_GLUT, ATTACK_JAULER, ATTACK_KRATZER}, .level = 11, .species = POKEMON_WELUNO, .evs = {[STAT_SPECIAL_ATTACK] = 32, [STAT_SPEED] = 32, [STAT_HP] = 4}, .nature_set = true, .evs_set = true, .pid = {.fields = {.nature = NATURE_MAESSIG}}},
};

const trainer_pokemon trainer_party_x160_route_2_rival_fire_starter[] = {
	{.ivs_set = true, .ivs = {20, 20, 20, 20, 20, 20}, .moves_set = true, .moves = {ATTACK_TACKLE, ATTACK_HEULER, ATTACK_SCHNABEL, ATTACK_RUCKZUCKHIEB}, .level = 10, .species = POKEMON_DARTIRI, .evs = {[STAT_ATTACK] = 32, [STAT_SPEED] = 32, [STAT_HP] = 4}, .nature_set = true, .evs_set = true, .pid = {.fields = {.nature = NATURE_FROH}}},
	{.ivs_set = true, .ivs = {20, 20, 20, 20, 20, 20}, .held_item = ITEM_SINELBEERE, .moves_set = true, .moves = {ATTACK_PFUND, ATTACK_SILBERBLICK, ATTACK_AQUAKNARRE}, .level = 11, .species = POKEMON_SEEKID, .evs = {[STAT_SPECIAL_ATTACK] = 32, [STAT_SPEED] = 32, [STAT_HP] = 4}, .nature_set = true, .evs_set = true, .pid = {.fields = {.nature = NATURE_MAESSIG}}},
};

const trainer_pokemon trainer_party_x161_route_2_rival_water_starter[] = {
	{.ivs_set = true, .ivs = {20, 20, 20, 20, 20, 20}, .moves_set = true, .moves = {ATTACK_WINDHOSE, ATTACK_AQUAKNARRE, ATTACK_SILBERBLICK, ATTACK_RAUCHWOLKE}, .level = 10, .species = POKEMON_SEEPER, .evs = {[STAT_HP] = 32, [STAT_SPECIAL_ATTACK] = 32, [STAT_SPEED] = 4}, .nature_set = true, .evs_set = true, .pid = {.fields = {.nature = NATURE_MAESSIG}}},
	{.ivs_set = true, .ivs = {20, 20, 20, 20, 20, 20}, .held_item = ITEM_SINELBEERE, .moves_set = true, .moves = {ATTACK_PFUND, ATTACK_HAERTNER, ATTACK_RASIERBLATT}, .level = 11, .species = POKEMON_LOCKSCHAL, .evs = {[STAT_HP] = 32, [STAT_ATTACK] = 32, [STAT_SPEED] = 4}, .nature_set = true, .evs_set = true, .pid = {.fields = {.nature = NATURE_HART}}},
};


// Felsige Oednis

const trainer_pokemon trainer_party_xb9_rival_felsige_oednis_plant_starter[] = {
	{.ivs_set = true, .ivs = {20, 20, 20, 20, 20, 20}, .moves_set = true, .moves = {ATTACK_SCHLAFPUDER, ATTACK_MEGASAUGER, ATTACK_SAEURE, ATTACK_EGELSAMEN}, .level = 21, .species = POKEMON_DUFLOR, .evs = {[STAT_HP] = 80, [STAT_SPECIAL_ATTACK] = 80, [STAT_SPEED] = 4}, .nature_set = true, .evs_set = true, .pid = {.fields = {.nature = NATURE_MAESSIG}}},
	{.ivs_set = true, .ivs = {20, 20, 20, 20, 20, 20}, .held_item = ITEM_TSITRUBEERE, .moves_set = true, .moves = {ATTACK_GLUT, ATTACK_BISS, ATTACK_ZERSCHNEIDER, ATTACK_KRATZER}, .level = 22, .species = POKEMON_ORTHODOS, .evs = {[STAT_SPECIAL_ATTACK] = 80, [STAT_SPEED] = 80, [STAT_HP] = 4}, .nature_set = true, .evs_set = true, .pid = {.fields = {.nature = NATURE_MAESSIG}}},
	{.ivs_set = true, .ivs = {20, 20, 20, 20, 20, 20}, .moves_set = true, .moves = {ATTACK_MEGASAUGER, ATTACK_KONFUSION, ATTACK_HYPNOSE, ATTACK_REFLEKTOR}, .level = 19, .species = POKEMON_STERNDU, .evs = {[STAT_SPEED] = 80, [STAT_SPECIAL_ATTACK] = 80, [STAT_HP] = 4}, .nature_set = true, .evs_set = true, .pid = {.fields = {.nature = NATURE_MAESSIG}}},
};

const trainer_pokemon trainer_party_xba_rival_felsige_oednis_fire_starter[] = {
	{.ivs_set = true, .ivs = {20, 20, 20, 20, 20, 20}, .moves_set = true, .moves = {ATTACK_NITROLADUNG, ATTACK_AERO_ASS, ATTACK_RUCKZUCKHIEB, ATTACK_SCHWERTTANZ}, .level = 21, .species = POKEMON_DARTIGNIS, .evs = {[STAT_HP] = 4, [STAT_ATTACK] = 80, [STAT_SPEED] = 80}, .nature_set = true, .evs_set = true, .pid = {.fields = {.nature = NATURE_FROH}}},
	{.ivs_set = true, .ivs = {20, 20, 20, 20, 20, 20}, .held_item = ITEM_TSITRUBEERE, .moves_set = true, .moves = {ATTACK_FINTE, ATTACK_AURORASTRAHL, ATTACK_AQUAWELLE, ATTACK_KONFUSTRAHL}, .level = 22, .species = POKEMON_SEESKULL, .evs = {[STAT_SPECIAL_ATTACK] = 80, [STAT_SPEED] = 80, [STAT_HP] = 4}, .nature_set = true, .evs_set = true, .pid = {.fields = {.nature = NATURE_MAESSIG}}},
	{.ivs_set = true, .ivs = {20, 20, 20, 20, 20, 20}, .moves_set = true, .moves = {ATTACK_METALLKLAUE, ATTACK_SAMENBOMBEN, ATTACK_NADELRAKETE, ATTACK_EGELSAMEN}, .level = 19, .species = POKEMON_KASTADUR, .evs = {[STAT_HP] = 80, [STAT_DEFENSE] = 80, [STAT_ATTACK] = 4}, .nature_set = true, .evs_set = true, .pid = {.fields = {.nature = NATURE_PFIFFIG}}},
};

const trainer_pokemon trainer_party_xbb_rival_felsige_oednis_water_starter[] = {
	{.ivs_set = true, .ivs = {20, 20, 20, 20, 20, 20}, .moves_set = true, .moves = {ATTACK_FEUERODEM, ATTACK_AQUAWELLE, ATTACK_EISSTURM, ATTACK_RAUCHWOLKE}, .level = 21, .species = POKEMON_SEEPER, .evs = {[STAT_SPECIAL_ATTACK] = 80, [STAT_HP] = 4, [STAT_SPEED] = 80}, .nature_set = true, .evs_set = true, .pid = {.fields = {.nature = NATURE_MAESSIG}}},
	{.ivs_set = true, .ivs = {20, 20, 20, 20, 20, 20}, .held_item = ITEM_TSITRUBEERE, .moves_set = true, .moves = {ATTACK_LAUBKLINGE, ATTACK_NATUR_KRAFT, ATTACK_EISENABWEHR, ATTACK_DURCHBRUCH}, .level = 22, .species = POKEMON_STICHSCHAL, .evs = {[STAT_HP] = 80, [STAT_ATTACK] = 80, [STAT_SPEED] = 4}, .nature_set = true, .evs_set = true, .pid = {.fields = {.nature = NATURE_HART}}},
	{.ivs_set = true, .ivs = {20, 20, 20, 20, 20, 20}, .moves_set = true, .moves = {ATTACK_GLUT, ATTACK_BISS, ATTACK_DONNERZAHN, ATTACK_SMOG}, .level = 19, .species = POKEMON_HUNDUSTER, .evs = {[STAT_SPECIAL_ATTACK] = 80, [STAT_HP] = 4, [STAT_SPEED] = 80}, .nature_set = true, .evs_set = true, .pid = {.fields = {.nature = NATURE_MAESSIG}}},
};

#endif
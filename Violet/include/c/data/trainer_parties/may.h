#ifndef H_TRAINER_PARTIES_MAY
#define H_TRAINER_PARTIES_MAY

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

// Route 4

const trainer_pokemon trainer_party_x29[] = {
	{.held_item = ITEM_SINELBEERE, .level = 15, .species = POKEMON_KNILZ, .ivs = {20, 20, 20, 20, 20, 20}, .ivs_set = true},
	{.held_item = ITEM_TSITRUBEERE, .level = 15, .species = POKEMON_SEEKID, .ivs = {20, 20, 20, 20, 20, 20}, .ivs_set = true},
};

const trainer_pokemon trainer_party_x2a[] = {
	{.held_item = ITEM_SINELBEERE, .level = 14, .species = POKEMON_HUNDUSTER, .ivs = {20, 20, 20, 20, 20, 20}, .ivs_set = true},
	{.held_item = ITEM_TSITRUBEERE, .level = 15, .species = POKEMON_LOCKSCHAL, .ivs = {20, 20, 20, 20, 20, 20}, .ivs_set = true},
};

const trainer_pokemon trainer_party_x2b[] = {
	{.held_item = ITEM_SINELBEERE, .level = 14, .species = POKEMON_STERNDU, .ivs = {20, 20, 20, 20, 20, 20}, .ivs_set = true},
	{.held_item = ITEM_TSITRUBEERE, .level = 15, .species = POKEMON_WELUNO, .ivs = {20, 20, 20, 20, 20, 20}, .ivs_set = true},
};

// Desert Village

const trainer_pokemon trainer_party_x5c[] = {
	{.moves_set = true, .moves = {ATTACK_STAHLFLUEGEL, ATTACK_AERO_ASS, ATTACK_NOTSITUATION, ATTACK_RUCKZUCKHIEB}, .level = 29, .species = POKEMON_STARAVIA},
	{.held_item = ITEM_TSITRUBEERE, .moves_set = true, .moves = {ATTACK_DRACHENTANZ, ATTACK_NASSSCHWEIF, ATTACK_EISENSCHWEIF, ATTACK_GIFTSCHWEIF}, .level = 31, .species = POKEMON_SEESKULL},
	{.held_item = ITEM_SINELBEERE, .moves_set = true, .moves = {ATTACK_SCHLAFPUDER, ATTACK_TEMPOHIEB, ATTACK_SAMENBOMBEN, ATTACK_FELSGRAB}, .level = 30, .species = POKEMON_KAPILZ},
};

const trainer_pokemon trainer_party_x5d[] = {
	{.moves_set = true, .moves = {ATTACK_STAHLFLUEGEL, ATTACK_AERO_ASS, ATTACK_NOTSITUATION, ATTACK_RUCKZUCKHIEB}, .level = 29, .species = POKEMON_STARAVIA},
	{.held_item = ITEM_TSITRUBEERE, .moves_set = true, .moves = {ATTACK_LAUBKLINGE, ATTACK_FLUCH, ATTACK_ZORNKLINGE, ATTACK_GEDULD}, .level = 31, .species = POKEMON_STICHSCHAL},
	{.held_item = ITEM_SINELBEERE, .moves_set = true, .moves = {ATTACK_FEUERZAHN, ATTACK_DONNERZAHN, ATTACK_BISS, ATTACK_SUPERZAHN}, .level = 30, .species = POKEMON_HUNDUSTER},
};

const trainer_pokemon trainer_party_x5e[] = {
	{.moves_set = true, .moves = {ATTACK_STAHLFLUEGEL, ATTACK_AERO_ASS, ATTACK_NOTSITUATION, ATTACK_RUCKZUCKHIEB}, .level = 29, .species = POKEMON_STARAVIA},
	{.held_item = ITEM_TSITRUBEERE, .moves_set = true, .moves = {ATTACK_FLAMMENRAD, ATTACK_BISS, ATTACK_SCHAUFLER, ATTACK_EISENSCHWEIF}, .level = 31, .species = POKEMON_ORTHODOS},
	{.held_item = ITEM_SINELBEERE, .moves_set = true, .moves = {ATTACK_AQUAWELLE, ATTACK_EISSTRAHL, ATTACK_PSYWELLE, ATTACK_BLITZ}, .level = 30, .species = POKEMON_STARMIE},
};

#endif
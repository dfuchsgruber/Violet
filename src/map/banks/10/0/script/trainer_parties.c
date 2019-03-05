/*
 * trainer_parties.c
 *
 *  Created on: Mar 5, 2019
 *      Author: dominik
 */

#include "types.h"
#include "constants/items.h"
#include "constants/attacks.h"
#include "constants/species.h"
#include "constants/trainer_builds.h"
#include "trainer/party.h"

trainer_pokemon_default_item_default_attacks trainer_party_xbf_inferior_gym[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false, 36, POKEMON_DARTIGNIS),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false, 35, POKEMON_CAMAUB),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false, 36, POKEMON_MAGMAR),
};

trainer_pokemon_default_item_default_attacks trainer_party_xc0_inferior_gym[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false, 39, POKEMON_CAMERUPT),
};

trainer_pokemon_default_item_default_attacks trainer_party_xc1_inferior_gym[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false, 35, POKEMON_VULNONA),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false, 38, POKEMON_IGELAVAR),
};

trainer_pokemon_default_item_default_attacks trainer_party_xc2_inferior_gym[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false, 34, POKEMON_MAGCARGO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false, 35, POKEMON_FUKANO),
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false, 35, POKEMON_GLUTEXO),
};

trainer_pokemon_default_item_default_attacks trainer_party_xc3_inferior_gym[] = {
	TRAINER_PARTY_DEFAULT_ITEM_DEFAULT_MOVES(0x0, 0x0,0x0,false,false, 40, POKEMON_GLURAK)
};


trainer_pokemon_custom_item_custom_attacks trainer_party_xc4_inferior_gymleader[] = {
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(19,  TRAINER_BUILD_PHYSICAL_SWEEPER_ATTACK_PREFERENCE,
			0x0, true, false, 39, POKEMON_FIARO, ITEM_HACKATTACK,
			ATTACK_STURZFLUG, ATTACK_FLAMMENBLITZ, ATTACK_STAHLFLUEGEL, ATTACK_HITZEKOLLER),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(19,
			TRAINER_BUILD_SPECIAL_SWEEPER_SPECIAL_ATTACK_PREFERENCE,
			0x0, false, false, 38, POKEMON_ZERBERTRES, ITEM_SCHLOHKRAUT,
			ATTACK_FINSTERAURA, ATTACK_SONNENTAG, ATTACK_HITZEKOLLER, ATTACK_SOLARSTRAHL),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(19,  TRAINER_BUILD_PHYSICAL_SWEEPER_ATTACK_PREFERENCE,
			0x0, false, false, 40, POKEMON_ARKANI, ITEM_SINELBEERE,
			ATTACK_TURBOTEMPO, ATTACK_KNIRSCHER, ATTACK_FLAMMENBLITZ, ATTACK_HITZEKOLLER),
	TRAINER_PARTY_CUSTOM_ITEM_CUSTOM_MOVES(19,
			TRAINER_BUILD_SPECIAL_SWEEPER_SPECIAL_ATTACK_PREFERENCE,
			0x0, false, false, 42, POKEMON_MAGBRANT, ITEM_TSITRUBEERE,
			ATTACK_HITZEKOLLER, ATTACK_FOKUSSTOSS, ATTACK_DONNERBLITZ, ATTACK_PSYCHOKINESE),
};


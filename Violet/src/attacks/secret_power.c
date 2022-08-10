/*
 * secret_power.c
 *
 *  Created on: Sep 29, 2018
 *      Author: dominik
 */

#include "types.h"
#include "battle/battlescript.h"
#include "battle/bg.h"
#include "constants/battle/battle_bgs.h"
#include "constants/battle/battle_effects.h"
#include "battle/communication.h"
#include "battle/state.h"
#include "constants/attacks.h"
#include "battle/attack.h"
#include "callbacks.h"

void bsc_cmd_xE4_secret_power() {
	switch (battle_bg_get_id()) {
	case BATTLE_BG_GRASS:
		battle_communication[BATTLE_COMMUNICATION_BATTLE_EFFECT] = BATTLE_EFFECT_POISON;
		break;
	case BATTLE_BG_STREET:
	case BATTLE_BG_GYM:
	case BATTLE_BG_POWER_PLANT:
		battle_communication[BATTLE_COMMUNICATION_BATTLE_EFFECT] = BATTLE_EFFECT_PARALYSIS;
		break;
	case BATTLE_BG_MOUNTAIN:
	case BATTLE_BG_HAWEILAND:
		battle_communication[BATTLE_COMMUNICATION_BATTLE_EFFECT] = BATTLE_EFFECT_CONFUSION;
		break;
	case BATTLE_BG_POND:
		battle_communication[BATTLE_COMMUNICATION_BATTLE_EFFECT] = BATTLE_EFFECT_LOWER_INITIATIVE;
		break;
	case BATTLE_BG_CLOUD:
	case BATTLE_BG_ARDEAL_CLOUD:
	case BATTLE_BG_SKY_ISLAND:
		battle_communication[BATTLE_COMMUNICATION_BATTLE_EFFECT] = BATTLE_EFFECT_ICE;
		break;
	case BATTLE_BG_SHORE:
	case BATTLE_BG_MILL:
		battle_communication[BATTLE_COMMUNICATION_BATTLE_EFFECT] = BATTLE_EFFECT_LOWER_ACCURACY;
		break;
	case BATTLE_BG_OCEAN:
		battle_communication[BATTLE_COMMUNICATION_BATTLE_EFFECT] = BATTLE_EFFECT_LOWER_ATTACK;
		break;
	case BATTLE_BG_CAVE:
	case BATTLE_BG_WATER_CAVE:
	case BATTLE_BG_CAVE_WATER:
	case BATTLE_BG_CLOUD_RUINS:
	case BATTLE_BG_ARDEAL:
	case BATTLE_BG_ARDEAL_DUNGEON:
	case BATTLE_BG_ROUTE_5_CAVE:
	case BATTLE_BG_INSIDE_STD:
	case BATTLE_BG_DUNGEON_FOREST_TENT_INSIDE:
		battle_communication[BATTLE_COMMUNICATION_BATTLE_EFFECT] = BATTLE_EFFECT_FLINCH;
		break;
	case BATTLE_BG_DESERT:
		battle_communication[BATTLE_COMMUNICATION_BATTLE_EFFECT] = BATTLE_EFFECT_RESIDUAL_DAMAGE;
		break;
	case BATTLE_BG_MUSEUM:
	case BATTLE_BG_DARK_TOWER:
		battle_communication[BATTLE_COMMUNICATION_BATTLE_EFFECT] = BATTLE_EFFECT_LOWER_SPECIAL_DEFENSE;
		break;
	case BATTLE_BG_FIRE:
		battle_communication[BATTLE_COMMUNICATION_BATTLE_EFFECT] = BATTLE_EFFECT_FIRE;
		break;
	case BATTLE_BG_GRAVEYARD:
		battle_communication[BATTLE_COMMUNICATION_BATTLE_EFFECT] = BATTLE_EFFECT_LOWER_SPECIAL_DEFENSE;
		break;
	case BATTLE_BG_CARGO_HALL:
	case BATTLE_BG_BBSHIP_INSIDE:
	case BATTLE_BG_BBSHIP_OUTSIDE:
		battle_communication[BATTLE_COMMUNICATION_BATTLE_EFFECT] = BATTLE_EFFECT_LOWER_EVASIVENESS;
		break;
	default:
	case BATTLE_BG_EVOLUTION:
	case BATTLE_BG_CAPTURE:
		battle_communication[BATTLE_COMMUNICATION_BATTLE_EFFECT] = BATTLE_EFFECT_NONE;
		break;
	case BATTLE_BG_ICE_CAVE:
		battle_communication[BATTLE_COMMUNICATION_BATTLE_EFFECT] = BATTLE_EFFECT_LOWER_INITIATIVE;
		break;
	}
	bsc_offset++;
}

void attack_anim_task_secret_power(u8 self) {
	// Instead of hardcoding the jump to the fitting animation into the script itself we write
	// a command for this.
	u16 attack;
	switch (battle_bg_get_id()) {
	case BATTLE_BG_STREET:
		attack = ATTACK_SLAM;
		break;
	case BATTLE_BG_GRASS:
		attack = ATTACK_ZAUBERBLATT;
		break;
	case BATTLE_BG_MOUNTAIN:
		attack = ATTACK_STEINHAGEL;
		break;
	case BATTLE_BG_POND:
		attack = ATTACK_BLUBBER;
		break;
	case BATTLE_BG_ARDEAL_CLOUD:
	case BATTLE_BG_CLOUD:
	case BATTLE_BG_SKY_ISLAND:
		attack = ATTACK_WINDSCHNITT;
		break;
	case BATTLE_BG_SHORE:
		attack = ATTACK_SCHNAPPER;
		break;
	case BATTLE_BG_OCEAN:
		attack = ATTACK_SURFER;
		break;
	case BATTLE_BG_CAVE:
	case BATTLE_BG_ROUTE_5_CAVE:
		attack = ATTACK_BISS;
		break;
	case BATTLE_BG_DESERT:
		attack = ATTACK_SANDGRAB;
		break;
	case BATTLE_BG_GYM:
		attack = ATTACK_NAHKAMPF;
		break;
	case BATTLE_BG_WATER_CAVE:
	case BATTLE_BG_CAVE_WATER:
		attack = ATTACK_AQUAWELLE;
		break;
	case BATTLE_BG_CLOUD_RUINS:
	case BATTLE_BG_MUSEUM:
		attack = ATTACK_ANTIK_KRAFT;
		break;
	case BATTLE_BG_FIRE:
		attack = ATTACK_FLAMMENWURF;
		break;
	default:
	case BATTLE_BG_EVOLUTION:
	case BATTLE_BG_CAPTURE:
		attack = ATTACK_TACKLE;
		break;
	case BATTLE_BG_MILL:
		attack = ATTACK_SCHNABEL;
		break;
	case BATTLE_BG_GRAVEYARD:
		attack = ATTACK_SPUKBALL;
		break;
	case BATTLE_BG_HAWEILAND:
		attack = ATTACK_AUFRUHR;
		break;
	case BATTLE_BG_CARGO_HALL:
		attack = ATTACK_TRICKBETRUG;
		break;
	case BATTLE_BG_ARDEAL_DUNGEON:
		attack = ATTACK_FINTE;
		break;
	case BATTLE_BG_DARK_TOWER:
		attack = ATTACK_FINSTERAURA;
		break;
	case BATTLE_BG_BBSHIP_INSIDE:
	case BATTLE_BG_BBSHIP_OUTSIDE:
		attack = ATTACK_RAUB;
		break;
	case BATTLE_BG_POWER_PLANT:
		attack = ATTACK_DONNERBLITZ;
		break;
	case BATTLE_BG_DUNGEON_FOREST_TENT_INSIDE:
	case BATTLE_BG_INSIDE_STD:
		attack = ATTACK_BODYCHECK;
		break;
	case BATTLE_BG_ICE_CAVE:
		attack = ATTACK_EISSTURM;
		break;
	}
	u8 *animation = attack_anims[attack];
	attack_anim_script = animation;
	battle_animation_big_callback_delete(self);
}

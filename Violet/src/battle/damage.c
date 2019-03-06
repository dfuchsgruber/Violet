/*
 * damage.c
 *
 *  Created on: Feb 12, 2019
 *      Author: dominik
 */

#include "types.h"
#include "battle/battler.h"
#include "battle/attack.h"
#include "battle/state.h"
#include "constants/abilities.h"
#include "constants/flags.h"
#include "constants/attacks.h"
#include "constants/attack_results.h"
#include "attack.h"
#include "debug.h"
#include "constants/items.h"
#include "battle/battlescript.h"
#include "item/item.h"
#include "flags.h"
#include "constants/item_hold_effects.h"
#include "constants/attack_categories.h"

// TODO: investigate this in the future, maybe...
/**
int calculate_base_damage(battler *attacker, battler *defender, u32 move, u16 side_status,
		u16 override_power, u8 override_type, u8 battler_idx_attacking, u8 battler_idx_defending) {
	(void)(side_status);
	(void)(defender);
	if (override_power) move_power = override_power;
	else move_power = attacks[move].base_power;
	u8 type;
	if (override_type) type = override_type & 0x3F;
	else type = attacks[move].type;
	int attack = attacker->stats[STAT_ATTACK];
	int defense = attacker->stats[STAT_DEFENSE];
	int special_attack = attacker->stats[STAT_SPECIAL_ATTACK];
	int special_defense = attacker->stats[STAT_SPECIAL_DEFENSE];
	u8 held_item_effect;
	u8 held_item_effect_parameter;
	if (attacker->item == ITEM_ENIGMABEERE) {
		held_item_effect = enigma_berries[battler_idx_attacking].hold_effect;
		held_item_effect_parameter = enigma_berries[battler_idx_attacking].hold_effect_parameter;
	} else {
		held_item_effect = item_get_hold_effect(attacker->item);
		held_item_effect_parameter = item_get_hold_effect_parameter(attacker->item);
	}
	// Abilities to boost attack values
	if (attacker->ability == KRAFTKOLOSS || attacker->ability == MENTALKRAFT)
		attack *= 2;
	if (!battle_flags.link_battle && !battle_flags.ereader_trainer && !battle_flags.battle_tower &&
			!battler_is_opponent(battler_idx_defending)) {
		if (checkflag(FRBADGE_1)) attack = (110 * attack) / 100;
		if (checkflag(FRBADGE_5)) defense = (110 * defense) / 100;
		if (checkflag(FRBADGE_7)){
			special_attack = (110 * special_attack) / 100;
			special_defense = (110 * special_defense) / 100;
		}
	}
	// Attack/Satk Boost for held items
	for (int i = 0; i < ITEM_HOLD_EFFECT_TYPE_BOOSTS_SIZE; i++) {
		if (item_hold_effect_type_boosts[i].hold_effect == held_item_effect &&
				item_hold_effect_type_boosts[i].type == type) {
			if (attacks[move].category == CATEGORY_PHYSICAL)
				attack = (attack * (held_item_effect_parameter + 100)) / 100;
			else if (attacks[move].category == CATEGORY_SPECIAL)
				special_attack = (attack * (held_item_effect_parameter + 100)) / 100;
			break;
		}
	}
	return 0;
}
**/

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
#include "battle/weather.h"
#include "battle/ressources.h"
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
#include "constants/pokemon_types.h"
#include "item/custom.h"
#include "abilities.h"
#include "constants/attack_affects_whom_flags.h"
#include "constants/battle/battle_side_statuses.h"
#include "constants/attack_flags.h"

static const u8 hold_effect_to_type[][2] = {
    {HOLD_EFFECT_BUG_POWER, TYPE_KAEFER},
    {HOLD_EFFECT_STEEL_POWER, TYPE_STAHL},
    {HOLD_EFFECT_GROUND_POWER, TYPE_BODEN},
    {HOLD_EFFECT_ROCK_POWER, TYPE_GESTEIN},
    {HOLD_EFFECT_GRASS_POWER, TYPE_PFLANZE},
    {HOLD_EFFECT_DARK_POWER, TYPE_UNLICHT},
    {HOLD_EFFECT_FIGHTING_POWER, TYPE_KAMPF},
    {HOLD_EFFECT_ELECTRIC_POWER, TYPE_ELEKTRO},
    {HOLD_EFFECT_WATER_POWER, TYPE_WASSER},
    {HOLD_EFFECT_FLYING_POWER, TYPE_FLUG},
    {HOLD_EFFECT_POISON_POWER, TYPE_GIFT},
    {HOLD_EFFECT_ICE_POWER, TYPE_EIS},
    {HOLD_EFFECT_GHOST_POWER, TYPE_GEIST},
    {HOLD_EFFECT_PSYCHIC_POWER, TYPE_PSYCHO},
    {HOLD_EFFECT_FIRE_POWER, TYPE_FEUER},
    {HOLD_EFFECT_DRAGON_POWER, TYPE_DRACHE},
    {HOLD_EFFECT_NORMAL_POWER, TYPE_NORMAL},
    {HOLD_EFFECT_FAIRY_POWER, TYPE_FEE},
};

#define APPLY_STAT_MOD(var, mon, stat, statIndex)                                   \
{                                                                                   \
    (var) = (stat) * (battle_stat_change_multipliers)[(mon)->stat_changes[(statIndex)]][0];         \
    (var) /= (battle_stat_change_multipliers)[(mon)->stat_changes[(statIndex)]][1];                 \
}

int battle_base_damage_calculate(battler *attacker, battler *defender, u32 move, u16 sideStatus, u16 powerOverride, u8 typeOverride, u8 battlerIdAtk, u8 battlerIdDef) {
    int damage = 0;
    int damageHelper;
    u8 type;
    int attack, defense;
    int spAttack, spDefense;
    u8 defenderHoldEffect;
    u8 defenderHoldEffectParam;
    u8 attackerHoldEffect;
    u8 attackerHoldEffectParam;

	DEBUG("Damage base calc attacker species %d, defender species %d, move %d, side_status %d, power override %d, type override %d, attacking_battler_idx %d, defending_battler_idx %d\n",
		attacker->species, defender->species, move, sideStatus, powerOverride, typeOverride, battlerIdAtk, battlerIdDef);

    // DEBUG("Dynamic base power is %d\n", battle_dynamic_base_power);

    if (!powerOverride)
        move_power = attacks[move].base_power;
    else
        move_power = powerOverride;
    if (!typeOverride)
        type = attacks[move].type;
    else {
        type = (u8)(typeOverride & 0x3F);
	}

	attack = attacker->stats[STAT_ATTACK - 1];
    defense = defender->stats[STAT_DEFENSE - 1];
    spAttack = attacker->stats[STAT_SPECIAL_ATTACK - 1];
    spDefense = defender->stats[STAT_SPECIAL_DEFENSE - 1];
	// DEBUG("Damage base calc: Attacker has attack %d, defender has defense %d\n", attacker->stats[STAT_ATTACK - 1], defender->stats[STAT_DEFENSE - 1]);
    

    if (attacker->item == ITEM_ENIGMABEERE) {
        attackerHoldEffect = enigma_berries[battlerIdAtk].hold_effect;
        attackerHoldEffectParam = enigma_berries[battlerIdAtk].hold_effect_parameter;
    } else {
        attackerHoldEffect = item_get_hold_effect(attacker->item);
        attackerHoldEffectParam = item_get_hold_effect_parameter(attacker->item);
    }

    if (defender->item == ITEM_ENIGMABEERE) {
        defenderHoldEffect = enigma_berries[battlerIdDef].hold_effect;
        defenderHoldEffectParam = enigma_berries[battlerIdDef].hold_effect_parameter;
    } else {
        defenderHoldEffect = item_get_hold_effect(defender->item);
        defenderHoldEffectParam = item_get_hold_effect_parameter(defender->item);
    }
	(void) defenderHoldEffectParam;
    if (attacker->ability == KRAFTKOLOSS || attacker->ability == MENTALKRAFT)
        attack *= 2;

    for (u8 i = 0; i < ARRAY_COUNT(hold_effect_to_type); i++) 
    {
        if (attackerHoldEffect == hold_effect_to_type[i][0] && type == hold_effect_to_type[i][1])
        {
            if (attacks[move].category == CATEGORY_PHYSICAL)
                attack = (attack * (attackerHoldEffectParam + 100)) / 100;
            else if (attacks[move].category == CATEGORY_SPECIAL)
                spAttack = (spAttack * (attackerHoldEffectParam + 100)) / 100;
            break;
        }
    }
    if (attackerHoldEffect == HOLD_EFFECT_BOOST_PHYSICAL_MOVES && attacks[move].category == CATEGORY_PHYSICAL) {
        attack = (attack * (attackerHoldEffectParam + 100)) / 100;
    }
    if (attackerHoldEffect == HOLD_EFFECT_BOOST_SPECIAL_MOVES && attacks[move].category == CATEGORY_SPECIAL) {
        attack = (attack * (attackerHoldEffectParam + 100)) / 100;
    }
	if (attackerHoldEffect == HOLD_EFFECT_CHOICE_ITEM && attackerHoldEffectParam == CHOICE_ITEM_BAND)
		attack = (150 * attack) / 100;
	if (attackerHoldEffect == HOLD_EFFECT_CHOICE_ITEM && attackerHoldEffectParam == CHOICE_ITEM_SPECS)
		spAttack = (150 * attack) / 100;
    if (attackerHoldEffect == HOLD_EFFECT_CHOICE_ITEM)
        attack = (150 * attack) / 100;
    if (attackerHoldEffect == HOLD_EFFECT_SOUL_DEW && !(battle_flags & (BATTLE_TOWER)) && (attacker->species == POKEMON_LATIAS || attacker->species == POKEMON_LATIOS))
        spAttack = (150 * spAttack) / 100;
    if (defenderHoldEffect == HOLD_EFFECT_SOUL_DEW && !(battle_flags & (BATTLE_TOWER)) && (defender->species == POKEMON_LATIAS || defender->species == POKEMON_LATIOS))
        spDefense = (150 * spDefense) / 100;
    if (attackerHoldEffect == HOLD_EFFECT_DEEP_SEA_TOOTH && attacker->species == POKEMON_PERLU)
        spAttack *= 2;
    if (defenderHoldEffect == HOLD_EFFECT_DEEP_SEA_SCALE && defender->species == POKEMON_PERLU)
        spDefense *= 2;
    if (attackerHoldEffect == HOLD_EFFECT_LIGHT_BALL && attacker->species == POKEMON_PIKACHU)
        spAttack *= 2;
    if (defenderHoldEffect == HOLD_EFFECT_METAL_POWDER && defender->species == POKEMON_DITTO)
        defense *= 2;
    if (defenderHoldEffect == HOLD_EFFECT_ASSAULT_VEST)
        spDefense = (150 * spDefense) / 100;
    if (attackerHoldEffect == HOLD_EFFECT_THICK_CLUB && (attacker->species == POKEMON_TRAGOSSO || attacker->species == POKEMON_KNOGGA))
        attack *= 2;
    if (defender->ability == SPECKSCHICHT && (type == TYPE_FEUER || type == TYPE_EIS))
        spAttack /= 2;
    if (attacker->ability == UEBEREIFER)
        attack = (150 * attack) / 100;
    if (attacker->ability == PLUS && ABILITY_PRESENT2(MINUS))
        spAttack = (150 * spAttack) / 100;
    if (attacker->ability == MINUS && ABILITY_PRESENT2(PLUS))
        spAttack = (150 * spAttack) / 100;
    if (attacker->ability == ADRENALIN && attacker->status1)
        attack = (150 * attack) / 100;
    if (defender->ability == NOTSCHUTZ && defender->status1)
        defense = (150 * defense) / 100;
    if (type == TYPE_ELEKTRO && ability_execute(ABILITY_CONTEXT_FIELD_SPORT, 0, 0, 0xFD, 0))
        move_power /= 2;
    if (type == TYPE_FEUER && ability_execute(ABILITY_CONTEXT_FIELD_SPORT, 0, 0, 0xFE, 0))
        move_power /= 2;
    if (type == TYPE_PFLANZE && attacker->ability == NOTDUENGER && attacker->current_hp <= (attacker->max_hp / 3))
        move_power = (u16)((150 * move_power) / 100);
    if (type == TYPE_FEUER && attacker->ability == GROSSBRAND && attacker->current_hp <= (attacker->max_hp / 3))
        move_power = (u16)((150 * move_power) / 100);
    if (type == TYPE_WASSER && attacker->ability == STURZBACH && attacker->current_hp <= (attacker->max_hp / 3))
        move_power = (u16)((150 * move_power) / 100);
    if (type == TYPE_KAEFER && attacker->ability == HEXAPLAGA && attacker->current_hp <= (attacker->max_hp / 3))
        move_power = (u16)((150 * move_power) / 100);
    if (attacks[move].effect == 7) // Explosion
        defense /= 2;
    if (attacker->ability == KRALLENWUCHT && (attacks[move].flags & MAKES_CONTACT))
        move_power = (u16)((130 * move_power) / 100);
	
    if (attacks[move].category == CATEGORY_PHYSICAL) {
		// DEBUG("Physical base damage calc: attack %d, defense %d, move power %d\n", attack, defense, move_power);
        if (critical_hit_multiplier == 2) {
            if (attacker->stat_changes[STAT_ATTACK] > 6)
                APPLY_STAT_MOD(damage, attacker, attack, STAT_ATTACK)
            else
                damage = attack;
        } else {
			APPLY_STAT_MOD(damage, attacker, attack, STAT_ATTACK)
		}
        damage = damage * move_power;
        damage *= (2 * attacker->level / 5 + 2);

        if (critical_hit_multiplier == 2)
        {
            if (defender->stat_changes[STAT_DEFENSE] < 6)
                APPLY_STAT_MOD(damageHelper, defender, defense, STAT_DEFENSE)
            else
                damageHelper = defense;
        }
        else
            APPLY_STAT_MOD(damageHelper, defender, defense, STAT_DEFENSE)

		// DEBUG("Physical damage %d / %d\n", damage, damageHelper);

        damage = damage / damageHelper;
        damage /= 50;

		// DEBUG("Physical Base-Damage after stat-mod is %d\n", damage);

        if ((attacker->status1 & STATUS1_BURNED) && attacker->ability != ADRENALIN)
            damage /= 2;

        if ((sideStatus & SIDE_STATUS_REFLECT) && critical_hit_multiplier == 1) {
            if ((battle_flags & BATTLE_DOUBLE) && battlers_alive(ALIVE_DEFENDING_SIDE) == 2)
                damage = 2 * (damage / 3);
            else
                damage /= 2;
        }

        if ((battle_flags & BATTLE_DOUBLE) && attacks[move].affects_whom == TARGET_BOTH_FOES && battlers_alive(ALIVE_DEFENDING_SIDE) == 2)
            damage /= 2;

        // moves always do at least 1 damage.
        if (damage == 0)
            damage = 1;
    } else if (attacks[move].category == CATEGORY_SPECIAL) {
        if (critical_hit_multiplier == 2) {
            if (attacker->stat_changes[STAT_SPECIAL_ATTACK] > 6)
                APPLY_STAT_MOD(damage, attacker, spAttack, STAT_SPECIAL_ATTACK)
            else
                damage = spAttack;
        } else
            APPLY_STAT_MOD(damage, attacker, spAttack, STAT_SPECIAL_ATTACK)

        damage = damage * move_power;
        damage *= (2 * attacker->level / 5 + 2);

        if (critical_hit_multiplier == 2) {
            if (defender->stat_changes[STAT_SPECIAL_DEFENSE] < 6)
                APPLY_STAT_MOD(damageHelper, defender, spDefense, STAT_SPECIAL_DEFENSE)
            else
                damageHelper = spDefense;
        }
        else
            APPLY_STAT_MOD(damageHelper, defender, spDefense, STAT_SPECIAL_DEFENSE)

        damage = (damage / damageHelper);
        damage /= 50;

        if ((sideStatus & SIDE_STATUS_LIGHTSCREEN) && critical_hit_multiplier == 1) {
            if ((battle_flags & BATTLE_DOUBLE) && battlers_alive(ALIVE_DEFENDING_SIDE) == 2)
                damage = 2 * (damage / 3);
            else
                damage /= 2;
        }
        if ((battle_flags & BATTLE_DOUBLE) && attacks[move].affects_whom == TARGET_BOTH_FOES && battlers_alive(ALIVE_DEFENDING_SIDE) == 2)
            damage /= 2;
    } 
	// are effects of weather negated with cloud nine or air lock
	if (WEATHER_HAS_EFFECT2) {
		if (battle_weather & BATTLE_WEATHER_RAIN_ANY) {
			switch (type) {
			case TYPE_FEUER:
				damage /= 2;
				break;
			case TYPE_WASSER:
				damage = (15 * damage) / 10;
				break;
			}
		}

		// any weather except sun weakens solar beam
		if ((battle_weather & (BATTLE_WEATHER_RAIN_ANY | BATTLE_WEATHER_SANDSTORM_ANY | BATTLE_WEATHER_HAIL_ANY)) && move == ATTACK_SOLARSTRAHL)
			damage /= 2;

		// sunny
		if (battle_weather & BATTLE_WEATHER_SUN_ANY) {
			switch (type) {
			case TYPE_FEUER:
				damage = (15 * damage) / 10;
				break;
			case TYPE_WASSER:
				damage /= 2;
				break;
			}
		}
	}
	
	// flash fire triggered
	if ((battle_ressources->flags->flags[battlerIdAtk] & RESOURCE_FLAG_FLASH_FIRE) && type == TYPE_FEUER)
		damage = (15 * damage) / 10;

	// DEBUG("Final Base-Damage is %d\n", damage);

    return damage + 2;
}


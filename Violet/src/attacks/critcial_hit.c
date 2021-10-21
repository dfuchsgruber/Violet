/*
 * critcial_hit.c
 *
 *  Created on: Feb 14, 2019
 *      Author: dominik
 */

#include "attack.h"
#include "battle/attack.h"
#include "battle/battler.h"
#include "battle/battlescript.h"
#include "battle/state.h"
#include "constants/abilities.h"
#include "constants/attack_effects.h"
#include "constants/item_hold_effects.h"
#include "constants/items.h"
#include "constants/species.h"
#include "item/item.h"
#include "math.h"
#include "prng.h"
#include "types.h"

// The chance of landing a critical hit at crit. stat i equals 1 / x[i]
u16 critical_hit_chances[5] = {
    10, 8, 4, 2, 1};

void bsc_command_x04_critcalc() {
    u16 item = battlers[attacking_battler].item;
    u8 hold_effect = item_get_hold_effect(item);
    if (item == ITEM_ENIGMABEERE)
        hold_effect = enigma_berries[attacking_battler].hold_effect;
    item_target_battler = attacking_battler;
    int critical_level = 0;
    if (battlers[attacking_battler].status2 & STATUS2_FOCUS_ENERGY)
        critical_level += 2;
    u8 move_effect = attacks[active_attack].effect;
    if (move_effect == ATTACK_EFFECT_HIGH_CRITICAL ||
        move_effect == ATTACK_EFFECT_SKY_ATTACK || move_effect == ATTACK_EFFECT_BLAZE_KICK ||
        move_effect == ATTACK_EFFECT_POISON_TAIL)
        critical_level++;
    if (hold_effect == HOLD_EFFECT_SCOPE_LENS)
        critical_level++;
    if (hold_effect == HOLD_EFFECT_LUCKY_PUNCH &&
        battlers[attacking_battler].species == POKEMON_CHANEIRA)
        critical_level += 2;
    if (hold_effect == HOLD_EFFECT_STICK &&
        battlers[attacking_battler].species == POKEMON_PORENTA)
        critical_level += 2;
    if (battlers[attacking_battler].ability == GLUECKSPILZ ||
        battlers[attacking_battler].ability == ESCHAT)
        critical_level++;
    critical_level = MIN(ARRAY_COUNT(critical_hit_chances) - 1, 4);

    // Roll for a critical hit
    if (battlers[defending_battler].ability != KAMPFPANZER &&
        battlers[defending_battler].ability != PANZERHAUT &&
        !(battler_statuses3[attacking_battler] & STATUS3_CANT_SCORE_A_CRIT) &&
        !(battle_flags & BATTLE_TUTORIAL) &&
        !(rnd16() % critical_hit_chances[critical_level]))
        critical_hit_multiplier = 2;
    else
        critical_hit_multiplier = 1;

    bsc_offset++;
}

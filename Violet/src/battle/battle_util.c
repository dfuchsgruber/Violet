#include "types.h"
#include "battle/state.h"
#include "battle/battler.h"
#include "debug.h"
#include "overworld/pokemon_party_menu.h"
#include "battle/attack.h"
#include "constants/attacks.h"
#include "item/item.h"
#include "attack.h"
#include "constants/item_hold_effects.h"
#include "constants/attack_categories.h"

pokemon *battler_load_party_range(u8 battler_idx, u8 *first, u8 *last) {
    if (battle_flags & BATTLE_MULTI) {
        *first = link_trainer_is_at_flank(battler_get_multiplayer_idx(battler_idx)) ? 3 : 0;
        *last = (u8)(*first + 3);
    } else {
        // Regular non-link battle
        if (SIDE(battler_idx) == BATTLE_SIDE_OPPONENT && (battle_flags & BATTLE_TWO_TRAINERS)) {
            *first = battler_get_position(battler_idx) == BATTLE_POSITION_OPPONENT_RIGHT ? 3 : 0;
            *last = (u8)(*first + 3);
        } else if (SIDE(battler_idx) == BATTLE_SIDE_PLAYER && (battle_flags & BATTLE_ALLY)) {
            *first = battler_get_position(battler_idx) == BATTLE_POSITION_PLAYER_RIGHT ? 3 : 0;
            *last = (u8)(*first + 3);
        } else {
            *first = 0;
            *last = 6;
        }
    }
    return SIDE(battler_idx) == BATTLE_SIDE_OPPONENT ? opponent_pokemon : player_pokemon;
}


void battler_get_partner_and_foes(u8 battler, u8 *partner, u8 *foe, u8 *foe_partner) {
    if (battle_flags & BATTLE_DOUBLE) {
        if (partner) *partner = PARTNER(battler);
        if (foe) *foe = OPPONENT(battler);
        if (foe_partner) *foe_partner = PARTNER(*foe);
    } else {
        if (partner) *partner = battler;
        if (foe) *foe = OPPONENT(battler);
        if (foe_partner) *foe_partner = *foe;
    }
}

bool battle_is_tag() {
    return (battle_flags & (BATTLE_ALLY | BATTLE_MULTI)) != 0 && (battle_flags & BATTLE_DOUBLE) != 0;
}

bool battle_has_two_opponents() {
    return (battle_flags & (BATTLE_TWO_TRAINERS | BATTLE_MULTI)) != 0 && (battle_flags & BATTLE_DOUBLE) != 0;
}

extern u16 battler_party_idxs[4];

// In retrospective - this function is suuuuper unneccesary...
u8 battler_idx_to_party_idx(u8 battler_idx) {
    return (u8)battler_party_idxs[battler_idx];
}

bool battler_has_no_switching_targets(u8 battler_idx, u8 party_idx, u8 partner_party_idx) {
    if (!(battle_flags & BATTLE_DOUBLE)) return false;
    u8 first = 0, last = 0;
    pokemon *party = battler_load_party_range(battler_idx, &first, &last);
    if (party_idx == 6)
        party_idx = (u8) battler_idx_to_party_idx(battler_idx);
    if (partner_party_idx == 6)
        partner_party_idx = (u8) battler_idx_to_party_idx(PARTNER(battler_idx));
    DEBUG("Battler %d has switching target?\nparty_idx %d, partner_party_idx %d\n", battler_idx, party_idx, partner_party_idx);
    for (int i = first; i < last; i++) {
        if (POKEMON_IS_VIABLE(party + i) && i != party_idx && i != partner_party_idx) {
            DEBUG("Party idx %d is viable.\n", i);
            return false;
        }
    }
    DEBUG("Battler %d has no swichting targets.\n", battler_idx);
    return true;
}

bool battler_is_alive(u8 battler_idx) {
    if (battlers[battler_idx].current_hp <= 0) 
        return false;
    if (battler_idx >= battler_cnt)
        return false;
    if (battlers_absent & int_bitmasks[battler_idx])
        return false;
    return true;
}

bool battle_active_attack_should_do_animation() {
    if (active_attack == ATTACK_DELEGATOR || active_attack == ATTACK_WANDLER) // Even with no animations, these ones are needed for the game to work
        return true;
    if (active_attack == ATTACK_TELEPORT && BATTLE_IS_WILD_DOUBLE && battler_is_opponent(attacking_battler) && battler_is_alive(PARTNER(attacking_battler)))
        return true; // In a double battle against two wilds, the teleport animation is required if both of them are still alive
    return (bsc_status_flags & 0x80) == 0; // 0x80: Animations inactive
}

void battler_get_hold_item_effect_and_parameter(u8 battler_idx, u8 *hold_effect, u8 *hold_effect_param) {
    if (battlers[battler_idx].item == ITEM_ENIGMABEERE) {
        *hold_effect = enigma_berries[battler_idx].hold_effect;
        *hold_effect_param = enigma_berries[battler_idx].hold_effect_parameter;
    } else {
        *hold_effect = item_get_hold_effect(battlers[battler_idx].item);
        *hold_effect_param = item_get_hold_effect_parameter(battlers[battler_idx].item);
    }
}

extern u8 bsc_attack_disabled[];
extern u8 bsc_attack_disabled_by_torment[];
extern u8 bsc_attack_disabled_by_taunt[];
extern u8 bsc_attack_disabled_by_imprison[];
extern u8 bsc_attack_disabled_by_choice_item[];
extern u8 bsc_attack_has_no_pp[];
extern u8 bsc_attack_disabled_by_assault_vest[];

u8 battle_player_set_move_selection_battlescript() {
    u8 hold_effect, hold_effect_param;
    battler_get_hold_item_effect_and_parameter(active_battler, &hold_effect, &hold_effect_param);
    u8 move_slot = battle_general_buffers1[active_battler][2];
    u16 move = battlers[active_battler].moves[move_slot];
    u8 limitations = 0;
    u16 *choiced_move = battle_state->choiced_move + active_battler;

    if (battler_disable[active_battler].disabled_move == move && move != 0) {
        battle_scripting.battler_idx = active_battler;
        active_attack = move;
        battler_move_selection_battlescripts[active_battler] = bsc_attack_disabled;
        limitations++;
    }
    if (move == battler_last_move[active_battler] && move != ATTACK_VERZWEIFLER && (battlers[active_battler].status2 & STATUS2_TORMENT)) {
        battler_cancel_multiturn_moves(active_battler);
        battler_move_selection_battlescripts[active_battler] = bsc_attack_disabled_by_torment;
        limitations++;
    }
    if (attacks[move].base_power == 0 && battler_disable[active_battler].taunt_timer > 0) {
        active_attack = move;
        battler_move_selection_battlescripts[active_battler] = bsc_attack_disabled_by_taunt;
        limitations++;
    }
    if (battle_move_get_imprison_count(active_battler, move) > 0) {
        active_attack = move;
        battler_move_selection_battlescripts[active_battler] = bsc_attack_disabled_by_imprison;
        limitations++;
    }
    item_target_battler = active_battler;
    if (hold_effect == HOLD_EFFECT_CHOICE_ITEM && *choiced_move != 0 && *choiced_move != 0xFFFF && *choiced_move != move) {
        active_attack = *choiced_move;
        bsc_last_used_item = battlers[active_battler].item;
        battler_move_selection_battlescripts[active_battler] = bsc_attack_disabled_by_choice_item;
        limitations++;
    }
    if (hold_effect == HOLD_EFFECT_ASSAULT_VEST && attacks[move].category == CATEGORY_STATUS) {
        active_attack = move;
        bsc_last_used_item = battlers[active_battler].item;
        battler_move_selection_battlescripts[active_battler] = bsc_attack_disabled_by_assault_vest;
        limitations++;
    }
    if (battlers[active_battler].current_pp[move_slot] == 0) {
        battler_move_selection_battlescripts[active_battler] = bsc_attack_has_no_pp;
        limitations++;
    }
    return limitations;
}

u8 battler_check_move_limitations(u8 battler_idx, u8 mask, u8 check) {
    u16 *choiced_move = battle_state->choiced_move + battler_idx;
    u8 hold_effect;
    u8 hold_effect_param; 
    battler_get_hold_item_effect_and_parameter(battler_idx, &hold_effect, &hold_effect_param);
    item_target_battler = battler_idx;
    for (int i = 0; i < 4; i++) {
        if ((check & MOVE_LIMITATION_ZEROMOVE) && battlers[battler_idx].moves[i] == 0)
            mask = (u8)(mask | int_bitmasks[i]);
        if ((check & MOVE_LIMITATION_PP) && battlers[battler_idx].current_pp[i] == 0)
            mask = (u8)(mask | int_bitmasks[i]);
        if ((check & MOVE_LIMITATION_DISABLED) && battler_disable[battler_idx].disabled_move == battlers[battler_idx].moves[i])
            mask = (u8)(mask | int_bitmasks[i]);
        if ((check & MOVE_LIMITATION_TORMENTED) && battlers[battler_idx].moves[i] == battler_last_move[battler_idx] && (battlers[battler_idx].status2 & STATUS2_TORMENT))
            mask = (u8)(mask | int_bitmasks[i]);
        if ((check & MOVE_LIMITATION_TAUNT) && attacks[battlers[battler_idx].moves[i]].base_power == 0 && battler_disable[battler_idx].taunt_timer > 0)
            mask = (u8)(mask | int_bitmasks[i]);
        if ((check & MOVE_LIMITATION_IMPRISON) && battle_move_get_imprison_count(battler_idx, battlers[battler_idx].moves[i]) > 0)
            mask = (u8)(mask | int_bitmasks[i]);
        // General limitations
        if (battler_disable[battler_idx].encore_timer > 0 && battler_disable[battler_idx].encore_move != battlers[battler_idx].moves[i])
            mask = (u8)(mask | int_bitmasks[i]);
        if (hold_effect == HOLD_EFFECT_CHOICE_ITEM && *choiced_move != 0 && *choiced_move != 0xFFFF && *choiced_move != battlers[battler_idx].moves[i])
            mask = (u8)(mask | int_bitmasks[i]);
        if (hold_effect == HOLD_EFFECT_ASSAULT_VEST && attacks[battlers[battler_idx].moves[i]].category == CATEGORY_STATUS)
            mask = (u8)(mask | int_bitmasks[i]);
    }
    return mask;
}
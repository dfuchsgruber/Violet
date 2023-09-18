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
#include "battle/communication.h"
#include "constants/abilities.h"
#include "battle/controller.h"
#include "prng.h"

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

u8 battle_get_unown_battler_that_disables_move(u16 move, u8 attacker) {
    for (u8 i = 0; i < battler_cnt; i++) {
        if (battler_is_opponent(i) != battler_is_opponent(attacker) && battler_is_alive(i) && battlers[i].species == POKEMON_ICOGNITO) {
            // Only prevents for foes
            u16 item_idx = battlers[i].item;
            if (item_idx && item_get_hold_effect(item_idx) == HOLD_EFFECT_LIMIT_MOVES_BY_UNOWN_LETTER) {
                int letter_idx = pokemon_unown_get_letter(battlers[i].pid);
                if(string_count_unown_letters(attack_names[move], letter_idx) > 0)
                    return i;
            }
        }
    }
    return battler_cnt;
}

extern const u8 bsc_attack_disabled[];
extern const u8 bsc_attack_disabled_by_torment[];
extern const u8 bsc_attack_disabled_by_taunt[];
extern const u8 bsc_attack_disabled_by_imprison[];
extern const u8 bsc_attack_disabled_by_choice_item[];
extern const u8 bsc_attack_has_no_pp[];
extern const u8 bsc_attack_disabled_by_assault_vest[];
extern const u8 bsc_attack_disabled_by_runenband[];

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
    u8 unown_battler_that_disables = battle_get_unown_battler_that_disables_move(battlers[active_battler].moves[move_slot],
        active_battler);
    if (unown_battler_that_disables < battler_cnt) {
        active_attack = move;
        bsc_last_used_item = battlers[unown_battler_that_disables].item;
        battler_move_selection_battlescripts[active_battler] = bsc_attack_disabled_by_runenband;
        defending_battler = unown_battler_that_disables;
        int letter = pokemon_unown_get_letter(battlers[unown_battler_that_disables].pid);
        buffer0[0] = (u8)(letter + 0xBB);
        buffer0[1] = 0xFF;
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
        if (battle_get_unown_battler_that_disables_move(battlers[battler_idx].moves[i], battler_idx) < battler_cnt)
            mask = (u8)(mask | int_bitmasks[i]);
    }   
    return mask;
}


enum {
    ATTACK_CANCELLER_FLAGS,
    ATTACK_CANCELLER_ASLEEP,
    ATTACK_CANCELLER_FROZEN,
    ATTACK_CANCELLER_TRUANT,
    ATTACK_CANCELLER_RECHARGE,
    ATTACK_CANCELLER_FLINCH,
    ATTACK_CANCELLER_DISABLED,
    ATTACK_CANCELLER_TAUNTED,
    ATTACK_CANCELLER_IMPRISONED,
    ATTACK_CANCELLER_BY_GLYPH,
    ATTACK_CANCELLER_CONFUSED,
    ATTACK_CANCELLER_PARALYSED,
    ATTACK_CANCELLER_GHOST,
    ATTACK_CANCELLER_IN_LOVE,
    ATTACK_CANCELLER_BIDE,
    ATTACK_CANCELLER_THAW,
    ATTACK_CANCELLER_END,
};

extern const u8 bsc_move_used_battler_woke_up[];
extern const u8 bsc_move_used_is_fast_asleep[];
extern const u8 bsc_move_used_is_frozen_solid[];
extern const u8 bsc_move_used_unfroze[];
extern const u8 bsc_move_used_truant_active[];
extern const u8 bsc_move_used_must_recharge[];
extern const u8 bsc_move_used_flinched[];
extern const u8 bsc_move_used_is_disabled[];
extern const u8 bsc_move_used_is_taunted[];
extern const u8 bsc_move_used_is_imprisoned[];
extern const u8 bsc_move_used_snapped_out_of_confusion[];
extern const u8 bsc_move_used_is_confused[];
extern const u8 bsc_move_used_is_paralyzed[];
extern const u8 bsc_move_used_is_immobilized_by_infatuation[];
extern const u8 bsc_move_used_is_in_love[];
extern const u8 bsc_move_used_bide_is_storing_energy[];
extern const u8 bsc_move_used_bide_release_energy[];
extern const u8 bsc_move_used_bide_no_energy_to_release[];
extern const u8 bsc_move_used_unfroze[];
extern const u8 bsc_move_used_disabled_by_runenband[];

u8 battle_attack_canceler_try_cancel_by_unable_to_move() {
    u8 effect = 0;
    int *bideDmg = &battle_scripting.bide_damage;
    do {
        switch (battle_state->attack_canceler_state)  {
        case ATTACK_CANCELLER_FLAGS: // flags clear
            battlers[attacking_battler].status2 &= (u32)(~(STATUS2_DESTINY_BOND));
            battler_statuses3[attacking_battler] &= (u32)(~(STATUS3_GRUDGE));
            ++battle_state->attack_canceler_state;
            break;
        case ATTACK_CANCELLER_ASLEEP: // check being asleep
            if (battlers[attacking_battler].status1 & STATUS1_SLEEPING) {
                if (battler_is_woken_up_by_uproar(attacking_battler)) {
                    battlers[attacking_battler].status1 &= (u32)(~(STATUS1_SLEEPING));
                    battlers[attacking_battler].status2 &= (u32)(~(STATUS2_NIGHTMARE));
                    battlescript_callstack_push_next_command();
                    battle_communication[BATTLE_COMMUNICATION_MULTISTRING_CHOOSER] = 1;
                    bsc_offset = bsc_move_used_battler_woke_up;
                    effect = 2;
                } else {
                    u8 sleep_turns_to_subtract;
                    if (battlers[attacking_battler].ability == FRUEHWECKER)
                        sleep_turns_to_subtract = 2;
                    else
                        sleep_turns_to_subtract = 1;
                    if ((battlers[attacking_battler].status1 & STATUS1_SLEEPING) < sleep_turns_to_subtract)
                        battlers[attacking_battler].status1 &= (u32)(~(STATUS1_SLEEPING));
                    else
                        battlers[attacking_battler].status1 -= sleep_turns_to_subtract;
                    if (battlers[attacking_battler].status1 & STATUS1_SLEEPING) {
                        if (active_attack != ATTACK_SCHNARCHER && active_attack != ATTACK_SCHLAFREDE) {
                            bsc_offset = bsc_move_used_is_fast_asleep;
                            bsc_status_flags |= BSC_STATUS_FLAG_UNABLE_TO_USE_MOVE;
                            effect = 2;
                        }
                    } else {
                        battlers[attacking_battler].status2 &= (u32)(~(STATUS2_NIGHTMARE));
                        battlescript_callstack_push_next_command();
                        battle_communication[BATTLE_COMMUNICATION_MULTISTRING_CHOOSER] = 0;
                        bsc_offset = bsc_move_used_battler_woke_up;
                        effect = 2;
                    }
                }
            }
            ++battle_state->attack_canceler_state;
            break;
        case ATTACK_CANCELLER_FROZEN: // check being frozen
            if (battlers[attacking_battler].status1 & STATUS1_FROZEN) {
                if (rnd16() % 5) {
                    if (attacks[active_attack].effect != 0x7D) { // unfreezing via a move effect happens in case `ATTACK_CANCELLER_THAW`
                        bsc_offset = bsc_move_used_is_frozen_solid;
                        bsc_status_flags |= BSC_STATUS_FLAG_NO_ATTACKSTRING;
                    } else {
                        ++battle_state->attack_canceler_state;
                        break;
                    }
                } else { // unfreeze 
                    battlers[attacking_battler].status1 &= (u32)(~(STATUS1_FROZEN));
                    battlescript_callstack_push_next_command();
                    bsc_offset = bsc_move_used_unfroze;
                    battle_communication[BATTLE_COMMUNICATION_MULTISTRING_CHOOSER] = 0;
                }
                effect = 2;
            }
            ++battle_state->attack_canceler_state;
            break;
        case ATTACK_CANCELLER_TRUANT: // truant
            if (battlers[attacking_battler].ability == SCHNARCHNASE && battler_disable[attacking_battler].truant_counter) {
                battler_cancel_multiturn_moves(attacking_battler);
                bsc_status_flags |= BSC_STATUS_FLAG_UNABLE_TO_USE_MOVE;
                battle_communication[BATTLE_COMMUNICATION_MULTISTRING_CHOOSER] = 0;
                bsc_offset = bsc_move_used_truant_active;
                attack_result |= ATTACK_MISSED;
                effect = 1;
            }
            ++battle_state->attack_canceler_state;
            break;
        case ATTACK_CANCELLER_RECHARGE: // recharge
            if (battlers[attacking_battler].status2 & STATUS2_RECHARGE)
            {
                battlers[attacking_battler].status2 &= (u32)(~(STATUS2_RECHARGE));
                battler_disable[attacking_battler].recharge_timer = 0;
                battler_cancel_multiturn_moves(attacking_battler);
                bsc_offset = bsc_move_used_must_recharge;
                bsc_status_flags |= BSC_STATUS_FLAG_UNABLE_TO_USE_MOVE;
                effect = 1;
            }
            ++battle_state->attack_canceler_state;
            break;
        case ATTACK_CANCELLER_FLINCH: // flinch
            if (battlers[attacking_battler].status2 & STATUS2_FLINCHED) {
                battlers[attacking_battler].status2 &= (u32)(~(STATUS2_FLINCHED));
                battler_statuses[attacking_battler].flinched = 1;
                battler_cancel_multiturn_moves(attacking_battler);
                bsc_offset = bsc_move_used_flinched;
                bsc_status_flags |= BSC_STATUS_FLAG_UNABLE_TO_USE_MOVE;
                effect = 1;
            }
            ++battle_state->attack_canceler_state;
            break;
        case ATTACK_CANCELLER_DISABLED: // disabled move
            if (battler_disable[attacking_battler].disabled_move == active_attack &&
             battler_disable[attacking_battler].disabled_move != ATTACK_NONE) {
                battler_statuses[attacking_battler].used_disabled_move = 1;
                battle_scripting.battler_idx = attacking_battler;
                battler_cancel_multiturn_moves(attacking_battler);
                bsc_offset = bsc_move_used_is_disabled;
                bsc_status_flags |= BSC_STATUS_FLAG_UNABLE_TO_USE_MOVE;
                effect = 1;
            }
            ++battle_state->attack_canceler_state;
            break;
        case ATTACK_CANCELLER_TAUNTED: // taunt
            if (battler_disable[attacking_battler].taunt_timer && attacks[active_attack].base_power == 0) {
                battler_statuses[attacking_battler].used_taunted_move = 1;
                battler_cancel_multiturn_moves(attacking_battler);
                bsc_offset = bsc_move_used_is_taunted;
                bsc_status_flags |= BSC_STATUS_FLAG_UNABLE_TO_USE_MOVE;
                effect = 1;
            }
            ++battle_state->attack_canceler_state;
            break;
        case ATTACK_CANCELLER_IMPRISONED: // imprisoned
            if (battle_move_get_imprison_count(attacking_battler, active_attack)) {
                battler_statuses[attacking_battler].used_imprisoned_move = 1;
                battler_cancel_multiturn_moves(attacking_battler);
                bsc_offset = bsc_move_used_is_imprisoned;
                bsc_status_flags |= BSC_STATUS_FLAG_UNABLE_TO_USE_MOVE;
                effect = 1;
            }
            ++battle_state->attack_canceler_state;
            break;
        case ATTACK_CANCELLER_BY_GLYPH: { // unowns with the glyph ribbon prevent moves with a certain letter
            u8 unown_battler_that_disables = battle_get_unown_battler_that_disables_move(active_attack,
                attacking_battler);
            if (unown_battler_that_disables < battler_cnt) {
                battler_statuses[attacking_battler].used_move_blocked_by_glyphs = 1;
                bsc_last_used_item = battlers[unown_battler_that_disables].item;
                battler_move_selection_battlescripts[active_battler] = bsc_attack_disabled_by_runenband;
                battle_scripting.battler_idx = unown_battler_that_disables;
                int letter = pokemon_unown_get_letter(battlers[unown_battler_that_disables].pid);
                buffer0[0] = (u8)(letter + 0xBB);
                buffer0[1] = 0xFF;
                battler_cancel_multiturn_moves(attacking_battler);
                bsc_offset = bsc_move_used_disabled_by_runenband;
                bsc_status_flags |= BSC_STATUS_FLAG_UNABLE_TO_USE_MOVE;
                effect = 1;
            }
            ++battle_state->attack_canceler_state;
            break;
        }
        case ATTACK_CANCELLER_CONFUSED: // confusion
            if (battlers[attacking_battler].status2 & STATUS2_CONFUSED) {
                --battlers[attacking_battler].status2; // progress confusion
                if (battlers[attacking_battler].status2 & STATUS2_CONFUSED) {
                    if (rnd16() & 1) {
                        battle_communication[BATTLE_COMMUNICATION_MULTISTRING_CHOOSER] = 0;
                        battlescript_callstack_push_next_command();
                    } else { // confusion dmg
                        battle_communication[BATTLE_COMMUNICATION_MULTISTRING_CHOOSER] = 1;
                        defending_battler = attacking_battler;
                        damage_to_apply = battle_base_damage_calculate(&battlers[attacking_battler], &battlers[attacking_battler], ATTACK_PFUND, 0, 40, 0, attacking_battler, attacking_battler);
                        battler_statuses[attacking_battler].hurt_in_confusion = 1;
                        bsc_status_flags |= BSC_STATUS_FLAG_UNABLE_TO_USE_MOVE;
                    }
                    bsc_offset = bsc_move_used_is_confused;
                } else { // snapped out of confusion
                    battlescript_callstack_push_next_command();
                    bsc_offset = bsc_move_used_snapped_out_of_confusion;
                }
                effect = 1;
            }
            ++battle_state->attack_canceler_state;
            break;
        case ATTACK_CANCELLER_PARALYSED: // paralysis
            if ((battlers[attacking_battler].status1 & STATUS1_PARALYZED) && (rnd16() % 4) == 0) {
                battler_statuses[attacking_battler].immobility = 1;
                bsc_offset = bsc_move_used_is_paralyzed;
                bsc_status_flags |= BSC_STATUS_FLAG_UNABLE_TO_USE_MOVE;
                effect = 1;
            }
            ++battle_state->attack_canceler_state;
            break;
        case ATTACK_CANCELLER_GHOST: // GHOST in pokemon tower
            // The ghost is skipped in Violet, it does not exist
            ++battle_state->attack_canceler_state;
            break;
        case ATTACK_CANCELLER_IN_LOVE: // infatuation
            if (battlers[attacking_battler].status2 & STATUS2_INFATUATION) {
                battle_scripting.battler_idx = count_trailing_zero_bits((battlers[attacking_battler].status2 & STATUS2_INFATUATION) >> 0x10);
                if (rnd16() & 1) {
                    battlescript_callstack_push_next_command(); // Pokemon breaks through infatuation
                } else {
                    battlescript_callstack_push(bsc_move_used_is_immobilized_by_infatuation);
                    bsc_status_flags |= BSC_STATUS_FLAG_UNABLE_TO_USE_MOVE;
                    battler_statuses[attacking_battler].love_immobility = 1;
                    battler_cancel_multiturn_moves(attacking_battler);
                }
                bsc_offset = bsc_move_used_is_in_love;
                effect = 1;
            }
            ++battle_state->attack_canceler_state;
            break;
        case ATTACK_CANCELLER_BIDE: // bide
            if (battlers[attacking_battler].status2 & STATUS2_BIDE) {
                battlers[attacking_battler].status2 -= 0x100;
                if (battlers[attacking_battler].status2 & STATUS2_BIDE) {
                    bsc_offset = bsc_move_used_bide_is_storing_energy;
                } else {
                    if (battler_damage_taken_accumulated[attacking_battler]) {
                        active_attack = ATTACK_GEDULD;
                        *bideDmg = battler_damage_taken_accumulated[attacking_battler] * 2;
                        defending_battler = battler_damage_taken_accumulated_caused_by_battler_idx[attacking_battler];
                        if (battlers_absent & int_bitmasks[defending_battler])
                            defending_battler = attack_get_target_of_active_battler(ATTACK_GEDULD, 1);
                        bsc_offset = bsc_move_used_bide_release_energy;
                    } else {
                        bsc_offset = bsc_move_used_bide_no_energy_to_release;
                    }
                }
                effect = 1;
            }
            ++battle_state->attack_canceler_state;
            break;
        case ATTACK_CANCELLER_THAW: // move thawing
            if (battlers[attacking_battler].status1 & STATUS1_FROZEN) {
                if (attacks[active_attack].effect == 0x7D) {
                    battlers[attacking_battler].status1 &= (u32)(~(STATUS1_FROZEN));
                    battlescript_callstack_push_next_command();
                    bsc_offset = bsc_move_used_unfroze;
                    battle_communication[BATTLE_COMMUNICATION_MULTISTRING_CHOOSER] = 1;
                }
                effect = 2;
            }
            ++battle_state->attack_canceler_state;
            break;
        case ATTACK_CANCELLER_END:
            break;
        }
    } while (battle_state->attack_canceler_state != ATTACK_CANCELLER_END && !effect);
    // Status1 of the attacking battler changed
    if (effect == 2) {
        active_battler = attacking_battler;
        battle_controller_emit_set_pokemon_data(0, BATTLE_CONTROLLER_EMIT_SET_POKEMON_DATA_STATUS_BATTLE, 0, 4, &battlers[active_battler].status1);
        battler_mark_for_controller_execution(active_battler);
    }
    return effect;
}

bool battler_was_unable_to_use_move(u8 battler_idx) {
    if (battler_statuses[battler_idx].immobility
     || battler_statuses[battler_idx].target_unaffected
     || battler_statuses[battler_idx].used_imprisoned_move
     || battler_statuses[battler_idx].love_immobility
     || battler_statuses[battler_idx].used_disabled_move
     || battler_statuses[battler_idx].used_taunted_move
     || battler_statuses[battler_idx].used_move_blocked_by_glyphs
     || battler_statuses[battler_idx].flinched
     || battler_statuses[battler_idx].hurt_in_confusion)
        return true;
    else
        return false;
}

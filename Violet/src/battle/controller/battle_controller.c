#include "battle/battler.h"
#include "battle/controller.h"
#include "battle/state.h"
#include "constants/battle/battle_actions.h"
#include "debug.h"
#include "mega.h"
#include "pokemon/virtual.h"
#include "save.h"
#include "types.h"

// TODO: This function is currently unused. It is ought to be called by every battle_controller_xxx_handle_choose_move
void battle_controller_emit_move_chosen(u8 buffer_idx, u8 chosen_move_idx, u8 target_battler_idx, u8 mega_evolution) {
    battle_buffer_transfer[0] = 0x21; // = EMIT_TWO_VALUES
    battle_buffer_transfer[1] = BATTLE_ACTION_EXECUTE_SCRIPT;
    battle_buffer_transfer[2] = chosen_move_idx;
    battle_buffer_transfer[3] = target_battler_idx;
    battle_buffer_transfer[4] = mega_evolution;
    battle_buffer_request_data_transfer(buffer_idx, battle_buffer_transfer, 5);
    dprintf("Emitted move chosen for battler %d\n", target_battler_idx);
}

// TODO: This function must replace a code block in the battle callback, i.e.
// https://github.com/pret/pokeemerald/blob/27c4329e4518a9838476e16c9fbb4cfb6d83a0d7/src/battle_main.c#L4439-L4441
// in the battle main function...
void battle_main_read_chosen_move() {
    battle_state->chosen_move_slots[active_battler] = battle_general_buffers1[active_battler][2];
    battle_state->move_target[active_battler] = battle_general_buffers1[active_battler][3];
    MEGA_STATE.marked_for_mega_evolution[active_battler] = battle_general_buffers1[active_battler][4];
}

void battle_execute_action() {
    if (battle_result) {
        battle_action = BATTLE_ACTION_FINISHED; // Battle has a result, i.e. ends
    }

    if (battle_action == BATTLE_ACTION_USE_MOVE) {
        if (battle_execute_action_mega_evolution())
            return;
    }

    battle_state->saved_turn_action_number = battle_action_current_turn;
    battle_actions[battle_action]();
    if (battle_action_current_turn < battler_cnt) {
        if (battle_state->saved_turn_action_number != battle_action_current_turn) {
            // It is another battler's turn, clear the battle script flags (no idea what they mean..., according to pokeemerald hitmarkers, but w/e)
            bsc_status_flags &= 0xFFF7FDFF;
        }
    } else {
        // All battler's had their actions, now end the turn
        bsc_status_flags &= 0xFFEFFFFF;
        battle_main_callback = battle_end_turn_functions[battle_result];
    }
}

extern u16 battler_party_idxs[4];

void battle_setup_party_idxs() {
    if (battle_flags & BATTLE_MULTI)
        return;
    u8 sent_out_by_owner[4] = {4, 4, 4, 4};
    u8 first = 0;
    u8 last = 0;
    for (u8 i = 0; i < battler_cnt; i++) {
        pokemon *party = battler_load_party_range(i, &first, &last);
        for (u8 j = first; j < last; j++) {
            // Check if j is the battler already sent out by the same owner
            if (POKEMON_IS_VIABLE(party + j) && sent_out_by_owner[battler_get_owner(i)] != j) {
                battler_party_idxs[i] = j;
                sent_out_by_owner[battler_get_owner(i)] = j;
                break;
            }
        }
    }
}

void battle_controller_set_to_partner() {
    battle_controllers[active_battler] = battle_controller_partner_execute_command;
}

// Called for double battles without a link partner / opponent, set's up the proper battle controller
void battle_controllers_setup_tag_battles() {
    if (battle_flags & (BATTLE_DOUBLE) && battle_flags & (BATTLE_ALLY)) {
        battler_positions[0] = 0;
        battle_controllers[0] = battle_controller_set_to_player;
        battler_positions[1] = 1;
        battle_controllers[1] = battle_controller_set_to_partner;
        battler_positions[2] = 2;
        battle_controllers[2] = battle_controller_set_to_opponent;
        battler_positions[3] = 3;
        battle_controllers[3] = battle_controller_set_to_opponent;
        battler_cnt = 4;
    } else {
        battler_positions[0] = 0;
        battle_controllers[0] = battle_controller_set_to_player;
        battler_positions[1] = 1;
        battle_controllers[1] = battle_controller_set_to_player;
        battler_positions[2] = 2;
        battle_controllers[2] = battle_controller_set_to_opponent;
        battler_positions[3] = 3;
        battle_controllers[3] = battle_controller_set_to_opponent;
        battler_cnt = 4;
    }
}

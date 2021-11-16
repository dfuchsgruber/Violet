#include "types.h"
#include "battle/state.h"
#include "battle/battler.h"
#include "battle/attack.h"
#include "math.h"
#include "attack.h"
#include "prng.h"
#include "debug.h"
#include "battle/controller.h"
#include "trainer/virtual.h"
#include "trainer/trainer.h"
#include "save.h"
#include "oam.h"
#include "pokemon/sprites.h"
#include "music.h"
#include "battle/ai.h"
#include "constants/attack_affects_whom_flags.h"
#include "mega.h"

void battle_controller_opponent_handle_choose_action() {
    ai_setup(trainer_idx_by_battler_idx(active_battler));
    battle_ai_choose_action();
    battle_controller_opponent_execution_finished();
}

void battle_controller_opponent_handle_choose_item() {
    u16 *item = BATTLE_STATE2->items[battler_get_owner(active_battler)] + TRAINER_AI_STATE2->chosen_item_idxs[active_battler];
    DEBUG("Emitting item %d\n", *item);
    battle_controller_emit_one_value(1, *item);
    *item = 0;
    battle_controller_opponent_execution_finished();
}

void battle_controller_opponent_handle_choose_pokemon() {
    u8 target_idx;
    if (battle_state->ai_switch_target_chosen & int_bitmasks[active_battler]) {
        target_idx = battle_state->battler_to_switch_into[active_battler];
        battle_state->ai_switch_target_chosen &= (u8)(~int_bitmasks[active_battler]);
    } else {
        target_idx = battle_ai_get_pokemon_to_switch_into();
        if (target_idx == 6)
            DEBUG("No pokemon to switch into for battler %d\n", active_battler);
    }
    battle_state->battler_to_switch_into[active_battler] = target_idx;
    battle_controller_opponent_emit_chosen_pokemon(1, target_idx, NULL);
    battle_controller_opponent_execution_finished();
}

void battle_controller_opponent_handle_choose_move() {
    if (battle_flags & (BATTLE_TRAINER | BATTLE_ROAMER | BATTLE_SAFARI | BATTLE_FLEEING_WILD)) {
        ai_setup(trainer_idx_by_battler_idx(active_battler));
        u8 move_idx = trainer_ai_choose_move_or_action();
        trainer_ai_choosing_state_t *ai_state = (trainer_ai_choosing_state_t*) &battle_general_buffers0[active_battler][4];
        switch (move_idx) {
            case AI_CHOICE_FLEE: {
                battle_controller_emit_two_values(1, BATTLE_ACTION_RUN, 0);
                break;
            }
            case AI_CHOICE_WATCH: {
                battle_controller_emit_two_values(1, BATTLE_ACTION_SAFARI_WATCH_CAREFULLY, 0);
                break;
            }
            default: { // Move chosen
                u8 affects = attacks[ai_state->moves[move_idx]].affects_whom;
                if (affects & (TARGET_USER | TARGET_UNUSED)) {
                    defending_battler = active_battler;
                }
                if (affects & TARGET_BOTH_FOES) {
                    defending_battler = battler_get_by_position(BATTLE_POSITION_PLAYER_LEFT);
                    if (battlers_absent & int_bitmasks[defending_battler]) // If the left is absent, target the right one...
                        defending_battler = battler_get_by_position(BATTLE_POSITION_PLAYER_RIGHT);
                }
                DEBUG("The chosen target of the opponent was %d\n", defending_battler);
                // TODO: battle_controller_emit_move_chosen instead for link compatibility?
                battle_controller_emit_two_values(1, BATTLE_ACTION_EXECUTE_SCRIPT, (u16)(move_idx | (defending_battler << 8)));

                if (battle_flags & BATTLE_TRAINER) {
                    mega_evolution_t *mega = battler_get_available_mega_evolution(active_battler);
                    if (mega)
                        MEGA_STATE.marked_for_mega_evolution[active_battler] = (u8)mega->type;
                }
                break;
            }

        }
    } else {
        // Choose random feasible move
        u8 move_idx;
        do {
            move_idx = (u8)(rnd16() % 4);
        } while (battlers[active_battler].moves[move_idx] == 0);
        u8 affects = attacks[battlers[active_battler].moves[move_idx]].affects_whom;
        if (affects & (TARGET_USER | TARGET_UNUSED)) {
            defending_battler = active_battler;
        } else if (affects & TARGET_BOTH_FOES) {
            defending_battler = battler_get_by_position(BATTLE_POSITION_PLAYER_LEFT);
            if (battlers_absent & int_bitmasks[defending_battler]) // If the left is absent, target the right one...
                defending_battler = battler_get_by_position(BATTLE_POSITION_PLAYER_RIGHT);
        } else if (battle_flags & BATTLE_DOUBLE) {
            defending_battler = (rnd16() & 1) ? battler_get_by_position(BATTLE_POSITION_PLAYER_LEFT) : battler_get_by_position(BATTLE_POSITION_PLAYER_RIGHT);
        } else {
            defending_battler = battler_get_by_position(BATTLE_POSITION_PLAYER_LEFT);
        }
        DEBUG("The randomly chosen target of the opponent was %d\n", defending_battler);
        battle_controller_emit_two_values(1, BATTLE_ACTION_EXECUTE_SCRIPT, (u16)(move_idx | (defending_battler << 8)));

    }
    battle_controller_opponent_execution_finished();
}

u8 battle_controller_opponent_get_trainer_pic() {
    // Cut secret base, e-reader, trainer tower, duel tower trainers...
    u16 trainer_idx;
    if (battle_flags & BATTLE_TWO_TRAINERS)
        trainer_idx = active_battler == 1 ? trainer_vars.trainer_id : fmem.trainer_varsB.trainer_id;
    else
        trainer_idx = trainer_vars.trainer_id;
    DEBUG("Get trainer idx for battler %d: %d\n", active_battler, trainer_idx);
    return trainers[trainer_idx].sprite;
}

u8 battle_controller_opponent_create_trainer_pic_oam(u8 relative_prio, s16 y) {
    s16 x;
    if (battle_has_two_opponents())
        x = battler_get_position(active_battler) & 2 ? 152 : 200;
    else 
        x = 176;
    DEBUG("y is %d\n", y);
    return oam_new_forward_search(&gp_oam_template, x, y, relative_prio);
}

/**
void battle_controller_opponent_handle_draw_trainer_picture() {
    u8 sprite = battle_controller_opponent_get_trainer_pic();
    s16 x;
    if (battle_has_two_opponents())
        x = battler_get_position(active_battler) & 2 ? 152 : 200;
    else
        x = 176;
    trainer_gfx_load(sprite, active_battler);
    trainer_gfx_initialize_gp_oam_template(sprite, battler_get_position(active_battler));
    s16 y = (s16)((8 - trainer_sprite_coordinates[sprite].y_offset) * 4 + 40);
    u8 oam_idx = oam_new_forward_search(&gp_oam_template, x, y, battler_oam_get_relative_priority(active_battler));
    battler_oams[active_battler] = oam_idx;
    oams[oam_idx].x2 = -240;
    oams[oam_idx].private[0] = 2;
    oams[oam_idx].final_oam.attr

}
**/


void sub_08035b30() {
    // I have no clue what this function does, it is changed in pokeemerald drastically, so we do these changes as well...
    bool healthboxes_done = false, wait_for_both_healthboxes;
    if (!battle_is_double() || (battle_is_double() && (battle_flags & BATTLE_MULTI)) || (battle_flags & BATTLE_TWO_TRAINERS)) {
        if (oams[battle_healthbox_oams[active_battler]].callback == oam_null_callback) healthboxes_done = true;
        wait_for_both_healthboxes = false;
    } else {
        if (oams[battle_healthbox_oams[active_battler]].callback == oam_null_callback &&
        oams[battle_healthbox_oams[PARTNER(active_battler)]].callback == oam_null_callback) healthboxes_done = true;
        wait_for_both_healthboxes = true;
    }
    /** There is no pendant for this in firered ??
    gUnknown_020244D8 = &gBattleSpritesDataPtr->healthBoxesData[gActiveBattler];
    gUnknown_020244DC = &gBattleSpritesDataPtr->healthBoxesData[gActiveBattler ^ BIT_FLANK]; **/
    if (healthboxes_done) {
        if (wait_for_both_healthboxes) {
            if (wait_for_both_healthboxes && battle_sprite_data->healthbox_info[active_battler].field_1_x1 && 
                battle_sprite_data->healthbox_info[PARTNER(active_battler)].field_1_x1) { // Wait for field_1_x1 of both boxes
                battle_sprite_data->healthbox_info[active_battler].flag_x80 = 0;
                battle_sprite_data->healthbox_info[active_battler].field_1_x1 = 0;
                battle_sprite_data->healthbox_info[PARTNER(active_battler)].flag_x80 = 0;
                battle_sprite_data->healthbox_info[PARTNER(active_battler)].field_1_x1 = 0;
                oam_free_vram_by_tag(0x27F9);
                oam_palette_free(0x27F9);
                volume_set(mplay_info_background_music, 0xFFFF, 256);
            } else {
                return;
            }
        } else if (battle_sprite_data->healthbox_info[active_battler].field_1_x1) { // Wait for field_1_x1 of one box
            // If for one box is waited and the current battler is the RIGHT side of the opponent, we free only if the other
            // opponent box has finished?

            if (battler_get_position(active_battler) == BATTLE_POSITION_OPPONENT_RIGHT) {
                if (battle_sprite_data->healthbox_info[PARTNER(active_battler)].flag_x80 == 0 &&
                        battle_sprite_data->healthbox_info[PARTNER(active_battler)].field_1_x1 == 0) {
                    oam_free_vram_by_tag(0x27F9);
                    oam_palette_free(0x27F9);
                    volume_set(mplay_info_background_music, 0xFFFF, 256);
                } else {
                    return;
                }
            }
            battle_sprite_data->healthbox_info[active_battler].flag_x80 = 0;
            battle_sprite_data->healthbox_info[active_battler].field_1_x1 = 0;
        } else { // Wait for one box, but field_1_x1 is not finished ?
            return;
        }
        battle_sprite_data->healthbox_info[active_battler].field_9 = 3; // Delay for battle controller execution, why 3 frames tho?
        battle_controllers[active_battler] = sub_08035ae8; // Delays until field9 of the healthbox has reached zero
    }
}
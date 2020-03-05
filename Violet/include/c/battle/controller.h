#ifndef H_BATTLE_CONTROLLER
#define H_BATTLE_CONTROLLER

#include "types.h"
#include "constants/battle/battle_actions.h"

/**
 * Battle controller callback that waits for the player to choose an action (move, item, switch, run)
 **/
void battle_controller_player_choose_action();

/**
 * Battle controller callback that waits for the player to choose a move.
 **/
void battle_controller_player_choose_move();

/**
 * Battle controller callback that waits for dma3 to finish and then continues to letting the player choose a move.
 **/
void battle_controller_player_choose_move_after_dma3();

/**
 * Battle controller callback that initializes choosing a move for the player.
 **/
void battle_controller_player_initialize_choose_move();

/**
 * Battle controller callback that waits for the player to switch moves.
 **/
void battle_controller_player_switch_moves();


/** 
 * Battler controller callback that waits for the player to choose a target.
 **/
void battle_controller_player_choose_target();

/**
 * Emits the pokemon chosen for switching.
 * @param buffer_idx the buffer idx
 * @param party_idx which pokemon to switch in
 * @param param3
 **/
void battle_controller_opponent_emit_chosen_pokemon(u8 buffer_idx, u8 party_idx, u8 *param3);

/**
 * Marks the opponent battle controller's execution as finished.
 **/
void battle_controller_opponent_execution_finished();

/**
 * Taken from pokeemerald.
 **/ 
void battle_controller_emit_get_pokemon_data(u8 buffer_idx, u8 request_idx, u8 battler_idx);

/**
 * Emits two return values for the battle controler.
 * @param buffer_idx
 * @param arg1 the first value to emit
 * @param arg2 the second value to emit
 **/
void battle_controller_emit_two_values(u8 buffer_idx, u8 arg1, u16 arg2);


/**
 * Emits an event to set the data of a battler.
 * @param buffer_idx which battle buffer to use (0 or 1)
 * @param request_idx Which controller event to request
 * @param pokemon_idx the pokemon to set
 * @param size how many bytes will be set
 * @param data data to transfer
 **/
void battle_controller_emit_set_pokemon_data(u8 buffer_idx, u8 request_idx, u8 pokemon_idx, u8 size,void *data);

/**
 * Emits an event to draw the trainer picture of the active battler.
 * @param buffer_idx the buffer to use (0 or 1)
 **/
void battle_controller_emit_draw_trainer_picture(u8 buffer_idx);

/**
 * Emits an event to make trainers throw out their balls.
 * @param buffer_idx the buffer to use (0 or 1)
 **/
void battle_controller_emit_intro_trainer_ball_throw(u8 buffer_idx);

/**
 * Marks a battler such that is executed by the battle controller.
 * @param battler_idx the battler to mark.
 **/
void battler_mark_for_controller_execution(u8 battler_idx);

#define BOUNCE_EFFECT_BATTLER 0
#define BOUNCE_EFFECT_HEALTHBAR 1

/**
 * Applies the bounce effect to an oam.
 * @param battler_idx the slot to apply the effect to
 * @param target which bounce effec to apply
 * @param ?
 * @param ?
 **/
void battle_bounce_effect(u8 battler_idx, u8 target, u8, u8);

u8 battle_selected_action[4];

extern void (*battle_controllers[4])();


u8 battle_buffer_transfer[256]; // General purpose buffer for transfering data

/**
 * Transfers data for battle (i.e. over the cable, if neccessary)
 * @param buffer_idx whether to use bufferA or bufferB
 * @param data the data to transmit
 * @param size how many bytes to transmit
 **/
void battle_buffer_request_data_transfer(u8 buffer_idx, void *data, u8 size);

/**
 * Battle controller function that delays finishing the execution of a battler's buffer until field_9 of its healthbar has dropped to zero.
 **/
void sub_08035ae8();

/**
 * Initializes the general purpose oam template with the sprite data of a trainer gfx.
 * @param sprite_idx the trainer sprite to load
 * @param battler_position the bank into which the gfx was loaded.
 **/
void trainer_gfx_initialize_gp_oam_template(u8 sprite_idx, u8 battler_position);

#endif
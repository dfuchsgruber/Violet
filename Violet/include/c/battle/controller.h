#ifndef H_BATTLE_CONTROLLER
#define H_BATTLE_CONTROLLER

#include "types.h"
#include "constants/battle/battle_actions.h"

enum {
    BATTLE_CONTROLLER_EMIT_SET_POKEMON_DATA_ALL_BATTLE,
    BATTLE_CONTROLLER_EMIT_SET_POKEMON_DATA_SPECIES_BATTLE,
    BATTLE_CONTROLLER_EMIT_SET_POKEMON_DATA_HELDITEM_BATTLE,
    BATTLE_CONTROLLER_EMIT_SET_POKEMON_DATA_MOVES_PP_BATTLE,
    BATTLE_CONTROLLER_EMIT_SET_POKEMON_DATA_MOVE1_BATTLE,
    BATTLE_CONTROLLER_EMIT_SET_POKEMON_DATA_MOVE2_BATTLE,
    BATTLE_CONTROLLER_EMIT_SET_POKEMON_DATA_MOVE3_BATTLE,
    BATTLE_CONTROLLER_EMIT_SET_POKEMON_DATA_MOVE4_BATTLE,
    BATTLE_CONTROLLER_EMIT_SET_POKEMON_DATA_PP_DATA_BATTLE,
    BATTLE_CONTROLLER_EMIT_SET_POKEMON_DATA_PPMOVE1_BATTLE,
    BATTLE_CONTROLLER_EMIT_SET_POKEMON_DATA_PPMOVE2_BATTLE,
    BATTLE_CONTROLLER_EMIT_SET_POKEMON_DATA_PPMOVE3_BATTLE,
    BATTLE_CONTROLLER_EMIT_SET_POKEMON_DATA_PPMOVE4_BATTLE,
    BATTLE_CONTROLLER_EMIT_SET_POKEMON_DATA_UNUSED_13_BATTLE,
    BATTLE_CONTROLLER_EMIT_SET_POKEMON_DATA_UNUSED_14_BATTLE,
    BATTLE_CONTROLLER_EMIT_SET_POKEMON_DATA_UNUSED_15_BATTLE,
    BATTLE_CONTROLLER_EMIT_SET_POKEMON_DATA_UNUSED_16_BATTLE,
    BATTLE_CONTROLLER_EMIT_SET_POKEMON_DATA_OTID_BATTLE,
    BATTLE_CONTROLLER_EMIT_SET_POKEMON_DATA_EXP_BATTLE,
    BATTLE_CONTROLLER_EMIT_SET_POKEMON_DATA_HP_EV_BATTLE,
    BATTLE_CONTROLLER_EMIT_SET_POKEMON_DATA_ATK_EV_BATTLE,
    BATTLE_CONTROLLER_EMIT_SET_POKEMON_DATA_DEF_EV_BATTLE,
    BATTLE_CONTROLLER_EMIT_SET_POKEMON_DATA_SPEED_EV_BATTLE,
    BATTLE_CONTROLLER_EMIT_SET_POKEMON_DATA_SPATK_EV_BATTLE,
    BATTLE_CONTROLLER_EMIT_SET_POKEMON_DATA_SPDEF_EV_BATTLE,
    BATTLE_CONTROLLER_EMIT_SET_POKEMON_DATA_FRIENDSHIP_BATTLE,
    BATTLE_CONTROLLER_EMIT_SET_POKEMON_DATA_POKERUS_BATTLE,
    BATTLE_CONTROLLER_EMIT_SET_POKEMON_DATA_MET_LOCATION_BATTLE,
    BATTLE_CONTROLLER_EMIT_SET_POKEMON_DATA_MET_LEVEL_BATTLE,
    BATTLE_CONTROLLER_EMIT_SET_POKEMON_DATA_MET_GAME_BATTLE,
    BATTLE_CONTROLLER_EMIT_SET_POKEMON_DATA_POKEBALL_BATTLE,
    BATTLE_CONTROLLER_EMIT_SET_POKEMON_DATA_ALL_IVS_BATTLE,
    BATTLE_CONTROLLER_EMIT_SET_POKEMON_DATA_HP_IV_BATTLE,
    BATTLE_CONTROLLER_EMIT_SET_POKEMON_DATA_ATK_IV_BATTLE,
    BATTLE_CONTROLLER_EMIT_SET_POKEMON_DATA_DEF_IV_BATTLE,
    BATTLE_CONTROLLER_EMIT_SET_POKEMON_DATA_SPEED_IV_BATTLE,
    BATTLE_CONTROLLER_EMIT_SET_POKEMON_DATA_SPATK_IV_BATTLE,
    BATTLE_CONTROLLER_EMIT_SET_POKEMON_DATA_SPDEF_IV_BATTLE,
    BATTLE_CONTROLLER_EMIT_SET_POKEMON_DATA_PERSONALITY_BATTLE,
    BATTLE_CONTROLLER_EMIT_SET_POKEMON_DATA_CHECKSUM_BATTLE,
    BATTLE_CONTROLLER_EMIT_SET_POKEMON_DATA_STATUS_BATTLE,
    BATTLE_CONTROLLER_EMIT_SET_POKEMON_DATA_LEVEL_BATTLE,
    BATTLE_CONTROLLER_EMIT_SET_POKEMON_DATA_HP_BATTLE,
    BATTLE_CONTROLLER_EMIT_SET_POKEMON_DATA_MAX_HP_BATTLE,
    BATTLE_CONTROLLER_EMIT_SET_POKEMON_DATA_ATK_BATTLE,
    BATTLE_CONTROLLER_EMIT_SET_POKEMON_DATA_DEF_BATTLE,
    BATTLE_CONTROLLER_EMIT_SET_POKEMON_DATA_SPEED_BATTLE,
    BATTLE_CONTROLLER_EMIT_SET_POKEMON_DATA_SPATK_BATTLE,
    BATTLE_CONTROLLER_EMIT_SET_POKEMON_DATA_SPDEF_BATTLE,
    BATTLE_CONTROLLER_EMIT_SET_POKEMON_DATA_COOL_BATTLE,
    BATTLE_CONTROLLER_EMIT_SET_POKEMON_DATA_BEAUTY_BATTLE,
    BATTLE_CONTROLLER_EMIT_SET_POKEMON_DATA_CUTE_BATTLE,
    BATTLE_CONTROLLER_EMIT_SET_POKEMON_DATA_SMART_BATTLE,
    BATTLE_CONTROLLER_EMIT_SET_POKEMON_DATA_TOUGH_BATTLE,
    BATTLE_CONTROLLER_EMIT_SET_POKEMON_DATA_SHEEN_BATTLE,
    BATTLE_CONTROLLER_EMIT_SET_POKEMON_DATA_COOL_RIBBON_BATTLE,
    BATTLE_CONTROLLER_EMIT_SET_POKEMON_DATA_BEAUTY_RIBBON_BATTLE,
    BATTLE_CONTROLLER_EMIT_SET_POKEMON_DATA_CUTE_RIBBON_BATTLE,
    BATTLE_CONTROLLER_EMIT_SET_POKEMON_DATA_SMART_RIBBON_BATTLE,
    BATTLE_CONTROLLER_EMIT_SET_POKEMON_DATA_TOUGH_RIBBON_BATTLE,
};

#define BATTLE_CONTROLLER_COMMAND_CNT 57

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
 * Executes the current command from the player battle controller.
 **/
void battle_controller_player_execute_command();

/**
 * Marks the partner's or player's execution as finished.
 **/
void battle_controller_player_or_partner_execution_finished();

/**
 * Executes the current command from the partner battle controller.
 **/
void battle_controller_partner_execute_command();

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
 * Emits to update the exp of a pokemon
 * @param buffer_idx the buffer to use
 * @param party_idx which pokemon in the player party to update the exp of
 * @param exp how many exp to add
 **/
void battle_controller_emit_exp_update(u8 buffer_idx, u8 party_idx, u16 exp);

/**
 * Emits one return value for the battle controller.
 * @param buffer_idx
 * @param arg the value to emit
 **/
void battle_controller_emit_one_value(u8 buffer_idx, u16 arg);


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
 * Emits an event to slide out the trainer picture to the right.
 * @param buffer_idx the buffer to use (0 or 1)
 **/
void battle_controller_emit_trainer_slide_out(u8 buffer_idx);

/**
 * Emits an event to slide in the trainer picture from the right.
 * @param buffer_idx the buffer to use (0 or 1)
 **/
void battle_controller_emit_trainer_slide_in(u8 buffer_idx);

/**
 * Emits an event to make trainers throw out their balls.
 * @param buffer_idx the buffer to use (0 or 1)
 **/
void battle_controller_emit_intro_trainer_ball_throw(u8 buffer_idx);

enum {
    BALL_THROW_ANIMATION_NO_SHAKES,
    BALL_THROW_ANIMATION_1_SHAKE,
    BALL_THROW_ANIMATION_2_SHAKES,
    BALL_THROW_ANIMATION_3_SHAKES,
    BALL_THROW_ANIMATION_SUCCESS,
    BALL_THROW_ANIMATION_TRAINER_BLOCK,
    BALL_THROW_ANIMATION_GHOST_DOGE,
};

/**
 * Emits to play a ball throw animation for catching
 * @param buffer_idx which buffer to use
 * @param ball_throw_animation which animation to emit
 **/
void battle_controller_emit_ball_throw_animation(u8 buffer_idx, u8 ball_throw_animation);

/**
 * Marks a battler such that is executed by the battle controller.
 * @param battler_idx the battler to mark.
 **/
void battler_mark_for_controller_execution(u8 battler_idx);

/**
 * Battle controller execution for the partner (ally) in a tag battle.
 **/
void battle_controller_partner_execute_command();

/**
 * Sets the battle controller of active_battler to the opponent
 **/
void battle_controller_set_to_opponent();
/**
 * Sets the battle controller of active_battler to the player
 **/
void battle_controller_set_to_player();

/**
 * Battle controller function for a ai partner to choose a move.
 **/
void battle_controller_partner_handle_choose_move();

/**
 * Battle controller function that overrides the move selection string printing.
 **/
void battle_controller_partner_handle_print_selection_string();

/**
 * Battle controller function for the ally to choose a action: Move, Item, Switching, ...
 **/
void battle_controller_partner_handle_choose_action();

/**
 * Battle controller function for the ally to choose a pokemon from their party.
 **/
void battle_controller_partner_handle_choose_pokemon();

/**
 * Battle controller function for the ally to choose an item to use (although it was predetermined already...)
 **/
void battle_controller_partner_handle_choose_item();

/**
 * Battle controller function for the partner to draw their trainer picture
 **/
void battle_controller_partner_handle_draw_trainer_picture();

/**
 * Battle controller function for the partner to handle exp. The partner simply doesn't gain exp...
 **/
void battle_controller_partner_handle_exp_update();

/**
 * Waits for *BOTH* healthboxes to be finished until the controller execution is continued.
 **/
void battle_controller_player_wait_for_healthboxes();

/**
 * Marks the controller of the active battler as finished as soon as no animations are running for it.
 **/
void battle_controller_wait_for_animation();

/**
 * Delays the finishing of the controller exeuction by field_9 of the healthbox_info of a battler.
 **/
void battle_controller_player_wait_for_healthbox_delay_and_finish_execution();


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

// Bitfield for each battler, if the battle controller command should be executed
u32 battler_marked_for_controller_execution;


u8 battle_buffer_transfer[256]; // General purpose buffer for transfering data

/**
 * Gets the player's multiplayer index.
 **/
u8 multiplayer_get_idx();

/**
 * Prepares transfering a battle buffer in a link battle.
 * @param buffer_idx the buffer to transfer
 * @param size how many bytes to transfer
 * @param data the data to transfer
 **/
void battle_prepare_buffer_data_transfer_link(u8 buffer_idx, u16 size, void *data);

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

/**
 * Loads the backsprite palette of a trainer
 * @param sprite_idx which backsprite to laod
 * @param battler_position at which bank to load the sprite palette
 **/
void battle_trainer_load_backsprite_palette(u8 sprite_idx, u8 battler_position);

/**
 * Battle controller function that waits until the oam of the battler (can be the trainer also) has a null-callback.
 **/
void battle_controller_player_wait_for_oam();

#endif
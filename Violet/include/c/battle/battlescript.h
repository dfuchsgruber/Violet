/*
 * battlescript.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_BATTLE_BATTLESCRIPT_H_
#define INCLUDE_C_BATTLE_BATTLESCRIPT_H_

#include "types.h"
#include "constants/battle/bsc_status_flags.h"

#define BSC_STATUS_FLAG_FAINTED(battler_idx) (int_bitmasks[battler_idx] << 0x1C)
#define BSC_STATUS_FLAG_FAINTED2(battler_idx) (0x10000000 << battler_idx)

extern u32 bsc_status_flags;
extern u8 *bsc_offset;
extern u8 bsc_effect_to_apply;

typedef struct {
	u8 stat_change;
	u8 field_1;
	u8 field_2;
	u8 field_3;
	int field_4;
	u8 field_8;
	u8 field_9;
	u8 field_A;
	u8 field_B;
	u8 field_C;
	u8 field_D;
	u16 field_E;
	u8 animation;
	u8 field_11;
	u8 field_12;
	u8 field_13;
	u8 field_14;
	u8 field_15;
	u8 field_16;
	u8 battler_idx;
	u8 field_18;
	u8 field_19;
	u8 status_effect;
	u8 field_1B;
	u8 field_1C;
	u8 field_1D;
	u8 field_1E;
} battlescript_global_stru;

typedef struct {
	u8 *scripts[8];
	u8 size;
} battlescript_stack_t;

extern battlescript_global_stru bsc_global;


typedef struct  {
    u32 pain_split_damage;
    u32 bide_damage;
    u8 multihit_string[6];
    u8 damage_multiplier;
    u8 charging_move_string_idx;
    u8 animation_arguments[2];
    u16 tripple_kick_power;
    u8 attack_done_state;
    u8 battler_using_ability;
    u8 multihit_move_effect;
    u8 battler_idx;
    u8 animation_user;
    u8 animation_targets;
    u8 stat_change;
    u8 stat_change_animation_played;
    u8 field_0x1c;
    u8 battle_style;
    u8 field_0x1e;
    u8 learn_move_state;
    u8 field_0x20;
    u8 reshow_main_state;
    u8 reshow_helper_state;
    u8 heal_item_amount;
    u8 windows_type;
    u8 multiplayer_idx;
    u8 special_trainer_battle_type;
} battle_scripting_t;

extern battle_scripting_t battle_scripting;

#define SET_STATCHANGE(stat, stages, goes_down)(battle_scripting.stat_change = (u8)((stat) + (stages << 4) + (goes_down << 7)))


extern u16 bsc_last_used_item; // Used for the BSC_LAST_ITEM buffer

extern u8 *battlescripts_pokeball[0xD]; // Battle-Scripts for using different pokeballs...
extern u8 *battlescripts_run_by_item[]; // Battle-Scripts for running using different items
extern u8 *battlescripts_use_item[]; // Battle-Scripts for using different item types
extern u8 battlescript_apply_status1[]; // Battle-Script that applies a status1 condition (burn, posion, etc.). Uses battle communcitation and the MOVE_EFECT_BYTE
extern u8 battlescript_attack_failed_no_pp_reduce[]; // Prints the "but if failed" message and doesn't reduce pp, ends the move afterwards
extern u8 bsc_roar_success_force_out[]; // Forces a pokémon out, making the target select a new switch in target
extern u8 bsc_roar_sucess_end_battle[]; // Uses roar to end a battle
/**
 * Loads the graphic for the attack "transform"
 * @param user_index battler index of the user
 * @param target_index battler index of the target
 * @param unkown TODO
 */
void battlescript_transform_load_graphic(u8 user_index, u8 target_index, u8 unkown);

/**
 * Uses the battle engine to print a string
 * @param str the string to print
 * @param duration the number of frames for the string to be present
 */
void battle_print_string(u8* str, u16 duration);

/**
 * Initializes the battle script sequences for attacks
 */
void battle_attack_init();

/**
 * Callback to execute the battlescript
 */
void battlescript_execute();

/**
 * Pushes the next command to execute to the battle script callstack
 */
void battlescript_callstack_push_next_command();

/**
 * Initializes a battle script and interrupts the battle engine meanwhile
 * @param bsc the battle script to initialize
 */
void battlescript_init_and_interrupt_battle(u8 *bsc);

/**
 * Initializes a battlescript. The current battle callback is pushed.
 * @param script the script to run. Scripts should be ended using end2.
 **/
void battlescript_init_and_push_current_callback(u8 *script);

/**
 * Battle script command 0x6 applies the damage modifiers
 */
void battlescript_cmd_x06_apply_damage_modifiers();

/**
 * Battle script command 0xEA: recoveres used items
 * structure: 0xEA [offset_failed_to_recover : word]
 */
void bsc_cmd_xEA_recycle_item();

/**
 * Battlescript command that step-by-step triggers events after a battle.
 * In Violet, this function is wrapped...
 **/
void bsc_cmd_x49_attack_done();

/**
 * Pushes a target script as return adress to the battlescript stack.
 * @param script the target script
 */
void battlescript_callstack_push(u8 *script);

/**
 * Returns a word from the current bsc pointer and increments by 4.
 * @return the word
 */
int bsc_get_word();

/**
 * Gets the battler idx associated with a battlescript argument.
 * @param arg the battle script argument
 * @return the battler idx
 **/
u8 battlescript_argument_to_battler_idx(u8 arg);

/**
 * Attempts to do a forced switch out and calls the proper subscript on failure.
 * @return if the switch out was sucessful
 **/
bool battlescript_force_switch_out();

void sub_08013ef0(u8 battler_idx);


// Multipliers for how much money is lost at losing a battle.
extern u8 money_lost_multipliers_by_number_of_badges[9];

#endif /* INCLUDE_C_BATTLE_BATTLESCRIPT_H_ */

/*
 * battlescript.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_BATTLE_BATTLESCRIPT_H_
#define INCLUDE_C_BATTLE_BATTLESCRIPT_H_

u32 *bsc_status_flags = (u32*)0x02023DD0;
u8 *bsc_buffers = (u8*)0x02022AB8;
u8 **bsc_offset = (u8**)0x02023D74;

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
 * Removes a callback launched by the attack animation engine. Removes all references in the
 * attack animation engine as well
 * @param self the own callback id
 */
void attack_anim_remove_big_callback(u8 self);

/**
 * Initializes a battle script and interrupts the battle engine meanwhile
 * @param bsc the battle script to initialize
 */
void battlescript_init_and_interrupt_battle(u8 *bsc);

/**
 * Battle script command 0x6 applies the damage modifiers
 */
void battlescript_cmd_x06_apply_damage_modifiers();

#endif /* INCLUDE_C_BATTLE_BATTLESCRIPT_H_ */

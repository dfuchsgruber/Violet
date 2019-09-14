/*
 * script.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_OVERWORLD_SCRIPT_H_
#define INCLUDE_C_OVERWORLD_SCRIPT_H_

typedef struct {
	u8 unkown[0x8];
	u8 *script;
	u8 unkown2[0x58];
	u8 *pointer_banks[1]; // Might be there are more than one
	// TODO (research the state)
} overworld_script_state_t;

extern overworld_script_state_t overworld_script_state;

extern u8 *overworld_script_virtual_ptr;

/**
 * Script command to initialize a mart
 * @param script_state the script state
 */
bool overworld_script_cmd_x86_pokemart(void *script_state);

/**
 * Reads a word from the current script offset (unaligned)
 * @param script_state the overworld script state
 */
int overworld_script_read_word(void *script_state);

/**
 * Initializes an overworld script
 * @param script The script offset to initialize
 */
void overworld_script_init(void* script);

/**
 * Halts the script until the warp is executed
 */
void overworld_script_wait_for_warp();

/**
 * Halts the script until it is forcefully resumed
 */
void overworld_script_halt();

/**
 * Resumes the execution of the overworld script halted by overworld_script_halt
 */
void overworld_script_resume();

/**
 * Changes the overworld script state to active
 */
void overworld_script_set_active();

/**
 * Changes the overworld script state to inactive
 **/
void overworld_script_set_inactive();

/**
 * Initializes a muted overworld script
 * @param script the script to initialize
 */
void overworld_script_init_muted(u8 *script);

/**
 * Shows a multichoice and spawns callback to process user input
 * @param x the x coordinate for the choice (in tiles)
 * @param y the y coordiante for the choice (in tiles)
 * @param choice the multichoice id
 * @param forced_choice if the choice is forced (i.e. can not be aborted with B-press)
 * @return on success
 */
bool multichoice(u8 x, u8 y, u8 choice, bool forced_choice);

/**
 * Gives an egg to the player.
 * @param species the species to create an egg of
 * @return the result of giving the egg
 */
u16 overworld_script_giveegg(u16 species);

#endif /* INCLUDE_C_OVERWORLD_SCRIPT_H_ */

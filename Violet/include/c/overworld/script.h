/*
 * script.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_OVERWORLD_SCRIPT_H_
#define INCLUDE_C_OVERWORLD_SCRIPT_H_

#define OVERWORLD_SCRIPT_STATE_STOP 0
#define OVERWORLD_SCRIPT_STATE_RUNNING 1
#define OVERWORLD_SCRIPT_STATE_WAITING_FOR_CALLBACK 2

typedef struct overworld_script_state_t overworld_script_state_t;

typedef struct overworld_script_state_t {
    u8 field_0;
    u8 state;
    u8 field_2;
    u8 field_3;
    bool (*callback)(); // Returns true when the handler is supposed to be waiting
    u8 *script;
    u8 field_12[80];
    bool (*commands)(overworld_script_state_t *);
    bool (*last_command)(overworld_script_state_t *);
    u8 *pointer_banks[4];
} overworld_script_state_t;

u8 *ow_script_string_buffers[3];

extern overworld_script_state_t overworld_script_state;

extern u8 *overworld_script_virtual_ptr;
extern u8 tbox_idx_money; // Money textbox uses that

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
 * Reads a 16-bit hword from the current script offset.
 * @param state the current script state
 * @return the 16-bit hword located at the current offset
 */
u16 overworld_script_read_hword(overworld_script_state_t *state);

/**
 * Initializes an overworld script
 * @param script The script offset to initialize
 */
void overworld_script_init(void *script);

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
 */
void overworld_script_set_inactive();

/**
 * Initializes a muted overworld script
 * @param script the script to initialize
 */
void overworld_script_init_muted(u8 *script);

/**
 * Big callback to process input of a yesnobox
 * @param self self-reference
 */
void yesnobox_handle_input(u8 self);

/**
 * Shows a yes/no box and spawns a callback to process user input
 * @param x unused
 * @param y unused
 * @return if the creation was sucessful
 */
bool yesnobox(u8 x, u8 y);

/**
 * Shows a multichoice and spawns callback to process user input
 * @param x the x coordinate for the choice (in tiles)
 * @param y the y coordiante for the choice (in tiles)
 * @param choice the multichoice id
 * @param forced_choice if the choice is forced (i.e. can not be aborted with B-press)
 * @return on success
 */
bool multichoice(u8 x, u8 y, u8 choice, u8 forced_choice);

/**
 * Shows a multichoice and spawns callback to process user input with the cursor at a default position
 * @param x the x coordinate for the choice (in tiles)
 * @param y the y coordiante for the choice (in tiles)
 * @param choice the multichoice id
 * @param forced_choice if the choice is forced (i.e. can not be aborted with B-press)
 * @param default_item the idx of the default choice, where the cursor is initialized
 * @return on success
 */
bool multichoice_with_default(u8 x, u8 y, u8 choice, u8 forced_choice, u8 default_item);

/**
 * Shows a multichoice and spawns callback to process user input with more than one column
 * @param x the x coordinate for the choice (in tiles)
 * @param y the y coordiante for the choice (in tiles)
 * @param choice the multichoice id
 * @param forced_choice if the choice is forced (i.e. can not be aborted with B-press)
 * @param num_columns the number of columns
 * @return on success
 */
bool multichoice_grid(u8 x, u8 y, u8 choice, u8 forced_choice, u8 num_columns);

/**
 * Gives an egg to the player.
 * @param species the species to create an egg of
 * @return the result of giving the egg
 */
u16 overworld_script_giveegg(u16 species);

/**
 * Checks if an ow script is active (called script context 1 in poke*)
 * @return if any script is active
 */
bool ow_script_is_active();

/**
 * Callback that shows a pokemon pic.
 * @param self self-reference
 */
void overworld_script_callback_show_pokemon_picture(u8 self);

#endif /* INCLUDE_C_OVERWORLD_SCRIPT_H_ */

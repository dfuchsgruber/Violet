/*
 * pokemon_party_menu.h
 *
 *  Created on: May 13, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_OVERWORLD_POKEMON_PARTY_MENU_H_
#define INCLUDE_C_OVERWORLD_POKEMON_PARTY_MENU_H_

#include "types.h"
#include "pokemon/virtual.h"

typedef struct {
    void (*callback)();
    u16 field_4;
    u16 field_6;
    u16 field_8;
    u16 field_A;
    u8 tbox_idx_question;
    u8 tbox_idx_options;
    u8 tbox_idx_description;
    u8 options[4];
    u8 field_19;
    u8 field_20;
    u8 field_21;
    u8 field_22;
    u8 number_options;
    u8 field_24[512];
    u16 outdoor_move_idx;

} pokemon_party_menu_options_state_t;

typedef struct {
    pokemon_party_menu_options_state_t *options_state;
    void *callback;
} pokemon_party_menu_state_t;

bool (*pokemon_party_menu_continuation)();

extern pokemon_party_menu_state_t pokemon_party_menu_state;
extern u8 pokemon_party_menu_current_index;
extern u8 pokemon_party_menu_current_index2;
extern u16 item_activated;

/**
 * Fades the party menu back to overworld and executes the field move callback. Used as continuation
 * when field moves are triggered
 * @return true
 */
bool pokemon_party_menu_return_and_execute_field_move();
/**
 * Adds a byte to a list of pokemon party menu context sensitive options (summary, give, take..)
 * @param list the list
 * @param size the offset of the list size
 * @param value the value to add
 */
void pokemon_party_menu_opt_add(u8 *list, u8 *size, u8 value);

/**
 * Gets the currently selected index of the pokemon party menu context sensitive options
 * (summary, give...)
 * @return the currently selected option
 */
u8 pokemon_party_menu_opt_get_current();

/**
 * Returns the index of the pokemon currently selected in the pokemon party
 */
u8 pokemon_party_menu_get_current_index();
/**
 * Callback to trigger a outdoor move from the pokemon party menu context sensitive options
 * @param self the own callback id
 */
void pokemon_party_menu_opt_outdoor_move(u8 callback_self);

/**
 * Builds the context sensitive options (summary, give...) for a pokemon
 * @param base the pokemon object list to build the options fore
 * @param index the index inside the pokemon object list
 */
void pokemon_party_menu_opt_build(pokemon *base, u8 index);

/**
 * Clears the context sensitive options (summary, give...) and prints a string
 * @param string_id the string to print
 */
void pokemon_party_menu_opt_clear_all_and_printstr(u8 string_id);

/**
 * Callback for the pokemon party menu to wait for a keypress and then return to the context
 * sensitive options (summary, give...)
 * @param self the own callback id
 */
void pokemon_party_menu_wait_for_keypress_and_return_to_opts(u8 self);

/**
 * Inits the rendering of text in the pokemon party menu
 * @param text the text to print
 * @param unknown TODO
 */
void pokemon_party_menu_init_text_rendering(u8 *text, u8 unknown);

/**
 * Pokemenu callback to wait for a text to be rendered
 * @param self the own callback id
 */
void pokemon_party_menu_wait_for_text_rendering(u8 self);

/**
 * Returns from the pokemon party menu and executes a callback
 * @param self the own callback id
 */
void pokemon_party_menu_return_and_execute_callback(u8 self);

/**
 * Prints a string from the pokemon party menu as question (i.e. with y/n choice box)
 * @param self the callback id
 */
void pokemon_party_menu_print_question(u8 self);

/**
 * Returns to the pokemon party menu (callback)
 */
void pokemon_party_menu_return_to();

/**
 * Initializes the pokemon party menu
 * @param a TODO
 * @param b TODO
 * @param c TODO
 * @param d TODO
 * @param e TODO
 * @param big_callback some big callback that is executed at some point (much descriptive, yes!)
 * @param return_callback the callback to execute when returning from the pokemon party menu
 */
void pokemon_party_menu_init(u8 a, u8 b, u8 c, u8 d, u8 e, void (*big_callback)(u8),
    void (*return_callback)());

/**
 * Some callback function. Seems to fit well as big_callback parameter for pokemon_party_menu_init.
 * @param self self-reference to the callback
 */
void sub_811FB5C(u8 self);

/**
 * Frees all components of the pokemon party menu
 */
void pokemon_party_menu_free();

/**
 * Callback1 that returns to the pokemon party menu.
 */
void pokemon_party_menu_return_callback();

/**
 * Gets the index in a party of a pokemon considering reordering due to inbattle-switches.
 * @param the current index, possibly after switching
 * @return the index of the pokemon in the player party array
 **/ 
u8 player_party_get_reordered_idx(u8 party_idx);

extern u8 pokemon_party_menu_order[3]; // 4 Bits per slot

#endif /* INCLUDE_C_OVERWORLD_POKEMON_PARTY_MENU_H_ */

/*
 * pokemon_party_menu.h
 *
 *  Created on: May 13, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_OVERWORLD_POKEMON_PARTY_MENU_H_
#define INCLUDE_C_OVERWORLD_POKEMON_PARTY_MENU_H_

#include "pokemon/virtual.h"
#include "types.h"

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
    void (*callback)();
    void (*big_callback)();
    u8 menu_type : 4;
    u8 layout : 2;
    u8 unk_8_6 : 2;
    u8 slot_idx;
    u8 slot_idx2;
    u8 action;
    u16 bag_item;
    s16 data1;
    s16 learn_move_state;
} pokemon_party_menu_state_t;

bool (*pokemon_party_menu_continuation)();

typedef struct {
    /*0x00*/ u16 species;
    /*0x02*/ u16 item;
    /*0x04*/ u8 nickname[11];
    /*0x0F*/ u8 level;
    /*0x10*/ u16 hp;
    /*0x12*/ u16 max_hp;
    /*0x14*/ u32 status;
    /*0x18*/ pid_t pid;
    /*0x1C*/ u8 gender;
    /*0x1D*/ u8 language;
    u16 padding;
} pokemon_party_menu_partner_pokemon_t;

extern pokemon_party_menu_partner_pokemon_t pokemon_party_menu_partner_party[3];

/**
 * Loads the partner party from a normal party.
 * @param p the party from which to load the partner party
 */
void pokemon_party_menu_load_partner_party(pokemon *p);

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

#define PARTY_LAYOUT_SINGLE          0
#define PARTY_LAYOUT_DOUBLE          1
#define PARTY_LAYOUT_MULTI           2
#define PARTY_LAYOUT_MULTI_SHOWCASE  3  // The layout during the screen that appears just before a multi battle
#define PARTY_LAYOUT_COUNT           4
#define KEEP_PARTY_LAYOUT            0xFF

#define PARTY_MENU_TYPE_FIELD                     0 
#define PARTY_MENU_TYPE_IN_BATTLE                 1 
#define PARTY_MENU_TYPE_CONTEST                   2 
#define PARTY_MENU_TYPE_CHOOSE_MON                3 
#define PARTY_MENU_TYPE_CHOOSE_HALF               4  // multi battles, eReader battles, and some battle facilities
#define PARTY_MENU_TYPE_MULTI_SHOWCASE            5
#define PARTY_MENU_TYPE_DAYCARE                   6 
#define PARTY_MENU_TYPE_MOVE_RELEARNER            7 
#define PARTY_MENU_TYPE_UNION_ROOM_REGISTER       8  // trading board
#define PARTY_MENU_TYPE_UNION_ROOM_TRADE          9  // trading board
#define PARTY_MENU_TYPE_SPIN_TRADE                10 // Unused beta for Gen IV's Spin Trade
#define PARTY_MENU_TYPE_MINIGAME                  11

#define PARTY_ACTION_CHOOSE_MON         0
#define PARTY_ACTION_SEND_OUT           1
#define PARTY_ACTION_CANT_SWITCH        2
#define PARTY_ACTION_USE_ITEM           3
#define PARTY_ACTION_ABILITY_PREVENTS   4
#define PARTY_ACTION_GIVE_ITEM          5  
#define PARTY_ACTION_GIVE_PC_ITEM       6
#define PARTY_ACTION_GIVE_MAILBOX_MAIL  7
#define PARTY_ACTION_SWITCH             8
#define PARTY_ACTION_SWITCHING          9
#define PARTY_ACTION_SOFTBOILED         10
#define PARTY_ACTION_CHOOSE_AND_CLOSE   11
#define PARTY_ACTION_MOVE_TUTOR         12
#define PARTY_ACTION_MINIGAME           13
#define PARTY_ACTION_REUSABLE_ITEM      14

// IDs for DisplayPartyMenuStdMessage, to display the message at the bottom of the party menu
#define PARTY_MSG_CHOOSE_MON                0
#define PARTY_MSG_CHOOSE_MON_OR_CANCEL      1
#define PARTY_MSG_CHOOSE_MON_AND_CONFIRM    2
#define PARTY_MSG_MOVE_TO_WHERE             3 
#define PARTY_MSG_TEACH_WHICH_MON           4
#define PARTY_MSG_USE_ON_WHICH_MON          5
#define PARTY_MSG_GIVE_TO_WHICH_MON         6
#define PARTY_MSG_NOTHING_TO_CUT            7
#define PARTY_MSG_CANT_SURF_HERE            8
#define PARTY_MSG_ALREADY_SURFING           9
#define PARTY_MSG_CURRENT_TOO_FAST          10
#define PARTY_MSG_ENJOY_CYCLING             11
#define PARTY_MSG_ALREADY_IN_USE            12
#define PARTY_MSG_CANT_USE_HERE             13
#define PARTY_MSG_NO_MON_FOR_BATTLE         14
#define PARTY_MSG_CHOOSE_MON_2              15
#define PARTY_MSG_NOT_ENOUGH_HP             16
#define PARTY_MSG_THREE_MONS_ARE_NEEDED     17
#define PARTY_MSG_TWO_MONS_ARE_NEEDED       18
#define PARTY_MSG_MONS_CANT_BE_SAME         19
#define PARTY_MSG_NO_SAME_HOLD_ITEMS        20
#define PARTY_MSG_UNUSED                    21
#define PARTY_MSG_DO_WHAT_WITH_MON          22
#define PARTY_MSG_RESTORE_WHICH_MOVE        23
#define PARTY_MSG_BOOST_PP_WHICH_MOVE       24
#define PARTY_MSG_DO_WHAT_WITH_ITEM         25
#define PARTY_MSG_DO_WHAT_WITH_MAIL         26
#define PARTY_MSG_NONE                      127

/**
 * Initializes the pokemon party menu
 * @param menu_type
 * @param layout
 * @param party_action
 * @param keep_cursor_position if the cursor position is to be kept after returning
 * @param message_idx which message to display
 * @param big_callback some big callback that is executed at some point (much descriptive, yes!)
 * @param return_callback the callback to execute when returning from the pokemon party menu
 */
void pokemon_party_menu_init(u8 menu_type, u8 layout, u8 party_action, u8 keep_cursor_position, u8 message_idx, void (*big_callback)(u8),
                             void (*return_callback)());

/**
 * Callback to initialize sliding the partner's party in the pokemon party preview.
 * @param self self-reference
 */
void pokemon_party_menu_partner_party_slide_in_initialize(u8 self);

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
 */
u8 player_party_get_reordered_idx(u8 party_idx);

extern u8 pokemon_party_menu_order[3]; // 4 Bits per slot

/**
 * Contiuation for the party menu that returns to the bag.
 */
void party_menu_continuation_return_to_bag();

/**
 * Callback for opening the pokemon party menu for item use
 */
void pokemon_party_menu_open_for_item_use();

/**
 * Gets the move slot that should be replaced when learning a new move
 * @return the move slot to replace
 */
u8 pokemon_get_move_slot_to_replace();

/**
 * Continuation that uses the item effect stored once the party menu is open
 * @param self self-reference
 */
void pokemon_party_menu_continuation_apply_item_effect(u8 self);

/**
 * Callback that waits for the text to finish and then plays a fanfare for a pokemon that learned a new move
 * @param self self-reference
 */
void pokemon_party_menu_play_fanfare_after_text_finished(u8 self);

#endif /* INCLUDE_C_OVERWORLD_POKEMON_PARTY_MENU_H_ */

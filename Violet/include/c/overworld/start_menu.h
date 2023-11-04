/*
 * menu.h
 *
 *  Created on: May 2, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_OVERWORLD_START_MENU_H_
#define INCLUDE_C_OVERWORLD_START_MENU_H_

typedef struct {
    const u8 *name;
    bool (*initialize)();
} start_menu_item_t;

enum {
    START_MENU_POKEPAD = 0,
    START_MENU_POKEMON,
    START_MENU_BAG,
    START_MENU_PLAYER,
    START_MENU_SAVE,
    START_MENU_OPTION,
    START_MENU_EXIT,
    START_MENU_RETIRE,
    START_MENU_PLAYER2,
    START_MENU_LEAVE_DUNGEON,
    NUM_START_MENU_ITEMS,
};

enum {
    START_MENU_STEUP_STATE_BUILD = 1,
    START_MENU_SETUP_STATE_LOAD_GFX,
    START_MENU_SETUP_STATE_PRINT_SAFARI_OR_CLOCK,
    START_MENU_SETUP_SCANNER,
    START_MENU_SETUP_STATE_PRINT_ITEMS,
    START_MENU_SETUP_STATE_SETUP_LIST,
};

extern const start_menu_item_t start_menu_items[NUM_START_MENU_ITEMS];

typedef struct {
    bool (*callback)(void);
    u8 cursor;
    u8 number_items;
    u8 items[9];
    u8 initialization_state;
    u8 number_items_printed;
    u8 safari_tbox_idx;
} start_menu_state_t;

extern const u8 *const start_menu_item_descriptions[NUM_START_MENU_ITEMS];

extern start_menu_state_t start_menu_state;

#define START_MENU_GFX_7_SEGMENT_TAG 0x3788
enum start_menu_clock_digit{
    START_MENU_CLOCK_HOURS_10, START_MENU_CLOCK_HOURS_1, START_MENU_CLOCK_MINUTES_10, START_MENU_CLOCK_MINUTES_1
};

extern const u8 gfx_start_menu_7_segmentTiles[];
extern const u8 gfx_start_menu_7_segmentPal[];

/**
 * Deletes the additional safari and clock windows of the start menu
 */
void start_menu_delete_safari();

/**
 * Adds an item to the start menu list
 **/
void start_menu_add_item(u8 item_idx);

/**
 * Builds the item idxs of the start menu
 **/
void start_menu_build();

/**
 * Initializes the textbox for the start menu.
 * @param number_items how many items are to be displayed
 * @return the box idx
 **/
u8 start_menu_tbox_initialize(u8 number_items);

/**
 * Creates a tbox for the safari balls in the start menu.
 **/
void start_menu_print_safari_balls();

/**
 * Clears the additional box (clock, safari balls) in the start menu
 **/
void start_menu_clear_additional_box();

/**
 * Draws a certain amount of the start menu items.
 * @param items_drawn_total pointer to how many items were drawn already
 * @param items_to_draw how many items to draw in this iteration
 * @return if all items were drawn with this iteration
 **/
bool start_menu_draw_items(u8 *items_drawn_total, u8 items_to_draw);

/**
 * Returns the box idx of the start menu box.
 * @return the box idx of the start menu box
 **/
u8 start_menu_get_tbox_idx();

/**
 * Prints the description of an item for the start menu.
 * @param str the description string to print
 **/
void start_menu_print_item_description(const u8 *str);

/**
 * Start menu function that initializes saving the game
 **/
bool start_menu_save_initialize();

/**
 * Build start menu items for link
 **/
void start_menu_build_link();

/**
 * Build start menu items for the union room
 **/
void start_menu_build_union_room();

/**
 * Builds the start menu items for the safari context
 **/
void start_menu_build_safari();

/**
 * Builds the standard start menu items
 **/
void start_menu_build_std();

/**
 * Initializes the start menu and clears the additional box (safari / clock)
 **/
bool start_menu_save_initialize_and_clear_additional_box();

/**
 * Initializes the options from the start menu
 **/
bool start_menu_options_initialize();

/**
 * Initializes the pokemon menu from the start menu
 **/
bool start_menu_pokemon_initialize();

/**
 * Initializes the trainer card from the start menu
 **/
bool start_menu_trainer_card_initialize();

/**
 * Initializes the trainer card from the start menu
 **/
bool start_menu_trainer_card_initialize2();

/**
 * Initializes the saving dialoge from the start menu
 **/
bool start_menu_save_initialize();

/**
 * Closes the start menu
 **/
bool start_menu_close();

/**
 * Initializes the retiring from safari dialoge from the start menu
 **/
bool start_menu_retire_initialize();

/**
 * Initializes the bag from the start menu
 **/
bool start_menu_bag_initialize();

/**
 * Fades the screen from the start menu if the overworld is left
*/
void start_menu_fade_if_applicable();

/**
 * Closes the start menu
 */
void start_menu_delete();

#endif /* INCLUDE_C_OVERWORLD_START_MENU_H_ */

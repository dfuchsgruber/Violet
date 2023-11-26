#ifndef H_POKEPAD_POKEDEX_PAGES_MOVE_LIST
#define H_POKEPAD_POKEDEX_PAGES_MOVE_LIST

#include "types.h"

#define POKEDEX_ENTRY_PAGE_MOVE_LIST_MAX_NUM_SHOWN 6
#define POKEDEX_ENTRY_PAGE_MOVE_LIST_MAX_NUM_CHARS 24

enum {
    POKEDEX_ENTRY_PAGE_MOVE_LIST_TBOX_LIST = 0,
    // POKEDEX_ENTRY_PAGE_MOVE_LIST_TBOX_HEADER,
    POKEDEX_ENTRY_PAGE_MOVE_LIST_TBOX_DESCRIPTION,
    POKEDEX_ENTRY_PAGE_MOVE_LIST_TBOX_STAT_NAMES,
    POKEDEX_ENTRY_PAGE_MOVE_LIST_TBOX_STAT_VALUES,
    NUM_POKEDEX_ENTRY_PAGE_MOVE_LIST_TBOXES,
};

enum {
    POKEDEX_ENTRY_PAGE_MOVE_LIST_INITIALIZATION_STATE_DATA_SETUP = 0,
    POKEDEX_ENTRY_PAGE_MOVE_LIST_INITIALIZATION_STATE_SETUP_TBOXES,
    POKEDEX_ENTRY_PAGE_MOVE_LIST_INITIALIZATION_STATE_SETUP_LIST,
    POKEDEX_ENTRY_PAGE_MOVE_LIST_INITIALIZATION_STATE_SETUP_SCROLL_INDICATORS,
    NUM_POKEDEX_ENTRY_PAGE_MOVE_LIST_INITIALIZATION_STATES,
};


extern LZ77COMPRESSED gfx_pokedex_entry_page_move_list_uiTiles;
extern LZ77COMPRESSED gfx_pokedex_entry_page_move_list_uiPal;
extern LZ77COMPRESSED gfx_pokedex_entry_page_move_list_uiMap;

/**
 * Sets up the background for the move list page.
 * @param layer the layer to setup the background on
*/
void pokedex_entry_page_move_list_setup_bg(u8 layer);

/**
 * Performs the setup of the move list page.
 * @return true if the setup is not running
*/
bool pokedex_entry_page_move_list_setup();

/**
 * Performs the destruction of the move list page.
*/
void pokedex_entry_page_move_list_destroy();

/**
 * Handles inputs for the move list page.
 * @param task_id the task id of the task that handles the page.
 * @return true if the input was processed and triggered an action
*/
bool pokedex_entry_page_move_list_handle_inputs(u8 self);

#endif /* H_POKEPAD_POKEDEX_PAGES_MOVE_LIST */
#ifndef H_POKEDEX_ENTRY_PAGE_FLAVOR_TEXT
#define H_POKEDEX_ENTRY_PAGE_FLAVOR_TEXT

#include "types.h"

#define POKEDEX_ENTRY_PAGE_FLAVOR_TEXT_NUM_VISIBLE_LINES 3

enum {
    POKEDEX_ENTRY_PAGE_FLAVOR_TEXT_INITIALIZATION_STATE_DATA_SETUP = 0,
    POKEDEX_ENTRY_PAGE_FLAVOR_TEXT_INITIALIZATION_STATE_SETUP_TBOXES,
    POKEDEX_ENTRY_PAGE_FLAVOR_TEXT_INITIALIZATION_STATE_SETUP_OAM,
    POKEDEX_ENTRY_PAGE_FLAVOR_TEXT_INITIALIZATION_STATE_SETUP_SCROLL_INDICATORS,
};

enum {
    POKEDEX_ENTRY_PAGE_FLAVOR_TEXT_TBOX_DATA = 0,
    POKEDEX_ENTRY_PAGE_FLAVOR_TEXT_TBOX_TEXT,
    NUM_POKEDEX_ENTRY_PAGE_FLAVOR_TEXT_TBOXES,
};

/**
 * Performs the setup of the flavor text page.
 * @return true if the setup is not running
*/
bool pokedex_entry_page_flavor_text_setup();

/**
 * Performs the destruction of the flavor text page.
*/
void pokedex_entry_page_flavor_text_destroy();

/**
 * Handles inputs for the flavor text page.
 * @param task_id the task id of the task that handles the page.
 * @return true if the input was processed and triggered an action
*/
bool pokedex_entry_page_flavor_text_handle_inputs(u8 task_id);

/**
 * Sets up the background for the flavor text page.
 * @param layer the layer to setup the background on
*/
void pokedex_entry_page_flavor_text_setup_bg(u8 layer);

extern LZ77COMPRESSED gfx_pokedex_entry_page_flavor_text_uiTiles;
extern LZ77COMPRESSED gfx_pokedex_entry_page_flavor_text_uiPal;
extern LZ77COMPRESSED gfx_pokedex_entry_page_flavor_text_uiMap;

#endif
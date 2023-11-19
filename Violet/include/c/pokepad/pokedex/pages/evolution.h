#ifndef H_POKEDEX_ENTRY_PAGE_EVOLUTION
#define H_POKEDEX_ENTRY_PAGE_EVOLUTION

#include "types.h"

#define POKEDEX_ENTRY_PAGE_EVOLUTION_NUM_VISIBLE_LINES 3

enum {
    POKEDEX_ENTRY_PAGE_EVOLUTION_INITIALIZATION_STATE_DATA_SETUP = 0,
    POKEDEX_ENTRY_PAGE_EVOLUTION_INITIALIZATION_STATE_SETUP_TBOXES,
    POKEDEX_ENTRY_PAGE_EVOLUTION_INITIALIZATION_STATE_SETUP_OAM,
    POKEDEX_ENTRY_PAGE_EVOLUTION_INITIALIZATION_STATE_SETUP_SCROLL_INDICATORS,
};
enum {
    POKEDEX_ENTRY_PAGE_EVOLUTION_TBOX_DATA = 0,
    POKEDEX_ENTRY_PAGE_EVOLUTION_TBOX_TEXT,
    NUM_POKEDEX_ENTRY_PAGE_EVOLUTION_TBOXES,
};

/**
 * Performs the setup of the evolution info page.
 * @return true if the setup is not running
*/
bool pokedex_entry_page_evolution_setup();

/**
 * Performs the destruction of the evolution info page.
*/
void pokedex_entry_page_evolution_destroy();

/**
 * Handles inputs for the evolution info page.
 * @param task_id the task id of the task that handles the page.
 * @return true if the input was processed and triggered an action
*/
bool pokedex_entry_page_evolution_handle_inputs(u8 task_id);

extern const LZ77COMPRESSED gfx_pokedex_entry_page_evolution_uiTiles;
extern const LZ77COMPRESSED gfx_pokedex_entry_page_evolution_uiPal;
extern const LZ77COMPRESSED gfx_pokedex_entry_page_evolution_uiMap;

#endif
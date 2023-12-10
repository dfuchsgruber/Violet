#ifndef H_POKEPAD_POKEDEX_PAGES_STATS
#define H_POKEPAD_POKEDEX_PAGES_STATS

#include "types.h"
#include "constants/pokemon_stat_names.h"

#define POKEDEX_ENTRY_PAGE_STATS_HEXAGON_SIZE 96
#define POKEDEX_ENTRY_PAGE_STATS_HEXAGON_X 138
#define POKEDEX_ENTRY_PAGE_STATS_HEXAGON_Y 75

enum {
    POKEDEX_ENTRY_PAGE_STATS_TBOX_STAT_BASE = 0,
    NUM_POKEDEX_ENTRY_PAGE_STATS_TBOXES = STAT_SPECIAL_DEFENSE + 1,
};

enum {
    POKEDEX_ENTRY_PAGE_STATS_INITIALIZATION_STATE_DATA_SETUP = 0,
    POKEDEX_ENTRY_PAGE_STATS_INITIALIZATION_STATE_SETUP_TBOXES,
    POKEDEX_ENTRY_PAGE_STATS_INITIALIZATION_STATE_SETUP_OAM,
    NUM_POKEDEX_ENTRY_PAGE_STATS_INITIALIZATION_STATES,
};

enum {
    POKEDEX_ENTRY_PAGE_STATS_GFX_BASESTATS = 0x72F0,
};


extern LZ77COMPRESSED gfx_pokedex_entry_page_stats_uiTiles;
extern LZ77COMPRESSED gfx_pokedex_entry_page_stats_uiMap;
extern LZ77COMPRESSED gfx_pokedex_entry_page_stats_uiPal;

/**
 * Sets up the background for the move list page.
 * @param layer the layer to setup the background on
*/
void pokedex_entry_page_stats_setup_bg(u8 layer);

/**
 * Performs the setup of the move list page for extra moves (tutor, tm, egg, ...)
 * @return true if the setup is not running
*/
bool pokedex_entry_page_stats_setup();

/**
 * Performs the destruction of the move list page.
*/
void pokedex_entry_page_stats_destroy();

/**
 * Handles inputs for the move list page.
 * @param task_id the task id of the task that handles the page.
 * @return true if the input was processed and triggered an action
*/
bool pokedex_entry_page_stats_handle_inputs(u8 self);

#endif /* H_POKEPAD_POKEDEX_PAGES_STATS */
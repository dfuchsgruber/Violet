#ifndef H_POKEDEX_ENTRY_PAGE_EVOLUTION
#define H_POKEDEX_ENTRY_PAGE_EVOLUTION

#include "types.h"
#include "pokepad/pokedex/entry.h"
#include "bg.h"

#define POKEDEX_ENTRY_PAGE_EVOLUTION_NUM_VISIBLE_LINES 4

#define POKEDEX_ENTRY_PAGE_EVOLUTION_BASE_TILE_UI(layer) (1 + (layer) * POKEDEX_ENTRY_PAGE_NUM_TILES)
#define POKEDEX_ENTRY_PAGE_EVOLUTION_BASE_TILE_TBOX(layer) (1 + (layer) * POKEDEX_ENTRY_PAGE_NUM_TILES + 200)


#define POKEDEX_ENTRY_PAGE_EVOLUTION_TBOX_TILE(layer,tile) ((bg_tile){\
    .text = {\
        .tile_number = (u16)(((POKEDEX_ENTRY_PAGE_EVOLUTION_BASE_TILE_TBOX((layer)) + (tile)) & 0x3FF)),\
        .palette = (u16)((2 + (layer) * POKEDEX_ENTRY_PAGE_NUM_PALS) & 0xF),\
    }\
})

enum {
    GFX_TAG_POKEDEX_ENTRY_PAGE_EVOLUTION_ICON_BASE = 0x4611,
};

enum {
    POKEDEX_ENTRY_PAGE_EVOLUTION_INITIALIZATION_STATE_DATA_SETUP = 0,
    POKEDEX_ENTRY_PAGE_EVOLUTION_INITIALIZATION_STATE_SETUP_TBOXES,
    POKEDEX_ENTRY_PAGE_EVOLUTION_INITIALIZATION_STATE_SETUP_OAM,
    POKEDEX_ENTRY_PAGE_EVOLUTION_INITIALIZATION_STATE_SETUP_SCROLL_INDICATORS,
};

enum {
    POKEDEX_ENTRY_PAGE_EVOLUTION_TBOX_BASE = 0,
    NUM_POKEDEX_ENTRY_PAGE_EVOLUTION_TBOXES = POKEDEX_ENTRY_PAGE_EVOLUTION_TBOX_BASE + POKEDEX_ENTRY_PAGE_EVOLUTION_NUM_VISIBLE_LINES,
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

/**
 * Sets up the background for the evolution info page.
 * @param layer the layer to setup the background on
*/
void pokedex_entry_page_evolution_setup_bg(u8 layer);

extern const LZ77COMPRESSED gfx_pokedex_entry_page_evolution_uiTiles;
extern const LZ77COMPRESSED gfx_pokedex_entry_page_evolution_uiPal;
extern const LZ77COMPRESSED gfx_pokedex_entry_page_evolution_uiMap;
extern const LZ77COMPRESSED gfx_pokedex_entry_page_evolution_ui_tboxTiles;

#endif
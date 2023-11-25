#ifndef H_POKEPAD_POKEDEX_ENTRY
#define H_POKEPAD_POKEDEX_ENTRY

#include "types.h"
#include "bg.h"
#include "color.h"

#define POKEDEX_ENTRY_PAGE_START_TILE (1 + TBOX_FRAME_SET_STYLE_NUM_TILES  + 10 * 3 + 10 * 3 + 2 * 3 + 2 * 9 + 2 * 8 + 2 * 8)
#define POKEDEX_ENTRY_PAGE_NUM_PALS 2
#define POKEDEX_ENTRY_PAGE_NUM_TILES 256

enum {
    POKEDEX_ENTRY_INITIALIZATION_STATE_DATA_SETUP = 0,
    POKEDEX_ENTRY_INITIALIZATION_STATE_STATE_RESET,
    POKEDEX_ENTRY_INITIALIZATION_STATE_SETUP_BGS,
    POKEDEX_ENTRY_INITIALIZATION_STATE_SETUP_TBOXES,
    POKEDEX_ENTRY_INITIALIZATION_STATE_LOAD_GFX,
    POKEDEX_ENTRY_INITIALIZATION_STATE_SETUP_OAM,
    POKEDEX_ENTRY_INITIALIZATION_STATE_LOAD_PAGE,
    POKEDEX_ENTRY_INITIALIZATION_STATE_SETUP_SHOW,
};

enum {
    POKEDEX_ENTRY_TBOX_PAGE_TITLE = 0,
    POKEDEX_ENTRY_TBOX_TITLE,
    POKEDEX_ENTRY_TBOX_CAUGHT_ICON,
    POKEDEX_ENTRY_TBOX_TYPES,
    POKEDEX_ENTRY_TBOX_CATEGORY,
    POKEDEX_ENTRY_TBOX_HABITAT,
    NUM_POKEDEX_ENTRY_TBOXES,
};

enum {
    POKEDEX_ENTRY_GFX_TAG_SPECIES = 0x60B0,
    POKEDEX_ENTRY_GFX_TAG_FORM,
    POKEDEX_ENTRY_GFX_TAG_EGG,
    POKEDEX_ENTRY_GFX_TAG_POKEBALL,
    POKEDEX_ENTRY_GFX_TAG_HEART,
};

enum {
    POKEDEX_ENTRY_PAGE_FLAVOR_TEXT = 0,
    POKEDEX_ENTRY_PAGE_EVOLUTION,
    NUM_POKEDEX_ENTRY_PAGES,
};

enum {
    POKEDEX_ENTRY_PAGE_CONTEXT_POKEDEX = 0,
    POKEDEX_ENTRY_PAGE_CONTEXT_CATCHING,
    POKEDEX_ENTRY_PAGE_NUM_CONTEXTS,
};

typedef struct {
    const u8 *title;
    bool (*setup)();
    void (*destroy)();
    bool (*handle_inputs)(u8);
    void (*setup_bg)(u8);
} pokedex_entry_page_t;

typedef struct {
    u16 species;
    u16 method;
    u16 argument;
    u8 indent : 4;
    u8 is_egg : 1;
    u8 is_mega : 1;
    u8 hatches_from_egg : 1;
} pokedex_entry_evolution_tree_node_t;

#define POKEDEX_ENTRY_PAGE_EVOLUTION_MAX_TREE_SIZE 12

typedef struct {
    u8 initialization_state;
    u8 page_initialization_state;
    u8 context;
    u8 page;
    u16 species;
    color_t color_to_fade_from;
    void (*continuation)();
    bg_tile (*bg_maps[4])[32];
    u8 pal_idx_pokemon;
    u8 oam_idx_pokemon;
    u16 base_tile_pokemon;
    u8 play_cry;
    u16 bg_x_offset[4];
    u16 bg_y_offset[4];
    // From catching
    u8 handle_inputs_delay;
    // This callback should only be killed in the catching context to indicate 
    // that the catching sequence continues: the vanilla game checks if this
    // callback is active (which is error prone, one could have spawned another one
    // at its index before returning controll...)
    u8 catching_cb_idx; 
    // Data for the page
    u8 page_layer : 1;
    u8 page_num_tboxes;
    u8 page_tbox_idxs[16];
    // For flavor text
    u8 page_flavor_text_num_lines;
    u16 page_flavor_text_first_line;
    u8 page_flavor_text_form_oam_idx;
    u8 page_flavor_text_egg_oam_idx;
    u8 page_flavor_text_pokeball_oam_idx;
    u8 page_flavor_text_heart_oam_idx;
    u8 page_flavor_text_scroll_indicators_cb_idx;
    // Evolution Page
    pokedex_entry_evolution_tree_node_t evolution_tree[POKEDEX_ENTRY_PAGE_EVOLUTION_MAX_TREE_SIZE];
    u8 evolution_tree_any_caught : 1;
    u8 evolution_tree_size;
    u8 evolution_tree_icon_oam_idxs[4];
    u16 evolution_tree_cursor;
    u16 evolution_tree_icon_base_tiles[4];
    u8 evolution_tree_icon_pal_idxs[4];
    u8 evolution_tree_scroll_indicators_cb_idx;

} pokedex_entry_state_t;

extern EWRAM pokedex_entry_state_t *pokedex_entry_state;

/**
 * Initializes the pokedex entry screen
 * @param species The species to display
 * @param context The context of the pokedex entry screen
 * @param continuation_cb1 The callback to set when the screen is closed
 * @param play_cry Whether to play the cry when the screen is opened
 * @param color_to_fade_from The color to fade from
*/
void pokedex_entry_initialize(u16 species, u8 context, void (*continuation_cb1)(), bool play_cry,
    color_t color_to_fade_from);

/**
 * Initializes tboxes for a page on the entry
 * @param boxes The tboxes to initialize
*/
void pokedex_entry_page_initialize_tboxes(const tboxdata *boxes);

/**
 * Frees tboxes for a page on the entry
*/
void pokedex_entry_page_free_tboxes();

/**
 * Loads the graphics for a page on the entry to the current layer
 * @param layer The layer to load the graphics to
 * @param tiles The tiles to load
 * @param map The map to load
 * @param pal The palette to load
*/
void pokedex_entry_page_load_gfx(u8 layer, const void *tiles, const void *map, const void *pal);

/**
 * Initializes the entry ui after a pokemon was caught in battle
 * @param species The species to display
 * @return The index of the callback: it is a dummy callback that is killed upon exiting the entry screen
*/
u8 pokedex_entry_initialize_from_battle(u16 species);

#endif /* H_POKEPAD_POKEDEX_ENTRY */
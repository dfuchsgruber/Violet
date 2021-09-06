#ifndef H_POKEPAD2
#define H_POKEPAD2

#include "types.h"
#include "save.h"
#include "oam.h"
#include "list_menu.h"

typedef struct {
    const u8 *tileset;
    const u8 *tilemap;
    const u8 *palette;
    const u8 name[14];
    u16 flag;
} pokepad_wallpaper;

#define POKEPAD_NUM_WALLPAPERS 2

typedef struct {
    u8 initialization_state;
    u8 callback_idx;
    u8 cursor_idx;
    u8 cursor_oam;
    u8 items[8];
    u8 num_items;
    u8 app_oams[8];
    u8 num_app_oams;
    u8 left_oam;
    u8 right_oam;
    u8 tbox_idx_context_menu;
    u8 callback_idx_context_menu;
    u8 scroll_indicator_callback_idx;
    u16 context_menu_list_size;
    u16 context_menu_num_items_shown;
    u16 context_menu_cursor_position;
    u16 context_menu_num_items_above;
    list_menu_item wallpaper_list[POKEPAD_NUM_WALLPAPERS];
} pokepad_memory2;


typedef struct {
    u16 flag;
    u8 *name;
    void (*initialize)(bool from_overworld);
    u8 *description;
    graphic icon_graphic;
    palette icon_palette;
} pokepad2_item;

enum {
    POKEPAD_ITEM_POKEDEX,
    POKEPAD_ITEM_WONDERTRADE,
    POKEPAD_ITEM_POKERADAR,
    POKEPAD_ITEM_INCUBATOR
};

enum {
    POKEPAD_CURSOR_TAG = 0x1775,
    POKEPAD_LEFT_INDICATOR_TAG,
    POKEPAD_RIGHT_INDICATOR_TAG,
    POKEPAD_ITEM_ICON_BASE_TAG,
};

/**
 * Frees all resources allocated by the pokepad gui
 **/
void pokepad2_free();

/**
 * Callback1 that initializes the pokepad gui from a black screen. 
 * Assumes that resources of the previous context are released.
 **/
void pokepad2_callback_initialize();

/**
 * Initializes the pokepad from the start menu
 **/
bool start_menu_pokepad_initialize();

extern const u8 gfx_pokepad_wallpaper_startersTiles[];
extern const u8 gfx_pokepad_wallpaper_startersPal[];
extern const u8 gfx_pokepad_wallpaper_startersMap[];
extern const u8 gfx_pokepad_wallpaper_elite_four_foundersTiles[];
extern const u8 gfx_pokepad_wallpaper_elite_four_foundersPal[];
extern const u8 gfx_pokepad_wallpaper_elite_four_foundersMap[];

extern const u8 gfx_pokepad_icon_incubatorTiles[];
extern const u8 gfx_pokepad_icon_incubatorPal[];
extern const u8 gfx_pokepad_icon_pokedexTiles[];
extern const u8 gfx_pokepad_icon_pokedexPal[];
extern const u8 gfx_pokepad_icon_pokeradarTiles[];
extern const u8 gfx_pokepad_icon_pokeradarPal[];
extern const u8 gfx_pokepad_icon_wondertradeTiles[];
extern const u8 gfx_pokepad_icon_wondertradePal[];

extern const u8 gfx_pokepad_cursorTiles[];
extern const u8 gfx_pokepad_cursorPal[];
extern const u8 gfx_pokepad_indicator_leftTiles[];
extern const u8 gfx_pokepad_indicator_leftPal[];
extern const u8 gfx_pokepad_indicator_rightTiles[];

#define POKEPAD_STATE ((pokepad_memory2*)fmem.pad_mem)


#endif
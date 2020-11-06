#ifndef H_POKEPAD2
#define H_POKEPAD2

#include "types.h"
#include "save.h"
#include "oam.h"

typedef struct {
    u8 initialization_state;
    u8 callback_idx;
    u8 cursor_idx;
    u8 items[8];
    u8 num_items;
    u8 app_oams[8];
    u8 num_app_oams;
    u8 left_oam;
    u8 right_oam;
} pokepad_memory2;

typedef struct {
    const u8 *tileset;
    const u8 *tilemap;
    const u8 *palette;
    u16 flag;
} pokepad_wallpaper;

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

#define POKEPAD_ITEM_ICON_BASE_TAG 0x1776

extern const u8 gfx_pokepad_wallpaper_startersTiles[];
extern const u8 gfx_pokepad_wallpaper_startersPal[];
extern const u8 gfx_pokepad_wallpaper_startersMap[];

extern const u8 gfx_pokepad_icon_incubatorTiles[];
extern const u8 gfx_pokepad_icon_incubatorPal[];
extern const u8 gfx_pokepad_icon_pokedexTiles[];
extern const u8 gfx_pokepad_icon_pokedexPal[];
extern const u8 gfx_pokepad_icon_pokeradarTiles[];
extern const u8 gfx_pokepad_icon_pokeradarPal[];
extern const u8 gfx_pokepad_icon_wondertradeTiles[];
extern const u8 gfx_pokepad_icon_wondertradePal[];

#define POKEPAD_STATE ((pokepad_memory2*)fmem.pad_mem)


#endif
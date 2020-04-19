#include "types.h"
#include "oam.h"
#include "callbacks.h"
#include "bios.h"
#include "bg.h"
#include "save.h"
#include "debug.h"
#include "map/event.h"
#include "overworld/map_control.h"
#include "vars.h"
#include "flags.h"

#define HIRO_GFX 0x1337
#define SLASH_GFX 0x1338
#define LUCIUS_GFX 0x1339

extern const u8 gfx_ardeal_tower_hiro_hitTiles[];
extern const u8 gfx_ardeal_tower_slashTiles[];
extern const u8 gfx_ardeal_tower_luciusTiles[];

graphic ae_animation_ardeal_tower_hiro_falling_graphic = {
    .sprite = gfx_ardeal_tower_hiro_hitTiles, .tag = HIRO_GFX, .size = GRAPHIC_SIZE_4BPP(16, 16)
};

graphic ae_animation_ardeal_tower_slash_graphic = {
    .sprite = gfx_ardeal_tower_slashTiles, .tag = SLASH_GFX, .size = GRAPHIC_SIZE_4BPP(16, 6 * 16)
};

graphic ae_animation_ardeal_tower_lucius_graphic = {
    .sprite = gfx_ardeal_tower_luciusTiles, .tag = LUCIUS_GFX, .size = GRAPHIC_SIZE_4BPP(16, 6 * 16)
};

static sprite hiro_falling_oam = {
    .attr0 = ATTR0_SHAPE_SQUARE, .attr1 = ATTR1_SIZE_16_16, .attr2 = ATTR2_PRIO(1),
};

oam_template ae_animation_ardeal_tower_hiro_falling_oam_template = {
    .tiles_tag = HIRO_GFX, .pal_tag = HIRO_GFX, .oam = &hiro_falling_oam,
    .animation = oam_gfx_anim_table_null, .graphics = NULL, .rotscale = oam_rotscale_anim_table_null,
    .callback = oam_null_callback,
};

static gfx_frame frames_scratch[] = {
    {.data = 0, .duration = 0},
    {.data = 0, .duration = 4},
    {.data = 4, .duration = 4},
    {.data = 8, .duration = 4},
    {.data = 12, .duration = 4},
    {.data = 16, .duration = 4},
    {.data = 20, .duration = 4},
    {.data = 20, .duration = 0},
    {.data = GFX_ANIM_END},
};

static gfx_frame *animations_scratch[] = {
    frames_scratch,
};

static gfx_frame frames_lucius_idle[] = {
    {.data = 0, .duration = 0},
    {.data = GFX_ANIM_END},
};


oam_template ae_animation_ardeal_tower_slash_oam_template = {
    .tiles_tag = SLASH_GFX, .pal_tag = SLASH_GFX, .oam = &hiro_falling_oam,
    .animation = animations_scratch, .graphics = NULL, .rotscale = oam_rotscale_anim_table_null,
    .callback = oam_null_callback,
};

static gfx_frame frames_lucius_strike[] = {
    {.data = 0, .duration = 0},
    {.data = 0, .duration = 4},
    {.data = 4, .duration = 4},
    {.data = 8, .duration = 4},
    {.data = 12, .duration = 4},
    {.data = 16, .duration = 4},
    {.data = 20, .duration = 4},
    {.data = 20, .duration = 0},
    {.data = GFX_ANIM_END},
};

static gfx_frame *animations_lucius[] = {
    frames_lucius_strike,
    frames_lucius_idle,
};


oam_template ae_animation_ardeal_tower_lucius_oam_template = {
    .tiles_tag = LUCIUS_GFX, .pal_tag = LUCIUS_GFX, .oam = &hiro_falling_oam,
    .animation = animations_lucius, .graphics = NULL, .rotscale = oam_rotscale_anim_table_null,
    .callback = oam_null_callback,
};

extern u8 gfx_ardeal_tower_hiro_falling1Tiles[];
extern u8 gfx_ardeal_tower_hiro_falling1Map[];
extern u8 gfx_ardeal_tower_hiro_falling2Tiles[];
extern u8 gfx_ardeal_tower_hiro_falling2Map[];

extern u8 gfx_ardeal_tower_hiroine_falling1Tiles[];
extern u8 gfx_ardeal_tower_hiroine_falling1Map[];
extern u8 gfx_ardeal_tower_hiroine_falling2Tiles[];
extern u8 gfx_ardeal_tower_hiroine_falling2Map[];

#define BG_IDX 1

void animation_ardeal_tower_falling_bg_animation(u8 self) {
    u16 *clk = big_callbacks[self].params + 0;
    u16 *frame = big_callbacks[self].params + 1;
    if (*clk > 0) {
        --*clk;
        return;
    }
    *clk = 8;
    void *tileset_src; void *tilemap_src;
    if (save2->player_is_female ) {
        tileset_src = *frame ? gfx_ardeal_tower_hiroine_falling2Tiles : gfx_ardeal_tower_hiroine_falling1Tiles;
        tilemap_src = *frame ? gfx_ardeal_tower_hiroine_falling2Map : gfx_ardeal_tower_hiroine_falling1Map;
    } else {
        tileset_src = *frame ? gfx_ardeal_tower_hiro_falling2Tiles : gfx_ardeal_tower_hiro_falling1Tiles;
        tilemap_src = *frame ? gfx_ardeal_tower_hiro_falling2Map : gfx_ardeal_tower_hiro_falling1Map;
    }
    bg_copy_vram(BG_IDX, tileset_src, 0x2000, 0, BG_COPY_TILESET);
    // dprintf("Tileset %x, frame %d\n", tileset_src, *frame);
    lz77uncompwram(tilemap_src, bg_get_tilemap(BG_IDX));
    bg_copy_vram(BG_IDX, bg_get_tilemap(BG_IDX), 0x800, 0, BG_COPY_TILEMAP);
    *frame ^= 1;
}


#define WARP_BANK 33
#define WARP_MAP_IDX 0
#define WARP_WARP_IDX 4

void animation_ardeal_tower_warp() {

    ++*var_access(STORY_PROGRESS);
    *var_access(SONG_OVERRIDE) = 0xFFFF; // No song on entrance to bb's ship
    // Pokémon, Poképad, Badges, Money are stolen from the player
    // Remove badges
    clearflag(FRBADGE_1);
    clearflag(FRBADGE_2);
    clearflag(FRBADGE_3);
    clearflag(FRBADGE_4);
    clearflag(FRBADGE_5);
    // Set the player's party to stolen and remove the pokepad
    setflag(FLAG_PLAYER_PARTY_STOLEN);
    player_pokemon_recount_pokemon();
    clearflag(PKMNMENU);
    clearflag(POKEDEX);
    // Player loses all money
    money_set(&cmem.money_backup, money_get(&save1->money));
    money_set(&save1->money, 0);
	warp_setup_by_event(WARP_BANK, WARP_MAP_IDX, WARP_WARP_IDX);
    warp_setup_muted_callback();
    warp_enable_flags();
}
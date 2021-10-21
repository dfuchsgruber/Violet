#ifndef H_BERRY
#define H_BERRY

#include "constants/berry_stages.h"
#include "constants/items.h"
#include "oam.h"
#include "overworld/sprite.h"
#include "save.h"
#include "types.h"

#define OW_PAL_TAG_BERRY_BASE 0x2800
#define NUM_OW_PAL_TAGS_BERRY 6
#define TAG_BERRY_GROWTH_SPARKLE 0x2880

#define ITEM_FIRST_BERRY ITEM_AMRENABEERE
#define ITEM_IDX_TO_BERRY_IDX(item_idx) ((item_idx)-ITEM_FIRST_BERRY)
#define BERRY_IDX_TO_ITEM_IDX(berry_idx) ((berry_idx) + ITEM_FIRST_BERRY)

typedef struct { // From pokeemerald
    /*0x00*/ u8 name[7];
    /*0x07*/ u8 firmness;
    /*0x08*/ u16 size;
    /*0x0A*/ u8 max_yield;
    /*0x0B*/ u8 min_yield;
    /*0x0C*/ const u8 *description1;
    /*0x10*/ const u8 *description2;
    /*0x14*/ u8 stage_duration;
    /*0x15*/ u8 spicy;
    /*0x16*/ u8 dry;
    /*0x17*/ u8 sweet;
    /*0x18*/ u8 bitter;
    /*0x19*/ u8 sour;
    /*0x1A*/ u8 smoothness;
} berry;

typedef struct {
    void (*continuation)(void);
    u16 indicator_offfset;
    u8 indicator_callback_idx;
    u8 num_list_menu_items;
    u8 list_menu_max_showed;
    u8 item_menu_icon_idx;
    u8 __attribute__((aligned(4))) bg1map[0x800];
    s16 data[4];
} berry_pouch_state_t;

/**
 * Fades the berry pouch and loads the continuation. Resources are freed as well.
 * @param self self-reference
 */
void berry_pouch_fade_and_continuation(u8 self);

/**
 * Initializes the berry pouch menu.
 * @param context in which context. Different contexts enables different behaviour
 * @param continuation the continuation after the berry pouch is closed
 * @param allow_select if select is allowed
 */
void berry_pouch_initialize(u8 context, void (*continuation)(), u8 allow_select);

/**
 * Gets the information of a berry
 * @param berry_idx the berry to get
 * @return berry the information of the berry
 */
berry *berry_get(u8 berry_idx);

/**
 * Gets the overworld sprite of a berry tree.
 * @param berry_idx the idx of the berry tree
 * @return the overworld sprite of the berry tree
 */
overworld_sprite *overworld_sprite_get_by_berry_tree_idx(u8 berry_tree_idx);

/**
 * Gets the overworld sprite of a berry
 * @param berry_idx the idx of the berry
 * @param the stage of the berry
 * @param if the berry is fertilized
 * @return the overworld sprite of the berry tree
 */
overworld_sprite *overworld_sprite_get_by_berry_idx(u8 berry_idx, u8 stage, bool fertilized);

/**
 * Gets the palette of a berry tree
 * @param berry_idx the idx of the berry tree
 * @return the palette of the berry tree
 */
palette *overworld_palette_get_by_berry_idx(u8 berry_idx);

/**
 * Gets the picture idx associated with a berry tree
 * @param berry_idx the idx of the berry tree
 * @return the picture idx of the berry tree
 */
u8 overworld_get_sprite_idx_by_berry_idx(u8 berry_idx);

/**
 * Gets the palette of a berry tree pal tag
 * @param tag the pal tag to get the palette of
 * @return the palette of the berry tree
 */
palette *overworld_palette_berry_get_by_tag(u16 tag);

/**
 * Tries proceeding the berry growth based on the ingame time
 */
void berry_proceed();

/**
 * Initializes a berry tree, but keeps its fertilization state.
 * @param berry_tree_idx which berry tree to initialize
 * @param berry_idx with which berry to initialize
 * @param stage at which stage
 */
void berry_tree_initialize(u8 berry_tree_idx, u8 berry_idx, u8 stage);

/**
 * Initializes all berry trees.
 */
void berry_trees_initialize_all();

extern void berry_pouch_callback_context_menu(u8 self);
extern void berry_pouch_callback_from_party_menu_give(u8 self);
extern void berry_pouch_callback_from_storage_pc(u8 self);
extern void berry_pouch_callback_from_mart_sell(u8 self);

extern u8 gfx_ow_berry_cheriTiles[];
extern u8 gfx_ow_berry_chestoTiles[];
extern u8 gfx_ow_berry_pechaTiles[];
extern u8 gfx_ow_berry_rawstTiles[];
extern u8 gfx_ow_berry_aspearTiles[];
extern u8 gfx_ow_berry_leppaTiles[];
extern u8 gfx_ow_berry_oranTiles[];
extern u8 gfx_ow_berry_persimTiles[];
extern u8 gfx_ow_berry_lumTiles[];
extern u8 gfx_ow_berry_sitrusTiles[];
extern u8 gfx_ow_berry_figyTiles[];
extern u8 gfx_ow_berry_wikiTiles[];
extern u8 gfx_ow_berry_magoTiles[];
extern u8 gfx_ow_berry_aguavTiles[];
extern u8 gfx_ow_berry_iapapaTiles[];
extern u8 gfx_ow_berry_razzTiles[];
extern u8 gfx_ow_berry_wepearTiles[];
extern u8 gfx_ow_berry_pomegTiles[];
extern u8 gfx_ow_berry_kelpsyTiles[];
extern u8 gfx_ow_berry_hondewTiles[];
extern u8 gfx_ow_berry_grepaTiles[];
extern u8 gfx_ow_berry_tamatoTiles[];
extern u8 gfx_ow_berry_cornnTiles[];
extern u8 gfx_ow_berry_rabutaTiles[];
extern u8 gfx_ow_berry_nomelTiles[];
extern u8 gfx_ow_berry_spelonTiles[];
extern u8 gfx_ow_berry_pamtreTiles[];
extern u8 gfx_ow_berry_durinTiles[];
extern u8 gfx_ow_berry_liechiTiles[];
extern u8 gfx_ow_berry_lansatTiles[];

extern u8 gfx_ow_berry_noneTiles[];
extern u8 gfx_ow_berry_none_fertilizedTiles[];
extern u8 gfx_ow_berry_dirt_pileTiles[];
extern u8 gfx_ow_berry_sproutTiles[];

extern u8 gfx_berry_tree_growth_sparkleTiles[];
extern color_t gfx_berry_tree_growth_sparklePal[16];

extern color_t gfx_ow_berry_pal2Pal[16];
extern color_t gfx_ow_berry_pal3Pal[16];
extern color_t gfx_ow_berry_pal4Pal[16];
extern color_t gfx_ow_berry_pal5Pal[16];

#endif

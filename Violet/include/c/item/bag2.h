#ifndef H_ITEM_BAG_2
#define H_ITEM_BAG_2

#include "types.h"
#include "bag.h"
#include "save.h"
#include "list_menu.h"
#include "constants/item_pockets.h"

enum {
    BAG_OPEN_ITEMS = 0,
    BAG_OPEN_KEYITEMS = 1,
    BAG_OPEN_POKEBALLS = 2,
    BAG_OPEN_LAST = 3,
    BAG_OPEN_TM_HM = 4,
    BAG_OPEN_BERRIES = 5,
    BAG_OPEN_BAIT = 6,
};

enum {
    BAG_CONTEXT_OVERWORLD = 0,
    BAG_CONTEXT_PARTY_GIVE,
    BAG_CONTEXT_SELL,
    BAG_CONTEXT_DEPOSIT,
    BAG_CONTEXT_BOX_GIVE,
    BAG_CONTEXT_BATTLE,
    BAG_CONTEXT_OLD_MAN,
    BAG_CONTEXT_TTVSCR_STATUS,
    BAG_CONTEXT_TTVSCR_CATCHING,
    BAG_CONTEXT_TTVSCR_REGISTER,
    BAG_CONTEXT_TTVSCR_TMS,
    BAG_CONTEXT_TTVSCR_LAST,
    BAG_CONTEXT_RECHARGE_TM_HM,
    BAG_CONTEXT_COMPOST,
    BAG_CONTEXT_PLANT_BERRY,
    NUM_BAG_CONTEXTS,
};

typedef struct {
    u8 initialization_state;
    u8 gfx_initialization_state;
    u8 context;
    u8 open_which;
    void (*continuation)();
    list_menu_item *list_menu_items;
    u8 (*list_menu_item_texts)[19];
    void *bg0_map;
    void *bg1_map;
    void *bg2_map;
    u8 oam_idx_bag;
    u8 oam_idx_item;
    u8 pal_idx_item;
    u16 oam_item_base_tile;
    u16 cursor_items_above[NUM_POCKETS];
    u16 cursor_position[NUM_POCKETS];
    u8 pocket_size[NUM_POCKETS];
    u8 pocket_max_shown[NUM_POCKETS];
    u8 idle_cb_idx;
    u8 list_menu_cb_idx;
    u8 scroll_indicator_items_cb_idx;
    u8 scroll_indicator_pockets_cb_idx;
    u8 pocket_switching_disabled;
} bag2_state_t;

#define BAG2_STATE ((bag2_state_t*)fmem.bag2_state)

#define BAG_OAM_TAG 0x3173
#define BAG_ITEM_OAM_TAG 0x3174

extern LZ77COMPRESSED gfx_bag_backgroundTiles;
extern LZ77COMPRESSED gfx_bag_backgroundMap;
extern LZ77COMPRESSED gfx_bag_backgroundPal;
extern LZ77COMPRESSED gfx_bag2Tiles;
extern LZ77COMPRESSED gfx_bag2Pal;

/**
 * @brief Opens the bag menu
 * 
 * @param context In which context the bag is opened
 * @param open_which which pocket to open
 * @param continuation the continuation on close
 */
void bag_open(u8 context, u8 open_which, void (*continuation)());

#endif
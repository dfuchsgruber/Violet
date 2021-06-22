#ifndef H_OVERWORLD_DETECTOR
#define H_OVERWORLD_DETECTOR
#include "types.h"
#include "map/header.h"

/**
 * Creates the static detector arrow
 * @return oam idx of the arrow
 **/
u8 overworld_effect_static_detector_arrow_new();

/**
 * Callback that updates the detector arrow that is shown above the player.
 * @param self self-reference
 **/
void overworld_static_detector_callback(u8 self);

enum {
    DETECTOR_ON = 0,
    DETECTOR_OFF = 1
};

enum {
    HIDDEN_ITEM_CB_VAR_DX = 0,
    HIDDEN_ITEM_CB_VAR_DY = 1,
    HIDDEN_ITEM_CB_VAR_ITEM_WAS_FOUND = 2,
    HIDDEN_ITEM_CB_VAR_DING_TIMER = 3,
    HIDDEN_ITEM_CB_VAR_NUM_DINGS_REMAINING = 4,
    HIDDEN_ITEM_CB_VAR_DING_NUM = 5,
    HIDDEN_ITEM_CB_VAR_IS_UNDERFOOT = 6,
    HIDDEN_ITEM_CB_VAR_OAM_IDX_STARS = 7,
    NUM_HIDDEN_ITEM_CB_VARS,
};

enum {
    DETECTOR_CB_VAR_OAM_IDX_ARROW = NUM_HIDDEN_ITEM_CB_VARS,
    DETECTOR_CB_VAR_X,
    DETECTOR_CB_VAR_Y,
    DETECTOR_CB_VAR_BANK,
    DETECTOR_CB_VAR_MAP_IDX,
    DETECTOR_CB_VAR_FLAG,
};

/**
 * Checks if any hidden item is within the visible area arround the player
 * @param event_header the event header of the map to check for items
 * @param cb_idx the callback where to store the results
 * @return if any item could be found
 **/
bool hidden_item_is_within_player_range(map_event_header_t *event_header, u8 cb_idx);

enum {
    ITEM_FINDER_ON_ITEM = 0,
    ITEM_FINDER_NORTH = 3,
    ITEM_FINDER_EAST = 2,
    ITEM_FINDER_SOUTH = 1,
    ITEM_FINDER_WEST = 4,  
};

/**
 * Gets the direction of a hidden item by the values computed by 'hidden_item_is_within_player_range'
 * @param dx the relative horizontal distance to the item
 * @param dy the relative vertical distance to the item
 * @return the direction the item is
 **/
u8 detector_get_hidden_item_direction(s16 dx, s16 dy);

/**
 * Issues an update of the static detector arrow if a flag is set
 * @param flag the flag to wait for
 **/
void overworld_static_detector_issue_update_when_flag_set(u16 flag);

extern const u8 gfx_item_finder_arrow_staticTiles[];

#define ITEM_FINDER_TAG 2000

palette palette_item_finder_arrow;

#endif
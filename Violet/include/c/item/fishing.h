#ifndef H_ITEM_FISHING
#define H_ITEM_FISHING

#include "types.h"
#include "oam.h"

#define FISHING_OAM_TAG_THROW 0xEAAA
#define FISHING_OAM_TAG_STAR 0xEAAB

enum {
    FISHING_STATE_LOCK_PLAYER,
    FISHING_STATE_REACH_BACK,
    FISHING_STATE_INITIALIZE_THROWING,
    FISHING_STATE_WAIT_FOR_A_TO_START_THROWING,
    FISHING_STATE_THROWING,
    FISHING_STATE_THROWN,
    FISHING_STATE_WAIT_THROW_STARS,
    NUM_FISHING_STATES,
};

enum {
    FISHING_STAR_EMPTY,
    FISHING_STAR_1,
    FISHING_STAR_2,
    FISHING_STAR_3,
    FISHING_STAR_FULL,
};

#define FISHING_THROW_PROGRESS_MARGIN 3
#define FISHING_THROW_PROGRESS_TOTAL_WIDTH (64 - (FISHING_THROW_PROGRESS_MARGIN * 2))

typedef struct {
    u8 state;
    u8 backup_overworld_idx;
    u8 oam_idx_throw_bar;
    u8 oam_idx_throw_bar_progress;
    u8 oam_idx_star[3];
    void *sprite_throw_bar_progress;
    u8 throw_bar_value;
    u8 throw_bar_decreasing;
    u16 throw_bar_progress_tile_idx;
} fishing_state_t;


extern u8 ow_script_fishing[];

/**
 * Callback to handle all fishing states.
 * @param self self-reference
 **/
void fishing_big_callback(u8 self);

/**
 * Callback to handle inputs for asking the player if he wants to use a bait.
 * @param self self-reference
 **/
void fishing_big_callback_bait(u8 self);

/**
 * Function that stops the fishing state from waiting and initializes the fishing implementation.
 **/
void fishing_start_after_bait_selection();

#endif
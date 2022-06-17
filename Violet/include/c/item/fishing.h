#ifndef H_ITEM_FISHING
#define H_ITEM_FISHING

#include "types.h"
#include "oam.h"

enum {
    FISHING_OAM_TAG_THROW = 0xEAAA,
    FISHING_OAM_TAG_STAR,
    FISHING_OAM_TAG_CATCHING_FRAME,
    FISHING_OAM_TAG_CATCHING_BAR,
    FISHING_OAM_TAG_CATCHING_FISH,
    FISHING_OAM_TAG_CATCHING_PROGRESS,
};

enum {
    FISHING_STATE_LOCK_PLAYER,
    FISHING_STATE_REACH_BACK,
    FISHING_STATE_INITIALIZE_THROWING,
    FISHING_STATE_WAIT_FOR_A_TO_START_THROWING,
    FISHING_STATE_THROWING,
    FISHING_STATE_THROWN,
    FISHING_STATE_WAIT_THROW_STARS,
    FISHING_STATE_PLAYER_THROW_ANIMATION_START,
    FISHING_STATE_PLAYER_THROW_ANIMATION_WAIT,
    FISHING_STATE_HIDE_THROWING,
    FISHING_STATE_PLAYER_THROW_ANIMATION_WAIT_2,
    FISHING_STATE_INITIALIZE_WAIT_FOR_BITE,
    FISHING_STATE_WAIT_FOR_BITE,
    FISHING_STATE_BITE_EXCLAMATION_MARK,
    FISHING_STATE_BITE_REACT_TO_EXCLAMATION_MARK,
    FISHING_STATE_INTIALIZE_CATCHING,
    FISHING_STATE_CATCHING,
    FISHING_STATE_IT_GOT_AWAY,
    FISHING_STATE_NOT_EVEN_A_NIBBLE,
    FISHING_STATE_WAIT_FRAME_TO_PRINT_TEXT,
    FISHING_STATE_RESET_PLAYER_STATE_AND_PRINT_TEXT,
    FISHING_STATE_PRINT_TEXT,
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

#define FISHING_CATCHING_PROGRESS_BAR_MARGIN 3
#define FISHING_CATCHING_PROGRESS_BAR_TOTAL_HEIGHT (96 - 2 * FISHING_CATCHING_PROGRESS_BAR_MARGIN)

#define FISHING_CATCHING_FRAME_TOTAL_HEIGHT (96 - 3 * 2)
#define FISHING_CATCHING_BAR_HEIGHT 16
#define FISHING_CATCHING_BAR_G FIXED_DIV(INT_TO_FIXED(1), INT_TO_FIXED(4))
#define FISHING_CATCHING_BAR_VELOCITY_LOSS FIXED_DIV(INT_TO_FIXED(3), INT_TO_FIXED(2))
#define FISHING_CATCHING_BAR_MAX_VELOCITY INT_TO_FIXED(8)
#define FISHING_CATCHING_BAR_BOOST FIXED_DIV(INT_TO_FIXED(5), INT_TO_FIXED(3))

#define FISHING_CATCHING_FISH_HEIGHT 8
#define CATCHING_DURATION 512

// For assembling the catching bar gfx
// Y-positions of each line in the gfx from which to assemble the actual bar

#define CATCHING_BAR_Y_TOP 0
#define CATCHING_BAR_Y_DEFAULT 1
#define CATCHING_BAR_Y_TOP_SHINE 2
#define CATCHING_BAR_Y_BOTTOM_SHADOW 3
#define CATCHING_BAR_Y_BOTTOM 4

typedef struct {
    u8 state;
    u8 substate;
    u8 backup_overworld_idx;
    u8 oam_idx_throw_bar;
    u8 oam_idx_throw_bar_progress;
    u8 oam_idx_star[3];
    u8 oam_idx_catching_frame;
    u8 oam_idx_catching_progress_bar;
    u8 oam_idx_catching_bar;
    u8 oam_idx_catching_fish;
    void *sprite_throw_bar_progress;
    void *sprite_catching_progress_bar;
    u8 throw_bar_value;
    u8 throw_bar_decreasing;
    u16 progress_tile_idx;
    u8 num_star_sounds;
    u8 delay;
    FIXED catching_bar_position;
    FIXED catching_bar_velocity;
    FIXED catching_fish_position;
    u16 catching_progress;
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

/**
 * @brief Proceeds the oams and aligns the player oam for fishing
 * 
 * @param player_oam the player oam
 */
void fishing_proceed_and_align_oams(oam_object *player_oam);

/**
 * @brief Checks if the current map can be fished on (i.e. if it has fishing encounters)
 * 
 * @return true 
 * @return false 
 */
bool map_current_has_wild_habitat_rod();

/**
 * @brief Gets the biting animation index by the direction the player is facing in
 * 
 * @param direction the direction
 * @return u8 the animation idx
 */
u8 fishing_get_bite_animation_idx_by_facing_direction(u8 direction);

/**
 * @brief Gets the "no bite" animation index by the direction the player is facing
 * 
 * @param direction the direciton
 * @return u8 the animation index
 */
u8 fishing_get_no_bite_animation_idx_by_facing_direction(u8 direction);

#endif
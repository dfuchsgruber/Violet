#ifndef H_ITEM_FISHING
#define H_ITEM_FISHING

#include "types.h"
#include "oam.h"
#include "constants/wild_pokemon_densities.h"

enum {
    FISHING_OAM_TAG_THROW = 0xEAAA,
    FISHING_OAM_TAG_STAR,
    FISHING_OAM_TAG_CATCHING_FRAME,
    FISHING_OAM_TAG_CATCHING_BAR,
    FISHING_OAM_TAG_CATCHING_FISH,
    FISHING_OAM_TAG_CATCHING_PROGRESS,
};

enum {
    FISHING_OAM_PRIORITY_FISH,
    FISHING_OAM_PRIORITY_STAR,
    FISHING_OAM_PRIORITY_BAR,
    FISHING_OAM_PRIORITY_PROGRESS,
    FISHING_OAM_PRIORITY_FRAME,
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
    FISHING_STATE_DELETE_CATCHING_AND_DO_CONTINUATION_STATE,
    FISHING_STATE_WAIT_CAUGHT_STARS,
    FISHING_STATE_CAUGHT,
    FISHING_STATE_IT_GOT_AWAY,
    FISHING_STATE_NOT_EVEN_A_NIBBLE,
    FISHING_STATE_WAIT_FRAME_TO_PRINT_TEXT,
    FISHING_STATE_RESET_PLAYER_STATE_AND_PRINT_TEXT,
    FISHING_STATE_PRINT_TEXT_AND_RELEASE,
    FISHING_STATE_PRINT_TEXT_AND_START_ENCOUNTER,
    FISHING_STATE_START_ENCOUNTER,
    NUM_FISHING_STATES,
};

enum {
    FISHING_STAR_STATE_PROGRESS = 0,
    FISHING_STAR_STATE_COLLECT,
    FISHING_STAR_STATE_WAIT_COLLECTING,
};

enum {
    FISHING_STAR_EMPTY,
    FISHING_STAR_1,
    FISHING_STAR_2,
    FISHING_STAR_3,
    FISHING_STAR_FULL,
    NUM_FISHING_STAR_ANIMATIONS,
};

enum {
    FISHING_STAR_RS_NONE,
    FISHING_STAR_RS_APPEAR,
    FISHING_STAR_RS_DISAPPEAR,
    FISHING_STAR_RS_COLLECT,
};

enum {
    // FISH_PATTERN_NONE initializes a new random pattern
    FISH_PATTERN_NEW,
    // These patterns initialize coordinates to move to
    FISH_PATTERN_MOVE_SLOW_CLOSE,
    FISH_PATTERN_MOVE_FAST_CLOSE,
    FISH_PATTERN_MOVE_FAST_FAR,
    FISH_PATTERN_OSCILLATE,
    // These patterns actually move to coordinates
    FISH_PATTERN_MOVE_TO_TARGET_POSITION,
    FISH_PATTERN_DO_OSCILLATION,
    NUM_FISH_PATTERNS,
};

#define FISH_PATTERN_NUM_PROPOSALS_CLOSE 4
#define FISH_PATTERN_NUM_PROPOSALS_FAR 2

enum {
    ROD_TYPE_NONE = -1,
    ROD_TYPE_OLD_ROD = 0,
    ROD_TYPE_GOOD_ROD,
    ROD_TYPE_SUPER_ROD,
};

#define FISHING_THROW_PROGRESS_MARGIN 3
#define FISHING_THROW_PROGRESS_TOTAL_WIDTH (64 - (FISHING_THROW_PROGRESS_MARGIN * 2))

#define FISHING_CATCHING_PROGRESS_BAR_MARGIN 3
#define FISHING_CATCHING_PROGRESS_BAR_TOTAL_HEIGHT (96 - 2 * FISHING_CATCHING_PROGRESS_BAR_MARGIN)

#define FISHING_CATCHING_FRAME_TOTAL_HEIGHT (96 - 3 * 2)
#define FISHING_CATCHING_BAR_HEIGHT 16
#define FISHING_CATCHING_STAR_HEIGHT 12
#define FISHING_CATCHING_BAR_G FIXED_DIV(INT_TO_FIXED(1), INT_TO_FIXED(5))
#define FISHING_CATCHING_BAR_VELOCITY_LOSS FIXED_DIV(INT_TO_FIXED(5), INT_TO_FIXED(2))
#define FISHING_CATCHING_BAR_MAX_VELOCITY FIXED_DIV(INT_TO_FIXED(7), INT_TO_FIXED(2))
#define FISHING_CATCHING_BAR_BOOST FIXED_DIV(INT_TO_FIXED(5), INT_TO_FIXED(3))

#define FISHING_CATCHING_FISH_HEIGHT 8
#define CATCHING_DURATION 512
#define CATCHING_STAR_DURATION 64
#define CATCHING_MAX_NUM_STARS 3
#define CATCHING_NEW_STAR_MAX_ATTEMPTS 100

#define MAX_FISH_RATING 8

// For assembling the catching bar gfx
// Y-positions of each line in the gfx from which to assemble the actual bar

enum {
    CATCHING_BAR_Y_TOP,
    CATCHING_BAR_Y_DEFAULT,
    CATCHING_BAR_Y_TOP_SHINE,
    CATCHING_BAR_Y_BOTTOM_SHADOW,
    CATCHING_BAR_Y_BOTTOM,
    NUM_CATCHING_BAR_COMPONENTS,
};

typedef struct {
    u8 state;
    u8 substate;
    u8 continuation_state;
    u8 star_state;
    u8 backup_overworld_idx;
    u8 rod_type;
    u8 oam_idx_throw_bar;
    u8 oam_idx_throw_bar_progress;
    u8 oam_idx_star[3];
    u8 oam_idx_catching_frame;
    u8 oam_idx_catching_progress_bar;
    u8 oam_idx_catching_bar;
    u8 oam_idx_catching_fish;
    u8 oam_idx_catching_star;
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
    FIXED catching_star_position;
    u8 catching_star_is_present : 1;
    u8 catching_succesfull : 1;
    u16 catching_progress;
    u16 star_progress;
    u8 num_stars_collected;
    u8 fish_rating;
    u16 bait;
    u8 fish_pattern;
    u8 fish_pattern_state;
    FIXED fish_origin_position;
    FIXED fish_target_position;
    u16 fish_t;
    u16 fish_pattern_duration;
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

/**
 * @brief Checks if an item is a rod
 * 
 * @param item_idx the item to check
 * @return true 
 * @return false 
 */
bool item_is_rod(u16 item_idx);

/**
 * @brief Gets the bait equipped to a rod
 * 
 * @param item_idx the rod
 * @return u16 the bait or ITEM_NONE if no bait is equipped
 */
u16 item_rod_get_equipped_bait(u16 item_idx);

/**
 * @brief Sets the bait equipped to a rod
 * 
 * @param rod_item_idx the rod to equip to
 * @param bait_item_idx the bait to equip
 */
void item_rod_equip_bait(u16 rod_item_idx, u16 bait_item_idx);

/**
 * @brief Uses up a bait on a rod
 * 
 * @param rod_item_idx The rod item to use the bait of
 * @return u16 The bait that was used or ITEM_NONE if none was equipped to the rod
 */
u16 item_rod_use_bait(u16 rod_item_idx);

/**
 * @brief Gets the rod associated with an item
 * 
 * @param item_idx the item idx
 * @return int the associated rod or ROD_TYPE_NONE if no rod matches
 */
int item_idx_to_rod_idx(u16 item_idx);

/**
 * @brief Gets the item associated with a rod
 * 
 * @param rod_idx the rod type
 * @return u16 the item or ITEM_NONE if the rod idx is invalid
 */
u16 rod_idx_to_item_idx(int rod_idx);

#endif
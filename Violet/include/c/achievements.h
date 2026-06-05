#ifndef H_ACHIVEMENTS
#define H_ACHIVEMENTS

#include "flags.h"
#include "list_menu.h"
#include "types.h"
#include "constants/achievements.h"

enum {
    ACHIEVEMENT_LEVEL_BRONZE,
    ACHIEVEMENT_LEVEL_SILVER,
    ACHIEVEMENT_LEVEL_GOLD,
    ACHIEVEMENT_LEVEL_PLATINUM,
};



typedef struct {
    u16 flag;
    const u8 *script;
    const u8 *description;
} achievement_reward_t;

#define ACHIEVEMENT_HAS_REWARD(achievement) ((achievement)->reward.flag != 0)
#define ACHIEVEMENT_REWARD_TAKEN(achievement) (checkflag((achievement)->reward.flag))

typedef struct {
    const u8 *description;
    bool (*is_achieved)(void);
    u16 max_progress;
    u8 level;
    u16 (*get_progress)(void);
    u16 flag_achieved;
    achievement_reward_t reward;
} achievement_t;

typedef struct {
    const u8 *name;
    const achievement_t *achievements;
    bool (*is_unlocked)(void);
    u8 num_achievements;
} achievement_group_t;

typedef struct {
    u8 cursor : 7;
    u8 return_to_achievements : 1;
} achievements_ui_cursor_t;

#define REWARDS_UI_NUM_ITEMS_SHOWN 6

typedef struct {
    u16 progress;
    u8 tail_idx;
    u8 last_achieved_idx;
    u8 first_claimable_reward_idx;
    u8 unlocked : 1;
    u8 completed : 1;
    u8 tail_reward_visible : 1;
} achievement_group_ui_cache_t;

typedef struct {
    u8 initialization_state;
    u8 opened_from_script : 1;
    u8 claim_note_visible : 1;
    u8 process_input_callback_idx;

    u8 list_menu_callback_idx;
    u8 scroll_indicator_callback_idx;
    const u8 *script_to_execute;
    u16 list_menu_scroll_offset;
    u16 list_menu_row;
    list_menu_template list_menu_template;
    list_menu_item list_menu_items[NUM_ACHIEVEMENT_GROUPS];

    u8 achievements[NUM_ACHIEVEMENT_GROUPS]; // Sorted
    achievement_group_ui_cache_t achievement_cache[NUM_ACHIEVEMENT_GROUPS];
    u8 achievements_item_strings[NUM_ACHIEVEMENT_GROUPS][64];

    u8 oam_idxs[REWARDS_UI_NUM_ITEMS_SHOWN];
    u8 oam_idxs_progress[REWARDS_UI_NUM_ITEMS_SHOWN];

} achievements_ui_state_t;

enum {
    NUM_POKEDEX_ACHIEVEMENTS = 6,
    NUM_POKERADAR_ACHIEVEMENTS = 4,
};

extern const achievement_t achievements_pokedex[NUM_POKEDEX_ACHIEVEMENTS];
extern const achievement_t achievements_pokeradar[NUM_POKERADAR_ACHIEVEMENTS];

extern const achievement_group_t achievement_groups[NUM_ACHIEVEMENT_GROUPS];
extern EWRAM achievements_ui_cursor_t achievements_ui_cursor;

/**
 * Initializes the pokepad from the start menu
 **/
bool start_menu_achievements_initialize();

/**
 * Initializes the achievements UI from an overworld script.
 */
void achievements_ui_initialize_from_overworld(void);

/**
 * Gets the tail of an achievement group, i.e. the first non-achieved achievement, or the last achievement.
 * @param group The achievement group
 * @return The index of the tail achievement in the group
 */
u8 achievement_group_get_tail_idx(const achievement_group_t *group);
/**
 * Main function to process input in the achievements menu, should be set as a big callback when the menu is entered
 */
void achievements_process_input(u8 self);


/**
 * Gets the group and achievement idx for an issued unlocked message, if any. An issued unlocked message is when an achievement is achieved but its reward not claimed, and the game has already issued a message about it being unlocked. This is used to know when to issue an unlock message in the overworld, and for which achievement.
    * @param group_idx_dst Output pointer for the achievement group idx of the issued message, only valid if the function returns true
    * @param achievement_idx_dst Output pointer for the achievement idx of the issued message, only valid if the function returns true
    * @return True if there is an issued unlocked message, false otherwise
 */
bool achievements_get_issued_unlocked_message_group_idx(u8 *group_idx_dst, u8 *achievement_idx_dst);

/**
 * Computes, for all achievement groups, if any reward is claimable and sets the flag for it to be issued in the overworld.
 */
void achievements_compute_unlocked_message_issued();

extern LZ77COMPRESSED gfx_achievements_ui_bgTiles;
extern LZ77COMPRESSED gfx_achievements_ui_bgMap;
extern LZ77COMPRESSED gfx_achievements_ui_bgPal;

extern LZ77COMPRESSED gfx_achievements_level_iconsTiles;
extern LZ77COMPRESSED gfx_achievements_level_iconsPal;
extern LZ77COMPRESSED gfx_achievements_progress_barTiles;
extern LZ77COMPRESSED gfx_achievements_progress_barPal;

extern u8 ow_script_achievement_unlocked[];

#endif

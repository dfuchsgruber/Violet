#ifndef H_ACHIVEMENTS
#define H_ACHIVEMENTS

#include "list_menu.h"
#include "types.h"
#include "flags.h"

enum {
    ACHIEVEMENT_LEVEL_BRONZE,
    ACHIEVEMENT_LEVEL_SILVER,
    ACHIEVEMENT_LEVEL_GOLD,
    ACHIEVEMENT_LEVEL_PLATINUM,
};

enum {
    ACHIEVEMENT_POKEDEX = 0,
    ACHIEVEMENT_TEST_2,
    ACHIEVEMENT_TEST_3,
    ACHIEVEMENT_TEST_4,
    ACHIEVEMENT_TEST_5,
    ACHIEVEMENT_TEST_6,
    ACHIEVEMENT_TEST_7,
    NUM_ACHIEVEMENT_GROUPS,
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


#define REWARDS_UI_NUM_ITEMS_SHOWN 6

typedef struct {
    u8 initialization_state;
    u8 process_input_callback_idx;

    u8 list_menu_callback_idx;
    u16 list_menu_scroll_offset;
    u16 list_menu_row;
    list_menu_template list_menu_template;
    list_menu_item list_menu_items[NUM_ACHIEVEMENT_GROUPS];

    u8 achievements[NUM_ACHIEVEMENT_GROUPS]; // Sorted
    u8 achievements_item_strings[NUM_ACHIEVEMENT_GROUPS][64];

    u8 oam_idxs[REWARDS_UI_NUM_ITEMS_SHOWN];

} achievements_ui_state_t;

extern const achievement_t achievements_pokedex[5];

extern const achievement_group_t achievement_groups[NUM_ACHIEVEMENT_GROUPS];

/**
 * Initializes the pokepad from the start menu
 **/
bool start_menu_achievements_initialize();

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

extern LZ77COMPRESSED gfx_achievements_ui_bgTiles;
extern LZ77COMPRESSED gfx_achievements_ui_bgMap;
extern LZ77COMPRESSED gfx_achievements_ui_bgPal;

extern LZ77COMPRESSED gfx_achievements_ui_level_iconsTiles;
extern LZ77COMPRESSED gfx_achievements_ui_level_iconsPal;

#endif
#ifndef H_ACHIVEMENTS
#define H_ACHIVEMENTS

#include "types.h"

enum {
    ACHIVEMENT_LEVEL_BRONZE,
    ACHIVEMENT_LEVEL_SILVER,
    ACHIVEMENT_LEVEL_GOLD,
    ACHIVEMENT_LEVEL_PLATINUM,
};

typedef struct {
    u16 flag;
    const u8 *script;
    const u8 *description;
} achievement_reward_t;

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

extern const achievement_t achievements_pokedex[5];

#endif
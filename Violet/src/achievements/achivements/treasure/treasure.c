#include "achievements.h"
#include "language.h"
#include "constants/flags.h"
#include "flags.h"
#include "pokepad/treasure_map.h"

extern const u8 ow_script_achievement_treasure_1_reward[];
extern const u8 ow_script_achievement_treasure_5_reward[];
extern const u8 ow_script_achievement_treasure_all_reward[];

u16 achievement_treasure_get_progress() {
    u16 num = 0;
    for (int i = 0; i < NUM_TREASURE_MAPS; i++) {
        if (checkflag((u16)(FLAG_TREASURE_BASE + i))) {
            num++;
        }
    }
    return num;
}

bool treasure_1_is_achieved(void) {return achievement_treasure_get_progress() >= 1;}
bool treasure_5_is_achieved(void) {return achievement_treasure_get_progress() >= 5;}
bool treasure_all_is_achieved(void) {return achievement_treasure_get_progress() >= NUM_TREASURE_MAPS;}

const achievement_t achievements_treasure[NUM_TREASURE_ACHIEVEMENTS] = {
    {
        .description = (const u8[]) LANGDEP(
            PSTRING("Finde 1 verborgenen Schatz!"), 
            PSTRING("Find 1 hidden treasure!")
        ),
        .is_achieved = treasure_1_is_achieved,
        .max_progress = 1,
        .get_progress = achievement_treasure_get_progress,
        .flag_achieved = FLAG_ACHIEVEMENT_TREASURE_1_ACHIEVED,
        .level = ACHIEVEMENT_LEVEL_BRONZE,
        .reward = {
            .flag = FLAG_ACHIEVEMENT_TREASURE_REWARD_1,
            .script = ow_script_achievement_treasure_1_reward,
            .description = (const u8[]) LANGDEP(
                PSTRING("1×Goldapfel."), 
                PSTRING("1×Golden Apple.")
            ),
        }
    },
    {
        .description = (const u8[]) LANGDEP(
            PSTRING("Finde 5 verborgene Schätze."),
            PSTRING("Find 5 hidden treasures.")
        ),
        .is_achieved = treasure_5_is_achieved,
        .max_progress = 5,
        .get_progress = achievement_treasure_get_progress,
        .flag_achieved = FLAG_ACHIEVEMENT_TREASURE_5_ACHIEVED,
        .level = ACHIEVEMENT_LEVEL_SILVER,
        .reward = {
            .flag = FLAG_ACHIEVEMENT_TREASURE_REWARD_5,
            .script = ow_script_achievement_treasure_5_reward,
            .description = (const u8[]) LANGDEP(
                PSTRING("1×Ap-Top."), 
                PSTRING("1×PP Max.")
            ),
        }
    },
    {
        .description = (const u8[]) LANGDEP(
            PSTRING("Finde alle verborgenen Schätze."),
            PSTRING("Find all hidden treasures.")
        ),
        .is_achieved = treasure_all_is_achieved,
        .max_progress = NUM_TREASURE_MAPS,
        .get_progress = achievement_treasure_get_progress,
        .flag_achieved = FLAG_ACHIEVEMENT_TREASURE_ALL_ACHIEVED,
        .level = ACHIEVEMENT_LEVEL_GOLD,
        .reward = {
            .flag = FLAG_ACHIEVEMENT_TREASURE_REWARD_ALL,
            .script = ow_script_achievement_treasure_all_reward,
            .description = (const u8[]) LANGDEP(
                PSTRING("TM59."), 
                PSTRING("TM59.")
            ),
        }
    },
};
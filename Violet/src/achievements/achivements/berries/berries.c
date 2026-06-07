#include "achievements.h"
#include "language.h"
#include "constants/flags.h"
#include "constants/sav_keys.h"
#include "save.h"
#include "vars.h"

extern u8 ow_script_achievement_berries_reward_1[];
extern u8 ow_script_achievement_berries_reward_20[];
extern u8 ow_script_achievement_berries_reward_50[];
extern u8 ow_script_achievement_berries_reward_100[];

u16 berries_get_progress() { return *var_access(VAR_REPLANTED_BERRIES_HARVESTED); }
bool berries_replant_1_is_achieved(void) { return *var_access(VAR_REPLANTED_BERRIES_HARVESTED) >= 1; }
bool berries_replant_20_is_achieved(void) { return *var_access(VAR_REPLANTED_BERRIES_HARVESTED) >= 20; }
bool berries_replant_50_is_achieved(void) { return *var_access(VAR_REPLANTED_BERRIES_HARVESTED) >= 50; }
bool berries_replant_100_is_achieved(void) { return *var_access(VAR_REPLANTED_BERRIES_HARVESTED) >= 100; }

const achievement_t achievements_berries[NUM_BERRIES_ACHIEVEMENTS] = {
    {
        .description = (const u8[]) LANGDEP(
            PSTRING("Ernte 1 neu angefplanzte Beere."), 
            PSTRING("Pick a berry that was replanted.")
        ),
        .is_achieved = berries_replant_1_is_achieved,
        .max_progress = 1,
        .get_progress = berries_get_progress,
        .flag_achieved = FLAG_BERRIES_ACHIEVEMENT_PICK_1_ACHIEVED,
        .level = ACHIEVEMENT_LEVEL_BRONZE,
        .reward = {
            .flag = FLAG_BERRIES_ACHIEVEMENT_PICK_1_REWARD_RECEIVED,
            .script = ow_script_achievement_berries_reward_1, // No script reward for this achievement
            .description = (const u8[]) LANGDEP(
                PSTRING("5×?-Samen"), 
                PSTRING("5×?-Seed")
            ),
        }, 
    },
    {
        .description = (const u8[]) LANGDEP(
            PSTRING("Ernte 20 neu angefplanzte Beeren."), 
            PSTRING("Pick 20 berries that were replanted.")
        ),
        .is_achieved = berries_replant_20_is_achieved,
        .max_progress = 20,
        .get_progress = berries_get_progress,
        .flag_achieved = FLAG_BERRIES_ACHIEVEMENT_PICK_20_ACHIEVED,
        .level = ACHIEVEMENT_LEVEL_SILVER,
        .reward = {
            .flag = FLAG_BERRIES_ACHIEVEMENT_PICK_20_REWARD_RECEIVED,
            .script = ow_script_achievement_berries_reward_20, // No script reward for this achievement
            .description = (const u8[]) LANGDEP(
                PSTRING("Neu angepflanzte\nBeeren werfen\n50% mehr\nErtrag ab."), 
                PSTRING("Replanted\nberries yield\n50% more.")
            ),
        }, 
    },
    {
        .description = (const u8[]) LANGDEP(
            PSTRING("Ernte 50 neu angefplanzte Beeren."), 
            PSTRING("Pick 50 berries that were replanted.")
        ),
        .is_achieved = berries_replant_50_is_achieved,
        .max_progress = 50,
        .get_progress = berries_get_progress,
        .flag_achieved = FLAG_BERRIES_ACHIEVEMENT_PICK_50_ACHIEVED,
        .level = ACHIEVEMENT_LEVEL_GOLD,
        .reward = {
            .flag = FLAG_BERRIES_ACHIEVEMENT_PICK_50_REWARD_RECEIVED,
            .script = ow_script_achievement_berries_reward_50, // No script reward for this achievement
            .description = (const u8[]) LANGDEP(
                PSTRING("1×Prunusbeere"), 
                PSTRING("1×Lum Berry")
            ),
        },
    },
    {
        .description = (const u8[]) LANGDEP(
            PSTRING("Ernte 100 neu angefplanzte Beeren."), 
            PSTRING("Pick 100 berries that were replanted.")
        ),
        .is_achieved = berries_replant_100_is_achieved,
        .max_progress = 100,
        .get_progress = berries_get_progress,
        .flag_achieved = FLAG_BERRIES_ACHIEVEMENT_PICK_100_ACHIEVED,
        .level = ACHIEVEMENT_LEVEL_GOLD,
        .reward = {
            .flag = FLAG_BERRIES_ACHIEVEMENT_PICK_100_REWARD_RECEIVED,
            .script = ow_script_achievement_berries_reward_100, // No script reward for this achievement
            .description = (const u8[]) LANGDEP(
                PSTRING("1×Antiker Samen"), 
                PSTRING("1×Ancient Seed")
            ),
        },
    } 
};
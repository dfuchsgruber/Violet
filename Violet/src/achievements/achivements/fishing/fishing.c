#include "achievements.h"
#include "language.h"
#include "pokepad/pokedex/operator.h"
#include "pokepad/pokedex/count.h"
#include "constants/flags.h"
#include "save.h"
#include "constants/sav_keys.h"

extern const u8 ow_script_achievement_fishing_5_reward[];
extern const u8 ow_script_achievement_fishing_20_reward[];
extern const u8 ow_script_achievement_fishing_50_reward[];
extern const u8 ow_script_achievement_fishing_100_reward[];

u16 achievement_fishing_get_progress() { return (u16)save_get_key(SAV_KEY_FISHING_ENCOUNTERS); }
bool achievement_fishing_5_is_achieved() { return save_get_key(SAV_KEY_FISHING_ENCOUNTERS) >= 5; }
bool achievement_fishing_20_is_achieved() { return save_get_key(SAV_KEY_FISHING_ENCOUNTERS) >= 20; }
bool achievement_fishing_50_is_achieved() { return save_get_key(SAV_KEY_FISHING_ENCOUNTERS) >= 50; }
bool achievement_fishing_100_is_achieved() { return save_get_key(SAV_KEY_FISHING_ENCOUNTERS) >= 100; }

const achievement_t achievements_fishing[NUM_FISHING_ACHIEVEMENTS] = {
    {
        .description = (const u8[]) LANGDEP(
            PSTRING("Fange 5 Pokémon mit einer Angel!"), 
            PSTRING("Catch 5 Pokémon with a fishing rod!")
        ),
        .is_achieved = achievement_fishing_5_is_achieved,
        .max_progress = 5,
        .get_progress = achievement_fishing_get_progress,
        .flag_achieved = FLAG_FISHING_ACHIEVEMENT_5_ACHIEVED,
        .level = ACHIEVEMENT_LEVEL_BRONZE,
        .reward = {
            .flag = FLAG_FISHING_REWARD_5,
            .script = ow_script_achievement_fishing_5_reward,
            .description = (const u8[]) LANGDEP(
                PSTRING("Pokémon beißen\nöfter an."), 
                PSTRING("Pokémon bite\nmore often.")
            ),
        }
    },
    {
        .description = (const u8[]) LANGDEP(
            PSTRING("Fange 20 Pokémon mit der Angel!"), 
            PSTRING("Catch 20 Pokémon with the fishing rod!")
        ),
        .is_achieved = achievement_fishing_20_is_achieved,
        .max_progress = 20,
        .get_progress = achievement_fishing_get_progress,
        .flag_achieved = FLAG_FISHING_ACHIEVEMENT_20_ACHIEVED,
        .level = ACHIEVEMENT_LEVEL_SILVER,
        .reward = {
            .flag = FLAG_FISHING_REWARD_20,
            .script = ow_script_achievement_fishing_20_reward,
            .description = (const u8[]) LANGDEP(
                PSTRING("Pokémon sind\nschneller am\nHaken."), 
                PSTRING("Pokémon get\non the\nhook faster.")
            ),
        }
    },
    {
        .description = (const u8[]) LANGDEP(
            PSTRING("Fange 50 Pokémon mit der Angel!"), 
            PSTRING("Catch 50 Pokémon with the fishing rod!")
        ),
        .is_achieved = achievement_fishing_50_is_achieved,
        .max_progress = 50,
        .get_progress = achievement_fishing_get_progress,
        .flag_achieved = FLAG_FISHING_ACHIEVEMENT_50_ACHIEVED,
        .level = ACHIEVEMENT_LEVEL_GOLD,
        .reward = {
            .flag = FLAG_FISHING_REWARD_50,
            .script = ow_script_achievement_fishing_50_reward,
            .description = (const u8[]) LANGDEP(
                PSTRING("5×Lotusköder"), 
                PSTRING("5×Lotus Bait") 
            ),
        }
    },
    {
        .description = (const u8[]) LANGDEP(
            PSTRING("Fange 100 Pokémon mit der Angel!"), 
            PSTRING("Catch 100 Pokémon with the fishing rod!")
        ),
        .is_achieved = achievement_fishing_100_is_achieved,
        .max_progress = 100,
        .get_progress = achievement_fishing_get_progress,
        .flag_achieved = FLAG_FISHING_ACHIEVEMENT_100_ACHIEVED,
        .level = ACHIEVEMENT_LEVEL_PLATINUM,
        .reward = {
            .flag = FLAG_FISHING_REWARD_100,
            .script = ow_script_achievement_fishing_100_reward,
            .description = (const u8[]) LANGDEP(
                PSTRING("1×Leuchtköder"), 
                PSTRING("1×Shiny Bait") 
            ),
        }
    },
};
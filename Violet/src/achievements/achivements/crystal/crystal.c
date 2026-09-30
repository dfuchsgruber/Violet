#include "achievements.h"
#include "language.h"
#include "pokepad/pokedex/operator.h"
#include "pokepad/pokedex/count.h"
#include "constants/flags.h"
#include "constants/pokemon_types.h"

extern const u8 ow_script_achievement_crystal_1_reward[];
extern const u8 ow_script_achievement_crystal_5_reward[];
extern const u8 ow_script_achievement_crystal_all_reward[];

u16 achievement_crystal_get_progress() {
    u16 num = 0;
    for (int i = 0; i < NUM_TYPES; i++) {
        if (checkflag((u16)(FLAG_TUTOR_CRYSTAL_BASE + i))) {
            num++;
        }
    }
    return num;
}
bool crystal_1_is_achieved(void) {return achievement_crystal_get_progress() >= 1;}
bool crystal_5_is_achieved(void) {return achievement_crystal_get_progress() >= 5;}
bool crystal_all_is_achieved(void) {return achievement_crystal_get_progress() >= NUM_TYPES;}

const achievement_t achievements_crystal[NUM_CRYSTAL_ACHIEVEMENTS] = {
    {
        .description = (const u8[]) LANGDEP(
            PSTRING("Finde 1 Antiken Kristall!"), 
            PSTRING("Find 1 Ancient Crystal!")
        ),
        .is_achieved = crystal_1_is_achieved,
        .max_progress = 1,
        .get_progress = achievement_crystal_get_progress,
        .flag_achieved = FLAG_ACHIEVEMENT_CRYSTAL_1_ACHIEVED,
        .level = ACHIEVEMENT_LEVEL_BRONZE,
        .reward = {
            .flag = FLAG_ACHIEVEMENT_CRYSTAL_REWARD_1,
            .script = ow_script_achievement_crystal_1_reward,
            .description = (const u8[]) LANGDEP(
                PSTRING("1×Energiekristall."), 
                PSTRING("1×Energy Crystal.")
            ),
        }
    },
    {
        .description = (const u8[]) LANGDEP(
            PSTRING("Finde 5 Antike Kristalle."),
            PSTRING("Find 5 Ancient Crystals.")
        ),
        .is_achieved = crystal_5_is_achieved,
        .max_progress = 5,
        .get_progress = achievement_crystal_get_progress,
        .flag_achieved = FLAG_ACHIEVEMENT_CRYSTAL_5_ACHIEVED,
        .level = ACHIEVEMENT_LEVEL_SILVER,
        .reward = {
            .flag = FLAG_ACHIEVEMENT_CRYSTAL_REWARD_5,
            .script = ow_script_achievement_crystal_5_reward,
            .description = (const u8[]) LANGDEP(
                PSTRING("1×Sonderbonbon."), 
                PSTRING("1×Rare Candy.")
            ),
        }
    },
    {
        .description = (const u8[]) LANGDEP(
            PSTRING("Finde alle Antiken Kristalle."),
            PSTRING("Find all Ancient Crystals.")
        ),
        .is_achieved = crystal_all_is_achieved,
        .max_progress = NUM_TYPES,
        .get_progress = achievement_crystal_get_progress,
        .flag_achieved = FLAG_ACHIEVEMENT_CRYSTAL_ALL_ACHIEVED,
        .level = ACHIEVEMENT_LEVEL_GOLD,
        .reward = {
            .flag = FLAG_ACHIEVEMENT_CRYSTAL_REWARD_ALL,
            .script = ow_script_achievement_crystal_all_reward,
            .description = (const u8[]) LANGDEP(
                PSTRING("3×Energiekristall."), 
                PSTRING("3×Energy Crystals.")
            ),
        }
    },
};
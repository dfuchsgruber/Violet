#include "achievements.h"
#include "language.h"
#include "constants/flags.h"
#include "vars.h"

extern const u8 ow_script_achievement_pokeradar_catch_5_reward[];
extern const u8 ow_script_achievement_pokeradar_catch_20_reward[];
extern const u8 ow_script_achievement_pokeradar_catch_50_reward[];
extern const u8 ow_script_achievement_pokeradar_catch_100_reward[];


u16 achievement_pokeradar_get_progress() {return *var_access(POKERADAR_ENCOUNTER_COUNT);}
bool pokeradar_5_is_achieved(void) {return achievement_pokeradar_get_progress() >= 5;}
bool pokeradar_20_is_achieved(void) {return achievement_pokeradar_get_progress() >= 20;}
bool pokeradar_50_is_achieved(void) {return achievement_pokeradar_get_progress() >= 50;}
bool pokeradar_100_is_achieved(void) {return achievement_pokeradar_get_progress() >= 100;}

// todo
const achievement_t achievements_pokeradar[NUM_POKERADAR_ACHIEVEMENTS] = {
    {
        .description = (const u8[]) LANGDEP(
            PSTRING("Finde 5 Pokémon mit dem Pokéradar."), 
            PSTRING("Find 5 Pokémon with the Pokéradar!")
        ),
        .is_achieved = pokeradar_5_is_achieved,
        .max_progress = 5,
        .get_progress = achievement_pokeradar_get_progress,
        .flag_achieved = FLAG_POKERADAR_ACHIVEMENT_ENCOUNTER_5_ACHIEVED,
        .level = ACHIEVEMENT_LEVEL_BRONZE,
        .reward = {
            .flag = FLAG_POKERADAR_REWARD_5,
            .script = ow_script_achievement_pokeradar_catch_5_reward,
            .description = (const u8[]) LANGDEP(
                PSTRING("1×Sonderbonbon"), 
                PSTRING("1×Rare Candy")
            ),
        }
    },
    {
        .description = (const u8[]) LANGDEP(
            PSTRING("Finde 20 Pokémon mit dem Pokéradar."), 
            PSTRING("Find 20 Pokémon with the Pokéradar!")
        ),
        .is_achieved = pokeradar_20_is_achieved,
        .max_progress = 20,
        .get_progress = achievement_pokeradar_get_progress,
        .flag_achieved = FLAG_POKERADAR_ACHIVEMENT_ENCOUNTER_20_ACHIEVED,
        .level = ACHIEVEMENT_LEVEL_SILVER,
        .reward = {
            .flag = FLAG_POKERADAR_POKEMON_DONT_FLEE,
            .script = ow_script_achievement_pokeradar_catch_20_reward,
            .description = (const u8[]) LANGDEP(
                PSTRING("Pokéradar\nPokémon\nfliehen nicht."), 
                PSTRING("Pokéradar\nPokémon\ndon't flee.")
            ),
        }
    },
    {
        .description = (const u8[]) LANGDEP(
            PSTRING("Finde 50 Pokémon mit dem Pokéradar."), 
            PSTRING("Find 50 Pokémon with the Pokéradar!")
        ),
        .is_achieved = pokeradar_50_is_achieved,
        .max_progress = 50,
        .get_progress = achievement_pokeradar_get_progress,
        .flag_achieved = FLAG_POKERADAR_ACHIVEMENT_ENCOUNTER_50_ACHIEVED,
        .level = ACHIEVEMENT_LEVEL_GOLD,
        .reward = {
            .flag = FLAG_POKERADAR_POKEMON_DONT_SPOT_PLAYER,
            .script = ow_script_achievement_pokeradar_catch_50_reward,
            .description = (const u8[]) LANGDEP(
                PSTRING("Pokéradar\nPokémon\nentdecken\nSpieler nicht\nmehr."), 
                PSTRING("Pokéradar\nPokémon\nno longer\nspot the\nplayer.")
            ),
        }
    },
    {
        .description = (const u8[]) LANGDEP(
            PSTRING("Finde 100 Pokémon mit dem Pokéradar."), 
            PSTRING("Find 100 Pokémon with the Pokéradar!")
        ),
        .is_achieved = pokeradar_100_is_achieved,
        .max_progress = 100,
        .get_progress = achievement_pokeradar_get_progress,
        .flag_achieved = FLAG_POKERADAR_ACHIVEMENT_ENCOUNTER_100_ACHIEVED,
        .level = ACHIEVEMENT_LEVEL_PLATINUM,
        .reward = {
            .flag = FLAG_POKERADAR_REWARD_100,
            .script = ow_script_achievement_pokeradar_catch_100_reward,
            .description = (const u8[]) LANGDEP(
                PSTRING("3×Goldbonbon"), 
                PSTRING("3×Gold Candy")
            ),
        }
    }

};
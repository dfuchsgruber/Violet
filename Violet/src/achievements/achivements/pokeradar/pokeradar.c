#include "achievements.h"
#include "language.h"
#include "pokepad/pokedex/operator.h"
#include "pokepad/pokedex/count.h"
#include "constants/flags.h"
#include "vars.h"

extern const u8 ow_script_achievement_pokedex_catch_5_reward[];


u16 achievement_pokeradar_get_progress() {return *var_access(POKERADAR_ENCOUNTER_COUNT);}
bool pokeradar_5_is_achieved(void) {return achievement_pokeradar_get_progress() >= 5;}

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
        .flag_achieved = FLAG_POKEDEX_ACHIVEMENT_CATCH_5_ACHIEVED,
        .level = ACHIEVEMENT_LEVEL_BRONZE,
        .reward = {
            .flag = FLAG_CATCHING_GIVES_EXP,
            .script = ow_script_achievement_pokedex_catch_5_reward,
            .description = (const u8[]) LANGDEP(
                PSTRING("Fangen gibt Erfahrungspunkte"), 
                PSTRING("Catching gives experience points")
            ),
        }
    },
};
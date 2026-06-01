#include "achievements.h"
#include "language.h"
#include "pokepad/pokedex/operator.h"
#include "pokepad/pokedex/count.h"
#include "constants/flags.h"

extern const u8 ow_script_achievement_pokedex_catch_5_reward[];
extern const u8 ow_script_achievement_pokedex_catch_20_reward[];
extern const u8 ow_script_achievement_pokedex_catch_50_reward[];
extern const u8 ow_script_achievement_pokedex_catch_150_reward[];

u16 pokedex_get_progress() {return POKEDEX_NUMBER_CAUGHT;}
bool pokedex_catch_5_is_achieved(void) {return POKEDEX_NUMBER_CAUGHT >= 5;}
bool pokedex_all_caught_is_achieved(void) {return POKEDEX_NUMBER_CAUGHT >= POKEDEX_CNT;}
bool pokedex_catch_20_is_achieved(void) {return POKEDEX_NUMBER_CAUGHT >= 20;}
bool pokedex_catch_50_is_achieved(void) {return POKEDEX_NUMBER_CAUGHT >= 50;}
bool pokedex_catch_150_is_achieved(void) {return POKEDEX_NUMBER_CAUGHT >= 150;}

const achievement_t achievements_pokedex[5] = {
    {
        .description = (const u8[]) LANGDEP(
            PSTRING("Registriere 5 Pokémon im Pokédex!"), 
            PSTRING("Register 5 Pokémon in the Pokédex!")
        ),
        .is_achieved = pokedex_catch_5_is_achieved,
        .max_progress = 5,
        .get_progress = pokedex_get_progress,
        .flag_achieved = FLAG_CATCHING_GIVES_EXP,
        .level = ACHIEVEMENT_LEVEL_BRONZE,
        .reward = {
            .flag = FLAG_POKEDEX_ACHIVEMENT_CATCH_5_REWARD,
            .script = ow_script_achievement_pokedex_catch_5_reward,
            .description = (const u8[]) LANGDEP(
                PSTRING("Fangen gibt Erfahrungspunkte"), 
                PSTRING("Catching gives experience points")
            ),
        }
    },
    {
        .description = (const u8[]) LANGDEP(
            PSTRING("Registriere 20 Pokémon im Pokédex!"), 
            PSTRING("Register 20 Pokémon in the Pokédex!")
        ),
        .is_achieved = pokedex_catch_20_is_achieved,
        .max_progress = 20,
        .get_progress = pokedex_get_progress,
        .flag_achieved = POKERADAR,
        .level = ACHIEVEMENT_LEVEL_BRONZE,
        .reward = {
            .flag = FLAG_POKEDEX_ACHIVEMENT_CATCH_20_REWARD,
            .script = ow_script_achievement_pokedex_catch_20_reward,
            .description = (const u8[]) LANGDEP(
                PSTRING("Pokéradar-App auf dem Poképad"), 
                PSTRING("Pokéradar app on the Poképad")
            ),
        }
    },
    {
        .description = (const u8[]) LANGDEP(
            PSTRING("Registriere 50 Pokémon im Pokédex!"), 
            PSTRING("Register 50 Pokémon in the Pokédex!")
        ),
        .is_achieved = pokedex_catch_50_is_achieved,
        .max_progress = 50,
        .get_progress = pokedex_get_progress,
        .flag_achieved = FLAG_INCREASED_CATCH_RATE,
        .level = ACHIEVEMENT_LEVEL_SILVER,
        .reward = {
            .flag = FLAG_POKEDEX_ACHIVEMENT_CATCH_50_REWARD,
            .script = ow_script_achievement_pokedex_catch_50_reward,
            .description = (const u8[]) LANGDEP(
                PSTRING("Erhöhte Fangrate"), 
                PSTRING("Increased catch rate")
            ),
        }
    },
    {
        .description = (const u8[]) LANGDEP(
            PSTRING("Registriere 150 Pokémon im Pokédex!"), 
            PSTRING("Register 50 Pokémon in the Pokédex!")
        ),
        .is_achieved = pokedex_catch_150_is_achieved,
        .max_progress = 150,
        .get_progress = pokedex_get_progress,
        .flag_achieved = FLAG_RARE_POKEMON_MORE_LIKELY,
        .level = ACHIEVEMENT_LEVEL_GOLD,
        .reward = {
            .flag = FLAG_POKEDEX_ACHIVEMENT_CATCH_150_REWARD,
            .script = ow_script_achievement_pokedex_catch_150_reward,
            .description = (const u8[]) LANGDEP(
                PSTRING("Seltene wilde\nPokémon\nerscheinen\nhäufiger"), 
                PSTRING("Rare wild\nPokémon appear\nmore frequently")
            ),
        }
    },
    {
        .description = (const u8[]) LANGDEP(
            PSTRING("Registriere alle 386 Pokémon im Pokédex!"), 
            PSTRING("Register all 386 Pokémon in the Pokédex!")
        ),
        .is_achieved = pokedex_all_caught_is_achieved,
        .max_progress = POKEDEX_CNT,
        .get_progress = pokedex_get_progress,
        .flag_achieved = FLAG_POKEDEX_ACHIVEMENT_CATCH_ALL,
        .reward = {0}, // TODO: Schillerpin
        .level = ACHIEVEMENT_LEVEL_PLATINUM,
    }
};
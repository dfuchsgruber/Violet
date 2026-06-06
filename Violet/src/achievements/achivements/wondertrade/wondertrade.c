#include "achievements.h"
#include "language.h"
#include "pokepad/pokedex/operator.h"
#include "pokepad/pokedex/count.h"
#include "constants/flags.h"
#include "vars.h"
#include "pokepad/wondertrade.h"

extern const u8 ow_script_achievement_wondertrade_5_reward[];
extern const u8 ow_script_achievement_wondertrade_25_reward[];
extern const u8 ow_script_achievement_wondertrade_100_reward[];

u16 wondertrade_get_progress() {return *var_access(WONDERTRADE_CNT);}
bool wondertrade_bronze_is_achieved(void) {return wondertrade_get_progress() >= WONDERTRADE_LEVEL_REQUIREMENT_SILVER;}
bool wondertrade_silver_is_achieved(void) {return wondertrade_get_progress() >= WONDERTRADE_LEVEL_REQUIREMENT_GOLD;}
bool wondertrade_platinum_is_achieved(void) {return wondertrade_get_progress() >= WONDERTRADE_LEVEL_REQUIREMENT_PLATINUM;}

const achievement_t achievements_wondertrade[NUM_WONDERTRADE_ACHIEVEMENTS] = {
    {
        .description = (const u8[]) LANGDEP(
            PSTRING("Tausche 5 Pokémon über Wundertausch!"), 
            PSTRING("Trade 5 Pokémon via Wonder Trade!")
        ),
        .is_achieved = wondertrade_bronze_is_achieved,
        .max_progress = WONDERTRADE_LEVEL_REQUIREMENT_SILVER,
        .get_progress = wondertrade_get_progress,
        .flag_achieved = FLAG_WONDERTRADE_ACHIEVEMENT_5_ACHIEVED,
        .level = ACHIEVEMENT_LEVEL_BRONZE,
        .reward = {
            .flag = FLAG_WONDERTRADE_CHARGING_STEPS_REDUCED, // no reward
            .script = ow_script_achievement_wondertrade_5_reward,
            .description = (const u8[]) LANGDEP(
                PSTRING("Weniger Schritte\nzum Wundertausch\nAufladen."), 
                PSTRING("Wonder Trade\ncharging requires\nfewer steps.")
            ),
        }
    },
    {
        .description = (const u8[]) LANGDEP(
            PSTRING("Tausche 25 Pokémon über Wundertausch!"), 
            PSTRING("Trade 25 Pokémon via Wonder Trade!")
        ),
        .is_achieved = wondertrade_silver_is_achieved,
        .max_progress = WONDERTRADE_LEVEL_REQUIREMENT_GOLD,
        .get_progress = wondertrade_get_progress,
        .flag_achieved = FLAG_WONDERTRADE_ACHIEVEMENT_50_ACHIEVED,
        .level = ACHIEVEMENT_LEVEL_SILVER,
        .reward = {
            .flag = FLAG_WONDERTRADE_REPLACE_CAUGHT_POKEMON, // no reward
            .script = ow_script_achievement_wondertrade_25_reward,
            .description = (const u8[]) LANGDEP(
                PSTRING("Nicht registrierte\nPokémon häufiger\nim Wundertausch."), 
                PSTRING("Unregistered\nPokémon more\nfrequently in\nWonder Trade.")
            ),
        }
    },
    {
        .description = (const u8[]) LANGDEP(
            PSTRING("Tausche 100 Pokémon über Wundertausch!"), 
            PSTRING("Trade 100 Pokémon via Wonder Trade!")
        ),
        .is_achieved = wondertrade_platinum_is_achieved,
        .max_progress = WONDERTRADE_LEVEL_REQUIREMENT_PLATINUM,
        .get_progress = wondertrade_get_progress,
        .flag_achieved = FLAG_WONDERTRADE_ACHIEVEMENT_100_ACHIEVED,
        .level = ACHIEVEMENT_LEVEL_GOLD,
        .reward = {
            .flag = WONDERTRADE_MEW_RECEIVED, // no reward
            .script = ow_script_achievement_wondertrade_100_reward,
            .description = (const u8[]) LANGDEP(
                PSTRING("Erhalte ein\nMew."), 
                PSTRING("Receive a\nMew.")
            ),
        }
    }
};

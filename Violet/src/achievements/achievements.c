#include "achievements.h"
#include "constants/flags.h"
#include "language.h"
#include "flags.h"
#include "debug.h"

bool achievement_pokedex_unlocked() { return checkflag(POKEDEX); }
bool achievement_pokeradar_unlocked() { return checkflag(POKERADAR); }
bool achievement_wondertrade_unlocked() { return checkflag(WONDERTRADE); }
bool achievement_breeding_unlocked() { return true; }

u8 achievement_group_get_tail_idx(const achievement_group_t *group) {
    u8 i = 0;
    for (; i < group->num_achievements - 1; i++) {
        if (!group->achievements[i].is_achieved() || i == group->num_achievements - 1) {
            break;
        }
    }
    return i;
}

const achievement_group_t achievement_groups[NUM_ACHIEVEMENT_GROUPS] = {
    [ACHIEVEMENT_POKEDEX] = {
        .name = (const u8[]) LANGDEP(PSTRING("Schnapp sie dir!"), PSTRING("Catch 'em all!")),
        .achievements = achievements_pokedex,
        .is_unlocked = achievement_pokedex_unlocked,
        .num_achievements = ARRAY_COUNT(achievements_pokedex),
    },
    [ACHIEVEMENT_POKERADAR] = {
        .name = (const u8[]) LANGDEP(PSTRING("Pokémon-Jäger"), PSTRING("Pokémon Hunter")),
        .achievements = achievements_pokeradar,
        .is_unlocked = achievement_pokeradar_unlocked,
        .num_achievements = ARRAY_COUNT(achievements_pokeradar),
    },
    [ACHIEVEMENT_WONDERTRADE] = {
        .name = (const u8[]) LANGDEP(PSTRING("Tauschfreude"), PSTRING("Trading Fun")),
        .achievements = achievements_wondertrade,
        .is_unlocked = achievement_wondertrade_unlocked,
        .num_achievements = ARRAY_COUNT(achievements_wondertrade),
    },
    [ACHIEVEMENT_BREEDING] = {
        .name = (const u8[]) LANGDEP(PSTRING("Ausgebrütet"), PSTRING("Egg-cellent")),
        .achievements = achievements_breeding,
        .is_unlocked = achievement_breeding_unlocked,
        .num_achievements = ARRAY_COUNT(achievements_breeding),
    }
};
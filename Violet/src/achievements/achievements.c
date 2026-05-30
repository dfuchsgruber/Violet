#include "achievements.h"
#include "language.h"
#include "flags.h"

bool achievement_pokedex_unlocked() { return checkflag(POKEDEX); }

const achievement_group_t achievement_groups[] = {
    [0] = {
        .name = (const u8[]) LANGDEP(PSTRING("Schnapp sie dir!"), PSTRING("Catch 'em all!")),
        .achievements = achievements_pokedex,
        .is_unlocked = achievement_pokedex_unlocked,
        .num_achievements = ARRAY_COUNT(achievements_pokedex),
    },
};
#include "achievements.h"
#include "language.h"
#include "flags.h"
#include "debug.h"

bool achievement_pokedex_unlocked() { return checkflag(POKEDEX); }

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
    {
        .name = (const u8[]) LANGDEP(PSTRING("Schnapp sie dir!"), PSTRING("Catch 'em all!")),
        .achievements = achievements_pokedex,
        .is_unlocked = achievement_pokedex_unlocked,
        .num_achievements = ARRAY_COUNT(achievements_pokedex),
    },
    {
        .name = (const u8[]) LANGDEP(PSTRING("Test2"), PSTRING("Test2")),
        .achievements = achievements_pokedex,
        .is_unlocked = achievement_pokedex_unlocked,
        .num_achievements = ARRAY_COUNT(achievements_pokedex),
    },
    {
        .name = (const u8[]) LANGDEP(PSTRING("Test2"), PSTRING("Test2")),
        .achievements = achievements_pokedex,
        .is_unlocked = achievement_pokedex_unlocked,
        .num_achievements = 1,
    },
    {
        .name = (const u8[]) LANGDEP(PSTRING("Test2"), PSTRING("Test2")),
        .achievements = achievements_pokedex,
        .is_unlocked = achievement_pokedex_unlocked,
        .num_achievements = ARRAY_COUNT(achievements_pokedex),
    },
    {
        .name = (const u8[]) LANGDEP(PSTRING("Test2"), PSTRING("Test2")),
        .achievements = achievements_pokedex,
        .is_unlocked = achievement_pokedex_unlocked,
        .num_achievements = ARRAY_COUNT(achievements_pokedex),
    },
    {
        .name = (const u8[]) LANGDEP(PSTRING("INvislbe Test2"), PSTRING("INvisble Test2")),
        .achievements = achievements_pokedex,
        .is_unlocked = achievement_pokedex_unlocked,
        .num_achievements = ARRAY_COUNT(achievements_pokedex),
    },
    {
        .name = (const u8[]) LANGDEP(PSTRING("INvislbe Test3"), PSTRING("INvisble Test3")),
        .achievements = achievements_pokedex,
        .is_unlocked = achievement_pokedex_unlocked,
        .num_achievements = ARRAY_COUNT(achievements_pokedex),
    },
};
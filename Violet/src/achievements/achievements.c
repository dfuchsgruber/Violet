#include "achievements.h"
#include "constants/flags.h"
#include "debug.h"
#include "flags.h"
#include "item/item.h"
#include "language.h"

bool achievement_pokedex_unlocked() { return checkflag(POKEDEX); }
bool achievement_pokeradar_unlocked() { return checkflag(POKERADAR); }
bool achievement_wondertrade_unlocked() { return checkflag(WONDERTRADE); }
bool achievement_breeding_unlocked() { return checkflag(POKEDEX); }
bool achievement_berries_unlocked() { return true; }
bool achievement_rematches_unlocked() { return checkflag(FLAG_VS_SEEKER); }
bool achievement_fishing_unlocked() { return item_check(ITEM_ANGEL, 1) || item_check(ITEM_PROFIANGEL, 1) || item_check(ITEM_SUPERANGEL, 1); }

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
        .name = (const u8[])LANGDEP(PSTRING("Schnapp sie dir!"), PSTRING("Catch 'em all!")),
        .achievements = achievements_pokedex,
        .is_unlocked = achievement_pokedex_unlocked,
        .num_achievements = ARRAY_COUNT(achievements_pokedex),
    },
    [ACHIEVEMENT_POKERADAR] = {
        .name = (const u8[])LANGDEP(PSTRING("Auf dem Radar"), PSTRING("On the radar")),
        .achievements = achievements_pokeradar,
        .is_unlocked = achievement_pokeradar_unlocked,
        .num_achievements = ARRAY_COUNT(achievements_pokeradar),
    },
    [ACHIEVEMENT_WONDERTRADE] = {
        .name = (const u8[])LANGDEP(PSTRING("Nimm, was kommt"), PSTRING("Trading Fun")),
        .achievements = achievements_wondertrade,
        .is_unlocked = achievement_wondertrade_unlocked,
        .num_achievements = ARRAY_COUNT(achievements_wondertrade),
    },
    [ACHIEVEMENT_BREEDING] = {
        .name = (const u8[])LANGDEP(PSTRING("Ei, ei, eiDOTS"), PSTRING("Egg-cellent")),
        .achievements = achievements_breeding,
        .is_unlocked = achievement_breeding_unlocked,
        .num_achievements = ARRAY_COUNT(achievements_breeding),
    },
    [ACHIEVEMENT_BERRIES] = {
        .name = (const u8[])LANGDEP(PSTRING("Grüner Daumen"), PSTRING("Green Thumb")),
        .achievements = achievements_berries,
        .is_unlocked = achievement_berries_unlocked,
        .num_achievements = ARRAY_COUNT(achievements_berries),
    },
    [ACHIEVEMENT_REMATCHES] = {
        .name = (const u8[])LANGDEP(PSTRING("Runde Zwei"), PSTRING("Round Two")),
        .achievements = achievements_rematches,
        .is_unlocked = achievement_rematches_unlocked,
        .num_achievements = ARRAY_COUNT(achievements_rematches),
    },
    [ACHIEVEMENT_FISHING] = {
        .name = (const u8[])LANGDEP(PSTRING("Petri Heil"), PSTRING("Fishin' for compliments")),
        .achievements = achievements_fishing,
        .is_unlocked = achievement_fishing_unlocked,
        .num_achievements = ARRAY_COUNT(achievements_fishing),
    },
};
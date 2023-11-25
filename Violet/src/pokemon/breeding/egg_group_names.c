#include "types.h"
#include "pokemon/breeding.h"
#include "constants/egg_groups.h"
#include "language.h"

static const u8 str_egg_group_none[] = LANGDEP(PSTRING("None"), PSTRING("None"));
static const u8 str_egg_group_monster[] = LANGDEP(PSTRING("Monster"), PSTRING("Monster"));
static const u8 str_egg_group_wasser_1[] = LANGDEP(PSTRING("Wasser 1"), PSTRING("Water 1"));
static const u8 str_egg_group_kaefer[] = LANGDEP(PSTRING("Käfer"), PSTRING("Bug"));
static const u8 str_egg_group_flug[] = LANGDEP(PSTRING("Flug"), PSTRING("Flying"));
static const u8 str_egg_group_feld[] = LANGDEP(PSTRING("Feld"), PSTRING("Field"));
static const u8 str_egg_group_fee[] = LANGDEP(PSTRING("Fee"), PSTRING("Fairy"));
static const u8 str_egg_group_pflanze[] = LANGDEP(PSTRING("Pflanze"), PSTRING("Grass"));
static const u8 str_egg_group_humanotyp[] = LANGDEP(PSTRING("Humanotyp"), PSTRING("Human-Like"));
static const u8 str_egg_group_wasser_3[] = LANGDEP(PSTRING("Wasser 3"), PSTRING("Water 3"));
static const u8 str_egg_group_mineral[] = LANGDEP(PSTRING("Mineral"), PSTRING("Mineral"));
static const u8 str_egg_group_amorph[] = LANGDEP(PSTRING("Amorph"), PSTRING("Amorphous"));
static const u8 str_egg_group_wasser_2[] = LANGDEP(PSTRING("Wasser 2"), PSTRING("Water 2"));
static const u8 str_egg_group_ditto[] = LANGDEP(PSTRING("Ditto"), PSTRING("Ditto"));
static const u8 str_egg_group_drache[] = LANGDEP(PSTRING("Drache"), PSTRING("Dragon"));
static const u8 str_egg_group_unbekannt[] = LANGDEP(PSTRING("Unbekannt"), PSTRING("Undiscovered"));

const u8 *const egg_group_names[NUM_EGG_GROUPS] = {
    [EGG_GROUP_NONE] = str_egg_group_none,
    [EGG_GROUP_MONSTER] = str_egg_group_monster,
    [EGG_GROUP_WASSER_1] = str_egg_group_wasser_1,
    [EGG_GROUP_KAEFER] = str_egg_group_kaefer,
    [EGG_GROUP_FLUG] = str_egg_group_flug,
    [EGG_GROUP_FELD] = str_egg_group_feld,
    [EGG_GROUP_FEE] = str_egg_group_fee,
    [EGG_GROUP_PFLANZE] = str_egg_group_pflanze,
    [EGG_GROUP_HUMANOTYP] = str_egg_group_humanotyp,
    [EGG_GROUP_WASSER_3] = str_egg_group_wasser_3,
    [EGG_GROUP_MINERAL] = str_egg_group_mineral,
    [EGG_GROUP_AMORPH] = str_egg_group_amorph,
    [EGG_GROUP_WASSER_2] = str_egg_group_wasser_2,
    [EGG_GROUP_DITTO] = str_egg_group_ditto,
    [EGG_GROUP_DRACHE] = str_egg_group_drache,
    [EGG_GROUP_UNBEKANNT] = str_egg_group_unbekannt,
};
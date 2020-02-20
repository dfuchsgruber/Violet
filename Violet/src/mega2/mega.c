#include "types.h"
#include "mega.h"
#include "constants/species.h"
#include "constants/items.h"
#include "flags.h"
#include "constants/flags.h"
#include "save.h"
#include "debug.h"

static mega_evolution_t mega_evolutions[] = {
    {POKEMON_BISAFLOR, ITEM_BISAFLORNIT, POKEMON_BISAFLORM, MEGA_EVOLUTION},
    {POKEMON_GLURAK, ITEM_GLURAKNIT, POKEMON_GLURAKM, MEGA_EVOLUTION},
    {POKEMON_GROUDON, ITEM_MAGMAHERZ, POKEMON_GROUDON_REGENT, REGENT_EVOLUTION},
    {POKEMON_GEOWAZ, ITEM_GEOWAZNIT, POKEMON_MEGA_GEOWAZ, MEGA_EVOLUTION},
    {POKEMON_TROPIUS, ITEM_TROPIUSNIT, POKEMON_MEGA_TROPIUS, MEGA_EVOLUTION},
    {0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF},
};


u8 battler_get_owner(u8 battler_idx) { 
    // TODO: Co-op battles, multi-trainer battles
    return (u8)battler_is_opponent(battler_idx);
}

mega_evolution_t *battler_get_available_mega_evolution(u8 battler_idx) {
    u8 owner = battler_get_owner(battler_idx);
    if (owner == 0 && !checkflag(PLAYER_ABLE_TO_MEGA_EVOLVE))
        return NULL;
    if (MEGA_STATE.owner_mega_evolved[owner])
        return NULL;
    // Check if any other battler with the same owner is marked for mega evolution
    for (u8 i = 0; i < battler_cnt; i++) {
        if (i != battler_idx && battler_get_owner(i) == owner && MEGA_STATE.marked_for_mega_evolution[i])
            return NULL; 
    }
    for (int i = 0; mega_evolutions[i].species != 0xFFFF; i++) {
        if (mega_evolutions[i].species == battlers[battler_idx].species && mega_evolutions[i].mega_item == battlers[battler_idx].item) {
            return mega_evolutions + i;
        }
    }
    return NULL;
}

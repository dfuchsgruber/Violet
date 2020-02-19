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

mega_evolution_t *battler_get_available_mega_evolution(u8 battler_idx) {
    if (!battler_is_opponent(battler_idx) && !checkflag(PLAYER_ABLE_TO_MEGA_EVOLVE))
        return NULL;
    u8 side = battler_get_position(battler_idx); // TODO: maybe adapt for multi-battles etc.
    if (fmem.mega_state.mega_evolution_performed & (1 << side)) {
        dprintf("Unable to perform mega on side %d\n", side);
        return NULL;
    }
    // Battlers with 0 pps can not perform a mega evolution
    int pp_total = 0;
    for (int i = 0; i < 4; i++) {
        pp_total += battlers[battler_idx].current_pp[i];
    }
    if (pp_total <= 0)
        return NULL;
    for (int i = 0; mega_evolutions[i].species != 0xFFFF; i++) {
        if (mega_evolutions[i].species == battlers[battler_idx].species && mega_evolutions[i].mega_item == battlers[battler_idx].item) {
            return mega_evolutions + i;
        }
    }
    return NULL;
}
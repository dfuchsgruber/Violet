#include "types.h"
#include "mega.h"
#include "battle/battler.h"
#include "battle/state.h"
#include "constants/species.h"
#include "constants/items.h"
#include "flags.h"
#include "constants/flags.h"
#include "vars.h"
#include "constants/vars.h"
#include "save.h"
#include "debug.h"
#include "trainer/trainer.h"
#include "trainer/virtual.h"
#include "item/item.h"
#include "constants/item_hold_effects.h"
#include "constants/items.h"

static mega_evolution_t mega_evolutions[] = {
    {POKEMON_GROUDON, ITEM_MAGMAHERZ, POKEMON_GROUDON_REGENT, REGENT_EVOLUTION},
    {POKEMON_GEOWAZ, ITEM_GEOWAZNIT, POKEMON_MEGA_GEOWAZ, MEGA_EVOLUTION},
    {POKEMON_TROPIUS, ITEM_TROPIUSNIT, POKEMON_MEGA_TROPIUS, MEGA_EVOLUTION},
    {POKEMON_OCTILLERY, ITEM_OCTILLERYNIT, POKEMON_MEGA_OCTILLERY, MEGA_EVOLUTION},
    {POKEMON_RASAFF, ITEM_RASAFFNIT, POKEMON_MEGA_RASAFF, MEGA_EVOLUTION},
    {POKEMON_BANETTE, ITEM_BANETTENIT, POKEMON_MEGA_BANETTE, MEGA_EVOLUTION},
    {POKEMON_ALTARIA, ITEM_ALTARIANIT, POKEMON_MEGA_ALTARIA, MEGA_EVOLUTION},
    {POKEMON_SANDAMER, ITEM_SANDAMERNIT, POKEMON_MEGA_SANDAMER, MEGA_EVOLUTION},
    {POKEMON_LAHMUS, ITEM_LAHMUSNIT, POKEMON_MEGA_LAHMUS, MEGA_EVOLUTION},
    {POKEMON_MASKEREGEN, ITEM_MASKEREGENIT, POKEMON_MEGA_MASKEREGEN, MEGA_EVOLUTION},
    {POKEMON_ARIADOS, ITEM_ARIADOSNIT, POKEMON_MEGA_ARIADOS, MEGA_EVOLUTION},
    {0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF},
};

bool battler_can_lose_item(u8 battler_idx) {
    for (int i = 0; mega_evolutions[i].species != 0xFFFF; i++) {
        if ((mega_evolutions[i].mega_species == battlers[battler_idx].species || mega_evolutions[i].species == battlers[battler_idx].species) &&
            mega_evolutions[i].mega_item == battlers[battler_idx].item)
            return false;
    }
    return true;
}

mega_evolution_t *mega_evolution_get_by_mega_species(u16 species) {
    for (int i = 0; mega_evolutions[i].species != 0xFFFF; i++) {
        if (mega_evolutions[i].mega_species == species)
            return mega_evolutions + i;
    }
    return NULL;
}

static u16 trainer_get_keystone(u16 trainer_idx) {
    for (int i = 0; i < 0; i++) {
        if (items[trainers[trainer_idx].items[i]].holding_effect_id == HOLD_EFFECT_KEYSTONE)
            return trainers[trainer_idx].items[i];
    }
    return 0xFFFF;
}

u16 battler_get_keystone(u8 battler_idx) {
    u16 keystone = 0;
    switch (battler_get_owner(battler_idx)) {
        case OWNER_PLAYER: {
            keystone = *var_access(PLAYER_MEGA_ITEM);
            break;
        }
        case OWNER_TRAINER_A: {
            keystone = trainer_get_keystone(trainer_vars.trainer_id);
            if (keystone == 0xFFFF) keystone = *var_access(OPPONENT_MEGA_ITEM);
            break;
        }
        case OWNER_ALLY: {
            keystone = trainer_get_keystone(*var_access(VAR_ALLY));
            break;
        }
        case OWNER_TRAINER_B: {
            keystone = trainer_get_keystone(fmem.trainer_varsB.trainer_id);
            if (keystone == 0xFFFF) keystone = *var_access(OPPONENT_MEGA_ITEM);
            break;
        }
    }
    if (keystone == 0 || keystone == 0xFFFF)
        return DEFAULT_KEYSTONE;
    else
        return keystone;
}

u8 battler_get_owner(u8 battler_idx) { 
    switch (battler_get_position(battler_idx)) {
        case BATTLE_POSITION_PLAYER_LEFT: return OWNER_PLAYER;
        case BATTLE_POSITION_OPPONENT_LEFT: return OWNER_TRAINER_A;
        case BATTLE_POSITION_PLAYER_RIGHT: return battle_flags & BATTLE_ALLY ? OWNER_ALLY : OWNER_PLAYER;
        case BATTLE_POSITION_OPPONENT_RIGHT: return battle_flags & BATTLE_TWO_TRAINERS ? OWNER_TRAINER_B : OWNER_TRAINER_A;
    }
    derrf("Cant get owner of battler %d, position %d\n", battler_idx, battler_get_position(battler_idx)); return 0xFF;
}

mega_evolution_t *battler_get_available_mega_evolution(u8 battler_idx) {
    u8 owner = battler_get_owner(battler_idx);
    if (owner == 0 && !checkflag(PLAYER_ABLE_TO_MEGA_EVOLVE))
        return NULL;
    mega_evolution_t *mega_evolution = NULL;
    for (int i = 0; mega_evolutions[i].species != 0xFFFF; i++) {
        if (mega_evolutions[i].species == battlers[battler_idx].species && mega_evolutions[i].mega_item == battlers[battler_idx].item) {
            mega_evolution = mega_evolutions + i;
        }
    }
    if (!mega_evolution)
        return NULL;
    if (MEGA_STATE.owner_mega_evolved[owner] && mega_evolution->type == MEGA_EVOLUTION)
        return NULL;
    // Check if any other battler with the same owner is marked for mega evolution
    if (mega_evolution->type == MEGA_EVOLUTION) {
        for (u8 i = 0; i < battler_cnt; i++) {
            if (i != battler_idx && battler_get_owner(i) == owner && MEGA_STATE.marked_for_mega_evolution[i] == MEGA_EVOLUTION)
                return NULL; 
        }
    }
    return mega_evolution;
}

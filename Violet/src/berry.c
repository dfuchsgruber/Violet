#include "types.h"
#include "save.h"
#include "berry.h"
#include "debug.h"
#include "agbmemory.h"
#include "vars.h"
#include "overworld/sprite.h"
#include "item/item.h"
#include "prng.h"
#include "constants/berry_pouch_contexts.h"
#include "callbacks.h"
#include "overworld/map_control.h"
#include "fading.h"
#include "overworld/pokemon_party_menu.h"
#include "rtc.h"

u8 berry_tree_get_berry(u8 berry_tree_idx) {
    return cmem.berry_trees[berry_tree_idx].berry;
}
 

static u8 berry_tree_initial_items[] = {
    [0] = ITEM_IDX_TO_BERRY_IDX(ITEM_LYDZIBEERE),
    [1] = ITEM_IDX_TO_BERRY_IDX(ITEM_PIRSIFBEERE),
};

void berry_tree_calculate_yield(u8 berry_tree_idx) {
    berry *b = berry_get(cmem.berry_trees[berry_tree_idx].berry);
    u8 yield = (u8)((rnd16() % (b->max_yield - b->min_yield)) + b->min_yield);
    cmem.berry_trees[berry_tree_idx].yield = (u8)(yield & 7);
    // dprintf("Initialized berry tree %d with yield %d\n", berry_tree_idx, yield);
}


u16 berry_get_stage_duration(u8 berry_tree_idx) {
    berry *b = berry_get(cmem.berry_trees[berry_tree_idx].berry);
    return (u16)(b->stage_duration * 5); // Where as in the original game the unit of stage duration would be hours, we simply make a stage 12 times faster (5 minutes)
}


void berry_tree_initialize(u8 berry_tree_idx, u8 berry_idx, u8 stage) {
    cmem.berry_trees[berry_tree_idx].berry = berry_idx;
    cmem.berry_trees[berry_tree_idx].stage = (u8)(stage & 7);
    berry_tree_calculate_yield(berry_tree_idx);
    cmem.berry_trees[berry_tree_idx].minutes_to_next_stage = berry_get_stage_duration(berry_tree_idx);
}


void berry_trees_initialize_all() {
    memset(cmem.berry_trees, 0, sizeof(cmem.berry_trees));
    for (u8 i = 0; i < ARRAY_COUNT(berry_tree_initial_items); i++) {
        berry_tree_initialize(i, berry_tree_initial_items[i], BERRY_STAGE_BERRIES);
    }
}

u16 berry_tree_get_stage() {
    return cmem.berry_trees[*var_access(0x8000)].stage;
}

u16 berry_tree_get_item() {
    return (u16)BERRY_IDX_TO_ITEM_IDX(cmem.berry_trees[*var_access(0x8000)].berry);
}

u16 berry_tree_get_yield() {
    return (u16)BERRY_IDX_TO_ITEM_IDX(cmem.berry_trees[*var_access(0x8000)].yield);
}

void berry_tree_update_gfx() {
    u8 person_idx = (u8)(*var_access(LASTTALKED));
    u8 npc_idx = npc_get_by_person_idx(person_idx, save1->map, save1->bank);
    if (npc_idx < 16) {
        u8 oam_idx = npcs[npc_idx].oam_id;
        npcs[npc_idx].flags.active = 0; // Temporarily disable the npc such that the pal can be released
        u8 pal_idx_old = (u8)((oams[oam_idx].final_oam.attr2 >> 12) & 15);
        npc_free_palette_if_unused_by_slot(pal_idx_old);
        npcs[npc_idx].flags.active = 1; // Set the npc to active again
        overworld_npc_update_palette(npcs + npc_idx, oams + oam_idx);
        map_event_person *person = map_get_person(npcs[npc_idx].overworld_id, npcs[npc_idx].map, npcs[npc_idx].bank);
        overworld_sprite *ow = overworld_sprite_get_by_berry_idx((u8)(person->value));
        oams[oam_idx].gfx_table = ow->graphics;
        oam_gfx_anim_start(oams + oam_idx, 0);
    }
}

bool berry_pick() {
    u16 item_idx = (u16)(BERRY_IDX_TO_ITEM_IDX(cmem.berry_trees[*var_access(0x8000)].berry));
    u8 count = cmem.berry_trees[*var_access(0x8000)].yield;
    if (!item_has_room(item_idx, count)) return false;
    item_add(item_idx, count);
    cmem.berry_trees[*var_access(0x8000)].picked_once = 1;
    cmem.berry_trees[*var_access(0x8000)].stage = BERRY_STAGE_NO_BERRY;
    return true;
}

void berry_pouch_callback_plant_berry(u8 self) {
    item_remove(item_activated, 1);
    u8 berry_tree_idx = (u8)*var_access(0x8000);
    berry_tree_initialize(berry_tree_idx, (u8)ITEM_IDX_TO_BERRY_IDX(item_activated), BERRY_STAGE_DIRT_PILE);
    cmem.berry_trees[berry_tree_idx].replanted = 1;
    big_callbacks[self].function = berry_pouch_fade_and_continuation;
}

void (*berry_pouch_callbacks[])(u8) = {
    [BERRY_POUCH_CONTEXT_FROM_OVERWORLD] = berry_pouch_callback_context_menu,
    [BERRY_POUCH_CONTEXT_FROM_PARTY_MENU_GIVE] = berry_pouch_callback_from_party_menu_give,
    [BERRY_POUCH_CONTEXT_FROM_MART_SELL] = berry_pouch_callback_from_mart_sell,
    [BERRY_POUCH_CONTEXT_FROM_STORAGE_PC] = berry_pouch_callback_from_storage_pc,
    [BERRY_POUCH_CONTEXT_FROM_BATTLE] = berry_pouch_callback_context_menu,
    [BERRY_POUCH_CONTEXT_FROM_BERRY_CRUSH] = 0,
    [BERRY_POUCH_CONTEXT_PLANTING] = berry_pouch_callback_plant_berry,
};

void berry_plant_callback_initialize_berry_pouch(u8 self) {
    if (!fading_control.active) {
        berry_pouch_initialize(BERRY_POUCH_CONTEXT_PLANTING, map_reload, 0);
        big_callback_delete(self);
    }
}

void berry_plant() {
    big_callback_new(berry_plant_callback_initialize_berry_pouch, 0);
    fadescreen_all(1, 0);
}

bool berry_tree_grow(u8 berry_tree_idx) {
    berry_tree *tree = cmem.berry_trees + berry_tree_idx;
    switch(tree->stage) {
        case BERRY_STAGE_NO_BERRY: return false; // Can't grow obviously
        case BERRY_STAGE_BERRIES: return false; // Can't grow any more, I will *not* destroy trees that were not harvested in time...
        case BERRY_STAGE_BLOSSOM:
            berry_tree_calculate_yield(berry_tree_idx);
            break;
    }
    tree->stage++;
    tree->minutes_to_next_stage = berry_get_stage_duration(berry_tree_idx);
    return true;
}

void berry_proceed_minutes(u16 minutes) {
    // dprintf("Proceeding berries by %d minutes\n", minutes);
    for (size_t i = 0; i < ARRAY_COUNT(cmem.berry_trees); i++) {
        berry_tree *tree = cmem.berry_trees + i;
        if (tree->stage != BERRY_STAGE_NO_BERRY) {
            u16 time = minutes; // This is the time left to be used up by the berry for growing
            while (time) {
                if (tree->minutes_to_next_stage > time) {
                    tree->minutes_to_next_stage = (u16)(tree->minutes_to_next_stage - time);
                    // dprintf("For tree %d there are %d min remaining for the next stage.\n", i, tree->minutes_to_next_stage);
                    break;
                }
                // We can entirely finished a stage
                time = (u16)(time - tree->minutes_to_next_stage);
                if(!berry_tree_grow((u8)i)) 
                    break; // The tree can't grow anymore
                dprintf("Tree %d grew to stage %d\n", i, tree->stage);
            }
        }
    }
}

void berry_proceed() {
    if (!time_test()) return;
	if (!fmem.berry_tree_time_last_updated_initialized) {
        time_read(&fmem.berry_tree_time_last_update);
        fmem.berry_tree_time_last_updated_initialized = 1;
        dprintf("Reference timestamp for berry tree updated initialized.\n");
	}
    rtc_timestamp time = {0};
    time_read(&time);
    u64 lseconds_last_update = rtc_timestamp_to_seconds(&fmem.berry_tree_time_last_update);
    u64 lseconds_current = rtc_timestamp_to_seconds(&time);
    if (lseconds_current < lseconds_last_update) {
        dprintf("Warning: The current time is before the last berry tree update, this most likely is a bug...\n");
        return;
    }
    u64 ldelta_minutes = MIN(60 * 24 * 7, (lseconds_current - lseconds_last_update) / 64); // We do not care about delays longer than a week...
    if (ldelta_minutes > 0) {
        u16 delta_minutes = (u16)ldelta_minutes;
        berry_proceed_minutes(delta_minutes);
        time_read(&fmem.berry_tree_time_last_update);
    }
}
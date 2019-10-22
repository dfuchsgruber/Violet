#include "types.h"
#include "callbacks.h"
#include "map/wild_pokemon.h"
#include "pokemon/virtual.h"
#include "constants/flags.h"
#include "flags.h"
#include "save.h"
#include "prng.h"
#include "data_structures.h"
#include "constants/sav_keys.h"
#include "debug.h"
#include "item/fishing.h"
#include "overworld/script.h"
#include "constants/items.h"
#include "item/item.h"

static u16 fishing_rng_no_bait() {
    u32 state = (u32)gp_stack_pop();
    u16 r = (u16)_prng_xorshift(&state);
    gp_stack_push((int)state);
    return (u16)(r % (512 - MIN(save_get_key(SAV_KEY_FISHING_ENCOUNTERS), 256)));
}

static u16 fishing_rng_bait() {
    u32 state = (u32)gp_stack_pop();
    u16 r = (u16)_prng_xorshift(&state);
    gp_stack_push((int)state);
    return (u16)(r % (256 - MIN(save_get_key(SAV_KEY_FISHING_ENCOUNTERS), 128)));
}

static u16 fishing_rng_golden_bait() {
    u32 state = (u32)gp_stack_pop();
    u16 r = (u16)_prng_xorshift(&state);
    gp_stack_push((int)state);
    return (u16)(r % (64 - MIN(save_get_key(SAV_KEY_FISHING_ENCOUNTERS), 32)));
}

u16 fishing_create_pokemon(wild_pokemon_habitat *habitat, u8 rod_type) {
    int idx = wildbattle_sample_from_rod_pdf(rod_type);
    u8 level = wildbattle_sample_level(habitat->data + idx);
    u16 species = habitat->data[idx].species;
    pid_t pid = {.value = 0};
    // Seed the fishing feature rng
    u32 seed = (u32)((rnd16() << 16) | rnd16());
    gp_stack_push((int)seed);
    if (checkflag(FLAG_FISHING_GOLDEN_BAIT_USED)) {
        pokemon_spawn_by_seed_algorithm(opponent_pokemon, species, (u8)(MIN(level + 5, 100)), 
        POKEMON_NEW_RANDOM_IVS, false, pid, false, 0, fishing_rng_golden_bait, NULL);
        clearflag(FLAG_FISHING_GOLDEN_BAIT_USED);
        item_remove(ITEM_GOLDKOEDER, 1);
        dprintf("Spawned fishing pokemon with golden bait\n");
    } else if (checkflag(FLAG_FISHING_BAIT_USED)) {
        pokemon_spawn_by_seed_algorithm(opponent_pokemon, species, (u8)(MIN(level + 2, 100)), 
        POKEMON_NEW_RANDOM_IVS, false, pid, false, 0, fishing_rng_bait, NULL);
        clearflag(FLAG_FISHING_BAIT_USED);
        item_remove(ITEM_KOEDER, 1);
        dprintf("Spawned fishing pokemon with bait\n");
    } else {
        pokemon_spawn_by_seed_algorithm(opponent_pokemon, species, level, 
        POKEMON_NEW_RANDOM_IVS, false, pid, false, 0, fishing_rng_no_bait, NULL);
        dprintf("Spawned fishing pokemon without bait\n");
    }
    gp_stack_pop();
    return species;
}

static void fishing_big_callback_wait_bait_selection(u8 self) {
    (void) self;
}

void fishing_start_after_bait_selection() {
    u8 idx = big_callback_get_id(fishing_big_callback_wait_bait_selection);
    if (idx == 0xFF) derrf("No fishing in progress, can't start it after bait selection...\n");
    big_callbacks[idx].function = fishing_big_callback;
}

void fishing_big_callback_bait(u8 self) {
    overworld_script_init(ow_script_fishing);
    big_callbacks[self].function = fishing_big_callback_wait_bait_selection;
}
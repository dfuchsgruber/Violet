#include "types.h"
#include "overworld/sprite.h"
#include "color.h"
#include "constants/items.h"
#include "save.h"
#include "debug.h"
#include "flags.h"
#include "vars.h"
#include "agbmemory.h"
#include "prng.h"
#include "mushroom_and_shell.h"
#include "constants/species.h"

// These special shells will spawn either shoal salt or shoal shell
static u16 shell_idx_with_shoal_salt_or_shoal_shell[] = {
    0x1337 // stub
};

u16 special_mushroom_get_stage() {
    return mushroom_get_stage(map_get_person((u8)(*var_access(LASTTALKED)), save1->map, save1->bank)->value);
}


static u32 mushroom_rates[] = {[MUSHROOM_TYPE_LARGE_MUSHROOM] = 1, [MUSHROOM_TYPE_TINY_MUSHROOM] = 4};

u16 mushroom_get_stage(u16 mushroom_idx) {
    if (gp_flag_get(mushroom_idx, cmem.mushroom_flags))
        return MUSHROOM_TYPE_PLUCKED;
    u32 seq[1] = {mushroom_idx};
    gp_rng_seed(daily_events_hash(seq, ARRAY_COUNT(seq)));
    return (u16)choice(mushroom_rates, ARRAY_COUNT(mushroom_rates), gp_rnd16);
}

void mushroom_pluck() {
    map_event_person *p = map_get_person((u8)(*var_access(LASTTALKED)), save1->map, save1->bank);
    u16 mushroom_idx = p->value;
    gp_flag_set(mushroom_idx, cmem.mushroom_flags);
}

u16 special_shell_get_stage() {
    u16 stage = shell_get_stage(map_get_person((u8)(*var_access(LASTTALKED)), save1->map, save1->bank)->value);
    dprintf("Shell stage is %d\n", stage);
    return stage;
}

static u32 shell_rates[] = {[SHELL_TYPE_HEART_SCALE] = 1, [SHELL_TYPE_PEARL] = 6, [SHELL_TYPE_LARGE_PEARL] = 2, [SHELL_TYPE_ENCOUNTER] = 10};
static u32 species_shell_rates[] = {[SHELL_TYPE_SHOAL_SALT] = 3, [SHELL_TYPE_SHOAL_SHELL] = 3, [SHELL_TYPE_ENCOUNTER] = 1};

u16 shell_get_stage(u16 shell_idx) {
    if (gp_flag_get(shell_idx, cmem.shell_flags)) {
        return SHELL_TYPE_EMPTY;
    }
    u32 seq[1] = {shell_idx};
    gp_rng_seed(daily_events_hash(seq, ARRAY_COUNT(seq)));
    // Check if we have special shell
    bool special_shell = false;
    for(size_t i = 0; i < ARRAY_COUNT(shell_idx_with_shoal_salt_or_shoal_shell); i++) {
        if (shell_idx_with_shoal_salt_or_shoal_shell[i] == shell_idx) {
            special_shell = true;
            break;
        }
    }
    if (special_shell) {
        return (u16)choice(species_shell_rates, ARRAY_COUNT(species_shell_rates), gp_rnd16);
    } else {
        return (u16)choice(shell_rates, ARRAY_COUNT(shell_rates), gp_rnd16);
    }
}

void shell_open() {
    map_event_person *p = map_get_person((u8)(*var_access(LASTTALKED)), save1->map, save1->bank);
    u16 shell_idx = p->value;
    gp_flag_set(shell_idx, cmem.shell_flags);
}

void mushroom_and_shell_regrow() {
    memset(cmem.mushroom_flags, 0, ARRAY_COUNT(cmem.mushroom_flags));
    memset(cmem.shell_flags, 0, ARRAY_COUNT(cmem.shell_flags));
}

static u32 mushroom_encounters[] = {[POKEMON_KNILZ] = 1, [POKEMON_WAUMPEL] = 1, [POKEMON_SAMURZEL] = 1, [POKEMON_MYRAPLA] = 1, [POKEMON_KNOFENSA] = 1, [0] = 6};

u16 mushroom_get_encounter() {
    map_event_person *p = map_get_person((u8)(*var_access(LASTTALKED)), save1->map, save1->bank);
    u16 mushroom_idx = p->value;
    u32 seq[1] = {mushroom_idx};
    gp_rng_seed(daily_events_hash(seq, ARRAY_COUNT(seq)));
    return (u16)choice(mushroom_encounters, ARRAY_COUNT(mushroom_encounters), gp_rnd16);
}

static u32 shell_encounters[] = {[POKEMON_MUSCHAS] = 3, [POKEMON_PERLU] = 2, [POKEMON_KRABBY] = 2, [POKEMON_KREBSCORPS] = 1};

u16 shell_get_encounter() {
    map_event_person *p = map_get_person((u8)(*var_access(LASTTALKED)), save1->map, save1->bank);
    u16 shell_idx = p->value;
    u32 seq[1] = {shell_idx};
    gp_rng_seed(daily_events_hash(seq, ARRAY_COUNT(seq)));
    u16 species = (u16)choice(shell_encounters, ARRAY_COUNT(shell_encounters), gp_rnd16);
    dprintf("Shell encounter %d\n", species);
    return species;
}

static u16 misc_feature_generator() {
    return (u16)(gp_rnd16() & 511);
}

void misc_encounter_setup() {
    u16 species = *var_access(0x8004);
    map_event_person *p = map_get_person((u8)(*var_access(LASTTALKED)), save1->map, save1->bank);
    u32 seq[1] = {p->value};
    gp_rng_seed(daily_events_hash(seq, ARRAY_COUNT(seq)));

    u8 mean = 0, std = 0;
    dungeon2_get_wild_pokemon_level_distribution(&mean, &std);
    FIXED x = gp_rnd_normal();
    int level = FIXED_TO_INT(FIXED_ADD(INT_TO_FIXED(mean), FIXED_MUL(x, INT_TO_FIXED(std))));
    level = MIN(100, MAX(5, level));
    pid_t pid = {0};
    pokemon_spawn_by_seed_algorithm(opponent_pokemon + 0, species, (u8)level, 32, false, pid, false, 0, misc_feature_generator, NULL);
}
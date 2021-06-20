#include "types.h"
#include "overworld/sprite.h"
#include "overworld/script.h"
#include "color.h"
#include "constants/items.h"
#include "save.h"
#include "debug.h"
#include "flags.h"
#include "vars.h"
#include "agbmemory.h"
#include "prng.h"
#include "overworld/misc.h"
#include "math.h"
#include "music.h"
#include "constants/species.h"
#include "constants/overworld/misc.h"

static gfx_frame gfx_animation_mushroom_idle[] = {
	{.data = 0, .duration = 0}, {.data = 0, .duration = 32}, {.data = 1, .duration = 32}, {.data = GFX_ANIM_JUMP, .duration = 0},
};

static gfx_frame gfx_animation_shell_idle[] = {
	{.data = 0, .duration = 0}, {.data = 0, .duration = 12}, {.data = 1, .duration = 12}, 
    {.data = 2, .duration = 12}, {.data = 3, .duration = 12}, {.data = 4, .duration = 12},
    {.data = GFX_ANIM_JUMP, .duration = 0},
};

static gfx_frame gfx_animation_trash_idle[] = {
	{.data = 0, .duration = 0}, {.data = 0, .duration = 48}, {.data = 0, .duration = 24}, 
    {.data = 1, .duration = 4}, {.data = 2, .duration = 6}, {.data = 1, .duration = 4},
    {.data = 0, .duration = 48}, {.data = 0, .duration = 24}, 
    {.data = 1, .duration = 4 | GFX_ANIM_HFLIP}, {.data = 2, .duration = 6 | GFX_ANIM_HFLIP}, {.data = 1, .duration = 4 | GFX_ANIM_HFLIP},
    {.data = GFX_ANIM_JUMP, .duration = 0},
};

static gfx_frame gfx_animation_trash_empty[] = {
	{.data = 0, .duration = 0},
    {.data = GFX_ANIM_END, .duration = 0},
};



static gfx_frame *gfx_animations_mushroom[1] = {gfx_animation_mushroom_idle};
static gfx_frame *gfx_animations_shell[1] = {gfx_animation_shell_idle};
static gfx_frame *gfx_animations_trash[2] = {gfx_animation_trash_idle, gfx_animation_trash_empty};

static graphic overworld_gfx_mushrooms[] = {
	[0] = {gfx_ow_mushroomTiles + 0 * GRAPHIC_SIZE_4BPP(16, 16), .size = GRAPHIC_SIZE_4BPP(16, 16), .tag = 0},
	[1] = {gfx_ow_mushroomTiles + 0 * GRAPHIC_SIZE_4BPP(16, 16), .size = GRAPHIC_SIZE_4BPP(16, 16), .tag = 0},
	[2] = {gfx_ow_mushroomTiles + 1 * GRAPHIC_SIZE_4BPP(16, 16), .size = GRAPHIC_SIZE_4BPP(16, 16), .tag = 0},
	[3] = {gfx_ow_mushroomTiles + 2 * GRAPHIC_SIZE_4BPP(16, 16), .size = GRAPHIC_SIZE_4BPP(16, 16), .tag = 0},
	[4] = {gfx_ow_mushroomTiles + 3 * GRAPHIC_SIZE_4BPP(16, 16), .size = GRAPHIC_SIZE_4BPP(16, 16), .tag = 0},
	[5] = {gfx_ow_mushroomTiles + 4 * GRAPHIC_SIZE_4BPP(16, 16), .size = GRAPHIC_SIZE_4BPP(16, 16), .tag = 0},
};


static graphic overworld_gfx_shells[] = {
	[0] = {gfx_ow_shellTiles + 0 * GRAPHIC_SIZE_4BPP(16, 16), .size = GRAPHIC_SIZE_4BPP(16, 16), .tag = 0},
	[1] = {gfx_ow_shellTiles + 0 * GRAPHIC_SIZE_4BPP(16, 16), .size = GRAPHIC_SIZE_4BPP(16, 16), .tag = 0},
	[2] = {gfx_ow_shellTiles + 0 * GRAPHIC_SIZE_4BPP(16, 16), .size = GRAPHIC_SIZE_4BPP(16, 16), .tag = 0},
	[3] = {gfx_ow_shellTiles + 0 * GRAPHIC_SIZE_4BPP(16, 16), .size = GRAPHIC_SIZE_4BPP(16, 16), .tag = 0},
	[4] = {gfx_ow_shellTiles + 0 * GRAPHIC_SIZE_4BPP(16, 16), .size = GRAPHIC_SIZE_4BPP(16, 16), .tag = 0},
	[5] = {gfx_ow_shellTiles + 1 * GRAPHIC_SIZE_4BPP(16, 16), .size = GRAPHIC_SIZE_4BPP(16, 16), .tag = 0},
	[6] = {gfx_ow_shellTiles + 2 * GRAPHIC_SIZE_4BPP(16, 16), .size = GRAPHIC_SIZE_4BPP(16, 16), .tag = 0},
	[7] = {gfx_ow_shellTiles + 3 * GRAPHIC_SIZE_4BPP(16, 16), .size = GRAPHIC_SIZE_4BPP(16, 16), .tag = 0},
	[8] = {gfx_ow_shellTiles + 4 * GRAPHIC_SIZE_4BPP(16, 16), .size = GRAPHIC_SIZE_4BPP(16, 16), .tag = 0},
	[9] = {gfx_ow_shellTiles + 5 * GRAPHIC_SIZE_4BPP(16, 16), .size = GRAPHIC_SIZE_4BPP(16, 16), .tag = 0},
};

static graphic overworld_gfx_trash[] = {
	[0] = {gfx_ow_trashTiles + 0 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[1] = {gfx_ow_trashTiles + 1 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[2] = {gfx_ow_trashTiles + 2 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[3] = {gfx_ow_trashTiles + 0 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[4] = {gfx_ow_trashTiles + 0 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
	[5] = {gfx_ow_trashTiles + 0 * GRAPHIC_SIZE_4BPP(16, 32), .size = GRAPHIC_SIZE_4BPP(16, 32), .tag = 0},
};

overworld_sprite overworld_mushroom_plucked = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_MUSHROOM,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 16), .width = 16, .height = 16,
        .final_oam = &ow_final_oam_16_16, .subsprite_table = &ow_formation_16_16, .gfx_animation = gfx_animations_mushroom,
        .graphics = overworld_gfx_mushrooms + 0, .rotscale_animation = oam_rotscale_anim_table_null, .inanimate = true,
};

overworld_sprite overworld_mushroom_tiny = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_MUSHROOM,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 16), .width = 16, .height = 16,
        .final_oam = &ow_final_oam_16_16, .subsprite_table = &ow_formation_16_16, .gfx_animation = gfx_animations_mushroom,
        .graphics = overworld_gfx_mushrooms + 2, .rotscale_animation = oam_rotscale_anim_table_null,
};

overworld_sprite overworld_mushroom_large = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_MUSHROOM,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 16), .width = 16, .height = 16,
        .final_oam = &ow_final_oam_16_16, .subsprite_table = &ow_formation_16_16, .gfx_animation = gfx_animations_mushroom,
        .graphics = overworld_gfx_mushrooms + 4, .rotscale_animation = oam_rotscale_anim_table_null,
};

overworld_sprite overworld_shell_empty = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_SHELL,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 16), .width = 16, .height = 16,
        .final_oam = &ow_final_oam_16_16, .subsprite_table = &ow_formation_16_16, .gfx_animation = gfx_animations_shell,
        .graphics = overworld_gfx_shells + 0, .rotscale_animation = oam_rotscale_anim_table_null, .inanimate = true,
};

overworld_sprite overworld_shell = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_SHELL,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 16), .width = 16, .height = 16,
        .final_oam = &ow_final_oam_16_16, .subsprite_table = &ow_formation_16_16, .gfx_animation = gfx_animations_shell,
        .graphics = overworld_gfx_shells + 5, .rotscale_animation = oam_rotscale_anim_table_null,
};

overworld_sprite overworld_trash_empty = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_TRASH,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
        .final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_trash + 1,
        .graphics = overworld_gfx_trash + 3, .rotscale_animation = oam_rotscale_anim_table_null, .inanimate = true,
};

overworld_sprite overworld_trash = {
		.tiles_tag= 0xFFFF, .pal_tag = OW_PAL_TAG_TRASH,
        .unknown = 0x11FF, .size = GRAPHIC_SIZE_4BPP(16, 32), .width = 16, .height = 32,
        .final_oam = &ow_final_oam_16_32, .subsprite_table = &ow_formation_16_32, .gfx_animation = gfx_animations_trash + 0,
        .graphics = overworld_gfx_trash, .rotscale_animation = oam_rotscale_anim_table_null,
};
palette overworld_mushroom_palette = {
    .pal = gfx_ow_mushroomPal, .tag = OW_PAL_TAG_MUSHROOM,
};

palette overworld_shell_palette = {
    .pal = gfx_ow_shellPal, .tag = OW_PAL_TAG_SHELL,
};

palette overworld_trash_palette = {
    .pal = gfx_ow_trashPal, .tag = OW_PAL_TAG_TRASH,
};

overworld_sprite *overworld_sprite_get_by_mushroom_idx(u16 mushroom_idx) {
    switch (mushroom_get_stage(mushroom_idx)) {
        default:
        case MUSHROOM_TYPE_PLUCKED:
            return &overworld_mushroom_plucked;
        case MUSHROOM_TYPE_TINY_MUSHROOM:
            return &overworld_mushroom_tiny;
        case MUSHROOM_TYPE_LARGE_MUSHROOM:
            return &overworld_mushroom_large;
    }
}

overworld_sprite *overworld_sprite_get_by_shell_idx(u16 shell_idx) {
    switch (shell_get_stage(shell_idx)) {
        case SHELL_TYPE_EMPTY:
            return &overworld_shell_empty;
        default:
            return &overworld_shell;
    }
}

overworld_sprite *overworld_sprite_get_by_trash_idx(u16 trash_idx) {
    dprintf("Trash can %d has type %d\n", trash_idx, trash_get_type(trash_idx));
    switch (trash_get_type(trash_idx)) {
        case TRASH_TYPE_EMPTY:
            return &overworld_trash_empty;
        default:
            return &overworld_trash;
    }
}

palette *overworld_palette_get_by_mushroom() {
    return &overworld_mushroom_palette;
}

palette *overworld_palette_get_by_shell() {
    return &overworld_shell_palette;
}

palette *overworld_palette_get_by_trash() {
    return &overworld_trash_palette;
}

#define DROPPING_DY 12
#define DROPPING_DT 24

 void misc_counter_overworld_oam_callback(oam_object *self) {
    u16 *frame = self->private + 7;
    if (*frame > DROPPING_DT) {
        self->y2 = 0;
        overworld_script_resume();
        self->callback = oam_null_callback;
        return;
    } else if (*frame == 0) {
    }
    // Sine for jumping
    FIXED t = INT_TO_FIXED(*frame);
    FIXED y = FIXED_SIN(FIXED_DIV(t, INT_TO_FIXED(DROPPING_DT  * 2)));
    y = FIXED_MUL(INT_TO_FIXED(DROPPING_DY), y);
    self->y2 = (s16)(-FIXED_TO_INT(y));
    ++*frame;
}

void special_misc_encounter_overworld_new() {
    coordinate_t faced_position = {0};
    position_t player_position = {0};
    player_get_facing_position(&faced_position.x, &faced_position.y);
    u8 direction = direction_get_opposite(player_get_facing());
    player_get_position(&player_position);
    u8 height = player_position.height;
    u16 species = *var_access(0x8004);
    map_event_person person = {0};
    person.overworld_index = overworld_get_sprite_idx_by_species(species);
    person.value = species;
    faced_position.x = (s16)(faced_position.x - 7);
    faced_position.y = (s16)(faced_position.y - 7);
    u8 oam_idx = overworld_create_oam_by_person(&person, 0, faced_position.x, faced_position.y, height, direction);
    oams[oam_idx].private[7] = 0;
    oams[oam_idx].callback = misc_counter_overworld_oam_callback;
}

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

static u32 trash_rates[] = {[TRASH_TYPE_WIND] = 2, [TRASH_TYPE_ITEM] = 3, [TRASH_TYPE_ENCOUNTER] = 2};

u16 trash_get_type(u16 trash_idx) {
    bool empty = trash_idx < 128 ? gp_flag_get(trash_idx, cmem.trash_flags) : gp_flag_get((u16)(trash_idx - 128), cmem.trash_flags2);
    if (empty) {
        return TRASH_TYPE_EMPTY;
    } else {
        u32 seq[1] = {trash_idx};
        gp_rng_seed(daily_events_hash(seq, ARRAY_COUNT(seq)));
        return (u16)choice(trash_rates, ARRAY_COUNT(trash_rates), gp_rnd16);
    }
}

u16 special_trash_get_type() {
    u16 type = trash_get_type(map_get_person((u8)(*var_access(LASTTALKED)), save1->map, save1->bank)->value);
    return type;
}

void trash_set_empty() {
    map_event_person *p = map_get_person((u8)(*var_access(LASTTALKED)), save1->map, save1->bank);
    u16 trash_idx = p->value;
    if (trash_idx < 128)
        gp_flag_set(trash_idx, cmem.trash_flags);
    else
        gp_flag_set((u16)(trash_idx - 128), cmem.trash_flags2);
}

void overworld_misc_intialize() {
    memset(cmem.mushroom_flags, 0, ARRAY_COUNT(cmem.mushroom_flags));
    memset(cmem.shell_flags, 0, ARRAY_COUNT(cmem.shell_flags));
    memset(cmem.trash_flags, 0, ARRAY_COUNT(cmem.trash_flags));
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

static u32 trash_encounters[] = {[POKEMON_SLEIMA] = 3, [POKEMON_SMOGON] = 2, [POKEMON_ZIGZACHS] = 2, [POKEMON_TEDDIURSA] = 1};
static u32 trash_items[] = {[ITEM_UEBERRESTE] = 1, [ITEM_MININUGGET] = 2, [ITEM_FLUCHTSEIL] = 10, [ITEM_POKEPUPPE] = 8, [ITEM_AETHER] = 5, 
    [ITEM_BITTERKRAUT] = 7, [ITEM_QUARZSTAUB] = 7, [ITEM_APFEL] = 15};

u16 trash_get_encounter_or_item() {
    map_event_person *p = map_get_person((u8)(*var_access(LASTTALKED)), save1->map, save1->bank);
    u16 trash_idx = p->value;
    u32 seq[1] = {trash_idx};
    gp_rng_seed(daily_events_hash(seq, ARRAY_COUNT(seq)));
    switch(trash_get_type(trash_idx)) {
        case TRASH_TYPE_ENCOUNTER:
            return (u16)choice(trash_encounters, ARRAY_COUNT(trash_encounters), gp_rnd16);
        case TRASH_TYPE_ITEM:
            return (u16)choice(trash_items, ARRAY_COUNT(trash_items), gp_rnd16);
        default:
            return 0;
    }
}

static u16 misc_feature_generator() {
    return (u16)(gp_rnd16() & 511);
}

void misc_encounter_setup() {
    pokemon_clear_opponent_party();
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
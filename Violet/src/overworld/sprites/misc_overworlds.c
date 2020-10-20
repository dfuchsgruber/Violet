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
#include "mushroom_and_shell.h"
#include "math.h"
#include "music.h"

static gfx_frame gfx_animation_mushroom_idle[] = {
	{.data = 0, .duration = 0}, {.data = 0, .duration = 32}, {.data = 1, .duration = 32}, {.data = GFX_ANIM_JUMP, .duration = 0},
};

static gfx_frame gfx_animation_shell_idle[] = {
	{.data = 0, .duration = 0}, {.data = 0, .duration = 12}, {.data = 1, .duration = 12}, 
    {.data = 2, .duration = 12}, {.data = 3, .duration = 12}, {.data = 4, .duration = 12},
    {.data = GFX_ANIM_JUMP, .duration = 0},
};

static gfx_frame *gfx_animations_mushroom[1] = {gfx_animation_mushroom_idle};

static gfx_frame *gfx_animations_shell[1] = {gfx_animation_shell_idle};

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

palette overworld_mushroom_palette = {
    .pal = gfx_ow_mushroomPal, .tag = OW_PAL_TAG_MUSHROOM,
};

palette overworld_shell_palette = {
    .pal = gfx_ow_shellPal, .tag = OW_PAL_TAG_SHELL,
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

palette *overworld_palette_get_by_mushroom() {
    return &overworld_mushroom_palette;
}

palette *overworld_palette_get_by_shell() {
    return &overworld_shell_palette;
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

#include "types.h"
#include "overworld/effect.h"
#include "overworld/sprite.h"
#include "overworld/script.h"
#include "oam.h"
#include "save.h"
#include "bios.h"
#include "flags.h"
#include "debug.h"
#include "map/bluetenbach_gym.h"
#include "save.h"

static bluetenbach_gym_rotating_wall_t bluetenbach_gym_rotating_walls[] = {
    {.anchor_x = 0x8, .anchor_y = 0xC, .is_l_shape = false, .rotation = 3},
    {.anchor_x = 0xd, .anchor_y = 0xa, .is_l_shape = true, .rotation = 3},
};

static graphic rotating_walls_graphic = {
    .sprite = gfx_tileset_bluetenbach_gym_rotating_wallsTiles, .tag = BLUTENBACH_GYM_ROTATING_WALL_TAG, .size = GRAPHIC_SIZE_4BPP(64, 64) * 4,
};

static sprite rotating_walls_oam_attributes = {
    .attr0 = ATTR0_SHAPE_SQUARE,
    .attr1 = ATTR1_SIZE_64_64,
    .attr2 = ATTR2_PRIO(1),
};

static gfx_frame rotating_wall_animation[] = {
    {.data = 0 * 8 * 8, .duration = 0}, {.data = GFX_ANIM_END},
    {.data = 1 * 8 * 8, .duration = 0}, {.data = GFX_ANIM_END},
    {.data = 2 * 8 * 8, .duration = 0}, {.data = GFX_ANIM_END},
    {.data = 3 * 8 * 8, .duration = 0}, {.data = GFX_ANIM_END},
};

static gfx_frame *rotating_wall_animations[] = {
    rotating_wall_animation + 0, rotating_wall_animation + 2, rotating_wall_animation + 4, rotating_wall_animation + 6,
};

static coordinate_t rotating_wall_coordinate_offsets[4] = {
    {32, -16},
    {32, -16},
    {0, -16},
    {32, 16},
};

static coordinate_t rotating_wall_coordinate_offsets_l_shape[4] = {
    {32, -16},
    {-16, -16},
    {-16, 32},
    {32, 16},
};

static u8 rotating_wall_gfx_animation_idxs[4] = {0, 1, 0, 1};
static u8 rotating_wall_hflips[4] = {false, false, false, false};
static u8 rotating_wall_gfx_animation_idxs_l_shape[4] = {2, 2, 3, 3};
static u8 rotating_wall_hflips_l_shape[4] = {false, true, true, false};

static void rotating_wall_callback(oam_object *self) {
    int idx = self->private[0];
    u8 rotation = (u8)((bluetenbach_gym_rotating_walls[idx].rotation + cmem.bluetenbach_gym_rotating_wall_orientations[idx]) % 4);
    map_position_to_oam_position((s16)(bluetenbach_gym_rotating_walls[idx].anchor_x + 7), (s16)(bluetenbach_gym_rotating_walls[idx].anchor_y + 7), &self->x, &self->y);
    u8 anim_idx, hflip;
    if (bluetenbach_gym_rotating_walls[idx].is_l_shape) {
        self->x = (s16)(self->x + rotating_wall_coordinate_offsets[rotation].x);
        self->y = (s16)(self->y + rotating_wall_coordinate_offsets[rotation].y);
        anim_idx = rotating_wall_gfx_animation_idxs[rotation];
        hflip = rotating_wall_hflips[rotation];
    } else {
        self->x = (s16)(self->x + rotating_wall_coordinate_offsets_l_shape[rotation].x);
        self->y = (s16)(self->y + rotating_wall_coordinate_offsets_l_shape[rotation].y);
        anim_idx = rotating_wall_gfx_animation_idxs_l_shape[rotation];
        hflip = rotating_wall_hflips_l_shape[rotation];
    }
    oam_gfx_anim_start_if_not_current(self, anim_idx);
    oam_flip(self, hflip, false);
}

static oam_template rotating_wall_template = {
    .tiles_tag = BLUTENBACH_GYM_ROTATING_WALL_TAG, .pal_tag = BLUTENBACH_GYM_ROTATING_WALL_TAG,
    .oam = &rotating_walls_oam_attributes,
    .animation = rotating_wall_animations,
    .rotscale = oam_rotscale_anim_table_null,
    .callback = rotating_wall_callback,
};

static void rotating_walls_initialize() {
    u8 pal_idx = oam_allocate_palette(BLUTENBACH_GYM_ROTATING_WALL_TAG);
    pal_decompress(gfx_tileset_bluetenbach_gym_rotating_wallsPal, (u16)(256 + 16 * pal_idx), 16 * sizeof(color_t));
    pal_apply_shaders_by_oam_palette_idx(pal_idx);
    oam_load_graphic(&rotating_walls_graphic);
    for (u8 i = 0; i < ARRAY_COUNT(bluetenbach_gym_rotating_walls); i++) {
        u8 oam_idx = oam_new_forward_search(&rotating_wall_template, 0, 0, 1);
        oams[oam_idx].flags |= OAM_FLAG_CENTERED;
        oams[oam_idx].private[0] = i;
        oam_gfx_anim_start(oams + oam_idx, 0);
        oams[oam_idx].callback(oams + oam_idx);
    }
}

void tileset_bluetenbach_gym_animation_initialize() {
    rotating_walls_initialize();
}
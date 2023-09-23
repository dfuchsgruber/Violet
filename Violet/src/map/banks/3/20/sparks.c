#include "types.h"
#include "map/cloud.h"
#include "oam.h"
#include "debug.h"
#include "overworld/sprite.h"
#include "overworld/effect.h"
#include "map/header.h"
#include "save.h"
#include "agbmemory.h"
#include "constants/block_behaviour.h"

#define OAM_TAG_SPARKS 1449
#define POWER_PLANT_BANK 3
#define POWER_PLANT_MAP_IDX 20

extern u8 gfx_overworld_effect_sparksTiles[];
extern u8 gfx_overworld_effect_sparks_verticalTiles[];
extern u8 gfx_overworld_effect_sparksPal[];

static const palette sparks_palette = {
    .pal = gfx_overworld_effect_sparksPal, .tag = OAM_TAG_SPARKS,
};

static const graphic sparks_graphics[] = {
    [0] = {.sprite = gfx_overworld_effect_sparksTiles + 0 * GRAPHIC_SIZE_4BPP(8, 32), .size = GRAPHIC_SIZE_4BPP(8, 32), .tag = 0xFFFF},
    [1] = {.sprite = gfx_overworld_effect_sparksTiles + 1 * GRAPHIC_SIZE_4BPP(8, 32), .size = GRAPHIC_SIZE_4BPP(8, 32), .tag = 0xFFFF},
};

static const graphic sparks_graphics_vertical[] = {
    [0] = {.sprite = gfx_overworld_effect_sparks_verticalTiles + 0 * GRAPHIC_SIZE_4BPP(8, 32), .size = GRAPHIC_SIZE_4BPP(8, 32), .tag = 0xFFFF},
    [1] = {.sprite = gfx_overworld_effect_sparks_verticalTiles + 1 * GRAPHIC_SIZE_4BPP(8, 32), .size = GRAPHIC_SIZE_4BPP(8, 32), .tag = 0xFFFF},
};

static const gfx_frame sparks_gfx_animation[] = {
    {.data = 0, .duration = 0}, {.data = 0, .duration = 8}, {.data = 1, .duration = 8}, {.data = GFX_ANIM_JUMP, .duration = 1},
};

static const gfx_frame *const sparks_gfx_animations[] = {sparks_gfx_animation};

static const sprite sparks_sprite = {.attr0 = ATTR0_SHAPE_HORIZONTAL, .attr1 = ATTR1_SIZE_32_8, .attr2 = ATTR2_PRIO(1)};
static const sprite sparks_sprite_vertical = {.attr0 = ATTR0_SHAPE_VERTICAL, .attr1 = ATTR1_SIZE_8_32, .attr2 = ATTR2_PRIO(1)};

static void oam_callback_sparks(oam_object *self) {
    if (save1->bank != POWER_PLANT_BANK || save1->map != POWER_PLANT_MAP_IDX) {
        oam_free(self);
        return;
    }
    s16 *x = (s16*)(self->private + 0);
    s16 *y = (s16*)(self->private + 1);
    // Since the sprite is centered, use half the circle 
    if (overworld_effect_is_oam_outside_camera_view(*x, *y, 32, 32)) {
        self->flags |= OAM_FLAG_INVISIBLE;
    } else {
        self->flags &= (u16)(~OAM_FLAG_INVISIBLE);
        map_position_to_oam_position(*x, *y, &self->x, &self->y);
        // Center at block
        if (self->private[2]) {
            self->x = (s16)(self->x + 8 + self->private[3]);
            self->y = (s16)(self->y + 16 + self->private[4]);
        } else {
            self->x = (s16)(self->x + 16 + self->private[3]);
            self->y = (s16)(self->y + 4 + self->private[4]);
        }
    }
}

static const oam_template sparks_templates[2] =  {
    {
        .tiles_tag = 0xFFFF, .pal_tag = OAM_TAG_SPARKS,
        .graphics = sparks_graphics,
        .oam = &sparks_sprite, .animation = sparks_gfx_animations,
        .rotscale = oam_rotscale_anim_table_null, .callback = oam_callback_sparks,
    },{
        .tiles_tag = 0xFFFF, .pal_tag = OAM_TAG_SPARKS,
        .graphics = sparks_graphics_vertical,
        .oam = &sparks_sprite_vertical, .animation = sparks_gfx_animations,
        .rotscale = oam_rotscale_anim_table_null, .callback = oam_callback_sparks,
    },
};

static const coordinate_t sparks_positions[] = {
    {.x = 0xe, .y = 0x17}, {.x = 0xe, .y = 0x14}, {.x = 0xc, .y = 0x15},
    {.x = 0x11, .y = 0x15}, {.x = 0xb, .y = 0xa}, {.x = 0xc, .y = 0xa},
    {.x = 0xb, .y = 0xb}, {.x = 0xc, .y = 0xb}, {.x = 0x14, .y = 0xc},
    {.x = 0x14, .y = 0xd}, {.x = 0xd, .y = 0x15}, {.x = 0x10, .y = 0x15}
};

static u8 sparks_vertical[ARRAY_COUNT(sparks_positions)] = {
    [2] = 1, [3] = 1, [10] = 1, [11] = 1,
};

static s16 x_displacements[ARRAY_COUNT(sparks_positions)] = {
    [8] = 8, [9] = 8,
};

static s16 y_displacements[ARRAY_COUNT(sparks_positions)] = {
    [8] = 12, [9] = 8,
};

static void sparks_initialize() {
    oam_palette_load_if_not_present_and_apply_shaders(&sparks_palette);
    for (u8 i = 0; i < ARRAY_COUNT(sparks_positions); i++) {
        u8 oam_idx = oam_new_forward_search(&sparks_templates[sparks_vertical[i]], 0, 0, 1);
        oams[oam_idx].flags |= OAM_FLAG_CENTERED;
        oams[oam_idx].private[0] = (u16)(sparks_positions[i].x + 7);
        oams[oam_idx].private[1] = (u16)(sparks_positions[i].y + 7);
        oams[oam_idx].private[2] = sparks_vertical[i];
        oams[oam_idx].private[3] = (u16) x_displacements[i];
        oams[oam_idx].private[4] = (u16) y_displacements[i];
        oam_gfx_anim_start(oams + oam_idx, 0);
        oams[oam_idx].callback(oams + oam_idx);
    }
}

void tileset_power_plant_animation_init() {
    sparks_initialize();
}
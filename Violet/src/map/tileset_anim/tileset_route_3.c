#include "types.h"
#include "overworld/effect.h"
#include "overworld/sprite.h"
#include "oam.h"
#include "save.h"

extern const u8 gfx_tileset_route_3_millTiles[];
extern const u8 gfx_tileset_route_3_millPal[];

#define ROUTE_3_MILL_TAG 0x888
#define ROUTE_3_BANK 15
#define ROUTE_3_MAP 0
#define ROUTE_3_X 0x2D + 7 
#define ROUTE_3_Y 0x7 + 7 

static const graphic route_3_mill_graphic = {
    .sprite = gfx_tileset_route_3_millTiles, .tag = ROUTE_3_MILL_TAG, .size = GRAPHIC_SIZE_4BPP(64, 64),
};

static const rotscale_frame route_3_mill_rotscale_animation[] = {
    {.affine = {.rotation = 1, .duration = 0xff}}, {.command = {.command = ROTSCALE_ANIM_JUMP, .parameter = 0}}, 
};

static const rotscale_frame *const route_3_mill_rotscale_animations[] = {route_3_mill_rotscale_animation};

static const sprite route_3_mill_final_oam = {
    .attr0 = ATTR0_DSIZE | ATTR0_ROTSCALE | ATTR0_SHAPE_SQUARE,
    .attr1 = ATTR1_SIZE_64_64,
    .attr2 = ATTR2_PRIO(1),
};

static void oam_callback_route_3_mill(oam_object *self) {
    if (save1->bank != ROUTE_3_BANK || save1->map != ROUTE_3_MAP) {
        oam_free(self);
        return;
    }
    // Since the sprite is centered, use half the circle 
    if (overworld_effect_is_oam_outside_camera_view(ROUTE_3_X, ROUTE_3_Y, 91 / 2, 91 / 2)) {
        self->flags |= OAM_FLAG_INVISIBLE;
    } else {
        self->flags &= (u16)(~OAM_FLAG_INVISIBLE);
        map_position_to_oam_position(ROUTE_3_X, ROUTE_3_Y, &self->x, &self->y);
        // Center at block
        self->x = (s16)(self->x + 8);
        self->y = (s16)(self->y + 8);
    }
}

static const oam_template route_3_mill_oam_template = {
    .tiles_tag = ROUTE_3_MILL_TAG, .pal_tag = ROUTE_3_MILL_TAG,
    .oam = &route_3_mill_final_oam,
    .animation = oam_gfx_anim_table_null,
    .rotscale = route_3_mill_rotscale_animations,
    .callback = oam_callback_route_3_mill,
};

void tileset_route_3_animation_initialize() {
    u8 pal_idx = oam_allocate_palette(ROUTE_3_MILL_TAG);
    pal_decompress(gfx_tileset_route_3_millPal, (u16)(256 + 16 * pal_idx), 16 * sizeof(color_t));
    pal_apply_shaders_by_oam_palette_idx(pal_idx);
    oam_load_graphic(&route_3_mill_graphic);
    u8 oam_idx = oam_new_forward_search(&route_3_mill_oam_template, 0, 0, 1);
    oams[oam_idx].flags |= OAM_FLAG_CENTERED;
    oams[oam_idx].callback(oams + oam_idx);
}
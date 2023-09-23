#include "types.h"
#include "map/tileset.h"
#include "overworld/effect.h"
#include "overworld/sprite.h"
#include "oam.h"
#include "save.h"

#define KASKADA_TEA_HOUSE_SMOKE_TAG 0x88A
#define KASKADA_TEA_HOUSE_BANK 8
#define KASKADA_TEA_HOUSE_MAP_IDX 12

extern const u16 gfx_maptileset_kaskada_tea_house_light_animTiles[];
extern const u8 gfx_maptileset_kaskada_tea_house_smokeTiles[];
extern const u8 gfx_maptileset_kaskada_tea_house_smokePal[];

static const graphic smoke_graphic = {
    .sprite = gfx_maptileset_kaskada_tea_house_smokeTiles, .tag = KASKADA_TEA_HOUSE_SMOKE_TAG, .size = GRAPHIC_SIZE_4BPP(16, 16) * 4,
};

static const sprite smoke_final_oam = {
    .attr0 = ATTR0_SHAPE_SQUARE,
    .attr1 = ATTR1_SIZE_16_16,
    .attr2 = ATTR2_PRIO(1),
};

static void oam_callback_smoke(oam_object *self) {
    if (save1->bank != KASKADA_TEA_HOUSE_BANK || save1->map != KASKADA_TEA_HOUSE_MAP_IDX) {
        oam_free(self);
        return;
    }
    s16 *x = (s16*)(self->private + 0);
    s16 *y = (s16*)(self->private + 1);
    // Since the sprite is centered, use half the circle 
    if (overworld_effect_is_oam_outside_camera_view(*x, *y, 16, 16)) {
        self->flags |= OAM_FLAG_INVISIBLE;
    } else {
        self->flags &= (u16)(~OAM_FLAG_INVISIBLE);
        map_position_to_oam_position(*x, *y, &self->x, &self->y);
        // Center at block
        self->x = (s16)(self->x + 8);
        self->y = (s16)(self->y + 8 - 8); // Offset it a bit above the mug...
    }
}

static const gfx_frame gfx_anim_smoke[] = {
    {.data = 0, .duration = 0}, {.data = 0, .duration = 16}, {.data = 4, .duration = 16}, {.data = 8, .duration = 16}, {.data = 12, .duration = 16}, {.data = GFX_ANIM_JUMP, .duration = 1},
};

static const gfx_frame *const gfx_anims_smoke[] = {gfx_anim_smoke};

static const oam_template smoke_template = {
    .tiles_tag = KASKADA_TEA_HOUSE_SMOKE_TAG, .pal_tag = KASKADA_TEA_HOUSE_SMOKE_TAG,
    .oam = &smoke_final_oam,
    .animation = gfx_anims_smoke,
    .rotscale = oam_rotscale_anim_table_null,
    .callback = oam_callback_smoke,
};

static const coordinate_t smoke_positions[] = {
    {.x = 2, .y = 7}, {.x = 0xA, .y = 7}, {.x = 9, .y = 3},
};

static void smoke_initialize() {
    u8 pal_idx = oam_allocate_palette(KASKADA_TEA_HOUSE_SMOKE_TAG);
    pal_decompress(gfx_maptileset_kaskada_tea_house_smokePal, (u16)(256 + 16 * pal_idx), 16 * sizeof(color_t));
    pal_apply_shaders_by_oam_palette_idx(pal_idx);
    oam_load_graphic(&smoke_graphic);
    for (u8 i = 0; i < ARRAY_COUNT(smoke_positions); i++) {
        u8 oam_idx = oam_new_forward_search(&smoke_template, 0, 0, 1);
        oams[oam_idx].flags |= OAM_FLAG_CENTERED;
        oams[oam_idx].private[0] = (u16)(smoke_positions[i].x + 7);
        oams[oam_idx].private[1] = (u16)(smoke_positions[i].y + 7);
        oam_gfx_anim_start(oams + oam_idx, 0);
        oams[oam_idx].callback(oams + oam_idx);
    }
}

static const tileset_animation tileset_kaskada_tea_house_animations[] = {
    {
		.cycle = 4, .speed = 32, .start_tile = 0x330, .num_tiles = 9,
		.gfx = gfx_maptileset_kaskada_tea_house_light_animTiles
    }
};

static const tileset_animation_header tileset_kaskada_tea_house_animations_head = {
    1, tileset_kaskada_tea_house_animations
};


void tileset_kaskada_tea_house_anim(u16 clk){
    generic_tileset_anim_proceed_all(&tileset_kaskada_tea_house_animations_head, clk);
}

void tileset_kaskada_tea_house_anim_init(){
    tileset_anim_clk1_cycle = generic_tileset_anim_get_clk(&tileset_kaskada_tea_house_animations_head);
    tileset_anim_1 = tileset_kaskada_tea_house_anim;
    smoke_initialize();
}


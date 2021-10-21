#include "bios.h"
#include "debug.h"
#include "flags.h"
#include "oam.h"
#include "overworld/effect.h"
#include "overworld/script.h"
#include "overworld/sprite.h"
#include "save.h"
#include "types.h"

extern u8 gfx_ow_bbshipPal[];

#define OAM_TAG_BB_SHIP 0x6666

static palette palette_bb_ship = {
    .pal = gfx_ow_bbshipPal,
    .tag = OAM_TAG_BB_SHIP,
};

static sprite final_oam_bb_ship = {
    .attr0 = ATTR0_SHAPE_HORIZONTAL,
    .attr1 = ATTR1_SIZE_64_32,
    .attr2 = ATTR2_PRIO(2),
};

static void oam_callback_bb_ship(oam_object *self) {
    if (save1->bank != self->private[2] || save1->map != self->private[3]) {
        oam_free(self);
        return;
    }
    s16 *privates = (s16 *)(self->private);
    s16 x = privates[0];
    s16 y = privates[1];
    // Since the sprite is centered, use half the circle
    if (overworld_effect_is_oam_outside_camera_view(x, y, 128, 64)) {
        self->flags |= OAM_FLAG_INVISIBLE;
    } else {
        self->flags &= (u16)(~OAM_FLAG_INVISIBLE);
        map_position_to_oam_position(x, y, &self->x, &self->y);
        // Center at block
        self->x = (s16)(self->x + 8 + privates[4]);
        self->y = (s16)(self->y + 8 + privates[5]);
        oam_set_subpriority_by_height(self, 0, 20);
    }
}

static oam_template template_bb_ship = {
    .tiles_tag = OAM_TAG_BB_SHIP,
    .pal_tag = OAM_TAG_BB_SHIP,
    .oam = &final_oam_bb_ship,
    .animation = oam_gfx_anim_table_null,
    .rotscale = oam_rotscale_anim_table_null,
    .callback = oam_callback_bb_ship,
};

static subsprite subsprites_bb_ship[4] = {
    {
        .x = -64,
        .y = -32,
        .shape = 1,
        .size = 3,
        .tile_offset = 0 * (64 / 8) * (32 / 8),
        .priority = 2,
    },
    {
        .x = 0,
        .y = -32,
        .shape = 1,
        .size = 3,
        .tile_offset = 1 * (64 / 8) * (32 / 8),
        .priority = 2,
    },
    {
        .x = -64,
        .y = 0,
        .shape = 1,
        .size = 3,
        .tile_offset = 2 * (64 / 8) * (32 / 8),
        .priority = 3,
    },
    {
        .x = 0,
        .y = 0,
        .shape = 1,
        .size = 3,
        .tile_offset = 3 * (64 / 8) * (32 / 8),
        .priority = 3,
    },
};

static subsprite_table subsprite_table_bb_ship = {
    .num_subsprites = ARRAY_COUNT(subsprites_bb_ship),
    .subsprites = subsprites_bb_ship,
};

u8 overworld_blackbeard_ship_new_at(s16 x, s16 y, s16 dx, s16 dy, u8 bank, u8 map) {
    if (oam_vram_get_tile(OAM_TAG_BB_SHIP) == 0xFFFF) {
        u16 tile = oam_vram_alloc(64 / 8 * 128 / 8);
        oam_vram_allocation_table_add(OAM_TAG_BB_SHIP, tile, 64 / 8 * 128 / 8);
        if (tile == 0xFFFF)
            return ARRAY_COUNT(oams);
        cpuset(gfx_ow_bbshipTiles, OAMCHARBASE(tile), CPUSET_COPY | CPUSET_HALFWORD | CPUSET_HALFWORD_SIZE(GRAPHIC_SIZE_4BPP(128, 64)));
    }
    oam_palette_load_if_not_present_and_apply_shaders(&palette_bb_ship);
    u8 oam_idx = oam_new_forward_search(&template_bb_ship, 0, 0, 31);
    if (oam_idx >= ARRAY_COUNT(oams))
        return ARRAY_COUNT(oams);
    oam_set_subsprite_table(oams + oam_idx, &subsprite_table_bb_ship);
    s16 *privates = (s16 *)oams[oam_idx].private;
    privates[0] = x;
    privates[1] = y;
    privates[2] = bank;
    privates[3] = map;
    privates[4] = dx;
    privates[5] = dy;
    oams[oam_idx].flags |= OAM_FLAG_CENTERED;
    oams[oam_idx].callback(oams + oam_idx);
    return oam_idx;
};

#define LAPIS_CAVE_BB_SHIP_BANK 8
#define LAPIS_CAVE_BB_SHIP_MAP_IDX 11
#define LAPIS_CAVE_BB_SHIP_X 0x1e + 7
#define LAPIS_CAVE_BB_SHIP_Y 0xb + 7

void tileset_lapis_cave_animations_initialize() {
    if (save1->bank == LAPIS_CAVE_BB_SHIP_BANK && save1->map == LAPIS_CAVE_BB_SHIP_MAP_IDX && !checkflag(KASKADA_BLACKMARET_BB_SHIP)) {
        fmem.blackbeard_ship_oam_idx = overworld_blackbeard_ship_new_at(LAPIS_CAVE_BB_SHIP_X, LAPIS_CAVE_BB_SHIP_Y, 0, -4, LAPIS_CAVE_BB_SHIP_BANK, LAPIS_CAVE_BB_SHIP_MAP_IDX);
    }
}

static void oam_callback_move_left(oam_object *self) {
    s16 *privates = (s16 *)(self->private);
    if (++privates[7] <= 12 * 16) {
        privates[4]--;
        //dprintf("Privates 4 is %d\n", privates[4]);
        oam_callback_bb_ship(self);
    } else {
        oam_free(self);
        overworld_script_resume();
    }
}

void blackbeard_ship_move_left() {
    oams[fmem.blackbeard_ship_oam_idx].callback = oam_callback_move_left;
}

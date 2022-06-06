#include "types.h"
#include "oam.h"
#include "item/bag2.h"

graphic bag_graphic_bag = {.sprite = gfx_bag2Tiles, .size = 8 * GRAPHIC_SIZE_4BPP(64, 64), .tag = BAG_OAM_TAG};
graphic bag_graphic_insert_bar = {.sprite = gfx_bag_insert_barTiles, .size = 2 * GRAPHIC_SIZE_4BPP(16, 16), .tag = BAG_INSERT_OAM_TAG};

static sprite bag_sprite = {.attr0 = ATTR0_SHAPE_SQUARE | ATTR0_ROTSCALE | ATTR0_DSIZE, .attr1 = ATTR1_SIZE_64_64, .attr2 = ATTR2_PRIO(1)};

static gfx_frame bag_anim_idle[] = {{.data = 0, .duration = 0}, {.data = GFX_ANIM_END}};
static gfx_frame bag_anim_items[] = {{.data = 64 * 3, .duration = 0}, {.data = GFX_ANIM_END}};
static gfx_frame bag_anim_key_items[] = {{.data = 64 * 5, .duration = 0}, {.data = GFX_ANIM_END}};
static gfx_frame bag_anim_pokeballs[] = {{.data = 64 * 1, .duration = 0}, {.data = GFX_ANIM_END}};
static gfx_frame bag_anim_berries[] = {{.data = 64 * 2, .duration = 0}, {.data = GFX_ANIM_END}};
static gfx_frame bag_anim_medicine[] = {{.data = 64 * 4, .duration = 0}, {.data = GFX_ANIM_END}};
static gfx_frame bag_anim_bait[] = {{.data = 64 * 6, .duration = 0}, {.data = GFX_ANIM_END}};
static gfx_frame bag_anim_tms[] = {{.data = 64 * 7, .duration = 0}, {.data = GFX_ANIM_END}};

static gfx_frame *bag_anims[] = {
    [POCKET_NONE] = bag_anim_idle,
    [POCKET_ITEMS] = bag_anim_items,
    [POCKET_KEY_ITEMS] = bag_anim_key_items,
    [POCKET_POKEBALLS] = bag_anim_pokeballs,
    [POCKET_BERRIES] = bag_anim_berries,
    [POCKET_MEDICINE] = bag_anim_medicine,
    [POCKET_TM_HM] = bag_anim_tms,
    [POCKET_BAIT] = bag_anim_bait,
};

static rotscale_frame bag_rs_anim_idle[] = {
    {.affine = {.affine_x_value = 0x100, .affine_y_value = 0x100, .rotation = 0, .duration = 0}},
    {.command = {.command = ROTSCALE_ANIM_END}}
};

static rotscale_frame bag_rs_anim_wiggle[] = {
    {.affine = {.rotation = -2, .duration = 2}},
    {.affine = {.rotation = 2, .duration = 4}},
    {.affine = {.rotation = -2, .duration = 4}},
    {.affine = {.rotation = 2, .duration = 2}},
    {.command = {.command = ROTSCALE_ANIM_END}}
};

static rotscale_frame *bag_rs_anims[] = {
    bag_rs_anim_idle,
    bag_rs_anim_wiggle, 
};

oam_template bag_oam_template = {
    .tiles_tag = BAG_OAM_TAG, .pal_tag = BAG_OAM_TAG,
    .oam = &bag_sprite, .graphics = NULL, .animation = bag_anims,
    .rotscale = bag_rs_anims, .callback = oam_null_callback,
};

void bag_oam_switch_pockets_callback(oam_object *self) {
    if (self->y2 != 0)
        self->y2++;
    else
        self->callback = oam_null_callback;
}

void bag_oam_switch_pockets(u8 pocket) {
    oam_object *o = oams + BAG2_STATE->oam_idx_bag;
    o->y2 = -5;
    o->callback = bag_oam_switch_pockets_callback;
    oam_gfx_anim_start(o, pocket);
}

static sprite sprite_item = {.attr0 = ATTR0_SHAPE_SQUARE, .attr1 = ATTR1_SIZE_32_32, .attr2 = ATTR2_PRIO(1)};

oam_template bag_oam_template_item = {
    .tiles_tag = BAG_ITEM_OAM_TAG, .pal_tag = BAG_ITEM_OAM_TAG,
    .graphics = NULL, .oam = &sprite_item, .animation = oam_gfx_anim_table_null,
    .rotscale = oam_rotscale_anim_table_null, .callback = oam_null_callback,
};
#include "overworld/detector.h"
#include "bios.h"
#include "callbacks.h"
#include "debug.h"
#include "flags.h"
#include "math.h"
#include "oam.h"
#include "options.h"
#include "overworld/npc.h"
#include "overworld/script.h"
#include "overworld/sprite.h"
#include "save.h"
#include "tile/coordinate.h"
#include "types.h"

static sprite static_detector_arrow_sprite = {
    .attr0 = ATTR0_SHAPE_SQUARE | ATTR0_ROTSCALE | ATTR0_DSIZE,
    .attr1 = ATTR1_SIZE_16_16,
    .attr2 = ATTR2_PRIO(1),
};

static rotscale_frame static_detector_rs_anim[] = {
    {.affine = {.affine_x_value = 0x100, .affine_y_value = 0x100, .duration = 0}},
    {.command = {.command = ROTSCALE_ANIM_END}}};

static rotscale_frame *static_detector_rs_anims[] = {static_detector_rs_anim};

static graphic static_detector_graphics[] = {
    {.sprite = gfx_item_finder_arrow_staticTiles + 0 * GRAPHIC_SIZE_4BPP(16, 16), .size = GRAPHIC_SIZE_4BPP(16, 16), .tag = 0xFFFF},
    {.sprite = gfx_item_finder_arrow_staticTiles + 1 * GRAPHIC_SIZE_4BPP(16, 16), .size = GRAPHIC_SIZE_4BPP(16, 16), .tag = 0xFFFF},
    {.sprite = gfx_item_finder_arrow_staticTiles + 2 * GRAPHIC_SIZE_4BPP(16, 16), .size = GRAPHIC_SIZE_4BPP(16, 16), .tag = 0xFFFF},
    {.sprite = gfx_item_finder_arrow_staticTiles + 3 * GRAPHIC_SIZE_4BPP(16, 16), .size = GRAPHIC_SIZE_4BPP(16, 16), .tag = 0xFFFF},
    {.sprite = gfx_item_finder_arrow_staticTiles + 4 * GRAPHIC_SIZE_4BPP(16, 16), .size = GRAPHIC_SIZE_4BPP(16, 16), .tag = 0xFFFF},
    {.sprite = gfx_item_finder_arrow_staticTiles + 5 * GRAPHIC_SIZE_4BPP(16, 16), .size = GRAPHIC_SIZE_4BPP(16, 16), .tag = 0xFFFF},
    {.sprite = gfx_item_finder_arrow_staticTiles + 6 * GRAPHIC_SIZE_4BPP(16, 16), .size = GRAPHIC_SIZE_4BPP(16, 16), .tag = 0xFFFF},
    {.sprite = gfx_item_finder_arrow_staticTiles + 7 * GRAPHIC_SIZE_4BPP(16, 16), .size = GRAPHIC_SIZE_4BPP(16, 16), .tag = 0xFFFF},
    {.sprite = gfx_item_finder_arrow_staticTiles + 8 * GRAPHIC_SIZE_4BPP(16, 16), .size = GRAPHIC_SIZE_4BPP(16, 16), .tag = 0xFFFF},
};

static gfx_frame static_detector_frames[][2] = {
    {{.data = 0, .duration = 0}, {.data = GFX_ANIM_END}},
    {{.data = 1, .duration = 0}, {.data = GFX_ANIM_END}},
    {{.data = 2, .duration = 0}, {.data = GFX_ANIM_END}},
    {{.data = 3, .duration = 0}, {.data = GFX_ANIM_END}},
    {{.data = 4, .duration = 0}, {.data = GFX_ANIM_END}},
    {{.data = 5, .duration = 0}, {.data = GFX_ANIM_END}},
    {{.data = 6, .duration = 0}, {.data = GFX_ANIM_END}},
    {{.data = 7, .duration = 0}, {.data = GFX_ANIM_END}},
    {{.data = 8, .duration = 0}, {.data = GFX_ANIM_END}},
};

static gfx_frame *static_detector_animations[] = {
    static_detector_frames[0],
    static_detector_frames[1],
    static_detector_frames[2],
    static_detector_frames[3],
    static_detector_frames[4],
    static_detector_frames[5],
    static_detector_frames[6],
    static_detector_frames[7],
    static_detector_frames[8],
};

#define ARROW_SINE_PERIOD 64

static void static_detector_arrow_callback(oam_object *self) {
    if (!(self->flags & OAM_FLAG_INVISIBLE)) {
        self->x = oams[player_state.oam_idx].x;
        self->y = (s16)(oams[player_state.oam_idx].y - 10);
        self->private[0] = (u16)((self->private[0] + 1) % ARROW_SINE_PERIOD);
        FIXED theta = FIXED_DIV(INT_TO_FIXED(self->private[0]), INT_TO_FIXED(ARROW_SINE_PERIOD));
        self->y2 = (s16)FIXED_TO_INT(FIXED_MUL(FIXED_SIN(theta), INT_TO_FIXED(2)));
        if (self->private[3]) {
            oam_try_set_rotation_and_scale(self, true, 0x100, 0x100, 0);
            oam_gfx_anim_start_if_not_current(self, 4);
        } else {
            oam_try_set_rotation_and_scale(self, true, 0x100, 0x100, (u16)(self->private[1] + 0x8000));
            oam_gfx_anim_start_if_not_current(self, (u8)self->private[2]);
        }

        /*
        coordinate_t coords;
        player_get_coordinates(&coords.x, &coords.y);
        s16 oam_x = 0;
        s16 oam_y = 0;
        map_position_to_oam_position(coords.x, (s16)(coords.y - 1), &oam_x, &oam_y);
        dprintf("Player at %d.%d\n", coords.x, coords.y);
        self->x = (s16)(oam_x - 8);
        self->y = (s16)(oam_y - 8);
        */
    }
}

static palette static_detector_arrow_palette = {
    .pal = gfx_item_finder_arrow_staticPal,
    .tag = ITEM_FINDER_STATIC_TAG,
};

static oam_template static_detector_arrow_template = {
    .tiles_tag = 0xFFFF,
    .pal_tag = ITEM_FINDER_STATIC_TAG,
    .oam = &static_detector_arrow_sprite,
    .graphics = static_detector_graphics,
    .animation = static_detector_animations,
    .rotscale = static_detector_rs_anims,
    .callback = static_detector_arrow_callback,
};

u8 overworld_effect_static_detector_arrow_new() {

    oam_palette_load_if_not_present_and_apply_shaders(&static_detector_arrow_palette);
    u8 oam_idx = oam_new_backward_search(&static_detector_arrow_template, 0, 0, 0x53);
    if (oam_idx < 64) {
        oam_object *o = oams + oam_idx;
        o->flags |= OAM_FLAG_CENTERED | OAM_FLAG_INVISIBLE;
        oam_rotscale_anim_init(oams + oam_idx, 0);
    }
    return oam_idx;
}

void overworld_static_detector_callback(u8 self) {
    u16 *vars = big_callbacks[self].params;
    u8 oam_idx = (u8)vars[DETECTOR_CB_VAR_OAM_IDX_ARROW];
    if (oam_idx < 64 && checkflag(FLAG_DETECTOR) && options[OPTION_DETECTOR].getter() == DETECTOR_ON) {
        coordinate_t coords;
        player_get_coordinates(&coords.x, &coords.y);
        bool flag_based_update = false;
        if (vars[DETECTOR_CB_VAR_FLAG] && checkflag(vars[DETECTOR_CB_VAR_FLAG])) {
            flag_based_update = true;
            vars[DETECTOR_CB_VAR_FLAG] = 0;
        }
        if (coords.x != vars[DETECTOR_CB_VAR_X] || coords.y != vars[DETECTOR_CB_VAR_Y] ||
            save1->bank != vars[DETECTOR_CB_VAR_BANK] || save1->map != vars[DETECTOR_CB_VAR_MAP_IDX] || flag_based_update) { // Update detector
            // dprintf("Updating detector arrow for position %d.%d\n", coords.x, coords.y);
            vars[DETECTOR_CB_VAR_X] = (u16)coords.x;
            vars[DETECTOR_CB_VAR_Y] = (u16)coords.y;
            vars[DETECTOR_CB_VAR_BANK] = save1->bank;
            vars[DETECTOR_CB_VAR_MAP_IDX] = save1->map;
            if (hidden_item_is_within_player_range(mapheader_virtual.events, self)) {
                oams[oam_idx].flags &= (u16)(~OAM_FLAG_INVISIBLE);
                int dx_abs = ABS((s16)vars[HIDDEN_ITEM_CB_VAR_DX]);
                int dy_abs = ABS((s16)vars[HIDDEN_ITEM_CB_VAR_DY]);
                int max_distance = MAX(dx_abs, dy_abs);
                if (max_distance <= 1) {
                    oams[oam_idx].private[2] = 3; // Red color
                } else if (max_distance <= 2) {
                    oams[oam_idx].private[2] = 2; // Orange color
                } else if (max_distance <= 4) {
                    oams[oam_idx].private[2] = 1; // Yellow color
                } else {
                    oams[oam_idx].private[2] = 0; // White color
                }
                u8 direction = detector_get_hidden_item_direction((s16)vars[HIDDEN_ITEM_CB_VAR_DX], (s16)vars[HIDDEN_ITEM_CB_VAR_DY]);
                oams[oam_idx].private[3] = direction == ITEM_FINDER_ON_ITEM;
                if (checkflag(FLAG_DIRECTIONAL_DETECTOR)) {
                    // Precise direction
                    oams[oam_idx].private[1] = negative_arctan2((s16)vars[HIDDEN_ITEM_CB_VAR_DX], (s16)vars[HIDDEN_ITEM_CB_VAR_DY]);
                } else {
                    // dprintf("Direction is %d\n", direction);
                    // For now, we don't want an arrow at all, so we just have no rotscale
                    oams[oam_idx].private[1] = 0x8000;
                    if (oams[oam_idx].private[2] < 4) // Non-directional animation
                        oams[oam_idx].private[2] = (u16)(oams[oam_idx].private[2] + 5);
                    else if (oams[oam_idx].private[2] == 4) {
                        oams[oam_idx].private[2] = 8; // Don't show the star
                    }
                    oams[oam_idx].private[3] = 0;

                    /*
                    switch (direction) {
                        case ITEM_FINDER_NORTH:
                            oams[oam_idx].private[1] = 0xc000;
                            break;
                        case ITEM_FINDER_EAST:
                            oams[oam_idx].private[1] = 0x0000;
                            break;
                        case ITEM_FINDER_SOUTH:
                            oams[oam_idx].private[1] = 0x4000;
                            break;
                        case ITEM_FINDER_WEST:
                            oams[oam_idx].private[1] = 0x8000;
                            break;
                    }
                    */
                }
                // dprintf("Have found hidden item at %d.%d\n", vars[HIDDEN_ITEM_CB_VAR_DX], vars[HIDDEN_ITEM_CB_VAR_DY]);
            } else {
                oams[oam_idx].flags |= OAM_FLAG_INVISIBLE;
            }
        }
    }
}

void overworld_static_detector_issue_update_when_flag_set(u16 flag) {
    u8 cb_idx = big_callback_get_id(overworld_static_detector_callback);
    if (cb_idx != 0xFF) {
        big_callbacks[cb_idx].params[DETECTOR_CB_VAR_FLAG] = flag;
    }
}

#include "types.h"
#include "flags.h"
#include "oam.h"
#include "save.h"
#include "callbacks.h"
#include "tile/coordinate.h"
#include "debug.h"
#include "overworld/detector.h"
#include "overworld/sprite.h"
#include "flags.h"
#include "bios.h"
#include "overworld/npc.h"
#include "options.h"

static sprite static_detector_arrow_sprite = {
    .attr0 = ATTR0_SHAPE_SQUARE | ATTR0_ROTSCALE | ATTR0_DSIZE, .attr1 = ATTR1_SIZE_16_16, .attr2 = ATTR2_PRIO(1),
};

static rotscale_frame static_detector_rs_anim[] = {
    {.affine = {.affine_x_value = 0x100, .affine_y_value = 0x100, .duration = 0}},
    {.command = {.command = ROTSCALE_ANIM_END}}
}; 

static rotscale_frame *static_detector_rs_anims[] = {static_detector_rs_anim};

static void static_detector_arrow_callback(oam_object *self) {
    if (!(self->flags & OAM_FLAG_INVISIBLE)) {
        self->x = oams[player_state.oam_idx].x;
        self->y = (s16)(oams[player_state.oam_idx].y - 16);
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

static oam_template static_detector_arrow_template = {
    .tiles_tag = 0xFFFF, .pal_tag = 0xFFFF, .oam = &static_detector_arrow_sprite,
    .animation = oam_gfx_anim_table_null, .rotscale = static_detector_rs_anims, .callback = static_detector_arrow_callback,
};

u8 overworld_effect_static_detector_arrow_new() {
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
        if (coords.x != vars[DETECTOR_CB_VAR_X] || coords.y != vars[DETECTOR_CB_VAR_Y] || 
            save1->bank != vars[DETECTOR_CB_VAR_BANK] || save1->map != vars[DETECTOR_CB_VAR_MAP_IDX]) { // Update detector
            dprintf("Updating detector arrow for position %d.%d\n", coords.x, coords.y);
            vars[DETECTOR_CB_VAR_X] = (u16)coords.x;
            vars[DETECTOR_CB_VAR_Y] = (u16)coords.y;
            vars[DETECTOR_CB_VAR_BANK] = save1->bank;
            vars[DETECTOR_CB_VAR_MAP_IDX] = save1->map;
            if (hidden_item_is_within_player_range(mapheader_virtual.events, self)) {
                oams[oam_idx].flags &= (u16)(~OAM_FLAG_INVISIBLE);
                u16 angle = negative_arctan2((s16)vars[HIDDEN_ITEM_CB_VAR_DX], (s16)vars[HIDDEN_ITEM_CB_VAR_DY]);
                oam_try_set_rotation_and_scale(oams + oam_idx, true, 0x100, 0x100, angle);
                dprintf("Have found hidden item at %d.%d\n", vars[HIDDEN_ITEM_CB_VAR_DX], vars[HIDDEN_ITEM_CB_VAR_DY]);
            } else {
                oams[oam_idx].flags |= OAM_FLAG_INVISIBLE;
            }
        }
    }
}
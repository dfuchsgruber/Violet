#include "types.h"
#include "overworld/static_effect.h"
#include "save.h"
#include "oam.h"
#include "overworld/sprite.h"
#include "overworld/map_control.h"

static void overworld_static_effect_delete(int idx) {
    oam_delete(fmem.overworld_static_effects[idx].oam_idx);
    fmem.overworld_static_effects[idx].idx = 0xFF;
}

int overworld_static_effect_get(int idx, int bank, int map_idx) {
    for (int i = 0; i < ARRAY_COUNT(fmem.overworld_static_effects); i++) {
        overworld_static_effect_t *eff = fmem.overworld_static_effects + i;
        if (eff->bank == bank && eff->map_idx == map_idx && eff->idx == idx) {
            return i;
        }
    }
    return -1;
}

static void overworld_static_effect_oam_callback_hide_if_outside_viewport(oam_object *self) {
    int idx = overworld_static_effect_get(self->private[0], self->private[1] >> 8, self->private[1] & 0xFF);
    if (idx >= 0) {
        if (save1->bank != self->private[2] || save1->map != self->private[3]) {
            if (overworld_viewport.active) {
                self->private[2] = save1->bank;
                self->private[3] = save1->map;
                self->private[4] = (u16)(self->private[4] - overworld_viewport.x);
                self->private[5] = (u16)(self->private[5] - overworld_viewport.y);
            } else {
                oam_delete(self);
                return;
            }
    }

    }
}

static void overworld_static_effect_new(u8 idx, u8 bank, u8 map_idx, overworld_static_effect_template_t *template, s16 cam_x, s16 cam_y) {
    for (int j = 0; j < ARRAY_COUNT(fmem.overworld_static_effects); j++) {
        overworld_static_effect_t *effect = fmem.overworld_static_effects + j;
        if (effect->idx == OVERWORLD_STATIC_EFFECT_EMPTY) {
            u8 oam_idx = oam_new_backward_search(&template->template_, 0, 0, 0x94);
            if (oam_idx == NUM_OAMS)
                return;
            s16 x = (s16)(template->x + 7 + cam_x);
            s16 y = (s16)(template->y + 7 + cam_y);
            oam_object *oam = oams + oam_idx;
            oam->flags |= OAM_FLAG_CENTERED;
            oam->private[0] = idx;
            oam->private[1] = (u16)(map_idx | (bank << 8));
            oam->private[2] = (u16)(template->x + 7);
            oam->private[3] = (u16)(template->y + 7);
            map_position_to_oam_position(x, y, &oam->x, &oam->y);
            overworld_static_effect_oam_callback_hide_if_outside_viewport(oam);

            oam_palette_load_if_not_present_and_apply_shaders(&template->uncompressed_palette);
            effect->bank = bank;
            effect->map_idx = map_idx;
            effect->idx = idx;
            effect->collision = template->collision;
            effect->width = template->width;
            effect->height = template->height;
            effect->oam_idx = oam_idx;
        }
    }
    
}

void overworld_static_effect_create_within_viewport(s16 camera_dx, s16 camera_dy) {
    int left = save1->x_cam_orig - 2;
    int right = save1->x_cam_orig + 7 + 2;
    int upper = save1->y_cam_orig - 2;
    int lower = save1->y_cam_orig + 7 + 2;
    for (size_t i = 0; i < fmem.overworld_num_static_effect_templates; i++) {
        overworld_static_effect_template_t *t = fmem.overworld_static_effect_templates + i;
        int x = t->x + 7;
        int y = t->y + 7;
        if (x >= left && x <= right && y >= upper && y <= lower) {
            if (overworld_static_effect_get((u8)i, save1->bank, save1->map) < 0) {
                overworld_static_effect_new((u8)i, save1->bank, save1->map, t, camera_dx, camera_dy);
            }
        }
    }
}

void overworld_static_effect_delete_outside_viewport() {
    int left = save1->x_cam_orig - 2;
    int right = save1->x_cam_orig + 7 + 2;
    int upper = save1->y_cam_orig - 2;
    int lower = save1->y_cam_orig + 7 + 2;
    for (size_t i = 0; i < ARRAY_COUNT(fmem.overworld_static_effects); i++) {
        overworld_static_effect_t *eff = fmem.overworld_static_effects + i;
        int x = eff->x + 7;
        int y = eff->y + 7;
        if (x < left || x > right || y < upper || y > lower) {
            oam_delete(oams + eff->oam_idx);
            // Replace the current effect with the tail of the effect list (dont increment i therefore)
            *eff = *(fmem.overworld_static_effects + --fmem.overworld_num_static_effects);
        } else {
            i++;
        }
    }
}

void overworld_static_effects_initialize() {
    for (int i = 0; i < ARRAY_COUNT(fmem.overworld_static_effects); i++)
        fmem.overworld_static_effects[i].idx = 0xFF;
    overworld_static_effect_create_within_viewport(0, 0);
}
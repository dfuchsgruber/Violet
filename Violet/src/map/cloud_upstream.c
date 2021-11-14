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
#include "overworld/map_control.h"

extern u8 gfx_overworld_cloud_upstreamTiles[];
extern u8 gfx_overworld_cloud_upstreamPal[];

static palette overworld_cloud_upstream_palette = {
    .pal = gfx_overworld_cloud_upstreamPal, .tag = OAM_TAG_CLOUD_UPSTREAM,
};

static graphic overworld_cloud_upstream_graphics[] = {
    // Over npcs
    [0] = {.sprite = gfx_overworld_cloud_upstreamTiles + 0 * GRAPHIC_SIZE_4BPP(64, 32), .size = GRAPHIC_SIZE_4BPP(64, 32), .tag = 0xFFFF},
    [1] = {.sprite = gfx_overworld_cloud_upstreamTiles + 1 * GRAPHIC_SIZE_4BPP(64, 32), .size = GRAPHIC_SIZE_4BPP(64, 32), .tag = 0xFFFF},
    [2] = {.sprite = gfx_overworld_cloud_upstreamTiles + 2 * GRAPHIC_SIZE_4BPP(64, 32), .size = GRAPHIC_SIZE_4BPP(64, 32), .tag = 0xFFFF},
    [3] = {.sprite = gfx_overworld_cloud_upstreamTiles + 3 * GRAPHIC_SIZE_4BPP(64, 32), .size = GRAPHIC_SIZE_4BPP(64, 32), .tag = 0xFFFF},
    [4] = {.sprite = gfx_overworld_cloud_upstreamTiles + 4 * GRAPHIC_SIZE_4BPP(64, 32), .size = GRAPHIC_SIZE_4BPP(64, 32), .tag = 0xFFFF},
    [5] = {.sprite = gfx_overworld_cloud_upstreamTiles + 5 * GRAPHIC_SIZE_4BPP(64, 32), .size = GRAPHIC_SIZE_4BPP(64, 32), .tag = 0xFFFF},
    [6] = {.sprite = gfx_overworld_cloud_upstreamTiles + 6 * GRAPHIC_SIZE_4BPP(64, 32), .size = GRAPHIC_SIZE_4BPP(64, 32), .tag = 0xFFFF},
    [7] = {.sprite = gfx_overworld_cloud_upstreamTiles + 7 * GRAPHIC_SIZE_4BPP(64, 32), .size = GRAPHIC_SIZE_4BPP(64, 32), .tag = 0xFFFF},
    [8] = {.sprite = gfx_overworld_cloud_upstreamTiles + 8 * GRAPHIC_SIZE_4BPP(64, 32), .size = GRAPHIC_SIZE_4BPP(64, 32), .tag = 0xFFFF},
    // Empty
    [9] = {.sprite = gfx_overworld_cloud_upstreamTiles + 9 * GRAPHIC_SIZE_4BPP(64, 32), .size = GRAPHIC_SIZE_4BPP(64, 32), .tag = 0xFFFF},
    // Behind npcs
    [10] = {.sprite = gfx_overworld_cloud_upstreamTiles + 10 * GRAPHIC_SIZE_4BPP(64, 32), .size = GRAPHIC_SIZE_4BPP(64, 32), .tag = 0xFFFF},
    [11] = {.sprite = gfx_overworld_cloud_upstreamTiles + 11 * GRAPHIC_SIZE_4BPP(64, 32), .size = GRAPHIC_SIZE_4BPP(64, 32), .tag = 0xFFFF},
    [12] = {.sprite = gfx_overworld_cloud_upstreamTiles + 12 * GRAPHIC_SIZE_4BPP(64, 32), .size = GRAPHIC_SIZE_4BPP(64, 32), .tag = 0xFFFF},
    [13] = {.sprite = gfx_overworld_cloud_upstreamTiles + 13 * GRAPHIC_SIZE_4BPP(64, 32), .size = GRAPHIC_SIZE_4BPP(64, 32), .tag = 0xFFFF},
    [14] = {.sprite = gfx_overworld_cloud_upstreamTiles + 14 * GRAPHIC_SIZE_4BPP(64, 32), .size = GRAPHIC_SIZE_4BPP(64, 32), .tag = 0xFFFF},
    [15] = {.sprite = gfx_overworld_cloud_upstreamTiles + 15 * GRAPHIC_SIZE_4BPP(64, 32), .size = GRAPHIC_SIZE_4BPP(64, 32), .tag = 0xFFFF},
    [16] = {.sprite = gfx_overworld_cloud_upstreamTiles + 16 * GRAPHIC_SIZE_4BPP(64, 32), .size = GRAPHIC_SIZE_4BPP(64, 32), .tag = 0xFFFF},
    [17] = {.sprite = gfx_overworld_cloud_upstreamTiles + 17 * GRAPHIC_SIZE_4BPP(64, 32), .size = GRAPHIC_SIZE_4BPP(64, 32), .tag = 0xFFFF},
    [18] = {.sprite = gfx_overworld_cloud_upstreamTiles + 18 * GRAPHIC_SIZE_4BPP(64, 32), .size = GRAPHIC_SIZE_4BPP(64, 32), .tag = 0xFFFF},
};

static sprite sprite_cloud_upstream_prio_1 = {.attr0 = ATTR0_SHAPE_HORIZONTAL, .attr1 = ATTR1_SIZE_64_32, .attr2 = ATTR2_PRIO(1)};
static sprite sprite_cloud_upstream_prio_2 = {.attr0 = ATTR0_SHAPE_HORIZONTAL, .attr1 = ATTR1_SIZE_64_32, .attr2 = ATTR2_PRIO(2)};
static sprite sprite_cloud_upstream_controller = {.attr0 = ATTR0_SHAPE_SQUARE, .attr1 = ATTR1_SIZE_8_8, .attr2 = ATTR2_PRIO(2)};

static bool cloud_upstream_hide(oam_cloud_upstream_state_t *state) {
    if (overworld_effect_is_oam_outside_camera_view(state->x, (s16)(state->y), 64, 64)) {
        for(int i = 0; i < CLOUD_UPSTREAM_NUM_OAMS; i++) {
            for (int j = 0; j < 2; j++)
                oams[state->oam_idxs[i][j]].flags |= OAM_FLAG_INVISIBLE;
        }
        return true;
    } else {
        for (int i = 0; i < CLOUD_UPSTREAM_NUM_OAMS; i++) {
            for (int j = 0; j < 2; j++)
                oams[state->oam_idxs[i][j]].flags &= (u16)(~OAM_FLAG_INVISIBLE);
        }
        return false;
    }
}

static void cloud_upstream_clear(oam_cloud_upstream_state_t *state) {
    for (int i = CLOUD_UPSTREAM_NUM_OAMS - 1; i >= 0; i--) {
        for (int j = 1; j >= 0; j--)
            oam_delete(oams + state->oam_idxs[i][j]);
    }
    oam_delete(oams + state->oam_idx_controller);
    free(state);
}

static bool cloud_upstream_clear_if_not_on_map(oam_cloud_upstream_state_t *state) {
    if (save1->bank != state->bank || save1->map != state->map_idx) {
        cloud_upstream_clear(state);
        return true;
    }
    return false;
}

static inline bool cloud_upstream_waiting(oam_cloud_upstream_state_t *state) {
    // Proceed held y-movements for the oams
    if (state->y_movement_delay++ >= 1) {
        state->y_movement_delay = 0;
        for (int i = 0; i < CLOUD_UPSTREAM_NUM_OAMS; i++) {
            for (int j = 0; j < 2; j++) {
                if (oams[state->oam_idxs[i][j]].private[0]) {
                    oams[state->oam_idxs[i][j]].private[0]--;
                    oams[state->oam_idxs[i][j]].y2--;
                }
            }
        }
    }
    if (state->delay) {
        --(state->delay);
        return true;
    }
    return false;
}

static void oam_callback_cloud_upstream_update_position(oam_object *self) {
    self->x = (s16)self->private[4];
    self->y = (s16)self->private[5];
    self->callback = oam_null_callback;
}

static void oam_callback_cloud_upstream_step0(oam_object *self);
static void oam_callback_cloud_upstream_step1(oam_object *self);
static void oam_callback_cloud_upstream_step2(oam_object *self);
static void oam_callback_cloud_upstream_step3(oam_object *self);
static void oam_callback_cloud_upstream_step4(oam_object *self);
static void oam_callback_cloud_upstream_step5(oam_object *self);
static void oam_callback_cloud_upstream_step6(oam_object *self);
static void oam_callback_cloud_upstream_step7(oam_object *self);
static void oam_callback_cloud_upstream_step8(oam_object *self);
static void oam_callback_cloud_upstream_step9(oam_object *self);
static void oam_callback_cloud_upstream_step10(oam_object *self);

static void oam_callback_cloud_upstream_step0(oam_object *self) {
    oam_cloud_upstream_state_t *state = (oam_cloud_upstream_state_t *)(self->private[0] | (self->private[1] << 16));
    if (cloud_upstream_clear_if_not_on_map(state))
        return;
    if (!cloud_upstream_hide(state) && !cloud_upstream_waiting(state)) { // Upstream effect is active
        s16 x = 0; s16 y = 0; // Anchor position for all oams
        map_position_to_oam_position(state->x, state->y, &x, &y);
        for (int j = 0; j < 2; j++) {
            // Hide mid and bottom
            oam_gfx_anim_start(oams + state->oam_idxs[CLOUD_UPSTREAM_MID][j], CLOUD_UPSTREAM_ANIM_NO_RING);
            oam_gfx_anim_start(oams + state->oam_idxs[CLOUD_UPSTREAM_TOP][j], CLOUD_UPSTREAM_ANIM_NO_RING);
            // The bottom ring starts appearing
            oams[state->oam_idxs[CLOUD_UPSTREAM_BOTTOM][j]].y = (s16)(y + 12);
            oams[state->oam_idxs[CLOUD_UPSTREAM_BOTTOM][j]].x = (s16)(x + 16 - 8);
        }
        oam_gfx_anim_start(oams + state->oam_idxs[CLOUD_UPSTREAM_BOTTOM][0], CLOUD_UPSTREAM_ANIM_BIG_RING);
        oam_gfx_anim_start(oams + state->oam_idxs[CLOUD_UPSTREAM_BOTTOM][1], CLOUD_UPSTREAM_ANIM_BIG_RING_BG);
        state->delay = 16;
        self->callback = oam_callback_cloud_upstream_step1;
    }
}

static void oam_callback_cloud_upstream_step1(oam_object *self) {
    oam_cloud_upstream_state_t *state = (oam_cloud_upstream_state_t *)(self->private[0] | (self->private[1] << 16));
    if (cloud_upstream_clear_if_not_on_map(state))
        return;
    if (!cloud_upstream_hide(state) && !cloud_upstream_waiting(state)) { // Upstream effect is active
        s16 x = 0; s16 y = 0; // Anchor position for all oams
        map_position_to_oam_position(state->x, state->y, &x, &y);
        for (int j = 0; j < 2; j++) {
            oams[state->oam_idxs[CLOUD_UPSTREAM_MID][j]].y = (s16)(y + 8);
            oams[state->oam_idxs[CLOUD_UPSTREAM_MID][j]].x = (s16)(x + 16 - 8);
        }
        oam_gfx_anim_start(oams + state->oam_idxs[CLOUD_UPSTREAM_MID][0], CLOUD_UPSTREAM_ANIM_NORMAL_RING);
        oam_gfx_anim_start(oams + state->oam_idxs[CLOUD_UPSTREAM_MID][1], CLOUD_UPSTREAM_ANIM_NORMAL_RING_BG);
        oams[state->oam_idxs[CLOUD_UPSTREAM_MID][0]].private[0] = 2;
        oams[state->oam_idxs[CLOUD_UPSTREAM_MID][1]].private[0] = 2;
        state->delay = 4;
        self->callback = oam_callback_cloud_upstream_step2;
    }
}

static void oam_callback_cloud_upstream_step2(oam_object *self) {
    oam_cloud_upstream_state_t *state = (oam_cloud_upstream_state_t *)(self->private[0] | (self->private[1] << 16));
    if (cloud_upstream_clear_if_not_on_map(state))
        return;
    if (!cloud_upstream_hide(state) && !cloud_upstream_waiting(state)) { // Upstream effect is active
        s16 x = 0; s16 y = 0; // Anchor position for all oams
        map_position_to_oam_position(state->x, state->y, &x, &y);
        for (int j = 0; j < 2; j++) {
            oams[state->oam_idxs[CLOUD_UPSTREAM_TOP][j]].y = (s16)(y + 4);
            oams[state->oam_idxs[CLOUD_UPSTREAM_TOP][j]].x = (s16)(x + 16 - 8);
        }
        oam_gfx_anim_start(oams + state->oam_idxs[CLOUD_UPSTREAM_TOP][0], CLOUD_UPSTREAM_ANIM_SMALL_RING);
        oam_gfx_anim_start(oams + state->oam_idxs[CLOUD_UPSTREAM_TOP][1], CLOUD_UPSTREAM_ANIM_SMALL_RING_BG);
        oams[state->oam_idxs[CLOUD_UPSTREAM_TOP][0]].private[0] = 4;
        oams[state->oam_idxs[CLOUD_UPSTREAM_TOP][1]].private[0] = 4;
        state->delay = 4;
        self->callback = oam_callback_cloud_upstream_step3;
    }
}

static void oam_callback_cloud_upstream_step3(oam_object *self) {
    oam_cloud_upstream_state_t *state = (oam_cloud_upstream_state_t *)(self->private[0] | (self->private[1] << 16));
    if (cloud_upstream_clear_if_not_on_map(state))
        return;
    if (!cloud_upstream_hide(state) && !cloud_upstream_waiting(state)) { // Upstream effect is activeCLOUD_UPSTREAM_TOP_2
        s16 x = 0; s16 y = 0; // Anchor position for all oams
        map_position_to_oam_position(state->x, state->y, &x, &y);
        for (int j = 0; j < 2; j++) {
            oams[state->oam_idxs[CLOUD_UPSTREAM_TOP_2][j]].y = (s16)(y - 2);
            oams[state->oam_idxs[CLOUD_UPSTREAM_TOP_2][j]].x = (s16)(x + 16 - 8);
        }
        oam_gfx_anim_start(oams + state->oam_idxs[CLOUD_UPSTREAM_TOP_2][0], CLOUD_UPSTREAM_ANIM_SMALL_RING);
        oam_gfx_anim_start(oams + state->oam_idxs[CLOUD_UPSTREAM_TOP_2][1], CLOUD_UPSTREAM_ANIM_SMALL_RING_BG);
        oams[state->oam_idxs[CLOUD_UPSTREAM_TOP_2][0]].private[0] = 4;
        oams[state->oam_idxs[CLOUD_UPSTREAM_TOP_2][1]].private[0] = 4;
        state->delay = 12;
        self->callback = oam_callback_cloud_upstream_step4;
    }
}

static void oam_callback_cloud_upstream_step4(oam_object *self) {
    oam_cloud_upstream_state_t *state = (oam_cloud_upstream_state_t *)(self->private[0] | (self->private[1] << 16));
    if (cloud_upstream_clear_if_not_on_map(state))
        return;
    if (!cloud_upstream_hide(state) && !cloud_upstream_waiting(state)) { // Upstream effect is active
        s16 x = 0; s16 y = 0; // Anchor position for all oams
        map_position_to_oam_position(state->x, state->y, &x, &y);
        for (int j = 0; j < 2; j++) {
            oams[state->oam_idxs[CLOUD_UPSTREAM_BOTTOM][j]].private[5] = (u16)(y - 10);
            oams[state->oam_idxs[CLOUD_UPSTREAM_BOTTOM][j]].private[4] = (u16)(x + 16 - 8);
            oams[state->oam_idxs[CLOUD_UPSTREAM_BOTTOM][j]].callback = oam_callback_cloud_upstream_update_position;
        }
        oam_gfx_anim_start(oams + state->oam_idxs[CLOUD_UPSTREAM_BOTTOM][0], CLOUD_UPSTREAM_ANIM_NORMAL_RING);
        oam_gfx_anim_start(oams + state->oam_idxs[CLOUD_UPSTREAM_BOTTOM][1], CLOUD_UPSTREAM_ANIM_NORMAL_RING_BG);
        oams[state->oam_idxs[CLOUD_UPSTREAM_BOTTOM][0]].private[0] = 4;
        oams[state->oam_idxs[CLOUD_UPSTREAM_BOTTOM][1]].private[0] = 4;
        state->delay = 4;
        self->callback = oam_callback_cloud_upstream_step5;
    }
}

static void oam_callback_cloud_upstream_step5(oam_object *self) {
    oam_cloud_upstream_state_t *state = (oam_cloud_upstream_state_t *)(self->private[0] | (self->private[1] << 16));
    if (cloud_upstream_clear_if_not_on_map(state))
        return;
    if (!cloud_upstream_hide(state) && !cloud_upstream_waiting(state)) { // Upstream effect is active
        s16 x = 0; s16 y = 0; // Anchor position for all oams
        map_position_to_oam_position(state->x, state->y, &x, &y);
        for (int j = 0; j < 2; j++) {
            oams[state->oam_idxs[CLOUD_UPSTREAM_MID][j]].private[5] = (u16)(y - 16);
            oams[state->oam_idxs[CLOUD_UPSTREAM_MID][j]].private[4] = (u16)(x + 16 - 8);
            oams[state->oam_idxs[CLOUD_UPSTREAM_MID][j]].callback = oam_callback_cloud_upstream_update_position;
        }
        oam_gfx_anim_start(oams + state->oam_idxs[CLOUD_UPSTREAM_MID][0], CLOUD_UPSTREAM_ANIM_BIG_RING);
        oam_gfx_anim_start(oams + state->oam_idxs[CLOUD_UPSTREAM_MID][1], CLOUD_UPSTREAM_ANIM_BIG_RING_BG);
        oams[state->oam_idxs[CLOUD_UPSTREAM_MID][0]].private[0] = 8;
        oams[state->oam_idxs[CLOUD_UPSTREAM_MID][1]].private[0] = 8;
        state->delay = 24;
        self->callback = oam_callback_cloud_upstream_step6;
    }
}

static void oam_callback_cloud_upstream_step6(oam_object *self) {
    oam_cloud_upstream_state_t *state = (oam_cloud_upstream_state_t *)(self->private[0] | (self->private[1] << 16));
    if (cloud_upstream_clear_if_not_on_map(state))
        return;
    if (!cloud_upstream_hide(state) && !cloud_upstream_waiting(state)) { // Upstream effect is active
        oam_gfx_anim_start(oams + state->oam_idxs[CLOUD_UPSTREAM_TOP][0], CLOUD_UPSTREAM_ANIM_NO_RING);
        oam_gfx_anim_start(oams + state->oam_idxs[CLOUD_UPSTREAM_TOP][1], CLOUD_UPSTREAM_ANIM_NO_RING);
        state->delay = 8;
        self->callback = oam_callback_cloud_upstream_step7;
    }
}

static void oam_callback_cloud_upstream_step7(oam_object *self) {
    oam_cloud_upstream_state_t *state = (oam_cloud_upstream_state_t *)(self->private[0] | (self->private[1] << 16));
    if (cloud_upstream_clear_if_not_on_map(state))
        return;
    if (!cloud_upstream_hide(state) && !cloud_upstream_waiting(state)) { // Upstream effect is active
        oam_gfx_anim_start(oams + state->oam_idxs[CLOUD_UPSTREAM_TOP_2][0], CLOUD_UPSTREAM_ANIM_NO_RING);
        oam_gfx_anim_start(oams + state->oam_idxs[CLOUD_UPSTREAM_TOP_2][1], CLOUD_UPSTREAM_ANIM_NO_RING);
        state->delay = 8;
        self->callback = oam_callback_cloud_upstream_step8;
    }
}

static void oam_callback_cloud_upstream_step8(oam_object *self) {
    oam_cloud_upstream_state_t *state = (oam_cloud_upstream_state_t *)(self->private[0] | (self->private[1] << 16));
    if (cloud_upstream_clear_if_not_on_map(state))
        return;
    if (!cloud_upstream_hide(state) && !cloud_upstream_waiting(state)) { // Upstream effect is active
        oam_gfx_anim_start(oams + state->oam_idxs[CLOUD_UPSTREAM_BOTTOM][0], CLOUD_UPSTREAM_ANIM_NO_RING);
        oam_gfx_anim_start(oams + state->oam_idxs[CLOUD_UPSTREAM_BOTTOM][1], CLOUD_UPSTREAM_ANIM_NO_RING);
        state->delay = 8;
        self->callback = oam_callback_cloud_upstream_step9;
    }
}

static void oam_callback_cloud_upstream_step9(oam_object *self) {
    oam_cloud_upstream_state_t *state = (oam_cloud_upstream_state_t *)(self->private[0] | (self->private[1] << 16));
    if (cloud_upstream_clear_if_not_on_map(state))
        return;
    if (!cloud_upstream_hide(state) && !cloud_upstream_waiting(state)) { // Upstream effect is active
        oam_gfx_anim_start(oams + state->oam_idxs[CLOUD_UPSTREAM_MID][0], CLOUD_UPSTREAM_ANIM_NO_RING);
        oam_gfx_anim_start(oams + state->oam_idxs[CLOUD_UPSTREAM_MID][1], CLOUD_UPSTREAM_ANIM_NO_RING);
        state->delay = 24;
        self->callback = oam_callback_cloud_upstream_step10;
    }
}

static void oam_callback_cloud_upstream_step10(oam_object *self) {
    oam_cloud_upstream_state_t *state = (oam_cloud_upstream_state_t *)(self->private[0] | (self->private[1] << 16));
    if (cloud_upstream_clear_if_not_on_map(state))
        return;
    if (!cloud_upstream_hide(state) && !cloud_upstream_waiting(state)) { // Upstream effect is active
        for (int i = 0; i < CLOUD_UPSTREAM_NUM_OAMS; i++) {
            for (int j = 0; j < 2; j++) {
                oams[state->oam_idxs[i][j]].private[0] = 0;
                oams[state->oam_idxs[i][j]].y2 = 0;
            }
        }
        // self->callback = oam_callback_cloud_upstream_step0;
        if (state->contunation)
            state->contunation();
        cloud_upstream_clear(state);
    }
}

static gfx_frame overworld_cloud_upstream_animation_big_ring[] = {
    {.data = 0, .duration = 0}, 
    // Small ring
    {.data = 0, .duration = 4}, {.data = 1, .duration = 4}, {.data = 2, .duration = 4}, {.data = 1, .duration = 4  | GFX_ANIM_HFLIP},
    // Normal ring
    {.data = 3, .duration = 4}, {.data = 4, .duration = 4}, {.data = 5, .duration = 4}, {.data = 4, .duration = 4  | GFX_ANIM_HFLIP},
    // Big ring
    {.data = 6, .duration = 4}, {.data = 7, .duration = 4}, {.data = 8, .duration = 4}, {.data = 7, .duration = 4  | GFX_ANIM_HFLIP},
    {.data = GFX_ANIM_JUMP, .duration = 9},
};

static gfx_frame overworld_cloud_upstream_animation_big_ring_bg[] = {
    {.data = 10, .duration = 0}, 
    // Small ring
    {.data = 10, .duration = 4}, {.data = 11, .duration = 4}, {.data = 12, .duration = 4}, {.data = 11, .duration = 4  | GFX_ANIM_HFLIP},
    // Normal ring
    {.data = 13, .duration = 4}, {.data = 14, .duration = 4}, {.data = 15, .duration = 4}, {.data = 14, .duration = 4  | GFX_ANIM_HFLIP},
    // Big ring
    {.data = 16, .duration = 4}, {.data = 17, .duration = 4}, {.data = 18, .duration = 4}, {.data = 17, .duration = 4  | GFX_ANIM_HFLIP},
    {.data = GFX_ANIM_JUMP, .duration = 9},
};

static gfx_frame overworld_cloud_upstream_animation_normal_ring[] = {
    {.data = 3, .duration = 0}, 
    // Small ring
    {.data = 0, .duration = 4}, {.data = 1, .duration = 4}, {.data = 2, .duration = 4}, {.data = 1, .duration = 4  | GFX_ANIM_HFLIP},
    // Normal ring
    {.data = 3, .duration = 4}, {.data = 4, .duration = 4}, {.data = 5, .duration = 4}, {.data = 4, .duration = 4  | GFX_ANIM_HFLIP},
    {.data = GFX_ANIM_JUMP, .duration = 5},
};

static gfx_frame overworld_cloud_upstream_animation_normal_ring_bg[] = {
    {.data = 13, .duration = 0}, 
    // Small ring
    {.data = 10, .duration = 4}, {.data = 11, .duration = 4}, {.data = 12, .duration = 4}, {.data = 11, .duration = 4  | GFX_ANIM_HFLIP},
    // Normal ring
    {.data = 13, .duration = 4}, {.data = 14, .duration = 4}, {.data = 15, .duration = 4}, {.data = 14, .duration = 4  | GFX_ANIM_HFLIP},
    {.data = GFX_ANIM_JUMP, .duration = 5},
};

static gfx_frame overworld_cloud_upstream_animation_small_ring[] = {
    {.data = 3, .duration = 0}, 
    // Small ring
    {.data = 0, .duration = 4}, {.data = 1, .duration = 4}, {.data = 2, .duration = 4}, {.data = 1, .duration = 4  | GFX_ANIM_HFLIP},
    {.data = GFX_ANIM_JUMP, .duration = 1},
};

static gfx_frame overworld_cloud_upstream_animation_small_ring_bg[] = {
    {.data = 13, .duration = 0}, 
    // Small ring
    {.data = 10, .duration = 4}, {.data = 11, .duration = 4}, {.data = 12, .duration = 4}, {.data = 11, .duration = 4  | GFX_ANIM_HFLIP},
    {.data = GFX_ANIM_JUMP, .duration = 1},
};

static gfx_frame overworld_cloud_upstream_animation_static_upstream[] = {
    {.data = 3, .duration = 0}, 
    // Small ring
    {.data = 0, .duration = 4}, {.data = 1, .duration = 4}, {.data = 2, .duration = 4}, {.data = 1, .duration = 4  | GFX_ANIM_HFLIP},
    {.data = 0, .duration = 4}, {.data = 1, .duration = 4}, {.data = 2, .duration = 4}, {.data = 1, .duration = 4  | GFX_ANIM_HFLIP},
    {.data = 9, .duration = 32},
    {.data = GFX_ANIM_JUMP, .duration = 1},
};

static gfx_frame overworld_cloud_upstream_animation_static_upstream_bg[] = {
    {.data = 3, .duration = 0}, 
    // Small ring
    {.data = 10, .duration = 4}, {.data = 11, .duration = 4}, {.data = 12, .duration = 4}, {.data = 11, .duration = 4  | GFX_ANIM_HFLIP},
    {.data = 10, .duration = 4}, {.data = 11, .duration = 4}, {.data = 12, .duration = 4}, {.data = 11, .duration = 4  | GFX_ANIM_HFLIP},
    {.data = 9, .duration = 32},
    {.data = GFX_ANIM_JUMP, .duration = 1},
};

static gfx_frame overworld_cloud_upstream_animation_no_ring[] = {
    {.data = 9, .duration = 0}, {.data = GFX_ANIM_END}
}; 

static gfx_frame *overworld_cloud_upstream_animations[] = {
    [CLOUD_UPSTREAM_ANIM_BIG_RING] = overworld_cloud_upstream_animation_big_ring,
    [CLOUD_UPSTREAM_ANIM_NORMAL_RING] = overworld_cloud_upstream_animation_normal_ring,
    [CLOUD_UPSTREAM_ANIM_SMALL_RING] = overworld_cloud_upstream_animation_small_ring,
    [CLOUD_UPSTREAM_ANIM_NO_RING] = overworld_cloud_upstream_animation_no_ring,
    [CLOUD_UPSTREAM_ANIM_BIG_RING_BG] = overworld_cloud_upstream_animation_big_ring_bg,
    [CLOUD_UPSTREAM_ANIM_NORMAL_RING_BG] = overworld_cloud_upstream_animation_normal_ring_bg,
    [CLOUD_UPSTREAM_ANIM_SMALL_RING_BG] = overworld_cloud_upstream_animation_small_ring_bg,
    [CLOUD_UPSTREAM_ANIM_STATIC] = overworld_cloud_upstream_animation_static_upstream,
    [CLOUD_UPSTREAM_ANIM_STATIC_BG] = overworld_cloud_upstream_animation_static_upstream_bg,
};

static void overworld_cloud_static_upstream_callback (oam_object *self) {
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
    s16 oam_x = 0; s16 oam_y = 0; // Anchor position for all oams
    map_position_to_oam_position((s16)(self->private[4]), (s16)(self->private[5]), &oam_x, &oam_y);
    self->x = (s16)(oam_x + 16 - 8);
    self->y = (s16)(oam_y + self->private[6] * 6);

    if (overworld_effect_is_oam_outside_camera_view((s16)self->private[4], (s16)self->private[5], 64, 32)) {
        self->flags |= OAM_FLAG_INVISIBLE;
    } else {
        self->flags &= (u16)(~OAM_FLAG_INVISIBLE);
    }
}

static oam_template overworld_cloud_upstream_oam_templates[] = {
    {
        .tiles_tag = 0xFFFF, .pal_tag = OAM_TAG_CLOUD_UPSTREAM,
        .graphics = overworld_cloud_upstream_graphics,
        .oam = &sprite_cloud_upstream_prio_1, .animation = overworld_cloud_upstream_animations,
        .rotscale = oam_rotscale_anim_table_null, .callback = oam_null_callback,
    },
    {
        .tiles_tag = 0xFFFF, .pal_tag = OAM_TAG_CLOUD_UPSTREAM,
        .graphics = overworld_cloud_upstream_graphics,
        .oam = &sprite_cloud_upstream_prio_2, .animation = overworld_cloud_upstream_animations,
        .rotscale = oam_rotscale_anim_table_null, .callback = oam_null_callback,
    },
    {
        .tiles_tag = 0xFFFF, .pal_tag = 0xFFFF,
        .graphics = overworld_cloud_upstream_graphics,
        .oam = &sprite_cloud_upstream_controller, .animation = oam_gfx_anim_table_null,
        .rotscale = oam_rotscale_anim_table_null, .callback = oam_callback_cloud_upstream_step0,
    }
};

oam_cloud_upstream_state_t *map_cloud_upstream_whirlwind_at(s16 x, s16 y) {
    oam_palette_load_if_not_present_and_apply_shaders(&overworld_cloud_upstream_palette);
    oam_cloud_upstream_state_t *state = malloc_and_clear(sizeof(oam_cloud_upstream_state_t));
    dprintf("Upstream at %d, %d: state allocated @0x%x\n", x, y, state);
    for (u8 i = 0; i < CLOUD_UPSTREAM_NUM_OAMS; i++) {
        for (int j = 0; j < 2; j++) {
            u8 oam_idx = oam_new_backward_search(&overworld_cloud_upstream_oam_templates[j], 0, 0, 200);
            state->oam_idxs[i][j] = oam_idx;
            oams[oam_idx].flags |= OAM_FLAG_CENTERED;
            oam_gfx_anim_start(oams + oam_idx, CLOUD_UPSTREAM_ANIM_NO_RING);
        }
    }
    state->x = (s16)(x + 7);
    state->y = (s16)(y + 7);
    state->bank = save1->bank;
    state->map_idx = save1->map;
    state->delay = 0;
    // Create a controller oam
    state->oam_idx_controller = oam_new_forward_search(&overworld_cloud_upstream_oam_templates[2], 0, 0, 0);
    oams[state->oam_idx_controller].flags |= OAM_FLAG_INVISIBLE;
    oams[state->oam_idx_controller].private[0] = (u16)((int)state);
    oams[state->oam_idx_controller].private[1] = (u16)((int)state >> 16);
    oams[state->oam_idx_controller].callback(oams + state->oam_idx_controller);
    return state;
}

static void map_cloud_static_upstream_oam_callback_delayed_gfx_animation(oam_object *self) {
    if (self->private[0] > 0) {
        --self->private[0];
    } else {
        oam_gfx_anim_start(self, (u8)(self->private[1]));
        self->callback = overworld_cloud_static_upstream_callback;
    }
}


void map_cloud_static_upstream_new_at_position(s16 x, s16 y, u8 bank, u8 map_idx) {
    oam_palette_load_if_not_present_and_apply_shaders(&overworld_cloud_upstream_palette);
    for (u8 i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            u8 oam_idx = oam_new_forward_search(overworld_cloud_upstream_oam_templates + j, 0, 0, 200);
            oams[oam_idx].flags |= OAM_FLAG_CENTERED;
            u8 anim_idx = j == 1 ? CLOUD_UPSTREAM_ANIM_STATIC_BG : CLOUD_UPSTREAM_ANIM_STATIC;
            oams[oam_idx].private[6] = i;
            if (i == 1) {
                oam_gfx_anim_start(oams + oam_idx, anim_idx);
                oams[oam_idx].callback = overworld_cloud_static_upstream_callback;
            } else {
                oams[oam_idx].private[0] = 8;
                oams[oam_idx].private[1] = anim_idx;
                oam_gfx_anim_start(oams + oam_idx, CLOUD_UPSTREAM_ANIM_NO_RING);
                oams[oam_idx].callback = map_cloud_static_upstream_oam_callback_delayed_gfx_animation;
            }
            oams[oam_idx].private[2] = bank;
            oams[oam_idx].private[3] = map_idx;
            oams[oam_idx].private[4] = (u16)(x + 7);
            oams[oam_idx].private[5] = (u16)(y + 7);
        }
    }
}

void map_cloud_upstream_new() {
    // for (u8 i = 0; i < mapheader_virtual.events->warp_cnt; i++) {
    //     map_event_warp *warp = mapheader_virtual.events->warps + i;
    //     u16 behaviour = block_get_behaviour_by_pos((s16)(warp->x + 7), (s16)(warp->y + 7));
    //     if (behaviour == MB_CLOUD_UPSTREAM_WARP) {
    //         map_cloud_static_upstream_new_at_position((s16)(warp->x), (s16)(warp->y), save1->bank, save1->map);
    //     }
    // }
}
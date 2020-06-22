#include "types.h"
#include "io.h"
#include "oam.h"
#include "callbacks.h"
#include "superstate.h"
#include "crafting.h"
#include "bg.h"
#include "dma.h"
#include "agbmemory.h"
#include "bios.h"
#include "fading.h"
#include "prng.h"
#include "item/item.h"
#include "music.h"
#include "math.h"
#include "debug.h"

static void cauldron_scene_step1_create_dropping_item(u16 frame);

static bg_config cauldron_bg_configs[] = {
    {.bg_id = 1, .char_base = 0, .map_base = 29, .size = 0, .color_mode = 1, .priority = 1},
    {.bg_id = 2, .char_base = 1, .map_base = 30, .size = 0, .color_mode = 1, .priority = 2},
    {.bg_id = 3, .char_base = 2, .map_base = 31, .size = 0, .color_mode = 1, .priority = 3},
};

static void cauldron_bg_scrolling_proceed() {
    for (int i = 0; i < 4; i++) {
        u16 h_offset = (u16)(CAULDRON_SCENE_STATE->bg_horizontal_origin + CAULDRON_SCENE_STATE->bg_horizontal_scrolling[i]);
        u16 v_offset = (u16)(CAULDRON_SCENE_STATE->bg_vertical_origin + CAULDRON_SCENE_STATE->bg_vertical_scrolling[i]);
        io_set((u16)(IO_BGHOFS(i)), h_offset);
        io_set((u16)(IO_BGVOFS(i)), v_offset);
    }
}

static void cauldron_vblank_handler() {
    cauldron_bg_scrolling_proceed();
    generic_vblank_handler();
}

static graphic cauldron_lights_graphic = {
    .sprite = gfx_crafting_cauldron_lightsTiles, .tag = CAULDRON_LIGHT_TAG, .size = 6 * GRAPHIC_SIZE_4BPP(32, 32),
};

static gfx_frame cauldron_light_gfx_frames[] = {
    {.data = 0, .duration = 0}, {.data = GFX_ANIM_END},
    {.data = 16, .duration = 0}, {.data = GFX_ANIM_END},
    {.data = 32, .duration = 0}, {.data = GFX_ANIM_END},
    {.data = 48, .duration = 0}, {.data = GFX_ANIM_END},
    {.data = 64, .duration = 0}, {.data = GFX_ANIM_END},
    {.data = 80, .duration = 0}, {.data = GFX_ANIM_END},
};

static gfx_frame *cauldron_light_gfx_animations[] = {
    [0] = cauldron_light_gfx_frames + 0 * 2,
    [1] = cauldron_light_gfx_frames + 1 * 2,
    [2] = cauldron_light_gfx_frames + 2 * 2,
    [3] = cauldron_light_gfx_frames + 3 * 2,
    [4] = cauldron_light_gfx_frames + 4 * 2,
    [5] = cauldron_light_gfx_frames + 5 * 2,
};

enum {CAULDRON_LIGHT_CENTER = 0, CAULDRON_LIGHT_SIDE = 1};

static void cauldron_light_oam_callback (oam_object *self) {
    u16 *frame = self->private + 0;
    u16 type = self->private[1];
    u16 color = self->private[2];
    if (++*frame >= 3 * 32) {
        CAULDRON_SCENE_STATE->lights_number_active--;
        *frame = 0;
        oam_gfx_anim_start_if_not_current(self, (u8)(type * 3 + color));
    }
    self->y2 = (s16)(-CAULDRON_SCENE_STATE->bg_vertical_origin);
    self->x2 = (s16)(-CAULDRON_SCENE_STATE->bg_horizontal_origin);
}



static sprite cauldron_light_final_oam = {
    .attr0 = ATTR0_SHAPE_SQUARE, .attr1 = ATTR1_SIZE_32_32, .attr2 = ATTR2_PRIO(3),
};

static oam_template cauldron_light_oam_template = {
    .tiles_tag = CAULDRON_LIGHT_TAG, .pal_tag = CAULDRON_LIGHT_TAG, .oam = &cauldron_light_final_oam,
    .animation = cauldron_light_gfx_animations, .graphics = NULL, .rotscale = oam_rotscale_anim_table_null,
    .callback = cauldron_light_oam_callback
};

static sprite cauldron_item_final_oam = {
    .attr0 = ATTR0_DSIZE | ATTR0_SHAPE_SQUARE | ATTR0_ROTSCALE, .attr1 = ATTR1_SIZE_32_32, .attr2 = ATTR2_PRIO(3)
};

#define CAULDRON_ITEM_DY 140
#define CAULDRON_ITEM_DX 32
#define CAULDRON_ITEM_DT 32

static void cauldron_item_callback(oam_object *self) {
    FIXED dt = INT_TO_FIXED(CAULDRON_ITEM_DT); // in frames
    FIXED dx = INT_TO_FIXED(CAULDRON_ITEM_DX);
    FIXED dy = INT_TO_FIXED(CAULDRON_ITEM_DY); // in pixel
    FIXED a = FIXED_DIV(dy, FIXED_MUL(dt, dt));
    FIXED vx = FIXED_DIV(dx, dt);
    u16 frame = self->private[0]++;
    if (frame >= CAULDRON_ITEM_DT) {
        self->callback = oam_null_callback;
        self->y2 = (s16)(self->y2 - 32);
        return;
    }
    FIXED t = INT_TO_FIXED(frame);
    FIXED y = FIXED_MUL(a, FIXED_MUL(t, t)); // y = at^2
    FIXED x = FIXED_MUL(vx, t); // x = vt
    self->y2 = (s16)(FIXED_TO_INT(y) + CAULDRON_SCENE_STATE->bg_vertical_origin);
    self->x2 = (s16)(-FIXED_TO_INT(x) + CAULDRON_SCENE_STATE->bg_horizontal_origin);
}

static cauldron_item_linear_translation cauldron_item_trajectory0[] = {
    {.dx = -8, .dy = -64, .dt = 16}, {.dx = 16, .dy = -4, .dt = 8}, {.dx = -8, .dy = 68, .dt = 16}
};

static cauldron_item_linear_translation cauldron_item_trajectory1[] = {
    {.dx = 8, .dy = -64, .dt = 16}, {.dx = -16, .dy = -4, .dt = 8}, {.dx = 8, .dy = 68, .dt = 16}
};

static cauldron_item_piecewise_linear_trajectory cauldron_item_trajectories[] = {
    [0] = {.pieces = cauldron_item_trajectory0, .count = ARRAY_COUNT(cauldron_item_trajectory0)},
    [1] = {.pieces = cauldron_item_trajectory1, .count = ARRAY_COUNT(cauldron_item_trajectory1)},
};

static void cauldron_item_callback_trajectory(oam_object *self) {
    u16 trajectory_idx = self->private[0];
    u16 piece_idx = self->private[1];
    u16 frame = self->private[2]++;
    s16 *x_origin = (s16*)(self->private + 3);
    s16 *y_origin = (s16*)(self->private + 4);

    if (piece_idx < cauldron_item_trajectories[trajectory_idx].count) { // Finished trajectory
        if (frame > cauldron_item_trajectories[trajectory_idx].pieces[piece_idx].dt) { // Next trajectory piece frame
            self->private[1]++;
            self->private[2] = 0;
            // Save new origin for next frame
            *x_origin = self->x2;
            *y_origin = self->y2;
        } else { // Translation in current frame
            FIXED t = INT_TO_FIXED(frame);
            FIXED ax = FIXED_DIV(INT_TO_FIXED(cauldron_item_trajectories[trajectory_idx].pieces[piece_idx].dx),
                INT_TO_FIXED(cauldron_item_trajectories[trajectory_idx].pieces[piece_idx].dt));
            FIXED ay = FIXED_DIV(INT_TO_FIXED(cauldron_item_trajectories[trajectory_idx].pieces[piece_idx].dy),
                INT_TO_FIXED(cauldron_item_trajectories[trajectory_idx].pieces[piece_idx].dt));
            FIXED x = FIXED_MUL(ax, t);
            FIXED y = FIXED_MUL(ay, t);
            self->x2 = (s16)(FIXED_TO_INT(x) + *x_origin);
            self->y2 = (s16)(FIXED_TO_INT(y) + *y_origin);
        }
    } else {
        self->callback = oam_null_callback;
    }
}

static void cauldron_item_move_along_trajectory(u8 oam_idx, u8 trajcetory_idx) {
    oam_object *o = oams + oam_idx;
    o->private[0] = trajcetory_idx;
    o->private[1] = 0;
    o->private[2] = 0;
    o->private[3] = (u16)(o->x2);
    o->private[4] = (u16)(o->y2);
    o->callback = cauldron_item_callback_trajectory;
}

static rotscale_frame cauldron_item_rotscale_animation[] = {
    {.affine = {.affine_x_value = 0x180, .affine_y_value = 0x180, .duration = 0}},
    {.affine = {.rotation = 4, .duration = CAULDRON_ITEM_DT}},
    {.command = {.command = ROTSCALE_ANIM_END}},
};


static rotscale_frame *cauldron_item_rotscale_animations[] = {
    cauldron_item_rotscale_animation,
};

static oam_template cauldron_item_template = {
    .oam = &cauldron_item_final_oam, .animation = oam_gfx_anim_table_null, .graphics = NULL,
    .rotscale = cauldron_item_rotscale_animations, .callback = cauldron_item_callback,
};


static coordinate_t cauldron_light_positions[3] = {
    {.x = 74, .y = 179},
    {.x = 120, .y = 194},
    {.x = 165, .y = 179},
};

static void cauldron_scene_light_animation(u8 self) {
    (void) self;
    if (CAULDRON_SCENE_STATE->lights_number_active == 0) {
        for (int i = 0; i < 3; i++) {
            u16 color = (u16)((i + CAULDRON_SCENE_STATE->lights_color_state) % 3);
            oams[CAULDRON_SCENE_STATE->oams_lights[i]].private[2] = color;
            CAULDRON_SCENE_STATE->lights_number_active++;
        }
        CAULDRON_SCENE_STATE->lights_color_state = (u8)((CAULDRON_SCENE_STATE->lights_color_state + 1) % 3);
    }
}

static void cauldron_scene_handle_animation() {
    if (!fading_is_active() && !dma3_busy(-1)) {
        if (CAULDRON_SCENE_STATE->step_callback) {
            CAULDRON_SCENE_STATE->step_callback(CAULDRON_SCENE_STATE->frame++);
        }
    }
    generic_callback1();
}

static void cauldron_scene_next_step(void (*step_callback)(u16)) {
    CAULDRON_SCENE_STATE->frame = 0;
    CAULDRON_SCENE_STATE->step_callback = step_callback;
    callback1_set(cauldron_scene_handle_animation);
}

static void cauldron_scene_step_none(u16 frame) {
    (void)frame;
}

static coordinate_t cauldron_item_positions[4] = {
    {.x = 147, .y = -16 - 64},
    {.x = 152, .y = -16 - 64},
    {.x = 157, .y = -16 - 64},
    {.x = 152, .y = -16 - 64},
};


static void cauldron_scene_item_shaker(u8 self) {
    u16 frame = big_callbacks[self].params[0]++;
    if (frame % 64 == 0) { // Shake a new item
        size_t idxs[4] = {0, 1, 2, 3};
        shuffle(idxs, ARRAY_COUNT(idxs), NULL);
        for (u8 i = 0; i < ARRAY_COUNT(idxs); i++) { // Shake the first, non-shaking oam
            u8 oam_idx = CAULDRON_SCENE_STATE->oams_items[idxs[i]];
            if (oam_idx >= 0x40)
                continue;
            if (oams[oam_idx].callback != cauldron_item_callback_trajectory) {
                dprintf("move oam %d\n", idxs[i]);
                cauldron_item_move_along_trajectory(oam_idx, (u8)(rnd16() % ARRAY_COUNT(cauldron_item_trajectories)));
                break;
            }
        }
    }
}

#define SHAKER_PERIOD 8

static void cauldron_scene_shaker(u8 self) {
    u16 frame = big_callbacks[self].params[0]++;
    FIXED t = FIXED_DIV(INT_TO_FIXED(frame % SHAKER_PERIOD), INT_TO_FIXED(SHAKER_PERIOD));
    FIXED y = FIXED_MUL(INT_TO_FIXED(CAULDRON_SCENE_STATE->shaking_intensity), FIXED_SIN(t));
    CAULDRON_SCENE_STATE->bg_horizontal_origin = (s16)FIXED_TO_INT(y); 
}


static void cauldron_scene_step6_increase_shaking_intensity(u16 frame) {
    if (frame % 48 == 0) {
        CAULDRON_SCENE_STATE->shaking_intensity++;
    }
    if (frame >= 256) {
        cauldron_item_move_along_trajectory(CAULDRON_SCENE_STATE->oams_items[0], 0);
        cauldron_scene_next_step(cauldron_scene_step_none);
    }
}

static void cauldron_scene_step5_scroll_down(u16 frame) {
    if (frame > 32) {
        big_callback_new(cauldron_scene_shaker, 0);
        big_callback_new(cauldron_scene_item_shaker, 1);
        play_sound(85); // Truck sound
        cauldron_scene_next_step(cauldron_scene_step6_increase_shaking_intensity);
        return;
    }
    CAULDRON_SCENE_STATE->bg_vertical_origin = (s16)(32 + 32 + frame);
}

static void cauldron_scene_step4_close_cauldron(u16 frame) {
    if (frame == 32)
        play_sound(152);
    if (frame >= 50) {
        cauldron_scene_next_step(cauldron_scene_step5_scroll_down);
    } else {
        CAULDRON_SCENE_STATE->bg_vertical_scrolling[2] = (s16)-(2 * frame + 65);
    }
}

static void cauldron_scene_step2_wait_dropping_item(u16 frame) {
    if (frame == 32) {
        if (CAULDRON_SCENE_STATE->recipe.ingredients[CAULDRON_SCENE_STATE->state].item || 
            CAULDRON_SCENE_STATE->recipe.ingredients[CAULDRON_SCENE_STATE->state].type == CRAFTING_INGREDIENT_ASH) {
            cauldron_scene_next_step(cauldron_scene_step1_create_dropping_item);
        } else {
            bg_sync_display_and_show(2);
            cauldron_scene_next_step(cauldron_scene_step4_close_cauldron);
        }
    }
}


static void cauldron_scene_step1_create_dropping_item(u16 frame) {
    (void) frame;
    u8 idx = CAULDRON_SCENE_STATE->state++;
    u16 item;
    if (CAULDRON_SCENE_STATE->recipe.ingredients[idx].type == CRAFTING_INGREDIENT_ASH) {
        item = ITEM_ASCHETASCHE;
    } else {
        item = CAULDRON_SCENE_STATE->recipe.ingredients[idx].item;
    }
    u8 oam_idx = item_oam_new_by_template(&cauldron_item_template, (u16)(CAULDRON_ITEM_BASE_TAG + idx), (u16)(CAULDRON_ITEM_BASE_TAG + idx), item);
    oams[oam_idx].x = cauldron_item_positions[idx].x;
    oams[oam_idx].y = cauldron_item_positions[idx].y;
    oams[oam_idx].priority_on_layer = 77;
    CAULDRON_SCENE_STATE->oams_items[idx] = oam_idx;
    cauldron_scene_next_step(cauldron_scene_step2_wait_dropping_item);
    play_sound(23);
}



static void cauldron_scene_step0_scroll_down(u16 frame) {
    if (frame <= 32) {
        CAULDRON_SCENE_STATE->bg_vertical_origin = (s16)(32 + frame);
    } else {
        CAULDRON_SCENE_STATE->state = 0;
        cauldron_scene_next_step(cauldron_scene_step1_create_dropping_item);
    }
}

void cauldron_scene_setup() {
    generic_callback1();
    switch (CAULDRON_SCENE_STATE->state) {
        case 0: {
            big_callback_delete_all();
            oam_reset();
            oam_palette_allocation_reset();
            dma0_reset_callback();
            tbox_free_all();
            break;
        }
        case 1: {
            bg_reset(0);
            bg_setup(0, cauldron_bg_configs, ARRAY_COUNT(cauldron_bg_configs));
            bg_virtual_map_displace(1, 0, 0);
            bg_virtual_set_displace(1, 0, 0);
            bg_virtual_map_displace(2, 0, 0);
            bg_virtual_set_displace(2, 0, 0);
            bg_virtual_map_displace(3, 0, 0);
            bg_virtual_set_displace(3, 0, 0);
            CAULDRON_SCENE_STATE->bg_vertical_origin = 32;
            CAULDRON_SCENE_STATE->bg_vertical_scrolling[2] = -64;
            bg_set_tilemap(1, malloc_and_clear(0x800));
            bg_set_tilemap(2, malloc_and_clear(0x800));
            bg_set_tilemap(3, malloc_and_clear(0x800));
            break;
        }
        case 2: {
            lz77uncompvram(gfx_crafting_cauldronTiles, CHARBASE(2)); // on bg3
            lz77uncompvram(gfx_crafting_cauldron_topTiles, CHARBASE(1)); // on bg2
            lz77uncompvram(gfx_crafting_cauldron_overlayTiles, CHARBASE(0)); // on bg1
            lz77uncompwram(gfx_crafting_cauldronMap, bg_get_tilemap(3));
            lz77uncompwram(gfx_crafting_cauldron_topMap, bg_get_tilemap(2));
            lz77uncompwram(gfx_crafting_cauldron_overlayMap, bg_get_tilemap(1));
            oam_load_graphic(&cauldron_lights_graphic);
            break;
        }
        case 3: {
            pal_decompress(gfx_crafting_cauldronPal, 0, sizeof(color_t) * 256);
            pal_decompress(gfx_crafting_cauldron_lightsPal, (u16)(256 + 16 * oam_allocate_palette(CAULDRON_LIGHT_TAG)), 16 * sizeof(color_t));
            pal_set_all_to_black();
            break;
        }
        case 4: {
            for (u8 i = 0; i < ARRAY_COUNT(CAULDRON_SCENE_STATE->oams_lights); i++) {
                CAULDRON_SCENE_STATE->oams_lights[i] = oam_new_forward_search(&cauldron_light_oam_template, 
                    cauldron_light_positions[i].x, cauldron_light_positions[i].y, 0);
                oam_object *oam = oams + CAULDRON_SCENE_STATE->oams_lights[i];
                oam->private[2] = i;
                oam->private[0] = (u16) (32 * i);
                if (i == 2) {
                    oams->flags |= OAM_FLAG_HFLIP;
                }
                big_callback_new(cauldron_scene_light_animation, 0);
            }
            break;
        }
        case 5: {
            bg_virtual_sync(1);
            bg_virtual_sync(2);
            bg_virtual_sync(3);
            break;
        }
        case 6: {
            bg_sync_display_and_show(1);
            // bg_sync_display_and_show(2);
            bg_sync_display_and_show(3);
            bg_display_sync();
            // Window 1 contains every layer except fx, Window 0 contians every layer and fx
            break;
        }
        case 7: {
            fadescreen_all(0, 0);
            io_set(IO_WININ, IO_WININOUT_OBJ(0) |
                IO_WININOUT_BG(0, 0) | IO_WININOUT_BG(0, 1) | IO_WININOUT_BG(0, 2) | IO_WININOUT_BG(0, 3) |
                IO_WININOUT_BG(1, 0) | IO_WININOUT_BG(1, 1) | IO_WININOUT_BG(1, 2) | IO_WININOUT_BG(1, 3) |
                IO_WININOUT_OBJ(1) | IO_WININOUT_FX(0));
            io_set(IO_WINOUT, IO_WININOUT_BG(0, 0) | IO_WININOUT_BG(1, 0));

            io_set(IO_BLDCNT, IO_BLDCNT_ALPHA_BLENDING | IO_BLDCNT_BG2_FIRST | IO_BLDCNT_BG3_SECOND | IO_BLDCNT_OBJ_SECOND);
            io_set(IO_BLDALPHA, IO_BLDALPHA_EVA(12) | IO_BLDALPHA_EVB(4));
            cauldron_scene_next_step(cauldron_scene_step0_scroll_down);
            break;
        }
        default:
            return;
    }
    CAULDRON_SCENE_STATE->state++;
}



void cauldron_scene_initialize(crafting_recipe *recipe) {
    fmem.gp_state = malloc_and_clear(sizeof(cauldron_scene_state));
    for (u8 i = 0; i < ARRAY_COUNT(CAULDRON_SCENE_STATE->oams_items); i++) {
        CAULDRON_SCENE_STATE->oams_items[i] = 0x40;
    }
    CAULDRON_SCENE_STATE->recipe = *recipe;
    callback1_set(cauldron_scene_setup);
    vblank_handler_set(cauldron_vblank_handler);
}

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
#include "battle/attack.h"
#include "language.h"
#include "overworld/map_control.h"
#include "overworld/script.h"
#include "text.h"

static void cauldron_scene_step1_create_dropping_item(u16 frame);

static const bg_config cauldron_bg_configs[] = {
    {.bg_id = 0, .char_base = 3, .map_base = 28, .size = 0, .color_mode = 0, .priority = 0},
    {.bg_id = 1, .char_base = 0, .map_base = 29, .size = 0, .color_mode = 1, .priority = 1},
    {.bg_id = 2, .char_base = 1, .map_base = 30, .size = 0, .color_mode = 1, .priority = 2},
    {.bg_id = 3, .char_base = 2, .map_base = 31, .size = 0, .color_mode = 1, .priority = 3},
};

static const tboxdata cauldron_tboxes[] = {
    [0] = {.bg_id = 0, .x = 2, .y = 15, .w = 26, .h = 4, .pal = 15, .start_tile = 1},
    [1] = {.bg_id = 0xFF},
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

static const graphic cauldron_lights_graphic = {
    .sprite = gfx_crafting_cauldron_lightsTiles, .tag = CAULDRON_LIGHT_TAG, .size = 6 * GRAPHIC_SIZE_4BPP(32, 32),
};

static const gfx_frame cauldron_light_gfx_frames[] = {
    {.data = 0, .duration = 0}, {.data = GFX_ANIM_END},
    {.data = 16, .duration = 0}, {.data = GFX_ANIM_END},
    {.data = 32, .duration = 0}, {.data = GFX_ANIM_END},
    {.data = 48, .duration = 0}, {.data = GFX_ANIM_END},
    {.data = 64, .duration = 0}, {.data = GFX_ANIM_END},
    {.data = 80, .duration = 0}, {.data = GFX_ANIM_END},
};

static const gfx_frame *const cauldron_light_gfx_animations[] = {
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
    u16 duration = self->private[3];
    if (++*frame >= duration) {
        CAULDRON_SCENE_STATE->lights_number_active--;
        *frame = 0;
        oam_gfx_anim_start_if_not_current(self, (u8)(type * 3 + color));
    }
    self->y2 = (s16)(-CAULDRON_SCENE_STATE->bg_vertical_origin);
    self->x2 = (s16)(-CAULDRON_SCENE_STATE->bg_horizontal_origin);
}

static void cauldron_light_initialize_all(u16 duration) {
    for (u8 i = 0; i < ARRAY_COUNT(CAULDRON_SCENE_STATE->oams_lights); i++) {
        oam_object *o = oams + CAULDRON_SCENE_STATE->oams_lights[i];
        o->private[3] = (u16)(3 * duration);
        o->private[0] = (u16)(i * duration); // make them light with delay
    }
}


static const sprite cauldron_light_final_oam = {
    .attr0 = ATTR0_SHAPE_SQUARE, .attr1 = ATTR1_SIZE_32_32, .attr2 = ATTR2_PRIO(3),
};

static const oam_template cauldron_light_oam_template = {
    .tiles_tag = CAULDRON_LIGHT_TAG, .pal_tag = CAULDRON_LIGHT_TAG, .oam = &cauldron_light_final_oam,
    .animation = cauldron_light_gfx_animations, .graphics = NULL, .rotscale = oam_rotscale_anim_table_null,
    .callback = cauldron_light_oam_callback
};

static const sprite cauldron_spark_final_oam = {
    .attr0 = ATTR0_SHAPE_SQUARE, .attr1 = ATTR1_SIZE_16_16, .attr2 = ATTR2_PRIO(0),
};

static const gfx_frame cauldron_spark_gfx_animation[] = {
    {.data = 0, .duration = 0}, {.data = 0, .duration = 4}, {.data = 4, .duration = 4}, 
    {.data = 8, .duration = 4}, {.data = GFX_ANIM_END},
};

static const gfx_frame *const cauldron_spark_gfx_animations[] = {
    [0] = cauldron_spark_gfx_animation,
};

static void cauldron_spark_oam_callback(oam_object *self) {
    if (self->flags & OAM_FLAG_GFX_ANIM_END)
        oam_delete(self);
}

static const oam_template cauldron_spark_oam_template = {
    .tiles_tag = BATTLE_ANIMATION_OAM_BASE + 11, .pal_tag = BATTLE_ANIMATION_OAM_BASE + 11,
    .oam = &cauldron_spark_final_oam, .animation = cauldron_spark_gfx_animations, .graphics = NULL,
    .rotscale = oam_rotscale_anim_table_null, .callback = cauldron_spark_oam_callback,
};


static const sprite cauldron_item_final_oam = {
    .attr0 = ATTR0_DSIZE | ATTR0_SHAPE_SQUARE | ATTR0_ROTSCALE, .attr1 = ATTR1_SIZE_32_32, .attr2 = ATTR2_PRIO(3)
};

#define CAULDRON_ITEM_DY 144
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
        // Re-position the oams
        self->y = (s16)(self->y + self->y2);
        self->x = 120;
        self->x2 = 0;
        self->y2 = 0;
        return;
    }
    FIXED t = INT_TO_FIXED(frame);
    FIXED y = FIXED_MUL(a, FIXED_MUL(t, t)); // y = at^2
    FIXED x = FIXED_MUL(vx, t); // x = vt
    self->y2 = (s16)(FIXED_TO_INT(y) + CAULDRON_SCENE_STATE->bg_vertical_origin);
    self->x2 = (s16)(-FIXED_TO_INT(x) + CAULDRON_SCENE_STATE->bg_horizontal_origin);
}

static void cauldron_item_move_along_parabola(oam_object *self) {
    u16 frame = self->private[0]++;
    s16 ymax = (s16)(self->private[1]);
    s16 dx = (s16)(self->private[2]);
    u16 dt = self->private[3];
    if (frame > dt) {
        self->callback = oam_null_callback;
        return;
    }
    // Move along parabola in y direction, that starts at (0, 0), has a mode at (t/2, ymax) and ends at (t, 0)
    FIXED t = INT_TO_FIXED(frame);
    FIXED by = FIXED_DIV(INT_TO_FIXED(-4 * ymax), INT_TO_FIXED(dt));
    FIXED ay = FIXED_DIV(-by, INT_TO_FIXED(dt));
    FIXED y = FIXED_ADD(FIXED_MUL(ay, FIXED_MUL(t, t)), FIXED_MUL(by, t));
    // Move along a sine wave in x direction
    FIXED theta = FIXED_DIV(t, INT_TO_FIXED(dt));
    FIXED x = FIXED_MUL(INT_TO_FIXED(dx), FIXED_SIN(theta));
    self->y2 = (s16)(FIXED_TO_INT(y) - 32);
    self->x2 = (s16)(FIXED_TO_INT(x)); // I think it looks better w/o + CAULDRON_SCENE_STATE->bg_horizontal_origin);
}

static void cauldron_item_set_parabolic_trajectory(u8 oam_idx, s16 ymax, s16 dx, u16 dt) {
    oam_object *o = oams + oam_idx;
    o->private[0] = 0;
    o->private[1] = (u16)ymax;
    o->private[2] = (u16)dx;
    o->private[3] = dt;
    // DEBUG("New trajectory for %d with ymax %d, dx %d and dt %d\n", oam_idx, ymax, dx, dt);
    o->callback = cauldron_item_move_along_parabola;
    oam_rotscale_anim_init(o, 1);
}

static const rotscale_frame cauldron_item_rotscale_animation0[] = {
    {.affine = {.affine_x_value = 0x180, .affine_y_value = 0x180, .duration = 0}},
    {.affine = {.rotation = 4, .duration = CAULDRON_ITEM_DT}},
    {.command = {.command = ROTSCALE_ANIM_END}},
};

static const rotscale_frame cauldron_item_rotscale_animation1[] = {
    {.affine = {.affine_x_value = 0x180, .affine_y_value = 0x180, .duration = 0}},
    {.affine = {.rotation = 8, .duration = 128}},
    {.command = {.command = ROTSCALE_ANIM_END}},
};

static const rotscale_frame *const cauldron_item_rotscale_animations[] = {
    [0] = cauldron_item_rotscale_animation0, [1] = cauldron_item_rotscale_animation1,
};

static const oam_template cauldron_item_template = {
    .oam = &cauldron_item_final_oam, .animation = oam_gfx_anim_table_null, .graphics = NULL,
    .rotscale = cauldron_item_rotscale_animations, .callback = cauldron_item_callback,
};


static const coordinate_t cauldron_light_positions[3] = {
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

static const coordinate_t cauldron_item_positions[4] = {
    {.x = 147, .y = -16 - 64},
    {.x = 152, .y = -16 - 64},
    {.x = 157, .y = -16 - 64},
    {.x = 152, .y = -16 - 64},
};


static void cauldron_scene_item_shaker(u8 self) {
    u16 frame = big_callbacks[self].params[0]++;
    if (frame % 16 == 0 && (rnd16() % 2)) { // Shake a new item
        size_t idxs[4] = {0, 1, 2, 3};
        shuffle(idxs, ARRAY_COUNT(idxs), NULL);
        for (u8 i = 0; i < ARRAY_COUNT(idxs); i++) { // Shake the first, non-shaking oam
            u8 oam_idx = CAULDRON_SCENE_STATE->oams_items[idxs[i]];
            if (oam_idx >= 0x40)
                continue;
            if (oams[oam_idx].callback != cauldron_item_move_along_parabola) {
                s16 ymax = (s16)(52 - (rnd16() % 16));
                s16 dx = (s16)((rnd16() % 5) * ((rnd16() % 2) ? 1 : -1));
                cauldron_item_set_parabolic_trajectory(oam_idx, ymax, dx, 32);
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

static void cauldron_scene_big_callback_null(u8 self) {
    (void)self;
}

static const u8 str_crafted[] = LANGDEP(
    PSTRING("PLAYER hat BUFFER_2x BUFFER_1\nhergestellt!"),
    PSTRING("PLAYER crafted BUFFER_2x BUFFER_1!")
);

static void cauldron_free_and_return_to_overworld() {
    if (!fading_is_active() && !dma3_busy(-1)) {
        free(bg_get_tilemap(0));
        free(bg_get_tilemap(1));
        free(bg_get_tilemap(2));
        free(bg_get_tilemap(3));
        cauldron_scene_state tmp = *CAULDRON_SCENE_STATE;
        free(CAULDRON_SCENE_STATE);
        crafting_ui_reinitialize(tmp.saved_ui_state.type,
            tmp.saved_ui_state.list_menu_cursor_positions, tmp.saved_ui_state.list_menu_cursor_above);
        
    }
    generic_callback1();
}

static void cauldron_scene_end_on_keypress(u8 self) {
    if (super.keys_new.value) {
        big_callback_delete(self);
        play_sound(5);
        fadescreen_all(1, 0);
        recipe_use(&CAULDRON_SCENE_STATE->recipe, CAULDRON_SCENE_STATE->count);
        callback1_set(cauldron_free_and_return_to_overworld);
    }
}

static void cauldron_scene_step9_success_string(u16 frame) {
    (void)frame;
    play_sound(257);
    tbox_flush_set(0, 0);
    tbox_tilemap_draw(0);
    u8 cb_idx = big_callback_new(cauldron_scene_big_callback_null, 0);
    itoa(buffer1, CAULDRON_SCENE_STATE->count * CAULDRON_SCENE_STATE->recipe.count, ITOA_NO_PADDING, 3);
    string_decrypt(strbuf, str_crafted);
    tbox_print_string_and_continue(cb_idx, 0, CRAFTING_CAULDRON_BASE_TILE_MESSAGE, CRAFTING_CAULDRON_PAL_IDX_MESSAGE, 
        2, tbox_get_set_speed(), strbuf, cauldron_scene_end_on_keypress);
    CAULDRON_SCENE_STATE->bg_vertical_scrolling[0] = (s16)(-CAULDRON_SCENE_STATE->bg_vertical_origin);
    cauldron_scene_next_step(cauldron_scene_step_none);
}


static void cauldron_scene_step8_decrease_shaking_intensity(u16 frame) {
    if (frame % 24 == 0) {
        CAULDRON_SCENE_STATE->shaking_intensity--;
    }
    if (frame % 32 == 0 && frame <= 128) {
        cauldron_light_initialize_all((u16)(32 >> ((128 - frame) / 32)));
    }
    if (frame >= 128) {
        if (big_callback_is_active(cauldron_scene_shaker))
            big_callback_delete(big_callback_get_id(cauldron_scene_shaker));
        cauldron_scene_next_step(cauldron_scene_step9_success_string);
    }
}


static void cauldron_scene_step7_wait_shaking(u16 frame) {
    if (frame >= 128) {
        if (big_callback_is_active(cauldron_scene_item_shaker))
            big_callback_delete(big_callback_get_id(cauldron_scene_item_shaker));
        play_sound(86); // Truck sound stop
        cauldron_scene_next_step(cauldron_scene_step8_decrease_shaking_intensity);
    }
    switch (frame) {
        case 0:
            oams[oam_new_backward_search(&cauldron_spark_oam_template, 63, 64, 0)].flags |= OAM_FLAG_HFLIP;
            break;
        case 24:
            oam_new_backward_search(&cauldron_spark_oam_template, 190, 97, 0);
            break;
        case 34:
            oams[oam_new_backward_search(&cauldron_spark_oam_template, 84, 37, 0)].flags |= OAM_FLAG_HFLIP;
            break;
        case 40:
            oams[oam_new_backward_search(&cauldron_spark_oam_template, 65, 117, 0)].flags |= OAM_FLAG_HFLIP;
            break;
        case 72:
            oam_new_backward_search(&cauldron_spark_oam_template, 160, 130, 0);
            break;
        case 90:
            oams[oam_new_backward_search(&cauldron_spark_oam_template, 85, 95, 0)].flags |= OAM_FLAG_HFLIP;
            break;
        case 98:
            oam_new_backward_search(&cauldron_spark_oam_template, 150, 53, 0);
            break;
        case 104:
            oam_new_backward_search(&cauldron_spark_oam_template, 178, 73, 0);
            break;
        case 112:
            oams[oam_new_backward_search(&cauldron_spark_oam_template, 95, 113, 0)].flags |= OAM_FLAG_HFLIP;
            break;
        case 120:
            oam_new_backward_search(&cauldron_spark_oam_template, 163, 56, 0);
            break;
    }

    if (frame == 24) {
    } else if (frame == 68) {
        oam_new_backward_search(&cauldron_spark_oam_template, 90, 88, 0);
    }
}


static void cauldron_scene_step6_increase_shaking_intensity(u16 frame) {
    if (frame % 48 == 0) {
        CAULDRON_SCENE_STATE->shaking_intensity++;
    }
    if (frame % 64 == 0 && frame <= 256) {
        cauldron_light_initialize_all((u16)(32 >> (frame / 64)));
    }
    if (frame >= 256) {
        cauldron_scene_next_step(cauldron_scene_step7_wait_shaking);
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
        if (CAULDRON_SCENE_STATE->state < MAX_NUM_INGREDIENTS && (CAULDRON_SCENE_STATE->recipe.ingredients[CAULDRON_SCENE_STATE->state].item || 
            CAULDRON_SCENE_STATE->recipe.ingredients[CAULDRON_SCENE_STATE->state].type == CRAFTING_INGREDIENT_ASH)) {
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
            bg_virtual_map_displace(0, 0, 0);
            bg_virtual_set_displace(0, 0, 0);
            bg_virtual_map_displace(1, 0, 0);
            bg_virtual_set_displace(1, 0, 0);
            bg_virtual_map_displace(2, 0, 0);
            bg_virtual_set_displace(2, 0, 0);
            bg_virtual_map_displace(3, 0, 0);
            bg_virtual_set_displace(3, 0, 0);
            CAULDRON_SCENE_STATE->bg_vertical_origin = 32;
            CAULDRON_SCENE_STATE->bg_vertical_scrolling[2] = -64;
            bg_set_tilemap(0, malloc_and_clear(0x800));
            bg_set_tilemap(1, malloc_and_clear(0x800));
            bg_set_tilemap(2, malloc_and_clear(0x800));
            bg_set_tilemap(3, malloc_and_clear(0x800));
            break;
        }
        case 2: {
            tbox_sync_with_virtual_bg_and_init_all(cauldron_tboxes);
            lz77uncompvram(gfx_crafting_cauldronTiles, CHARBASE(2)); // on bg3
            lz77uncompvram(gfx_crafting_cauldron_topTiles, CHARBASE(1)); // on bg2
            lz77uncompvram(gfx_crafting_cauldron_overlayTiles, CHARBASE(0)); // on bg1
            lz77uncompwram(gfx_crafting_cauldronMap, bg_get_tilemap(3));
            lz77uncompwram(gfx_crafting_cauldron_topMap, bg_get_tilemap(2));
            lz77uncompwram(gfx_crafting_cauldron_overlayMap, bg_get_tilemap(1));
            oam_load_graphic(&battle_animation_graphics[11]);
            oam_load_graphic(&cauldron_lights_graphic);
            break;
        }
        case 3: {
            pal_decompress(gfx_crafting_cauldronPal, 0, sizeof(color_t) * 256);
            pal_decompress(gfx_crafting_cauldron_lightsPal, (u16)(256 + 16 * oam_allocate_palette(CAULDRON_LIGHT_TAG)), 16 * sizeof(color_t));
            battle_animation_load_oam_palette(&battle_animation_palettes[11]);
            tbox_init_frame_message(0, CRAFTING_CAULDRON_BASE_TILE_MESSAGE, CRAFTING_CAULDRON_PAL_IDX_MESSAGE * 16);
            // tbox_context_init_border_set_style(0, 256 + 20, 14 * 16);
            pal_set_all_to_black();
            break;
        }
        case 4: {
            for (u8 i = 0; i < ARRAY_COUNT(CAULDRON_SCENE_STATE->oams_lights); i++) {
                CAULDRON_SCENE_STATE->oams_lights[i] = oam_new_forward_search(&cauldron_light_oam_template, 
                    cauldron_light_positions[i].x, cauldron_light_positions[i].y, 0);
                oam_object *oam = oams + CAULDRON_SCENE_STATE->oams_lights[i];
                oam->private[2] = i;
                if (i == 2) {
                    oams->flags |= OAM_FLAG_HFLIP;
                }
            }
            big_callback_new(cauldron_scene_light_animation, 0);
            cauldron_light_initialize_all(32);
            break;
        }
        case 5: {
            bg_virtual_sync(0);
            bg_virtual_sync(1);
            bg_virtual_sync(2);
            bg_virtual_sync(3);
            break;
        }
        case 6: {
            bg_sync_display_and_show(0);
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



void cauldron_scene_initialize(const crafting_recipe *recipe, crafting_ui_state *ui_state) {
    fmem.gp_state = malloc_and_clear(sizeof(cauldron_scene_state));
    for (u8 i = 0; i < ARRAY_COUNT(CAULDRON_SCENE_STATE->oams_items); i++) {
        CAULDRON_SCENE_STATE->oams_items[i] = 0x40;
    }
    CAULDRON_SCENE_STATE->recipe = *recipe;
    CAULDRON_SCENE_STATE->count = ui_state->quantity;
    CAULDRON_SCENE_STATE->saved_ui_state.type = ui_state->type;
    memcpy(CAULDRON_SCENE_STATE->saved_ui_state.list_menu_cursor_positions, ui_state->list_menu_cursor_positions, sizeof(ui_state->list_menu_cursor_positions));
    memcpy(CAULDRON_SCENE_STATE->saved_ui_state.list_menu_cursor_above, ui_state->list_menu_cursor_above, sizeof(ui_state->list_menu_cursor_above));
    callback1_set(cauldron_scene_setup);
    vblank_handler_set(cauldron_vblank_handler);
}

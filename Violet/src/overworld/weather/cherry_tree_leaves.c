#include "types.h"
#include "overworld/weather.h"
#include "overworld/sprite.h"
#include "oam.h"
#include "debug.h"
#include "math.h"
#include "prng.h"

#define PERIOD 256
#define NEW_PERIOD 28
#define CHERRY_TREE_LEAVES_NUM_OAMS 28

// This is the "visible" off-screen margin where oams are considered visible
#define MARGIN 16
// 6-bit fractional part, i.e. 64 -> 1.0
#define SLOPE_RANGE 32
// 6-bit fractional part i.e. 64 -> 1.0
#define SPEED_RANGE 32

enum {
    ANIM_IDLE,
    ANIM_HORIZONTAL,
    ANIM_SEMI_HORIZONTAL,
    ANIM_DIAGONAL,
    ANIM_SPIN,
};

typedef struct {
    u16 frame;
    u8 slope; // 6-bit fractional part
    u8 dydt; // 6-bit fractional part
    u8 dxdt; // 6-bit fractional part (slope = dydt / dxdt, but this saves a div)
    s16 x0;
    u8 y0;
    u8 idx;
    u16 spin_frame; // frame at which the oam spins
} cherry_tree_leave_state_t;

static void weather_cherry_tree_leaves_oam_callback_initialize(oam_object *self);
static void weather_cherry_tree_leaves_oam_callback_fall(oam_object *self);
static void weather_cherry_tree_leaves_oam_callback_wait(oam_object *self);

static void weather_cherry_tree_leaves_oam_start_animation_by_slope(oam_object *self) {
    // TODO: pick suitable animation by slope
    cherry_tree_leave_state_t *state = (cherry_tree_leave_state_t*) self->private;
    u8 slope = state->slope;
    if (slope > 112) {
        oam_gfx_anim_start(self, ANIM_HORIZONTAL);
    } else if (slope > 104) {
        oam_gfx_anim_start(self, ANIM_SEMI_HORIZONTAL);
    } else {
        oam_gfx_anim_start(self, ANIM_DIAGONAL);
    }
}

// We have 32 oams that are distributed evenly in x-boxes of size 32 (8 boxes)

static void weather_cherry_tree_leaves_oam_callback_initialize(oam_object *self) {
    cherry_tree_leave_state_t *state = (cherry_tree_leave_state_t*) self->private;
    state->frame = 0;
    state->x0 = (s16)(32 * (state->idx % 8) + (rnd16() % 32));
    state->y0 = (u16)((-coordinate_camera_y_offset - MARGIN) & 0xFF);
    state->slope = (u8)(112 - (SLOPE_RANGE / 2) + (rnd16() % SLOPE_RANGE));
    state->dydt = (u8)(32 - (SPEED_RANGE / 2) + (rnd16() % SPEED_RANGE));
    state->dxdt = (u8)(state->dydt * state->slope / 64);
    state->spin_frame = (u16)(rnd16() % 512);
    weather_cherry_tree_leaves_oam_start_animation_by_slope(self);
    self->flags &= (u16)(~OAM_FLAG_INVISIBLE);
    self->callback = weather_cherry_tree_leaves_oam_callback_fall;
}

static void weather_cherry_tree_leaves_oam_callback_spin(oam_object *self) {
    weather_cherry_tree_leaves_oam_callback_fall(self);
    if (self->flags & OAM_FLAG_GFX_ANIM_END) {
        weather_cherry_tree_leaves_oam_start_animation_by_slope(self);
        self->callback = weather_cherry_tree_leaves_oam_callback_fall;
    }
}

static void weather_cherry_tree_leaves_oam_callback_fall(oam_object *self) {
    cherry_tree_leave_state_t *state = (cherry_tree_leave_state_t*) self->private;
    int frame = state->frame++;
    if (frame == state->spin_frame) {
        self->callback = weather_cherry_tree_leaves_oam_callback_spin;
        oam_gfx_anim_start(self, ANIM_SPIN);
        state->spin_frame = 0xFFFF;
        return;
    }

    int x = (state->x0 + coordinate_camera_x_offset - frame * state->dxdt / 64) & 0xFF; 
    int y = (state->y0 + coordinate_camera_y_offset + frame * state->dydt / 64) & 0xFF;
    self->x = (s16)(x - MARGIN / 2);
    self->y = (s16)y;
    // DEBUG("Sprite at pos0 %d,%d is at %d,%d at frame %d, slope %d, dydt %d, dxdt %d\n", state->x0, state->y0, x, y, frame, state->slope, state->dydt, state->dxdt);

    // If the sprite is beyond y_end (in the visible area), delete it
    if (y >= 160 + MARGIN && y <= 160 + 2 * MARGIN) {
        self->flags |= OAM_FLAG_INVISIBLE;
        self->y = 256 - MARGIN;
        //DEBUG("Reset oam\n.");
        self->callback = weather_cherry_tree_leaves_oam_callback_wait;
    } else if (y >= 256 - MARGIN) {
        self->flags |= OAM_FLAG_INVISIBLE;
        self->y = 256 - MARGIN;
    } else {
        self->flags &= (u16)(~OAM_FLAG_INVISIBLE);
    }

}

static void weather_cherry_tree_leaves_oam_callback_wait(oam_object *self) {
    cherry_tree_leave_state_t *state = (cherry_tree_leave_state_t*) self->private;
    int frame = state->frame++;
    if (frame >= PERIOD) {
        weather_cherry_tree_leaves_oam_callback_initialize(self);
    }
}



extern u8 gfx_weather_cherry_tree_leavesTiles[];

static graphic weather_cherry_tree_leaves_graphics[] = {
    [0] = {.sprite = gfx_weather_cherry_tree_leavesTiles + GRAPHIC_SIZE_4BPP(16, 16) * 0, .size = GRAPHIC_SIZE_4BPP(16, 16)},
    [1] = {.sprite = gfx_weather_cherry_tree_leavesTiles + GRAPHIC_SIZE_4BPP(16, 16) * 1, .size = GRAPHIC_SIZE_4BPP(16, 16)},
    [2] = {.sprite = gfx_weather_cherry_tree_leavesTiles + GRAPHIC_SIZE_4BPP(16, 16) * 2, .size = GRAPHIC_SIZE_4BPP(16, 16)},
    [3] = {.sprite = gfx_weather_cherry_tree_leavesTiles + GRAPHIC_SIZE_4BPP(16, 16) * 3, .size = GRAPHIC_SIZE_4BPP(16, 16)},
};

static sprite weather_cherry_tree_sprite = {.attr0 = ATTR0_SHAPE_SQUARE, .attr1 = ATTR1_SIZE_16_16, .attr2 = ATTR2_PRIO(1)};

static gfx_frame weather_cherry_tree_leaves_animation_idle[] = {
    {.data = 0, .duration = 0}, {.data = GFX_ANIM_END},
};

static gfx_frame weather_cherry_tree_leaves_animation_horizontal[] = {
    {.data = 3, .duration = 0}, {.data = 3, .duration = 24}, 
    {.data = 3, .duration = 24 | GFX_ANIM_HFLIP},
    {.data = GFX_ANIM_JUMP, .duration = 0},
};


static gfx_frame weather_cherry_tree_leaves_animation_semi_horizontal[] = {
    {.data = 2, .duration = 0}, {.data = 2, .duration = 16},
    {.data = 3, .duration = 16}, 
    {.data = 3, .duration = 16 | GFX_ANIM_HFLIP},
    {.data = GFX_ANIM_JUMP, .duration = 0},
};

static gfx_frame weather_cherry_tree_leaves_animation_diagonal[] = {
    {.data = 1, .duration = 0}, {.data = 1, .duration = 16},
    {.data = 2, .duration = 16}, 
    {.data = 3, .duration = 8},
    {.data = 2, .duration = 16}, 
    {.data = GFX_ANIM_JUMP, .duration = 0},
};

static gfx_frame weather_cherry_tree_leaves_animation_spin[] = {
    {.data = 2, .duration = 0}, {.data = 2, .duration = 4},
    {.data = 3, .duration = 4}, {.data = 3, .duration = 4 | GFX_ANIM_HFLIP},
    {.data = 2, .duration = 4 | GFX_ANIM_HFLIP}, {.data = 1, .duration = 4 | GFX_ANIM_HFLIP},
    {.data = 0, .duration = 4 | GFX_ANIM_HFLIP}, {.data = 1, .duration = 4 | GFX_ANIM_HFLIP | GFX_ANIM_VFLIP},
    {.data = 1, .duration = 4 | GFX_ANIM_VFLIP}, {.data = 1, .duration = 4}, {.data = 2, .duration = 4}, 
    {.data = 3, .duration = 4}, {.data = GFX_ANIM_END},
};

static gfx_frame *weather_cherry_tree_leaves_animations[] = {
    [ANIM_IDLE] = weather_cherry_tree_leaves_animation_idle,
    [ANIM_HORIZONTAL] = weather_cherry_tree_leaves_animation_horizontal,
    [ANIM_SEMI_HORIZONTAL] = weather_cherry_tree_leaves_animation_semi_horizontal,
    [ANIM_DIAGONAL] = weather_cherry_tree_leaves_animation_diagonal,
    [ANIM_SPIN] = weather_cherry_tree_leaves_animation_spin,
};

static oam_template weather_cherry_tree_leaves_template = {
    .tiles_tag = 0xFFFF, .pal_tag = 0x1200,
    .oam = &weather_cherry_tree_sprite,
    .animation = weather_cherry_tree_leaves_animations,
    .graphics = weather_cherry_tree_leaves_graphics,
    .rotscale = oam_rotscale_anim_table_null,
    .callback = weather_cherry_tree_leaves_oam_callback_initialize,
};

void weather_cherry_tree_leaves_initialize_variables() {
    DEBUG("Cherry tree init vars.\n");
    overworld_weather.init_step = 0;
    overworld_weather.gamma_to = 0;
    overworld_weather.gamma_step_delay = 20;
    overworld_weather.cherry_tree_target_num_oams = CHERRY_TREE_LEAVES_NUM_OAMS;
    overworld_weather.cherry_tree_new_timer = 0;
}

static void weather_cherry_tree_leaves_create_oam() {
    if (overworld_weather.cherry_tree_num_oams == 0)
        overworld_weather.cherry_tree_oam_group_head = NUM_OAMS;

    u8 idx = overworld_weather.cherry_tree_num_oams;
    u8 oam_idx = oam_new_backward_search(&weather_cherry_tree_leaves_template, 0, 250, 78);
    if (overworld_weather.cherry_tree_oam_group_head == NUM_OAMS)
        overworld_weather.cherry_tree_oam_group_head = oam_idx;

    if (oam_idx < NUM_OAMS) {
        overworld_weather.sprites.s1.cherry_tree_sprites[idx] = oams + oam_idx;
        cherry_tree_leave_state_t *state = (cherry_tree_leave_state_t*) oams[oam_idx].private;
        state->idx = overworld_weather.cherry_tree_num_oams;

        if (oam_idx != overworld_weather.cherry_tree_oam_group_head)
            oam_add_to_group(oam_idx, overworld_weather.cherry_tree_oam_group_head);
    } else {    
        overworld_weather.sprites.s1.cherry_tree_sprites[idx] = NULL;
    }
    DEBUG("Created new cherry leave oam with idx %d as the %d-th.\n", oam_idx, idx);
    overworld_weather.cherry_tree_num_oams++;
}

static void weather_cherry_tree_leaves_delete_oam() {
    if (overworld_weather.cherry_tree_num_oams > 0) {
        oam_object **o = overworld_weather.sprites.s1.cherry_tree_sprites + (--overworld_weather.cherry_tree_num_oams);
        if (*o)
            oam_delete(*o);
        DEBUG("Deleted cherry tree oam at 0x%x with cherry tree idx %d\n", *o, overworld_weather.cherry_tree_num_oams);
        *o = NULL;
    }
}

static bool weather_cherry_tree_leaves_create_or_delete_oam() {
    if (overworld_weather.cherry_tree_num_oams < overworld_weather.cherry_tree_target_num_oams) {
        weather_cherry_tree_leaves_create_oam();
    } else if (overworld_weather.cherry_tree_num_oams > overworld_weather.cherry_tree_target_num_oams) {
        weather_cherry_tree_leaves_delete_oam();
    }
    return overworld_weather.cherry_tree_num_oams != overworld_weather.cherry_tree_target_num_oams;
}

void weather_cherry_tree_leaves_main() {
    switch (overworld_weather.init_step){
        case 0: {
            // Periodically create a new oam until all created
            if (++overworld_weather.cherry_tree_new_timer > NEW_PERIOD) {
                overworld_weather.cherry_tree_new_timer = 0; // Reset the timer
                if (!weather_cherry_tree_leaves_create_or_delete_oam())
                    overworld_weather.init_step++;
            }
            break;
        }
        case 1: {
            break;
        }
    }
}

void weather_cherry_tree_leaves_initialize_all() {
    DEBUG("Cherry tree init all.\n");
    weather_cherry_tree_leaves_initialize_variables();
    // Initialize all oams
    for (int i = 0; i < overworld_weather.cherry_tree_target_num_oams; i++){
        int idx = overworld_weather.cherry_tree_num_oams;
        weather_cherry_tree_leaves_create_oam();
        oam_object *o = overworld_weather.sprites.s1.cherry_tree_sprites[idx];
        if (o) {
            cherry_tree_leave_state_t *state = (cherry_tree_leave_state_t*)o->private;
            weather_cherry_tree_leaves_oam_callback_initialize(o);
            state->frame = ((u16)(i * NEW_PERIOD) % PERIOD);
        }
    }
    DEBUG("Cherry tree init all done.\n");
}

bool weather_cherry_tree_leaves_closure() {
    switch (overworld_weather.finish_step) {
        case 0: {   
            overworld_weather.cherry_tree_target_num_oams = 0;
            overworld_weather.cherry_tree_new_timer = 0; // Timer
            overworld_weather.finish_step++;
            FALL_THROUGH;
        }
        case 1 : {
            // Periodically delete an oam until all deleted
            if (++overworld_weather.cherry_tree_new_timer > NEW_PERIOD) {
                overworld_weather.cherry_tree_new_timer = 0; // Reset the timer
                if (!weather_cherry_tree_leaves_create_or_delete_oam()) {
                    overworld_weather.finish_step++;
                    return false;
                }
            }
            return true;
        }
    }
    return false;
}
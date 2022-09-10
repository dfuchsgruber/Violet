#include "types.h"
#include "overworld/weather.h"
#include "overworld/sprite.h"
#include "oam.h"
#include "debug.h"
#include "math.h"
#include "prng.h"

#define NEW_PERIOD 28
#define DELETE_PERIOD 8
#define MAX_TIME_DELETE 512
#define MIN_TIME_DELETE 256
#define MAX_NUM_VISIBLE 32

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
    NUM_ANIMS,
};

typedef struct {
    u16 frame;
    u8 slope; // 6-bit fractional part
    u8 dydt; // 6-bit fractional part
    u8 dxdt; // 6-bit fractional part (slope = dydt / dxdt, but this saves a div)
    u8 spin_enabled : 1;
    u8 new_trajectory_enabled : 1;
    s16 x0 : 12;
    u16 num_animation_colors : 2;
    u16 animation_color : 2;
    u8 y0;
    u8 idx;
    u16 spin_frame; // frame at which the oam spins
    u16 deletion_timer;
    // TODO: this struct is "full", if you want more members, allocate it on the heap (the heap space oh no :( )
} any_leave_state_t;

static void weather_cherry_tree_leaves_oam_callback_initialize(oam_object *self);
static void weather_cherry_tree_leaves_oam_callback_fall(oam_object *self);
// static void weather_cherry_tree_leaves_oam_callback_wait(oam_object *self);

static void weather_cherry_tree_leaves_oam_start_animation_by_slope(oam_object *self) {
    // TODO: pick suitable animation by slope
    any_leave_state_t *state = (any_leave_state_t*) self->private;
    u8 slope = state->slope;
    if (slope > 112) {
        oam_gfx_anim_start(self, (u8)(ANIM_HORIZONTAL + NUM_ANIMS * state->animation_color));
    } else if (slope > 104) {
        oam_gfx_anim_start(self, (u8)(ANIM_SEMI_HORIZONTAL + NUM_ANIMS * state->animation_color));
    } else {
        oam_gfx_anim_start(self, (u8)(ANIM_DIAGONAL + NUM_ANIMS * state->animation_color));
    }
}

// We have 32 oams that are distributed evenly in x-boxes of size 32 (8 boxes)

static inline bool weather_any_leaves_oam_is_off_screen(s16 y) {
    return y >= 160 + MARGIN && y <= 256 - MARGIN;
}

static void weather_any_leaves_calculate_position(oam_object *self) {
    any_leave_state_t *state = (any_leave_state_t*) self->private;
    int frame = state->frame;
    int x = (state->x0 + coordinate_camera_x_offset - frame * state->dxdt / 64); 
    int y = (state->y0 + coordinate_camera_y_offset + frame * state->dydt / 64);
    self->x = (s16)((x & 0xFF) - MARGIN / 2);
    self->y = (s16)(y & 0xFF);
}

static void weather_any_leaves_new_trajectory(any_leave_state_t *state) {
    state->x0 = (s16)((32 * (state->idx % 8) + (rnd16() % (MARGIN / 2))) & 0x7FF);
    state->slope = (u8)(112 - (SLOPE_RANGE / 2) + (rnd16() % SLOPE_RANGE));
    state->dydt = (u8)(32 - (SPEED_RANGE / 2) + (rnd16() % SPEED_RANGE));
    state->dxdt = (u8)(state->dydt * state->slope / 64);
    state->spin_frame = (u16)(rnd16() % 512);
    state->spin_enabled = true;
    state->animation_color = (u16)((rnd16() % (1 + state->num_animation_colors)) & 3);
}

static void weather_any_leaves_oam_callback_initialize(oam_object *self) {
    any_leave_state_t *state = (any_leave_state_t*) self->private;
    state->frame = 0;
    state->y0 = (u16)((-coordinate_camera_y_offset - MARGIN) & 0xFF);
    weather_any_leaves_new_trajectory(state);
    weather_cherry_tree_leaves_oam_start_animation_by_slope(self);
    self->flags &= (u16)(~OAM_FLAG_INVISIBLE);
    self->callback = weather_cherry_tree_leaves_oam_callback_fall;
}

static void weather_cherry_tree_leaves_oam_callback_initialize(oam_object *self) {
    any_leave_state_t *state = (any_leave_state_t*) self->private;
    state->num_animation_colors = 1 - 1; // only the first color is used (pink)
    weather_any_leaves_oam_callback_initialize(self);
}

static void weather_cherry_tree_leaves_oam_callback_spin(oam_object *self) {
    any_leave_state_t *state = (any_leave_state_t*) self->private;
    ++state->frame;
    weather_any_leaves_calculate_position(self);
    if (self->flags & OAM_FLAG_GFX_ANIM_END) {
        weather_cherry_tree_leaves_oam_start_animation_by_slope(self);
        self->callback = weather_cherry_tree_leaves_oam_callback_fall;
    }
}

static void weather_cherry_tree_leaves_oam_callback_calculate_new_trajectory(oam_object *self) {
    any_leave_state_t *state = (any_leave_state_t*) self->private;
    weather_any_leaves_new_trajectory(state);
    weather_any_leaves_calculate_position(self);
    if (weather_any_leaves_oam_is_off_screen(self->y)) {
        // If the trajectory has an off-screen sprite off-screen again, it therefore is valid
        // Resume the fall with the new trajectory
        self->callback = weather_cherry_tree_leaves_oam_callback_fall;
        self->flags &= (u16)(~OAM_FLAG_INVISIBLE);
    }
}

static void weather_cherry_tree_leaves_oam_callback_fall(oam_object *self) {
    any_leave_state_t *state = (any_leave_state_t*) self->private;
    int frame = ++state->frame; // 
    if (state->spin_enabled && (frame & 511) == state->spin_frame) {
        self->callback = weather_cherry_tree_leaves_oam_callback_spin;
        oam_gfx_anim_start(self, (u8)(ANIM_SPIN + NUM_ANIMS * state->animation_color));
        state->spin_enabled = false;
        return;
    }
    weather_any_leaves_calculate_position(self);
    if (state->new_trajectory_enabled && weather_any_leaves_oam_is_off_screen(self->y)) {
        // Off screen sprites can get a new trajectory (randomless looks nice after all)
        // Calculate a new trajectory each frame until we find one that is off-screen as well
        self->flags |= OAM_FLAG_INVISIBLE;
        self->callback = weather_cherry_tree_leaves_oam_callback_calculate_new_trajectory;
        state->new_trajectory_enabled = false;
    } else if (!state->new_trajectory_enabled && self->y >= 0 && self->y < 160) {
        // Sprite is visible again, so the next time it gets off-screen we calculate new trajectory parameters
        state->new_trajectory_enabled = true;
    }
}


extern LZ77COMPRESSED gfx_weather_cherry_tree_leavesTiles;
extern LZ77COMPRESSED gfx_weather_colorful_leavesTiles;

static sprite weather_any_leaves_sprite = {.attr0 = ATTR0_SHAPE_SQUARE, .attr1 = ATTR1_SIZE_16_16, .attr2 = ATTR2_PRIO(1)};

#define NUM_COLORS_FRAMES_PER_COLOR 4
#define GFX_COLOR_AND_FRAME(color_num, frame_num) ((frame_num + color_num * NUM_COLORS_FRAMES_PER_COLOR) * GRAPHIC_SIZE_4BPP_TO_NUM_TILES(16, 16))

static gfx_frame weather_cherry_tree_leaves_animation_idle_0[] = {
    {.data = GFX_COLOR_AND_FRAME(0, 0), .duration = 0}, {.data = GFX_ANIM_END},
};
static gfx_frame weather_cherry_tree_leaves_animation_idle_1[] = {
    {.data = GFX_COLOR_AND_FRAME(1, 0), .duration = 0}, {.data = GFX_ANIM_END},
};
static gfx_frame weather_cherry_tree_leaves_animation_idle_2[] = {
    {.data = GFX_COLOR_AND_FRAME(2, 0), .duration = 0}, {.data = GFX_ANIM_END},
};
static gfx_frame weather_cherry_tree_leaves_animation_idle_3[] = {
    {.data = GFX_COLOR_AND_FRAME(3, 0), .duration = 0}, {.data = GFX_ANIM_END},
};

static gfx_frame weather_cherry_tree_leaves_animation_horizontal_0[] = {
    {.data = GFX_COLOR_AND_FRAME(0, 3), .duration = 0}, 
    {.data = GFX_COLOR_AND_FRAME(0, 3), .duration = 24}, 
    {.data = GFX_COLOR_AND_FRAME(0, 3), .duration = 24 | GFX_ANIM_HFLIP},
    {.data = GFX_ANIM_JUMP, .duration = 0},
};
static gfx_frame weather_cherry_tree_leaves_animation_horizontal_1[] = {
    {.data = GFX_COLOR_AND_FRAME(1, 3), .duration = 0}, 
    {.data = GFX_COLOR_AND_FRAME(1, 3), .duration = 24}, 
    {.data = GFX_COLOR_AND_FRAME(1, 3), .duration = 24 | GFX_ANIM_HFLIP},
    {.data = GFX_ANIM_JUMP, .duration = 0},
};
static gfx_frame weather_cherry_tree_leaves_animation_horizontal_2[] = {
    {.data = GFX_COLOR_AND_FRAME(2, 3), .duration = 0}, 
    {.data = GFX_COLOR_AND_FRAME(2, 3), .duration = 24}, 
    {.data = GFX_COLOR_AND_FRAME(2, 3), .duration = 24 | GFX_ANIM_HFLIP},
    {.data = GFX_ANIM_JUMP, .duration = 0},
};
static gfx_frame weather_cherry_tree_leaves_animation_horizontal_3[] = {
    {.data = GFX_COLOR_AND_FRAME(3, 3), .duration = 0}, 
    {.data = GFX_COLOR_AND_FRAME(3, 3), .duration = 24}, 
    {.data = GFX_COLOR_AND_FRAME(3, 3), .duration = 24 | GFX_ANIM_HFLIP},
    {.data = GFX_ANIM_JUMP, .duration = 0},
};

static gfx_frame weather_cherry_tree_leaves_animation_semi_horizontal_0[] = {
    {.data = GFX_COLOR_AND_FRAME(0, 2), .duration = 0}, 
    {.data = GFX_COLOR_AND_FRAME(0, 2), .duration = 16},
    {.data = GFX_COLOR_AND_FRAME(0, 3), .duration = 16}, 
    {.data = GFX_COLOR_AND_FRAME(0, 3), .duration = 16 | GFX_ANIM_HFLIP},
    {.data = GFX_ANIM_JUMP, .duration = 0},
};
static gfx_frame weather_cherry_tree_leaves_animation_semi_horizontal_1[] = {
    {.data = GFX_COLOR_AND_FRAME(1, 2), .duration = 0}, 
    {.data = GFX_COLOR_AND_FRAME(1, 2), .duration = 16},
    {.data = GFX_COLOR_AND_FRAME(1, 3), .duration = 16}, 
    {.data = GFX_COLOR_AND_FRAME(1, 3), .duration = 16 | GFX_ANIM_HFLIP},
    {.data = GFX_ANIM_JUMP, .duration = 0},
};
static gfx_frame weather_cherry_tree_leaves_animation_semi_horizontal_2[] = {
    {.data = GFX_COLOR_AND_FRAME(2, 2), .duration = 0}, 
    {.data = GFX_COLOR_AND_FRAME(2, 2), .duration = 16},
    {.data = GFX_COLOR_AND_FRAME(2, 3), .duration = 16}, 
    {.data = GFX_COLOR_AND_FRAME(2, 3), .duration = 16 | GFX_ANIM_HFLIP},
    {.data = GFX_ANIM_JUMP, .duration = 0},
};
static gfx_frame weather_cherry_tree_leaves_animation_semi_horizontal_3[] = {
    {.data = GFX_COLOR_AND_FRAME(3, 2), .duration = 0}, 
    {.data = GFX_COLOR_AND_FRAME(3, 2), .duration = 16},
    {.data = GFX_COLOR_AND_FRAME(3, 3), .duration = 16}, 
    {.data = GFX_COLOR_AND_FRAME(3, 3), .duration = 16 | GFX_ANIM_HFLIP},
    {.data = GFX_ANIM_JUMP, .duration = 0},
};

static gfx_frame weather_cherry_tree_leaves_animation_diagonal_0[] = {
    {.data = GFX_COLOR_AND_FRAME(0, 1), .duration = 0}, 
    {.data = GFX_COLOR_AND_FRAME(0, 1), .duration = 16},
    {.data = GFX_COLOR_AND_FRAME(0, 2), .duration = 16}, 
    {.data = GFX_COLOR_AND_FRAME(0, 3), .duration = 8},
    {.data = GFX_COLOR_AND_FRAME(0, 2), .duration = 16}, 
    {.data = GFX_ANIM_JUMP, .duration = 0},
};
static gfx_frame weather_cherry_tree_leaves_animation_diagonal_1[] = {
    {.data = GFX_COLOR_AND_FRAME(1, 1), .duration = 0}, 
    {.data = GFX_COLOR_AND_FRAME(1, 1), .duration = 16},
    {.data = GFX_COLOR_AND_FRAME(1, 2), .duration = 16}, 
    {.data = GFX_COLOR_AND_FRAME(1, 3), .duration = 8},
    {.data = GFX_COLOR_AND_FRAME(1, 2), .duration = 16}, 
    {.data = GFX_ANIM_JUMP, .duration = 0},
};
static gfx_frame weather_cherry_tree_leaves_animation_diagonal_2[] = {
    {.data = GFX_COLOR_AND_FRAME(2, 1), .duration = 0}, 
    {.data = GFX_COLOR_AND_FRAME(2, 1), .duration = 16},
    {.data = GFX_COLOR_AND_FRAME(2, 2), .duration = 16}, 
    {.data = GFX_COLOR_AND_FRAME(2, 3), .duration = 8},
    {.data = GFX_COLOR_AND_FRAME(2, 2), .duration = 16}, 
    {.data = GFX_ANIM_JUMP, .duration = 0},
};
static gfx_frame weather_cherry_tree_leaves_animation_diagonal_3[] = {
    {.data = GFX_COLOR_AND_FRAME(3, 1), .duration = 0}, 
    {.data = GFX_COLOR_AND_FRAME(3, 1), .duration = 16},
    {.data = GFX_COLOR_AND_FRAME(3, 2), .duration = 16}, 
    {.data = GFX_COLOR_AND_FRAME(3, 3), .duration = 8},
    {.data = GFX_COLOR_AND_FRAME(3, 2), .duration = 16}, 
    {.data = GFX_ANIM_JUMP, .duration = 0},
};

static gfx_frame weather_cherry_tree_leaves_animation_spin_0[] = {
    {.data = GFX_COLOR_AND_FRAME(0, 2), .duration = 0}, 
    {.data = GFX_COLOR_AND_FRAME(0, 2), .duration = 4},
    {.data = GFX_COLOR_AND_FRAME(0, 3), .duration = 4}, 
    {.data = GFX_COLOR_AND_FRAME(0, 3), .duration = 4 | GFX_ANIM_HFLIP},
    {.data = GFX_COLOR_AND_FRAME(0, 2), .duration = 4 | GFX_ANIM_HFLIP}, 
    {.data = GFX_COLOR_AND_FRAME(0, 1), .duration = 4 | GFX_ANIM_HFLIP},
    {.data = GFX_COLOR_AND_FRAME(0, 0), .duration = 4 | GFX_ANIM_HFLIP}, 
    {.data = GFX_COLOR_AND_FRAME(0, 1), .duration = 4 | GFX_ANIM_HFLIP | GFX_ANIM_VFLIP},
    {.data = GFX_COLOR_AND_FRAME(0, 1), .duration = 4 | GFX_ANIM_VFLIP}, 
    {.data = GFX_COLOR_AND_FRAME(0, 1), .duration = 4}, 
    {.data = GFX_COLOR_AND_FRAME(0, 2), .duration = 4}, 
    {.data = GFX_COLOR_AND_FRAME(0, 3), .duration = 4}, 
    {.data = GFX_ANIM_END},
};
static gfx_frame weather_cherry_tree_leaves_animation_spin_1[] = {
    {.data = GFX_COLOR_AND_FRAME(1, 2), .duration = 0}, 
    {.data = GFX_COLOR_AND_FRAME(1, 2), .duration = 4},
    {.data = GFX_COLOR_AND_FRAME(1, 3), .duration = 4}, 
    {.data = GFX_COLOR_AND_FRAME(1, 3), .duration = 4 | GFX_ANIM_HFLIP},
    {.data = GFX_COLOR_AND_FRAME(1, 2), .duration = 4 | GFX_ANIM_HFLIP}, 
    {.data = GFX_COLOR_AND_FRAME(1, 1), .duration = 4 | GFX_ANIM_HFLIP},
    {.data = GFX_COLOR_AND_FRAME(1, 0), .duration = 4 | GFX_ANIM_HFLIP}, 
    {.data = GFX_COLOR_AND_FRAME(1, 1), .duration = 4 | GFX_ANIM_HFLIP | GFX_ANIM_VFLIP},
    {.data = GFX_COLOR_AND_FRAME(1, 1), .duration = 4 | GFX_ANIM_VFLIP}, 
    {.data = GFX_COLOR_AND_FRAME(1, 1), .duration = 4}, 
    {.data = GFX_COLOR_AND_FRAME(1, 2), .duration = 4}, 
    {.data = GFX_COLOR_AND_FRAME(1, 3), .duration = 4}, 
    {.data = GFX_ANIM_END},
};
static gfx_frame weather_cherry_tree_leaves_animation_spin_2[] = {
    {.data = GFX_COLOR_AND_FRAME(2, 2), .duration = 0}, 
    {.data = GFX_COLOR_AND_FRAME(2, 2), .duration = 4},
    {.data = GFX_COLOR_AND_FRAME(2, 3), .duration = 4}, 
    {.data = GFX_COLOR_AND_FRAME(2, 3), .duration = 4 | GFX_ANIM_HFLIP},
    {.data = GFX_COLOR_AND_FRAME(2, 2), .duration = 4 | GFX_ANIM_HFLIP}, 
    {.data = GFX_COLOR_AND_FRAME(2, 1), .duration = 4 | GFX_ANIM_HFLIP},
    {.data = GFX_COLOR_AND_FRAME(2, 0), .duration = 4 | GFX_ANIM_HFLIP}, 
    {.data = GFX_COLOR_AND_FRAME(2, 1), .duration = 4 | GFX_ANIM_HFLIP | GFX_ANIM_VFLIP},
    {.data = GFX_COLOR_AND_FRAME(2, 1), .duration = 4 | GFX_ANIM_VFLIP}, 
    {.data = GFX_COLOR_AND_FRAME(2, 1), .duration = 4}, 
    {.data = GFX_COLOR_AND_FRAME(2, 2), .duration = 4}, 
    {.data = GFX_COLOR_AND_FRAME(2, 3), .duration = 4}, 
    {.data = GFX_ANIM_END},
};
static gfx_frame weather_cherry_tree_leaves_animation_spin_3[] = {
    {.data = GFX_COLOR_AND_FRAME(3, 2), .duration = 0}, 
    {.data = GFX_COLOR_AND_FRAME(3, 2), .duration = 4},
    {.data = GFX_COLOR_AND_FRAME(3, 3), .duration = 4}, 
    {.data = GFX_COLOR_AND_FRAME(3, 3), .duration = 4 | GFX_ANIM_HFLIP},
    {.data = GFX_COLOR_AND_FRAME(3, 2), .duration = 4 | GFX_ANIM_HFLIP}, 
    {.data = GFX_COLOR_AND_FRAME(3, 1), .duration = 4 | GFX_ANIM_HFLIP},
    {.data = GFX_COLOR_AND_FRAME(3, 0), .duration = 4 | GFX_ANIM_HFLIP}, 
    {.data = GFX_COLOR_AND_FRAME(3, 1), .duration = 4 | GFX_ANIM_HFLIP | GFX_ANIM_VFLIP},
    {.data = GFX_COLOR_AND_FRAME(3, 1), .duration = 4 | GFX_ANIM_VFLIP}, 
    {.data = GFX_COLOR_AND_FRAME(3, 1), .duration = 4}, 
    {.data = GFX_COLOR_AND_FRAME(3, 2), .duration = 4}, 
    {.data = GFX_COLOR_AND_FRAME(3, 3), .duration = 4}, 
    {.data = GFX_ANIM_END},
};

static gfx_frame *weather_any_leaves_animations[] = {
    [ANIM_IDLE + 0 * NUM_ANIMS] = weather_cherry_tree_leaves_animation_idle_0,
    [ANIM_HORIZONTAL + 0 * NUM_ANIMS] = weather_cherry_tree_leaves_animation_horizontal_0,
    [ANIM_SEMI_HORIZONTAL + 0 * NUM_ANIMS] = weather_cherry_tree_leaves_animation_semi_horizontal_0,
    [ANIM_DIAGONAL + 0 * NUM_ANIMS] = weather_cherry_tree_leaves_animation_diagonal_0,
    [ANIM_SPIN + 0 * NUM_ANIMS] = weather_cherry_tree_leaves_animation_spin_0,
    [ANIM_IDLE + 1 * NUM_ANIMS] = weather_cherry_tree_leaves_animation_idle_1,
    [ANIM_HORIZONTAL + 1 * NUM_ANIMS] = weather_cherry_tree_leaves_animation_horizontal_1,
    [ANIM_SEMI_HORIZONTAL + 1 * NUM_ANIMS] = weather_cherry_tree_leaves_animation_semi_horizontal_1,
    [ANIM_DIAGONAL + 1 * NUM_ANIMS] = weather_cherry_tree_leaves_animation_diagonal_1,
    [ANIM_SPIN + 1 * NUM_ANIMS] = weather_cherry_tree_leaves_animation_spin_1,
    [ANIM_IDLE + 2 * NUM_ANIMS] = weather_cherry_tree_leaves_animation_idle_2,
    [ANIM_HORIZONTAL + 2 * NUM_ANIMS] = weather_cherry_tree_leaves_animation_horizontal_2,
    [ANIM_SEMI_HORIZONTAL + 2 * NUM_ANIMS] = weather_cherry_tree_leaves_animation_semi_horizontal_2,
    [ANIM_DIAGONAL + 2 * NUM_ANIMS] = weather_cherry_tree_leaves_animation_diagonal_2,
    [ANIM_SPIN + 2 * NUM_ANIMS] = weather_cherry_tree_leaves_animation_spin_2,
    [ANIM_IDLE + 3 * NUM_ANIMS] = weather_cherry_tree_leaves_animation_idle_3,
    [ANIM_HORIZONTAL + 3 * NUM_ANIMS] = weather_cherry_tree_leaves_animation_horizontal_3,
    [ANIM_SEMI_HORIZONTAL + 3 * NUM_ANIMS] = weather_cherry_tree_leaves_animation_semi_horizontal_3,
    [ANIM_DIAGONAL + 3 * NUM_ANIMS] = weather_cherry_tree_leaves_animation_diagonal_3,
    [ANIM_SPIN + 3 * NUM_ANIMS] = weather_cherry_tree_leaves_animation_spin_3,
};

static oam_template weather_cherry_tree_leaves_template = {
    .tiles_tag = OVERWORLD_WEATHER_CHERRY_TREE_LEAVES_GFX_TAG, .pal_tag = 0x1200,
    .oam = &weather_any_leaves_sprite,
    .animation = weather_any_leaves_animations,
    .graphics = NULL,
    .rotscale = oam_rotscale_anim_table_null,
    .callback = weather_cherry_tree_leaves_oam_callback_initialize,
};

void weather_cherry_tree_leaves_initialize_variables() {
    // DEBUG("Cherry tree init vars.\n");
    overworld_weather.init_step = 0;
    overworld_weather.gamma_to = 0;
    overworld_weather.gamma_step_delay = 20;
    overworld_weather.cherry_tree_target_num_oams = CHERRY_TREE_LEAVES_NUM_OAMS;
    overworld_weather.cherry_tree_new_timer = 0;
    overworld_weather.cherry_tree_oam_group_head = NUM_OAMS; // Every new "wave" of particles that stays is within a new group
}

static void weather_cherry_tree_leaves_create_oam() {
    if (overworld_weather.cherry_tree_num_oams == 0)
        overworld_weather.cherry_tree_oam_group_head = NUM_OAMS;

    u8 idx = overworld_weather.cherry_tree_num_oams;
    u8 oam_idx = oam_new_backward_search(&weather_cherry_tree_leaves_template, 0, 250, 78);
    if (overworld_weather.cherry_tree_oam_group_head == NUM_OAMS)
        overworld_weather.cherry_tree_oam_group_head = oam_idx;

    if (oam_idx < NUM_OAMS) {
        overworld_weather.cherry_tree_num_oams_visible++;
        overworld_weather.sprites.s1.any_leave_sprites[idx] = oams + oam_idx;
        any_leave_state_t *state = (any_leave_state_t*) oams[oam_idx].private;
        state->idx = overworld_weather.cherry_tree_num_oams;

        if (oam_idx != overworld_weather.cherry_tree_oam_group_head) {
            oam_add_to_group(oam_idx, overworld_weather.cherry_tree_oam_group_head);
            // DEBUG("Added oam to group head %d\n", overworld_weather.cherry_tree_oam_group_head);
        }
    } else {    
        overworld_weather.sprites.s1.any_leave_sprites[idx] = NULL;
    }
    // DEBUG("Created new cherry leave oam with idx %d as the %d-th.\n", oam_idx, idx);
    overworld_weather.cherry_tree_num_oams++;
}

static void weather_cherry_tree_leaves_oam_callback_delete_oam(oam_object *self) {
    any_leave_state_t *state = (any_leave_state_t*) self->private;
    ++state->frame;
    weather_any_leaves_calculate_position(self);
    // DEBUG("Leave %d waits for deletion at %d\n", state->idx, self->y);
    if (weather_any_leaves_oam_is_off_screen(self->y) || --state->deletion_timer == 0) {
        // Sprite is off-screen, we can hide it
        // DEBUG("[0x%x] : Idx %d is off-screen at %d, remaining %d\n", _main_rnd & 0xFF, state->idx, self->y, overworld_weather.cherry_tree_num_oams_visible);
        oam_clear(self);
        overworld_weather.cherry_tree_num_oams_visible--;
    }
}

static void weather_cherry_tree_leaves_delete_oam() {
    if (overworld_weather.cherry_tree_num_oams > 0) {
        oam_object **o = overworld_weather.sprites.s1.any_leave_sprites + (--overworld_weather.cherry_tree_num_oams);
        if (*o) {
            any_leave_state_t *state = (any_leave_state_t*) (*o)->private;
            state->deletion_timer = (u16)((rnd16() % (MAX_TIME_DELETE - MIN_TIME_DELETE)) + MIN_TIME_DELETE);
            (*o)->callback = weather_cherry_tree_leaves_oam_callback_delete_oam;
        }
        *o = NULL;
    } else {
        DEBUG("Attempting to delete oams that are not there. There is a bug!\n");
    }
}

static bool weather_cherry_tree_leaves_create_or_delete_oam() {
    if (overworld_weather.cherry_tree_num_oams < overworld_weather.cherry_tree_target_num_oams) {
        if (overworld_weather.cherry_tree_num_oams_visible < MAX_NUM_VISIBLE) {
            // There should never be too many oams visible. Possibly some cherry tree leaves
            // that are flagged for deletion are still present (from a previous weather transition)
            // we let those get deleted before spawning new particles
            weather_cherry_tree_leaves_create_oam();
        }
    } else if (overworld_weather.cherry_tree_num_oams > overworld_weather.cherry_tree_target_num_oams) {
        weather_cherry_tree_leaves_delete_oam();
    }
    return overworld_weather.cherry_tree_num_oams != overworld_weather.cherry_tree_target_num_oams;
}

static graphic graphic_cherry_tree_leaves = {
    .sprite = gfx_weather_cherry_tree_leavesTiles, 
    .size = GRAPHIC_SIZE_4BPP(16, 64), 
    .tag = OVERWORLD_WEATHER_CHERRY_TREE_LEAVES_GFX_TAG
};

static void weather_cherry_tree_leaves_allocate_gfx() {
    if (oam_vram_get_tile(graphic_cherry_tree_leaves.tag) == 0xFFFF)
        oam_load_graphic_using_heap(&graphic_cherry_tree_leaves);
}

static void cherry_tree_leaves_free_gfx() {
    oam_free_vram_by_tag(graphic_cherry_tree_leaves.tag);
}

void weather_cherry_tree_leaves_main() {
    switch (overworld_weather.init_step){
        case 0: {
            weather_cherry_tree_leaves_allocate_gfx();
            overworld_weather.init_step++;
            break;
        }
        case 1: {
            // Periodically create a new oam until all created
            if (++overworld_weather.cherry_tree_new_timer > NEW_PERIOD) {
                overworld_weather.cherry_tree_new_timer = 0; // Reset the timer
                if (!weather_cherry_tree_leaves_create_or_delete_oam())
                    overworld_weather.init_step++;
            }
            break;
        }
    }
}

void weather_cherry_tree_leaves_initialize_all() {
    weather_cherry_tree_leaves_initialize_variables();
    weather_cherry_tree_leaves_allocate_gfx();
    // Initialize all oams
    for (int i = 0; i < overworld_weather.cherry_tree_target_num_oams; i++){
        int idx = overworld_weather.cherry_tree_num_oams;
        weather_cherry_tree_leaves_create_oam();
        oam_object *o = overworld_weather.sprites.s1.any_leave_sprites[idx];
        if (o) {
            any_leave_state_t *state = (any_leave_state_t*)o->private;
            weather_cherry_tree_leaves_oam_callback_initialize(o);
            state->frame = (u16)(i * NEW_PERIOD);
        }
    }
}

bool weather_cherry_tree_leaves_closure() {
    DEBUG("Weather cherry tree closure in step %d, num visible %d\n", overworld_weather.finish_step, overworld_weather.cherry_tree_num_oams_visible);
    switch (overworld_weather.finish_step) {
        case 0: {   
            overworld_weather.cherry_tree_target_num_oams = 0;
            overworld_weather.cherry_tree_new_timer = 0; // Timer
            overworld_weather.finish_step++;
            FALL_THROUGH;
        }
        case 1 : {
            // Flag all oams for deletion, they will themselves despawn once off-screen
            while (weather_cherry_tree_leaves_create_or_delete_oam()) {}
            overworld_weather.finish_step++;
            return true;

            // // Periodically delete an oam until all deleted
            // if (++overworld_weather.cherry_tree_new_timer > DELETE_PERIOD) {
            //     overworld_weather.cherry_tree_new_timer = 0; // Reset the timer
            //     if (!weather_cherry_tree_leaves_create_or_delete_oam()) {
            //         overworld_weather.finish_step++;
            //     }
            // }
            // return true;
        }
        case 2: {
            if (overworld_weather.cherry_tree_num_oams_visible == 0) {
                cherry_tree_leaves_free_gfx();
                overworld_weather.finish_step++;
                return false;
            } else {
                return true;
            }
        }
    }
    return false;
}

static void weather_colorful_petals_oam_callback_initialize(oam_object *self) {
    any_leave_state_t *state = (any_leave_state_t*) self->private;
    state->num_animation_colors = 4 - 1; // 4 colors are used
    weather_any_leaves_oam_callback_initialize(self);
}

static oam_template weather_colorful_petals_template = {
    .tiles_tag = OVERWORLD_WEATHER_COLORFUL_PETALS_GFX_TAG, .pal_tag = 0x1200,
    .oam = &weather_any_leaves_sprite,
    .animation = weather_any_leaves_animations,
    .graphics = NULL,
    .rotscale = oam_rotscale_anim_table_null,
    .callback = weather_colorful_petals_oam_callback_initialize,
};

void weather_colorful_petals_initialize_variables() {
    // DEBUG("Cherry tree init vars.\n");
    overworld_weather.init_step = 0;
    overworld_weather.gamma_to = OVERWORLD_WEATHER_COLORFUL_PETALS_GAMMA;
    overworld_weather.gamma_step_delay = 20;
    overworld_weather.colorful_petals_target_num_oams = COLORFUL_PETALS_NUM_OAMS;
    overworld_weather.colorful_petals_new_timer = 0;
    overworld_weather.colorful_petals_oam_group_head = NUM_OAMS; // Every new "wave" of particles that stays is within a new group
}

static void weather_colorful_petals_create_oam() {
    if (overworld_weather.colorful_petals_num_oams == 0)
        overworld_weather.colorful_petals_oam_group_head = NUM_OAMS;

    u8 idx = overworld_weather.colorful_petals_num_oams;
    u8 oam_idx = oam_new_backward_search(&weather_colorful_petals_template, 0, 250, 78);
    if (overworld_weather.colorful_petals_oam_group_head == NUM_OAMS)
        overworld_weather.colorful_petals_oam_group_head = oam_idx;

    if (oam_idx < NUM_OAMS) {
        overworld_weather.colorful_petals_num_oams_visible++;
        overworld_weather.sprites.s1.any_leave_sprites[idx] = oams + oam_idx;
        any_leave_state_t *state = (any_leave_state_t*) oams[oam_idx].private;
        state->idx = overworld_weather.colorful_petals_num_oams;

        if (oam_idx != overworld_weather.colorful_petals_oam_group_head) {
            oam_add_to_group(oam_idx, overworld_weather.colorful_petals_oam_group_head);
            // DEBUG("Added oam to group head %d\n", overworld_weather.cherry_tree_oam_group_head);
        }
    } else {    
        overworld_weather.sprites.s1.any_leave_sprites[idx] = NULL;
    }
    // DEBUG("Created new cherry leave oam with idx %d as the %d-th.\n", oam_idx, idx);
    overworld_weather.colorful_petals_num_oams++;
}

static void weather_colorful_petals_oam_callback_delete_oam(oam_object *self) {
    any_leave_state_t *state = (any_leave_state_t*) self->private;
    ++state->frame;
    weather_any_leaves_calculate_position(self);
    // DEBUG("Leave %d waits for deletion at %d\n", state->idx, self->y);
    if (weather_any_leaves_oam_is_off_screen(self->y) || --state->deletion_timer == 0) {
        // Sprite is off-screen, we can hide it
        // DEBUG("[0x%x] : Idx %d is off-screen at %d, remaining %d\n", _main_rnd & 0xFF, state->idx, self->y, overworld_weather.cherry_tree_num_oams_visible);
        oam_clear(self);
        overworld_weather.colorful_petals_num_oams_visible--;
    }
}

static void weather_colorful_petals_delete_oam() {
    if (overworld_weather.colorful_petals_num_oams > 0) {
        oam_object **o = overworld_weather.sprites.s1.any_leave_sprites + (--overworld_weather.colorful_petals_num_oams);
        if (*o) {
            any_leave_state_t *state = (any_leave_state_t*) (*o)->private;
            state->deletion_timer = (u16)((rnd16() % (MAX_TIME_DELETE - MIN_TIME_DELETE)) + MIN_TIME_DELETE);
            (*o)->callback = weather_colorful_petals_oam_callback_delete_oam;
        }
        *o = NULL;
    } else {
        DEBUG("Attempting to delete oams that are not there. There is a bug!\n");
    }
}

static bool weather_colorful_petals_create_or_delete_oam() {
    if (overworld_weather.colorful_petals_num_oams < overworld_weather.colorful_petals_target_num_oams) {
        if (overworld_weather.colorful_petals_num_oams_visible < MAX_NUM_VISIBLE) {
            // There should never be too many oams visible. Possibly some cherry tree leaves
            // that are flagged for deletion are still present (from a previous weather transition)
            // we let those get deleted before spawning new particles
            weather_colorful_petals_create_oam();
        }
    } else if (overworld_weather.colorful_petals_num_oams > overworld_weather.colorful_petals_target_num_oams) {
        weather_colorful_petals_delete_oam();
    }
    return overworld_weather.colorful_petals_num_oams != overworld_weather.colorful_petals_target_num_oams;
}

static graphic graphic_colorful_petals = {
    .sprite = gfx_weather_colorful_leavesTiles, 
    .size = 4 * 4 * GRAPHIC_SIZE_4BPP(16, 16), 
    .tag = OVERWORLD_WEATHER_COLORFUL_PETALS_GFX_TAG,
};

static void weather_colorful_petals_allocate_gfx() {
    if (oam_vram_get_tile(graphic_colorful_petals.tag) == 0xFFFF) {
        oam_load_graphic_using_heap(&graphic_colorful_petals);
        DEBUG("Loaded colorful petals to tile num %d\n", oam_vram_get_tile(graphic_colorful_petals.tag));
    }
}

static void colorful_petals_free_gfx() {
    oam_free_vram_by_tag(graphic_colorful_petals.tag);
}

void weather_colorful_petals_main() {
    switch (overworld_weather.init_step){
        case 0: {
            weather_colorful_petals_allocate_gfx();
            overworld_weather.init_step++;
            break;
        }
        case 1: {
            // Periodically create a new oam until all created
            if (++overworld_weather.colorful_petals_new_timer > NEW_PERIOD) {
                overworld_weather.colorful_petals_new_timer = 0; // Reset the timer
                if (!weather_colorful_petals_create_or_delete_oam())
                    overworld_weather.init_step++;
            }
            break;
        }
    }
}

void weather_colorful_petals_initialize_all() {
    weather_colorful_petals_initialize_variables();
    weather_colorful_petals_allocate_gfx();
    // Initialize all oams
    for (int i = 0; i < overworld_weather.colorful_petals_target_num_oams; i++){
        int idx = overworld_weather.colorful_petals_num_oams;
        weather_colorful_petals_create_oam();
        oam_object *o = overworld_weather.sprites.s1.any_leave_sprites[idx];
        if (o) {
            any_leave_state_t *state = (any_leave_state_t*)o->private;
            weather_colorful_petals_oam_callback_initialize(o);
            state->frame = (u16)(i * NEW_PERIOD);
        }
    }
}

bool weather_colorful_petals_closure() {
    DEBUG("Weather colorful_petals closure in step %d, num visible %d\n", overworld_weather.finish_step, overworld_weather.colorful_petals_num_oams_visible);
    switch (overworld_weather.finish_step) {
        case 0: {   
            overworld_weather.colorful_petals_target_num_oams = 0;
            overworld_weather.colorful_petals_new_timer = 0; // Timer
            overworld_weather.finish_step++;
            FALL_THROUGH;
        }
        case 1 : {
            // Flag all oams for deletion, they will themselves despawn once off-screen
            while (weather_colorful_petals_create_or_delete_oam()) {}
            overworld_weather.finish_step++;
            return true;

            // // Periodically delete an oam until all deleted
            // if (++overworld_weather.cherry_tree_new_timer > DELETE_PERIOD) {
            //     overworld_weather.cherry_tree_new_timer = 0; // Reset the timer
            //     if (!weather_cherry_tree_leaves_create_or_delete_oam()) {
            //         overworld_weather.finish_step++;
            //     }
            // }
            // return true;
        }
        case 2: {
            if (overworld_weather.colorful_petals_num_oams_visible == 0) {
                colorful_petals_free_gfx();
                overworld_weather.finish_step++;
                return false;
            } else {
                return true;
            }
        }
    }
    return false;
}
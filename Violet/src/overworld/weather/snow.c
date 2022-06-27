#include "types.h"
#include "overworld/weather.h"
#include "oam.h"
#include "debug.h"
#include "math.h"
#include "prng.h"

#define SNOW_PERIOD 256
#define SNOW_NEW_PERIOD 30

#define t_x private[0]
#define t_y private[1]
// in 256-th
#define t_dydt private[2]
#define t_frame private[3]
#define t_xduration private[4]
#define t_theta_frame_offset private[5]
#define t_x_amplitude private[6]
#define t_y_end private[7]

static void weather_snow_oam_callback_initialize(oam_object *self);
static void weather_snow_oam_callback_fall(oam_object *self);
static void weather_snow_oam_callback_wait(oam_object *self);

static void weather_snow_oam_callback_initialize(oam_object *self) {
    self->t_x = (u16)(rnd16() % 256);
    self->t_y = (u16)((-coordinate_camera_y_offset - 8) & 0xFF); // Spawn slightly above 0
    self->t_dydt = (u16)(64 + (rnd16() % 128));
    self->t_xduration = (u16)(160 + (rnd16() % 80));
    self->t_frame = 0;
    self->t_theta_frame_offset = (u16)(rnd16() % 80);
    self->t_x_amplitude = (u16)(1 + (rnd16() % 3));
    self->t_y_end = (u16)(125 + (rnd16() % 25));
    oam_gfx_anim_start(self, rnd16() & 1 ? 0 : 1);
    self->flags &= (u16)(~OAM_FLAG_INVISIBLE);
    self->callback = weather_snow_oam_callback_fall;
    // self->flags |= OAM_FLAG_CENTERED;
}

static void weather_snow_oam_callback_fall(oam_object *self) {
    int dy = self->t_dydt * self->t_frame / 256;
    // amplitude * sin(2pi / duration * 3t/2)
    int theta = FIXED_DIV(FIXED_MUL(FIXED_DIV(INT_TO_FIXED(3), INT_TO_FIXED(2)), INT_TO_FIXED(self->t_frame + self->t_theta_frame_offset)), INT_TO_FIXED(self->t_xduration));
    int dx = FIXED_TO_INT(FIXED_MUL(INT_TO_FIXED(self->t_x_amplitude), FIXED_SIN(theta)));
    int x = (self->t_x + coordinate_camera_x_offset + dx) & 0xFF;
    int y = (self->t_y + dy + coordinate_camera_y_offset) & 0xFF;
    self->x = (s16)x;
    self->y = (s16)y;
    self->t_frame++;

    // Sprite will be invisible if it is outside the visible range
    // x: visible [0, 240 + 4]
    // y : visible [0, 160 + 4] ... [252, 0] (wrap arround)
    if ((y >= 164 && y < 252)) {
        self->flags |= OAM_FLAG_INVISIBLE;
        self->y = 250;
    } else if (y >= self->t_y_end && y <= 164) {
        // Sprite has reached the ground, it should disappear (i.e. the cycle resets)
        self->flags |= OAM_FLAG_INVISIBLE;
        self->y = 250;
        self->callback = weather_snow_oam_callback_wait;
    } else {
        self->flags &= (u16)(~OAM_FLAG_INVISIBLE);
    }
}

static void weather_snow_oam_callback_wait(oam_object *self) {
    u16 frame = self->t_frame++;
    if (frame >= SNOW_PERIOD) {
        weather_snow_oam_callback_initialize(self);
    }
}

static oam_template weather_snow_oam_template = {
    .tiles_tag = 0xFFFF, .pal_tag = 0x1200,
    .oam = &overworld_weather_snow_sprite,
    .animation = overworld_weather_snow_animations,
    .graphics = overworld_weather_snow_graphics,
    .rotscale = oam_rotscale_anim_table_null,
    .callback = weather_snow_oam_callback_initialize,
};

void weather_snow_initialize_variables() {
    DEBUG("Snow init vars.\n");
    overworld_weather.init_step = 0;
    overworld_weather.weather_gfx_loaded = false;
    overworld_weather.gamma_to = 0;
    overworld_weather.gamma_step_delay = 20;
    overworld_weather.target_snowflake_sprite_count = 16;
    overworld_weather.snowflake_visible_count = 0;
}

static void weather_snow_create_oam() {
    if (overworld_weather.snowflake_sprite_count == 0)
        overworld_weather.snow_group_head = NUM_OAMS;

    u8 idx = overworld_weather.snowflake_sprite_count;
    u8 oam_idx = oam_new_backward_search(&weather_snow_oam_template, 0, 250, 78);
    if (overworld_weather.snow_group_head == NUM_OAMS)
        overworld_weather.snow_group_head = oam_idx;

    if (oam_idx < NUM_OAMS) {
        overworld_weather.sprites.s1.snowflakeSprites[idx] = oams + oam_idx;
        if (oam_idx != overworld_weather.snow_group_head)
            oam_add_to_group(oam_idx, overworld_weather.snow_group_head);
    } else {    
        overworld_weather.sprites.s1.snowflakeSprites[idx] = NULL;
    }
    // DEBUG("Created new snowflake oam with idx %d as the %d-th.\n", oam_idx, idx);
    overworld_weather.snowflake_sprite_count++;
}

static void weather_snow_delete_oam() {
    if (overworld_weather.snowflake_sprite_count > 0) {
        oam_object **o = overworld_weather.sprites.s1.snowflakeSprites + (--overworld_weather.snowflake_sprite_count);
        if (*o)
            oam_delete(*o);
        // DEBUG("Deleted new snowflake oam at 0x%x with snowflake idx %d\n", *o, overworld_weather.snowflake_sprite_count);
        *o = NULL;
    }
}

static bool weather_snow_create_or_delete_oam() {
    if (overworld_weather.snowflake_sprite_count < overworld_weather.target_snowflake_sprite_count) {
        weather_snow_create_oam();
    } else if (overworld_weather.snowflake_sprite_count > overworld_weather.target_snowflake_sprite_count) {
        weather_snow_delete_oam();
    }
    return overworld_weather.snowflake_sprite_count != overworld_weather.target_snowflake_sprite_count;
}


void weather_snow_main() {
    switch (overworld_weather.init_step){
        case 0: {
            // Periodically create a new snowflake oam until all created
            if (++overworld_weather.snowflake_visible_count > SNOW_NEW_PERIOD) {
                overworld_weather.snowflake_visible_count = 0; // Reset the timer
                if (!weather_snow_create_or_delete_oam())
                    overworld_weather.init_step++;
            }
            break;
        }
        case 1: {
            break;
        }
    }
}

void weather_snow_initialize_all() {
    DEBUG("Snow init all.\n");
    weather_snow_initialize_variables();
    // Initialize all snowflakes
    for (int i = 0; i < overworld_weather.target_snowflake_sprite_count; i++){
        int idx = overworld_weather.snowflake_sprite_count;
        weather_snow_create_oam();
        oam_object *o = overworld_weather.sprites.s1.snowflakeSprites[idx];
        if (o) {
            weather_snow_oam_callback_initialize(o);
            o->t_frame = ((u16)(i * SNOW_NEW_PERIOD) % SNOW_PERIOD);
        }
    }
}

bool weather_snow_closure() {
    switch (overworld_weather.finish_step) {
        case 0: {   
            overworld_weather.target_snowflake_sprite_count = 0;
            overworld_weather.snowflake_visible_count = 0; // Timer
            overworld_weather.finish_step++;
            FALL_THROUGH;
        }
        case 1 : {
            // Periodically delete a  snowflake oam until all deleted
            if (++overworld_weather.snowflake_visible_count > SNOW_NEW_PERIOD) {
                overworld_weather.snowflake_visible_count = 0; // Reset the timer
                if (!weather_snow_create_or_delete_oam()) {
                    overworld_weather.finish_step++;
                    return false;
                }
            }
            return true;
        }
    }
    return false;
}
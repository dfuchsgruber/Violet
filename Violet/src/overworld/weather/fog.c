
#include "types.h"
#include "overworld/weather.h"
#include "oam.h"
#include "debug.h"

extern const oam_template overworld_weather_dynamic_fog_oam_template;
extern const graphic overworld_weather_dynamic_fog_graphic;

void overworld_weather_dynamic_fog_create_oams() {
    if (!overworld_weather.fog_d_oams_created) {
        oam_load_graphic_uncompressed(&overworld_weather_dynamic_fog_graphic);
        u8 group_head = NUM_OAMS;
        for (int i = 0; i < 20; i++) {
            u8 oam_idx = oam_new_backward_search(&overworld_weather_dynamic_fog_oam_template, 0, (s16)((i / 5) * 64), 0xFF);
            if (oam_idx != NUM_OAMS) {
                if (group_head == NUM_OAMS)
                    group_head = oam_idx;
                if (oam_idx != group_head)
                    oam_add_to_group(oam_idx, group_head);
                oams[oam_idx].private[0] = (u16)(i % 5);
                oams[oam_idx].private[1] = (u16)(i / 5);
                overworld_weather.sprites.s2.fogDSprites[i] = oams + oam_idx;
            } else {
                overworld_weather.sprites.s2.fogDSprites[i] = NULL;
            }
        }
    }
    overworld_weather.fog_d_oams_created = true;
}

extern const graphic overworld_weather_static_fog_graphic;
extern const oam_template overworld_weather_static_fog_oam_template;

void overworld_weather_static_fog_create_oams() {
    if (!overworld_weather.fog_h_oams_created) {
        oam_load_graphic_uncompressed(&overworld_weather_static_fog_graphic);
        u8 group_head = NUM_OAMS;
        for (int i = 0; i < 20; i++) {
            u8 oam_idx = oam_new_backward_search(&overworld_weather_static_fog_oam_template, 0, 0, 0xFF);
            if (oam_idx != NUM_OAMS) {
                if (group_head == NUM_OAMS)
                    group_head = oam_idx;
                if (oam_idx != group_head)
                    oam_add_to_group(oam_idx, group_head);
                oams[oam_idx].private[0] = (u16)(i % 5);
                oams[oam_idx].x = (s16)((i % 5) * 64 + 32);
                oams[oam_idx].y = (s16)((i / 5) * 64 + 32);
                overworld_weather.sprites.s2.fogHSprites[i] = oams + oam_idx;
            } else {
                overworld_weather.sprites.s2.fogHSprites[i] = NULL;
            }
        }
    }
    overworld_weather.fog_h_oams_created = true;
}

void weather_light_static_fog_main() {
    overworld_weather.fog_x_scroll_position = (u16)((coordinate_camera_x_offset - overworld_weather.fog_x_scroll_offset) & 0xFF);
    if (++overworld_weather.fog_x_scroll_counter > 3) {
        overworld_weather.fog_x_scroll_counter = 0;
        overworld_weather.fog_x_scroll_offset++;
    }
    switch (overworld_weather.init_step) {
        case 0: {
            overworld_weather_static_fog_create_oams();
            if (overworld_weather.current_weather == MAP_WEATHER_STATIC_FOG) {
                overworld_weather_set_target_blend_coefficients(12, 8, 3);
            } else if (overworld_weather.current_weather == MAP_WEATHER_LIGHT_STATIC_FOG) {
                overworld_weather_set_target_blend_coefficients(5, 12, 3);
            } else {
                // Is that used for bubbles ?? Probably this line could be commented out
                overworld_weather_set_target_blend_coefficients(4, 16, 3);
            }
            DEBUG("Set light static fog bld coefs to %d, %d\n");
            overworld_weather.init_step++;
            break;
        }
        case 1: {
            if (overworld_weather_update_blend()) {
                overworld_weather.weather_gfx_loaded = true;
                overworld_weather.init_step++;
            }
            break;
        }
    }
}

void weather_light_static_fog_initialize_all() {
    weather_static_fog_initialize_variables();
    while (!overworld_weather.weather_gfx_loaded) {
        weather_light_static_fog_main();
    }
}
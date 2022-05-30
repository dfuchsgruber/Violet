#include "types.h"
#include "overworld/weather.h"
#include "oam.h"

extern graphic overworld_weather_sandstorm_graphic;
extern color_t overworld_weather_sandstormPal[16];
extern oam_template overworld_weather_sandstorm_template;

void overworld_weather_sandstorm_oams_create() {
    if (!overworld_weather.sandstorm_oams_created) {
        oam_load_graphic_uncompressed(&overworld_weather_sandstorm_graphic);
        overworld_weather_load_palette(overworld_weather_sandstormPal);
        u8 group_head = NUM_OAMS;
        for (int i = 0; i < 20; i++) {
            u8 oam_idx = oam_new_backward_search(
                &overworld_weather_sandstorm_template, 0, (s16)((i / 5) * 64), 1);
            if (group_head == NUM_OAMS)
                group_head = oam_idx;
            if (oam_idx != NUM_OAMS) {
                overworld_weather.sprites.s2.sandstormSprites1[i] = oams + oam_idx;
                oams[oam_idx].private[0] = (u16)(i % 5);
                oams[oam_idx].private[1] = (u16)(i / 5);
                if (group_head != NUM_OAMS && oam_idx != group_head) {
                    oam_add_to_group(oam_idx, group_head);
                }
            } else {
                overworld_weather.sprites.s2.sandstormSprites1[i] = NULL;
            }
        }
        overworld_weather.sandstorm_oams_created = true;
    }
}

extern u16 overworld_weather_sandstorm_swirl_oam_delays[5];

void overworld_weather_sandstorm_swirl_oams_create() {
    if (!overworld_weather.sandstorm_swirl_oams_created) {
        u8 group_head = NUM_OAMS;
        for (int i = 0; i < 5; i++) {
            u8 oam_idx = oam_new_backward_search(&overworld_weather_sandstorm_template, (s16)(i * 48 + 24), 208, 1);
            if (group_head == NUM_OAMS)
                group_head = oam_idx;
            if (oam_idx != NUM_OAMS) {
                oam_object *o = oams + oam_idx;
                o->final_oam.attr1 = (u16)((o->final_oam.attr1 & (~ATTR1_SIZE_64_64)) | ATTR1_SIZE_32_32);
                o->private[1] = (u16)(i * 51);
                o->private[0] = 8;
                o->private[2] = 0;
                o->private[4] = 0x6730;
                o->private[3] = overworld_weather_sandstorm_swirl_oam_delays[i];
                oam_gfx_anim_start(o, 1);
                oam_calculate_center_coordinates(o, ATTR0_SHAPE_SQUARE >> 14, ATTR1_SIZE_32_32 >> 14, 0);
                o->callback = overworld_weather_sandstorm_oam_callback_wait_for_delay;
                if (group_head != NUM_OAMS && oam_idx != group_head) {
                    oam_add_to_group(oam_idx, group_head);
                }
                overworld_weather.sprites.s2.sandstormSprites2[i] = oams + oam_idx;
            } else {
                overworld_weather.sprites.s2.sandstormSprites2[i] = NULL;
            }
        }   
        overworld_weather.sandstorm_swirl_oams_created = true;
    }
}
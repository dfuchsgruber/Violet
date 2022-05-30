
#include "types.h"
#include "overworld/weather.h"
#include "oam.h"

extern oam_template overworld_weather_dynamic_fog_oam_template;
extern graphic overworld_weather_dynamic_fog_graphic;

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

extern graphic overworld_weather_static_fog_graphic;
extern oam_template overworld_weather_static_fog_oam_template;

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
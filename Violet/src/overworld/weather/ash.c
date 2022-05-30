#include "types.h"
#include "overworld/weather.h"
#include "oam.h"

extern oam_template overworld_weather_ash_template;

void overworld_weather_ash_create_oams() {
    if (!overworld_weather.ash_oams_created) {
        u8 group_head = NUM_OAMS;
        for (int i = 0; i < 20; i++) {
            u8 oam_idx = oam_new_backward_search(&overworld_weather_ash_template, 0, 0, 0x4E);
            if (oam_idx != NUM_OAMS) {
                if (group_head == NUM_OAMS)
                    group_head = oam_idx;
                if (oam_idx != group_head)
                    oam_add_to_group(oam_idx, group_head);
                oams[oam_idx].private[1] = 0;
                oams[oam_idx].private[2] = (u16)(i % 5);
                oams[oam_idx].private[3] = (u16)(i / 5);
                oams[oam_idx].private[0] = (u16)(oams[oam_idx].private[3] * 64 + 32);
                overworld_weather.sprites.s2.ashSprites[i] = oams + oam_idx;
            } else {
                overworld_weather.sprites.s2.ashSprites[i] = NULL;
            }
        }
    }
    overworld_weather.ash_oams_created = true;
}

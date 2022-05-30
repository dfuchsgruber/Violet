#include "types.h"
#include "overworld/weather.h"
#include "oam.h"
#include "tile/coordinate.h"

extern oam_template overworld_weather_rain_template;
extern coordinate_t overworld_weather_rain_positions[];

bool overworld_weather_create_rain_oam() {
    if (overworld_weather.rain_oam_count >= 24)
        return false;
    if (overworld_weather.rain_oam_count == 0)
        overworld_weather.rain_group_head = NUM_OAMS;
    u8 idx = overworld_weather.rain_oam_count;
    u8 oam_idx = oam_new_backward_search(&overworld_weather_rain_template,
        overworld_weather_rain_positions[idx].x, overworld_weather_rain_positions[idx].y, 78);
    if (overworld_weather.rain_group_head == NUM_OAMS)
        overworld_weather.rain_group_head = oam_idx;
    if (oam_idx < NUM_OAMS) {
        oams[oam_idx].private[5] = 0;
        oams[oam_idx].private[1] = (u16)((idx * 145));
        while (oams[oam_idx].private[1] >= 600)
            oams[oam_idx].private[1] = (u16)(oams[oam_idx].private[1] - 600);

        overworld_weather_rain_oam_start_fall(oams + oam_idx);
        overworld_weather_rain_oam_start_movement(oams + oam_idx, (u16)(9 * idx));
        oams[oam_idx].flags |= OAM_FLAG_INVISIBLE;
        overworld_weather.sprites.s1.rainSprites[idx] = oams + oam_idx;
        if (oam_idx != overworld_weather.rain_group_head)
            oam_add_to_group(oam_idx, overworld_weather.rain_group_head);
    } else {
        overworld_weather.sprites.s1.rainSprites[idx] = NULL;
    }
    overworld_weather.rain_oam_count++;
    if (overworld_weather.rain_oam_count == 24) {
        for (int i = 0; i < 24; i++) {
            oam_object *o = overworld_weather.sprites.s1.rainSprites[i];
            if (o) {
                if (o->private[6] == 0)
                    o->callback = overworld_weather_rain_oam_callback_update;
                else
                    o->callback = overworld_weather_rain_oam_callback_wait_for_delay;
            }
        }
        return false;
    }
    return true;
}
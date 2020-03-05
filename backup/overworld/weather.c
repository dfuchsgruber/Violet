#include "types.h"
#include "overworld/weather.h"
#include "constants/map_weathers.h"
#include "color.h"
#include "fading.h"
#include "bios.h"
#include "dns.h"
#include "debug.h"

color_t overworld_weather_static_fog_get_overlay_color() {
    color_t fog_overlay = {.rgb = {.red = 28, .green = 31, .blue = 28}};
    if (dns_on()) {
        fog_overlay = color_blend_and_multiply(fog_overlay, dns_get_overlay(pal_shaders), dns_get_alpha(pal_shaders));
    }
    return fog_overlay;
}

void pal_oam_apply_fading(u8 oam_pal_idx) {
    // dprintf("Pal idx %d, pr state %d, Shader state %d\n", oam_pal_idx, overworld_weather.pal_processing_state, pal_shaders);
    u8 pal_idx = (u8)(oam_pal_idx + 16);
    if (overworld_weather.pal_processing_state == OVERWORLD_WEATHER_PAL_PROCESSING_STATE_FADING_IN) {
        if (overworld_weather.field_1738) {
            if (overworld_weather.current_weather == MAP_WEATHER_STATIC_FOG) {
                overworld_weather_static_fog_add_affected_pal_idx(pal_idx);
            }
            for (int i = 0; i < 16; i++) {
                color_t target_color = overworld_weather.fadescreen_target_color;
                pals[pal_idx * 16 + i] = target_color;
            }
        }
    } else if (overworld_weather.pal_processing_state == OVERWORLD_WEATHER_PAL_PROCESSING_STATE_FADING_OUT) {
        cpufastset(&pals[pal_idx * 16], &pal_restore[pal_idx * 16], CPUFASTSET_COPY | CPUFASTSET_SIZE(sizeof(color_t) * 16));
        color_t overlay = {.value = fading_control.color};
        pal_alpha_blending((u16)(pal_idx * 16), 16, fading_control.target_alpha, overlay);
    } else {
        if (overworld_weather.current_weather != MAP_WEATHER_STATIC_FOG) {
            pal_gamma_shift(pal_idx, 1, overworld_weather.gamma);
        } else {
            pal_alpha_blending((u16)(pal_idx * 16), 16, OVERWORLD_WEATHER_STATIC_FOG_PALETTE_BLENDING_ALPHA, 
                overworld_weather_static_fog_get_overlay_color());
        }
    }
}

void overworld_weather_static_fog_pal_blend(u8 alpha, color_t overlay) {
    pal_alpha_blending(0, 256, alpha, overlay);
    color_t fog_overlay = overworld_weather_static_fog_get_overlay_color();
    for (u8 pal_idx = 16; pal_idx < 32; pal_idx++) {
        if (overworld_weather_static_fog_is_pal_affected(pal_idx)) {
            for (u16 color_idx = (u16)(pal_idx * 16); color_idx < (u16)((pal_idx + 1) * 16); color_idx++) {
                color_t blended = pal_restore[color_idx];
                blended = color_alpha_blend(blended, fog_overlay, OVERWORLD_WEATHER_STATIC_FOG_PALETTE_BLENDING_ALPHA);
                pals[color_idx] = color_alpha_blend(blended, overlay, alpha);
            }
        } else {
            pal_alpha_blending((u16)(pal_idx * 16), 16, alpha, overlay);
        }
    }
}
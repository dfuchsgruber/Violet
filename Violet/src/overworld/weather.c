#include "types.h"
#include "overworld/weather.h"
#include "constants/map_weathers.h"
#include "color.h"
#include "fading.h"
#include "bios.h"
#include "dns.h"
#include "debug.h"
#include "overworld/effect.h"
#include "save.h"
#include "overworld/script.h"
#include "callbacks.h"
#include "agbmemory.h"
#include "vars.h"
#include "fading.h"
#include "prng.h"
#include "math.h"

WEATHER_FUNCTION_WITH_BLEND(weather_inside_initialize_variables);
WEATHER_FUNCTION_WITH_BLEND(weather_inside_initialize_all);
WEATHER_FUNCTION_WITH_BLEND(weather_sunny_with_cloud_reflection_initialize_variables);
WEATHER_FUNCTION_WITH_BLEND(weather_sunny_with_cloud_reflection_initialize_all);
WEATHER_FUNCTION_WITH_BLEND(weather_outside_initialize_variables);
WEATHER_FUNCTION_WITH_BLEND(weather_outside_initialize_all);
WEATHER_FUNCTION_WITH_BLEND(weather_rain_initialize_variables);
WEATHER_FUNCTION_WITH_BLEND(weather_rain_initialize_all);
WEATHER_FUNCTION_WITH_BLEND(weather_snow_initialize_variables);
WEATHER_FUNCTION_WITH_BLEND(weather_snow_initialize_all);
WEATHER_FUNCTION_WITH_BLEND(weather_thunder_initialize_variables);
WEATHER_FUNCTION_WITH_BLEND(weather_thunder_initialize_all);
WEATHER_FUNCTION_WITH_BLEND(weather_ash_initialize_variables);
WEATHER_FUNCTION_WITH_BLEND(weather_ash_initialize_all);
WEATHER_FUNCTION_WITH_BLEND(weather_sandstorm_initialize_variables);
WEATHER_FUNCTION_WITH_BLEND(weather_sandstorm_initialize_all);
WEATHER_FUNCTION_WITH_BLEND(weather_dynamic_fog_initialize_variables);
WEATHER_FUNCTION_WITH_BLEND(weather_dynamic_fog_initialize_all);
WEATHER_FUNCTION_WITH_BLEND(weather_dense_fog_initialize_variables);
WEATHER_FUNCTION_WITH_BLEND(weather_dense_fog_initialize_all);
WEATHER_FUNCTION_WITH_BLEND(weather_cloudy_initialize_variables);
WEATHER_FUNCTION_WITH_BLEND(weather_cloudy_initialize_all);
WEATHER_FUNCTION_WITH_BLEND(weather_extreme_sun_initialize_variables);
WEATHER_FUNCTION_WITH_BLEND(weather_extreme_sun_initialize_all);
WEATHER_FUNCTION_WITH_BLEND(weather_extreme_thunder_initialize_variables);
WEATHER_FUNCTION_WITH_BLEND(weather_extreme_thunder_initialize_all);
WEATHER_FUNCTION_WITH_BLEND(weather_underwater_initialize_variables);
WEATHER_FUNCTION_WITH_BLEND(weather_underwater_initialize_all);
WEATHER_FUNCTION_WITH_BLEND(weather_weather_0f_initialize_variables);
WEATHER_FUNCTION_WITH_BLEND(weather_weather_0f_initialize_all);
WEATHER_FUNCTION_WITH_BLEND(weather_static_fog_initialize_variables);
WEATHER_FUNCTION_WITH_BLEND(weather_static_fog_initialize_all);

#define CEMETERY_BANK 3
#define CEMETERY_MAP 14

static bool is_cemetery_map() {
    return save1->bank == CEMETERY_BANK && save1->map == CEMETERY_MAP;
}

static color_t weather_burning_trees_filter = {.rgb = {.red = 31, .blue = 16, .green = 15}};
static color_t weather_fog_cemetery_filter = {.rgb = {.red = 15, .green = 15, .blue = 28}};
static color_t weather_cold_blue_filter = {.rgb = {.red = 200 / 8, .green = 232 / 8, .blue = 248 / 8}};

void weather_set_filter(u8 weather) {
    // DEBUG("Weather filter set according to weather %d\n", weather);
    switch (weather) {
        case MAP_WEATHER_BURNING_TREES:
            fmem.weather_blend_active = 1;
            fmem.weather_blend = weather_burning_trees_filter;
            break;
        case MAP_WEATHER_STATIC_FOG:
            if (is_cemetery_map()) {
                fmem.weather_blend_active = 1;
                fmem.weather_blend = weather_fog_cemetery_filter;
            } else {
                fmem.weather_blend_active = 0;
            }
            break;
        case MAP_WEATHER_COLD_BLUE:
            fmem.weather_blend_active = 1;
            fmem.weather_blend = weather_cold_blue_filter;
            break;
        default:
            fmem.weather_blend_active = 0;
            break;
    }
}

void weather_burning_trees_update_pal_restore_and_tmp() {
    weather_set_filter(MAP_WEATHER_BURNING_TREES);
    for (u8 pal_idx = 0; pal_idx < 32; pal_idx++) {
        u8 gamma_type = palette_get_gamma_type(pal_idx);
        if (gamma_type != GAMMA_NONE) {
            pal_color_multiply((u16)(16 * pal_idx), 16, fmem.weather_blend);
            // DEBUG("blending pal %d\n", pal_idx);
        }
    }
    cpuset(pal_restore, pal_tmp, CPUSET_COPY | CPUSET_HALFWORD | CPUSET_HALFWORD_SIZE(32 * 16 * sizeof(color_t)));
}


weather_callbacks_t weather_callbacks[] = {
    [MAP_WEATHER_INSIDE] = {.initialize_variables = weather_inside_initialize_variables_with_blend, .main = weather_inside_main, .initialize_all = weather_inside_initialize_all_with_blend, .closure = weather_inside_closure },
    [MAP_WEATHER_SUNNY_WITH_CLOUD_REFLECTION] = {.initialize_variables = weather_sunny_with_cloud_reflection_initialize_variables_with_blend, .main = weather_sunny_with_cloud_reflection_main, .initialize_all = weather_sunny_with_cloud_reflection_initialize_all_with_blend, .closure = weather_sunny_with_cloud_reflection_closure },
    [MAP_WEATHER_OUTSIDE] = {.initialize_variables = weather_outside_initialize_variables_with_blend, .main = weather_outside_main, .initialize_all = weather_outside_initialize_all_with_blend, .closure = weather_outside_closure },
    [MAP_WEATHER_RAIN] = {.initialize_variables = weather_rain_initialize_variables_with_blend, .main = weather_rain_main, .initialize_all = weather_rain_initialize_all_with_blend, .closure = weather_rain_closure },
    [MAP_WEATHER_SNOW] = {.initialize_variables = weather_snow_initialize_variables_with_blend, .main = weather_snow_main, .initialize_all = weather_snow_initialize_all_with_blend, .closure = weather_snow_closure },
    [MAP_WEATHER_THUNDER] = {.initialize_variables = weather_thunder_initialize_variables_with_blend, .main = weather_thunder_main, .initialize_all = weather_thunder_initialize_all_with_blend, .closure = weather_thunder_closure },
    [MAP_WEATHER_STATIC_FOG] = {.initialize_variables = weather_static_fog_initialize_variables_with_blend, .main = weather_static_fog_main, .initialize_all = weather_static_fog_initialize_all_with_blend, .closure = weather_static_fog_closure },
    [MAP_WEATHER_ASH] = {.initialize_variables = weather_ash_initialize_variables_with_blend, .main = weather_ash_main, .initialize_all = weather_ash_initialize_all_with_blend, .closure = weather_ash_closure },
    [MAP_WEATHER_SANDSTORM] = {.initialize_variables = weather_sandstorm_initialize_variables_with_blend, .main = weather_sandstorm_main, .initialize_all = weather_sandstorm_initialize_all_with_blend, .closure = weather_sandstorm_closure },
    [MAP_WEATHER_DYNAMIC_FOG] = {.initialize_variables = weather_dynamic_fog_initialize_variables_with_blend, .main = weather_dynamic_fog_main, .initialize_all = weather_dynamic_fog_initialize_all_with_blend, .closure = weather_dynamic_fog_closure },
    [MAP_WEATHER_DENSE_FOG] = {.initialize_variables = weather_dense_fog_initialize_variables_with_blend, .main = weather_dense_fog_main, .initialize_all = weather_dense_fog_initialize_all_with_blend, .closure = weather_dense_fog_closure },
    [MAP_WEATHER_CLOUDY] = {.initialize_variables = weather_cloudy_initialize_variables_with_blend, .main = weather_cloudy_main, .initialize_all = weather_cloudy_initialize_all_with_blend, .closure = weather_cloudy_closure },
    [MAP_WEATHER_EXTREME_SUN] = {.initialize_variables = weather_extreme_sun_initialize_variables_with_blend, .main = weather_extreme_sun_main, .initialize_all = weather_extreme_sun_initialize_all_with_blend, .closure = weather_extreme_sun_closure },
    [MAP_WEATHER_EXTREME_THUNDER] = {.initialize_variables = weather_extreme_thunder_initialize_variables_with_blend, .main = weather_extreme_thunder_main, .initialize_all = weather_extreme_thunder_initialize_all_with_blend, .closure = weather_extreme_thunder_closure },
    [MAP_WEATHER_UNDERWATER] = {.initialize_variables = weather_underwater_initialize_variables_with_blend, .main = weather_underwater_main, .initialize_all = weather_underwater_initialize_all_with_blend, .closure = weather_underwater_closure },
    [MAP_WEATHER_WEATHER_0F] = {.initialize_variables = weather_weather_0f_initialize_variables_with_blend, .main = weather_weather_0f_main, .initialize_all = weather_weather_0f_initialize_all_with_blend, .closure = weather_weather_0f_closure },
    [MAP_WEATHER_BURNING_TREES] = {.initialize_variables = weather_extreme_sun_initialize_variables_with_blend, .main = weather_extreme_sun_main, .initialize_all = weather_extreme_sun_initialize_all_with_blend, .closure = weather_extreme_sun_closure },
    [MAP_WEATHER_COLD_BLUE] = {.initialize_variables = weather_inside_initialize_variables_with_blend, .main = weather_inside_main, .initialize_all = weather_inside_initialize_all_with_blend, .closure = weather_inside_closure},
};

void pal_gamma_shift(u8 start_pal_idx, u8 num_pals, s8 gamma_idx) {
    u8 current_pal_idx;
    u16 pal_offset;
    u8 *gamma_table;
    u16 i;

    if (gamma_idx > 0) {
        gamma_idx--;
        pal_offset = (u16)(start_pal_idx * 16);
        num_pals = (u8)(num_pals + start_pal_idx);
        current_pal_idx = start_pal_idx;
        // Loop through the speficied palette range and apply necessary gamma shifts to the colors.
        while (current_pal_idx < num_pals) {
            if (palette_get_gamma_type(current_pal_idx) == GAMMA_NONE) {
                // No palette change.
                cpufastset(pal_restore + pal_offset, pals + pal_offset, CPUFASTSET_COPY | CPUFASTSET_SIZE(16 * sizeof(u16)));
                pal_offset = (u16)(pal_offset + 16);
            }
            else {
                if (palette_get_gamma_type(current_pal_idx) == GAMMA_ALTERNATIVE || current_pal_idx - 16 == overworld_weather.alternative_gamma_oam_pal_idx)
                    gamma_table = overworld_weather.alternative_gamma_shifts[gamma_idx];
                else
                    gamma_table = overworld_weather.gamma_shifts[gamma_idx];

                for (i = 0; i < 16; i++) {
                    // Apply gamma shift to the original color.
                    color_t col = pal_restore[pal_offset];
                    color_t shifted = {.rgb = {.red = (u8)(gamma_table[col.rgb.red] & 31), .green = (u8)(gamma_table[col.rgb.green] & 31),
                     .blue = (u8)(gamma_table[col.rgb.blue] & 31)}};
                    pals[pal_offset++] = shifted;
                }
            }
            current_pal_idx++;
        }
    }
    else if (gamma_idx < 0)
    {

        gamma_idx = (s8)(-gamma_idx - 1);
        pal_offset = (u16)(start_pal_idx * 16);
        num_pals = (u8)(num_pals + start_pal_idx);
        current_pal_idx = start_pal_idx;
        
        while (current_pal_idx < num_pals) {
            if (palette_get_gamma_type(current_pal_idx) == GAMMA_NONE) {
                // No palette change.
                cpufastset(pal_restore + pal_offset, pals + pal_offset, CPUFASTSET_COPY | CPUFASTSET_SIZE(16 * sizeof(u16)));
                pal_offset = (u16)(pal_offset + 16);
            }
            else {
                for (i = 0; i < 16; i++)
                {
                    pals[pal_offset] = drought_colors[gamma_idx][DROUGHT_COLOR_INDEX(pal_restore[pal_offset].value)];
                    pal_offset++;
                }
            }
            current_pal_idx++;
        }
    }
    else
    {
        // No palette blending.
        cpufastset(pal_restore + start_pal_idx * 16, pals + start_pal_idx * 16, CPUFASTSET_COPY | CPUFASTSET_SIZE((u32)(num_pals) * 16 * sizeof(u16)));
    }
}

bool overworld_weather_drought_load_palettes() {
    if (overworld_weather.load_drought_pals_index < 32) {
        overworld_weather.load_drought_pals_index = 32;
        overworld_weather.load_drought_pals_offset = 32;
    }
    return false;
}




bool overworld_weather_static_fog_palette_affected(u8 pal_idx) {
    // The vanilla system is kinda dumb... It enqueues pals that are affected but never dequeues them
    // This is not suitable for a completely dynamic system. However we can assume that only ground effects
    // will be affected 
    if (pal_idx < 16)
        return false;
    u16 tag = oam_palette_get_tag((u8)(pal_idx - 16));
    if (tag == 0xFFFF)
        return false;
    return tag_is_ground_effect(tag);
}

void pal_fog_alpha_blending(u16 first, u16 num_cols) {
    color_t fog_col = dns_get_fog_overlay();
    // DEBUG("Fog overlay is 0x%x\n", fog_col);
    for (int i = 0; i < num_cols; i++) {
        color_t new = {.rgb = {
            .red = (u16)(MIN(31, (8 * pal_restore[first + i].rgb.red + 12 * fog_col.rgb.red) / 16) & 31),
            .green = (u16)(MIN(31, (8 * pal_restore[first + i].rgb.green + 12 * fog_col.rgb.green) / 16) & 31),
            .blue = (u16)(MIN(31, (8 * pal_restore[first + i].rgb.blue + 12 * fog_col.rgb.blue) / 16) & 31),
        }};
        pals[first + i] = new;
    }
}

void pal_oam_apply_fading(u8 oam_pal_idx) {
    // DEBUG("Pal idx %d, pr state %d, Shader state %d\n", oam_pal_idx, overworld_weather.pal_processing_state, pal_shaders);
    u8 pal_idx = (u8)(oam_pal_idx + 16);
    if (overworld_weather.pal_processing_state == OVERWORLD_WEATHER_PAL_PROCESSING_STATE_FADING_IN) {
        if (overworld_weather.is_fade_in_active) {
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
            if (palette_get_gamma_type(pal_idx) == GAMMA_NORMAL)
                pal_gamma_shift(pal_idx, 1, overworld_weather.gamma);
        } else {
            // DEBUG("Before alpha blending 0x%x\n", pals[pal_idx * 16 + 4] );
            // color_t fog_overlay = dns_get_fog_overlay();
            pal_fog_alpha_blending((u16)(pal_idx * 16), 16);
            // DEBUG("After alpha blending 0x%x\n", pals[pal_idx * 16 + 4]);
        }
    }
}

void overworld_weather_static_fog_pal_blend(u8 alpha, color_t overlay) {
    pal_alpha_blending(0, 256, alpha, overlay);
    // color_t fog_overlay = dns_get_fog_overlay();
    for (u8 pal_idx = 16; pal_idx < 32; pal_idx++) {
        if (overworld_weather_static_fog_is_pal_affected(pal_idx)) {
            pal_fog_alpha_blending((u16)(pal_idx * 16), 16);
            for (u16 color_idx = (u16)(pal_idx * 16); color_idx < (u16)((pal_idx + 1) * 16); color_idx++) {
                pals[color_idx] = color_alpha_blend(pals[color_idx], overlay, alpha); // The fog effect blends into pals
            }
        } else {
            pal_alpha_blending((u16)(pal_idx * 16), 16, alpha, overlay);
        }
    }
}

static bool overworld_weather_update_gamma_shift() {
    if (overworld_weather.gamma == overworld_weather.gamma_to)
        return false;
    if (++overworld_weather.gamma_step_frame >= overworld_weather.gamma_step_delay) {
        overworld_weather.gamma_step_frame = 0;
        if (overworld_weather.gamma < overworld_weather.gamma_to)
            overworld_weather.gamma++;
        else
            overworld_weather.gamma--;
    }
    return true;
}


static bool overworld_weather_update_blend() {
    return false; // No continuous blending so far
};

void overworld_weather_update_gamma_shift_and_filter() {
    // DEBUG("updating blend and gamma\n");
    if (!overworld_weather_update_gamma_shift() && !overworld_weather_update_blend()) {
        overworld_weather.pal_processing_state = OVERWORLD_WEATHER_PAL_PROCESSING_STATE_IDLE;
    } else {
        pal_gamma_shift(0, 32, overworld_weather.gamma);
    }
}

void overworld_weather_fade_in_with_filter() {
    // Not implemented currently
    overworld_weather_fade_in();
}

static s8 weather_gammas[] = {
    [MAP_WEATHER_RAIN] = 3,
    [MAP_WEATHER_THUNDER] = 3,
    [MAP_WEATHER_EXTREME_THUNDER] = 3,
    [MAP_WEATHER_CLOUDY] = 3,
    [MAP_WEATHER_EXTREME_SUN] = -6,
    [MAP_WEATHER_BURNING_TREES] = -6,
};

void overworld_weather_fade_in() {
    if (++overworld_weather.fade_in_counter > 1)
        overworld_weather.is_fade_in_active = false;
    
    s8 target_gamma = weather_gammas[overworld_weather.current_weather];
    switch (overworld_weather.current_weather) {
        case MAP_WEATHER_RAIN:
        case MAP_WEATHER_THUNDER:
        case MAP_WEATHER_EXTREME_THUNDER:
        case MAP_WEATHER_CLOUDY: {
            if (!overworld_weather_fade_in_with_gamma(target_gamma)) {
                // Fade-in with gamma filter
                overworld_weather.gamma = target_gamma;
                overworld_weather.pal_processing_state = OVERWORLD_WEATHER_PAL_PROCESSING_STATE_IDLE;
            }
            break;
        }
        case MAP_WEATHER_EXTREME_SUN:
        case MAP_WEATHER_BURNING_TREES: {
            if (!overworld_weather_fade_in_with_gamma_and_drought(target_gamma)) {
                overworld_weather.gamma = target_gamma;
                overworld_weather.pal_processing_state = OVERWORLD_WEATHER_PAL_PROCESSING_STATE_IDLE;
            }
            break;
        }
        case MAP_WEATHER_STATIC_FOG: {
            if (!overworld_weather_fade_in_static_fog()) {
                overworld_weather.gamma = target_gamma;
                overworld_weather.pal_processing_state = OVERWORLD_WEATHER_PAL_PROCESSING_STATE_IDLE;
            }
            break;
        }
        default: {
            if (!fading_control.active) {
                overworld_weather.gamma = overworld_weather.gamma_to;
                overworld_weather.pal_processing_state = OVERWORLD_WEATHER_PAL_PROCESSING_STATE_IDLE;
            }
            break;
        }
    }
}

static bool overworld_weather_fade_in_is_delayed_and_delay_proceed() {
    int delay = *var_access(VAR_MAP_TRANSITION_FADING_DELAY);
    if (fmem.weather_blend_delay >= delay) {
        fmem.weather_blend_delay = 0;
        return false;
    } else {
        fmem.weather_blend_delay++;
        return true;
    }
}

bool overworld_weather_fade_in_with_gamma(s8 gamma) {
    if (overworld_weather.fadescreen_cnt == 16)
        return false;
    if (overworld_weather_fade_in_is_delayed_and_delay_proceed())
        return true;
    if (++overworld_weather.fadescreen_cnt >= 16) {
        pal_gamma_shift(0, 32, gamma);
        overworld_weather.fadescreen_cnt = 16;
        return false;
    } else {
        pal_gamma_shift_with_blend(0, 32, gamma, (u8)(16 - overworld_weather.fadescreen_cnt), overworld_weather.fadescreen_target_color);
        return true;
    }
}

bool overworld_weather_fade_in_with_gamma_and_drought(s8 gamma) {
    DEBUG("Fade-in with drought, fadescreen cnt %d.\n", overworld_weather.fadescreen_cnt);
    if (overworld_weather.fadescreen_cnt == 16)
        return false;
    if (overworld_weather_fade_in_is_delayed_and_delay_proceed())
        return true;
    if (++overworld_weather.fadescreen_cnt >= 16) {
        pal_gamma_shift(0, 32, gamma);
        overworld_weather.fadescreen_cnt = 16;
        return false;
    } else {
        pal_gamma_shift_and_blend_and_drought(gamma, (u8)(16 - overworld_weather.fadescreen_cnt), overworld_weather.fadescreen_target_color);
        return true;
    }
}

void pal_gamma_shift_and_blend_and_drought(s8 gamma, u8 alpha, color_t target) {
    gamma = (s8)(-gamma - 1);
    u8 rblend = target.rgb.red;
    u8 gblend = target.rgb.green;
    u8 bblend = target.rgb.blue;
    u16 color_idx = 0;
    for (u8 pal_idx = 0; pal_idx < 32; pal_idx++) {
        if ((palette_get_gamma_type(pal_idx) == GAMMA_NONE)) {
            pal_alpha_blending(color_idx, 16, alpha, target);
            color_idx = (u16)(color_idx + 16);
        } else {
            for (int i = 0; i < 16; i++) {
                color_t c = drought_colors[gamma][DROUGHT_COLOR_INDEX(pal_restore[color_idx].value)];
                u8 r2 = c.rgb.red;
                u8 g2 = c.rgb.green;
                u8 b2 = c.rgb.blue;
                color_t new = {
                    .rgb = {
                        .red = (u8)((
                            r2 + (((rblend - r2) * alpha) >> 4)
                        ) & 0x1F),
                        .blue = (u8)((
                            b2 + (((bblend - b2) * alpha) >> 4)
                        ) & 0x1F),
                        .green = (u8)((
                            g2 + (((gblend - g2) * alpha) >> 4)
                        ) & 0x1F),
                    }
                };
                pals[color_idx++] = new;
            }
        }
    }
}

bool overworld_weather_fade_in_static_fog() {
    if (overworld_weather.fadescreen_cnt == 16)
        return false;
    if (overworld_weather_fade_in_is_delayed_and_delay_proceed())
        return true;
    overworld_weather.fadescreen_cnt++;
    pal_fog_blend_apply((u8)(16 - overworld_weather.fadescreen_cnt), overworld_weather.fadescreen_target_color);
    return true;
}

static bool weather_affects_palette[] = {
    [MAP_WEATHER_RAIN] = true,
    [MAP_WEATHER_THUNDER] = true,
    [MAP_WEATHER_EXTREME_THUNDER] = true,
    [MAP_WEATHER_STATIC_FOG] = true,
    [MAP_WEATHER_CLOUDY] = true,
    [MAP_WEATHER_EXTREME_SUN] = true,
    [MAP_WEATHER_BURNING_TREES] = true,
};

void fadescreen_all(u8 mode, u8 delay) {
    bool fade_out;
    bool use_weather_pal = weather_affects_palette[overworld_weather.current_weather];
    u16 color;

    switch (mode) {
        case FADE_FROM_BLACK:
            fade_out = false;
            color = 0;
            break;
        case FADE_FROM_WHITE:
            fade_out = false;
            color = 0xFFFF;
            break;
        case FADE_TO_BLACK:
            fade_out = true;
            color = 0;
            break;
        case FADE_TO_WHITE:
            fade_out = true;
            color = 0xFFFF;
            break;
        default:
            return;
    }
    if (fade_out) {
        if (use_weather_pal)
            cpufastset(pals, pal_restore, CPUFASTSET_COPY | CPUFASTSET_SIZE(sizeof(pals)));
        fadescreen(0xFFFFFFFF, delay, 0, 16, color);
        overworld_weather.pal_processing_state = OVERWORLD_WEATHER_PAL_PROCESSING_STATE_FADING_OUT;
    } else {
        // Fade-in
        overworld_weather.fadescreen_target_color.value = color;
        if (use_weather_pal)
            overworld_weather.fadescreen_cnt = 0;
        else
            fadescreen(0xFFFFFFFF, delay, 16, 0, color);
        overworld_weather.pal_processing_state = OVERWORLD_WEATHER_PAL_PROCESSING_STATE_FADING_IN;
        overworld_weather.is_fade_in_active = true;
        overworld_weather.fade_in_counter = 0;
        overworld_weather_set_blend_coefficients((u8)overworld_weather.blend_eva_from, (u8)overworld_weather.blend_evb_from);
        overworld_weather.ready_to_initialize = true;
    }
}


void overworld_weather_load_palette(const color_t *pal) {
    pal_copy(pal, (u16)(256 + overworld_weather.alternative_gamma_oam_pal_idx * 16), 16 * sizeof(color_t));
    pal_apply_shaders_by_oam_palette_idx(overworld_weather.alternative_gamma_oam_pal_idx);
}

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

extern oam_template overworld_weather_snowflake_template;

bool overworld_weather_create_snowflake_oam() {
    DEBUG("Create snowflake, currently %d visible.\n", overworld_weather.snowflake_sprite_count);
    u8 oam_idx = oam_new_backward_search(&overworld_weather_snowflake_template, 0, 0, 78);
    if (oam_idx == NUM_OAMS)
        return false;
    
    oams[oam_idx].private[4] = overworld_weather.snowflake_sprite_count;
    overworld_weather_snowflake_initialize(oams + oam_idx);
    oams[oam_idx].flags |= OAM_FLAG_CENTERED;
    if (overworld_weather.snowflake_sprite_count > 0) {
        oam_add_to_group(oam_idx, overworld_weather.snow_group_head);
    } else {
        overworld_weather.snow_group_head = oam_idx;
    }
    overworld_weather.sprites.s1.snowflakeSprites[overworld_weather.snowflake_sprite_count++] = oams + oam_idx;
    return true;
}

extern graphic overworld_weather_static_fog_graphic;
extern oam_template overworld_weather_static_fog_oam_template;

void overworld_weather_static_fog_create_oams() {
    if (!overworld_weather.fog_h_oam_created) {
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
    overworld_weather.fog_h_oam_created = true;
}

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

extern oam_template overworld_weather_dynamic_fog_oam_template;
extern graphic overworld_weather_dynamic_fog_graphic;

void overworld_weather_dynamic_fog_create_oams() {
    if (!overworld_weather.fog_d_sprites_created) {
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
    overworld_weather.fog_d_sprites_created = true;
}

// Snow

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
    if ((x >= 240 + 4) || (y >= 164 && y < 252)) {
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
    DEBUG("Created new snowflake oam with idx %d as the %d-th.\n", oam_idx, idx);
    overworld_weather.snowflake_sprite_count++;
}

static void weather_snow_delete_oam() {
    if (overworld_weather.snowflake_sprite_count > 0) {
        oam_object **o = overworld_weather.sprites.s1.snowflakeSprites + (--overworld_weather.snowflake_sprite_count);
        if (*o)
            oam_delete(*o);
        DEBUG("Deleted new snowflake oam at 0x%x with snowflake idx %d\n", *o, overworld_weather.snowflake_sprite_count);
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

#undef t_x
#undef t_y
#undef t_dy
#undef t_frame
#undef t_duration
#undef t_theta_frame_offset
#undef t_x_amplitude
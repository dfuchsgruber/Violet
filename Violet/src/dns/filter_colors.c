#include "types.h"
#include "bios.h"
#include "rtc.h"
#include "color.h"
#include "dns.h"
#include "constants/vars.h"
#include "constants/shader_states.h"
#include "vars.h"
#include "save.h"
#include "fading.h"
#include "dma.h"
#include "debug.h"
#include "overworld/weather.h"
#include "flags.h"

static const color_t dns_colors[] = {
    [SHADER_NIGHT] = {.rgb = {.red = 15, .green = 15, .blue = 28}},
    [SHADER_MORNING] = {.rgb = {.red = 28, .green = 31, .blue = 26}},
    [SHADER_EVENING] = {.rgb = {.red = 28, .green = 22, .blue = 22}},
    [SHADER_CEOMETRIA_GYM_PUNISHMENT_ROOM] = {.rgb = {.red = 6, .green = 8, .blue = 19}},
};

// This is very inconsistent: How to calculate the fog colors: Look for two colors you want to match and solve the system 
// 0.5 * unfogged + 0.75 * fog_overlay = blended
// Or alternatively: fog_overlay = (blended - 0.5 * unfogged) / 0.75
// The unfogged color should be after application of the filter and the fogged color what the output is
// There will always be some kind of inconsistencies here
// Hint: Always try to match the ground arround high grass, that looks most realistic imo...

static const color_t dns_colors_fog[] = {
    [SHADER_NIGHT] = {.rgb = {.red = 5, .green = 7, .blue = 17}}, //{.rgb = {.red = 13, .green = 13, .blue = 25}},
    [SHADER_MORNING] = {.rgb = {.red = 22, .green = 23, .blue = 21}},
    [SHADER_EVENING] = {.rgb = {.red = 25, .green = 18, .blue = 18}},
    [SHADER_CEOMETRIA_GYM_PUNISHMENT_ROOM] = {.rgb = {.red = 5, .green = 7, .blue = 17}},
};

color_t dns_get_fog_overlay() {
    switch (pal_shaders) {
        case SHADER_NIGHT:
        case SHADER_MORNING:
        case SHADER_EVENING:
            if (dns_on()) {
                return dns_colors_fog[pal_shaders];
            }
    }
    color_t fog_overlay = {.rgb = {.red = 27, .green = 30, .blue = 27}};
    return fog_overlay;
}

void pal_apply_shaders(u16 start_color, u16 number_colors) {
    // Default shaders
    bool filter_active = false;
    color_t filter = {.rgb = {31, 31, 31}};

    if (checkflag(FLAG_FILTER_COLOR_ACTIVE)) {
        color_t c = {.value = *var_access(VAR_FILTER_COLOR)};
        filter_active = true;
        filter = color_multiply(filter, c);

    }
            
    switch (pal_shaders) {
        case SHADER_GREYSCALE:
            pal_apply_greyscale(&pal_restore[start_color], number_colors);
            break;
        case SHADER_SEPIA:
            pal_apply_sepia(&pal_restore[start_color], number_colors);
            break;
        case SHADER_GREYSCALE_AND_BACKUP:
            pal_apply_greyscale(&pal_restore[start_color], number_colors);
            pal_update_backup(start_color, number_colors);
            break;
        case SHADER_NIGHT:
        case SHADER_MORNING:
        case SHADER_EVENING:
            if (dns_on()) {
                filter_active = true;
                filter = color_multiply(filter, dns_colors[pal_shaders]);
                DEBUG("DNS filter color %x\n", filter);
            }
            break;
        case SHADER_CEOMETRIA_GYM_PUNISHMENT_ROOM:
            filter_active = true;
            filter = color_multiply(filter, dns_colors[pal_shaders]);
            break;
        default:
            break;
    }
    // DEBUG("Set filter to map weather %d\n", save1->map_weather);
    weather_set_filter(save1->map_weather);
    if (weather_blend_active) {
        filter_active = true;
        filter = color_multiply(filter, weather_blend);
    }
    // DEBUG("Pal apply filters to color %d (num %d), filter 0x%x, filter active %d\n", start_color, number_colors, filter, filter_active);
    if (filter_active) {
        pal_color_multiply(start_color, number_colors, filter);
        cpuset(&pal_restore[start_color], &pals[start_color], CPUSET_HALFWORD | CPUSET_COPY | CPUSET_HALFWORD_SIZE(number_colors * sizeof(color_t)));
        // cpuset(&pal_restore[start_color], &pal_backup[start_color], CPUSET_HALFWORD | CPUSET_COPY | CPUSET_HALFWORD_SIZE(number_colors * sizeof(color_t)));
    }
}

void pal_color_multiply(u16 start_color, u16 number_colors, color_t filter) {
    for (int i = 0; i < number_colors; i++) {
        pal_restore[start_color + i] = color_multiply(pal_restore[start_color + i], filter);
    }
}

void pal_apply_shaders_by_palette_idx(u8 pal_idx, u8 number_palettes) {
    pal_apply_shaders((u16)(pal_idx * 16), (u16)(number_palettes * 16));
}

void pal_apply_shaders_by_oam_palette_idx(u8 oam_pal_idx) {
    pal_apply_shaders((u16)(oam_pal_idx * 16 + 256), 16);
} 

void pal_proceed() {
    void *src = pals;
    if (!fading_control.buffer_transfer_disabled) {
        DMA_COPY_16(3, src, PALS, 32 * 16 * sizeof(color_t));
        palette_proceed_dma_transfer_requested = 0;
        if (fading_control.active && fading_control.mode == 2) {
            fading_update_blending();
        }
    }
}

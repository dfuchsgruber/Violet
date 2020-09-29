#include "types.h"
#include "bios.h"
#include "rtc.h"
#include "color.h"
#include "dns.h"
#include "constants/vars.h"
#include "constants/shader_states.h"
#include "vars.h"
#include "save.h"
#include "constants/map_weathers.h"
#include "debug.h"
#include "battle/state.h"
#include "overworld/map_control.h"
#include "dma.h"
#include "fading.h"

bool is_battle() { 
    return super.callback1 == battle_callback1; 
}

bool is_overworld() {
    return super.callback1 == overworld_callback1 || super.callback1 == overworld_callback1_proceed_only; 
}

void pal_proceed() {
    void *src = pals;
    if (is_overworld() || is_battle()) {
        src = fmem.pals_filtered;
    }
    if (!fading_control.buffer_transfer_disabled) {
        DMA_COPY_16(3, src, PALS, 32 * 16 * sizeof(color_t));
        palette_proceed_dma_transfer_requested = 0;
        if (fading_control.active && fading_control.mode == 2) {
            fading_update_blending();
        }
    }
}

static void pal_filter_alpha_blend(u32 affected_palettes, color_t over, u8 alpha) {
    for (int pal_idx = 0; pal_idx < 32; pal_idx++) {
            if (affected_palettes & int_bitmasks[pal_idx]) {
                for (int i = 0; i < 16; i++) {
                fmem.pals_filtered[pal_idx][i] = color_alpha_blend(pals[16 * pal_idx + i], over, alpha);
            }
        } else {
            cpuset(pals + 16 * pal_idx, fmem.pals_filtered[pal_idx], CPUSET_COPY | CPUSET_HALFWORD | CPUSET_HALFWORD_SIZE(16 * sizeof(color_t)));
        }
    }
}

static void pal_filter_color_multiply(u32 affected_palettes, color_t over) {
    for (int pal_idx = 0; pal_idx < 32; pal_idx++) {
            if (affected_palettes & int_bitmasks[pal_idx]) {
                for (int i = 0; i < 16; i++) {
                fmem.pals_filtered[pal_idx][i] = color_multiply(pals[16 * pal_idx + i], over);
            }
        } else {
            cpuset(pals + 16 * pal_idx, fmem.pals_filtered[pal_idx], CPUSET_COPY | CPUSET_HALFWORD | CPUSET_HALFWORD_SIZE(16 * sizeof(color_t)));
        }
    }
}

static void pal_filter_color_subtract(u32 affected_palettes, color_t over) {
    for (int pal_idx = 0; pal_idx < 32; pal_idx++) {
            if (affected_palettes & int_bitmasks[pal_idx]) {
                for (int i = 0; i < 16; i++) {
                color_t original = pals[16 * pal_idx + i];
                color_t subtracted = {
                    .rgb = {
                        .red = (u8)(MAX(original.rgb.red - over.rgb.red, 0) & 31),
                        .green = (u8)(MAX(original.rgb.green - over.rgb.green, 0) & 31),
                        .blue = (u8)(MAX(original.rgb.blue - over.rgb.blue, 0) & 31),
                    }
                };
                fmem.pals_filtered[pal_idx][i] = subtracted;
            } 
        } else {
            cpuset(pals + 16 * pal_idx, fmem.pals_filtered[pal_idx], CPUSET_COPY | CPUSET_HALFWORD | CPUSET_HALFWORD_SIZE(16 * sizeof(color_t)));
        }
    }
}

static u32 overworld_affected_pals = (u32)~((1 << 13) | (1 << 14) | (1 << 15));
static u32 battle_affected_pals = 0; // No filters in battle

void pal_filters_apply() {

    u32 affected_pals = super.in_battle ? battle_affected_pals : overworld_affected_pals;
    bool filter_used = false;
    switch (fmem.dns_filter_mode) {
        case PAL_FILTER_ALPHA_BLENDING:
            pal_filter_alpha_blend(affected_pals, fmem.dns_filter, fmem.dns_alpha);
            filter_used = true;
            break;
        case PAL_FILTER_COLOR_MULTIPLIY:
            dprintf("Color multiplictation due to dns, affects 0x%x, filter color is 0x%x\n", affected_pals, fmem.dns_filter);
            pal_filter_color_multiply(affected_pals, fmem.dns_filter);
            filter_used = true;
            break;
        case PAL_FILTER_SUBTRACTION:
            pal_filter_color_subtract(affected_pals, fmem.dns_filter);
            filter_used = true;
            break;
    }
    switch (fmem.weather_filter_mode) {
        case PAL_FILTER_ALPHA_BLENDING:
            pal_filter_alpha_blend(affected_pals, fmem.weather_filter, fmem.weather_alpha);
            filter_used = true;
            break;
        case PAL_FILTER_COLOR_MULTIPLIY:
            pal_filter_color_multiply(affected_pals, fmem.weather_filter);
            filter_used = true;
            break;
        case PAL_FILTER_SUBTRACTION:
            pal_filter_color_subtract(affected_pals, fmem.weather_filter);
            filter_used = true;
            break;
    }
    if (!filter_used) // We still need to sync the filtered buffer
        cpuset(pals, fmem.pals_filtered, CPUSET_HALFWORD | CPUSET_COPY | CPUSET_HALFWORD_SIZE(32 * 16 * sizeof(color_t)));

}

/*
color_t dns_get_overlay(u8 shader_state) {
    switch (shader_state) {
        case SHADER_NIGHT: {
            color_t overlay = {.rgb = {.red = 0x7D / 8, .green = 0x7D / 8, .blue = 0xE2 / 8}};
            return overlay;
        }
        case SHADER_MORNING: {
            color_t overlay = {.rgb = {.red = 0xE2 / 8, .green = 0xFA / 8, .blue = 0xD0 / 8}};
            return overlay;
        }
        case SHADER_EVENING: {
            color_t overlay = {.rgb = {.red = 0xE0 / 8, .green = 0xB5 / 8, .blue = 0xB5 / 8}};
            return overlay;
        }
        case SHADER_CEOMETRIA_GYM_PUNISHMENT_ROOM: {
            color_t overlay = {.rgb = {.red = 6, .green = 8, .blue = 19}};
            return overlay;
        }
        default: {
            color_t overlay = {.value = 0};
            return overlay;
        }
    }
}


u8 dns_get_alpha(u8 shader_state) {
    switch (shader_state) {
        case SHADER_NIGHT:
            return 16;
        case SHADER_MORNING:
            return 16;
        case SHADER_EVENING:
            return 16;
        case SHADER_CEOMETRIA_GYM_PUNISHMENT_ROOM:
            return 16;
        default:
            return 0;
    }
}
*/

/*
static void pal_apply_weather_shaders(u16 start_color, u16 number_colors) {
    
    dprintf("Weather based shader for weather %d\n", save1->map_weather);
    // Weather based shaders
    switch (save1->map_weather) {
        case MAP_WEATHER_BURNING_TREES: {
            color_t overlay = {.rgb = {.red = 31, .blue = 12, .green = 11}};
            dns_blend_colors(start_color, number_colors, overlay, 16);
            for (u16 i = start_color; i < start_color + number_colors; i++)  
                pal_restore[i] = color_multiply(pal_restore[i], overlay);
            break;
        }
        default:
            return;
    }
    cpuset(&pal_restore[start_color], &pals[start_color], CPUSET_HALFWORD | CPUSET_COPY | CPUSET_HALFWORD_SIZE(number_colors * sizeof(color_t)));
    // pal_apply_greyscale(&pal_restore[start_color], number_colors);
}
*/

void pal_apply_shaders(u16 start_color, u16 number_colors) {
    // pal_apply_weather_shaders(start_color, number_colors);
    // Default shaders
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
        /*
        case SHADER_NIGHT:
        case SHADER_MORNING:
        case SHADER_EVENING:
            if (dns_on()) {
                dns_blend_colors(start_color, number_colors, 
                dns_get_overlay(pal_shaders), dns_get_alpha(pal_shaders));
            }
            break;
        case SHADER_CEOMETRIA_GYM_PUNISHMENT_ROOM:
            dns_blend_colors(start_color, number_colors, 
                dns_get_overlay(pal_shaders), dns_get_alpha(pal_shaders));
            break;
        */
        default:
            return;
    }
    cpuset(&pal_restore[start_color], &pals[start_color], CPUSET_HALFWORD | CPUSET_COPY | CPUSET_HALFWORD_SIZE(number_colors * sizeof(color_t)));
}

/*
void dns_blend_colors(u16 start_col, u16 col_cnt, color_t overlay, u8 alpha) {
    (void) alpha;
    if (dns_on()) {
        u16 end_col = (u16) (start_col + col_cnt);
        for (;start_col < end_col; start_col++) {
            pal_restore[start_col] = color_multiply(pal_restore[start_col], overlay);
            //pal_restore[start_col] = color_blend_and_multiply(pal_restore[start_col], overlay, alpha);;
        }
    }
}
*/


void pal_apply_shaders_by_palette_idx(u8 pal_idx, u8 number_palettes) {
    pal_apply_shaders((u16)(pal_idx * 16), (u16)(number_palettes * 16));
}

void pal_apply_shaders_by_oam_palette_idx(u8 oam_pal_idx) {
    pal_apply_shaders((u16)(oam_pal_idx * 16 + 256), 16);
}

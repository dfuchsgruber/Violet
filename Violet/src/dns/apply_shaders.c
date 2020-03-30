#include "types.h"
#include "bios.h"
#include "rtc.h"
#include "color.h"
#include "dns.h"
#include "constants/vars.h"
#include "constants/shader_states.h"
#include "vars.h"
#include "save.h"


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

void pal_apply_shaders(u16 start_color, u16 number_colors) {
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
        default:
            return;
    }
    cpuset(&pal_restore[start_color], &pals[start_color], CPUSET_HALFWORD | CPUSET_COPY | CPUSET_HALFWORD_SIZE(number_colors * sizeof(color_t)));
}

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

void pal_apply_shaders_by_palette_idx(u8 pal_idx, u8 number_palettes) {
    pal_apply_shaders((u16)(pal_idx * 16), (u16)(number_palettes * 16));
}

void pal_apply_shaders_by_oam_palette_idx(u8 oam_pal_idx) {
    pal_apply_shaders((u16)(oam_pal_idx * 16 + 256), 16);
}

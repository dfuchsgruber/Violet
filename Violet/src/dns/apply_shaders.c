#include "types.h"
#include "rtc.h"
#include "color.h"
#include "dns.h"
#include "constants/vars.h"
#include "constants/shader_states.h"
#include "vars.h"

u8 dns_get_alpha() {
    u16 timezone = *var_access(SHADER_STATE);
    u8 alpha = 0;
    if (timezone == SHADER_CEOMETRIA_GYM_PUNISHMENT_ROOM) {
        alpha = 11;
    } else if (dns_on()) {
        switch (timezone) {
            case SHADER_NIGHT:
            case SHADER_MORNING:
            { //night
                alpha = 14;
                break;
            }
            case SHADER_EVENING:
            { //evening
                alpha = 13;
                break;
            }
        }
    }
    return alpha;
}

color_t dns_get_over() {
    u16 timezone = *var_access(SHADER_STATE);
    u16 o = 0;
    if (timezone == SHADER_CEOMETRIA_GYM_PUNISHMENT_ROOM) {
        o = 0x4D06;
    } else if (dns_on()) {
        switch (timezone) {
            case SHADER_NIGHT:
            { //night
                o = 0x4D06;
                break;
            }
            case SHADER_MORNING:
            { //morning
                o = 0x65ff;
                break;
            }
            case SHADER_EVENING:
            { //evening
                o = 0x29fd;
                break;
            }
        }
    }
    color_t over = {o};
    return over;
}

void dns_apply_shaders(u16 start_col, u16 col_cnt) {
    int shader_state = *var_access(SHADER_STATE);
    if (
        (dns_on() && (shader_state == SHADER_NIGHT || shader_state == SHADER_EVENING || shader_state == SHADER_MORNING)) ||
        (shader_state == SHADER_CEOMETRIA_GYM_PUNISHMENT_ROOM)
    )
    if (*var_access(SHADER_STATE) && dns_on()) {
        dns_blend_colors(start_col, col_cnt, dns_get_over(), dns_get_alpha());
    }
}

void dns_blend_colors(u16 start_col, u16 col_cnt, color_t overlay, u8 alpha) {
    u16 end_col = (u16) (start_col + col_cnt);
    while (start_col < end_col) {
        color_t original = pal_restore[start_col];
        color_t new = color_blend_and_multiply(original, overlay, alpha);
        pal_restore[start_col] = new;
        pals[start_col] = new;
        start_col++;
    }
}

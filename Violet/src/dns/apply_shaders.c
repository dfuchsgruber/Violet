#include "types.h"
#include "rtc.h"
#include "color.h"
#include "dns.h"
#include "constants/vars.h"
#include "vars.h"

u8 dns_get_alpha() {
    u16 timezone = *var_access(SHADER_STATE);
    u8 alpha = 0;
    if (dns_on()) {
        switch (timezone) {
            case 1:
            case 2:
            { //night
                alpha = 14;
                break;
            }
            case 3:
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
    if (dns_on()) {
        switch (timezone) {
            case 1:
            { //night
                o = 0x4D06;
                break;
            }
            case 2:
            { //morning
                o = 0x65ff;
                break;
            }
            case 3:
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
    
    if (*var_access(SHADER_STATE) && dns_on()) {
        dns_blend_colors(start_col, col_cnt, dns_get_over(), dns_get_alpha());
    }
    //dprintf("dns apply shaders\n");

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

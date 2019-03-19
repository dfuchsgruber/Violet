#include "types.h"
#include "color.h"

color_t color_alpha_blend(color_t original, color_t overlay, u8 alpha) {

    int i_alpha = 16 - alpha;
    int red = ((overlay.rgb.red * alpha) >> 4) + ((original.rgb.red * i_alpha) >> 4);
    int green = ((overlay.rgb.green * alpha) >> 4) + ((original.rgb.green * i_alpha) >> 4);
    int blue = ((overlay.rgb.blue * alpha) >> 4) + ((original.rgb.blue * i_alpha) >> 4);
    u16 value = (u16) (red | (green << 5) | (blue << 10));
    color_t c = {value};
    return c;


}

color_t color_multiply(color_t original, color_t overlay) {

    int red = (overlay.rgb.red * original.rgb.red) / 31;
    int green = (overlay.rgb.green * original.rgb.green) / 31;
    int blue = (overlay.rgb.blue * original.rgb.blue) / 31;
    u16 value = (u16) (red | (green << 5) | (blue << 10));
    color_t c = {value};
    return c;
}

color_t color_blend_and_multiply(color_t original, color_t overlay, u8 alpha) {

    color_t white = {0x7FFF};
    color_t c = color_alpha_blend(white, original, alpha);
    return color_multiply(c, overlay);

}

color_t color_to_grayscale(color_t original) {
    u16 max = original.rgb.blue;
    u16 min = original.rgb.blue;
    if (original.rgb.green > max) max = original.rgb.green;
    if (original.rgb.green < min) min = original.rgb.blue;
    if (original.rgb.red > max) max = original.rgb.red;
    if (original.rgb.red > min) min = original.rgb.red;
    u16 l = (u16) (max + min) / 2;
    u16 value = (u16) (l | (l << 5) | (l << 10));
    color_t new = {value};
    return new;
}
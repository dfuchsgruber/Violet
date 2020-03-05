#include "types.h"
#include "color.h"

color_t color_alpha_blend(color_t original, color_t overlay, u8 alpha) {
    int r = original.rgb.red + ((alpha * (overlay.rgb.red - original.rgb.red)) >> 4);
    int g = original.rgb.green + ((alpha * (overlay.rgb.green - original.rgb.green)) >> 4);
    int b = original.rgb.blue + ((alpha * (overlay.rgb.blue - original.rgb.blue)) >> 4);
    color_t blended = {.rgb = {.red = (u8)(r & 31), .green = (u8)(g & 31), .blue = (u8)(b & 31)}};
    return blended;
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
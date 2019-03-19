#include "types.h"

#ifndef COLOR
#define COLOR

typedef struct {
    u16 red : 5;
    u16 green : 5;
    u16 blue : 5;
    u16 unused : 1;
} rgb_t;

typedef union {
    u16 value;
    rgb_t rgb;
} color_t;

typedef struct {
    color_t *palette;
    u16 tag;
    u16 filler;
} pal_resource;


extern color_t pal_restore[];
extern color_t pals[];
extern color_t pal_tmp[];
extern color_t typechart_icon_pal[16];
extern color_t tbox_pokeball_pal[16];


/**
 * Alpha blends a single color
 * @param original Base color
 * @param overlay Target color
 * @param alpha Alpha channel intensity
 * @return The blended color
 */
color_t color_alpha_blend(color_t original, color_t overlay, u8 alpha);

/**
 * Performs color multiplication to blend colors into one another
 * @param original Base color
 * @param overlay Target color
 * @return The blended color
 */
color_t color_multiply(color_t original, color_t overlay);

/**
 * Performs color alpha blending and multiplication both
 * @param original Base color
 * @param overlay Target color
 * @param alpha Alpha channel intensity
 * @return The blended color
 */
color_t color_blend_and_multiply(color_t original, color_t overlay, u8 alpha);

/**
 * Transforms a color into grayscale
 * @param original The color to transform
 * @return The grayscaled color
 */
color_t color_to_grayscale(color_t original);

/**
 * Blends colors using (probably) alpha blending
 * @param color_index Index of the first color that will be blended
 * @param num_colors Number of colors that will be blended
 * @param intensity Intensity of the blending (0-15)
 * @param target_color Color to blend into
 */
void pal_blend(u16 color_index, u16 num_colors, u8 intesity, color_t target_color);

/**
 * Copies a palette (uncompressed) into palette buffers
 * @param src Palette data to copy
 * @param dst_col Color index (0-511) of the first color in destination
 * @param size The palette size (in bytes = 2 per color)
 */
void pal_copy(const void *src, u16 dst_col, u16 size);

/**
 * Decompresses and copies a palette into palette buffers
 * @param dst_col Color index (0-511) of the first color in destination
 * @param size The palette size (in bytes = 2 per color)
 */
void pal_decompress(const void* src, u16 dst_col, u16 size);

/**
 * Copies all palettes into the PAL RAM
 */
void pal_proceed();

/**
 * Sets all colors to black (color = 0)
 */
void pal_set_all_to_black();

/**
 * Applies a shader to a palette based on the pal in pal_restore
 * @param ow_pal the palette id
 */
void pal_apply_shader(u8 ow_pal);

/**
 * Applies the current fading state to a palette based on the pal in pal_restore
 * @param ow_pal the palette id
 */
void pal_apply_fading(u8 ow_pal);


#endif

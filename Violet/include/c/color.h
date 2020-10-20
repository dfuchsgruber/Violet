
#ifndef H_COLOR
#define H_COLOR

#include "types.h"

#define PALS 0x05000000

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


// Backup of palettes prior to application of fading effects
extern color_t pal_restore[512];
// Synced with the palette RAM using the DMA3
extern color_t pals[512];
// Used for temporarily storing palettes when decompressing
extern color_t pal_tmp[512];
extern color_t typechart_icon_pal[16];
extern color_t tbox_pokeball_pal[16];
// ?
extern color_t pal_backup[512];

/**
 * Alpha blends a single color
 * @param original Base color
 * @param overlay Target color
 * @param alpha Alpha channel intensity
 * @return The blended color
 */
color_t color_alpha_blend(color_t original, color_t overlay, u8 alpha);

#define COLOR_MULTIPLY_IDENTITY 0x7FFF
#define COLOR_MULTIPLY_ZERO 0

u8 color_multiplication_lut[32][32];

#define COLOR_MULTIPLY_ACCURATE_LUT 1

static inline color_t color_multiply(color_t original, color_t overlay) {
    #if COLOR_MULTIPLY_ACCURATE_LUT
    u16 value = (u16) (
        (color_multiplication_lut[original.rgb.red][overlay.rgb.red] << 0) | 
        (color_multiplication_lut[original.rgb.green][overlay.rgb.green] << 5) | 
        (color_multiplication_lut[original.rgb.blue][overlay.rgb.blue] << 10)
    );
    #else
    // Preserve rgb(31, 31, 31) as identity element, rgb(0, 0, 0) is preserved as zero-element by definition
    if (original.value == COLOR_MULTIPLY_IDENTITY) 
        return overlay;
    if (overlay.value == COLOR_MULTIPLY_IDENTITY) 
        return original; 
    u16 value = (u16)(
        ((original.rgb.red * overlay.rgb.red / 32) << 0) |
        ((original.rgb.green * overlay.rgb.green / 32) << 5) |
        ((original.rgb.blue * overlay.rgb.blue / 32) << 10)
    );
    #endif
    color_t c = {.value = value};
    return c;
}

/**
 * Does color multiplication to pals
 * @param start_color the first color to multiply
 * @param number_colors how many colors to multiply
 * @param filter the filter to multiply with
 **/
void pal_color_multiply(u16 start_color, u16 number_colors, color_t filter);

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
 * Sets all colors in `pals` to white (color = .rgb(31, 31, 31))
 **/
void pal_set_all_to_white();

/**
 * Updates the pal_backup buffer with the values form pal_restore
 * @param start_color the first color to update
 * @param number_colors how many colors should be updated
 **/
void pal_update_backup(u16 start_color, u16 number_colors);

/**
 * Applies an in-place greyscale filter to a set of colors.
 * @param src the set of colors to modify
 * @param the size of the color set to modify
 **/
void pal_apply_greyscale(color_t *src, u16 number_colors);

/**
 * Applies an in-place sepia filter to a set of colors.
 * @param src the set of colors to modify
 * @param the size of the color set to modify
 **/
void pal_apply_sepia(color_t *src, u16 number_colors);

/**
 * Applies active palette shaders (sepia, greyscale, dns filter) to the pal_restore.
 * @param start_color the first color to affect
 * @param number_colors the number of colors to be affected
 **/
void pal_apply_shaders(u16 start_color, u16 number_colors);

/**
 * Applies active palette shaders (sepia, greyscale, dns filter) to the pal_restore given a palette idx and a number of palettes.
 * @param pal_idx the index of the first palette to affect
 * @param number_palettes the number of palettes to affect
 **/
void pal_apply_shaders_by_palette_idx(u8 pal_idx, u8 number_palettes);

/**
 * Applies active palette shaders (sepia, greyscale, dns filter) to the pal_restore given a oam palette idx.
 * @param oam_pal_idx the index of the oam palette
 **/
void pal_apply_shaders_by_oam_palette_idx(u8 oam_pal_idx);

/**
 * Applies alpha blending to a set of colors using the pal_restore to create colors in pals.
 * @param start_color the first color to blend
 * @param number_colors the number of consecutive colors to affect
 * @param alpha the alpha value of the blending
 * @param overlay the overlay color that is blended
 **/
void pal_alpha_blending(u16 start_color, u16 number_colors, u8 alpha, color_t overlay);


enum {
    GAMMA_NONE,
    GAMMA_NORMAL,
    GAMMA_ALTERNATIVE
} gamma_types;

/**
 * Applies a gamma shift to a set of colors using the pal_restore to create colors in pals.
 * @param pal_idx the first palatte that is affected by the gamma shift
 * @param number_pals the number of consecutive palettes affected by the gamma shift
 * @param gamma the gamma value
 **/
void pal_gamma_shift(u8 pal_idx, u8 number_pals, s8 gamma);

/**
 * Applies a gamma shift to a set of colors using the pal_restore to create colors in pals. Also applies alpha blending.
 * @param pal_idx the first palatte that is affected by the gamma shift
 * @param number_pals the number of consecutive palettes affected by the gamma shift
 * @param gamma the gamma value
 * @param alpha the value of alpha blending
 * @param blending the filter to blend over the pals
 **/
void pal_gamma_shift_with_blend(u8 pal_idx, u8 number_pals, s8 gamma, u8 alpha, color_t blending);

/**
 * Gets the gamma type of a palette.
 * @param pal_idx the palette to check (0-31)
 * @return the gamma type used for the palette (adaptive to dynamic overworlds)
 **/
u8 palette_get_gamma_type(u8 pal_idx);

/**
 * Applies fading effects to the oam palette.
 * @param oam_pal_idx the oam palette idx to affect
 **/
void pal_oam_apply_fading(u8 oam_pal_idx);

// If a buffer transfer using the dma3 is requested
extern u32 palette_proceed_dma_transfer_requested;

#endif

#include "types.h"
#include "gpu.h"
#include "debug.h"

void gpu_fill_rectangle_4bpp(void *sprite, int x0, int y0, int x1, int y1, u32 color, size_t area_width) {

    if (area_width & 7) 
        ERROR("Filling a 4bpp rectangle in a tiled bitmap only works with area widths divisble by 8, not %d\n.", area_width);
    size_t area_width_tiles = area_width / 8;

    u32 *sprite32 = (u32*)sprite;

    // Assemble a "row" filled with color
    color &= 0xF;
    u32 fill = 0;
    for (int i = 0; i < 8; i++) {
        fill <<= 4;
        fill |= color;
    }
    u32 mask = 0xFFFFFFFF;

    // Iterate over rows
    for (int y = y0; y < y1; y++) {
        // Iterate over 8-pixel chunks (32 bit integers)
        for (int xx = x0 & (~7); xx < x1; xx += 8) {
            // TODO: handle borders
            u32 apply = mask;
            int tile_x = xx / 8;
            int tile_y = y / 8;
            // Horizontal edge cases
            if (xx < x0)
                apply <<= 4 * (x0 - xx);
            if (xx + 8 > x1)
                apply &= (0xFFFFFFFF) >> (4 * (xx + 8 - x1));


            u32 *row = sprite32 + 8 * (tile_y * (int)area_width_tiles + tile_x) + (y & 7);
            *row = ((*row) & (~apply)) | (fill & apply);
        }
    }
}
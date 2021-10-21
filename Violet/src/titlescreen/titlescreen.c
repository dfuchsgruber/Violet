#include "titlescreen.h"
#include "bg.h"
#include "bios.h"
#include "callbacks.h"
#include "color.h"
#include "debug.h"
#include "io.h"
#include "math.h"
#include "prng.h"
#include "types.h"

extern const unsigned short gfx_ts_start_higherTiles[]; //lz77
extern const unsigned short gfx_ts_start_higherMap[];   //lz77
extern const unsigned short gfx_ts_start_higherPal[];   //not lz77

extern const unsigned short gfx_ts_deoxys_0Tiles[];
extern const unsigned short gfx_ts_deoxys_0Map[];
extern const unsigned short gfx_ts_deoxys_1Tiles[];
extern const unsigned short gfx_ts_deoxys_1Map[];
extern const unsigned short gfx_ts_deoxys_2Tiles[];
extern const unsigned short gfx_ts_deoxys_2Map[];
extern const unsigned short gfx_ts_deoxys_0Pal[];

extern const unsigned short gfx_ts_start_lowerTiles[];
extern const unsigned short gfx_ts_start_lowerMap[];
extern const unsigned short gfx_ts_start_lowerPal[];

extern const unsigned short gfx_ts_titleTiles[];
extern const unsigned short gfx_ts_titleMap[];
extern const unsigned short gfx_ts_titlePal[];

extern const unsigned short gfx_ts_bgTiles[];
extern const unsigned short gfx_ts_bgMap[];
extern const color_t gfx_ts_bgPal[];

const unsigned short *ts_deoxysTiles[] = {
    gfx_ts_deoxys_0Tiles,
    gfx_ts_deoxys_1Tiles,
    gfx_ts_deoxys_2Tiles,
    gfx_ts_deoxys_1Tiles};

const unsigned short *ts_deoxysMap[] = {
    gfx_ts_deoxys_0Map,
    gfx_ts_deoxys_1Map,
    gfx_ts_deoxys_2Map,
    gfx_ts_deoxys_1Map};

const u16 ts_deoxysScroll[] = {
    0, 1, 0, 0xFFFF, 0xFFFE, 0xFFFC, 0xFFFE, 0xFFFF};

void ts_setup_pal() {
    pal_copy(gfx_ts_titlePal, 0, 12 * 32);
    pal_copy(gfx_ts_bgPal, 12 * 16, 32);
    pal_copy(gfx_ts_deoxys_0Pal, 13 * 16, 32);
    pal_copy(gfx_ts_start_higherPal, 14 * 16, 32);
    pal_copy(gfx_ts_start_lowerPal, 15 * 16, 32);
}

void ts_setup_bg() {
    //Load palettes
    ts_setup_pal();

    //Load the tilesets
    bg_decompress_vram(0, gfx_ts_titleTiles, 0, 0, false);
    bg_decompress_vram(1, gfx_ts_deoxys_0Tiles, 0, 0, false);
    bg_decompress_vram(2, gfx_ts_start_higherTiles, 0, 0, false);
    bg_decompress_vram(2, gfx_ts_start_lowerTiles, 0, 13, false);
    bg_decompress_vram(3, gfx_ts_bgTiles, 0, 0, false);
    //mind that at tileset change 13 might change to a bigger or smaller value
    //Also in lowerMaps grit file you might change the displacement value maXX
    //respectivly (kinda ugly workarround here...)
    bg_decompress_vram(0, gfx_ts_titleMap, 0, 0, true);
    bg_decompress_vram(1, gfx_ts_deoxys_0Map, 0, 0, true);
    bg_decompress_vram(2, gfx_ts_start_higherMap, 0, 0, true);
    bg_decompress_vram(2, gfx_ts_start_lowerMap, 0, 36, true);
    bg_decompress_vram(3, gfx_ts_bgMap, 0, 0, true);
}

void ts_color_anim(u16 *vars) {
    if (++(vars[3]) > 7) { //4 as frames between color change
        vars[3] = 0;

        //do a color change
        if (!vars[4]) {
            //increment
            if (++(vars[5]) == 5) {
                //switch to decrement
                vars[4] = 1;
            }
        } else {
            if (--(vars[5]) == 0) {
                //switch to increment
                vars[4] = 0;
            }
        }

        color_t col_pure_violet = {0};
        col_pure_violet.rgb.blue = 31;
        col_pure_violet.rgb.red = 31;
        int i;
        for (i = 6; i < 12; i++) {
            color_t n = color_alpha_blend(gfx_ts_bgPal[i], col_pure_violet, (u8)vars[5]);
            //kinda ugly to push directly into restore, but this way we force a
            //100% correctness even at fadescreen
            pal_restore[12 * 16 + i] = n;
            pals[12 * 16 + i] = n;
        }
    }
}

void ts_animation_sprite(u16 *vars) {
    //probably the most ugly thing to do, but we know fixed vram offsets
    if (++(vars[6]) > 7) {
        vars[6] = 0;
        vars[7] = (vars[7] + 1) & 7;

        //Vscroll
        io_set(0x16, ts_deoxysScroll[vars[7]]);

        //Graphic copy
        if (!(vars[7] & 1)) {
            lz77uncompvram(ts_deoxysTiles[vars[7] / 2], (u16 *)0x06004000);
            lz77uncompvram(ts_deoxysMap[vars[7] / 2], (u16 *)0x0600F000);
        }
    }
}

void ts_animation_step(u16 *vars) {
    //we are free to use the vars from index 3 upwards
    u8 ts_main_cb_id = big_callback_get_id(titlescreen_handle);

    if (big_callbacks[ts_main_cb_id].params[0] == 3 &&
        big_callbacks[ts_main_cb_id].params[1] == 1) {
        //do an animation
        ts_color_anim(vars);
        ts_animation_sprite(vars);
    }
}

#include "types.h"
#include "stdbool.h"
#include "transparency.h"
#include "constants/flags.h"
#include "flags.h"
#include "overworld/map_control.h"
#include "io.h"
#include "constants/specials.h"
#include "text.h"
#include "bg.h"
#include "debug.h"
#include "callbacks.h"
#include "constants/map_weathers.h"

const color_t tbox_palette_transparent[16] = {
    {0x0},
    {0x0},
    {0x7FFF},
    {0x0},
    {0x7FFF},
    {0x0},
    {0x0},
    {0x0},
    {0x7FFF},
    {0x0},
    {0x0},
    {0x0},
    {0x0},
    {0x0},
    {0x0},
    {0x0},
};

bool transparency_is_on() {
    //DEBUG("Transparency used by weather %d, bypassed %d\n", transparency_used_by_weather(), checkflag(FLAG_BYPASS_TRANSPARENCY));
    return !checkflag(TRANS_DISABLE) && !transparency_used_by_weather();
}

static const u8 weather_uses_transparency[NUM_MAP_WEATHERS] = {
    [MAP_WEATHER_STATIC_FOG] = true,
    [MAP_WEATHER_SANDSTORM] = true,
    [MAP_WEATHER_DYNAMIC_FOG] = true,
    [MAP_WEATHER_DENSE_FOG] = true,
    [MAP_WEATHER_LIGHT_STATIC_FOG] = true,
};

bool transparency_used_by_weather() {
    return weather_uses_transparency[map_get_current_weather()];
}

void transparency_on() {
    if (transparency_used_by_weather())
        return;
    // setflag(TRANS_PALETTE_FETCH);
    io_set(0x48, 0x1F3F);
    io_set(0x50, 0x3F41);
    io_set(0x52, 0x060F);
}

void transparency_off() {
    if (!transparency_used_by_weather()) {
        io_set(0x48, 0x1F1F);
        io_set(0x50, 0x1E40);
        io_set(0x52, 0x0010);
    }
}


extern const void *gfx_text_std_borderTiles[];
extern const color_t gfx_text_std_borderPal[16];

void tbox_frame_std_load_gfx_and_pal(u8 tbox_idx, u16 tile_offset, u16 color_idx) {
    bg_load_tileset((u8)tbox_get_attribute(tbox_idx, TBOX_ATTRIBUTE_BG), gfx_text_std_borderTiles, 0x280, tile_offset);
    pal_copy(gfx_text_std_borderPal, color_idx, 16 * sizeof(color_t));
}

void tbox_frame_transparent_load_gfx_and_pal() {
    bg_load_tileset((u8)tbox_get_attribute(0, TBOX_ATTRIBUTE_BG), gfx_text_std_borderTiles, 0x280, 0x200);
    pal_copy(tbox_palette_transparent, 15 * 16, 16 * sizeof(color_t));
}

void overworld_tbox_load_gfx() {
    if (transparency_is_on()) {
        transparency_on();
        tbox_frame_transparent_load_gfx_and_pal();
    } else if (overworld_tbox_is_sign()) {
        transparency_off();
        tbox_load_sign_gfx_and_pal();
    } else {
        transparency_off();
        tbox_load_message_gfx_and_pal();
    }
}

/**
static void callback_transparency_disable(u8 self){
    if (transparency_is_on())
        transparency_off();
    big_callback_delete(self);
}
**/

void overworld_tbox_delete() {
    //big_callback_new(callback_transparency_disable, 0); // 1 frame later
    overworld_tbox_remove_task();
    tbox_clear_message(0, 1);
    overworld_tbox_state = 0;
    if (transparency_is_on())
        transparency_off();
}
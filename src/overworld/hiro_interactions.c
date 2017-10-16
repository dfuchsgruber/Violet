#include "types.h"
#include "oams.h"

extern const int gfx_ow_surfTiles[];

graphic ow_hiro_surf_graphics[] = {
    {&gfx_ow_surfTiles[0x0], 0x200, 0},
    {&gfx_ow_surfTiles[0x80], 0x200, 0},
    {&gfx_ow_surfTiles[0x100], 0x200, 0},
    {&gfx_ow_surfTiles[0x180], 0x200, 0},
    {&gfx_ow_surfTiles[0x200], 0x200, 0},
    {&gfx_ow_surfTiles[0x280], 0x200, 0}
};

extern const int gfx_ow_arrowTiles[];

graphic ow_hiro_arrow_graphics[] = {
    {&gfx_ow_arrowTiles[0],0x80, 0},
    {&gfx_ow_arrowTiles[0x20],0x80, 0},
    {&gfx_ow_arrowTiles[0x40],0x80, 0},
    {&gfx_ow_arrowTiles[0x60],0x80, 0},
    {&gfx_ow_arrowTiles[0x80],0x80, 0},
    {&gfx_ow_arrowTiles[0xA0],0x80, 0},
    {&gfx_ow_arrowTiles[0xC0],0x80, 0},
    {&gfx_ow_arrowTiles[0xE0],0x80, 0}
};

extern const int gfx_ow_emojiTiles[];

graphic ow_hiro_emoji_graphics[] = {
    {&gfx_ow_emojiTiles[0x0], 0x80, 0},
    {&gfx_ow_emojiTiles[0x20], 0x80, 0},
    {&gfx_ow_emojiTiles[0x40], 0x80, 0},
    {&gfx_ow_emojiTiles[0x60], 0x80, 0},
    {&gfx_ow_emojiTiles[0x80], 0x80, 0},
    {&gfx_ow_emojiTiles[0xA0], 0x80, 0},
    {&gfx_ow_emojiTiles[0xC0], 0x80, 0},
    {&gfx_ow_emojiTiles[0xE0], 0x80, 0},
    {&gfx_ow_emojiTiles[0x100], 0x80, 0},
    {&gfx_ow_emojiTiles[0x120], 0x80, 0},
    {&gfx_ow_emojiTiles[0x140], 0x80, 0},
    {&gfx_ow_emojiTiles[0x160], 0x80, 0},
    {&gfx_ow_emojiTiles[0x180], 0x80, 0},
    {&gfx_ow_emojiTiles[0x1A0], 0x80, 0},
    {&gfx_ow_emojiTiles[0x1C0], 0x80, 0}
};

extern int gfx_ow_flyTiles[];

graphic ow_hiro_fly_graphics[] = {
    {&gfx_ow_flyTiles[0x0], 0x800, 0},
    {&gfx_ow_flyTiles[0x200], 0x800, 0},
    {&gfx_ow_flyTiles[0x400], 0x800, 0},
    {&gfx_ow_flyTiles[0x600], 0x800, 0},
    {&gfx_ow_flyTiles[0x800], 0x800, 0}
};
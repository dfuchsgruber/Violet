#include "types.h"
#include "text.h"
#include "constants/pokemon_types.h"

const move_info_gfx_t move_info_icon_gfxs[] = {
    [MOVE_INFO_NONE] = { 12, 12, 0x00 },
    [MOVE_INFO_TYPE_BASE + TYPE_NORMAL] = { 32, 12, 0x20 },
    [MOVE_INFO_TYPE_BASE + TYPE_KAMPF] = { 32, 12, 0x64 },
    [MOVE_INFO_TYPE_BASE + TYPE_FLUG] = { 32, 12, 0x60 },
    [MOVE_INFO_TYPE_BASE + TYPE_GIFT] = { 32, 12, 0x80 },
    [MOVE_INFO_TYPE_BASE + TYPE_BODEN] = { 32, 12, 0x48 },
    [MOVE_INFO_TYPE_BASE + TYPE_GESTEIN] = { 32, 12, 0x44 },
    [MOVE_INFO_TYPE_BASE + TYPE_KAEFER] = { 32, 12, 0x6C },
    [MOVE_INFO_TYPE_BASE + TYPE_GEIST] = { 32, 12, 0x68 },
    [MOVE_INFO_TYPE_BASE + TYPE_STAHL] = { 32, 12, 0x88 },
    [MOVE_INFO_TYPE_BASE + TYPE_FEE] = { 32, 12, 0xA4 }, 
    [MOVE_INFO_TYPE_BASE + TYPE_FEUER] = { 32, 12, 0x24 },
    [MOVE_INFO_TYPE_BASE + TYPE_WASSER] = { 32, 12, 0x28 },
    [MOVE_INFO_TYPE_BASE + TYPE_PFLANZE] = { 32, 12, 0x2C },
    [MOVE_INFO_TYPE_BASE + TYPE_ELEKTRO] = { 32, 12, 0x40 },
    [MOVE_INFO_TYPE_BASE + TYPE_PSYCHO] = { 32, 12, 0x84 },
    [MOVE_INFO_TYPE_BASE + TYPE_EIS] = { 32, 12, 0x4C },
    [MOVE_INFO_TYPE_BASE + TYPE_DRACHE] = { 32, 12, 0xA0 },
    [MOVE_INFO_TYPE_BASE + TYPE_UNLICHT] = { 32, 12, 0x8C },
    [MOVE_INFO_TYPE] = { 40, 12, 0xA8 },
    [MOVE_INFO_POWER] = { 40, 12, 0xC0 },
    [MOVE_INFO_ACCURACY] = { 40, 12, 0xC8 },
    [MOVE_INFO_PP] = { 40, 12, 0xE0 },
    [MOVE_INFO_EFFECT] = { 40, 12, 0xE8 },
    [MOVE_INFO_CATEGORY] = { 40, 12, 0x100 },
    [MOVE_INFO_PHYSICAL] = { 32, 12, 0x120 },
    [MOVE_INFO_SPECIAL] = { 32, 12, 0x124 },
    [MOVE_INFO_STATUS] = { 32, 12, 0x128 },
};
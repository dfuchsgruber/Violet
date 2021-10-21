#include "agbmemory.h"
#include "battle/bg.h"
#include "bios.h"
#include "color.h"
#include "constants/vars.h"
#include "dns.h"
#include "rtc.h"
#include "save.h"
#include "types.h"
#include "vars.h"

void battle_bg_load(u8 bg_id) {
    lz77uncompvram(battle_bgs[bg_id].tileset, (void *)0x6008000);
    lz77uncompvram(battle_bgs[bg_id].tilemap, (void *)0x600D000);
    pal_decompress(battle_bgs[bg_id].pal, 0x20, 0x60);
    // pal_apply_shaders(0x20, 0x30);
}

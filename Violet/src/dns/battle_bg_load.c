#include "types.h"
#include "rtc.h"
#include "color.h"
#include "save.h"
#include "dns.h"
#include "constants/vars.h"
#include "battle/bg.h"
#include "vars.h"
#include "bios.h"
#include "agbmemory.h"

void battle_bg_load(u8 bg_id) {

    lz77uncompvram(battle_bgs[bg_id].tileset, (void*) 0x6008000);
    lz77uncompvram(battle_bgs[bg_id].tilemap, (void*) 0x600D000);

    if (*var_access(SHADER_STATE) && dns_on()) {

        color_t *buf = (color_t*) malloc(0x60);
        color_t *prebuf = (color_t*) 0x02037ACC;
        lz77uncompwram(battle_bgs[bg_id].pal, prebuf);

        color_t over = dns_get_over();
        u8 alpha = dns_get_alpha();

        int i;
        for (i = 0; i < 0x30; i++) {
            color_t original = prebuf[i];
            color_t new = color_blend_and_multiply(original, over, alpha);
            buf[i] = new;
        }

        pal_copy(buf, 0x20, 0x60);

        free(buf);
    } else {
        pal_decompress(battle_bgs[bg_id].pal, 0x20, 0x60);
    }
}

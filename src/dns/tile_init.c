#include "types.h"
#include "romfuncs.h"
#include "rtc.h"
#include "map.h"
#include "color.h"
#include "save.h"
#include "battle.h"
#include "dns.h"

void tile_init(mapfooter *foot) {

    if (*vardecrypt(VAR_TIMEZONE) == 1 && !*built_in_shaders && dns_on()) {

        u16 *pal_save_copy = (u16*) 0x020371F8;

        if (foot->tileset1 == &tilesets[0]) {
            //Tileset1 = 0
            pal_save_copy[0x21] = 0x377D;
            pal_save_copy[0x22] = 0x377D;
            pal_save_copy[0x25] = 0x1ABB;
        }
    }
}

#include "types.h"
#include "vars.h"
#include "music.h"
#include "save.h"
#include "map/header.h"
#include "constants/vars.h"
#include "debug.h"

u16 map_get_song() {
    dprintf("Saved music is %d\n", save1->map_music_override);
    u16 forced = *var_access(SONG_OVERRIDE);
    if(forced == 0xFFFF)return 0;
    if (forced) return forced;
    return get_mapheader(save1->bank, save1->map)->music;
}


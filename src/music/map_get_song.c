#include "types.h"
#include "vars.h"
#include "music.h"
#include "save.h"
#include "map/header.h"
#include "constants/vars.h"

u16 map_get_song() {
    u16 forced = *var_access(SONG_OVERRIDE);
    if(forced == 0xFFFF)return 0;
    if (forced) return forced;
    saveblock1 *s = *save1;
    return get_mapheader(s->bank, s->map)->music;
}


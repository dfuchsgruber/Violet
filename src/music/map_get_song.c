#include "types.h"
#include "romfuncs.h"
#include "music.h"
#include "map.h"
#include "save.h"

u16 current_map_get_song(){
    u16 forced = *vardecrypt(VAR_MAP_MUSIC_FORCE);
    if(forced) return forced;
    saveblock1 *s = *save1;
    return get_mapheader(s->bank, s->map)->music;
}


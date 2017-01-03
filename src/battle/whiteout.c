#include "types.h"
#include "romfuncs.h"
#include "music.h"
#include "battle.h"
#include "transparency.h"

void whiteout(){
    *vardecrypt(VAR_BATTLE_MUSIC) = 0;
    *vardecrypt(VAR_MAP_MUSIC_FORCE) = 0;
    clearflag(FLAG_BYPASS_TRANSPARENCY);
    setflag(FLAG_TRANSPARENCY_ON);
}
#include "types.h"
#include "romfuncs.h"
#include "music.h"
#include "battle.h"
#include "transparency.h"
#include "debug.h"


void whiteout(){
    *vardecrypt(VAR_BATTLE_MUSIC) = 0;
    *vardecrypt(VAR_MAP_MUSIC_FORCE) = 0;
    clearflag(FLAG_BYPASS_TRANSPARENCY);
    setflag(FLAG_TRANSPARENCY_ON);
}

void trainerbattle_after_battle(){
    void (*_trainerbattle_after_battle)() = (void(*)()) (0x08080408 | 1);
    _trainerbattle_after_battle();
    u8 *trainer_kind_of_battle = (u8*) 0x020386AC;
    u8 *battle_result = (u8*) 0x02023E8A;
    u16 *lastresult = (u16*) 0x020370D0;
    if(*trainer_kind_of_battle == 9 && (*battle_result == 3 || *battle_result == 2))
        *lastresult = 0xFF;
}
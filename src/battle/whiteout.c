#include "types.h"
#include "romfuncs.h"
#include "transparency.h"
#include "debug.h"
#include "battle/battler.h"
#include "constants/vars.h"
#include "constants/flags.h"


void whiteout(){
    *vardecrypt(BATTLE_SONG_OVERRIDE) = 0;
    *vardecrypt(SONG_OVERRIDE) = 0;
    clearflag(TRANS_DISABLE);
    setflag(TRANS_PALETTE_FETCH);
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

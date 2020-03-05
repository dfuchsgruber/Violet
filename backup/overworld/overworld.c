#include "types.h"
#include "agbmemory.h"
#include "save.h"
#include "constants/flags.h"
#include "flags.h"
#include "debug.h"

void map_reset_temporary_flags_and_vars() {
    memset(save1->tmp_vars_and_flags, 0, 32);
    clearflag(0x803);
    clearflag(0x804);
    clearflag(STRENGTH_USED);                   
    clearflag(FLAG_IN_BATTLE);
    clearflag(0x842);
    setflag(POKERADAR_POKEMON_SPAWNED);
}
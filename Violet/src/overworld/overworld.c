#include "types.h"
#include "agbmemory.h"
#include "save.h"
#include "constants/flags.h"
#include "flags.h"
#include "debug.h"

void map_reset_temporary_flags_and_vars() {
    memset(save1->flags, 0, 4); // Flags 0 - 32
    memset(save1->vars, 0, 16 * 2); // Vars 0 - 16
    clearflag(0x803);
    clearflag(0x804);
    clearflag(STRENGTH_USED);                   
    clearflag(FLAG_IN_BATTLE);
    clearflag(0x842);
    setflag(POKERADAR_POKEMON_SPAWNED);
    clearflag(FLAG_PLAYER_ON_LADDER);
}
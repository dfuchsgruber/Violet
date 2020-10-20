#include "types.h"
#include "overworld/map_control.h"
#include "constants/flags.h"
#include "map/header.h"
#include "save.h"
#include "flags.h"

bool map_flash_usable() {
    return !checkflag(FLASH_USED) && get_mapheader(save1->bank, save1->map)->flash_type;
}
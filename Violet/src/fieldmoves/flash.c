#include "constants/flags.h"
#include "constants/vars.h"
#include "debug.h"
#include "field_move.h"
#include "flags.h"
#include "overworld/map_control.h"
#include "overworld/pokemon_party_menu.h"
#include "overworld/script.h"
#include "save.h"
#include "tile/coordinate.h"
#include "types.h"
#include "vars.h"

void field_move_golem_regirock_overworld() {
    *var_access(LASTRESULT) = pokemon_party_menu_get_current_index();
    overworld_script_init(ow_script_field_move_golem_regirock);
}

bool field_move_check_flash() {
    if (map_flash_usable()) {
        pokemon_party_menu_continuation = pokemon_party_menu_return_and_execute_field_move;
        field_move_overworld_continuation = field_move_flash_overworld;
        return true;
    }
    // Check Regirock's cave
    position_t pos;
    player_get_position(&pos);
    dprintf("@ %d.%d with position %x,%x\n", save1->bank, save1->map, pos.coordinates.x, pos.coordinates.y);
    if (save1->bank == 28 && save1->map == 0 && pos.coordinates.x - 7 == 0x9 &&
        pos.coordinates.y - 7 == 0x1F && !checkflag(FLAG_REGIROCK_PUZZLE_SOLVED)) {
        pokemon_party_menu_continuation = pokemon_party_menu_return_and_execute_field_move;
        field_move_overworld_continuation = field_move_golem_regirock_overworld;
        return true;
    }
    return false;
}

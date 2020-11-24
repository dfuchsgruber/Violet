#include "types.h"
#include "pokemon/virtual.h"
#include "overworld/pokemon_party_menu.h"
#include "vars.h"
#include "debug.h"

void overworld_get_flash_level() {
    int flash_level = 3;
    int level = pokemon_get_attribute(player_pokemon + pokemon_party_menu_current_index, ATTRIBUTE_LEVEL, 0);
    if (level > 15)
        flash_level--;
    if (level > 25)
        flash_level--;
    if (level > 50)
        flash_level--;
    dprintf("Set flash level to %d because user has level %d\n", flash_level, level);
    *var_access(LASTRESULT) = (u16)MAX(0, flash_level);
}
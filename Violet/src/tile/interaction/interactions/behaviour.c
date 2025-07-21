#include "tile/block.h"
#include "types.h"
#include "tile/interaction.h"
#include "vars.h"
#include "tile/interaction/flavor_text.h"
#include "constants/block_behaviour.h"
#include "tile/interaction/tv.h"
#include "tile/interaction/pc.h"
#include "text.h"

const u8 *tile_interaction_get_by_tile_behaviour(const position_t *tile_position, u16 behaviour, u8 direction, u16 *interaction_sound) {
    player_facing = direction;

    const u8 *script = behaviour_get_flavor_text_script(tile_position, behaviour, direction);
    if (script != NULL) {
        return script;
    }
    switch(behaviour) {
        case MB_PC:
            *interaction_sound = 0; // No sound for PC interaction
            return ow_script_pc;
        case MB_REGION_MAP:
            return ow_script_region_map;
        case MB_POKEMON_CENTER_SIGN:
            if (direction == DIR_UP) {
                overworld_tbox_set_sign();
                return ow_script_pokemon_center_sign;
            }
            break;
        case MB_TELEVISION:
            return ow_script_tv;
        case MB_TRASH:
            return ow_script_trash;
        case MB_ROCK_CLIMB:
            return ow_script_rock_climb;
        case MB_CRAFTING_CAULDRON:
            return ow_script_crafting_cauldron;
    }
    return NULL;
}
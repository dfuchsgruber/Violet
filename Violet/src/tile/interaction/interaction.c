#include "types.h"
#include "tile/interaction.h"
#include "tile/block.h"
#include "overworld/script.h"
#include "music.h"

static const u8 *tile_interaction_get(const position_t *position, u16 behaviour, u8 direction, u16 *interaction_sound) {
    const u8 *script = tile_interaction_get_by_person(position, behaviour, direction);
    if (script != NULL)
        return script;

    script = tile_interaction_get_by_signpost(position, behaviour, direction);
    if (script != NULL)
        return script;

    script = tile_interaction_get_by_tile_behaviour(position, behaviour, direction, interaction_sound);
    if (script != NULL)
        return script;

    script = tile_interaction_get_by_water(position, behaviour, direction);
    if (script != NULL)
        return script;

    return NULL;
}



u8 overworld_script_initialize_by_tile_interaction(position_t *position, u16 behaviour, u8 direction){
    u16 interaction_sound = 5;
    const u8 *script = tile_interaction_get(position, behaviour, direction, &interaction_sound);
    if (script == NULL)
        return false;

    // Don't play interaction sound for certain scripts.
    if (interaction_sound != 0)
        play_sound(interaction_sound);

    overworld_script_init(script);
    return true;
}
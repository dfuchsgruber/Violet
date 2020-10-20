#include "types.h"
#include "overworld/npc.h"
#include "overworld/sprite.h"
#include "map/event.h"
#include "overworld/script.h"
#include "debug.h"
#include "save.h"
#include "vars.h"

bool overworld_script_command_spritebehave (overworld_script_state_t *state) {
    u8 person_idx = (u8)var_get(overworld_script_read_hword(state));
    u8 behaviour = *(state->script++);
    person_set_behaviour(person_idx, behaviour);
    u8 npc_idx = npc_get_by_person_idx(person_idx, save1->map, save1->bank);
    if (npc_idx < NUM_NPCS) {
        npcs[npc_idx].behavior_type = behaviour;
        oams[npcs[npc_idx].oam_id].callback = npc_movements_oam_callbacks[behaviour];
        dprintf("Person %d (npc %d) got behaviour %d\n", person_idx, npc_idx, behaviour);
    }
    return false;
}
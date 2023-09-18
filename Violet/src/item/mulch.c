#include "types.h"
#include "item/item.h"
#include "callbacks.h"
#include "overworld/pokemon_party_menu.h"
#include "overworld/map_control.h"
#include "overworld/npc.h"
#include "tile/coordinate.h"
#include "berry.h"
#include "constants/person_script_stds.h"
#include "map/event.h"
#include "map/header.h"
#include "save.h"
#include "debug.h"
#include "vars.h"
#include "language.h"
#include "overworld/script.h"
#include "item/bag.h"

extern const u8 ow_script_fertilize_berry_tree[];

static void item_mulch_overworld_continuation_print_string(u8 self) {
    overworld_script_init(ow_script_fertilize_berry_tree);
    DEBUG("Var 0x8000: %d, LASTTALKED %d\n", *var_access(0x8000), *var_access(LASTTALKED));
    big_callback_delete(self);
}

void item_effect_mulch(u8 self) {
    position_t faced_position;
    player_get_position_faced(&faced_position);
    u8 npc_idx = npc_get_by_position(faced_position.coordinates.x, faced_position.coordinates.y);
    DEBUG("Npc idx is %d\n", npc_idx);
    if (npc_idx < NUM_NPCS) {
	    const map_event_person *p = map_get_person(npcs[npc_idx].overworld_id, npcs[npc_idx].map, npcs[npc_idx].bank);
        if (p && p->script_std == PERSON_BERRY_TREE) {
            u16 berry_tree_idx = p->value;
            if (cmem.berry_trees[berry_tree_idx].stage == BERRY_STAGE_NO_BERRY && !cmem.berry_trees[berry_tree_idx].fertilized) {
                // The berry can be fertilized with mulch
                item_use_continuation = item_mulch_overworld_continuation_print_string;
                item_close_bag_and_return_to_overworld(self);
                *var_access(0x8000) = berry_tree_idx;
                *var_access(LASTTALKED) = npcs[npc_idx].overworld_id;
                return; 
            }
        }
    }
    item_print_string_can_not_be_used_by_oak(self, (u8)big_callbacks[self].params[3]);
}
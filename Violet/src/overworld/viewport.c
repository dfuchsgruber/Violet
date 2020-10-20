#include "types.h"
#include "overworld/npc.h"
#include "map/event.h"
#include "save.h"
#include "debug.h"

void overworld_viewport_set_position(s16 x, s16 y) {
    u8 npc_idx;
    if (!npc_get_id_by_overworld_id(MAP_EVENT_PERSON_VIEWPORT, save1->map, save1->bank, &npc_idx)) {
        dprintf("Found npc @ %x %d\n", npcs + npc_idx, npc_idx);
        npcs[npc_idx].origin_x = x;
        npcs[npc_idx].origin_y = y;
        npcs[npc_idx].dest_x = x;
        npcs[npc_idx].dest_y = y;
        npcs[npc_idx].from_x = x;
        npcs[npc_idx].from_y = y;
    }
    void (*rst)() = (void(*)()) 0x0805faa9;
    rst();
}

void test_overworld_viewport_set_position() {
    overworld_viewport_set_position(0x3F, 0x19);
}
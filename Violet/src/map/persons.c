#include "types.h"
#include "save.h"
#include "map/event.h"
#include "debug.h"

map_event_person *person_get_by_target_index(u8 target_index, map_event_person *persons, u8 num_persons){
    if(target_index == 254)
        return &(cmem.pokeradar_person);
    for(u8 i = 0; i < num_persons; i++)
        if(persons[i].target_index == target_index) return &persons[i];
    return NULL;
}

static bool person_in_connection_get_bank_and_map(u8 in_connection, u8 *bank, u8 *map_idx) {
    for (size_t k = 0; k < mapheader_virtual.connections->count; k++) {
        if (mapheader_virtual.connections->connections[k].direction == in_connection) {
            *bank = mapheader_virtual.connections->connections[k].bank;
            *map_idx = mapheader_virtual.connections->connections[k].map;
            return true;
        }
    }
    return false;
}

static map_event_person *person_in_connection_get_target(u8 in_connection, u8 target_person) {
    u8 bank, map_idx;
    if (!person_in_connection_get_bank_and_map(in_connection, &bank, &map_idx))
        return NULL;
    map_header_t *adj = get_mapheader(bank, map_idx);
    return person_get_by_target_index(target_person, 
                adj->events->persons, adj->events->person_cnt);
}

void persons_load_from_header() {
    int j = 0;
    for (int i = 0; i < mapheader_virtual.events->person_cnt; i++) {
        map_event_person *p = mapheader_virtual.events->persons + i;
        if (p->in_connection) {
            map_event_person *target = person_in_connection_get_target(p->in_connection, p->argument);
            if (!target) {
                dprintf("Didnt find target person %d on adjacency %d\n", p->argument, p->in_connection);
                continue;
            }
            save1->persons[j] = *target;
            // TODO: These can be inferred from the connection type (and should be !)
            save1->persons[j].x = p->x;
            save1->persons[j].y = p->y;

            save1->persons[j].target_index = p->target_index;
            // These values are needed to mark the person as in-connection even though it has been fully loaded otherwise.
            save1->persons[j].in_connection = p->in_connection;
            save1->persons[j].argument = p->argument;
            j++;
        } else {
            save1->persons[j++] = *p;
        }
    }
}

// @0x0805e080
u8 npc_create_by_person(map_event_person *p, u8 map_idx, u8 bank) {
    if (p->in_connection) {
        if (!person_in_connection_get_bank_and_map(p->in_connection, &bank, &map_idx)) {
            derrf("Adjacent map not found!\n");
            return NUM_NPCS;
        }
        p = person_in_connection_get_target(p->in_connection, p->argument);
        if (!p) {
            derrf("Adjacent target person %d not found for adjacecy %\n", p->argument, p->in_connection);
            return NUM_NPCS;
        }
    }
    u8 npc_idx = NUM_NPCS;
    if (npc_get_empty_idx(p->target_index, map_idx, bank, &npc_idx))
        return NUM_NPCS;
    npc *n = npcs + npc_idx;
    npc_clear(n);
    s16 x = (s16)(p->x + 7);
    s16 y = (s16)(p->y + 7);
    n->flags.active = true;
    n->flags.trigger_ground_effects_on_move = true;
    n->sprite = p->overworld_index;
    n->behavior_type = p->behavior;
    n->overworld_id = p->target_index;
    n->origin_x = x;
    n->origin_y = y;
    n->dest_x = x;
    n->dest_y = y;
    n->from_x = x;
    n->from_y = y;
    n->height.current = (u8)(p->level & 15);
    n->height.previous = (u8)(p->level & 15);
    n->rectangle.x = p->behavior_range_x;
    n->rectangle.y = p->behavior_range_y;
    n->trainer_trigger = (u8)(p->trainer_type_and_strength_flag);
    n->sight_range = (u8)(p->alert_radius);
    n->map = map_idx;
    n->bank = bank;
    n->movement_direction_previous = behaviour_initial_facing_directions[n->behavior_type];
    npc_set_direction(n, n->movement_direction_previous);
    npc_set_dynamic_picture(n);
    if (behaviour_has_range[n->behavior_type]) {
        if (n->rectangle.x == 0)
            n->rectangle.x++;
        if (n->rectangle.y == 0)
            n->rectangle.y++;
    }
    return npc_idx;
}
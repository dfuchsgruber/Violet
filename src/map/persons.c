#include "types.h"
#include "save.h"
#include "map.h"

map_event_person *person_get_by_target_index(u8 target_index, map_event_person *persons, u8 num_persons){
    if(target_index == 254)
        return &(cmem->pokeradar_person);
    for(u8 i = 0; i < num_persons; i++)
        if(persons[i].target_index == target_index) return &persons[i];
    return NULL;
}

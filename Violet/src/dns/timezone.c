#include "types.h"
#include "rtc.h"
#include "color.h"
#include "save.h"
#include "dns.h"
#include "tile/trash.h"
#include "constants/vars.h"
#include "constants/shader_states.h"
#include "constants/map_types.h"
#include "superstate.h"
#include "vars.h"

void callback_switch_timezone() {
    update_timezone();
    tmp_hash_update_seed();
    callback1_set((void*) 0x08056829); //return to normal map reload
}

void update_timezone() {
    rtc_timestamp stamp = {0};
    time_read(&stamp);

    u8 bank = save1->bank;
    u8 map = save1->map;

    if (bank == CEOMETRIA_GYM_PUNISHMENT_ROOM_BANK && map == CEOMETRIA_GYM_PUNISHMENT_ROOM_MAP_IDX &&
        ceometria_gym_room_is_negative(cmem.ceometria_gym_state.next_rooms[*var_access(CEOMETRIA_GYM_NEXT_ROOM)])) {
        // Negative (punishment) rooms are shaded in dark blue
        *var_access(SHADER_STATE) = SHADER_CEOMETRIA_GYM_PUNISHMENT_ROOM;
    } else if (is_inside_map(bank, map)) {
        *var_access(SHADER_STATE) = SHADER_NONE;
    } else {
        if (stamp.hour >= 22 || stamp.hour <= 6) {
            *var_access(SHADER_STATE) = SHADER_NIGHT; //night
        } else if (stamp.hour <= 8) {
            *var_access(SHADER_STATE) = SHADER_MORNING; //morning
        } else if (stamp.hour >= 20) {
            *var_access(SHADER_STATE) = SHADER_EVENING; //evening
        } else {
            *var_access(SHADER_STATE) = SHADER_NONE;
        }
    }
}

bool is_inside_map(u8 bank, u8 map) {

    map_header_t *head = get_mapheader(bank, map);
    u8 type = head->type;
    return (type == MAP_TYPE_BASEMENT) || (type == MAP_TYPE_INSIDE) || (type == MAP_TYPE_SECRET_BASE);
}

bool dns_on() {
    return !(save2->sound_state);
}

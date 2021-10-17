#include "types.h"
#include "rtc.h"
#include "color.h"
#include "save.h"
#include "dns.h"
#include "constants/vars.h"
#include "constants/shader_states.h"
#include "constants/map_types.h"
#include "superstate.h"
#include "vars.h"
#include "overworld/map_control.h"

void callback_switch_timezone() {
    update_timezone();
    callback1_set(overworld_return_to); //return to normal map reload
}

u8 dns_get_daytime() {
    rtc_timestamp stamp = {0};
    time_read(&stamp);
    if (stamp.hour >= 22 || stamp.hour <= 6) {
        return DAYTIME_NIGHT; //night
    } else if (stamp.hour <= 8) {
        return DAYTIME_MORNING; //morning
    } else if (stamp.hour >= 20) {
        return DAYTIME_EVENING; //evening
    } else {
        return DAYTIME_DAY;
    }
}

void update_timezone() {
    rtc_timestamp stamp = {0};
    time_read(&stamp);

    u8 bank = save1->bank;
    u8 map = save1->map;
    switch (pal_shaders) {
        case SHADER_GREYSCALE:
        case SHADER_SEPIA:
        case SHADER_GREYSCALE_AND_BACKUP:
            // These shaders are to be applied forcefully, so the time zone mustn't change while they are active
            return;
        default: {
            // Update the timezone based on the location of the player and the internal time
            if (bank == CEOMETRIA_GYM_PUNISHMENT_ROOM_BANK && map == CEOMETRIA_GYM_PUNISHMENT_ROOM_MAP_IDX &&
                ceometria_gym_room_is_negative(cmem.ceometria_gym_state.next_rooms[*var_access(CEOMETRIA_GYM_NEXT_ROOM)])) {
                // Negative (punishment) rooms are shaded in dark blue
                pal_shaders = SHADER_CEOMETRIA_GYM_PUNISHMENT_ROOM;
            } else if (is_inside_map(bank, map)) {
                pal_shaders = SHADER_NONE;
            } else {
                switch (dns_get_daytime()) {
                    case DAYTIME_NIGHT:
                        pal_shaders = SHADER_NIGHT; //night
                        break;
                    case DAYTIME_MORNING:
                        pal_shaders = SHADER_MORNING;
                        break;
                    case DAYTIME_EVENING:
                        pal_shaders = SHADER_EVENING;
                        break;
                    default:
                        pal_shaders = SHADER_NONE;
                        break;
                }
            }
        }
    }
}

bool is_inside_map(u8 bank, u8 map) {

    map_header_t *head = get_mapheader(bank, map);
    u8 type = head->type;
    return (type == MAP_TYPE_BASEMENT) || (type == MAP_TYPE_INSIDE) || (type == MAP_TYPE_SECRET_BASE);
}

bool dns_on() {
    switch (pal_shaders) {
        case SHADER_NIGHT:
        case SHADER_EVENING:
        case SHADER_MORNING:
            return !(cmem.settings.dns_disabled);
        case SHADER_CEOMETRIA_GYM_PUNISHMENT_ROOM:
            return true;
    }
    return false;
}

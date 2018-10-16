#include "types.h"
#include "rtc.h"
#include "color.h"
#include "save.h"
#include "dns.h"
#include "tile/trash.h"
#include "constants/vars.h"
#include "superstate.h"
#include "vars.h"

void callback_switch_timezone() {
    update_timezone();
    tmp_hash_update_seed();
    callback1_set((void*) 0x08056829); //return to normal map reload

}

void update_timezone() {

    rtc_timestamp stamp = {0, 0, 0, 0, 0, 0, 0};
    time_read(&stamp);

    u8 bank = save1->bank;
    u8 map = save1->map;

    if (is_inside_map(bank, map)) {
        *var_access(SHADER_STATE) = 0;
    } else {
        if (stamp.hour >= 22 || stamp.hour <= 6) {
            *var_access(SHADER_STATE) = 1; //night
        } else if (stamp.hour <= 8) {
            *var_access(SHADER_STATE) = 2; //morning
        } else if (stamp.hour >= 20) {
            *var_access(SHADER_STATE) = 3; //evening
        } else {
            *var_access(SHADER_STATE) = 0;
        }
    }
}

bool is_inside_map(u8 bank, u8 map) {

    map_header_t *head = get_mapheader(bank, map);
    u8 type = head->type;
    return (type == 4) || (type == 8) || (type == 9);
}

bool dns_on() {
    return !(save2->sound_state);
}

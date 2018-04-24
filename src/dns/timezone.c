#include "types.h"
#include "romfuncs.h"
#include "rtc.h"
#include "color.h"
#include "save.h"
#include "dns.h"
#include "tile/trash.h"
#include "constants/vars.h"

void callback_switch_timezone() {
    update_timezone();
    update_a_vector();
    set_callback1((void*) 0x08056829); //return to normal map reload

}

void update_timezone() {

    rtc_timestamp stamp = {0, 0, 0, 0, 0, 0, 0};
    rtc_read(&stamp);

    u8 bank = (*save1)->bank;
    u8 map = (*save1)->map;

    if (is_inside_map(bank, map)) {
        *vardecrypt(SHADER_STATE) = 0;
    } else {
        if (stamp.hour >= 22 || stamp.hour <= 6) {
            *vardecrypt(SHADER_STATE) = 1; //night
        } else if (stamp.hour <= 8) {
            *vardecrypt(SHADER_STATE) = 2; //morning
        } else if (stamp.hour >= 20) {
            *vardecrypt(SHADER_STATE) = 3; //evening
        } else {
            *vardecrypt(SHADER_STATE) = 0;
        }
    }
}

bool is_inside_map(u8 bank, u8 map) {

    mapheader *head = get_mapheader(bank, map);
    u8 type = head->type;
    return (type == 4) || (type == 8) || (type == 9);
}

bool dns_on() {
    return !((*save2)->sound_state);
}

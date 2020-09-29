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
#include "overworld/map_control.h"
#include "debug.h"

void callback_switch_timezone() {
    update_timezone();
    callback1_set(overworld_return_to); //return to normal map reload
}

static color_t dns_filter_colors[] = {
    [DAYTIME_DAY] = {.rgb = {31, 31, 31}}, // No filter should be applied
    [DAYTIME_NIGHT] = {.rgb = {.red = 0x7D / 8, .green = 0x7D / 8, .blue = 0xE2 / 8}},
    [DAYTIME_MORNING] = {.rgb = {.red = 0xE2 / 8, .green = 0xFA / 8, .blue = 0xD0 / 8}},
    [DAYTIME_EVENING] = {.rgb = {.red = 0xE0 / 8, .green = 0xB5 / 8, .blue = 0xB5 / 8}},
};

static u8 dns_filters[] = {
    [0] = DAYTIME_NIGHT,
    [1] = DAYTIME_NIGHT,
    [2] = DAYTIME_NIGHT,
    [3] = DAYTIME_NIGHT,
    [4] = DAYTIME_NIGHT,
    [5] = DAYTIME_NIGHT,
    [6] = DAYTIME_MORNING,
    [7] = DAYTIME_MORNING,
    [8] = DAYTIME_MORNING,
    [9] = DAYTIME_MORNING,
    [10] = DAYTIME_DAY,
    [11] = DAYTIME_DAY,
    [12] = DAYTIME_DAY,
    [13] = DAYTIME_DAY,
    [14] = DAYTIME_DAY,
    [15] = DAYTIME_DAY,
    [17] = DAYTIME_DAY,
    [18] = DAYTIME_DAY,
    [19] = DAYTIME_EVENING,
    [20] = DAYTIME_EVENING,
    [21] = DAYTIME_EVENING,
    [22] = DAYTIME_EVENING,
    [23] = DAYTIME_NIGHT,
    [24] = DAYTIME_NIGHT,
};

u8 dns_get_daytime() {
    rtc_timestamp stamp = {0};
    time_read(&stamp);
    return dns_filters[stamp.hour];
}

static color_t dns_get_color() {
    rtc_timestamp stamp = {0};
    time_read(&stamp);

    color_t color_from = dns_filter_colors[dns_filters[stamp.hour]];
    color_t color_to = dns_filter_colors[dns_filters[(stamp.hour + 1) % 24]];
    if (color_from.value != color_to.value) { // Interpolate between colors
        color_t mixed = {
            .rgb = {
                .red = (u8)((color_from.rgb.red + ((color_to.rgb.red - color_from.rgb.red) * stamp.minute) / 60) & 31),
                .green = (u8)((color_from.rgb.green + ((color_to.rgb.green - color_from.rgb.green) * stamp.minute) / 60) & 31),
                .blue = (u8)((color_from.rgb.blue + ((color_to.rgb.blue - color_from.rgb.blue) * stamp.minute) / 60) & 31),
            }
        };
        return mixed;
    } else {
        return color_from;
    }
}

void update_timezone() {
    u8 bank = save1->bank;
    u8 map = save1->map;
    fmem.dns_filter_mode = PAL_FILTER_NONE;
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
                fmem.dns_filter_mode = PAL_FILTER_COLOR_MULTIPLIY;
                color_t filter = {.rgb = {.red = 6, .green = 8, .blue = 19}};
                fmem.dns_filter = filter;
            } else if (is_inside_map(bank, map)) {
                fmem.dns_filter_mode = PAL_FILTER_NONE;
            } else if (dns_on()){
                fmem.dns_filter_mode = PAL_FILTER_COLOR_MULTIPLIY;
                fmem.dns_filter = dns_get_color();
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
    return !(save2->sound_state);
}

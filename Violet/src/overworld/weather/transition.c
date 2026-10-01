#include "types.h"
#include "overworld/tv.h"
#include "overworld/weather.h"
#include "map/header.h"
#include "save.h"

void map_transition_update_weather() {
    u8 map_weather = tv_event_weather_get_if_active(save1->bank, save1->map);
    if (map_weather >= NUM_MAP_WEATHERS) {
        map_weather = mapheader_virtual.weather;
    }
    u8 previous_weather = save1->map_weather;
    save1->map_weather = map_weather;
    overworld_weather_increment_rain_sav_key(map_weather, previous_weather);
}
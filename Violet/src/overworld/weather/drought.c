#include "types.h"
#include "overworld/weather.h"
#include "color.h"
#include "bios.h"
#include "save.h"


bool overworld_weather_drought_load_palettes() {
    if (overworld_weather.load_drought_pals_index < 32) {
        overworld_weather.load_drought_pals_index = 32;
        overworld_weather.load_drought_pals_offset = 32;
    }
    return false;
}

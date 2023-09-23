#include "types.h"
#include "overworld/weather.h"
#include "color.h"
#include "bios.h"
#include "save.h"

void weather_burning_trees_update_pal_restore_and_tmp() {
    weather_set_filter(MAP_WEATHER_BURNING_TREES);
    for (u8 pal_idx = 0; pal_idx < 32; pal_idx++) {
        u8 gamma_type = palette_get_gamma_type(pal_idx);
        if (gamma_type != GAMMA_NONE) {
            pal_color_multiply((u16)(16 * pal_idx), 16, weather_blend);
            // DEBUG("blending pal %d\n", pal_idx);
        }
    }
    cpuset(pal_restore, pal_tmp, CPUSET_COPY | CPUSET_HALFWORD | CPUSET_HALFWORD_SIZE(32 * 16 * sizeof(color_t)));
}
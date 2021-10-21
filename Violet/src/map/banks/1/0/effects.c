#include "callbacks.h"
#include "color.h"
#include "debug.h"
#include "fading.h"
#include "overworld/map_control.h"
#include "overworld/script.h"
#include "superstate.h"
#include "types.h"
#include "vars.h"

static void map_reload_if_fading_done(u8 self) {
    (void)self;
    if (!fading_control.active) {
        *var_access(VAR_MAP_TRANSITION_FADING_DELAY) = 8;
        pal_set_all_to_black();
        map_blocks_initialize();
        callback1_set(map_reload);
    }
}

void silvania_forest_white_blend_map_reload() {
    fadescreen_all(1, 8);
    big_callback_new(map_reload_if_fading_done, 0);
}

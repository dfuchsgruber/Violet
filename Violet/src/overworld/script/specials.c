#include "types.h"
#include "fading.h"
#include "callbacks.h"
#include "overworld/script.h"
#include "overworld/pokemon_party_menu.h"

void move_relearner_initialize() {
    overworld_script_set_active();
    big_callback_new(move_relearner_initialize_after_fading, 10);
    fadescreen_all(FADE_TO_BLACK, 0);
}
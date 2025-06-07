#include "attack.h"
#include "callbacks.h"
#include "fading.h"
#include "item/tm_hm.h"
#include "overworld/pokemon_party_menu.h"
#include "overworld/script.h"
#include "text.h"
#include "types.h"
#include "vars.h"

void move_relearner_initialize() {
    overworld_script_set_active();
    big_callback_new(move_relearner_initialize_after_fading, 10);
    fadescreen_all(FADE_TO_BLACK, 0);
}

bool special_x196_buffer_tm_hm_name() {
    // 8004 = item ID
    u16 item_idx = *var_access(0x8004);
    if (ITEM_IS_TM_OR_HM(item_idx)) {
        strcpy(
            buffer0, attack_names[item_idx_to_attack(item_idx)]);
        return true;
    } else {
        return false;
    }
}

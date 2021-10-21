#include "summary.h"
#include "battle/state.h"
#include "debug.h"
#include "types.h"

s8 summary_selected_party_idx_apply_delta_consider_tag_battles(s8 delta) {
    dprintf("Delta application\n");
    if (battle_is_tag()) {
        return summary_selected_party_idx_apply_delta_in_multi_battles(delta);
    } else {
        return summary_selected_party_idx_apply_delta(delta);
    }
}

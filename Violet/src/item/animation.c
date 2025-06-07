#include "item/animation.h"
#include "constants/items.h"
#include "types.h"
#include "item/tm_hm.h"

static const struct {
    u16 item_idx;
    u16 animation_type;
} item_animation_types[2] = {
    {ITEM_SONDERBONBON, 0},
    {ITEM_TRANK, 1},
};

u16 item_animation_get_animation_type(u16 item_idx) {
    for (size_t i = 0; i < ARRAY_COUNT(item_animation_types); i++) {
        if (item_animation_types[i].item_idx == item_idx) {
            return item_animation_types[i].animation_type;
        }
    }
    if (ITEM_IS_TM_OR_HM(item_idx)) {
        return 4; // TM/HM animation
    }
    return 0; // Default animation
}
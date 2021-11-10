#include "types.h"
#include "oam.h"
#include "debug.h"

static inline size_t oams_compress() {
    size_t num = 0;
    size_t num_inactive = NUM_OAMS;
    for (size_t i = 0; i < NUM_OAMS; i++) {
        if ((oams[i].flags & OAM_FLAG_ACTIVE) && !(oams[i].flags & OAM_FLAG_INVISIBLE)) {
            oam_order[num++] = (u8)i;
        } else {
            oam_order[--num_inactive] = (u8)i; // The inactive ones are always put last, since they wont be copied whatsoever... 
        }
    }
    return num;
}

static inline int oam_get_y(oam_object *o) {
    int y = o->final_oam.attr0 & 0xFF;
    if (y >= 160)
        y -= 256;
    if ((o->final_oam.attr0 & (ATTR0_ROTSCALE | ATTR0_DSIZE)) == (ATTR0_ROTSCALE | ATTR0_DSIZE) &&
        (o->final_oam.attr1 >> 14)  == (ATTR1_SIZE_64_64 >> 14)) {
        u32 shape = (o->final_oam.attr0 >> 14) & 3;
        if (shape == (ATTR0_SHAPE_SQUARE >> 14) || shape == (ATTR0_SHAPE_VERTICAL >> 14)) {
            if (y > 128)
                y -= 256;
        }
    }
    return y;
}


static inline bool oam_priority_greater(size_t idx_first, size_t idx_second) {
    idx_first = oam_order[idx_first];
    idx_second = oam_order[idx_second];
    u16 prio_first = oam_priorities[idx_first];
    u16 prio_second = oam_priorities[idx_second];
    if (prio_first > prio_second)
        return true;
    else if (prio_second > prio_first)
        return false;
    else {
        return oam_get_y(oams + idx_first) < oam_get_y(oams + idx_second);
    }
}

void oam_sort() {
    size_t n = oams_compress();
    if (n == 0)
        return;
    bool swapped;
    do {
        swapped = false;
        for (size_t i = 0; i < n - 1; i++) {
            if (oam_priority_greater(i, i + 1)) {
                u8 tmp = oam_order[i];
                oam_order[i] = oam_order[i + 1];
                oam_order[i + 1] = tmp;
                swapped = true;
            }
        }
        n--;
    } while (swapped);
}
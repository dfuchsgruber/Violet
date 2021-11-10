#include "types.h"
#include "oam.h"
#include "debug.h"

static inline size_t oams_compress() {
    int tail = NUM_OAMS - 1;
    int i = 0;
    while(i <= tail) {
        // Search the last active element
        while (tail >= 0 && (oams[oam_order[tail]].flags & (OAM_FLAG_ACTIVE | OAM_FLAG_INVISIBLE)) != OAM_FLAG_ACTIVE)
            tail--;
        // Tail now points the last active element
        if (i > tail) 
            break; // whole range [i...NUM_OAMS] is inactive, done
        else if ((oams[oam_order[i]].flags & (OAM_FLAG_ACTIVE | OAM_FLAG_INVISIBLE)) != OAM_FLAG_ACTIVE) {
            // i is an inactive oam, swap with tail and continue
            u8 tmp = oam_order[i];
            oam_order[i] = oam_order[tail]; // i is now an active oam
            oam_order[tail] = tmp;
        }
        i++; // either i was active to begin with or it was swapped with tail, which was active by definition
    }
    return (size_t)i;
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
    size_t swaps = 0;
    do {
        swapped = false;
        for (size_t i = 0; i < n - 1; i++) {
            if (oam_priority_greater(i, i + 1)) {
                u8 tmp = oam_order[i];
                oam_order[i] = oam_order[i + 1];
                oam_order[i + 1] = tmp;
                swapped = true;
                swaps++;
            }
        }
        n--;
    } while (swapped);
}
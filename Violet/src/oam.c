#include "types.h"
#include "oam.h"
#include "debug.h"
#include "superstate.h"

// Compresses the oam_order to [0...i, i+1...n_active], where all >= i+1 are active, but invisible and need not to be rendered
static inline size_t oam_compress_and_calculate_visible_cnt() {
    int tail = oam_order_compressed_size - 1;
    int i = 0;
    while(i <= tail) {
        // Search the last non-invisible element
        while (tail >= 0 && (oams[oam_order[tail]].flags & (OAM_FLAG_INVISIBLE)))
            tail--;
        // Tail now points the last non-invisible element
        if (i > tail) 
            break; // whole range [i...NUM_OAMS] is invisible, done
        else if ((oams[oam_order[i]].flags & (OAM_FLAG_INVISIBLE))) {
            // i is an invisible oam, swap with tail and continue
            u8 tmp = oam_order[i];
            oam_order[i] = oam_order[tail]; // i is now a visible oam
            oam_order[tail] = tmp;
        }
        i++; // either i was active to begin with or it was swapped with tail, which was active by definition
    }
    oam_visible_cnt = (u8)i;
    return oam_visible_cnt;
}


bool oam_order_compressed_remove_idx(u8 idx) {
    if (idx < NUM_OAMS && oam_order_compressed_size > 0) {
        for (size_t i = 0; i < oam_order_compressed_size; i++) {
            if (oam_order[i] == idx) {
                oam_order[i] = oam_order[oam_order_compressed_size - 1];
                oam_order_compressed_size--;
                return true;
            }
        }
    }
    return false;
}

bool oam_order_compressed_add_idx(u8 idx) {
    if (idx < NUM_OAMS && oam_order_compressed_size < NUM_OAMS) {
        oam_order[oam_order_compressed_size++] = idx;
        return true;
    }
    return false;
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

static inline u8 oam_object_to_idx(oam_object *o) {
    size_t delta = (size_t)o - (size_t)oams;
    if (delta % sizeof(oam_object) == 0) {
        return (u8)(delta / sizeof(oam_object));
    } else {
        return NUM_OAMS;
    }
}

void oam_calculate_position() {
    int cnt = oam_visible_cnt;
    for (int i = 0; i < cnt; i++) {
        oam_object *o = oams + oam_order[i];
        if (o->flags & OAM_FLAG_CENTERED) {
            o->final_oam.attr1 = (u16)(((o->final_oam.attr1 >> 9) << 9) | ((
                (o->x + o->x2 + o->x_centre + coordinate_camera_x_offset) & 0x1FF
            ) & 0x1FF));
            o->final_oam.attr0 = (u16)(((o->final_oam.attr0 >> 8) << 8) | (
                (o->y + o->y2 + o->y_centre + coordinate_camera_y_offset) & 0xFF
            ));
        } else {
            o->final_oam.attr1 = (u16)(((o->final_oam.attr1 >> 9) << 9) | ((
                (o->x + o->x2 + o->x_centre) & 0x1FF
            ) & 0x1FF));
            o->final_oam.attr0 = (u16)(((o->final_oam.attr0 >> 8) << 8) | (
                (o->y + o->y2 + o->y_centre) & 0xFF
            ));

        }
    }
}

void oam_calculate_priority() {
    int cnt = oam_visible_cnt;
    for (int i = 0; i < cnt; i++) {
        u8 oam_idx = oam_order[i];
        oam_object *o = oams + oam_idx;
        oam_priorities[oam_idx] = (u16)(o->priority_on_layer | ((o->final_oam.attr2 >> 10) & 3));
    }
}


void oam_sort() {
    size_t n = oam_visible_cnt;
    if (n == 0)
        return;
    // dprintf("compressed size %d\n", n);
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

static sprite oam_empty = {
    .attr0 = 160 | ATTR0_SHAPE_SQUARE, .attr1 = 304 | ATTR1_SIZE_8_8, .attr2 = ATTR2_PRIO(3),
};

void oam_copy_to_oam_buffer() {
    u8 cnt = 0;
    int vis_cnt = oam_visible_cnt;
    for (int i = 0; i < vis_cnt; i++) {
        if (oam_add_to_buffer(oams + oam_order[i], &cnt))
            return;
    }
    while(cnt < oam_buffer_size) {
        super.oam_attributes[cnt++] = oam_empty;
    }
}

void oam_proceed() {
    oam_compress_and_calculate_visible_cnt(); // compresses the oam_order such that the first indices are the ones to render
    // dprintf("Visible %d\n", oam_visible_cnt);
    oam_calculate_position();
    oam_calculate_priority();
    oam_sort();
    u8 tmp = super.disable_oams;
    super.disable_oams = true;
    oam_copy_to_oam_buffer();
    oam_copy_rotscale_to_buffer();
    super.disable_oams = (u8)(tmp & 1);
    oam_copy_requests_enabled = true;
}


void oam_clear(oam_object *o); // Declare it here so no other file is tempted to use it. This should only be called internally

void oam_clear_all() {
    u8 i;
    oam_order_compressed_size = 0;
    for (i = 0; i < NUM_OAMS; i++) {
        oam_clear(oams + i);
        oam_order[i] = i;
    }
    oam_clear(oams + i);
}

static void oam_free_sheet(oam_object *o) {
    if ((o->flags & OAM_FLAG_SPRITES) || !o->gfx_table)
        return;
    int base_tile = o->final_oam.attr2 & 0x3FF;
    int end_tile = base_tile + o->gfx_table->size / GRAPHIC_SIZE_4BPP(8, 8);
    for (int i = base_tile; i < end_tile; i++) {
        oam_vram_allocation[i >> 3] = (u8)(oam_vram_allocation[i >> 3] & (~(1 << (i & 7))));
    }
}

void oam_delete(oam_object *o) {
    if (o->flags & OAM_FLAG_ACTIVE) {
        oam_free_sheet(o);
        oam_clear(o);
        
        u8 idx = oam_object_to_idx(o);
        if (idx < NUM_OAMS) {
            oam_order_compressed_remove_idx(idx);
        }
    }
}

u8 oam_new_at(u8 idx, oam_template *template, s16 x, s16 y, u8 subpriority) {
    oam_object *o = oams + idx;
    oam_clear(o);
    o->flags |= OAM_FLAG_GFX_ANIM_START | OAM_FLAG_ROTSCALE_ANIM_START | OAM_FLAG_SPRITES;
    o->priority_on_layer = subpriority;
    o->final_oam = *template->oam;
    o->animation_table = template->animation;
    o->rotscale_table = template->rotscale;
    o->oam_template = template;
    o->callback = template->callback;
    o->x = x;
    o->y = y;
    oam_calculate_center_coordinates(o, (u8)(o->final_oam.attr0 >> 14), (u8)(o->final_oam.attr1 >> 14), (u8)((o->final_oam.attr0 >> 8) & 3));
    if (template->tiles_tag == 0xFFFF) {
        int base_tile;
        o->gfx_table = template->graphics;
        base_tile = oam_vram_alloc((u8)(o->gfx_table->size / GRAPHIC_SIZE_4BPP(8, 8))); // idk why we cast to u8, but i want to be consistent with the original func
        if (base_tile == 0xFFFF) {
            oam_clear(o);
            return NUM_OAMS;
        }
        o->final_oam.attr2 = (u16)((o->final_oam.attr2 & ~0x3FF) | base_tile);
        o->flags &= (u16)(~OAM_FLAG_SPRITES);
        o->base_tile = 0;
    } else {
        o->base_tile = oam_vram_get_tile(template->tiles_tag);
        oam_update_base_tile_by_gfx_animation(o);
    }
    if (o->final_oam.attr0 & ATTR0_ROTSCALE) {
        oam_rotscale_animation_initialize(o);
    }
    if (template->pal_tag != 0xFFFF) {
        o->final_oam.attr2 = (u16)((o->final_oam.attr2 & ~0xF000) | (oam_palette_get_index(template->pal_tag) << 12));
    }
    oam_order_compressed_add_idx(idx);
    o->flags |= OAM_FLAG_ACTIVE;
    return idx;
}
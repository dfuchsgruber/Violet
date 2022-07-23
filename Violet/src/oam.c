#include "types.h"
#include "oam.h"
#include "debug.h"
#include "superstate.h"
#include "save.h"
#include "agbmemory.h"
#include "dma.h"

#define DEBUG_OAMS 0
#define BENCHMARK 0

#if DEBUG_OAMS
    #define OAM_DEBUG(...) DEBUG (__VA_ARGS__)
#else
    #define OAM_DEBUG(...) 
#endif

#if BENCHMARK
    #define BENCHMARK_WRAP(x) x
#else
    #define BENCHMARK_WRAP(x) ;
#endif

extern u32 oam_priorities_iram[NUM_OAMS];

// Functions that (by my design) should not be called externally
u8 oam_new_at(u8 idx, oam_template *template, s16 x, s16 y, u8 subpriority);

static inline void oam_allocation_remove(oam_alloc_list_element_t *list, u8 idx) {
    u8 prev = list[idx].previous;
    u8 next = list[idx].next;
    list[prev].next = next;
    list[next].previous = prev;
}

static inline void oam_allocation_insert_after(oam_alloc_list_element_t *list, u8 idx, u8 idx_before) {
    u8 next = list[idx_before].next;
    list[idx_before].next = idx;
    list[next].previous = idx;
    list[idx].next = next;
    list[idx].previous = idx_before;
}

void oam_print_allocation_list() {
    oam_alloc_list_element_t *list = fmem.oam_allocation_list;
    OAM_DEBUG("Oam alloc list: ");
    u8 idx = OAM_ALLOC_FREE_START;
    while (true) {
        OAM_DEBUG(" %d", idx);
        if (idx == OAM_ALLOC_ACTIVE_END) break;
        idx = list[idx].next;
    }
    OAM_DEBUG("\n");
}

u8 oam_allocate(u8 where) {
    oam_alloc_list_element_t *list = fmem.oam_allocation_list;
    u8 idx = list[OAM_ALLOC_FREE_START].next;
    if (idx != OAM_ALLOC_ACTIVE_START) {
        oam_allocation_remove(list, idx);
        switch (where) {
            default:
            case OAM_ALLOCATE_AT_START:
                oam_allocation_insert_after(list, idx, list[OAM_ALLOC_ACTIVE_MIDDLE].previous);
                oam_active_cnt++;
                break;
            case OAM_ALLOCATE_AT_END:
                oam_allocation_insert_after(list, idx, OAM_ALLOC_ACTIVE_MIDDLE);
                oam_active_cnt++;
                break;
        }
        fmem.oam_groups[idx].next = NUM_OAMS;
        fmem.oam_groups[idx].previous = NUM_OAMS;
        OAM_DEBUG("allocated %d, where: %d\n", idx, where);
        return idx;
    } else {
        OAM_DEBUG("couldnt allocate\n", idx);
        return NUM_OAMS; // no free slots
    }
}

void oam_add_to_group(u8 oam_idx, u8 group_head) {
    oams[oam_idx].flags |= OAM_FLAG_IN_GROUP;
    while (fmem.oam_groups[group_head].next < NUM_OAMS)
        group_head = fmem.oam_groups[group_head].next;
    fmem.oam_groups[group_head].next = oam_idx;
    fmem.oam_groups[oam_idx].previous = group_head;
    fmem.oam_groups[oam_idx].next = NUM_OAMS;
}

void oam_allocation_initialize() {
    oam_alloc_list_element_t *list = fmem.oam_allocation_list;
    for (int i = 0; i < NUM_OAMS; i++) {
        list[i].previous = (u8)(i - 1);
        list[i].next = (u8)(i + 1);
    }
    list[0].previous = OAM_ALLOC_FREE_START;
    list[NUM_OAMS - 1].next = OAM_ALLOC_ACTIVE_START;
    list[OAM_ALLOC_FREE_START].previous = 0xFF;
    list[OAM_ALLOC_FREE_START].next = 0;
    list[OAM_ALLOC_ACTIVE_START].previous = NUM_OAMS - 1;
    list[OAM_ALLOC_ACTIVE_START].next = OAM_ALLOC_ACTIVE_MIDDLE;
    list[OAM_ALLOC_ACTIVE_MIDDLE].previous = OAM_ALLOC_ACTIVE_START;
    list[OAM_ALLOC_ACTIVE_MIDDLE].next = OAM_ALLOC_ACTIVE_END;
    list[OAM_ALLOC_ACTIVE_END].previous = OAM_ALLOC_ACTIVE_START;
    list[OAM_ALLOC_ACTIVE_END].next = 0xFF;
    oam_active_cnt = 0;
}

static inline void oam_update_position(oam_object *o) {
    // Update position
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

static inline bool oam_should_sort(int oam_idx) {
    u16 flags = oams[oam_idx].flags;
    if (flags & OAM_FLAG_IN_GROUP)
        return false;
    // Check if the oam is a group head
    if (fmem.oam_groups[oam_idx].next < NUM_OAMS && fmem.oam_groups[oam_idx].previous >= NUM_OAMS)
        return true;
    else
        return !(flags & OAM_FLAG_INVISIBLE);
}


#define SWAP(i, j) \
    oams_to_sort_t tmp = fmem.oams_to_sort[i]; \
    fmem.oams_to_sort[i] = fmem.oams_to_sort[j]; \
    fmem.oams_to_sort[j] = tmp; 

// Compresses the oam_order to [0...i, i+1...n_active-1], where all >= i+1 are active, but invisible and need not to be rendered
static inline size_t oam_compress_and_calculate_visible_cnt() {
    // s16 *ys = fmem.oam_ys;
    int tail = oam_active_cnt - 1;
    int i;
    for(i = 0; i <= tail; i++) {
        // DEBUG("Should sort %d: %d\n", fmem.oams_to_sort[i], oam_should_sort(i));
        oam_object *o = oams + fmem.oams_to_sort[i].oam_idx;
        if (!(o->flags & OAM_FLAG_INVISIBLE))
            oam_update_position(o);
    }
    i = 0;
    while(i <= tail) {
        // Search the last element to sort
        while (tail >= 0 && !oam_should_sort(fmem.oams_to_sort[tail].oam_idx)) { //   (oams[fmem.oams_to_sort[tail]].flags & (OAM_FLAG_INVISIBLE | OAM_FLAG_IN_GROUP))) {
            tail--;
        }
        // Tail now points the last element to sort
        if (i > tail) 
            break; // whole range [i...NUM_OAMS] is not to sort, done
        else if  (!oam_should_sort(fmem.oams_to_sort[i].oam_idx)) { //((oams[fmem.oams_to_sort[i]].flags & (OAM_FLAG_INVISIBLE | OAM_FLAG_IN_GROUP))) {
            // i is an oam not to sort, swap with tail and continue
            SWAP(tail, i);
        }

        u8 oam_idx = fmem.oams_to_sort[i].oam_idx;
        oam_object *o = oams + oam_idx;

        // Get y-coordinate
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
        u32 bg_priority;
        switch (o->sprite_mode) {
            case SUBSPRITES_OFF:
            case SUBSPRITES_ON_AND_IGNORE_PRIORITY:
            default:
                bg_priority = ((o->final_oam.attr2 >> 10) & 3);
                break;
            case SUBSPRITES_ON:
                // DEBUG("Obj 0x%x with sprite_idx %d, subsprite idx %d\n", o, o->sprite_idx, fmem.oams_to_sort[i].subsprite_idx);
                bg_priority = o->subsprites[o->sprite_idx].subsprites[fmem.oams_to_sort[i].subsprite_idx].priority;
                break;
        }

        // Calculate priority
        oam_priorities_iram[i] = (u32)(
            (u32)(o->priority_on_layer << 16) | 
            (bg_priority << 24) |
            (u32)(0x8000 - y)
        );
        i++; // either i was active to begin with or it was swapped with tail, which was active by definition
    }
    oam_visible_cnt = (u8)i;
    return oam_visible_cnt;
}

static void oam_calculate_y() {
}

void oam_calculate_position() {
}

void oam_calculate_priority() {
}

void oam_sort() {
    int n = oam_visible_cnt;
    u8 oam_radix_sort_buffer[2][NUM_OAMS]; // nom, nom, juicy stack memory :)
    u8 buckets[16]; // 4-bit buckets
    // Initialize the oam_radix_sort_buffer
    for (int i = 0; i < n; i++)
        oam_radix_sort_buffer[0][i] = (u8)i;
    int toggle = 0; // alternate between the two arrays in `oam_radix_sort_buffer` to realize radix sort
    if (n > 1) {
        for (int round = 0; round < 7; round++) {
            // Calculate bucket sizes
            for (int i = 0; i < 16; i++)
                buckets[i] = 0;
            for (int i = 0; i < n; i++) {
                u32 priority = oam_priorities_iram[oam_radix_sort_buffer[toggle][i]];
                u32 bucket_idx = (priority >> (round << 2)) & 0xF;
                buckets[bucket_idx]++;
            }
            // Calculate bucket offsets in the second array
            buckets[15] = (u8)(n - buckets[15]);
            for (int i = 14; i >= 0; i--) {
                buckets[i] = (u8)(buckets[i + 1] - buckets[i]);
            }
            // Collect elements
            for (int i = 0; i < n; i++) {
                u32 priority = oam_priorities_iram[oam_radix_sort_buffer[toggle][i]];
                u32 bucket_idx = (priority >> (round << 2)) & 0xF;
                oam_radix_sort_buffer[toggle ^ 1][buckets[bucket_idx]++] = oam_radix_sort_buffer[toggle][i];
            }
            toggle ^= 1; // switch source and destination arrays
        }
    }
    for (int i = 0; i < n; i++)
        fmem.oam_order_sorted[i] = oam_radix_sort_buffer[toggle][i];
}

static sprite oam_empty = {
    .attr0 = 160 | ATTR0_SHAPE_SQUARE, .attr1 = 304 | ATTR1_SIZE_8_8, .attr2 = ATTR2_PRIO(3),
};

static void oam_add_to_buffer(oam_object *o, u8 subsprite_idx, sprite *dst) {
    if (o->sprite_mode != SUBSPRITES_OFF) {;
        subsprite_table *subsprites_table = o->subsprites + o->sprite_idx;
        if (!subsprites_table || !(subsprites_table->subsprites) || subsprite_idx >= subsprites_table->num_subsprites)
            return;
        int tile_num = o->final_oam.attr2 & 0x3FF;
        int x = o->final_oam.attr1 & 0x1FF;
        int y = o->final_oam.attr0 & 0xFF;
        x -= o->x_centre;
        y -= o->y_centre;

        subsprite *subsprite = subsprites_table->subsprites + subsprite_idx;

        int dx = subsprite->x;
        int dy = subsprite->y;

        if (o->final_oam.attr1 & ATTR1_HFLIP) {
            dx += oam_sizes[subsprite->shape][subsprite->size].width;
            dx = ~dx + 1;
        }
        if (o->final_oam.attr1 & ATTR1_VFLIP) {
            dy += oam_sizes[subsprite->shape][subsprite->size].height;
            dy = ~dy + 1;
        }
        *dst = o->final_oam;
        (void) tile_num;
        dst->attr0 = (u16)((dst->attr0 & (~ATTR0_SHAPE_MASK)) | (subsprite->shape << 14));
        dst->attr1 = (u16)((dst->attr1 & (~ATTR1_SIZE_MASK)) | (subsprite->size << 14));
        dst->attr2 = (u16)((dst->attr2 & (~0x3FF)) | (((tile_num + subsprite->tile_offset) & 0x3FF) << 0));
        dst->attr0 = (u16)((dst->attr0 & (~0xFF)) | (((y + dy) & 0xFF) << 0));
        dst->attr1 = (u16)((dst->attr1 & (~0x1FF)) | (((x + dx) & 0x1FF) << 0));
        if (o->sprite_mode != SUBSPRITES_ON_AND_IGNORE_PRIORITY)
            dst->attr2 = (u16)((dst->attr2 & (~ATTR2_PRIO_MASK)) | ATTR2_PRIO(subsprite->priority));
    } else {
        *dst = o->final_oam;
    }
}

void oam_copy_to_oam_buffer() {
    u8 cnt = 0;
    int vis_cnt = oam_visible_cnt;
    // u32 t_total = 0;
    // u8 iters = 0;
    for (int i = 0; i < vis_cnt; i++) {
        u8 current = fmem.oams_to_sort[fmem.oam_order_sorted[i]].oam_idx;
        u8 subsprite_idx_current = fmem.oams_to_sort[fmem.oam_order_sorted[i]].subsprite_idx;
        while (current < NUM_OAMS && cnt < ARRAY_COUNT(super.oam_attributes)) {
            // u32 t = 0;
            if (!(oams[current].flags & OAM_FLAG_INVISIBLE)) {
                oam_add_to_buffer(oams + current, subsprite_idx_current, &super.oam_attributes[cnt++]);
                // DEBUG("Added oam with priority %d at iram order %d\n", (oams[current].final_oam.attr2 >> 10) & 3, i);
            }
            // if (t > 1000)
            //     DEBUG("    Copying of %d (iter %d) took %d, has subsprites %d\n", current, iters, t, oams[current].sprite_mode);
            // DEBUG("   Copied %d (group %d)\n", current, fmem.oams_to_sort[i]);
            // t_total += t;
            // iters++;
            if (subsprite_idx_current == 0)
                current = fmem.oam_groups[current].next;
            else
                break; // Do not add all group oams for the children of a subsprite
        }
    }
    // DEBUG("Copied took %d (%d iters)\n", t_total, iters);
    // OAM_DEBUG("Oam buffer %d / %d full\n", cnt, oam_buffer_size);
    while(cnt < oam_buffer_size) {
        super.oam_attributes[cnt++] = oam_empty;
    }
}

void oam_proceed() {
    #if DEBUG_OAMS
        // oam_print_allocation_list();
    #endif

    BENCHMARK_WRAP(benchmark_start();)
    oam_compress_and_calculate_visible_cnt(); // compresses the oam_order such that the first indices are the ones to render
    BENCHMARK_WRAP(u32 t_compress = benchmark_end();)

    // OAM_DEBUG("Visible %d\n", oam_visible_cnt);
    BENCHMARK_WRAP(benchmark_start();)
    oam_calculate_position();
    BENCHMARK_WRAP(u32 t_pos = benchmark_end();)

    BENCHMARK_WRAP(benchmark_start();)
    oam_calculate_priority();
    BENCHMARK_WRAP(u32 t_prio = benchmark_end();)

    BENCHMARK_WRAP(benchmark_start();)
    oam_calculate_y();
    BENCHMARK_WRAP(u32 t_y = benchmark_end();)

    BENCHMARK_WRAP(benchmark_start();)
    oam_sort();

    u8 tmp = super.disable_oams;
    super.disable_oams = true;
    BENCHMARK_WRAP(u32 t_sort = benchmark_end();)
    

    BENCHMARK_WRAP(benchmark_start();)
    oam_copy_to_oam_buffer();
    BENCHMARK_WRAP(u32 t_copy = benchmark_end();)

    // Debug

    BENCHMARK_WRAP(benchmark_start();)
    oam_copy_rotscale_to_buffer();
    super.disable_oams = (u8)(tmp & 1);
    oam_copy_requests_enabled = true;
    BENCHMARK_WRAP(u32 t_affine = benchmark_end();)

    BENCHMARK_WRAP(DEBUG("\tOam sum %d, Vis %d, compr %d, pos %d, prio %d, sort %d, cpy %d, rs %d, y %d\n", 
    t_compress + t_pos + t_prio +  t_y + t_sort + t_copy + t_affine,
    oam_visible_cnt, t_compress, t_pos, t_prio, t_sort, t_copy, t_affine, t_y);)
}

void oam_clear(oam_object *o); // Declare it here so no other file can use it. This should only be called internally

void oam_clear_all() {
    u8 i;
    oam_active_cnt = 0;
    for (i = 0; i < NUM_OAMS; i++) {
        oam_clear(oams + i);
        fmem.oams_to_sort[i].oam_idx = i;
        fmem.oams_to_sort[i].subsprite_idx = 0;
    }
    oam_clear(oams + i);
    oam_allocation_initialize();
}

u8 oam_new_forward_search(oam_template *template, s16 x, s16 y, u8 priority_on_layer) {
    u8 idx = oam_allocate(OAM_ALLOCATE_AT_START);
    if (idx != NUM_OAMS) {
        return oam_new_at(idx, template, x, y, priority_on_layer);
    } else {
        return NUM_OAMS;
    }
}

u8 oam_new_backward_search(oam_template *template, s16 x, s16 y, u8 priority_on_layer) {
    u8 idx = oam_allocate(OAM_ALLOCATE_AT_END);
    if (idx != NUM_OAMS) {
        return oam_new_at(idx, template, x, y, priority_on_layer);
    } else {
        return NUM_OAMS;
    }
}

u8 oam_new_forward_search_and_animation(oam_template *template, s16 x, s16 y, u8 priority_on_layer) {
    u8 idx = oam_new_forward_search(template, x, y, priority_on_layer);
    if (idx != NUM_OAMS) {
        oams[idx].callback(oams + idx);
        if (oams[idx].flags & OAM_FLAG_ACTIVE) {
            oam_animation_proceed(oams + idx);
        }
    }
    return idx;
}

u8 oam_copy_forward_search(oam_object *src, s16 x, s16 y, u8 priority_on_layer) {
    u8 idx = oam_allocate(OAM_ALLOCATE_AT_START);
    if (idx != NUM_OAMS) {
        oams[idx] = *src;
        oams[idx].x = x;
        oams[idx].y = y;
        oams[idx].priority_on_layer = priority_on_layer;
    }
    return idx;
}

u8 oam_copy_backward_search(oam_object *src, s16 x, s16 y, u8 priority_on_layer) {
    u8 idx = oam_allocate(OAM_ALLOCATE_AT_END);
    if (idx != NUM_OAMS) {
        oams[idx] = *src;
        oams[idx].x = x;
        oams[idx].y = y;
        oams[idx].priority_on_layer = priority_on_layer;
    }
    return idx;
}

void oam_copy_requests_proceed() {
    if (oam_copy_requests_enabled) {
        u8 i = 0;
        while (oam_copy_requests_cnt > 0) {
            DMA_COPY_32(3, oam_copy_requests[i].src, oam_copy_requests[i].dst, oam_copy_requests[i].size);
            oam_copy_requests_cnt--;
            i++;
        }
        oam_copy_requests_enabled = false;
    }
}

void oam_animations_proceed() {
    oam_alloc_list_element_t *list = fmem.oam_allocation_list;
    // Also performs gargabe collection and builds the oam order
    // oam_print_allocation_list();

    u8 current = list[OAM_ALLOC_ACTIVE_START].next;
    while (current != OAM_ALLOC_ACTIVE_END) {
        u8 next = list[current].next;
        if (current != OAM_ALLOC_ACTIVE_MIDDLE) {
            oam_object *current_object = oams + current;
            if (current_object->flags & OAM_FLAG_ACTIVE) {
                current_object->callback(current_object);
                if (current_object->flags & OAM_FLAG_ACTIVE) {
                    oam_animation_proceed(current_object);
                }
            }
            if (!(current_object->flags & OAM_FLAG_ACTIVE)) {
                // Remove from active list
                u8 prev = list[current].previous;
                list[prev].next = next;
                list[next].previous = prev;

                // Insert into free list
                u8 free_start = list[OAM_ALLOC_FREE_START].next;
                list[OAM_ALLOC_FREE_START].next = current;
                list[current].previous = OAM_ALLOC_FREE_START;
                list[current].next = free_start;
                list[free_start].previous = current;

                u8 group_prev = fmem.oam_groups[current].previous;
                u8 group_next = fmem.oam_groups[current].next;
                if (group_prev < NUM_OAMS) {
                    fmem.oam_groups[group_prev].next = group_next;
                } else {
                    // Element was group head, make next element group head
                    if (group_next < NUM_OAMS) {
                        oams[group_next].flags &= (u16)(~OAM_FLAG_IN_GROUP);
                    }
                }
                if (group_next < NUM_OAMS) {
                    fmem.oam_groups[group_next].previous = group_prev;
                }
                // oam_allocation_remove(list, current);
                // oam_allocation_insert_after(list, current, OAM_ALLOC_FREE_START);
                OAM_DEBUG("Garbage collection on %d\n", current);
            }
        }
        current = next;
    }
    // Build buffer to compress and sort
    oam_active_cnt = 0;
    for (current = list[OAM_ALLOC_ACTIVE_START].next; current != OAM_ALLOC_ACTIVE_END; current = list[current].next) {
        if (current == OAM_ALLOC_ACTIVE_MIDDLE)
            continue;
        if (oams[current].flags & OAM_FLAG_ACTIVE) {
            fmem.oams_to_sort[oam_active_cnt].oam_idx = current;
            fmem.oams_to_sort[oam_active_cnt].subsprite_idx = 0;
            oam_active_cnt++;
            if (oams[current].sprite_mode) {
                subsprite_table *table = oams[current].subsprites + oams[current].sprite_idx;
                if (table && table->subsprites) {
                    // Add all subsprites, they need to be sorted as well
                    for (u8 i = 1; i < table->num_subsprites; i++) {
                        fmem.oams_to_sort[oam_active_cnt].oam_idx = current;
                        fmem.oams_to_sort[oam_active_cnt].subsprite_idx = i;
                        oam_active_cnt++;
                    }
                }
            }
        }
    }

    #if DEBUG_OAMS
        u8 cnt_free = 0; u8 cnt_active = 0;
        current = list[OAM_ALLOC_FREE_START].next;
        while (current != OAM_ALLOC_ACTIVE_START) {
            if (oams[current].flags & OAM_FLAG_ACTIVE) {
                OAM_DEBUG("Error: Oam %d is in inactive list, but is active! (build from %x), callback %x\n", current, 
                    oams[current].oam_template, oams[current].callback);
            }
            current = list[current].next;
            cnt_free++;
        }
        current = list[OAM_ALLOC_ACTIVE_START].next;
        while (current != OAM_ALLOC_ACTIVE_END) {
            cnt_active++;
            current = list[current].next;
        }
        // OAM_DEBUG("List active %d, list free %d\n", cnt_active, cnt_free);
    #endif
}

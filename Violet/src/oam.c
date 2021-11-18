#include "types.h"
#include "oam.h"
#include "debug.h"
#include "superstate.h"
#include "save.h"
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

extern u8 oam_order_iram[NUM_OAMS];
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
        OAM_DEBUG("allocated %d, where: %d\n", idx, where);
        return idx;
    } else {
        OAM_DEBUG("couldnt allocate\n", idx);
        return NUM_OAMS; // no free slots
    }
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

// Compresses the oam_order to [0...i, i+1...n_active-1], where all >= i+1 are active, but invisible and need not to be rendered
static inline size_t oam_compress_and_calculate_visible_cnt() {
    // s16 *ys = fmem.oam_ys;
    int tail = oam_active_cnt - 1;
    int i = 0;
    while(i <= tail) {
        // Search the last non-invisible element
        while (tail >= 0 && (oams[oam_order_iram[tail]].flags & (OAM_FLAG_INVISIBLE)))
            tail--;
        // Tail now points the last non-invisible element
        if (i > tail) 
            break; // whole range [i...NUM_OAMS] is invisible, done
        else if ((oams[oam_order_iram[i]].flags & (OAM_FLAG_INVISIBLE))) {
            // i is an invisible oam, swap with tail and continue
            u8 tmp = oam_order_iram[tail];
            oam_order_iram[tail] = oam_order_iram[i]; // i is now a visible oam
            oam_order_iram[i] = tmp;
        }

        u8 oam_idx = oam_order_iram[i];
        oam_object *o = oams + oam_idx;

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

        // Update y-coordinate
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

        // Calculate priority
        oam_priorities_iram[oam_idx] = (u32)(
            (o->priority_on_layer << 16) | 
            (((o->final_oam.attr2 >> 10) & 3) << 24) |
            (0x8000 - y)
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

#define SWAP(i, j) \
    u8 tmp = oam_order_iram[i]; \
    oam_order_iram[i] = oam_order_iram[j]; \
    oam_order_iram[j] = tmp;

static inline void oam_insertion_sort(u32 from, u32 to) {
    return;
    // DEBUG("Insertion sort on %d from %d to %d\n", to-from, from, to);
    u8 current;
    u32 j;
    for (u32 i = from; i < to; i++) {
        current = oam_order_iram[i];
        j = i;
        while(j > from && oam_priorities_iram[oam_order_iram[j - 1]] > oam_priorities_iram[current]) {
            u8 tmp = oam_order_iram[j];
            oam_order_iram[j] = oam_order_iram[j - 1];
            oam_order_iram[j - 1] = tmp;
            j--;
        }
        oam_order_iram[j] = current;
    }  
}

static inline void heapsort_sift_down(int idx, u8 *arr, int size) {
    while (idx < size) {
        int largest = idx;
        int left = (idx << 1) + 1;
        int right = (idx << 1) + 2;
        if (left < size && oam_priorities_iram[arr[largest]] < oam_priorities_iram[arr[left]])
            largest = left;
        if (right < size && oam_priorities_iram[arr[largest]] < oam_priorities_iram[arr[right]])
            largest = right;
        if (largest != idx) {
            u8 tmp = arr[largest];
            arr[largest] = arr[idx];
            arr[idx] = tmp;
            idx = largest;
        } else {
            return;
        }
    }
}

static inline void oam_heapsort(u32 from, u32 to) {
    int size = (int)(to - from);
    if (size == 0)
        return;
    // 1. Build a max-heap
    u8 *heap = oam_order_iram + from;
    for (int i = (size >> 1) - 1; i >= 0; i--) {
        heapsort_sift_down(i, heap, size);
    }
    // 2. Run heapsort, successively remove elements from the heap
    // DEBUG("Heapsort removal order, size is \n");
    for (int i = size - 1; i >= 0; i--) {
        u8 tmp = heap[0];
        // DEBUG("%d ", oam_priorities_iram[tmp]);
        heap[0] = heap[i];
        heap[i] = tmp;
        heapsort_sift_down(0, heap, i);
    }
    // DEBUG("\n");
}

void oam_sort() {
    size_t n = oam_visible_cnt;
    if (n == 0)
        return;
    // First, perform radix sort on the bg-priority (0-3)
    u32 prio_1_start = 0, prio_3_start = n;
    u32 i = 0;
    while (i < prio_3_start) {
        if ((oam_priorities_iram[oam_order_iram[i]] >> 24) == 0) {
            // Place all with bg prio 0 at the beginning (before prio_1_start)
            SWAP(i, prio_1_start);
            prio_1_start++;
            i++;
        } else if ((oam_priorities_iram[oam_order_iram[i]] >> 24) == 3) {
            // Place all with bg prio 3 at the end (after prio_3_start)
            prio_3_start--;
            SWAP(i, prio_3_start);
        } else {
            i++; // Ignore bg priorities 1 and 2 for now
        }
    }
    // Sort the bg priotities 1 und 2 between prio_1 start and prio_3_start
    i = prio_1_start;
    u32 prio_2_start = i;
    while (i < prio_3_start) {
        if ((oam_priorities_iram[oam_order_iram[i]] >> 24) == 1) {
            SWAP(i, prio_2_start);
            prio_2_start++;
        }
        i++;
    }
    // For each bucket, sort either with insertion sort for small arrays or heapsort for large arrays
    if (prio_1_start > 10)
        oam_heapsort(0, prio_1_start);
    else
        oam_insertion_sort(0, prio_1_start);
    if (prio_2_start - prio_1_start > 10)
        oam_heapsort(prio_1_start, prio_2_start);
    else
        oam_insertion_sort(0, prio_1_start);
    if (prio_3_start - prio_2_start > 10)
        oam_heapsort(prio_2_start, prio_3_start);
    else
        oam_insertion_sort(prio_2_start, prio_3_start);
    if (n - prio_3_start > 10)
        oam_heapsort(prio_3_start, n);
    else
        oam_insertion_sort(prio_3_start, n);
}

static sprite oam_empty = {
    .attr0 = 160 | ATTR0_SHAPE_SQUARE, .attr1 = 304 | ATTR1_SIZE_8_8, .attr2 = ATTR2_PRIO(3),
};

void oam_copy_to_oam_buffer() {
    u8 cnt = 0;
    int vis_cnt = oam_visible_cnt;
    for (int i = 0; i < vis_cnt; i++) {
        if (oam_add_to_buffer(oams + oam_order_iram[i], &cnt))
            return;
    }
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

    BENCHMARK_WRAP(benchmark_start();)
    oam_copy_rotscale_to_buffer();
    super.disable_oams = (u8)(tmp & 1);
    oam_copy_requests_enabled = true;
    BENCHMARK_WRAP(u32 t_affine = benchmark_end();)

    BENCHMARK_WRAP(DEBUG("\tOam sum %d, Vis %d, compr %d, pos %d, prio %d, sort %d, cpy %d, rs %d, y %d\n", 
    t_compress + t_pos + t_prio +  t_y + t_sort + t_copy + t_affine,
    
    oam_visible_cnt, t_compress, t_pos, t_prio, t_sort, t_copy, t_affine, t_y);)
}

void oam_clear(oam_object *o); // Declare it here so no other file is tempted to use it. This should only be called internally

void oam_clear_all() {
    u8 i;
    oam_active_cnt = 0;
    for (i = 0; i < NUM_OAMS; i++) {
        oam_clear(oams + i);
        oam_order_iram[i] = i;
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
    oam_active_cnt = 0;
    while (current != OAM_ALLOC_ACTIVE_END) {
        u8 next = list[current].next;
        if (current != OAM_ALLOC_ACTIVE_MIDDLE) {
            oam_object *current_object = oams + current;
            if (current_object->flags & OAM_FLAG_ACTIVE) {
                current_object->callback(current_object);
                if (current_object->flags & OAM_FLAG_ACTIVE) {
                    oam_animation_proceed(current_object);
                }
                // OAM_DEBUG("Animated sprite %d with callback %x andd template %x\n", current, current_object->callback, current_object->oam_template);
            }
            if (current_object->flags & OAM_FLAG_ACTIVE) {
                oam_order_iram[oam_active_cnt++] = current;
            } else {
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



                // oam_allocation_remove(list, current);
                // oam_allocation_insert_after(list, current, OAM_ALLOC_FREE_START);
                OAM_DEBUG("Garbage collection on %d\n", current);
            }
        }
        current = next;
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
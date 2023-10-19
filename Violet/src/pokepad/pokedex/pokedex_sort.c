#include "types.h"
#include "stdbool.h"
#include "pokepad/pokedex/gui.h"
#include "oam.h"
#include "callbacks.h"
#include "save.h"
#include "bg.h"
#include "text.h"
#include "mega.h"
#include "pokemon/basestat.h"
#include "pokemon/names.h"
#include "color.h"
#include "superstate.h"
#include "transparency.h"
#include "music.h"
#include "agbmemory.h"
#include "io.h"
#include "pokepad/pokedex/state.h"

static inline void pokedex_quicksort_list_swap(int a, int b) {
    pokedex_list_element *list = pokedex_state->list;
    pokedex_list_element tmp;
    memcpy(&tmp, &list[a], sizeof (pokedex_list_element));
    memcpy(&list[a], &list[b], sizeof (pokedex_list_element));
    memcpy(&list[b], &tmp, sizeof (pokedex_list_element));
}

static inline int pokedex_quicksort_list_compare(u8 comparator, int a, int b) {
    pokedex_list_element *list = pokedex_state->list;
    int reverse = comparator > 3 ? -1 : 1;
    comparator &= 3;
    switch (comparator) {
        case POKEDEX_SORTING_NUMERIC : // by number
            return (list[a].dex_id - list[b].dex_id) * reverse;
            break;
        case POKEDEX_SORTING_ALPHABETIC: { // by name
            const u8 *name_a = pokemon_names[list[a].species];
            const u8 *name_b = pokemon_names[list[b].species];
            int i = 0;
            while (true) {
                if (name_a[i] - name_b[i])
                    return (name_a[i] - name_b[i]) * reverse;
                if (name_a[i] == 0xFF)

                    return 0;
                i++;
            }
            break;
        } 
        case POKEDEX_SORTING_SIZE: { // by height
            int dif = (pokedex_get_data(list[a].dex_id)->height - pokedex_get_data(list[b].dex_id)->height) * reverse;
            if (dif) return dif;
            return (list[a].dex_id - list[b].dex_id)*reverse;
        }
        case POKEDEX_SORTING_WEIGHT: {
            int dif = (pokedex_get_data(list[a].dex_id)->weight - pokedex_get_data(list[b].dex_id)->weight) * reverse;
            if (dif) return dif;
            return (list[a].dex_id - list[b].dex_id)*reverse;
        }
    }
    return a - b;
}

void pokedex_quicksort_list(u8 comparator, int l, int r) {
    // Iteratiive implementation of quicksort
    int *stack = (int*) malloc((u32) (r - l + 1) * sizeof (int));
    int top = -1;
    stack[++top] = l;
    stack[++top] = r;

    while (top >= 0) {
        r = stack[top--];
        l = stack[top--];
        if (l < r) {
            int i = l - 1;
            int j = r;
            do { //split array
                do {
                    i++;
                } while (pokedex_quicksort_list_compare(comparator, i, r) < 0);
                do {
                    j--;
                } while (j >= l && pokedex_quicksort_list_compare(comparator, j, r) > 0);
                if (i < j)
                    pokedex_quicksort_list_swap(i, j);
            } while (i < j);
            pokedex_quicksort_list_swap(i, r);
            stack[++top] = l;
            stack[++top] = i - 1;
            stack[++top] = i + 1;
            stack[++top] = r;
        }
    }
    // Find the index in the list of current species
    int i;
    for (i = 0; i < POKEDEX_CNT; i++) {
        if (csave.pokedex_species) {
            if (pokedex_state->list[i].species == csave.pokedex_species) {
                pokedex_state->current_list_index = (u16) i;
                break;
            }
        } else {
            if (pokedex_state->list[i].seen) {
                pokedex_state->current_list_index = (u16) i;
                break;
            }
        }
    }
    free(stack);
}

// The animation is realized like this:
// The list area is in Win1, which contains no layers
// The visible area is in Win0, which contains all layers, but this window shrinks
// The area outside the list area is in WinOut, which contains all layers
// Win1 wants to hide all layers, but Win0's rectangle superceeds this and shows a smaller rectangle

void pokedex_callback_resort(u8 self) {
    pokedex_sorting_state_t *state = (pokedex_sorting_state_t*)big_callbacks[self].params;
    switch (state->state) {
        case POKEDEX_SORTING_STATE_CLOSING:
            state->y0 = (u8)MIN((state->y0 + POKEDEX_LIST_DELTA_Y), (POKEDEX_LIST_Y0 + POKEDEX_LIST_Y1) / 2);
            state->y1 = (u8)MAX((state->y1 - POKEDEX_LIST_DELTA_Y), (POKEDEX_LIST_Y0 + POKEDEX_LIST_Y1) / 2);
            io_set(IO_WIN0V, (u16)IO_WINH(state->y0, state->y1));
            if (state->y1 <= state->y0)
                state->state++;
            break;
        case POKEDEX_SORTING_STATE_SORTING: {
            pokedex_quicksort_list(csave.pokedex_sorting, 0, POKEDEX_CNT - 1);
            pokedex_list_update_bounds();
            pokedex_update_list(pokedex_state->list_is_scrolling_down);
            state->state++;
            break;
        }
        case POKEDEX_SORTING_STATE_OPENING: {
            state->y0 = (u8)MAX((state->y0 - POKEDEX_LIST_DELTA_Y), POKEDEX_LIST_Y0);
            state->y1 = (u8)MIN((state->y1 + POKEDEX_LIST_DELTA_Y), POKEDEX_LIST_Y1);
            io_set(IO_WIN0V, (u16)IO_WINH(state->y0, state->y1));
            if (state->y0 <= POKEDEX_LIST_Y0 && state->y1 >= POKEDEX_LIST_Y1) {
                io_bic(IO_DISPCNT, IO_DISPCNT_WIN0 | IO_DISPCNT_WIN1);
                big_callbacks[self].function = state->continuation;
            }
            break;
        }
    }
}

void pokedex_resort_list(u8 self, void (*continuation)(u8)) {
    pokedex_sorting_state_t *state = (pokedex_sorting_state_t*)big_callbacks[self].params;
    state->state = POKEDEX_SORTING_STATE_CLOSING;
    io_set(IO_DISPCNT, (u16)(io_get(IO_DISPCNT) | IO_DISPCNT_WIN0 | IO_DISPCNT_WIN1));
            io_set(IO_WININ, IO_WININOUT_BG(0, 0) | IO_WININOUT_BG(0, 1) | IO_WININOUT_BG(0, 2) | 
                IO_WININOUT_BG(0, 3) | IO_WININOUT_OBJ(0) | IO_WININOUT_FX(0));
            io_set(IO_WINOUT, IO_WININOUT_BG(0, 0) | IO_WININOUT_BG(0, 1) | IO_WININOUT_BG(0, 2) | 
                IO_WININOUT_BG(0, 3) | IO_WININOUT_OBJ(0) | IO_WININOUT_FX(0));
            state->y0 = POKEDEX_LIST_Y0;
            state->y1 = POKEDEX_LIST_Y1;
            io_set(IO_WIN0H, IO_WINH(POKEDEX_LIST_X0, POKEDEX_LIST_X1));
            io_set(IO_WIN1H, IO_WINH(POKEDEX_LIST_X0, POKEDEX_LIST_X1));
            io_set(IO_WIN1V, IO_WINH(POKEDEX_LIST_Y0, POKEDEX_LIST_Y1));
    state->continuation = continuation;
    big_callbacks[self].function = pokedex_callback_resort;
}
#include "types.h"
#include "stdbool.h"
#include "romfuncs.h"
#include "pokepad.h"
#include "pokedex.h"
#include "oams.h"
#include "callbacks.h"
#include "save.h"
#include "utils.h"
#include "bg.h"
#include "gfx.h"
#include "text.h"
#include "mega.h"
#include "pokemon.h"
#include "basestats.h"
#include "color.h"
#include "superstate.h"
#include "utils.h"
#include "transparency.h"

void pokedex_sort_locate_cursor() {
    ;
    oams[fmem->dex_mem->oam_sort_cursor].x2 = (s16) (fmem->dex_mem->sort_cursor_pos * 32);
}

void pokedex_big_callback_resort(u8 self) {
    switch (big_callbacks[self].params[0]) {
        case 0:
        { //init resort (win1 feature)
            sound(6);
            u16 dispcnt = get_io(0) | 0x4000;
            set_io(0, dispcnt);
            set_io(0x48, 0x81F); //everything is in window 0 but nothing is in window 1
            set_io(0x42, 0x40F0); //leftmost = 64, rightmost = 240
            set_io(0x46, 0xa0A0); //topmost = 33, bottommost = 160
            big_callbacks[self].params[0] = 1;
            big_callbacks[self].params[1] = 160;
            //spawn_big_callback(pokedex_big_callback_quicksort_parallel, 0);
            break;
        }
        case 1:
        {
            //move window upwards
            if (big_callbacks[self].params[1] <= 33) {
                big_callbacks[self].params[1] = 33;
                big_callbacks[self].params[0] = 2;
            } else {
                big_callbacks[self].params[1] = (u16) (big_callbacks[self].params[1] - 8);
            }
            u16 topmost_new = (u16) (big_callbacks[self].params[1] << 8);
            set_io(0x46, topmost_new | 0xA0);
            break;
        }
        case 2:
        {
            //sound(4);
            //while(true){}
            if (fmem->dex_mem->reverse_req) {
                pokedex_quicksort_revert(0, POKEDEX_CNT);
            } else {
                pokedex_quicksort_list(fmem->dex_mem->current_comparator, 0, POKEDEX_CNT - 1);
            }
            pokedex_update_list();
            big_callbacks[self].params[0] = 3;
            sound(6);
            break;
        }
        case 3:
        {
            //move window downwards
            if (big_callbacks[self].params[1] >= 232) {

                u16 dispcnt = (u16) (get_io(0) & (~0x4000));
                set_io(0, dispcnt);
                fmem->dex_mem->resorting = false;
                remove_big_callback(self);
            } else {
                big_callbacks[self].params[1] = (u16) (big_callbacks[self].params[1] + 8);
            }
            u16 topmost_new = (u16) (big_callbacks[self].params[1] << 8);
            if (topmost_new > 0xA000) topmost_new = 0xA000;
            set_io(0x46, topmost_new | 0xA0);
            break;
        }

    }
    /*
    pokedex_quicksort_list(fmem->dex_mem->current_comparator, 0, POKEDEX_CNT-1);
    pokedex_update_list();
    fmem->dex_mem->resorting = false;
    remove_big_callback(self);
     */
}

void pokedex_callback_sort() {
    cb1handling();
    if (fmem->dex_mem->resorting)
        return;
    if (super->keys_new.keys.B) {
        //return to group selection
        oams[fmem->dex_mem->oam_sort_cursor].anim_number = 0;
        gfx_init_animation(&oams[fmem->dex_mem->oam_sort_cursor], 0);
        fmem->dex_mem->sort_cursor_pos = fmem->dex_mem->current_comparator & 3;
        pokedex_sort_locate_cursor();
        set_callback1(pokedex_callback_group_selection);
        sound(5);
        return;
    } else if (super->keys_new.keys.A) {
        //log new sorting
        u8 old_sorting = fmem->dex_mem->current_comparator & 3;
        u8 new_sorting = fmem->dex_mem->sort_cursor_pos;
        if (old_sorting == new_sorting) {
            fmem->dex_mem->current_comparator ^= 4;
            fmem->dex_mem->reverse_req = true;
        } else {
            fmem->dex_mem->current_comparator = new_sorting;
            fmem->dex_mem->reverse_req = false;
        }
        fmem->dex_mem->resorting = true;
        sound(5);
        big_callbacks[spawn_big_callback(pokedex_big_callback_resort, 0)].params[0] = 0;
    } else if (super->keys_new.keys.left && fmem->dex_mem->sort_cursor_pos > 0) {
        fmem->dex_mem->sort_cursor_pos--;
        pokedex_sort_locate_cursor();
        sound(5);
    } else if (super->keys_new.keys.right && fmem->dex_mem->sort_cursor_pos < 3) {
        fmem->dex_mem->sort_cursor_pos++;
        pokedex_sort_locate_cursor();
        sound(5);
    }

}

void pokedex_quicksort_list_swap(int a, int b) {
    pokedex_list_element *list = fmem->dex_mem->list;
    pokedex_list_element tmp;
    memcopy(&tmp, &list[a], sizeof (pokedex_list_element));
    memcopy(&list[a], &list[b], sizeof (pokedex_list_element));
    memcopy(&list[b], &tmp, sizeof (pokedex_list_element));
}

void pokedex_quicksort_revert(int from, int to) {
    do {
        pokedex_quicksort_list_swap(from++, --to);
    } while (to > from);
    fmem->dex_mem->current_list_index = (u16) (POKEDEX_CNT - 1 - fmem->dex_mem->current_list_index);
}

int pokedex_quicksort_list_compare(u8 comparator, int a, int b) {
    pokedex_list_element *list = fmem->dex_mem->list;
    int reverse = comparator > 3 ? -1 : 1;
    comparator &= 3;
    switch (comparator) {
        case 0://by number
            return (list[a].dex_id - list[b].dex_id) * reverse;
            break;
        case 1:
        {//by name
            u8 *name_a = pokemon_names[list[a].species];
            u8 *name_b = pokemon_names[list[b].species];
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
        case 2:
        {//by height
            int dif = (pokedex_get_data(list[a].dex_id)->height - pokedex_get_data(list[b].dex_id)->height) * reverse;
            if (dif) return dif;
            return (list[a].dex_id - list[b].dex_id)*reverse;
        }
        case 3:
        {
            int dif = (pokedex_get_data(list[a].dex_id)->weight - pokedex_get_data(list[b].dex_id)->weight) * reverse;
            if (dif) return dif;
            return (list[a].dex_id - list[b].dex_id)*reverse;
        }
    }
    return a - b;
}

void pokedex_quicksort_list(u8 comparator, int l, int r) {
    //we do an iteratiive implementation of quicksort
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
    //now we find the index in the list of current species
    int i;
    for (i = 0; i < POKEDEX_CNT; i++) {
        if (fmem->dex_mem->current_species) {
            if (fmem->dex_mem->list[i].species == fmem->dex_mem->current_species) {
                fmem->dex_mem->current_list_index = (u16) i;
                break;
            }
        } else {
            if (fmem->dex_mem->list[i].seen) {
                fmem->dex_mem->current_list_index = (u16) i;
                break;
            }
        }
    }

    free(stack);
}
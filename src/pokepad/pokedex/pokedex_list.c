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

bool pokedex_callback_list_mode_proceed() {
    switch (fmem->dex_mem->list_mode) {
        case 1:
            if (super->keys.keys.down) {
                if (super->keys_new_rst.keys.down)
                    fmem->dex_mem->list_fast_mode = true;
                return true;
            }
            break;
        case 2:
            if (super->keys.keys.up) {
                if (super->keys_new_rst.keys.up)
                    fmem->dex_mem->list_fast_mode = true;
                return true;
            }
            break;
        case 3:
            if (super->keys.keys.right) {
                if (super->keys_new_rst.keys.right)
                    fmem->dex_mem->list_fast_mode = true;
                return true;
            }
            break;
        case 4:
            if (super->keys.keys.left) {
                if (super->keys_new_rst.keys.left)
                    fmem->dex_mem->list_fast_mode = true;
                return true;
            }
            break;
    }
    return false;
}

void pokedex_callback_list_enter_mode(u8 mode) {
    if (mode == 1 || mode == 3) {
        fmem->dex_mem->cursor_anchor = true;
    } else if (mode == 2 || mode == 4) {
        fmem->dex_mem->cursor_anchor = false;
    }
    fmem->dex_mem->list_mode = mode;
    fmem->dex_mem->list_fast_mode = false;
}

void pokedex_callback_list() {
    cb1handling();

    if (super->keys_new.keys.down) {
        pokedex_callback_list_enter_mode(1);
    } else if (super->keys_new.keys.up) {
        pokedex_callback_list_enter_mode(2);
    } else if (super->keys_new.keys.right) {
        pokedex_callback_list_enter_mode(3);
    } else if (super->keys_new.keys.left) {
        pokedex_callback_list_enter_mode(4);
    } else if (super->keys_new.keys.A) {
        //Todo enter page
        if (fmem->dex_mem->list[fmem->dex_mem->current_list_index].seen) {
            sound(5);
            set_callback1(pokedex_callback_init_entry);
            init_fadescreen(1, 0);
            return;
        }
    } else if (super->keys_new.keys.B) {
        //Todo return to group selection
        fmem->dex_mem->in_list = false;
        set_callback1(pokedex_callback_group_selection);
        sound(5);
        return;
    }
    //No new key was pressed, check if we stay in mode
    if (pokedex_callback_list_mode_proceed()) {
        //We stay in mode (maybe we just enabled fast mode)
        if (fmem->dex_mem->list_countdown) {
            fmem->dex_mem->list_countdown--;
        } else {
            int mode_lo[] = {0, 1, -1, 8, -8};
            u16 index_old = fmem->dex_mem->current_list_index;
            int index_new = index_old + mode_lo[fmem->dex_mem->list_mode];
            if (index_new < pokedex_get_first_seen())
                index_new = pokedex_get_first_seen();
            if (index_new > pokedex_get_last_seen())
                index_new = pokedex_get_last_seen();
            if (index_new != index_old) {
                sound(5);
                fmem->dex_mem->current_list_index = (u16) index_new;
                fmem->dex_mem->list_countdown = fmem->dex_mem->list_fast_mode ? 0 : 8;
                pokedex_update_list();
            }
        }
    }

}

void pokedex_build_list() {
    pokedex_list_element *list = (pokedex_list_element*) malloc(POKEDEX_CNT * sizeof (pokedex_list_element));
    fmem->dex_mem->list = list;
    int list_size = 0;
    u16 i;
    int j;
    for (i = 0; i < POKEMON_CNT; i++) {
        //check if pokemon is a mega target

        bool is_mega_target = !pokedex_get_id(i);
        j = 0;
        while (megas[j].species != 0xFFFF) {
            if (megas[j].target == i) {
                is_mega_target = true;
                break;
            }
            j++;
        }
        if (!is_mega_target) {
            //Add the pokemon to list with its dex number
            list[list_size].species = i;
            u16 dex_id = pokedex_get_id(i);
            list[list_size].dex_id = dex_id;
            list[list_size].seen = pokedex_operator_by_dex_id(dex_id, 0);
            list[list_size].caught = pokedex_operator_by_dex_id(dex_id, 1);
            list_size++;
        }
    }
    if (list_size > POKEDEX_CNT) {
        while (true) {
        }//Debuging exit
    }
}

void pokedex_update_list() {
    pokedex_list_element *list = fmem->dex_mem->list;
    fmem->dex_mem->current_species = list[fmem->dex_mem->current_list_index].species;
    //find first and last element in list
    int first = fmem->dex_mem->current_list_index - fmem->dex_mem->cursor_anchor - 3; //
    if (first < pokedex_get_first_seen())
        first = pokedex_get_first_seen();
    int last = first + 7;
    if (last > pokedex_get_last_seen())
        //test(pokedex_get_last_seen(),fmem->dex_mem->current_list_index);
        last = pokedex_get_last_seen();
    first = last - 7;
    if (first < pokedex_get_first_seen())
        first = pokedex_get_first_seen();

    u8 *buf = strbuf;
    *buf = 0xFF;


    u8 str_none [] = {0, 0xFF};
    u8 str_pokepad_pokedex_cursor [] = {0xEF, 0xFF};

    tbox_flush(POKEDEX_TBOX_LIST_NAME, 0);
    tbox_flush(POKEDEX_TBOX_LIST_TYPES, 0);
    tbox_flush(POKEDEX_TBOX_LIST_CAPTURE, 0);
    tbox_flush(POKEDEX_TBOX_LIST_NR, 0);
    int i = 0;
    while (first <= last) {
        u16 y_pixel = (u16) (14 * i);

        //We create the number string
        pokedex_tbox_draw_num(POKEDEX_TBOX_LIST_NR, 0, list[first].species, 0xC, y_pixel);

        //buf = str_append(buf, first == fmem->dex_mem->current_list_index ? str_arrow : str_none);
        if (first == fmem->dex_mem->current_list_index) {
            buf = str_append(buf, str_pokepad_pokedex_cursor);
        }
        if (list[first].seen) {
            buf = str_append(buf, pokemon_names[list[first].species]);
        } else {
            buf = str_append(buf, str_pokepad_pokedex_unkown_ref);
        }
        buf = str_append(buf, str_pokepad_pokedex_nl_ref);


        if (list[first].caught) {
            //now we draw the types
            u8 type1 = (u8) (basestats[list[first].species].type1 + 1);
            u8 type2 = (u8) (basestats[list[first].species].type2 + 1);
            tbox_draw_type_icon_by_type_p1(POKEDEX_TBOX_LIST_TYPES, type1, 0, y_pixel);
            if (type1 != type2)
                tbox_draw_type_icon_by_type_p1(POKEDEX_TBOX_LIST_TYPES, type2, 0x20, y_pixel);
            tbox_draw_type_icon_by_type_p1(POKEDEX_TBOX_LIST_CAPTURE, 0, 0, y_pixel);
        } else {

        }

        //Now we draw the typechart (lmostup x = 22, y = 5)

        /*
        if(type2 == type1) type2 = 0xFF;
        u8 y = (u8)(5 + 2 * i);
         * */
        first++;
        i++;

    }

    tbox_tilemap_draw(POKEDEX_TBOX_LIST_NAME);
    tbox_tilemap_draw(POKEDEX_TBOX_LIST_TYPES);
    tbox_tilemap_draw(POKEDEX_TBOX_LIST_CAPTURE);
    tbox_tilemap_draw(POKEDEX_TBOX_LIST_NR);
    tbox_print_string(POKEDEX_TBOX_LIST_NAME, 2, 0, 0, 0, 0, pokedex_fontcolmap, 0, strbuf);
    tbox_print_string(POKEDEX_TBOX_LIST_TYPES, 2, 0, 0, 0, 0, pokedex_fontcolmap, 0, str_none);
    tbox_print_string(POKEDEX_TBOX_LIST_CAPTURE, 2, 0, 0, 0, 0, pokedex_fontcolmap, 0, str_none);
    tbox_print_string(POKEDEX_TBOX_LIST_NR, 2, 0, 0, 0, 0, pokedex_fontcolmap, 0, str_none);
    bg_virtual_sync(0);

    //while(true){}
}
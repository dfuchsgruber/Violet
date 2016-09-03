/* 
 * File:   pokedex.h
 * Author: Domi
 *
 * Created on 11. August 2016, 23:10
 */

#ifndef POKEDEX_H
#define	POKEDEX_H

#include "anim_engine.h"
#include "pokemon.h"

#ifdef	__cplusplus
extern "C" {
#endif
    
    #define POKEDEX_CNT 386

    #define POKEDEX_TBOX_SEEN 0
    #define POKEDEX_TBOX_CAUGHT 1
    #define POKEDEX_TBOX_LIST_NAME 2
    #define POKEDEX_TBOX_LIST_TYPES 3
    #define POKEDEX_TBOX_LIST_CAPTURE 4
    #define POKEDEX_TBOX_LIST_NR 5
    
    #define POKEDEX_VAR_LAST_SPECIES 0x50DB
    #define POKEDEX_VAR_COMPARATOR 0x50DA
    #define POKEDEX_FLAG_HABITAT 0x927
    
    extern u8 *str_pokepad_pokedex_nl_ref;
    extern u8 *str_pokepad_pokedex_unkown_ref;
    extern u8 *str_pokepad_pokedex_form_ref;
    extern u8 *str_pokepad_pokedex_data_ref;
    extern u8 *str_pokepad_pokedex_qmark_ref;
    extern u8 *str_pokepad_pokedex_std_buttons_ref;
    extern u8 *str_pokepad_pokedex_habitat_ref;
    
    typedef struct{
        u16 dex_id;
        u16 species;
        bool seen;
        bool caught;
    }pokedex_list_element;
    
    typedef struct {
        bool from_outdoor;
        bool in_list;
        u8 current_group;
        u8 group_fading_index;
        bool group_fading_mode;
        u8 sorting;
        u16 current_species;
        u16 current_list_index;
        u8 current_comparator;
        bool cursor_anchor;
        //for list
        u8 list_mode; //0 = none, 1 = down, 2 = up, 3=right, 4=left
        bool list_fast_mode;
        u8 list_countdown;
        //for sortings
        u8 oam_sort_cursor;
        u8 sort_cursor_pos;
        bool resorting;
        bool reverse_req;
        pokedex_list_element *list;
        //for entry
        u16 tile_pokepic;
        u8 pal_pokepic;
        u8 oam_pokepic;
        bool entry_fade;
    } pokedex_memory;
    
    
     
    typedef struct {
        u8 category[12];
        u16 height;
        u16 weight;
        u8 *page0;
        u8 *page1;
        u16 unused;
        u16 poke_scale;
        u16 poke_displace;
        u16 trainer_scale;
        u16 trainer_displace;
        u16 unused_2;
    }pokedex_data;
    

    void pokedex_init_components();
    void pokedex_callback_init();
    void pokedex_init(bool from_outdoor);
    void pokedex_show_components();
    void pokedex_build_list();
    void pokedex_quicksort_list(u8 comparator, int l, int r);//0 := nr, 1 := name, 2 := size, 3 := weight
    int pokedex_quicksort_list_compare(u8 comparator, int a, int b);
    void pokedex_quicksort_list_swap(int a, int b);
    void pokedex_group_window_set();
    void pokedex_callback_group_selection();
    void pokedex_callback_return();
    void pokedex_free_maps();
    int pokedex_get_first_seen();
    int pokedex_get_last_seen();
    void pokedex_update_list();
    void pokedex_callback_list();
    void pokedex_callback_list_enter_mode(u8 mode);
    bool pokedex_callback_list_mode_proceed();
    void pokedex_sort_locate_cursor();
    void pokedex_callback_sort();
    void pokedex_big_callback_quicksort_parallel(u8 self);
    void pokedex_quicksort_revert(int from, int to);
    void pokedex_callback_init_entry();
    void pokedex_entry_load_strings();
    void pokedex_entry_load_pokepic();
    void pokedex_entry_update();
    void pokedex_callback_entry_idle();
    void pokedex_callback_entry_back();
    bool pokedex_operator(u16 val, u8 op, bool is_species_id);
    u16 pokedex_get_number_seen_or_caught(bool caught);
    //Romfuncs
    u16 pokedex_get_id(u16 species);
    bool pokedex_operator_by_dex_id(u16 dex_id, u8 op); //0 := is_seen, 1 := is_caught, 2 := set_seen, 3 := set_caught4
    pokedex_data *pokedex_get_data(u16 dex_id);
    bool national_dex_is_achieved();
    u16 pokemon_get_display_number(u16 species);
    
    u16 pokedex_order[POKEMON_CNT-1];
    
#ifdef	__cplusplus
}
#endif

#endif	/* POKEDEX_H */


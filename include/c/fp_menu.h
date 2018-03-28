/* 
 * File:   fp_menu.h
 * Author: Domi
 *
 * Created on 16. Oktober 2016, 12:09
 */

#ifndef FP_MENU_H
#define	FP_MENU_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "pokemon/virtual.h"
#include "oam.h"

    typedef struct {
        u8 poke_index;
        u8 stat_index;
        u16 tile_pokepic;
        u8 pal_pokepic;
        u8 oam_pokepic;
        u8 oam_arrows[4]; //down, up, left, right
        u8 delay;
        u8 pokepic_loading_state;

    } fp_memory;

    void fp_menu_init(u8 self);

    void fp_menu_callback_init();
    void fp_menu_callback_show();
    void fp_menu_callback_idle();
    void fp_menu_pokemon_load();
    u16 fp_menu_get_sum_applied(pokemon *target);
    void pokemon_set_fp_applied(pokemon *target, int stat, u8 value);
    u8 pokemon_get_fp_applied(pokemon *target, int stat);
    u16 fp_menu_get_sum_applied(pokemon *target);
    void fp_menu_stat_load(pokemon *target);
    void fp_menu_stats_load(pokemon *target);
    void fp_menu_pokepic_callback(oam_object *self);
    void fp_menu_callback_poke_jump(u8 self);
    void fp_menu_callback_arrow_anim(u8 self);
    void fp_menu_callback_return();
    void fp_menu_callback_pokemon_load();

    extern u8 *fp_menu_names[6];
    extern u8 str_fp_menu_plus[];
    extern u8 str_fp_menu_minus[];


#ifdef	__cplusplus
}
#endif

#endif	/* FP_MENU_H */


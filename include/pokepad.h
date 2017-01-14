/* 
 * File:   pokepad.h
 * Author: Domi
 *
 * Created on 23. Juni 2016, 13:38
 */

#ifndef POKEPAD_H
#define	POKEPAD_H

#include "anim_engine.h"
#include "oams.h"
#include "wondertrade.h"
#include "pokedex.h"

#define VAR_POKEPAD_LASTUSED 0x50ED
#define VAR_POKEPAD_REGISTERED 0x50EC

#define POKEPAD_DESCRIPTION_TBOX 0
#define POKEPAD_BUTTON_TBOX_BASE 1

#define FLAG_WONDERTRADE 0x915
#define FLAG_POKERADAR 0x23C


#ifdef	__cplusplus
extern "C" {
#endif

    extern u8 *str_pokepad_r_ref;
    extern u8 *str_pokepad_l_ref;
    extern u8 *str_pokepad_registered_ref;
    extern u8 *str_pokepad_deregistered_ref;

    typedef struct pokepad_item {
        u16 flag;
        u8 *string;
        void (*func)(bool from_outdoor);
        pstring description;
    } pokepad_item;

    typedef struct pokepad_memory {
        u8 items [8];
        u8 current_item;
        u8 item_cnt;
        u8 color_cb;
        u8 arrow_oam;
        u8 l_oam;
        u8 r_oam;
        u8 lr_countdown;
    } pokepad_memory;

    bool startmenu_init_pokepad();
    void pokepad_callback_init();
    void pokepad_init_components();
    void pokepad_show_components();
    void pokepad_build_buttons(void *tilemap);
    void pokepad_draw_button(void *tilemap, u8 x, u8 y, u8*string);
    void pokepad_callback_background_anim(u8 self);
    void pokepad_load_description();
    void pokepad_oam_arrow_anim(oam_object *self);
    void pokepad_callback_registered_string();
    void pokepad_free_and_return();
    void pokepad_free_components();

    graphic graphic_pokepad_arrow;
    graphic graphic_pokepad_l;
    graphic graphic_pokepad_r;
    sprite sprite_pokepad_lr;
    sprite sprite_pokepad_arrow;
    oam_template oam_template_pokepad_arrow;
    oam_template oam_template_pokepad_l;
    oam_template oam_template_pokepad_r;

    graphic graphic_wondertrade_badges;
    sprite sprite_wondertrade_badges;
    oam_template oam_template_wondertrade_badges;

    bool pokepad_init_function_outdoor();

    extern pokepad_item *pokepad_items;



#ifdef	__cplusplus
}
#endif

#endif	/* POKEPAD_H */


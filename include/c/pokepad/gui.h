/*
 * gui.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_POKEPAD_GUI_H_
#define INCLUDE_C_POKEPAD_GUI_H_

#include "oam.h"
#include "pokepad/state.h"


#define POKEPAD_DESCRIPTION_TBOX 0
#define POKEPAD_BUTTON_TBOX_BASE 1

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

#endif /* INCLUDE_C_POKEPAD_GUI_H_ */

/* 
 * File:   pokepad.h
 * Author: Domi
 *
 * Created on 23. Juni 2016, 13:38
 */

#ifndef POKEPAD_H
#define	POKEPAD_H

#include "anim_engine.h"


#define VAR_POKEPAD_LASTUSED 0x50EE

#ifdef	__cplusplus
extern "C" {
#endif

    typedef struct pokepad_item{
        u16 flag;
        u8 *string;
        void (*func)();
        pstring description;
    }pokepad_item;
    
    typedef struct pokepad_memory{
        u8 items [12];
        u8 current_item;
        u8 item_cnt;
        void *bg1set;
        void *buttonset;
        u8 tboxes [12]; // 12 boxes for the item text
    } pokepad_memory;
    
    bool startmenu_init_pokepad();
    void pokepad_callback_init();
    void pokepad_init_components();
    void pokepad_show_components();
    void pokepad_build_buttons(void *tilemap);
    void pokepad_draw_button(void *tilemap, u8 x, u8 y, u8*string, u16 start_tile);

#ifdef	__cplusplus
}
#endif

#endif	/* POKEPAD_H */


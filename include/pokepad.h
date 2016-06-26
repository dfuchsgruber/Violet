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
        pstring string;
        void (*script)();
        pstring description;
    }pokepad_item;
    
    typedef struct pokepad_memory{
        u8 items [12];
        u8 current_item;
        u8 status;
    } pokepad_memory;
    
    void startmenu_init_pokepad();
    void pokepad_callback();
    void pokepad_init_components();

#ifdef	__cplusplus
}
#endif

#endif	/* POKEPAD_H */


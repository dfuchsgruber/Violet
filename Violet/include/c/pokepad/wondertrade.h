/*
 * wondertrade.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_POKEPAD_WONDERTRADE_H_
#define INCLUDE_C_POKEPAD_WONDERTRADE_H_

#include "types.h"

#define POKEPAD_WONDERTRADE_TBOX_TITLE 0
#define POKEPAD_WONDERTRADE_TBOX_LEVEL_H 1
#define POKEPAD_WONDERTRADE_TBOX_LEVEL_T 2
#define POKEPAD_WONDERTRADE_TBOX_CNT_H 3
#define POKEPAD_WONDERTRADE_TBOX_CNT_T 4
#define POKEPAD_WONDERTRADE_TBOX_NEXT_H 5
#define POKEPAD_WONDERTRADE_TBOX_NEXT_T 6
#define POKEPAD_WONDERTRADE_TBOX_RENDERER 7
#define POKEPAD_WONDERTRADE_TBOX_TRADE 8
#define POKEPAD_WONDERTRADE_TBOX_BACK 9


    typedef struct wondertrade_memory {
        bool from_outdoor;
        bool error_m;
        bool usable;
        u8 scroll_cb;
        u8 color_cb;
        u8 oam_badge;
        u8 cursor;
    } wondertrade_memory;

    extern u8 str_wondertrade_not_possible_script[];
    extern u8 script_wondertrade_failure[];
    extern u8 str_wondertrade_name0[];
    extern u8 *wondertrade_ot_names[];

    /**
     * Callback responsible for scrolling the background of the wondertrade ui
     * @param self the own callback id
     */
    void wondertrade_bg_scroll_callback(u8 self);

    /**
     * Initializes a wondertrade
     */
    void wondertrade_init_components();

    /**
     * Callback that initalizes all ui and state of the wondertrade
     */
    void wondertrade_init_callback();

    /**
     * Loads the steps currently done for wondertrade into a buffer
     */
    void wondertrade_buffer_steps();

    /**
     * Initializes a wondertrade from either the pokepad or the outdoor LR shortcut
     * @param is_outdoor whether initialized via LR shortcut from overworld
     */
    void wondertrade_init(bool is_outdoor);

    /**
     * Selects the pokemon to receive during wondertrade
     * @return the selected pokemon
     */
    u16 wondertrade_select_pokemon();

    /**
     * Spawns a virtual pokemon for the wondertrade
     */
    void wondertrade_spawn_pokemon();

    /**
     * Checks if the selected own pokemon can be traded away (eggs and pokemon with hm moves can't)
     * @return if the pokemon can be traded away
     */
    bool wondertrade_can_pokemon_be_sent();

    /**
     * Seed function for the pokemon spawn generator using the wondertrade level
     * @return a seed in range [0; x] where x is small for high wondertrade levels
     */
    u16 wondertrade_next_seed();

    /**
     * Gets the level of the wondertrade
     * @return the wondertrade level
     */
    u8 wondertrade_get_level();

    /**
     * Wondertrade idle callback1
     */
    void wondertrade_callback_idle();

    /**
     * Wondertrade callback1 to show all ui components
     */
    void wondertrade_show_components();

    /**
     * Frees all wondertrade components and returns to the previous state
     */
    void wondertrade_callback_free_components_and_return();

    /**
     * Initializes the color callbacks for the wondertrade
     */
    void wondertrade_init_callback();

    /**
     * Callback1 after the selection of a pokemon
     */
    void wondertrade_callback_after_selection();

    /**
     * Initializes the selection of a pokemon
     */
    void wondertrade_callback_init_selection();

    /**
     * Frees all allocated memory by the wondertrade
     */
    void wondertrade_free_components();

    /**
     * Initializes the ingame trade callback
     */
    void ingame_trade_init_callback();


#endif /* INCLUDE_C_POKEPAD_WONDERTRADE_H_ */

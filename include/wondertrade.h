/* 
 * File:   wondertrade.h
 * Author: Domi
 *
 * Created on 8. August 2016, 00:34
 */

#ifndef WONDERTRADE_H
#define	WONDERTRADE_H

#ifdef	__cplusplus
extern "C" {
#endif

#define VAR_POKEPAD_WONDERTRADE_STEP_CNT 0x50E2
#define VAR_POKEPAD_WONDERTRADE_CNT 0x50F2

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

#define POKEPAD_WONDERTRADE_MEW_FLAG 0x91F

    typedef struct wondertrade_memory {
        bool from_outdoor;
        bool error_m;
        bool usable;
        u8 scroll_cb;
        u8 color_cb;
        u8 oam_badge;
        u8 cursor;
    } wondertrade_memory;

    extern u8 *str_pokepad_wondertrade_ref;
    extern u8 *script_wondertrade_failure;
    extern u8 *str_wondertrade_level_ref;
    extern u8 *str_wondertrade_bronze_ref;
    extern u8 *str_wondertrade_silver_ref;
    extern u8 *str_wondertrade_gold_ref;
    extern u8 *str_wondertrade_platin_ref;
    extern u8 *str_wondertrade_anzahl_ref;
    extern u8 *str_wondertrade_next_ref;
    extern u8 *str_wondertrade_none_ref;
    extern u8 *str_wondertrade_not_possible_script_ref;
    extern u8 *str_wondertrade_do_ref;
    extern u8 *str_wondertrade_back_ref;
    extern u8 *str_wondertrade_error_m_ref;

    extern u8 *str_wondertrade_name0_ref;
    extern u8 *wondertrade_ot_names[];

    void wondertrade_bg_scroll_callback(u8 self);
    void wondertrade_init_components();
    void wondertrade_init_callback();
    void wondertrade_load_steps_into_buffer();
    void wondertrade_init(bool is_outdoor);

    u16 wondertrade_select_pokemon();
    void wondertrade_spawn_pokemon();
    bool wondertrade_can_pokemon_be_sent();
    u16 wondertrade_next_seed();
    u8 wondertrade_get_level();
    void wondertrade_bg_scroll_callback(u8 self);
    void wondertrade_callback_idle();
    void wondertrade_show_components();
    void wondertrade_callback_free_components_and_return();
    void wondertrade_init_components();
    void wondertrade_init_callback();
    void wondertrade_load_steps_into_buffer();
    void wondertrade_init(bool is_outdoor);
    void wondertrade_callback_after_selection();
    void wondertrade_callback_init_selection();
    void wondertrade_free_components();

#ifdef	__cplusplus
}
#endif

#endif	/* WONDERTRADE_H */


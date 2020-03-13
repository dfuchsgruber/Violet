#ifndef H_SUPERSTATE
#define H_SUPERSTATE

#include "types.h"
#include "oam.h"

typedef union {

    struct {
        u16 A : 1;
        u16 B : 1;
        u16 select : 1;
        u16 start : 1;
        u16 right : 1;
        u16 left : 1;
        u16 up : 1;
        u16 down : 1;
        u16 r : 1;
        u16 l : 1;
    } keys;
    u16 value;
} key;

typedef struct superstate {
    void (*callback0)();
    void (*callback1)();
    void (*saved_callback)();
    void (*vblank_callback)();
    void (*blank_callback)();
    void (*vcount_callback)();
    void (*serial_callback)();
    u32 wait;
    u32 *vblank_cnt_ptr;
    u32 local_vlbank_cnt;
    //key section
    key keys;
    key keys_new;
    key keys_inv;
    key keys_remapped; //by options (L->A, R->B)
    key keys_new_rst; //keys are registered as new here when pressed long enough
    key keys_countdown;
    u16 keys_watched;
    key watched_keys;
    u16 oam_attributes[128][4];
    u8 state;
    u8 disable_oams : 1;
    u8 in_battle : 1;

} superstate;

extern superstate super;

/**
 * Generic callback1 that manages most of the game state (can be called inside other callback1s)
 */
void generic_callback1();

/**
 * Generic vblank handler
 */
void generic_vblank_handler();

/**
 * Sets the callback1
 * @param f the callback function to set
 */
void callback1_set(void (*f)());

/**
 * Sets the callback2
 * @param f the callback function to set
 */
void callback2_set(void (*f)());

/**
 * Sets the callback3
 * @param f the callback function to set
 */
void vblank_handler_set(void (*f)());

/**
 * Updates the context of the game.
 **/
void game_context_update();

/**
 * Checks if the game state is "normal" or something like that, i.e. either a standard callback0 or a flag that must be set to bypass that.
 **/
bool sub_080bf8d8();

#endif

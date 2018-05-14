#ifndef H_SUPERSTATE
#define H_SUPERSTATE

#include "types.h"

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
    void *callbacks[7]; //3 :=vlbank, 4:=hblank
    u32 wait;
    u32 *vblank_cnt_ptr;
    u32 local_vlbank_cnt;
    //key section
    key keys;
    key keys_new;
    key keys_held2;
    key keys_remapped; //by options (L->A, R->B)
    key keys_new_rst; //keys are registered as new here when pressed long enough
    u16 key_press_countdown;

} superstate;

superstate *super = (superstate*) 0x03003040;

/**
 * Generic callback1 that manages most of the game state (can be called inside other callback1s)
 */
void generic_callback1();

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
void callback3_set(void (*f)());

#endif

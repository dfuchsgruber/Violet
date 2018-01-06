/**
 * Xorshift pseudo randon number generator
 */

#include "types.h"
#include "prng.h"



u16 rnd_init(){
    u16 timer = *(u16*)0x04000104;
    if(!timer) timer++; //Just any not zero number
    u16 *timer_cntl = (u16*)0x04000106;
    *timer_cntl = 0; //Disable timer
    rnd_main_set_seed(timer);
    u16 *malloc_magic = (u16*)0x02020000;
    *malloc_magic = timer;
}

u16 rnd16(){
    return (u16)_prng_xorshift(_main_rnd);
}

void rnd_main_set_seed(u32 seed){
    *_main_rnd = seed;
}

u32 _prng_xorshift(u32 *_seed){
    //Period of 2^32 - 1
    u32 seed = *_seed;
    seed ^= seed << 13;
    seed ^= seed >> 17;
    seed ^= seed << 5;
    *_seed = seed;
    return seed;
}


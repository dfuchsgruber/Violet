/* 
 * File:   prng.h
 * Author: Domi
 *
 * Created on 5. Januar 2018, 14:37
 */

#ifndef PRNG_H
#define	PRNG_H

#ifdef	__cplusplus
extern "C" {
#endif

    u32 *_main_rnd = (u32*)0x03004F50;

    u16 rnd_init(); //Initializes the main rng module (xorshift)

    /**
     * Provides new 16 bit random value (periodicity is 2^32)
     * @return 16 bit random value
     */
    u16 rnd16();

    /**
     * Sets the seed of the main rng module
     * @param seed
     * @return 
     */
    void rnd_main_set_seed(u32 seed);

    /**
     * Shifts any 32 bit rng state
     * @param _seed Pointer to prng state
     * @return Next state
     */
    u32 _prng_xorshift(u32 *_seed);



#ifdef	__cplusplus
}
#endif

#endif	/* PRNG_H */


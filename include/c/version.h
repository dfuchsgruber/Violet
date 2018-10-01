/* 
 * File:   version.h
 * Author: Domi
 *
 * Created on 6. Januar 2017, 22:39
 */

#ifndef VERSION_H
#define	VERSION_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "types.h"
#include "save.h"
#include "pokemon/virtual.h"

#define VERSION_ALPHA_2_2 3
#define VERSION_ALPHA_2_1 2
#define VERSION_ALPHA_2_0 1
#define VERSION_LATEST VERSION_ALPHA_2_2
    
// Old pid structure (before 2.2)
typedef union {
    u32 value;

    struct {
        u32 ability : 1;
        u32 gender_partial : 7;
        u32 shinyness : 16;
        u32 nature : 5;
        u32 form : 3;
    } fields;
} _pid_t_old;

/**
 * Fixes a pokemon which is in the format of version < 2.2
 * @param target the pokemon to fix (might be in compressed format)
 */
void version_alpha_2_2_fix_pid(pokemon *target);
    
    void version_upgrade_alpha_1_X_to_2_0();
    void version_upgrade_alpha_2_0_to_2_1();
    void version_upgrade_alpha_2_1_to_2_2();

    /**
     * Transfers the pokedex flag from the order of alpha < 2.2 to the order of alpha >= 2.2
     */
    void version_transfer_pokedex();


#ifdef	__cplusplus
}
#endif

#endif	/* VERSION_H */


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

#define VERSION_ALPHA_2_2 3
#define VERSION_ALPHA_2_1 2
#define VERSION_ALPHA_2_0 1
#define VERSION_LATEST VERSION_ALPHA_2_2
    
    
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


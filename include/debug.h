/* 
 * File:   debug.h
 * Author: Domi
 *
 * Created on 12. November 2016, 16:22
 */

#ifndef DEBUG_H
#define	DEBUG_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "types.h"
    
#define ERR_UNKOWN_GRASS_ANIMATION 0
#define ERR_TAN_16_COS_16_EQUALS_ZERO 1    
    
    void debug1(int a);
    void debug2(int a, int b);
    void debug3(int a, int b, int c);
    void debug4(int a, int b, int c, int d);
    void debugn(int *n);
    void err(int e);


#ifdef	__cplusplus
}
#endif

#endif	/* DEBUG_H */


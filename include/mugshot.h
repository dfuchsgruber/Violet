/* 
 * File:   mugshot.h
 * Author: Domi
 *
 * Created on 16. Juni 2016, 15:07
 */

#ifndef MUGSHOT_H
#define	MUGSHOT_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "stdbool.h"

    typedef struct mugshot {
        void *gfx;
        void *pal;
    } mugshot;

    void spawn_mugshot();

    void clear_mugshot();

#ifdef	__cplusplus
}
#endif

#endif	/* MUGSHOT_H */


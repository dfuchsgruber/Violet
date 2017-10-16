/* 
 * File:   starterselection.h
 * Author: Domi
 *
 * Created on 30. September 2017, 16:30
 */

#ifndef STARTERSELECTION_H
#define	STARTERSELECTION_H

#include "data_structures.h"


#ifdef	__cplusplus
extern "C" {
#endif

#define STARTER_SELECTED 0x4052
    
    typedef struct {
        u16 hscroll;
        u8 hscroll_delay;
        u8 cursor;
        u8 pokeball_oams[3];
        bool selected;
    } trainerschool_selection_memory;
    
#define TSS_MEM ((trainerschool_selection_memory*)gp_stack_peek())



#ifdef	__cplusplus
}
#endif

#endif	/* STARTERSELECTION_H */


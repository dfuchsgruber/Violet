/*
 * vars.h
 *
 *  Created on: May 2, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_VARS_H_
#define INCLUDE_C_VARS_H_

#include "constants/vars.h"

/**
 * Accesses a variable
 * @param var The variable to access
 * @return The offset of the variable
 */
u16 *var_access(u16 var);

/**
 * Gets a value from a var if the arg is >= 0x4000 and else just returns the value.
 * @param arg if >= 0x4000 it is interpreted as variable, else as value 
 * @return the value of variable arg if arg >= 0x4000 and else arg
 **/
u16 var_get(u16 var);

u16 lastresult;

#endif /* INCLUDE_C_VARS_H_ */

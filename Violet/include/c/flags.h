/*
 * flags.h
 *
 *  Created on: May 1, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_FLAGS_H_
#define INCLUDE_C_FLAGS_H_

#include "constants/flags.h"

/**
 * Sets a flag
 * @param The flag to set
 */
void setflag(u16 flag);

/**
 * Clears a flag
 * @param The flag to clear
 */
void clearflag(u16 flag);

/**
 * Returns offset of a flag byte in memory
 * @param The flag
 * @return Offset to the byte containing the flag
 */
u8 *flag_access_ext(u16 flag);

/**
 * Checks if a flag is set
 * @param The flag to check
 * @return If the flag is set
 */
bool checkflag(u16 flag);

/**
 * Accesses the flag memory
 * @param flag the flag to access
 * @return offset of the byte containing the flag
 */
u8 *flag_access(u16 flag);

#endif /* INCLUDE_C_FLAGS_H_ */

/*
 * flags.h
 *
 *  Created on: May 1, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_FLAGS_H_
#define INCLUDE_C_FLAGS_H_

#include "constants/flags.h"
#include "types.h"

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

/**
 * Calculates how many badges the player has unlocked.
 * @return how many badges the player has
 */
u8 badges_number_get();

/**
 * Gets a flag from a list of bytes
 * @param flag the flag idx to get
 * @param flags the bytes that store the flag
 * @return if a flag is set
 */
bool gp_flag_get(u16 flag, u8 *flags);

/**
 * Sets a flag in a list of bytes
 * @param flag the flag idx to set
 * @param flags the bytes that store the flag
 */
void gp_flag_set(u16 flag, u8 *flags);

/**
 * Clears a flag in a list of bytes
 * @param flag the flag idx to clear
 * @param flags the bytes that store the flag
 */
void gp_flag_clear(u16 flag, u8 *flags);

#endif /* INCLUDE_C_FLAGS_H_ */

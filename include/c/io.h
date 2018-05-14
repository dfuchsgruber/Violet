/*
 * io.h
 *
 *  Created on: May 1, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_IO_H_
#define INCLUDE_C_IO_H_

/**
 * Sets the value of an IO register in the next frame
 * @param ioreg The register to set
 * @param value The value to set the register to
 */
void io_set(u16 ioreg, u16 value);

/**
 * Gets the value of an IO register
 * @param ioreg The register to get
 * @return The value of the register
 */
u16 io_get(u16 ioreg);

/**
 * Bitclears an IO register
 * @param ioreg the register to bic
 * @param mask the mask to apply
 */
void io_bic(u8 ioreg, u16 mask);

#endif /* INCLUDE_C_IO_H_ */

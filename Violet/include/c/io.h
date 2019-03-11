/*
 * io.h
 *
 *  Created on: May 1, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_IO_H_
#define INCLUDE_C_IO_H_

#define IO_BGHOFS(x) (0x10 + ((x) << 2))
#define IO_BGVOFS(x) (0x12 + ((x) << 2))

#define IO_BLDCNT 0x50
#define IO_BLDCNT_BG0_FIRST 1
#define IO_BLDCNT_BG1_FIRST 2
#define IO_BLDCNT_BG2_FIRST 4
#define IO_BLDCNT_BG3_FIRST 8
#define IO_BLDCNT_OBJ_FIRST 16
#define IO_BLDCNT_BACKDROP_FIRST 32
#define IO_BLDCNT_ALPHA_BLENDING 1 << 6
#define IO_BLDCNT_BRIGHTNESS_INCREASE 2 << 6
#define IO_BLDCNT_BRIGHTNESS_DECREASE 3 << 6
#define IO_BLDCNT_BG0_SECOND 0x100
#define IO_BLDCNT_BG1_SECOND 0x200
#define IO_BLDCNT_BG2_SECOND 0x400
#define IO_BLDCNT_BG3_SECOND 0x800
#define IO_BLDCNT_OBJ_SECOND 0x1000
#define IO_BLDCNT_BACKDROP_SECOND 0x2000

#define IO_BLDALPHA 0x52
#define IO_BLDALPHA_EVA(x) (x)
#define IO_BLDALPHA_EVB(x) (x << 8)

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

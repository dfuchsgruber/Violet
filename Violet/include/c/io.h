/*
 * io.h
 *
 *  Created on: May 1, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_IO_H_
#define INCLUDE_C_IO_H_

#define IO_ADDRESS 0x04000000

#define IO_DISPCNT 0x0
#define IO_DISPCNT_BG_MODE(x) (x)
#define IO_DISPCNT_CGB_MODE 8
#define IO_DISPCNT_DISPLAY_FRAME 16
#define IO_DISPCNT_H_BANK_INTERVAL_OBJ_PROCESSING 32
#define IO_DISPCNT_OAM_CHARACTER_MAPPING_ONE_DIMENSIONAL 64
#define IO_DISPCNT_OAM_CHARACTER_MAPPING_TWO_DIMENSIONAL 0
#define IO_DISPCNT_FORCED_BLANK 128
#define IO_DISPCNT_BG(bg) ((bg) << 8)
#define IO_DISPCNT_OBJ 0x1000
#define IO_DISPCNT_WIN0 0x2000
#define IO_DISPCNT_WIN1 0x4000
#define IO_DISPCNT_OBJWIN 0x8000

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

#define IO_WININOUT_BG(win,bg) (1 << ((bg) + 8 * (win)))
#define IO_WININOUT_OBJ(win) (16 << (8 * (win)))
#define IO_WININOUT_FX(win) (32 << (8 * (win)))
#define IO_WININ 0x48
#define IO_WINOUT 0x4C

#define IO_WINH(left,right) ((right) | ((left) << 8))
#define IO_WINV(up,down) ((down) | ((up) << 8))
#define IO_WIN0H 0x40
#define IO_WIN1H 0x42
#define IO_WIN0V 0x44
#define IO_WIN1V 0x46

#define IO_DMA_BASE 0x040000B0
#define IO_DMA_REGS(num) (IO_DMA_BASE + 12 * num)

#define IO_IME (*(vu16*) (IO_ADDRESS + 0x208))

// timer
#define TIMER_1CLK        0x00
#define TIMER_64CLK       0x01
#define TIMER_256CLK      0x02
#define TIMER_1024CLK     0x03
#define TIMER_INTR_ENABLE 0x40
#define TIMER_ENABLE   0x80
#define IO_TM2CNT (*(vu32*) (IO_ADDRESS + 0x108))
#define IO_TM2CNT_L (*(vu16*) (IO_ADDRESS + 0x108))
#define IO_TM2CNT_H (*(vu16*) (IO_ADDRESS + 0x10a))
#define IO_TM3CNT (*(vu32*) (IO_ADDRESS + 0x10c))
#define IO_TM3CNT_L (*(vu16*) (IO_ADDRESS + 0x10c))
#define IO_TM3CNT_H  (*(vu16*) (IO_ADDRESS + 0x10e))



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

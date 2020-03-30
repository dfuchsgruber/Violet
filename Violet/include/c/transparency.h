/* 
 * File:   transparency.h
 * Author: Domi
 *
 * Created on 2. August 2016, 23:09
 */

#ifndef TRANSPARENCY_H
#define	TRANSPARENCY_H

#include "types.h"
#include "color.h"

void transparency_handler(u8 *command);
bool transparency_is_on();
bool transparency_used_by_weather();
void transparency_on();
void transparency_off();
bool transparency_load_black_pal();

const color_t tbox_palette_transparent[16];

#endif	/* TRANSPARENCY_H */


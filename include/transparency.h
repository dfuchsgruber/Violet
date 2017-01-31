/* 
 * File:   transparency.h
 * Author: Domi
 *
 * Created on 2. August 2016, 23:09
 */

#ifndef TRANSPARENCY_H
#define	TRANSPARENCY_H

#define FLAG_BYPASS_TRANSPARENCY 0x911
#define FLAG_TRANSPARENCY_ON 0x910

#include "types.h"
#include "color.h"

void transparency_handler(u8 *command);
bool transparency_is_on();
bool transparency_used_by_weather();
void transparency_on();
void transparency_off();
bool transparency_load_black_pal();

const color transparency_black_box_pals [10 * 16];

#endif	/* TRANSPARENCY_H */


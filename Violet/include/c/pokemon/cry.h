/*
 * pokemon_cry.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_POKEMON_CRY_H_
#define INCLUDE_C_POKEMON_CRY_H_

#include "pokemon/count.h"

typedef struct {
    u8 header[4];
    void *data;
    u8 vol_curve[4];
} pokemon_cry;

pokemon_cry pokemon_cries_forward[POKEMON_CNT];
pokemon_cry pokemon_cries_backward[POKEMON_CNT];

/**
 * Plays the cry of a pokemon
 * @param species The species to play the cry of
 * @param feature Feature for the cry
 */
void pokemon_play_cry(u16 species, u8 feature);

// Extern cries from wav2agb

extern u8 cry_661[];
extern u8 cry_662[];
extern u8 cry_663[];
extern u8 cry_396[];
extern u8 cry_397[];
extern u8 cry_398[];
extern u8 cry_436[];
extern u8 cry_437[];
extern u8 cry_672[];
extern u8 cry_673[];
extern u8 cry_708[];
extern u8 cry_709[];
extern u8 cry_669[];
extern u8 cry_670[];
extern u8 cry_671[];
extern u8 cry_470[];
extern u8 cry_700[];
extern u8 cry_595[];
extern u8 cry_596[];
extern u8 cry_597[];
extern u8 cry_598[];
extern u8 cry_679[];
extern u8 cry_680[];
extern u8 cry_681[];
extern u8 cry_302[];
extern u8 cry_592[];
extern u8 cry_593[];
extern u8 cry_200[];
extern u8 cry_475[];
extern u8 cry_636[];
extern u8 cry_637[];
extern u8 cry_471[];
extern u8 cry_701[];
extern u8 cry_462[];
extern u8 cry_468[];
extern u8 cry_707[];
extern u8 cry_607[];
extern u8 cry_608[];
extern u8 cry_609[];
extern u8 cry_459[];
extern u8 cry_460[];
extern u8 cry_424[];
extern u8 cry_430[];
extern u8 cry_478[];
extern u8 cry_472[];
extern u8 cry_466[];
extern u8 cry_473[];
extern u8 cry_442[];
extern u8 cry_463[];
extern u8 cry_476[];
extern u8 cry_429[];
extern u8 cry_467[];
extern u8 cry_477[];
extern u8 cry_447[];
extern u8 cry_448[];
extern u8 cry_443[];
extern u8 cry_444[];
extern u8 cry_445[];
extern u8 cry_115[];
extern u8 cry_474[];
extern u8 cry_464[];
extern u8 cry_446[];
extern u8 cry_780[];
extern u8 cry_440[];
extern u8 cry_438[];
extern u8 cry_433[];


#endif /* INCLUDE_C_POKEMON_CRY_H_ */

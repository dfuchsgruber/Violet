/* 
 * File:   debug.h
 * Author: Domi
 *
 * Created on 12. November 2016, 16:22
 */

#ifndef DEBUG_H
#define DEBUG_H

#ifdef __cplusplus
extern "C" {
#endif

#include "types.h"
#include <stdarg.h>

#define ERR_UNKOWN_GRASS_ANIMATION 0
#define ERR_TAN_16_COS_16_EQUALS_ZERO 1
#define ERR_HIDDEN_FLAG_CHUNK_GT_3 2
#define ERR_FLAG_ACCESS_INVALID 3
#define ERR_NO_REPEL_ITEM 4
#define ERR_DUNGEON_GEN_PATTERN_MISMATCH_SEG_0 5
#define ERR_DUNGEON_GEN_PATTERN_MISMATCH_SEG_1 6
#define ERR_DUNGEON_GEN_PATTERN_MISMATCH_SEG_2 7
#define ERR_DUNGEON_GEN_PATTERN_MISMATCH_SEG_3 8
#define ERR_MEGA_CALLBACK_NOT_ACCESSIBLE 9
#define ERR_GENERIC 10
#define ERR_TRADE_EVO_NOT_IMPLEMENTED 11

void debug1(int a);
void debug2(int a, int b);
void debug3(int a, int b, int c);
void debug4(int a, int b, int c, int d);
void debugn(int *n);
void err(int e);
void err2(int e, int p);

void dprintf(const char *str, ...);
void derrf(const char *str, ...);

#ifdef __cplusplus
}
#endif

#endif /* DEBUG_H */

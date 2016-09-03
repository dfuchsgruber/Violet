/* 
 * File:   evolution.h
 * Author: Domi
 *
 * Created on 2. September 2016, 14:11
 */

#ifndef EVOLUTION_H
#define	EVOLUTION_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "types.h"
#include "item.h"

#define EVOLUTION_METHOD_NONE 0
#define EVOLUTION_METHOD_FRIENDSHIP 1
#define EVOLUTION_METHOD_FRIENDSHIP_DAY 2
#define EVOLUTION_METHOD_FRIENDSHIP_NIGHT 3
#define EVOLUTION_METHOD_LEVEL_UP 4
#define EVOLUTION_METHOD_TRADE 5
#define EVOLUTION_METHOD_TRADE_HOLD_ITEM 6
#define EVOLUTION_METHOD_STONE 7
#define EVOLUTION_METHOD_ATK_GT_DEF 8
#define EVOLUTION_METHOD_ATK_EQ_DEF 9
#define EVOLUTION_METHOD_ATK_LT_DEF 10
#define EVOLUTION_METHOD_PID_EVEN 11
#define EVOLUTION_METHOD_PID_ODD 12
#define EVOLUTION_METHOD_SPAWN_SECOND 13
#define EVOLUTION_METHOD_CREATE_SPAWN 14
#define EVOLUTION_METHOD_BEAUTY 15
#define EVOLUTION_METHOD_ON_MAP 16
#define EVOLUTION_METHOD_HOLD_ITEM 17
#define EVOLUTION_METHOD_KNOW_MOVE 18
#define EVOLUTION_METHOD_ITEM_AND_DISTINCT_MAP 19
#define EVOLUTION_METHOD_LINK_CABLE_AND_ITEM 20
#define EVOLUTION_METHOD_MALE_AND_STONE 21
    
    typedef struct {
        u16 method;
        u16 condition;
        u16 target;
        u16 padding;
    }pokemon_evolution;
    
u16 pokemon_get_basis_stage(u16 species);

#ifdef	__cplusplus
}
#endif

#endif	/* EVOLUTION_H */


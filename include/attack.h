/* 
 * File:   attack.h
 * Author: Domi
 *
 * Created on 3. Januar 2017, 17:56
 */

#ifndef ATTACK_H
#define	ATTACK_H

#ifdef	__cplusplus
extern "C" {
#endif

    typedef struct{
        u8 effect;
        u8 base_power;
        u8 type;
        u8 accuracy;
        u8 pp;
        u8 effect_accuracy;
        u8 affects_whom;
        u8 priority;
        u8 flags;
        u8 effect_table;
        u8 category;
        u8 padding;
    }attack;

    attack *attacks = (attack*)0x9100000;

#ifdef	__cplusplus
}
#endif

#endif	/* ATTACK_H */


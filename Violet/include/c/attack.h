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

#include "pokemon/virtual.h"

#define ATTACK_CNT 413

    typedef struct{
        u8 effect;
        u8 base_power;
        u8 type;
        u8 accuracy;
        u8 pp;
        u8 effect_accuracy;
        u8 affects_whom;
        s8 priority;
        u8 flags;
        u8 effect_table;
        u8 category;
        u8 padding;
    }attack;

    
    typedef struct{
        u8 attacker;
        u8 defender;
        u8 multiplicator;
    }type_effectiveness;
    
    attack attacks[ATTACK_CNT];
    /**
     * Battle scripts for each attack effect.
     */
    extern u8 *attack_effects[];

    /**
     * Checks if an attack is a hidden machine
     * @param move the attack
     * @return if the attack is a hidden machine
     */
    bool attack_is_hidden_machine(u16 move);

    /**
     * Checks if an attack needs charging
     * @param move the attack
     * @return if the attack needs charing
     */
    bool attack_needs_charging(u16 move);

    /**
     * Returns the type of hidden power based on a pokemon's pid.
     * @param pid the pid of a pokemon
     * @return its hidden power type
     */
    u8 hidden_power_get_type(pid_t pid);

    /**
     * Returns the base power of hidden power based on a pokemon's pid.
     * @param pid the pid of a pokemon
     * @return its hidden power base power
     */
    u8 hidden_power_get_base_power(pid_t pid);

#ifdef	__cplusplus
}
#endif

#endif	/* ATTACK_H */


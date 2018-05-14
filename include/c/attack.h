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

#ifdef	__cplusplus
}
#endif

#endif	/* ATTACK_H */


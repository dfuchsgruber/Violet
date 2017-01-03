/* 
 * File:   pokeradar.h
 * Author: Domi
 *
 * Created on 9. August 2016, 00:16
 */

#ifndef POKERADAR_H
#define	POKERADAR_H

#include "types.h"
#include "map.h"

#ifdef	__cplusplus
extern "C" {
#endif

#define POKERADAR_VAR_SPECIES 0x50EB
#define POKERADAR_VAR_CNT 0x50EA
#define POKERADAR_VAR_STEP_CNT 0x50E9
#define POKERADAR_VAR_LEVEL 0x50EE
#define POKERADAR_FLAG_SPAWNED 0x917

    extern u8 *script_pokeradar;
    extern u8 *script_pokeradar_alert;
    extern u8 *script_pokeradar_poschange;
    extern u8 *script_pokeradar_flee;

    bool pokeradar_npc_alert(u8 npc_id);
    bool pokeradar_determine_position(coordinate *result);
    void pokeradar_callback_return_to_ow_and_init_script();
    void pokeradar_init(bool is_outdoor);
    u8 pokeradar_prepeare();
    void pokeradar_spawn_pokemon();
    u16 pokeradar_next_seed();
    bool pokeradar_step();

#ifdef	__cplusplus
}
#endif

#endif	/* POKERADAR_H */


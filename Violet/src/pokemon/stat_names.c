/*
 * stat_names.c
 *
 *  Created on: Feb 17, 2019
 *      Author: dominik
 */

#include "constants/pokemon_stat_names.h"
#include "language.h"
#include "pokemon/names.h"
#include "types.h"

u8 *pokemon_get_stat_name(u8 stat) {
    switch (stat) {
        case STAT_HP:
            return pokemon_stat_names[POKEMON_STAT_NAME_HP];
        case STAT_ATTACK:
            return pokemon_stat_names[POKEMON_STAT_NAME_ATTACK];
        case STAT_DEFENSE:
            return pokemon_stat_names[POKEMON_STAT_NAME_DEFENSE];
        case STAT_SPEED:
            return pokemon_stat_names[POKEMON_STAT_NAME_SPEED];
        case STAT_SPECIAL_ATTACK:
            return pokemon_stat_names[POKEMON_STAT_NAME_SPECIAL_ATTACK];
        case STAT_SPECIAL_DEFENSE:
            return pokemon_stat_names[POKEMON_STAT_NAME_SPECIAL_DEFENSE];
        default:
            return 0;
    }
}

u8 pokemon_stat_name_abbreviated_hp[] = LANGDEP(PSTRING("Kp"), PSTRING("Hp"));
u8 pokemon_stat_name_abbreviated_attack[] = LANGDEP(PSTRING("Ang."), PSTRING("Atk."));
u8 pokemon_stat_name_abbreviated_defense[] = LANGDEP(PSTRING("Ver."), PSTRING("Def."));
u8 pokemon_stat_name_abbreviated_special_attack[] = LANGDEP(PSTRING("S.Ang."), PSTRING("S.Atk."));
u8 pokemon_stat_name_abbreviated_special_defense[] = LANGDEP(PSTRING("S.Ver."), PSTRING("S.Def."));
u8 pokemon_stat_name_abbreviated_speed[] = LANGDEP(PSTRING("Init."), PSTRING("Spe."));

u8 *pokemon_stat_names_abbreviated[6] = {
    [STAT_HP] = pokemon_stat_name_abbreviated_hp,
    [STAT_ATTACK] = pokemon_stat_name_abbreviated_attack,
    [STAT_DEFENSE] = pokemon_stat_name_abbreviated_defense,
    [STAT_SPEED] = pokemon_stat_name_abbreviated_speed,
    [STAT_SPECIAL_ATTACK] = pokemon_stat_name_abbreviated_special_attack,
    [STAT_SPECIAL_DEFENSE] = pokemon_stat_name_abbreviated_special_defense};

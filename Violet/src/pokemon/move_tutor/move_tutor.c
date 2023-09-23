#include "types.h"
#include "stdbool.h"
#include "pokemon/moves.h"
#include "constants/attacks.h"
#include "constants/move_tutor.h"

bool move_tutor_is_compatible(u16 species, u8 move_tutor){
    u32 mask = (u32)(1 << move_tutor);
    if(pokemon_move_tutor_compatibility[species] & mask)
        return true;
    return false;
}

const u16 move_tutor_attacks[32] = {
    [MOVE_TUTOR_FOKUSSTOSS] = ATTACK_FOKUSSTOSS,
    [MOVE_TUTOR_GIFTHIEB] = ATTACK_GIFTHIEB,
    [MOVE_TUTOR_FINSTERAURA] = ATTACK_FINSTERAURA,
    [MOVE_TUTOR_EISZAHN] = ATTACK_EISZAHN,
    [MOVE_TUTOR_DONNERZAHN] = ATTACK_DONNERZAHN,
    [MOVE_TUTOR_KREUZSCHERE] = ATTACK_KREUZSCHERE,
    [MOVE_TUTOR_STEINKANTE] = ATTACK_STEINKANTE,
    [MOVE_TUTOR_LICHTKANONE] = ATTACK_LICHTKANONE,
    [MOVE_TUTOR_DRACO_METEOR] = ATTACK_DRACO_METEOR,
    [MOVE_TUTOR_ENERGIEBALL] = ATTACK_ENERGIEBALL,
    [MOVE_TUTOR_DRACHENPULS] = ATTACK_DRACHENPULS,
    [MOVE_TUTOR_FEUERZAHN] = ATTACK_FEUERZAHN,
    [MOVE_TUTOR_EXPLOSION] = ATTACK_EXPLOSION,
    [MOVE_TUTOR_STEINHAGEL] = ATTACK_STEINHAGEL,
    [MOVE_TUTOR_DELEGATOR] = ATTACK_DELEGATOR,
    [MOVE_TUTOR_FLORA_STATUE] = ATTACK_FLORA_STATUE,
    [MOVE_TUTOR_LOHEKANONADE] = ATTACK_LOHEKANONADE,
    [MOVE_TUTOR_AQUAHAUBITZE] = ATTACK_AQUAHAUBITZE,
    [MOVE_TUTOR_DONNERWELLE] = ATTACK_DONNERWELLE,
};

u16 move_tutor_get_attack(u8 move_tutor_idx) {
    return move_tutor_attacks[move_tutor_idx];
}


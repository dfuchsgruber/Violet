#include "constants/abilities.h"
#include "constants/pokemon_attributes.h"
#include "constants/pokemon_statuses.h"
#include "constants/pokemon_types.h"
#include "constants/vars.h"
#include "debug.h"
#include "flags.h"
#include "map/ceometria_gym.h"
#include "overworld/script.h"
#include "pokemon/basestat.h"
#include "pokemon/virtual.h"
#include "save.h"
#include "types.h"
#include "vars.h"

void ceometria_gym_punishment_room_get_script() {
    int room_type = cmem.ceometria_gym_state.next_rooms[*var_access(CEOMETRIA_GYM_NEXT_ROOM)];
    switch (room_type) {
        case CEOMETRIA_GYM_NOTHING:
            overworld_script_virtual_ptr = ow_script_ceometria_gym_punishment_nothing;
            break;
        case CEOMETRIA_GYM_HEALING_ROOM:
            overworld_script_virtual_ptr = ow_script_ceometria_gym_punishment_healing;
            break;
        case CEOMETRIA_GYM_POISON_ROOM:
            overworld_script_virtual_ptr = ow_script_ceometria_gym_punishment_poison;
            break;
        case CEOMETRIA_GYM_BADLY_POISON_ROOM:
            overworld_script_virtual_ptr = ow_script_ceometria_gym_punishment_bad_poison;
            break;
        case CEOMETRIA_GYM_BURNING_ROOM:
            overworld_script_virtual_ptr = ow_script_ceometria_gym_punishment_burn;
            break;
        case CEOMETRIA_GYM_FREEZING_ROOM:
            overworld_script_virtual_ptr = ow_script_ceometria_gym_punishment_freeze;
            break;
        case CEOMETRIA_GYM_PARALYSING_ROOM:
            overworld_script_virtual_ptr = ow_script_ceometria_gym_punishment_paralysis;
            break;
        case CEOMETRIA_GYM_SLEEPING_ROOM:
            overworld_script_virtual_ptr = ow_script_ceometria_gym_punishment_sleep;
            break;
        case CEOMETRIA_GYM_TRAINER_ROOM:
            ceometria_gym_build_trainer_party(41, 44);
            overworld_script_virtual_ptr = ow_script_ceometria_gym_punishment_trainer;
            break;
        case CEOMETRIA_GYM_REDUCE_HP_ROOM:
            overworld_script_virtual_ptr = ow_script_ceometria_gym_punishment_reduce_hp;
            break;
        case CEOMETRIA_GYM_REDUCE_PP_ROOM:
            overworld_script_virtual_ptr = ow_script_ceometria_gym_punishment_reduce_pp;
            break;
        default:
            derrf("Unkown punishment room type %d\n", room_type);
    }
}

void ceometria_gym_punishment_healing() {
    int idx = (u16)ceometria_gym_rnd() % player_pokemon_cnt;
    pokemon_heal(&player_pokemon[idx]);
    dprintf("Healed idx %d\n", idx);
}

s16 ceometria_gym_punishment_get_eligible_index() {
    int room_type = cmem.ceometria_gym_state.next_rooms[*var_access(CEOMETRIA_GYM_NEXT_ROOM)];
    u8 indices[6] = {0};
    int num_eligible = 0;
    for (u8 i = 0; i < player_pokemon_cnt; i++) {
        pokemon *dst = &player_pokemon[i];
        int species = pokemon_get_attribute(dst, ATTRIBUTE_SPECIES2, 0);
        u8 type1 = basestats[species].type1;
        u8 type2 = basestats[species].type2;
        u8 ability = pokemon_get_ability(dst);
        int status = pokemon_get_attribute(dst, ATTRIBUTE_STATUS, 0);
        bool eligible = false;
        switch (room_type) {
            case CEOMETRIA_GYM_BADLY_POISON_ROOM:
            case CEOMETRIA_GYM_POISON_ROOM:
                eligible = type1 != TYPE_GIFT && type2 != TYPE_GIFT && type1 != TYPE_STAHL && type2 != TYPE_STAHL &&
                           ability != IMMUNITAET && pokemon_get_attribute(dst, ATTRIBUTE_CURRENT_HP, 0) > 0 && !(status & STATUS_CONDITION_ANY);
                break;
            case CEOMETRIA_GYM_BURNING_ROOM:
                eligible = type1 != TYPE_FEUER && type2 != TYPE_FEUER && ability != AQUAHUELLE &&
                           pokemon_get_attribute(dst, ATTRIBUTE_CURRENT_HP, 0) > 0 && !(status & STATUS_CONDITION_ANY);
                break;
            case CEOMETRIA_GYM_PARALYSING_ROOM:
                eligible = type1 != TYPE_ELEKTRO && type2 != TYPE_ELEKTRO && ability != FLEXIBILITAET &&
                           pokemon_get_attribute(dst, ATTRIBUTE_CURRENT_HP, 0) > 0 && !(status & STATUS_CONDITION_ANY);
                break;
            case CEOMETRIA_GYM_FREEZING_ROOM:
                eligible = type1 != TYPE_EIS && type2 != TYPE_EIS && ability != MAGMAPANZER &&
                           pokemon_get_attribute(dst, ATTRIBUTE_CURRENT_HP, 0) > 0 && !(status & STATUS_CONDITION_ANY);
                break;
            case CEOMETRIA_GYM_SLEEPING_ROOM:
                eligible = ability != INSOMNIA && ability != MUNTERKEIT &&
                           pokemon_get_attribute(dst, ATTRIBUTE_CURRENT_HP, 0) > 0 && !(status & STATUS_CONDITION_ANY);
                break;
            case CEOMETRIA_GYM_HEALING_ROOM:
                eligible = !pokemon_is_healed(dst);
                break;
            case CEOMETRIA_GYM_REDUCE_HP_ROOM:
                eligible = pokemon_get_attribute(dst, ATTRIBUTE_CURRENT_HP, 0) > 1;
                break;
            case CEOMETRIA_GYM_REDUCE_PP_ROOM: {
                for (u8 j = 0; j < 4; j++) {
                    if (pokemon_get_attribute(dst, (u8)(ATTRIBUTE_PP1 + j), 0) > 0) {
                        eligible = true;
                    }
                }
                break;
            }
        }
        if (eligible) {
            indices[num_eligible++] = i;
        }
    }
    if (num_eligible == 0) {
        return -1;
    } else {
        s16 idx = indices[(u16)ceometria_gym_rnd() % num_eligible];
        dprintf("Eligible party idx %d of %d\n", idx, num_eligible);
        return idx;
    }
}

void ceometria_gym_punishment_apply() {
    pokemon *dst = &player_pokemon[*var_access(0x8004)];
    int status = pokemon_get_attribute(dst, ATTRIBUTE_STATUS, 0);
    int room_type = cmem.ceometria_gym_state.next_rooms[*var_access(CEOMETRIA_GYM_NEXT_ROOM)];
    switch (room_type) {
        case CEOMETRIA_GYM_BADLY_POISON_ROOM:
            status |= STATUS_CONDITION_BAD_POISON;
            break;
        case CEOMETRIA_GYM_POISON_ROOM:
            status |= STATUS_CONDITION_POISON;
            break;
        case CEOMETRIA_GYM_BURNING_ROOM:
            status |= STATUS_CONDITION_BURN;
            break;
        case CEOMETRIA_GYM_FREEZING_ROOM:
            status |= STATUS_CONDITION_FREEZE;
            break;
        case CEOMETRIA_GYM_PARALYSING_ROOM:
            status |= STATUS_CONDITION_PARALYSIS;
            break;
        case CEOMETRIA_GYM_SLEEPING_ROOM:
            status |= ((u16)ceometria_gym_rnd() % 3) + 1;
            break;
        case CEOMETRIA_GYM_HEALING_ROOM:
            pokemon_heal(dst);
            return;
        case CEOMETRIA_GYM_REDUCE_HP_ROOM: {
            int hp = 1;
            pokemon_set_attribute(dst, ATTRIBUTE_CURRENT_HP, &hp);
            return;
        }
        case CEOMETRIA_GYM_REDUCE_PP_ROOM: {
            int pp = 0;
            for (int i = 0; i < 1 + ((u16)ceometria_gym_rnd() % 4); i++) {
                if (pokemon_get_attribute(dst, (u8)(ATTRIBUTE_ATTACK1 + i), 0)) {
                    pokemon_set_attribute(dst, (u8)(ATTRIBUTE_PP1 + i), &pp);
                }
            }
            return;
        }
        default:
            derrf("Unknown room type for punishment %d\n", room_type);
    }
    pokemon_set_attribute(dst, ATTRIBUTE_STATUS, &status);
}

void ceometria_gym_update_scores() {
    int room_type = cmem.ceometria_gym_state.next_rooms[*var_access(CEOMETRIA_GYM_NEXT_ROOM)];
    cmem.ceometria_gym_state.last_room = (u8)(room_type & 0xF);
    switch (room_type) {
        case CEOMETRIA_GYM_NOTHING:
            CEOMETRIA_GYM_NON_TRAINER_SCORE_ADD(20);
            break;
        case CEOMETRIA_GYM_TRAINER_ROOM:
            CEOMETRIA_GYM_PUNISHMENT_SCORE_ADD(11);
            cmem.ceometria_gym_state.non_trainer_score = 0;
            break;
        case CEOMETRIA_GYM_BADLY_POISON_ROOM:
            CEOMETRIA_GYM_PUNISHMENT_SCORE_ADD(12);
            CEOMETRIA_GYM_NON_TRAINER_SCORE_ADD(10);
            break;
        case CEOMETRIA_GYM_FREEZING_ROOM:
            CEOMETRIA_GYM_PUNISHMENT_SCORE_ADD(15);
            CEOMETRIA_GYM_NON_TRAINER_SCORE_ADD(5);
            break;
        case CEOMETRIA_GYM_BURNING_ROOM:
            CEOMETRIA_GYM_PUNISHMENT_SCORE_ADD(10);
            CEOMETRIA_GYM_NON_TRAINER_SCORE_ADD(10);
            break;
        case CEOMETRIA_GYM_PARALYSING_ROOM:
            CEOMETRIA_GYM_PUNISHMENT_SCORE_ADD(8);
            CEOMETRIA_GYM_NON_TRAINER_SCORE_ADD(12);
            break;
        case CEOMETRIA_GYM_SLEEPING_ROOM:
            CEOMETRIA_GYM_PUNISHMENT_SCORE_ADD(15);
            CEOMETRIA_GYM_NON_TRAINER_SCORE_ADD(10);
            break;
        case CEOMETRIA_GYM_HEALING_ROOM:
            cmem.ceometria_gym_state.punishment_score = 0;
            CEOMETRIA_GYM_NON_TRAINER_SCORE_ADD(24);
            break;
        case CEOMETRIA_GYM_REDUCE_HP_ROOM:
            CEOMETRIA_GYM_PUNISHMENT_SCORE_ADD(18);
            CEOMETRIA_GYM_NON_TRAINER_SCORE_ADD(8);
            break;
        case CEOMETRIA_GYM_REDUCE_PP_ROOM:
            CEOMETRIA_GYM_PUNISHMENT_SCORE_ADD(17);
            CEOMETRIA_GYM_NON_TRAINER_SCORE_ADD(15);
            break;
        case CEOMETRIA_GYM_POISON_ROOM:
            CEOMETRIA_GYM_PUNISHMENT_SCORE_ADD(10);
            CEOMETRIA_GYM_NON_TRAINER_SCORE_ADD(12);
            break;
        default:
            derrf("Unknown room type for score updates %d\n", room_type);
    }
    dprintf("Ceometria gym: punishment score %d, non-trainer score %d\n", cmem.ceometria_gym_state.punishment_score, cmem.ceometria_gym_state.non_trainer_score);
}

void ceometria_gym_punishment_room_create_npc() {
    int room_type = cmem.ceometria_gym_state.next_rooms[*var_access(CEOMETRIA_GYM_NEXT_ROOM)];
    switch (room_type) {
        case CEOMETRIA_GYM_NOTHING:
            setflag(16);
            break;
        case CEOMETRIA_GYM_TRAINER_ROOM:
            *var_access(0x4010) = 61;
            break;
        case CEOMETRIA_GYM_POISON_ROOM:
        case CEOMETRIA_GYM_PARALYSING_ROOM:
            *var_access(0x4010) = 26;
            break;
        case CEOMETRIA_GYM_BURNING_ROOM:
            *var_access(0x4010) = 27;
            break;
        case CEOMETRIA_GYM_SLEEPING_ROOM:
            *var_access(0x4010) = 32;
            break;
        case CEOMETRIA_GYM_FREEZING_ROOM:
            *var_access(0x4010) = 35;
            break;
        case CEOMETRIA_GYM_BADLY_POISON_ROOM:
            *var_access(0x4010) = 52;
            break;
        case CEOMETRIA_GYM_REDUCE_HP_ROOM:
        case CEOMETRIA_GYM_REDUCE_PP_ROOM:
            *var_access(0x4010) = 58;
            break;
        case CEOMETRIA_GYM_HEALING_ROOM:
            *var_access(0x4010) = 23;
            break;
    }
}

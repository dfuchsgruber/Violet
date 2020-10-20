#include "types.h"
#include "save.h"
#include "map/ceometria_gym.h"
#include "prng.h"
#include "flags.h"
#include "overworld/script.h"
#include "vars.h"
#include "text.h"
#include "language.h"
#include "debug.h"
#include "constants/vars.h"
#include "constants/species.h"
#include "constants/trainer_builds.h"

u16 ceometria_gym_trainer_pokemon[] = {
    POKEMON_NEBULAK, POKEMON_ALPOLLO, POKEMON_TRAUNFUGIL, POKEMON_TRAUNMAGIL,
    POKEMON_ZWIRRLICHT, POKEMON_ZWIRRKLOP, POKEMON_LICHTEL,
    POKEMON_LATERNECTO, POKEMON_PARAGONI, POKEMON_QUABBEL, POKEMON_APOQUALLYP,
    POKEMON_ZOBIRIS, 0xFFFF
};

void ceometria_gym_build_trainer_party(u8 min_level, u8 max_level) {
    int num_species = 0;
    while (ceometria_gym_trainer_pokemon[num_species] != 0xFFFF) num_species++;
    trainer_pokemon_default_item_default_attacks *dst = (trainer_pokemon_default_item_default_attacks*)&fmem.dynamic_trainer_party;
    for (int i = 0; i < 3; i++) {
        dst[i].species = ceometria_gym_trainer_pokemon[(u16)ceometria_gym_rnd() % num_species];
        dst[i].build.bitfield.build_idx = TRAINER_BUILD_NONE;
        dst[i].level = (u8)(min_level + ((u16)ceometria_gym_rnd() % (max_level - min_level + 1)));
    }
}

u32 ceometria_gym_rnd() {
    return _prng_xorshift(&cmem.ceometria_gym_state.rng_state);
}

void ceometria_gym_initialize() {
    // Seed the gym
    cmem.ceometria_gym_state.rng_state = (u32)(rnd16() | (rnd16() << 16));
    cmem.ceometria_gym_state.waiting_room_cnt = 0;
    cmem.ceometria_gym_state.non_trainer_score = 0;
    cmem.ceometria_gym_state.punishment_score = 0;
    cmem.ceometria_gym_state.last_room = NUM_CEOMETRIA_GYM_ROOM_TYPES;
}

u8 ceometria_gym_overworld_pictures_male[] = {
    27, 32, 26, 30
};

u8 ceometria_gym_overworld_pictures_female[] = {
    23, 28, 35, 58
};

static u8 ceometria_gym_generate_room() {
    u8 room = cmem.ceometria_gym_state.last_room;
    // Try to sample a room differnt than the last room type
    for (int attempts = 0; attempts < 8 && room == cmem.ceometria_gym_state.last_room; attempts++) {
        if ((ceometria_gym_rnd() % CEOMETRIA_GYM_PUNISHMENT_SCORE_MAX) < cmem.ceometria_gym_state.non_trainer_score) {
            room = CEOMETRIA_GYM_TRAINER_ROOM;
        } else if ((ceometria_gym_rnd() % CEOMETRIA_GYM_NON_TRAINER_SCORE_MAX) < cmem.ceometria_gym_state.punishment_score) {
            room = CEOMETRIA_GYM_HEALING_ROOM;
        } else {
            room = (u8)(ceometria_gym_rnd() % NUM_CEOMETRIA_GYM_ROOM_TYPES);
        }
    }
    if (room == NUM_CEOMETRIA_GYM_ROOM_TYPES) derrf("Couldn't sample any room type.\n");
    return room;
}

void ceometria_gym_next_waiting_room() {
    // Determine next rooms
    for (int room_idx = 0; room_idx < 3; room_idx++) {
        cmem.ceometria_gym_state.next_rooms[room_idx] = ceometria_gym_generate_room();
    }
    cmem.ceometria_gym_state.waiting_room_cnt++;
    // Create persons
    for (int i = 0; i < 4; i++) {
        if (ceometria_gym_rnd() & 1) {
            // 50% chance that the person is hidden
            setflag((u16)(16 + i));
        } else {
            cmem.ceometria_gym_state.persons[i].type = ceometria_gym_rnd() & 3;
            cmem.ceometria_gym_state.persons[i].target = (u32)((u16)ceometria_gym_rnd() % 3) & 3;
            cmem.ceometria_gym_state.persons[i].variant = ceometria_gym_rnd() & 7;
            cmem.ceometria_gym_state.persons[i].is_present = ceometria_gym_rnd() & 1;
            if (cmem.ceometria_gym_state.persons[i].is_present) {
                // Create a picture
                bool is_female = cmem.ceometria_gym_state.persons[i].variant >= 4;
                if (is_female) {
                    *var_access((u16)(0x4010 + i)) = ceometria_gym_overworld_pictures_female[ceometria_gym_rnd() & 3];
                } else {
                    *var_access((u16)(0x4010 + i)) = ceometria_gym_overworld_pictures_male[ceometria_gym_rnd() & 3];
                }
            } else {
                setflag((u16)(16 + i));
            }
        }
    }
    // Set trainerflags
    for (u16 i = 0x5F3; i < 0x5FC; i++) {
        clearflag(i);
    }
}


u8 *ceometria_gym_person_scripts_trainerbattle[8] = {
    ow_script_ceometria_gym_trainer_variant_0,
    ow_script_ceometria_gym_trainer_variant_1,
    ow_script_ceometria_gym_trainer_variant_2,
    ow_script_ceometria_gym_trainer_variant_3,
    ow_script_ceometria_gym_trainer_variant_4,
    ow_script_ceometria_gym_trainer_variant_5,
    ow_script_ceometria_gym_trainer_variant_6,
    ow_script_ceometria_gym_trainer_variant_7,
};

u8 *ceometria_gym_person_scripts_say_nothing[8] = {
    ow_script_ceometria_gym_say_nothing_variant_0,
    ow_script_ceometria_gym_say_nothing_variant_1,
    ow_script_ceometria_gym_say_nothing_variant_2,
    ow_script_ceometria_gym_say_nothing_variant_3,
    ow_script_ceometria_gym_say_nothing_variant_4,
    ow_script_ceometria_gym_say_nothing_variant_5,
    ow_script_ceometria_gym_say_nothing_variant_6,
    ow_script_ceometria_gym_say_nothing_variant_7,
};

u8 *ceometria_gym_person_scripts_reveal_room[] = {
    [CEOMETRIA_GYM_NOTHING] = ow_script_ceometria_gym_reveal_room_nothing,
    [CEOMETRIA_GYM_TRAINER_ROOM] = ow_script_ceometria_gym_reveal_room_trainer,
    [CEOMETRIA_GYM_POISON_ROOM] = ow_script_ceometria_gym_reveal_room_poison,
    [CEOMETRIA_GYM_BADLY_POISON_ROOM] = ow_script_ceometria_gym_reveal_room_poison,
    [CEOMETRIA_GYM_FREEZING_ROOM] = ow_script_ceometria_gym_reveal_room_frozen,
    [CEOMETRIA_GYM_BURNING_ROOM] = ow_script_ceometria_gym_reveal_room_burn,
    [CEOMETRIA_GYM_PARALYSING_ROOM] = ow_script_ceometria_gym_reveal_room_paralysis,
    [CEOMETRIA_GYM_SLEEPING_ROOM] = ow_script_ceometria_gym_reveal_room_sleep,
    [CEOMETRIA_GYM_HEALING_ROOM] = ow_script_ceometria_gym_reveal_room_healing,
    [CEOMETRIA_GYM_REDUCE_HP_ROOM] = ow_script_ceometria_gym_reveal_room_reduce_any,
    [CEOMETRIA_GYM_REDUCE_PP_ROOM] = ow_script_ceometria_gym_reveal_room_reduce_any
};

u8 *ceometria_gym_room_hint_room_not_negative[4] = {
    ow_script_ceometria_gym_hint_room_not_negative_variant_0,
    ow_script_ceometria_gym_hint_room_not_negative_variant_1,
    ow_script_ceometria_gym_hint_room_not_negative_variant_2,
    ow_script_ceometria_gym_hint_room_not_negative_variant_3
};

u8 *ceometria_gym_room_hint_room_negative[4] = {
    ow_script_ceometria_gym_hint_room_negative_variant_0,
    ow_script_ceometria_gym_hint_room_negative_variant_1,
    ow_script_ceometria_gym_hint_room_negative_variant_2,
    ow_script_ceometria_gym_hint_room_negative_variant_3
};

void ceometria_gym_person_buffer_target_room() {
    u16 person_idx = *var_access(0x8004);
    switch (cmem.ceometria_gym_state.persons[person_idx].target % 3) {
        case 0: {
            u8 s[] = LANGDEP(PSTRING("linke Raum"), PSTRING("left room"));
            strcpy(buffer0, s);
            break;
        }
        case 1 : {
            u8 s[] = LANGDEP(PSTRING("mittlere Raum"), PSTRING("middle room"));
            strcpy(buffer0, s);
            break;
        }
        case 2 : {
            u8 s[] = LANGDEP(PSTRING("rechte Raum"), PSTRING("right room"));
            strcpy(buffer0, s);
            break;
        }

    }
} 

bool ceometria_gym_room_is_negative(u8 type) {
    switch (type) {
        case CEOMETRIA_GYM_NOTHING:
        case CEOMETRIA_GYM_HEALING_ROOM:
            return false;
        case CEOMETRIA_GYM_TRAINER_ROOM:
        case CEOMETRIA_GYM_BADLY_POISON_ROOM:
        case CEOMETRIA_GYM_FREEZING_ROOM:
        case CEOMETRIA_GYM_BURNING_ROOM:
        case CEOMETRIA_GYM_PARALYSING_ROOM:
        case CEOMETRIA_GYM_SLEEPING_ROOM:
        case CEOMETRIA_GYM_POISON_ROOM:
        case CEOMETRIA_GYM_REDUCE_HP_ROOM:
        case CEOMETRIA_GYM_REDUCE_PP_ROOM:
            return true;
        default:
            derrf("Unkown room type (%d) to hint\n", type);
            return false;
    }
}

void ceometria_gym_waiting_room_person_get_script() {
    u16 person_idx = *var_access(0x8004);
    int variant = cmem.ceometria_gym_state.persons[person_idx].variant % 8;
    int target_room = cmem.ceometria_gym_state.persons[person_idx].target % 3;
    u8 target_room_type = cmem.ceometria_gym_state.next_rooms[target_room];
    dprintf("Type is %d\n", cmem.ceometria_gym_state.persons[person_idx].type);
    switch (cmem.ceometria_gym_state.persons[person_idx].type) {
        case CEOMETRIA_GYM_SAY_NOTHING: {
            overworld_script_virtual_ptr = ceometria_gym_person_scripts_say_nothing[variant];
            break;
        }
        case CEOMETRIA_GYM_TRAINER_BATTLE: {
            ceometria_gym_build_trainer_party(39, 43);
            overworld_script_virtual_ptr = ceometria_gym_person_scripts_trainerbattle[variant];
            break;
        }
        case CEOMETRIA_GYM_REVEAL_ROOM: {
            overworld_script_virtual_ptr = ceometria_gym_person_scripts_reveal_room[target_room_type];
            break;
        }
        case CEOMETRIA_GYM_HINT_ROOM: {
            if (ceometria_gym_room_is_negative(target_room_type)) {
                overworld_script_virtual_ptr = ceometria_gym_room_hint_room_negative[variant & 3];
            } else {
                overworld_script_virtual_ptr = ceometria_gym_room_hint_room_not_negative[variant & 3];
            }
            break;
        }
        default:
            derrf("Unkown person type %d\n", cmem.ceometria_gym_state.persons[person_idx].type);
    }

}

u8 ceometria_gym_get_number_waiting_rooms() {
    return cmem.ceometria_gym_state.waiting_room_cnt;
}
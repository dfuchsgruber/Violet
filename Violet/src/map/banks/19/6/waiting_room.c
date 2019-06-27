#include "types.h"
#include "save.h"
#include "map/ceometria_gym.h"
#include "prng.h"
#include "flags.h"
#include "overworld/script.h"
#include "vars.h"
#include "text.h"
#include "language.h"

u32 ceometria_gym_rnd() {
    return _prng_xorshift(&cmem.ceometria_gym_state.rng_state);
}

void ceometria_gym_initialize() {
    // Seed the gym
    cmem.ceometria_gym_state.rng_state = (u32)(rnd16() | (rnd16() << 16));
    cmem.ceometria_gym_state.waiting_room_cnt = 0;
    ceometria_gym_next_waiting_room();
}

void ceometria_gym_next_waiting_room() {
    // Determine next rooms
    for (int room_idx = 0; room_idx < 3; room_idx++) {
        cmem.ceometria_gym_state.next_rooms[room_idx] = (u8)(ceometria_gym_rnd() % 8);
    }
    cmem.ceometria_gym_state.waiting_room_cnt++;
    // Create persons
    for (int i = 0; i < 4; i++) {
        if (ceometria_gym_rnd() & 1) {
            // 50% chance that the person is hidden
            setflag((u16)(16 + i));
        } else {
            cmem.ceometria_gym_state.persons[i].type = ceometria_gym_rnd() & 3;
            cmem.ceometria_gym_state.persons[i].target = (ceometria_gym_rnd() % 3) & 3;
            cmem.ceometria_gym_state.persons[i].variant = ceometria_gym_rnd() & 15;
        }
    }
    // Set trainerflags
    for (u16 i = 0x5F3; i < 0x5FB; i++) {
        setflag(i);
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

u16 ceometria_gym_person_buffer_target_room() {
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

void ceometria_gym_waiting_room_person_get_script() {
    u16 person_idx = *var_access(0x8004);
    int variant = cmem.ceometria_gym_state.persons[person_idx].variant;
    switch (cmem.ceometria_gym_state.persons[person_idx].type) {
        case CEOMETRIA_GYM_SAY_NOTHING: {
            overworld_script_virtual_ptr = ceometria_gym_person_scripts_say_nothing[variant];
            break;
        }
        case CEOMETRIA_GYM_TRAINER_BATTLE: {
            overworld_script_virtual_ptr = ceometria_gym_person_scripts_trainerbattle[variant];
            break;
        }

    }

}
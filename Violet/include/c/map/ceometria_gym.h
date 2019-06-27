#ifndef H_MAP_CEOMETRIA_GYM
#define H_MAP_CEOMETRIA_GYM

#include "types.h"

enum ceometria_gym_room_types {
    CEOMETRIA_GYM_NOTHING = 0,
    CEOMETRIA_GYM_TRAINER_ROOM = 1,
    CEOMETRIA_GYM_BADLY_POISON_ROOM = 2,
    CEOMETRIA_GYM_FREEZING_ROOM = 3,
    CEOMETRIA_GYM_BURNING_ROOM = 4,
    CEOMETRIA_GYM_PARALYSING_ROOM = 5,
    CEOMETRIA_GYM_SLEEPING_ROOM = 6,
    CEOMETRIA_GYM_HEALING_ROOM = 7
};

enum ceometria_gym_person_types {
    CEOMETRIA_GYM_SAY_NOTHING = 0,
    CEOMETRIA_GYM_REVEAL_ROOM = 1,
    CEOMETRIA_GYM_HINT_ROOM = 2,
    CEOMETRIA_GYM_TRAINER_BATTLE = 3
};

typedef struct {
    u32 rng_state;
    u8 waiting_room_cnt;
    u8 next_rooms[3];
    struct {
        u8 type : 2;
        u8 target : 2;
        u8 variant : 4;
    } persons[4];

} ceometria_gym_state_t;

/**
 * Random Number Generator for the ceometria gym.
 * @return A random 32-bit integer
 **/
u32 ceometria_gym_rnd() ;

/**
 * Initializes the ceometria gym.
 **/
void ceometria_gym_initialize();

/**
 * Initializes the next waiting room and the three following rooms.
 **/
void ceometria_gym_next_waiting_room();

/**
 * Uses var 0x8004 to get the index of the dynamic person to load the script of
 * and loads its script to the virtual ram script location.
 **/
void ceometria_gym_waiting_room_person_get_script();

/**
 * Uses var 0x8004 to get the index of a dynamic person and buffers a string that
 * describes the room the person targets (for revealing its contents) in buffer0.
 **/
void ceometria_gym_person_buffer_target_room();


extern u8 ow_script_ceometria_gym_say_nothing_variant_0[];
extern u8 ow_script_ceometria_gym_say_nothing_variant_1[];
extern u8 ow_script_ceometria_gym_say_nothing_variant_2[];
extern u8 ow_script_ceometria_gym_say_nothing_variant_3[];
extern u8 ow_script_ceometria_gym_say_nothing_variant_4[];
extern u8 ow_script_ceometria_gym_say_nothing_variant_5[];
extern u8 ow_script_ceometria_gym_say_nothing_variant_6[];
extern u8 ow_script_ceometria_gym_say_nothing_variant_7[];
extern u8 ow_script_ceometria_gym_trainer_variant_0[];
extern u8 ow_script_ceometria_gym_trainer_variant_1[];
extern u8 ow_script_ceometria_gym_trainer_variant_2[];
extern u8 ow_script_ceometria_gym_trainer_variant_3[];
extern u8 ow_script_ceometria_gym_trainer_variant_4[];
extern u8 ow_script_ceometria_gym_trainer_variant_5[];
extern u8 ow_script_ceometria_gym_trainer_variant_6[];
extern u8 ow_script_ceometria_gym_trainer_variant_7[];

#endif
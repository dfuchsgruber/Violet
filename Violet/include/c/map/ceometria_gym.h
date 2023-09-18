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
    CEOMETRIA_GYM_HEALING_ROOM = 7,
    CEOMETRIA_GYM_REDUCE_HP_ROOM = 8,
    CEOMETRIA_GYM_REDUCE_PP_ROOM = 9,
    CEOMETRIA_GYM_POISON_ROOM = 10,
    NUM_CEOMETRIA_GYM_ROOM_TYPES,
};

enum ceometria_gym_person_types {
    CEOMETRIA_GYM_SAY_NOTHING = 0,
    CEOMETRIA_GYM_REVEAL_ROOM = 1,
    CEOMETRIA_GYM_HINT_ROOM = 2,
    CEOMETRIA_GYM_TRAINER_BATTLE = 3
};

#define CEOMETRIA_GYM_PUNISHMENT_SCORE_MAX 64
#define CEOMETRIA_GYM_NON_TRAINER_SCORE_MAX 64
#define CEOMETRIA_GYM_PUNISHMENT_SCORE_ADD(x) cmem.ceometria_gym_state.punishment_score = (u8)MIN(cmem.ceometria_gym_state.punishment_score + (x), CEOMETRIA_GYM_PUNISHMENT_SCORE_MAX)
#define CEOMETRIA_GYM_NON_TRAINER_SCORE_ADD(x) cmem.ceometria_gym_state.non_trainer_score = (u8)MIN(cmem.ceometria_gym_state.non_trainer_score + (x), CEOMETRIA_GYM_NON_TRAINER_SCORE_MAX)


typedef struct {
    u32 rng_state;
    u8 waiting_room_cnt : 4;
    u8 last_room : 4;
    u8 punishment_score; // Increases with punishments, makes healing rooms more likely
    u8 non_trainer_score; // Increases with non-trainer rooms, makes trainers more likely
    u8 next_rooms[3];
    struct {
        u8 type : 2;
        u8 target : 2;
        u8 variant : 3;
        u8 is_present : 1;
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

/**
 * Checks if a certain room type resembles a negative room.
 * @param type the room type to check
 * @return if the room type resembles a negative room
 **/
bool ceometria_gym_room_is_negative(u8 type);

/**
 * Creates a virtual dynamic trainer party for trainers in the ceometria gym.
 * @param min_level the minimal level of the party pokemon
 * @param max_level the maximal level of the party pokemon
 **/
void ceometria_gym_build_trainer_party(u8 min_level, u8 max_level);

extern const u8 ow_script_ceometria_gym_say_nothing_variant_0[];
extern const u8 ow_script_ceometria_gym_say_nothing_variant_1[];
extern const u8 ow_script_ceometria_gym_say_nothing_variant_2[];
extern const u8 ow_script_ceometria_gym_say_nothing_variant_3[];
extern const u8 ow_script_ceometria_gym_say_nothing_variant_4[];
extern const u8 ow_script_ceometria_gym_say_nothing_variant_5[];
extern const u8 ow_script_ceometria_gym_say_nothing_variant_6[];
extern const u8 ow_script_ceometria_gym_say_nothing_variant_7[];
extern const u8 ow_script_ceometria_gym_trainer_variant_0[];
extern const u8 ow_script_ceometria_gym_trainer_variant_1[];
extern const u8 ow_script_ceometria_gym_trainer_variant_2[];
extern const u8 ow_script_ceometria_gym_trainer_variant_3[];
extern const u8 ow_script_ceometria_gym_trainer_variant_4[];
extern const u8 ow_script_ceometria_gym_trainer_variant_5[];
extern const u8 ow_script_ceometria_gym_trainer_variant_6[];
extern const u8 ow_script_ceometria_gym_trainer_variant_7[];
extern const u8 ow_script_ceometria_gym_reveal_room_nothing[];
extern const u8 ow_script_ceometria_gym_reveal_room_trainer[];
extern const u8 ow_script_ceometria_gym_reveal_room_poison[];
extern const u8 ow_script_ceometria_gym_reveal_room_sleep[];
extern const u8 ow_script_ceometria_gym_reveal_room_paralysis[];
extern const u8 ow_script_ceometria_gym_reveal_room_burn[];
extern const u8 ow_script_ceometria_gym_reveal_room_frozen[];
extern const u8 ow_script_ceometria_gym_reveal_room_healing[];
extern const u8 ow_script_ceometria_gym_reveal_room_reduce_any[];
extern const u8 ow_script_ceometria_gym_hint_room_not_negative_variant_0[];
extern const u8 ow_script_ceometria_gym_hint_room_not_negative_variant_1[];
extern const u8 ow_script_ceometria_gym_hint_room_not_negative_variant_2[];
extern const u8 ow_script_ceometria_gym_hint_room_not_negative_variant_3[];
extern const u8 ow_script_ceometria_gym_hint_room_negative_variant_0[];
extern const u8 ow_script_ceometria_gym_hint_room_negative_variant_1[];
extern const u8 ow_script_ceometria_gym_hint_room_negative_variant_2[];
extern const u8 ow_script_ceometria_gym_hint_room_negative_variant_3[];
extern const u8 ow_script_ceometria_gym_punishment_nothing[];
extern const u8 ow_script_ceometria_gym_punishment_healing[];
extern const u8 ow_script_ceometria_gym_punishment_poison[];
extern const u8 ow_script_ceometria_gym_punishment_bad_poison[];
extern const u8 ow_script_ceometria_gym_punishment_burn[];
extern const u8 ow_script_ceometria_gym_punishment_sleep[];
extern const u8 ow_script_ceometria_gym_punishment_freeze[];
extern const u8 ow_script_ceometria_gym_punishment_paralysis[];
extern const u8 ow_script_ceometria_gym_punishment_trainer[];
extern const u8 ow_script_ceometria_gym_punishment_reduce_hp[];
extern const u8 ow_script_ceometria_gym_punishment_reduce_pp[];

#endif
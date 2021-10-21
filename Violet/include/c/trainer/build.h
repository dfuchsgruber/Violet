/*
 * build.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_TRAINER_BUILD_H_
#define INCLUDE_C_TRAINER_BUILD_H_

#include "constants/trainer_builds.h"

typedef struct build {
    u8 nature;                // If 255, use random nature
    u8 evs[6];                // If 255, use difficulty and story state dependent evs
    u16 prefered_item;        // Only if the pokemon has no item so far
    u8 hidden_power_type;     // If 255, use random type
    u8 hidden_power_strength; // If 255, use random strength
    u8 use_gender : 1;        // If true, a gender is assigned
    u8 gender;
} trainer_build_t;

trainer_build_t trainer_builds[NUM_TRAINER_BUILDS];

typedef struct build_field {
    u8 build_idx : 5;
    u8 ability : 1; // Note that the ability is only considered for build_idx != 0
    u8 has_hidden_ability : 1;
    u8 is_shiny : 1;

} build_field;

typedef union union_build_field {
    u8 value;
    build_field bitfield;
} union_build_field;

#endif /* INCLUDE_C_TRAINER_BUILD_H_ */

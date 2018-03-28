/*
 * build.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_TRAINER_BUILD_H_
#define INCLUDE_C_TRAINER_BUILD_H_

typedef struct build {
    u8 nature : 5;
    u8 evs[6];
    u16 prefered_item;
} build;

typedef struct build_field {
    u8 build : 5;
    u8 ability : 1;
    u8 hability : 1;
    u8 shinyness : 1;

} build_field;

union union_build_field {
    u8 value;
    build_field bitfield;
};


#endif /* INCLUDE_C_TRAINER_BUILD_H_ */

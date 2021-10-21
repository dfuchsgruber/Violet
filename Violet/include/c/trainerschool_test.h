/* 
 * File:   trainerschool_test.h
 * Author: Domi
 *
 * Created on 26. September 2017, 23:14
 */

#ifndef TRAINERSCHOOL_TEST_H
#define TRAINERSCHOOL_TEST_H

#include "save.h"
#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    u8 answer_cnt;
    u8 correct_answer;
    u8 *question;
    u8 **answers;
} trainerschool_test_question;

typedef struct {
    u8 current_question;
    u8 cursor;
    u8 answer_oam;
    u16 delay;
    u8 frame;
    u16 timer;
    u8 finished;
} trainerschool_test_memory;

trainerschool_test_question trainerschool_test_questions[10];
void trainerschool_test_idle();

#define TRAINER_SCHOOL_TEST_STATE ((trainerschool_test_memory *)(fmem.gp_state))

#ifdef __cplusplus
}
#endif

#endif /* TRAINERSCHOOL_TEST_H */

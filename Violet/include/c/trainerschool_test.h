/* 
 * File:   trainerschool_test.h
 * Author: Domi
 *
 * Created on 26. September 2017, 23:14
 */

#ifndef TRAINERSCHOOL_TEST_H
#define	TRAINERSCHOOL_TEST_H

#include "types.h"
#include "save.h"

#ifdef	__cplusplus
extern "C" {
#endif

    typedef struct {
        u8 answer_cnt;
        u8 correct_answer;
        const u8 *question;
        const u8 *const *const answers;
    } trainerschool_test_question;
    
    typedef struct {
        u8 current_question;
        u8 cursor;
        u8 answer_oam;
        u16 delay;
        u8 frame;
        u16 timer;
        u8 finished;
    } trainerschool_test_state_t;

extern const trainerschool_test_question trainerschool_test_questions [10];
void trainerschool_test_idle();

extern EWRAM trainerschool_test_state_t *trainerschool_test_state;

#ifdef	__cplusplus
}
#endif

#endif	/* TRAINERSCHOOL_TEST_H */


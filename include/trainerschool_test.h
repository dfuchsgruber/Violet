/* 
 * File:   trainerschool_test.h
 * Author: Domi
 *
 * Created on 26. September 2017, 23:14
 */

#ifndef TRAINERSCHOOL_TEST_H
#define	TRAINERSCHOOL_TEST_H

#ifdef	__cplusplus
extern "C" {
#endif

#define TRAINERSCHOOL_CORRECT_ANSWERS 0x50f4
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
        u8 delay;
        u8 frame;
    } trainerschool_test_memory;

trainerschool_test_question trainerschool_test_questions [10];
void trainerschool_test_idle();

#ifdef	__cplusplus
}
#endif

#endif	/* TRAINERSCHOOL_TEST_H */


/* 
 * File:   access_card.h
 * Author: Domi
 *
 * Created on 30. Oktober 2016, 20:04
 */

#ifndef ACCESS_CARD_H
#define ACCESS_CARD_H

#ifdef __cplusplus
extern "C" {
#endif

#include "types.h"

#define ACCESS_CARD_ELEMENT_CNT 4
#define ACCESS_CARD_INDEX_ATRIUM 3

extern u8 **access_card_element_names;

typedef struct {
    u16 flag;
    u8 bank;
    u8 map;
    u8 exit;
    u8 virtual_eg; //used to calculate how long elevating lasts

} access_card_element;

#ifdef __cplusplus
}
#endif

#endif /* ACCESS_CARD_H */

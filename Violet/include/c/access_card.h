/* 
 * File:   access_card.h
 * Author: Domi
 *
 * Created on 30. Oktober 2016, 20:04
 */

#ifndef ACCESS_CARD_H
#define	ACCESS_CARD_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "types.h"

enum {
    ACCESS_CARD_CYBERNETIK = 0,
    ACCESS_CARD_CLOUDS_LAB,
    ACCESS_CARD_FOSSIL,
    ACCESS_CARD_GEHEIMPOWER,
    ACCESS_CARD_ATRIUM,
    ACCESS_CARD_ELEMENT_CNT
};

    typedef struct {
        u16 flag;
        u8 bank;
        u8 map;
        u8 exit;
        u8 virtual_eg; //used to calculate how long elevating lasts
        const u8 *name;
    } access_card_element;




#ifdef	__cplusplus
}
#endif

#endif	/* ACCESS_CARD_H */


/* 
 * File:   present.h
 * Author: Domi
 *
 * Created on 1. Februar 2018, 23:03
 */

#ifndef PRESENT_H
#define	PRESENT_H

#include "types.h"


#ifdef	__cplusplus
extern "C" {
#endif

    /*
     * SHA3 Section
     */
    
    #define SHA3_MDLEN 8
    #define SHA3_INLEN 32
    
    typedef struct{
        union{
            u8 bytes[200];
            u64 dwords[25];
        } state;
        int bitrate, mdlen;
    } sha3_state;
    
    #define ROT64(x,y) (((x) << (y)) | ((x) >> ((sizeof(u64) * 8) - (y))))
    
    /**
     * SHA3 hash for in
     * @param in byte array of size SHA3_INLEN
     * @param md byte array of size SHA3_MDLEN
     * @return md
     */
    u8 *sha3(u8 *in, u8 *md);
    
    /*
     * Present section
     */
    
    typedef struct{
        u8 field_0;
        u8 field_1;
        u8 icon_initializer;
        u8 field_3;
        u8 field_4;
        u8 field_5;
        u8 field_6;
        u8 field_7;
        u8 *query_string;
    } pstring_query_string;

    pstring_query_string *pstring_query_strings[6];

    typedef struct{
        u8 md[SHA3_MDLEN];
        u8 *script;
    } present_t;
    
    
#ifdef	__cplusplus
}
#endif

#endif	/* PRESENT_H */


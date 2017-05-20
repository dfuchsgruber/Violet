/* 
 * File:   language.h
 * Author: Domi
 *
 * Created on 2. Mai 2017, 20:06
 */

#ifndef LANGUAGE_H
#define	LANGUAGE_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#define P99_PROCTECT(...) __VA_ARGS__
    
    #define GER 0
    #define EN 1

    #define LANGUAGE GER

    #if LANGUAGE==GER
    #define PSTRING(ger,en) ger
    #else
    #define PSTRING(ger,en) en
    #endif    
    
    



#ifdef	__cplusplus
}
#endif

#endif	/* LANGUAGE_H */


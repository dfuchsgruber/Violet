#include "types.h"
#include "romfuncs.h"
#include "basestats.h"
#include "pstring.h"
#include "present.h"
#include "utils.h"

extern u8 str_present_query[];

pstring_query_string pstring_query_string_present = {
    0,
    10,
    3,
    1,
    1,
    0,
    0,
    0,
    str_present_query
};
    
pstring_query_string *pstring_query_strings[] = {
    (pstring_query_string *) 0x083E195C,
    (pstring_query_string *) 0x083E1968,
    (pstring_query_string *) 0x083E1974,
    (pstring_query_string *) 0x083E1974,
    (pstring_query_string *) 0x083E1980,
    &pstring_query_string_present
};

void (*pstring_query_string_initializers[])() = {
    (void(*)())(0x809F584 | 1),
    (void(*)())(0x809F584 | 1),
    (void(*)())(0x809F5D8 | 1),
    (void(*)())(0x809F5D8 | 1),
    (void(*)())(0x809F584 | 1),
    // String initializer for present also is std print string initializer
    (void(*)())(0x809F584 | 1)
};

void closure(){
    
    // The input is the inputed string extended by this arbitrary salt
    u8 input[SHA3_INLEN] = {
        224, 36, 30, 106, 254, 80, 213, 241, 25, 136, 35, 3, 132, 229, 10, 248, 
        166, 138, 11, 177, 77, 6, 255, 203, 229, 77, 4, 199, 170, 186, 33, 88 
    };
    strcpy(input, buffer0);
    u8 md[SHA3_MDLEN] = {0};
    sha3(input, md);
    
    dprintf("\n");
    for(int i = 0; i < SHA3_MDLEN; i++)
        dprintf(" %x ", md[SHA3_MDLEN - i - 1]);
    dprintf("SHA3 is ");
    
    void (*std_closure_and_map_reload)() = (void(*)())(0x08056900 | 1);
    std_closure_and_map_reload();
}

void special_query_present_code(){
    pokemon_query_string(5, buffer0, POKEMON_BOTOGEL, 0xFF, 0, closure);
}

#include "types.h"
#include "present.h"
#include "text.h"
#include "overworld/script.h"
#include "constants/species.h"
#include "language.h"
#include "agbmemory.h"
#include "vars.h"
#include "debug.h"

const u8 str_present_query[] = LANGDEP(
    PSTRING("Geschenkcode?"),
    PSTRING("Present Code?"));

const pstring_query_string pstring_query_string_present = {
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
    
const pstring_query_string *const pstring_query_strings[] = {
    (const pstring_query_string *) 0x083E195C,
    (const pstring_query_string *) 0x083E1968,
    (const pstring_query_string *) 0x083E1974,
    (const pstring_query_string *) 0x083E1974,
    (const pstring_query_string *) 0x083E1980,
    &pstring_query_string_present
};

void (*const pstring_query_string_initializers[])() = {
    (void(*)())(0x809F584 | 1),
    (void(*)())(0x809F584 | 1),
    (void(*)())(0x809F5D8 | 1),
    (void(*)())(0x809F5D8 | 1),
    (void(*)())(0x809F584 | 1),
    // String initializer for present also is std print string initializer
    (void(*)())(0x809F584 | 1)
};

extern const u8 ow_script_present_0[];
extern const u8 ow_script_present_purple_kecleon[];

const present_t presents[NUM_PRESENTS] = {
    {
        {0x62, 0xb7, 0xfb, 0xdf, 0xfa, 0x6a, 0x4e, 0x18},
        ow_script_present_0     
    },
	{
		{214, 45, 234, 154, 148, 135, 48, 215},
		ow_script_present_purple_kecleon
	}
};

static const u8 *present_get_matching_md(const u8 *md){
    for(int i = 0; i < NUM_PRESENTS; i++){
        //DEBUG("Checking present %d\n", i);
        bool matched = true;
        for(int j = 0; j < SHA3_MDLEN; j++){
            //DEBUG("Input md: %d, Expected md: %d\n", md[j], presents[i].md[j]);
            if(presents[i].md[j] != md[j]){
                matched = false;
                break;
            }
        }
        if(matched)
            return presents[i].script;
    }
    return NULL;
}

void present_query_closure(){
    if (buffer0[0] == 0xFF) {
        *var_access(0x800D) = 0xFF;
    } else {        
        // The input is the inputed string extended by this arbitrary salt
        u8 input[SHA3_INLEN] = {
            224, 36, 30, 106, 254, 80, 213, 241, 25, 136, 35, 3, 132, 229, 10, 248, 
            166, 138, 11, 177, 77, 6, 255, 203, 229, 77, 4, 199, 170, 186, 33, 88 
        };
        strcpy(input, buffer0);
        u8 md[SHA3_MDLEN] = {0};
        sha3(input, md);
        for (int i = 0; i < SHA3_MDLEN; i++) {
            DEBUG("Input md[%d]: %d\n", i, md[i]);
        }
        
        
        const u8 *script = present_get_matching_md(md);
        if(script){
            overworld_script_virtual_ptr = script;
            *var_access(0x800D) = 1;
        }else{
            *var_access(0x800D) = 0;
        }
    }
    
    void (*std_closure_and_map_reload)() = (void(*)())(0x08056900 | 1);
    std_closure_and_map_reload();
}

void special_query_present_code(){
    memset(buffer0, 0xFF, 11);
    pokemon_query_string(5, buffer0, POKEMON_BOTOGEL, 0xFF, 0, present_query_closure);
}

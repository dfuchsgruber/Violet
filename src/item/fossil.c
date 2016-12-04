#include "types.h"
#include "romfuncs.h"
#include "misc.h"
#include "basestats.h"
#include "item.h"
#include "map.h"
#include "save.h"
#include "rtc.h"


u16 fossils [5] = {
    ITEM_ALTBERNSTEIN,
    ITEM_DOMFOSSIL,
    ITEM_HELIXFOSSIL,
    ITEM_KLAUENFOSSIL,
    ITEM_WURZELFOSSIL
};

u16 fossil_species[5] = {
    POKEMON_AERODACTYL,
    POKEMON_KABUTO,
    POKEMON_AMONITAS,
    POKEMON_ANORITH,
    POKEMON_LILIEP
};

void fossil_print_multichoice() {

    //iterate through all access cards
    u8 **d_elements = cmalloc(sizeof (u8*) * 5);
    int i;
    u16 displayed = 0;
    for (i = 0; i < 5; i++) {
        if(checkitem(fossils[i], 1)){
            d_elements[displayed++] = items[fossils[i]].name;
        }
    }
    
    *vardecrypt(0x4077) = displayed;
    if (displayed) {
        void **script_state_pointers = (void**) 0x03000F14;
        *script_state_pointers = d_elements;
        if (multichoice(0, 0, 0, false)) {
            script_halt();
        }
    }
    free(d_elements);
}

void fossil_execute() {
    *vardecrypt(0x4077) = 0;
    int index = *vardecrypt(0x800D);
    int i;
    for (i = 0; i < 5; i++) {
        if(!checkitem(fossils[i], 1)) continue;
        if (index) {
            index--;
        } else {
            if(rtc_test()){
                rtc_read(&cmem->fossil_gen_time);
                item_remove(fossils[i], 1);
                *vardecrypt(0x8004) = fossils[i];
                *vardecrypt(0x50D1) = fossil_species[i];
            }else{
                *vardecrypt(0x8004) = 0;
            }
        }
    }
}

u16 fossil_is_finished(){
    rtc_timestamp t;
    rtc_read(&t);
    int seconds_current = rtc_timestamp_to_seconds(&t);
    int seconds_generated = rtc_timestamp_to_seconds(&cmem->fossil_gen_time);
    if(seconds_current - seconds_generated > 60*60){
        return 1;
    }else{
        return 0;
    }
}

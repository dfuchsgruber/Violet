#include "types.h"
#include "constants/items.h"
#include "item/item.h"
#include "constants/species.h"
#include "multichoice.h"
#include "save.h"
#include "rtc.h"
#include "debug.h"
#include "access_card.h"
#include "vars.h"
#include "item/item.h"
#include "overworld/script.h"

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

    // Return 1 for success and 0 for failure
    u16 *lastresult = var_access(0x800D);
    *lastresult = 0;
    
    // Iterate through all possible fossils
    dynamic_multichoice_t choices[5];
    int i;
    u16 displayed = 0;
    for (i = 0; i < 5; i++) {
        if(item_check(fossils[i], 1)){
            choices[displayed].text = items[fossils[i]].name;
            choices[displayed].field_4 = 0;
            displayed++;
        }
    }
    
    *var_access(0x4077) = displayed;
    dprintf("Displaying %d choices\n", displayed);
    if (displayed) {
        void **script_state_pointers = (void**) 0x03000F14;
        *script_state_pointers = choices;
        if (multichoice(0, 0, 0, false)) {
            dprintf("Halting for dchoice\n");
            overworld_script_halt();
            *lastresult = 1;
        }
    }
}

void fossil_execute() {
    *var_access(0x4077) = 0;
    int index = *var_access(0x800D);
    int i;
    for (i = 0; i < 5; i++) {
        if(!item_check(fossils[i], 1)) continue;
        if (index) {
            index--;
        } else {
            if(rtc_test()){
                rtc_read(&cmem->fossil_gen_time);
                item_remove(fossils[i], 1);
                *var_access(0x8004) = fossils[i];
                *var_access(0x50D1) = fossil_species[i];
            }else{
                *var_access(0x8004) = 0;
            }
        }
    }
}

u16 fossil_is_finished(){
    rtc_timestamp t;
    rtc_read(&t);
    u64 seconds_current = rtc_timestamp_to_seconds(&t);
    u64 seconds_generated = rtc_timestamp_to_seconds(&cmem->fossil_gen_time);
    if(seconds_current - seconds_generated > 60*60){
        return 1;
    }else{
        return 0;
    }
}

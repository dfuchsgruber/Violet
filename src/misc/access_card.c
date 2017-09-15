#include "types.h"
#include "romfuncs.h"
#include "misc.h"
#include "map.h"
#include "access_card.h"


access_card_element access_card_elements [ACCESS_CARD_ELEMENT_CNT] = {
    {0, 9, 13, 0, 8}, //Cybernetik
    {FLAG_ACCESS_CARD_FOSSIL, 9, 15, 0, 3}, //Fossil
    {0, 9, 14, 1, 0} //Atrium
};

void access_card_print_multichoice() {

    //iterate through all access cards
    u8 **d_elements = cmalloc(sizeof (u8*) * ACCESS_CARD_ELEMENT_CNT);
    int i;
    u16 displayed = 0;
    for (i = 0; i < ACCESS_CARD_ELEMENT_CNT; i++) {
        if (access_card_elements[i].flag) {
            if (!checkflag(access_card_elements[i].flag)) continue;
        }
        d_elements[displayed++] = access_card_element_names[i];
    }
    if (displayed) {
        *vardecrypt(0x4077) = displayed;
        void **script_state_pointers = (void**) 0x03000F14;
        *script_state_pointers = d_elements;
        if (multichoice(0, 0, 0, false)) {
            script_halt();
        }
    }
    free(d_elements);
}

void access_card_execute_elevator() {
    *vardecrypt(0x4077) = 0;
    int index = *vardecrypt(0x800D);
    int i;
    for (i = 0; i < ACCESS_CARD_ELEMENT_CNT; i++) {
        if (access_card_elements[i].flag) {
            if (!checkflag(access_card_elements[i].flag)) continue;
        }
        if (index) {
            index--;
        } else {

            u16 *current_eg = vardecrypt(0x50D3);
            *vardecrypt(0x8006) = access_card_elements[*current_eg].virtual_eg;
            *vardecrypt(0x8005) = access_card_elements[i].virtual_eg;
            //We reached the table entry we looked for
            if (*current_eg == i) {
                *vardecrypt(0x800D) = 0;
            } else {
                *current_eg = (u16) i;
                *vardecrypt(0x800D) = 1;
            }
            map_event_warp w = get_mapheader(access_card_elements[i].bank, access_card_elements[i].map)->events->warps[access_card_elements[i].exit];

            warp_history_set(0, access_card_elements[i].bank, access_card_elements[i].map, 0xFF, w.x, w.y);
            break;

        }
    }
}

void access_card_init_by_atrium() {
    *vardecrypt(0x50D3) = ACCESS_CARD_INDEX_ATRIUM;
}

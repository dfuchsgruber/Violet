#include "access_card.h"
#include "agbmemory.h"
#include "constants/flags.h"
#include "constants/vars.h"
#include "flags.h"
#include "list_menu.h"
#include "map/header.h"
#include "multichoice.h"
#include "overworld/map_control.h"
#include "overworld/script.h"
#include "types.h"
#include "vars.h"

access_card_element access_card_elements[ACCESS_CARD_ELEMENT_CNT] = {
    {0, 9, 13, 0, 8},                        // Cybernetik
    {ORINA_CITY_VIOLET_GRUNTS, 9, 15, 0, 3}, // Fossil
    {SECRET_POWER_LAB_ACCESS, 9, 19, 0, 2},  // Geheimpower
    {0, 9, 14, 1, 0}                         // Atrium
};

void access_card_print_multichoice() {

    //iterate through all access cards
    list_menu_item *d_elements = malloc_and_clear(sizeof(list_menu_item) * ACCESS_CARD_ELEMENT_CNT);
    int i;
    u16 displayed = 0;
    for (i = 0; i < ACCESS_CARD_ELEMENT_CNT; i++) {
        if (access_card_elements[i].flag) {
            if (!checkflag(access_card_elements[i].flag))
                continue;
        }
        d_elements[displayed++].text = access_card_element_names[i];
    }
    if (displayed) {
        *var_access(DYN_MULTICHOICE_ITEM_CNT) = displayed;
        overworld_script_state.pointer_banks[0] = (u8 *)d_elements;
        if (multichoice(0, 0, 0, false)) {
            overworld_script_halt();
        }
    }
    free(d_elements);
}

void access_card_execute_elevator() {
    *var_access(DYN_MULTICHOICE_ITEM_CNT) = 0;
    int index = *var_access(0x800D);
    int i;
    for (i = 0; i < ACCESS_CARD_ELEMENT_CNT; i++) {
        if (access_card_elements[i].flag) {
            if (!checkflag(access_card_elements[i].flag))
                continue;
        }
        if (index) {
            index--;
        } else {

            u16 *current_eg = var_access(LAZ_CORP_CURRENT_LEVEL);
            *var_access(0x8006) = access_card_elements[*current_eg].virtual_eg;
            *var_access(0x8005) = access_card_elements[i].virtual_eg;
            //We reached the table entry we looked for
            if (*current_eg == i) {
                *var_access(0x800D) = 0;
            } else {
                *current_eg = (u16)i;
                *var_access(0x800D) = 1;
            }
            map_event_warp w = get_mapheader(access_card_elements[i].bank, access_card_elements[i].map)->events->warps[access_card_elements[i].exit];

            warp_last_map_set(0, access_card_elements[i].bank, access_card_elements[i].map, 0xFF, w.x, w.y);
            break;
        }
    }
}

void access_card_init_by_atrium() {
    *var_access(LAZ_CORP_CURRENT_LEVEL) = ACCESS_CARD_INDEX_ATRIUM;
}

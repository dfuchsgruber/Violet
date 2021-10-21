#include "callbacks.h"
#include "constants/flags.h"
#include "constants/vars.h"
#include "flags.h"
#include "item/item.h"
#include "language.h"
#include "text.h"
#include "types.h"
#include "vars.h"

u8 str_item_ashbag[] = LANGDEP(
    PSTRING("In der Aschetasche befindet\nsich BUFFER_1 Asche.PAUSE_UNTIL_PRESS"),
    PSTRING("The ashbag containsBUFFER_1\nashes.PAUSE_UNTIL_PRESS"));

void item_ashbag_field(u8 self) {
    itoa(buffer0, *var_access(ASH), 0, 5);
    string_decrypt(strbuf, str_item_ashbag);
    u8 n = (u8)big_callbacks[self].params[3];
    item_print_string(self, n, 4, strbuf);
}

bool special_ash_can_store() {
    u16 *ash = var_access(ASH);
    u16 *picked_up = var_access(0x8006);
    *picked_up = (u16)(*picked_up * 50);
    if (*ash + *picked_up <= 50000 && checkflag(ASHBAG_RECEIVED)) {
        *ash = (u16)(*ash + *picked_up);
        return 1;
    } else {
        return 0;
    }
}

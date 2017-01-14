#include "types.h"
#include "romfuncs.h"
#include "callbacks.h"
#include "text.h"
#include "item.h"
#include "tile.h"

extern u8 *str_item_ashbag_ref;

void item_ashbag_field(u8 self){
    value_to_str(buffer0, *vardecrypt(VAR_ASH), 0, 5);
    string_decrypt(strbuf, str_item_ashbag_ref);
    u8 n = (u8)big_callbacks[self].params[3];
    item_printstr(self, n, 4, strbuf);
}

bool special_ash_can_store(){
    u16 *ash = vardecrypt(VAR_ASH);
    u16 *picked_up = vardecrypt(0x8006);
    *picked_up = (u16)(*picked_up * 50);
    if(*ash+*picked_up <= 50000 && checkflag(FLAG_ASHBAG)){
        *ash = (u16)(*ash + *picked_up);
        return 1;
    }else{
        return 0;
    }
}

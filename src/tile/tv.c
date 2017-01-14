#include "types.h"
#include "romfuncs.h"
#include "tile.h"


//Text format :=...Es laufen [XXX]:YYYYYYY....
//Beispiel: Es laeuft eine Doku: Blablabla

void load_tv_text() {

    u8 **ptrbank0 = (u8**) 0x03000f14;
    *ptrbank0 = get_tv_text();

}

extern u8 str_tv_albus[];
extern u8 str_tv_violet[];

u8 *get_tv_text() {

    u16 story_prog = *vardecrypt(0x4051);
    if (story_prog < 0xB) {
        return (u8*) 0x08927118; //Sendung Uli und Klaus
    }
    if (story_prog < 0x15) {
        return (u8*) 0x089273CA; //Nachrichten: Primus entfuehrt
    }
    if (story_prog < 0x1D) {
        return (u8*) 0x08927535; //History-Doku: Atkania Reportage
    }
    if (story_prog < 0x22){
        return str_tv_albus;
    }
    return str_tv_violet;
}

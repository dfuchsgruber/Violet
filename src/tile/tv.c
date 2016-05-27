#include "types.h"
#include "romfuncs.h"
#include "tile.h"


//Text format :=...Es laufen [XXX]:YYYYYYY....
//Beispiel: Es läuft eine Doku: Blablabla

void load_tv_text(){
	
	u8 **ptrbank0 = (u8**)0x03000f14;
	*ptrbank0 = get_tv_text();
	
}

u8 *get_tv_text(){
	
	u16 story_prog = *vardecrypt(0x4051);
	if (story_prog < 0xB){
		return (u8*)0x08927118; //Sendung Uli und Klaus
	}
	if (story_prog < 0x15){
		return (u8*)0x089273CA; //Nachrichten: Primus entführt
	}
	if (story_prog < 0x1D){
		return (u8*)0x08927535; //History-Doku: Atkania Reportage
	}
	return (u8*)0x08927535;
}

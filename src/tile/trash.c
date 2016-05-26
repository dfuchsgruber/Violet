#include "../header/types.h"
#include "../header/romfuncs.h"
#include "../header/save.h"
#include "../header/item.h"

void special_set_trashflag();
void generate_trash_item(u8 facing);
bool check_trashflag(u8 facing);
void set_trashflag(u8 facing);
int get_trash_hash_by_facing(u8 facing, int m);
int hash_trash(s16 x, s16 y, u8 map, u8 bank, int m);
void new_trash_vector();

void generate_trash_item(u8 facing){
	
	u16 item = 0;
	if (!check_trashflag(facing)){
		
		int hash = get_trash_hash_by_facing(facing, 97);
		if (hash <= 2){
			//Leftovers
			item = ITEM_UEBERRESTE;
		}else if(hash < 8){
			//Rare berries
			int berry_index = get_trash_hash_by_facing(facing, 7);
			item = (u16)(ITEM_LYDZIBEERE + berry_index);
		}else if(hash < 20){
			//Common berries
			int berry_index = get_trash_hash_by_facing(facing, 11);
			item = (u16)(ITEM_AMRENABEERE + berry_index);
		}
	}
	*vardecrypt(0x8000) = item;
}

void special_set_trashflag(){
	set_trashflag((u8)(*vardecrypt(0x800C)));
}

bool check_trashflag(u8 facing){
	
	int hashflag = get_trash_hash_by_facing(facing, 127);
	int mask = 1 << (hashflag & 7);
	int value = dmem->trash_flags[hashflag >> 3] & mask;
	return value != 0;
}

void set_trashflag(u8 facing){
	int hashflag = get_trash_hash_by_facing(facing, 127);
	u8 mask = (u8) (1 << (hashflag & 7));
	dmem->trash_flags[hashflag >> 3] |= mask;
}


int get_trash_hash_by_facing(u8 facing, int m){
	
	s16 pos[2];
	get_current_tile_position(&pos[0], &pos[1]);
	switch(facing){
		case 1://down
			pos[1]++;
			break;
		case 2://up
			pos[1]--;
			break;
		case 3://left
			pos[0]--;
			break;
		case 4:
			pos[0]++;
			break;
	}
	return hash_trash(pos[0], pos[1], (*save1)->map,(*save1)->bank, m);
}

/**
* returns hash value of trash from 0 to m-1
**/
int hash_trash(s16 x, s16 y, u8 map, u8 bank, int m){
	
	//First we get the a-vector
	u8 a[4];
	
	u16 a_component_0 = *vardecrypt(0x50DE);
	u16 a_component_1 = *vardecrypt(0x50DD);
	
	a[0] = (u8)a_component_0;
	a[1] = (u8)(a_component_0 >> 8);
	a[2] = (u8)a_component_1;
	a[3] = (u8)(a_component_1 >> 8);
	
	int h = (x * a[0]) + (y * a[1]) + (map * a[2]) + (bank * a[3]);
	return (int)__umod((u32)h, (u32)m);
	
	
}

void new_trash_vector(){
	
	u32 val;
	do {val = (u32)(random_change_seed() | (random_change_seed() << 16));} while(!val);
	*vardecrypt(0x50DE) = (u16)val;
	*vardecrypt(0x50DD) = (u16)(val >> 16);
	
}


#ifndef H_TILE
#define H_TILE

#define DESERT_MAP 21
#define DESERT_BANK 3

#include <stdbool.h>

typedef struct bdata{
	
		u32 behavior : 9;
		u32 field_1 : 5;
		u32 field_2 : 4;
		u32 field_3 : 6;
		u32 field_4 : 3;
		u32 field_5 : 2;
		u32 field_6 : 3;
		u32 field_7 : 1;
	
}bdata;

typedef union union_block_data{
	bdata data;
	u32 value;
} block_data;

typedef struct morgana_anim {
	u16 blocks[4];
	u16 walkfield;
} morgana_anim;


void do_fata_morgana ();

void special_set_trashflag();
void generate_trash_item(u8 facing);
bool check_trashflag(u8 facing);
void set_trashflag(u8 facing);
int get_trash_hash_by_facing(u8 facing, int m);
int a_hash(s16 x, s16 y, u8 map, u8 bank, int m);
void new_a_vector();

void load_tv_text();
u8 *get_tv_text();

#endif
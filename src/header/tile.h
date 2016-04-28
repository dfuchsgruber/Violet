#ifndef H_TILE
#define H_TILE

#include "types.h"

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




#endif
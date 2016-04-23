#include "../../header/dungeon_generator.h"
#include "../../header/map.h"
#include "../../header/types.h"
#include "../../header/save.h"
#include "../../header/romfuncs.h"

void compute_dungeon_blocks();
void compute_rooms(dungeon_generator *d);

u32 random_next32 (dungeon_generator *d);
u16 random_next16 (dungeon_generator *d);
u8 random_next8 (dungeon_generator *d);


void compute_rooms(dungeon_generator *d){
	
	u32 i;
	
	u32 rooms_max = (u32)(d->rooms_per_line * d->rooms_per_row); 
	d->rooms = (room*)malloc(sizeof(room) * rooms_max);
	
	//calculate room size
	u32 hsegment_cnt = (u32)(d->rooms_per_line * 2 - 1);
	u32 vsegment_cnt = (u32)(d->rooms_per_row * 2 - 1);
	u32 hsegment_size = (u32)(d->width / hsegment_cnt);
	u32 vsegment_size = (u32)(d->height / vsegment_cnt);
	

	u16 room_asize_x =(u16)((u16)(d->width-4) / hsegment_cnt);
	u16 room_asize_y =(u16)((u16)(d->height-4) /vsegment_cnt);
	
	u32 rooms_built;
	do{
		
		rooms_built = 0;
		
		//now we build the rooms
		for (i = 0; i < rooms_max; i++){
			
				//room parameters are calculated
				d->rooms[i].width = room_asize_x;
				d->rooms[i].height = room_asize_y;
				
				//for the x and y coordinates it gets tricky, the segment id is 2 * i
				u32 room_y = i / (d->rooms_per_line);
				u32 room_x = __umod( (u32)i, d->rooms_per_line);
				
				d->rooms[i].x = (s16)(room_x * 2 * hsegment_size);
				d->rooms[i].y = (s16)(room_y * 2 * vsegment_size);
				d->rooms[i].area = (u8)rooms_built;
			
			//decide weather to build a room
			if (random_next8(d) <= d->room_frequency){
				
				//room will be built
				d->rooms[i].presence = true;
				//(*((u16*)0x020370D0))++;
				rooms_built++;
				
			}else{
				d->rooms[i].presence = false;
			}
		}
		
	}while(rooms_built < (d->min_rooms));
	
	//Now we draw rooms
	for (i = 0; i < rooms_max; i++){
		int x, y;
		for (x = 0; x < d->rooms[i].width; x++){
			for (y = 0; y < d->rooms[i].width; y++){
				if (d->rooms[i].presence){
					set_block_id((s16)(d->rooms[i].x + x + 7), (s16)(d->rooms[i].y + y + 7), 20);
				}
			}
		}
	}
	
}


void compute_dungeon_blocks(){
	
	if (dflags->blocks_initialized){
		//The blocks were already loaded, so we use the same seed
		dmem->dgen.seed = dmem->dgen.initial_seed;
	}
	
	dflags->blocks_initialized = 1;
	
	dungeon_generator *d = &(dmem->dgen);
	
	//first we compute the dungeon
	compute_rooms(d);
	
	foot_ddata->footer = &(dmem->footer);
	//special_x8E_update_map_graphics();
	
}





u32 random_next32 (dungeon_generator *d){
	return (u32)((random_next16(d) << 16) | random_next16(d));
}

u16 random_next16 (dungeon_generator *d){
	d->seed = (u32)(d->seed * 0x41C64E6D + 0x6073);
	return (u16)(d->seed >> 16);
}

u8 random_next8(dungeon_generator *d){
	return (u8)random_next16(d);
}
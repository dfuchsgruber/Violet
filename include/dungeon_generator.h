#ifndef H_DUNGEON_GENERATE
#define H_DUNGEON_GENERATE

#include "types.h"
#include "map.h"
#include <stdbool.h>

#define SEG_A (1 << 7)
#define SEG_B (1 << 6)
#define SEG_C (1 << 5)
#define SEG_D (1 << 4)
#define SEG_E (1 << 3)
#define SEG_F (1 << 2)
#define SEG_G (1 << 1)
#define SEG_H (1 << 0)

#define FLAG_LOAD_DMAP 0x922
#define SIMPLE_GIVEITEM_SCRIPT(item) O_SCRIPT_COPYVARIFNOTZERO(0x8000, item), O_SCRIPT_COPYVARIFNOTZERO(0x8001, 1), O_SCRIPT_CALLSTD(1), O_SCRIPT_END

typedef struct room {
    u16 width;
    u16 height;
    s16 x;
    s16 y;
    s16 connector_x;
    s16 connector_y;
    bool is_person_located;
    bool presence;
    u8 roomx;
    u8 roomy;
    u8 region;
} room;

typedef struct dungeon_generator {
    u32 seed;
    u32 initial_seed;

    u8 from_bank;
    u8 from_map;
    s16 from_x;
    s16 from_y;
    u8 facing;

    map_data *map;
    u16 width;
    u16 height;
    u16 rooms_per_line;
    u16 rooms_per_row;
    u8 room_frequency; //is devided by 256
    u8 min_rooms;
    room *rooms;
    u8 regions;
    u8 *dbuf;
    
    u8 additional_connection_attempts;


} dungeon_generator;

typedef struct dungeon_data {
    u8 is_dungeon_generated;
    u8 room_frequency;
    u8 rooms_per_line;
    u8 rooms_per_row;
    u16 width;
    u16 height;
    u32 seed;


} dungeon_data;

typedef struct dungeon_flags {
    u8 header_initialized : 1;
    u8 blocks_initialized : 1;
    u8 other : 6;
} dungeon_flags;

typedef struct neighbours {
    u8 down;
    u8 up;
    u8 left;
    u8 right;
} neighbours;

union union_neighbours {
    neighbours n;
    u32 value;
};

dungeon_flags *dflags = (dungeon_flags*) 0x203CEC4;

int dungeon_get_type();

bool dungeon_crash();
bool special_dungeon_warpback();
void dungeon_store_current_pos();
void dungeon_relocate_room_connector(u8 r, dungeon_generator *d);
void dungeon_compute_blocks();
void compute_dungeon_rooms(dungeon_generator *d);
void dungeon_compute_paths(dungeon_generator *d);
void dungeon_compute_tile_map(dungeon_generator *d);
void dungeon_relocate_events(dungeon_generator *d);

void dungeon_set_block_passable(s16 x, s16 y, dungeon_generator *d);
bool dungeon_is_block_passable(s16 x, s16 y, dungeon_generator *d);

void dungeon_room_get_neighbours(union union_neighbours *drn, union union_neighbours *npn, 
        union union_neighbours *srn, dungeon_generator *d, u32 current_room);
u8 dungeon_pick_random_neighbour_room(union union_neighbours n, dungeon_generator *d);
void dungeon_connect_rooms(u8 first, u8 second, dungeon_generator *d);

u32 dungeon_random_next_32(dungeon_generator *d);
u16 dungeon_random_next_16(dungeon_generator *d);
u8 dungeon_random_next_8(dungeon_generator *d);

mapheader *compute_dungeon_header();
mapfooter *compute_dungeon_footer();
map_events *compute_dungeon_events();



#endif
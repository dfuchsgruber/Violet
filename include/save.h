#ifndef HSAVE
#define HSAVE
#include "map.h"
#include "dungeon_generator.h"
#include "rtc.h"
#include "pokepad.h"
#include "fp_menu.h"
#include "fpmenu.h"

typedef struct saveblock1 {
    s16 x;
    s16 y;
    u8 bank;
    u8 map;
    u8 unkown_0[0x16];
    s8 healingplace_bank;
    u8 healingplace_map;
    u8 unkown_1[0x6];
    u8 last_outdoor_bank;
    u8 last_outdoor_map;
    u8 unkown[0xA];
    u8 flash_circle_size;
    u8 field_31;
    u16 current_footer_id;
    //0x34
    u8 unkown_2[0x8AC];
    map_event_person persons[256];
    //TODO


} saveblock1;

typedef struct saveblock2 {
    u8 unkown[0x8];
    u8 player_is_female;
    u8 unkown_4[0xA];
    u8 detector_state; //original key swtiching
    u8 text_speed;
    u8 sound_state : 1;
    u8 unkown_2 : 7;
    u8 unkown_3[0x12];
    u8 pokedex_caught_flags[0x34]; //416 flags
    u8 pokedex_seen_flags[0x34]; //416 flags
} saveblock2;

typedef struct custom_memory {
    u8 flag_extension[0x80]; //additional 0x400 flags (0x900-0xD00)
    u8 pokedex_seen_extension[0x40]; //additional 512 flags
    u8 pokedex_caught_extension[0x40]; //additional 512 flags
    u8 gp_freespace[0x100];
    u16 var_extension[0x100]; //Additional 256 vars (0x5000-0x50FF)

    //dungeon_data ddata;
    mapheader dhead;
    mapfooter footer;
    dungeon_generator dgen;
    map_events devents;
    map_event_warp ladder;
    map_event_person dpers[5];

    //trash memory (generall a vector memory)
    u8 trash_flags[16];
    rtc_timestamp a_gen_time;
    u8 a_vector[4];

} custom_memory;

typedef struct {
    u8 dmap_status;
    u8 unused_1;
    u8 unused_2;
    u8 unused_3;
    pokepad_memory *pad_mem;
    wondertrade_memory *wtrade_mem;
    pokedex_memory *dex_mem;
    fp_memory *fp_mem;
    script additional_levelscript_4;

} floating_memory;



saveblock1 **save1 = (saveblock1**) 0x03004F58;
saveblock2 **save2 = (saveblock2**) 0x03004F5C;
custom_memory *cmem = (custom_memory*) 0x0203C200;
floating_memory *fmem = (floating_memory*) 0x0203CEC4;

#endif
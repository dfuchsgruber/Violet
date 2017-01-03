#include "dungeon_generator.h"
#include "map.h"
#include "save.h"
#include "types.h"
#include "romfuncs.h"
#include <stdbool.h>


static map_connections null_connections = {0, NULL};

mapheader *compute_dungeon_header() {

    (*save1)->flash_circle_size = 1;

    if (dflags->header_initialized) {
        return &(cmem->dhead);
    } else {

        dflags->header_initialized = 1;

        //build the dungoen generator
        dungeon_generator *generator = &(cmem->dgen);
        //generator->initial_seed = random_change_seed() | ((u32)(random_change_seed() << 16));
        generator->seed = generator->initial_seed;
        generator->width = 65;
        generator->height = 65;
        generator->rooms_per_line = 6;
        generator->rooms_per_row = 6;
        generator->room_frequency = 0x80;
        generator->min_rooms = 8;

        //We make the mapheader
        cmem->dhead.footer = compute_dungeon_footer(generator);
        cmem->dhead.events = compute_dungeon_events();

        cmem->dhead.levelscripts = (void*) 0x871A220;
        cmem->dhead.connections = &null_connections;
        cmem->dhead.music = 0x14b;
        cmem->dhead.map_index = 0x1c1; //test index
        cmem->dhead.flash = 2;
        cmem->dhead.weather = WEATHER_INSIDE;
        cmem->dhead.type = 0;
        cmem->dhead.show_name = 0;
        cmem->dhead.battle_style = 0;

        //return (mapheader*)0x8728D54;
        return &(cmem->dhead);

    }
}

static u16 border [4] = {0x32A, 0x32b, 0x32c, 0x32d};

mapfooter *compute_dungeon_footer(dungeon_generator *d) {

    cmem->footer.width = d->width;
    cmem->footer.height = d->height;
    cmem->footer.border_blocks = border;
    cmem->footer.map = (map_block*) 0x892AD80;
    cmem->footer.tileset1 = (tileset*) 0x082D49B8;
    cmem->footer.tileset2 = (tileset*) 0x082D4B20;
    cmem->footer.border_width = 2;
    cmem->footer.border_height = 2;
    return &(cmem->footer);

}

/**
static map_event_warp nullwarp = {1, 1, 0, 0, 0, 0};
static map_events nullevents = {
        0, 1, 0, 0,
        NULL,
        &nullwarp,
        NULL,
        NULL
};
 **/

map_events *compute_dungeon_events() {

    cmem->ladder.x = 0;
    cmem->ladder.y = 0;
    cmem->ladder.height = 0;
    cmem->ladder.target_warp_id = 0;
    cmem->ladder.target_map = 3;
    cmem->ladder.target_bank = 3;

    cmem->devents.person_cnt = 5;
    cmem->devents.warp_cnt = 1;
    cmem->devents.script_cnt = 0;
    cmem->devents.signpost_cnt = 0;
    cmem->devents.persons = cmem->dpers;
    cmem->devents.warps = &(cmem->ladder);
    cmem->devents.scripts = NULL;
    cmem->devents.signposts = NULL;

    int i;
    for (i = 0; i < 5; i++) {
        cmem->dpers[i].target_index = (u8) i;
        cmem->dpers[i].overworld_index = 92;
        cmem->dpers[i].field_2 = 0;
        cmem->dpers[i].field_3 = 0;
        cmem->dpers[i].x = 0;
        cmem->dpers[i].y = 0;
        cmem->dpers[i].field_8 = 0;
        cmem->dpers[i].facing = 0;
        cmem->dpers[i].behavior = 0;
        cmem->dpers[i].field_B = 0;
        cmem->dpers[i].is_trainer = 0;
        cmem->dpers[i].padding = 0;
        cmem->dpers[i].field_D = 0;
        cmem->dpers[i].alert_radius = 0;
        cmem->dpers[i].script = NULL;
        cmem->dpers[i].flag = 0;
        cmem->dpers[i].field_16 = 0;
        cmem->dpers[i].field_17 = 0;
    }
    //For now we return a static event list
    //return (map_events*) 0x087198A4;
    return &(cmem->devents);
    //return &nullevents;
}


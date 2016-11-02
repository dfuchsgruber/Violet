#include "dungeon_generator.h"
#include "map.h"
#include "types.h"
#include "save.h"
#include "romfuncs.h"
#include "item.h"
#include "overworld_script.h"
#include "utils.h"

//item scripts
static u8 dungeon_item_scripts_orbs [][13] = {

    //Nature orbs (10 items)
    {SIMPLE_GIVEITEM_SCRIPT(ITEM_ANGR_ORB_P)},
    {SIMPLE_GIVEITEM_SCRIPT(ITEM_ANGR_ORB_N)},
    {SIMPLE_GIVEITEM_SCRIPT(ITEM_VERT_ORB_P)},
    {SIMPLE_GIVEITEM_SCRIPT(ITEM_VERT_ORB_N)},
    {SIMPLE_GIVEITEM_SCRIPT(ITEM_INIT_ORB_P)},

    {SIMPLE_GIVEITEM_SCRIPT(ITEM_INIT_ORB_N)},
    {SIMPLE_GIVEITEM_SCRIPT(ITEM_SPA_ORB_P)},
    {SIMPLE_GIVEITEM_SCRIPT(ITEM_SPA_ORB_N)},
    {SIMPLE_GIVEITEM_SCRIPT(ITEM_SPV_ORB_P)},
    {SIMPLE_GIVEITEM_SCRIPT(ITEM_SPV_ORB_N)},


};

static u8 dungeon_item_script_heartscale [13] = {SIMPLE_GIVEITEM_SCRIPT(ITEM_HERZSCHUPPE)};

static u8 dungeon_item_scripts_fossils [][13] = {
    //Fossils
    {SIMPLE_GIVEITEM_SCRIPT(ITEM_HELIXFOSSIL)},
    {SIMPLE_GIVEITEM_SCRIPT(ITEM_DOMFOSSIL)},
    {SIMPLE_GIVEITEM_SCRIPT(ITEM_KLAUENFOSSIL)},
    {SIMPLE_GIVEITEM_SCRIPT(ITEM_WURZELFOSSIL)},
    {SIMPLE_GIVEITEM_SCRIPT(ITEM_ALTBERNSTEIN)}
};

static u8 dungeon_item_scripts_evolution_stones [][13] = {

    {SIMPLE_GIVEITEM_SCRIPT(ITEM_FEUERSTEIN)},
    {SIMPLE_GIVEITEM_SCRIPT(ITEM_WASSERSTEIN)},
    {SIMPLE_GIVEITEM_SCRIPT(ITEM_BLATTSTEIN)},
    {SIMPLE_GIVEITEM_SCRIPT(ITEM_MONDSTEIN)},
    {SIMPLE_GIVEITEM_SCRIPT(ITEM_SONNENSTEIN)},

    {SIMPLE_GIVEITEM_SCRIPT(ITEM_FINSTERSTEIN)},
    {SIMPLE_GIVEITEM_SCRIPT(ITEM_LEUCHTSTEIN)},
    {SIMPLE_GIVEITEM_SCRIPT(ITEM_FUNKELSTEIN)}
};

static u8 dungeon_item_scripts_common [][13] = {
    {SIMPLE_GIVEITEM_SCRIPT(ITEM_AETHER)},
    {SIMPLE_GIVEITEM_SCRIPT(ITEM_ELIXIER)},
    {SIMPLE_GIVEITEM_SCRIPT(ITEM_STERNENSTAUB)},
    {SIMPLE_GIVEITEM_SCRIPT(ITEM_FLUCHTSEIL)},
    {SIMPLE_GIVEITEM_SCRIPT(ITEM_EWIGSTEIN)}
};

static u8 dungeon_item_scripts_rare [][13] = {
    {SIMPLE_GIVEITEM_SCRIPT(ITEM_SONDERBONBON)},
    {SIMPLE_GIVEITEM_SCRIPT(ITEM_SPIRITKERN)},
    {SIMPLE_GIVEITEM_SCRIPT(ITEM_SCHUETZER)},
    {SIMPLE_GIVEITEM_SCRIPT(ITEM_METALLMANTEL)},
    {SIMPLE_GIVEITEM_SCRIPT(ITEM_TOP_AETHER)},
    {SIMPLE_GIVEITEM_SCRIPT(ITEM_TOP_ELIXIER)},
    {SIMPLE_GIVEITEM_SCRIPT(ITEM_STERNENSTUECK)},
    {SIMPLE_GIVEITEM_SCRIPT(ITEM_NUGGET)}
};

void compute_dungeon_rooms(dungeon_generator *d) {
    u32 i;

    u32 rooms_max = (u32) (d->rooms_per_line * d->rooms_per_row);
    d->rooms = (room*) malloc(sizeof (room) * rooms_max);

    //calculate room size
    u32 hsegment_cnt = (u32) (d->rooms_per_line * 2 - 1);
    u32 vsegment_cnt = (u32) (d->rooms_per_row * 2 - 1);
    u32 hsegment_size = (u32) (d->width / hsegment_cnt);
    u32 vsegment_size = (u32) (d->height / vsegment_cnt);


    u16 room_asize_x = (u16) ((u16) (d->width - 4) / hsegment_cnt);
    u16 room_asize_y = (u16) ((u16) (d->height - 4) / vsegment_cnt);

    u32 rooms_built;
    do {

        rooms_built = 0;

        //now we build the rooms
        for (i = 0; i < rooms_max; i++) {

            //room parameters are calculated
            d->rooms[i].width = (u16) (room_asize_x - (random_next8(d) & 3) + 2);
            d->rooms[i].height = (u16) (room_asize_y - (random_next8(d) & 3) + 2);

            //for the x and y coordinates it gets tricky, the segment id is 2 * i
            u32 room_y = i / (d->rooms_per_line);
            u32 room_x = __umod((u32) i, d->rooms_per_line);

            d->rooms[i].roomx = (u8) room_x;
            d->rooms[i].roomy = (u8) room_y;
            d->rooms[i].x = (s16) (room_x * 2 * hsegment_size + 1);
            d->rooms[i].y = (s16) (room_y * 2 * vsegment_size + 1);

            d->rooms[i].connector_x = (s16) (d->rooms[i].x + (int) __umod(random_next8(d), (u32) (d->rooms[i].width)));
            d->rooms[i].connector_y = (s16) (d->rooms[i].y + (int) __umod(random_next8(d), (u32) (d->rooms[i].height)));

            d->rooms[i].region = (u8) rooms_built;
            d->rooms[i].is_person_located = false;

            //decide weather to build a room
            if (random_next8(d) <= d->room_frequency) {

                //room will be built
                d->rooms[i].presence = true;
                //(*((u16*)0x020370D0))++;
                rooms_built++;

            } else {
                d->rooms[i].presence = false;
                d->rooms[i].region = 0xFE;
            }
        }

    } while (rooms_built < (d->min_rooms));
    d->regions = (u8) rooms_built;

    //Now we draw rooms
    for (i = 0; i < rooms_max; i++) {
        if (d->rooms[i].presence) {
            int x, y;
            for (x = 0; x < d->rooms[i].width; x++) {
                for (y = 0; y < d->rooms[i].height; y++) {
                    set_block((s16) (d->rooms[i].x + x), (s16) (d->rooms[i].y + y), d);
                }
            }
        }
    }

}

u8 room_coordinate_to_index(u8 x, u8 y, dungeon_generator *d) {
    return (u8) (y * d->rooms_per_line + x);
}

void compute_dungeon_paths(dungeon_generator *d) {

    //first we pick a random room to start with
    u32 rooms_max = (u32) (d->rooms_per_line * d->rooms_per_row);
    u32 current_room;
    do {
        current_room = __umod(random_next32(d), rooms_max);

    } while (!(d->rooms[current_room].presence));

    union union_neighbours different_region_neighbours = {
        {0xFF, 0xFF, 0xFF, 0xFF}}; //all neighbours that have a different region
    union union_neighbours not_present_neighbours = {
        {0xFF, 0xFF, 0xFF, 0xFF}}; //all neighbours that are not a room but could be expanded into one

    //now we collect the neighbours with different regions and not present neighbours

    while (d->regions > 1) {
        different_region_neighbours.value = 0xFFFFFFFF;
        not_present_neighbours.value = 0xFFFFFFFF;
        dungeon_room_get_neighbours(&different_region_neighbours, &not_present_neighbours, d, current_room);

        //we connect rooms
        if (different_region_neighbours.value != 0xFFFFFFFF) {
            //we have different region neighbours
            u8 target = dungeon_pick_room(different_region_neighbours, d);

            dungeon_connect_rooms((u8) current_room, target, d);

            current_room = target;
            d->regions--;

        } else if (not_present_neighbours.value != 0xFFFFFFFF) {
            //we have no different region neighbours, so we expand a neighbour into a one tile room
            u8 target = dungeon_pick_room(not_present_neighbours, d);
            d->rooms[target].presence = true;
            d->rooms[target].width = 1;
            d->rooms[target].height = 1;
            d->rooms[target].x = d->rooms[target].connector_x;
            d->rooms[target].y = d->rooms[target].connector_y;
            d->rooms[target].region = d->rooms[current_room].region;

            dungeon_connect_rooms((u8) current_room, target, d);
            current_room = target;
            set_block((s16) (d->rooms[target].x), (s16) (d->rooms[target].y), d);

        } else {

            //Algorithm reached dead end, rechoice of current room
            do {
                current_room = __umod(random_next32(d), rooms_max);
            } while (!(d->rooms[current_room].presence));
        }

    }
}


// picks a random room from availible neighbour list

u8 dungeon_pick_room(union union_neighbours n, dungeon_generator *d) {
    int choice;
    while (true) {
        choice = random_next8(d) & 3;
        switch (choice) {
            case 0:
                if (n.n.down != 0xFF) {
                    return n.n.down;
                }
                break;
            case 1:
                if (n.n.up != 0xFF) {
                    return n.n.up;
                }
                break;
            case 2:
                if (n.n.left != 0xFF) {
                    return n.n.left;
                }
                break;
            case 3:
                if (n.n.right != 0xFF) {
                    return n.n.right;
                }
                break;
        }
    }
    return 0xFF;
}

void dungeon_connect_rooms(u8 first, u8 second, dungeon_generator *d) {

    //while (second == 5 || first == 5){}

    //First we merge the regions by replacing all occurences of the second region with the first one
    int i;
    u8 rfirst = d->rooms[first].region, rsecond = d->rooms[second].region;
    for (i = 0; i < (d->rooms_per_line * d->rooms_per_row); i++) {
        if ((d->rooms[i].region) == rsecond) {
            d->rooms[i].region = rfirst;
        }
    }

    int dx = d->rooms[second].connector_x - d->rooms[first].connector_x;
    int dy = d->rooms[second].connector_y - d->rooms[first].connector_y;

    if (d->rooms[second].roomx != d->rooms[first].roomx) {
        //horizontal connection line
        int y = d->rooms[second].connector_y;
        for (int x = 0; x != dx; x += signum(dx)) {

            if (abs(x) < abs(dx / 2)) {
                //proceed horizontal line drawing
                set_block((s16) (d->rooms[second].connector_x - x), (s16) (y), d);
            } else {
                if (y == d->rooms[second].connector_y) {
                    //we draw the vertical part
                    for (; y != (d->rooms[first].connector_y); y -= signum(dy)) {
                        set_block((s16) (d->rooms[second].connector_x - x), (s16) (y), d);
                    }
                    set_block((s16) (d->rooms[second].connector_x - x), (s16) (y), d);
                } else {
                    set_block((s16) (d->rooms[second].connector_x - x), (s16) (y), d);
                }
            }

        }
    } else {
        //vertical connection line
        int x = d->rooms[second].connector_x;
        for (int y = 0; y != dy; y += signum(dy)) {

            if (abs(y) < abs(dy / 2)) {
                //proceed horizontal line drawing
                set_block((s16) (x), (s16) (d->rooms[second].connector_y - y), d);
            } else {
                if (x == d->rooms[second].connector_x) {
                    //we draw the vertical part
                    for (; x != (d->rooms[first].connector_x); x -= signum(dx)) {
                        set_block((s16) (x), (s16) (d->rooms[second].connector_y - y), d);
                    }
                    set_block((s16) (x), (s16) (d->rooms[second].connector_y - y), d);
                } else {
                    set_block((s16) (x), (s16) (d->rooms[second].connector_y - y), d);
                }
            }

        }


    }

    //shuffle connection points
    d->rooms[first].connector_x = (s16) ((u32) d->rooms[first].x + __umod(random_next8(d), (u32) d->rooms[first].width));
    d->rooms[first].connector_y = (s16) ((u32) d->rooms[first].y + __umod(random_next8(d), (u32) d->rooms[first].height));
    d->rooms[second].connector_x = (s16) ((u32) d->rooms[second].x + __umod(random_next8(d), (u32) d->rooms[second].width));
    d->rooms[second].connector_y = (s16) ((u32) d->rooms[second].y + __umod(random_next8(d), (u32) d->rooms[second].height));

}

void dungeon_room_get_neighbours(union union_neighbours *drn, union union_neighbours *npn, dungeon_generator *d, u32 current_room) {

    drn->value = 0xFFFFFFFF;
    npn->value = 0xFFFFFFFF;

    u8 cix = d->rooms[current_room].roomx, ciy = d->rooms[current_room].roomy;
    u8 n;
    if (ciy > 0) { //UP
        n = room_coordinate_to_index(cix, (u8) (ciy - 1), d);
        if (d->rooms[n].presence && d->rooms[n].region != d->rooms[current_room].region) {
            drn->n.up = n;
        } else if (!(d->rooms[n].presence)) {
            npn->n.up = n;
        }
    }
    if (ciy < (d->rooms_per_row - 1)) { //DOWN
        n = room_coordinate_to_index(cix, (u8) (ciy + 1), d);
        if (d->rooms[n].presence && d->rooms[n].region != d->rooms[current_room].region) {
            drn->n.down = n;
        } else if (!(d->rooms[n].presence)) {
            npn->n.down = n;
        }
    }
    if (cix > 0) { //LEFT
        n = room_coordinate_to_index((u8) (cix - 1), ciy, d);
        if (d->rooms[n].presence && d->rooms[n].region != d->rooms[current_room].region) {
            drn->n.left = n;
        } else if (!(d->rooms[n].presence)) {
            npn->n.left = n;
        }
    }
    if (cix < (d->rooms_per_line - 1)) { //RIGHT
        n = room_coordinate_to_index((u8) (cix + 1), ciy, d);
        if (d->rooms[n].presence && d->rooms[n].region != d->rooms[current_room].region) {
            drn->n.right = n;
        } else if (!(d->rooms[n].presence)) {
            npn->n.right = n;
        }
    }
}

void set_block(s16 x, s16 y, dungeon_generator *d) {

    int index = y * d->width + x;
    u8 mask = (u8) (1 << (index & 7));
    d->dbuf[(u16) (index / 8)] |= mask;

}

bool get_block(s16 x, s16 y, dungeon_generator *d) {
    int index = y * d->width + x;
    int mask = 1 << (index & 7);
    if ((d->dbuf[index / 8]) & mask) {
        return true;
    }
    return false;
}

void compute_dungeon_tiles(dungeon_generator *d) {

    s16 x, y;
    for (x = 0; x < d->width; x++) {
        for (y = 0; y < d->height; y++) {
            u16 block;
            u8 r = random_next8(d);
            if (get_block(x, y, d)) {
                if (r & 31) {
                    block = 0x2D9;
                } else {
                    block = (u16) (0x338 + ((r >> 5) & 3));
                }

            } else {
                if (r < 0x10) {
                    block = (u16) ((r & 2 ? 0xE82 : 0xF36) + (r & 1 ? 1 : 0));
                } else {
                    block = (u16) (0x32A + __umod(random_next8(d), 12));
                }
            }
            set_block_id((s16) (x + 7), (s16) (y + 7), block);
        }
    }

}

void relocate_dungeon_events(dungeon_generator *d) {

    u32 rooms_max = (u32) (d->rooms_per_line * d->rooms_per_row);

    //we find fitting rooms for events (rooms with sizes > 1){
    u32 i;
    int candidates = 0;
    for (i = 0; i < rooms_max; i++) {
        if (d->rooms[i].presence && d->rooms[i].width > 1 && d->rooms[i].height > 1) {
            candidates++;
        }
    }
    if (!candidates) {
        return;
    }

    //setting up a warp

    u32 entrance;
    do {
        entrance = __umod(random_next8(d), rooms_max);
    } while (!(d->rooms[entrance].presence && d->rooms[entrance].width > 1 && d->rooms[entrance].height > 1)); //pick a real room


    //now we pick a random position that is not at rooms border
    d->rooms[entrance].is_person_located = true;
    s16 x = d->rooms[entrance].x; //+ __umod(random_next8(d), (u32)(d->rooms[entrance].width - 2)));
    s16 y = d->rooms[entrance].y; //+ __umod(random_next8(d), (u32)(d->rooms[entrance].height - 2)));

    s16 x_rel = (s16) (__umod(random_next8(d), (u32) ((d->rooms[entrance].width - 2))) + 1);
    s16 y_rel = (s16) (__umod(random_next8(d), (u32) ((d->rooms[entrance].height - 2))) + 1);

    x = (s16) (x + x_rel);
    y = (s16) (y + y_rel);

    cmem->ladder.x = x;
    cmem->ladder.y = y;
    cmem->ladder.height = 0;
    cmem->ladder.target_warp_id = 3;
    cmem->ladder.target_map = 3;
    cmem->ladder.target_bank = 3;

    candidates--;



    for (i = 0; i < rooms_max - 1 && i < 5 && candidates; i++) { //we locate persons in rooms that were not picked
        if (random_next8(d) >= 0x60) { // 160 / 256 chance that an item will be spawned
            u32 picked;
            do {
                picked = __umod(random_next8(d), rooms_max);
            } while (d->rooms[picked].is_person_located ||
                    (!(d->rooms[picked].presence && d->rooms[picked].width > 1 && d->rooms[picked].height > 1)));

            x = d->rooms[picked].x;
            y = d->rooms[picked].y;

            x_rel = (s16) (d->rooms[picked].width / 2);
            y_rel = (s16) (d->rooms[picked].height / 2);

            cmem->dpers[i].flag = (u16) (i + 0x13); //use dynamic flags 0x13 - 0x18
            cmem->dpers[i].x = (s16) (x + x_rel);
            cmem->dpers[i].y = (s16) (y + y_rel);

            //setting up a random script for the item
            u8 r = random_next8(d);
            if (r < 0x50) { // 0 - 0x4F is a nature item
                cmem->dpers[i].script = dungeon_item_scripts_orbs[__umod(random_next8(d), 10)];
            } else if (r < 0x90) { // 0x50 - 0x8F is a common item
                cmem->dpers[i].script = dungeon_item_scripts_common[__umod(random_next8(d), 5)];
            } else if (r < 0xC0) { // 0x90 - 0xBF is heartscale
                cmem->dpers[i].script = dungeon_item_script_heartscale;
            } else if (r < 0xD8) { // 0xC0 - 0xD7 is evolution stone
                cmem->dpers[i].script = dungeon_item_scripts_evolution_stones[__umod(random_next8(d), 8)];
            } else if (r < 0xF0) { // 0xD8 - 0xEF is rare item
                cmem->dpers[i].script = dungeon_item_scripts_rare[__umod(random_next8(d), 8)];
            } else { //0xF0 - 0xEF is a fossil
                cmem->dpers[i].script = dungeon_item_scripts_fossils[__umod(random_next8(d), 5)];
            }

            candidates--;


        } else {
            cmem->dpers[i].flag = 0x820;
        }

    }

    //set_block_id((s16)(x+7), (s16)(y+7), 0x285);

}

void compute_dungeon_blocks() {

    if (dflags->blocks_initialized) {
        //The blocks were already loaded, so we use the same seed
        cmem->dgen.seed = cmem->dgen.initial_seed;
    }

    dflags->blocks_initialized = 1;

    dungeon_generator *d = &(cmem->dgen);

    //build a buffer of flags that state if a tile is enabled or not
    d->dbuf = cmalloc((u32) ((d->width) * (d->height) / 8));


    //first we compute the dungeon
    compute_dungeon_rooms(d);
    compute_dungeon_paths(d);
    compute_dungeon_tiles(d);
    relocate_dungeon_events(d);

    free(d->dbuf);
    free(d->rooms);

    foot_ddata->footer = &(cmem->footer);
    //special_x8E_update_map_graphics();

}

u32 random_next32(dungeon_generator *d) {
    return (u32) ((random_next16(d) << 16) | random_next16(d));
}

u16 random_next16(dungeon_generator *d) {
    d->seed = (u32) (d->seed * 0x41C64E6D + 0x6073);
    return (u16) (d->seed >> 16);
}

u8 random_next8(dungeon_generator *d) {
    return (u8) random_next16(d);
}
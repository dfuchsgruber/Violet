#include "dungeon_generator.h"
#include "map.h"
#include "types.h"
#include "save.h"
#include "romfuncs.h"
#include "item.h"
#include "overworld_script.h"
#include "utils.h"
#include "debug.h"

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



void dungeon_draw_rooms(dungeon_generator *d){
    int rooms = d->rooms_per_line * d->rooms_per_row;
    int i;
    for (i = 0; i < rooms; i++) {
        if (d->rooms[i].presence) {
            int x, y;
            for (x = 0; x < d->rooms[i].width; x++) {
                for (y = 0; y < d->rooms[i].height; y++) {
                    dungeon_set_block_passable((s16) (d->rooms[i].x + x), (s16) (d->rooms[i].y + y), d);
                }
            }
        }
    }
}

void dungeon_compute_rooms(dungeon_generator *d){
    
    //allocate rooms
    int rooms = d->rooms_per_line * d->rooms_per_row;
    d->rooms = malloc((sizeof(room) * (u32)rooms));
    
    //seperate the dungeon map into a grid of segments, where each room is a
    //segment and each space between rooms is a segment
    //we also ensure, that there is a wall to the dungeon borders of size 1
    
    int hor_segments = d->rooms_per_line * 2 - 1;
    int ver_segments = d->rooms_per_row * 2 - 1;
    
    int hor_seg_size = (d->width-2) / hor_segments;
    int ver_seg_size = (d->height-2) / ver_segments;
    
    int rooms_built;
    do{
        
        rooms_built = 0;
        
        //try to create a full set rooms
        int i;
        for(i = 0; i < rooms; i++){
            
            //Now we find the x,y of the current room inside a room grid
            int room_x = i % (d->rooms_per_line);
            int room_y = i / d->rooms_per_line;
            
            //We also find the x,y of the segment the room is represented by
            int seg_x = room_x * 2;
            int seg_y = room_y * 2;
            
            //determine the width, height of a room
            //we take a segment size and multiply w,h by a of range [0,5; 1.0]
            int room_width = hor_seg_size * ((dungeon_random_next_8(d) % 6) + 5); //mul with 5...10
            room_width /= 10;
            int room_height = ver_seg_size * ((dungeon_random_next_8(d) % 6) + 5);
            room_height /= 10;
            
            int x = seg_x * hor_seg_size + 1;
            int y = seg_y * ver_seg_size + 1;
            
            //initialize the room struct
            d->rooms[i].roomx = (u8) room_x;
            d->rooms[i].roomy = (u8) room_y;
            d->rooms[i].x = (s16) (x);
            d->rooms[i].y = (s16) (y);
            d->rooms[i].region = (u8) rooms_built;
            d->rooms[i].is_person_located = false;
            d->rooms[i].width = (u16) room_width;
            d->rooms[i].height = (u16) room_height;
            
            dungeon_relocate_room_connector((u8)i, d);
            
            //determine if the virutal room will be transported to the map or not
            if(dungeon_random_next_8(d) <= d->room_frequency){
                d->rooms[i].presence = true;
                rooms_built++;
            }else{
                d->rooms[i].presence = false;
            }
            
        }
    }while(rooms_built < d->min_rooms);
    d->regions = (u8)rooms_built;
    
    dungeon_draw_rooms(d);
}

u8 dungeon_room_coordinates_to_room_index(u8 x, u8 y, dungeon_generator *d) {
    return (u8) (y * d->rooms_per_line + x);
}

void dungeon_compute_paths(dungeon_generator *d) {

    //first we pick a random room to start with
    u32 rooms_max = (u32) (d->rooms_per_line * d->rooms_per_row);
    u32 current_room;
    do {
        current_room = dungeon_random_next_32(d) % rooms_max;

    } while (!(d->rooms[current_room].presence));

    union union_neighbours different_region_neighbours = {
        {0xFF, 0xFF, 0xFF, 0xFF}}; //all neighbours that have a different region
    union union_neighbours not_present_neighbours = {
        {0xFF, 0xFF, 0xFF, 0xFF}}; //all neighbours that are not a room but could be expanded into one

    //now we collect the neighbours with different regions and not present neighbours

    while (d->regions > 1) {
        different_region_neighbours.value = 0xFFFFFFFF;
        not_present_neighbours.value = 0xFFFFFFFF;
        dungeon_room_get_neighbours(&different_region_neighbours, &not_present_neighbours, NULL, d, current_room);

        //we connect rooms
        if (different_region_neighbours.value != 0xFFFFFFFF) {
            //we have different region neighbours
            u8 target = dungeon_pick_random_neighbour_room(different_region_neighbours, d);

            dungeon_connect_rooms((u8) current_room, target, d);

            current_room = target;
            d->regions--;

        } else if (not_present_neighbours.value != 0xFFFFFFFF) {
            //we have no different region neighbours, so we expand a neighbour into a one tile room
            u8 target = dungeon_pick_random_neighbour_room(not_present_neighbours, d);
            d->rooms[target].presence = true;
            d->rooms[target].width = 1;
            d->rooms[target].height = 1;
            d->rooms[target].x = d->rooms[target].connector_x;
            d->rooms[target].y = d->rooms[target].connector_y;
            d->rooms[target].region = d->rooms[current_room].region;

            dungeon_connect_rooms((u8) current_room, target, d);
            current_room = target;
            dungeon_set_block_passable((s16) (d->rooms[target].x), (s16) (d->rooms[target].y), d);

        } else {

            //Algorithm reached dead end, rechoice of current room
            do {
                current_room = dungeon_random_next_32(d) % rooms_max;
            } while (!(d->rooms[current_room].presence));
        }

    }
}


// picks a random room from availible neighbour list
u8 dungeon_pick_random_neighbour_room(union union_neighbours n, dungeon_generator *d) {
    int choice;
    while (true) {
        choice = dungeon_random_next_8(d) & 3;
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

/**
 * Merges two regions inside a dungeon by replacing all occurences of region==s with r
 * @param r
 * @param s
 * @param d
 */
void dungeon_merge_regions(u8 r, u8 s, dungeon_generator *d){
    int i;
    int rooms = d->rooms_per_line * d->rooms_per_row;
    for(i = 0; i < rooms; i++){
        if(d->rooms[i].presence && d->rooms[i].region == s)
            d->rooms[i].region = r;
    }
}

void dungeon_relocate_room_connector(u8 r, dungeon_generator *d){
    int x = d->rooms[r].x + (dungeon_random_next_8(d) % d->rooms[r].width);
    int y = d->rooms[r].y + (dungeon_random_next_8(d) % d->rooms[r].height);
    d->rooms[r].connector_x = (s16)x;
    d->rooms[r].connector_y = (s16)y;
}

void dungeon_connect_rooms(u8 r, u8 s, dungeon_generator *d){
    
    //Find x,y of the connectors
    s16 rx = d->rooms[r].connector_x;
    s16 ry = d->rooms[r].connector_y;
    s16 sx = d->rooms[s].connector_x;
    s16 sy = d->rooms[s].connector_y;
    
    //Start from rx,ry and step towards sx, sy
    s16 x = rx, y = ry;
    while(x != sx || y != sy){
        //calculate remaining distances
        int dx = abs(sx-x);
        int dy = abs(sy-y);
        if(dx > dy){
            //connect by walking into x direction
            x = (s16)(x + signum(sx-x));
        }else{
            //connect by walking into y direction
            y = (s16)(y + signum(sy-y));
        }
        dungeon_set_block_passable(x, y, d);
    }
    
    //Connects two rooms of a dungeon
    dungeon_merge_regions(d->rooms[r].region, d->rooms[s].region, d);
    
    //Relocate the connectors
    dungeon_relocate_room_connector(r, d);
    dungeon_relocate_room_connector(s, d);
    
}


void dungeon_room_get_neighbours(union union_neighbours *drn, union union_neighbours *npn, union union_neighbours *srn, dungeon_generator *d, u32 current_room) {

    drn->value = 0xFFFFFFFF;
    npn->value = 0xFFFFFFFF;

    u8 cix = d->rooms[current_room].roomx, ciy = d->rooms[current_room].roomy;
    u8 n;
    if (ciy > 0) { //UP
        n = dungeon_room_coordinates_to_room_index(cix, (u8) (ciy - 1), d);
        if (d->rooms[n].presence && d->rooms[n].region != d->rooms[current_room].region && drn) {
            drn->n.up = n;
        } else if (!(d->rooms[n].presence) && npn) {
            npn->n.up = n;
        } else if(srn){
            srn->n.up = n;
        }
    }
    if (ciy < (d->rooms_per_row - 1)) { //DOWN
        n = dungeon_room_coordinates_to_room_index(cix, (u8) (ciy + 1), d);
        if (d->rooms[n].presence && d->rooms[n].region != d->rooms[current_room].region && drn) {
            drn->n.down = n;
        } else if (!(d->rooms[n].presence) && npn) {
            npn->n.down = n;
        } else if(srn){
            srn->n.up = n;
        }
    }
    if (cix > 0) { //LEFT
        n = dungeon_room_coordinates_to_room_index((u8) (cix - 1), ciy, d);
        if (d->rooms[n].presence && d->rooms[n].region != d->rooms[current_room].region && drn) {
            drn->n.left = n;
        } else if (!(d->rooms[n].presence) && npn) {
            npn->n.left = n;
        } else if (srn){
            srn->n.up = n;
        }
    }
    if (cix < (d->rooms_per_line - 1)) { //RIGHT
        n = dungeon_room_coordinates_to_room_index((u8) (cix + 1), ciy, d);
        if (d->rooms[n].presence && d->rooms[n].region != d->rooms[current_room].region && drn) {
            drn->n.right = n;
        } else if (!(d->rooms[n].presence) && npn) {
            npn->n.right = n;
        } else if(srn){
            srn->n.up = n;
        }
    }
}

void dungeon_set_block_passable(s16 x, s16 y, dungeon_generator *d) {

    int index = y * d->width + x;
    u8 mask = (u8) (1 << (index & 7));
    d->dbuf[(u16) (index / 8)] |= mask;

}

bool dungeon_is_block_passable(s16 x, s16 y, dungeon_generator *d) {
    if(x < 0 || y < 0 || x >= d->width || y >= d->height) return false;
    int index = y * d->width + x;
    int mask = 1 << (index & 7);
    if ((d->dbuf[index / 8]) & mask) {
        return true;
    }
    return false;
}

/**
 * Returns a bitfield stating which tiles arround the tile are way and which
 * are solid
 * @param x 
 * @param y
 * @param d
 * @return 
 */
u8 dungeon_surrouding_blocks_as_bitfield(s16 x, s16 y, dungeon_generator *d){
    s16 i, j;
    u8 bitfield = 0;
    for(i = -1; i <= 1; i++){
        for(j = -1; j <= 1; j++){
            if(i || j){
                bitfield = (u8)(bitfield << 1); //shift the current bitfield away
                s16 sur_x = (s16)(x+i);
                s16 sur_y = (s16)(y+j);
                if(dungeon_is_block_passable(sur_x, sur_y, d))
                    bitfield |= 1;
            }

        }
    }
    return bitfield;
}


void dungeon_block_id_by_surrouding_bitfield(u8 bitfield, u16 block[]){
    //bitfield comes as 0bABCDEFGH where 0 is solid, 1 is free to pass
    //the enviorement of the segment is given by this structure
    // A D F
    // B   G
    // C E H
    
    u16 seg_0, seg_1, seg_2, seg_3;
    
    seg_0 = bitfield;
    seg_1 = bitfield;
    seg_2 = bitfield;
    seg_3 = bitfield;
    
    //tile 0 of segement, depens on A,D,B
    switch(bitfield & (SEG_A | SEG_B | SEG_D)){
        case 0b11010000: seg_0 = 0x288; break;
        case 0b01010000: seg_0 = 0x288; break;
        case 0b10010000: seg_0 = 0x289; break;
        case 0b00010000: seg_0 = 0x289; break;
        case 0b11000000: seg_0 = 0x290; break;
        case 0b01000000: seg_0 = 0x290; break;
        case 0b10000000: seg_0 = 0x2A4; break;
        case 0b00000000: seg_0 = 0x291; break;
        default:
            err2( ERR_DUNGEON_GEN_PATTERN_MISMATCH_SEG_0, bitfield);
    }
    
    //tile 1 of segment, depends on D, F, G
    switch(bitfield & (SEG_D | SEG_F | SEG_G)){
        case 0b00010110: seg_1 = 0x28A; break;
        case 0b00000110: seg_1 = 0x292; break;
        case 0b00010010: seg_1 = 0x28A; break;
        case 0b00000010: seg_1 = 0x292; break;
        case 0b00010100: seg_1 = 0x289; break;
        case 0b00000100: seg_1 = 0x2A3; break;
        case 0b00010000: seg_1 = 0x289; break;
        case 0b00000000: seg_1 = 0x291; break;
        default:
            err2( ERR_DUNGEON_GEN_PATTERN_MISMATCH_SEG_1, bitfield);
    }
    
    //tile 2 of segment, depends on B, C, E
    switch(bitfield & (SEG_B | SEG_C | SEG_E)){
        case 0b01101000: seg_2 = 0x298; break;
        case 0b00101000: seg_2 = 0x299; break;
        case 0b01001000: seg_2 = 0x298; break;
        case 0b00001000: seg_2 = 0x299; break;
        case 0b01100000: seg_2 = 0x290; break;
        case 0b00100000: seg_2 = 0x29C; break;
        case 0b01000000: seg_2 = 0x290; break;
        case 0b00000000: seg_2 = 0x291; break;
        default:
            err2( ERR_DUNGEON_GEN_PATTERN_MISMATCH_SEG_2, bitfield);
        
    }
    
    //tile 3 of segement, depends on E, G, H
    switch(bitfield & (SEG_E | SEG_G | SEG_H)){
        case 0b00001011: seg_3 = 0x29A; break;
        case 0b00000011: seg_3 = 0x292; break;
        case 0b00001001: seg_3 = 0x299; break;
        case 0b00000001: seg_3 = 0x29B; break;
        
        case 0b00001010: seg_3 = 0x29A; break;
        case 0b00000010: seg_3 = 0x292; break;
        case 0b00001000: seg_3 = 0x299; break;
        case 0b00000000: seg_3 = 0x291; break;
        default:
            err2( ERR_DUNGEON_GEN_PATTERN_MISMATCH_SEG_3, bitfield);
    }
    
   
    block[0] = seg_0 | 0xC00;
    block[1] = seg_1 | 0xC00;
    block[2] = seg_2 | 0xC00;
    block[3] = seg_3 | 0xC00;
    
    
}


void dungeon_compute_tile_map(dungeon_generator *d) {
    s16 x, y;
    for (x = 0; x < d->width; x++) {
        for (y = 0; y < d->height; y++) {
            u8 bitfield = dungeon_surrouding_blocks_as_bitfield(x, y, d);
            u16 block[4];
            //first we need to compute the bitfield for surrounding blocks
            if(!dungeon_is_block_passable(x, y, d)){
                dungeon_block_id_by_surrouding_bitfield(bitfield, block);
            }else{
                block[0] = 0x281;
                block[1] = 0x281;
                block[2] = 0x281;
                block[3] = 0x281;
            }
            
            set_block_id((s16) (2*x + 7), (s16) (2*y + 7), block[0]);
            set_block_id((s16) (2*x + 8), (s16) (2*y + 7), block[1]);
            set_block_id((s16) (2*x + 7), (s16) (2*y + 8), block[2]);
            set_block_id((s16) (2*x + 8), (s16) (2*y + 8), block[3]);
        }
    }

}

void dungeon_relocate_events(dungeon_generator *d) {

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
        entrance = dungeon_random_next_8(d) % rooms_max;
    } while (!(d->rooms[entrance].presence && d->rooms[entrance].width > 1 && d->rooms[entrance].height > 1)); //pick a real room


    //now we pick a random position that is not at rooms border
    d->rooms[entrance].is_person_located = true;
    s16 x = d->rooms[entrance].x; //+ __umod(random_next8(d), (u32)(d->rooms[entrance].width - 2)));
    s16 y = d->rooms[entrance].y; //+ __umod(random_next8(d), (u32)(d->rooms[entrance].height - 2)));

    s16 x_rel = (s16) ((dungeon_random_next_8(d) % (d->rooms[entrance].width - 2)) + 1);
    s16 y_rel = (s16) ((dungeon_random_next_8(d) % (d->rooms[entrance].height - 2)) + 1);

    x = (s16) (2*(x + x_rel));
    y = (s16) (2*(y + y_rel));

    cmem->ladder.x = x;
    cmem->ladder.y = y;
    cmem->ladder.height = 0;
    cmem->ladder.target_warp_id = 3;
    cmem->ladder.target_map = 3;
    cmem->ladder.target_bank = 3;

    candidates--;



    for (i = 0; i < rooms_max - 1 && i < 5 && candidates; i++) { //we locate persons in rooms that were not picked
        if (dungeon_random_next_8(d) < 0xc0) { // 3/4 chance that an item will be spawned
            u32 picked;
            do {
                picked = dungeon_random_next_8(d) % rooms_max;
            } while (d->rooms[picked].is_person_located ||
                    (!(d->rooms[picked].presence && d->rooms[picked].width > 1 && d->rooms[picked].height > 1)));

            x = d->rooms[picked].x;
            y = d->rooms[picked].y;

            x_rel = (s16) (d->rooms[picked].width / 2);
            y_rel = (s16) (d->rooms[picked].height / 2);

            cmem->dpers[i].flag = (u16) (i + 0x13); //use dynamic flags 0x13 - 0x18
            cmem->dpers[i].x = (s16) (2*(x + x_rel)+1); //items are always on the right side of a segment, where nothing can block them
            cmem->dpers[i].y = (s16) (2*(y + y_rel));

            //setting up a random script for the item
            u8 r = dungeon_random_next_8(d);
            if (r < 0x70) { // 112 / 256 Orb
                cmem->dpers[i].script = dungeon_item_scripts_orbs[dungeon_random_next_8(d) % 10];
            } else if (r < 0xE0) { // 112 / 256 Common Item
                cmem->dpers[i].script = dungeon_item_scripts_common[dungeon_random_next_8(d) % 5];
            } else if (r < 0xEC) { // 12 / 256 Heartscale
                cmem->dpers[i].script = dungeon_item_script_heartscale;
            } else if (r < 0xF4) { // 8 / 256 Evolution Stone
                cmem->dpers[i].script = dungeon_item_scripts_evolution_stones[dungeon_random_next_8(d) % 8];
            } else if (r < 0xFE) { // 10 / 256 Rare Item
                cmem->dpers[i].script = dungeon_item_scripts_rare[dungeon_random_next_8(d) % 8];
            } else { // 2 / 256 Fossil
                cmem->dpers[i].script = dungeon_item_scripts_fossils[dungeon_random_next_8(d) % 5];
            }
            d->rooms[picked].is_person_located = true;
            candidates--;


        } else {
            cmem->dpers[i].flag = 0x820;
        }

    }

    //set_block_id((s16)(x+7), (s16)(y+7), 0x285);

}

void dungeon_attempt_additional_placements(dungeon_generator *d){
    
    union union_neighbours neighbours;
    int i;
    int rooms = d->rooms_per_line * d->rooms_per_row;
    for(i = 0; i < d->additional_connection_attempts; i++){
        int r = dungeon_random_next_16(d) % rooms; //the first room
        dungeon_room_get_neighbours(NULL, NULL, &neighbours, d, (u8)r);
        u8 n = dungeon_pick_random_neighbour_room(neighbours, d);
        dungeon_connect_rooms((u8)r, n, d);
    }
}

u16 dungeon_decoration_stone_blocks[4] = {0x282, 0x283, 0x29F, 0x2A7};
u16 dungeon_decoration_plant_blocks[4] = {0x338, 0x339, 0x33A, 0x33B};

void dungeon_decorate_passable_segment(s16 x, s16 y, dungeon_generator *d){
    
    //try to place a dripping wall there
    //only possible if the blocks above resemble a horizontal wall
    u8 surrounding_blocks = dungeon_surrouding_blocks_as_bitfield(x, y, d);
    //bitfield comes as 0bABCDEFGH where 0 is solid, 1 is free to pass
    //the enviorement of the segment is given by this structure
    // A D F
    // B   G
    // C E H
    if((surrounding_blocks & (SEG_D | SEG_B | SEG_G | SEG_A | SEG_F)) == 0b01000010){
        set_block_id((s16)(2*x+7), (s16)(2*y+6), 0x2EE | 0xC00);
        set_block_id((s16)(2*x+8), (s16)(2*y+6), 0x2EF | 0xC00);
        set_block_id((s16)(2*x+7), (s16)(2*y+7), 0x2F6);
        set_block_id((s16)(2*x+8), (s16)(2*y+7), 0x2F7);
    }else{
        //no dripping wall can be placed here, so we place a random decor
        switch(dungeon_random_next_8(d) % 5){
            case 0:
                //place meteor crater
                set_block_id((s16)(2*x+7), (s16)(2*y+7), 0x2D5);
                set_block_id((s16)(2*x+8), (s16)(2*y+7), 0x2D6);
                set_block_id((s16)(2*x+7), (s16)(2*y+8), 0x2DD);
                set_block_id((s16)(2*x+8), (s16)(2*y+8), 0x2DE);
                break;
            case 1:
                //place sand patch
                set_block_id((s16)(2*x+7), (s16)(2*y+7), 0x2F3);
                set_block_id((s16)(2*x+8), (s16)(2*y+7), 0x2F5);
                set_block_id((s16)(2*x+7), (s16)(2*y+8), 0x303);
                set_block_id((s16)(2*x+8), (s16)(2*y+8), 0x305);
                break;
            case 2:
            case 3:{
                //place a random stone
                u16 stone_block = dungeon_decoration_stone_blocks[dungeon_random_next_8(d) & 3];
                int y_displacement = dungeon_random_next_8(d) & 1;
                set_block_id((s16) (2*x + 7), (s16) (2*y + 7), 0x281);
                set_block_id((s16) (2*x + 8), (s16) (2*y + 7), 0x281);
                set_block_id((s16) (2*x + 7), (s16) (2*y + 8), 0x281);
                set_block_id((s16) (2*x + 8), (s16) (2*y + 8), 0x281);
                set_block_id((s16) (2*x+7), (s16)(2*y+7+y_displacement), stone_block | 0xC00);
                break;
            }
            case 4:
            case 5:{
                //place a random plant
                u16 stone_block = dungeon_decoration_plant_blocks[dungeon_random_next_8(d) & 3];
                int y_displacement = dungeon_random_next_8(d) & 1;
                int x_displacement = dungeon_random_next_8(d) & 1;
                set_block_id((s16) (2*x + 7), (s16) (2*y + 7), 0x281);
                set_block_id((s16) (2*x + 8), (s16) (2*y + 7), 0x281);
                set_block_id((s16) (2*x + 7), (s16) (2*y + 8), 0x281);
                set_block_id((s16) (2*x + 8), (s16) (2*y + 8), 0x281);
                set_block_id((s16)(2*x+7+x_displacement), (s16)(2*y+7+y_displacement), stone_block);
                break;
            }
        }
    }

}

void dungeon_decorate(dungeon_generator *d){
    
    int i;
    for(i = 0; i < d->width * d->height / 13; i++){
        //pick a random tile and decorate it
        s16 x = (s16)(dungeon_random_next_16(d) % d->width);
        s16 y = (s16)(dungeon_random_next_16(d) % d->height);
        if(dungeon_is_block_passable(x, y, d)){
            //passable block to decorate
            dungeon_decorate_passable_segment(x, y, d);
        }else{
            
        }
    }
}

void dungeon_compute_blocks() {
    
    if (dflags->blocks_initialized) {
        //The blocks were already loaded, so we use the same seed
        cmem->dgen.seed = cmem->dgen.initial_seed;
    }

    dflags->blocks_initialized = 1;

    dungeon_generator *d = &(cmem->dgen);

    //build a buffer of flags that state if a tile is enabled or not
    d->dbuf = cmalloc((u32) ((d->width) * (d->height) / 8));


    //first we compute the dungeon
    dungeon_compute_rooms(d);
    dungeon_compute_paths(d);
    dungeon_attempt_additional_placements(d);
    dungeon_compute_tile_map(d);
    dungeon_decorate(d);
    dungeon_relocate_events(d);

    free(d->dbuf);
    free(d->rooms);

    foot_ddata->footer = &(cmem->footer);
    //special_x8E_update_map_graphics();

}

u32 dungeon_random_next_32(dungeon_generator *d) {
    return (u32) ((dungeon_random_next_16(d) << 16) | dungeon_random_next_16(d));
}

u16 dungeon_random_next_16(dungeon_generator *d) {
    d->seed = (u32) (d->seed * 0x41C64E6D + 0x6073);
    return (u16) (d->seed >> 16);
}

u8 dungeon_random_next_8(dungeon_generator *d) {
    return (u8) dungeon_random_next_16(d);
}
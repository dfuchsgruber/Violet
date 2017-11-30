#include "types.h"
#include "romfuncs.h"
#include "save.h"
#include "item.h"
#include "tile.h"
#include "rtc.h"

void generate_trash_item(u8 facing) {

    u16 item = 0;
    if (!check_trashflag(facing)) {

        u32 hash = (u32)get_tile_hash_by_facing(facing, 97);
        if (!hash) {
            //Leftovers
            item = ITEM_UEBERRESTE;
        } else if (hash < 8) {
            //Rare berries
            int berry_index = get_tile_hash_by_facing(facing, 7);
            item = (u16) (ITEM_LYDZIBEERE + berry_index);
        } else if (hash < 20) {
            //Common berries
            int berry_index = get_tile_hash_by_facing(facing, 11);
            item = (u16) (ITEM_AMRENABEERE + berry_index);
        }
    }
    *vardecrypt(0x8000) = item;
}

void special_set_trashflag() {
    set_trashflag((u8) (*vardecrypt(0x800C)));
}

bool check_trashflag(u8 facing) {

    int hashflag = get_tile_hash_by_facing(facing, 127);
    int mask = 1 << (hashflag & 7);
    int value = cmem->trash_flags[hashflag >> 3] & mask;
    return value != 0;
}

void set_trashflag(u8 facing) {
    int hashflag = get_tile_hash_by_facing(facing, 127);
    u8 mask = (u8) (1 << (hashflag & 7));
    cmem->trash_flags[hashflag >> 3] |= mask;
}

int get_tile_hash_by_facing(u8 facing, int m) {

    s16 pos[2];
    get_current_tile_position(&pos[0], &pos[1]);
    switch (facing) {
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
    return a_hash(pos[0], pos[1], (*save1)->map, (*save1)->bank, m);
}

/**
 * returns hash value of trash from 0 to m-1
 **/
int a_hash(s16 x, s16 y, u8 map, u8 bank, int m) {

    int h = (x * cmem->a_vector[0]) + (y * cmem->a_vector[1]) + (map * cmem->a_vector[2]) + (bank * cmem->a_vector[3]);
    return h % m;


}

void new_a_vector() {

    int i;
    for (i = 0; i < 4; i++) {
        cmem->a_vector[i] = (u8) random_change_seed();
    }
    rtc_read(&(cmem->a_gen_time));

}

void reset_trash_flags() {
    int i;
    for (i = 0; i < 16; i++) {
        cmem->trash_flags[i] = 0;
        cmem->any_a_flags[i] = 0;
    }

}

void update_a_vector() {
    //cpuset(0, &(cmem->flag_extension[0x40]), CPUSET_WORD | CPUSET_FILL | 8);
    
    rtc_timestamp current_time;
    rtc_read(&current_time);

    int day_difference = (current_time.year * 365 + current_time.month * 30 + current_time.day) -
            (cmem->a_gen_time.year * 365 + cmem->a_gen_time.month * 30 + cmem->a_gen_time.day);
    if (day_difference >= 7) {
        new_a_vector();
        reset_trash_flags();
    }
}


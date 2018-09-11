#include "types.h"
#include "save.h"
#include "constants/items.h"
#include "tile/trash.h"
#include "rtc.h"
#include "vars.h"
#include "prng.h"
#include "debug.h"

void generate_trash_item(u8 facing) {

    u16 item = 0;
    if (!check_trashflag(facing)) {

        u32 hash = (u32)get_tile_hash_by_facing(facing, 97);
        if (!hash) {
            //Leftovers
            item = ITEM_UEBERRESTE;
        } else if (hash < 8) {
            //Rare berries
            u32 berry_index = get_tile_hash_by_facing(facing, 7);
            item = (u16) (ITEM_LYDZIBEERE + berry_index);
        } else if (hash < 20) {
            //Common berries
            u32 berry_index = get_tile_hash_by_facing(facing, 11);
            item = (u16) (ITEM_AMRENABEERE + berry_index);
        }
    }
    *var_access(0x8000) = item;
}

void special_set_trashflag() {
    set_trashflag((u8) (*var_access(0x800C)));
}

bool check_trashflag(u8 facing) {

    u32 hashflag = get_tile_hash_by_facing(facing, 127);
    int mask = 1 << (hashflag & 7);
    int value = cmem->trash_flags[hashflag >> 3] & mask;
    return value != 0;
}

void set_trashflag(u8 facing) {
    u32 hashflag = get_tile_hash_by_facing(facing, 127);
    u8 mask = (u8) (1 << (hashflag & 7));
    cmem->trash_flags[hashflag >> 3] |= mask;
}

u32 get_tile_hash_by_facing(u8 facing, size_t m) {

    s16 pos[2];
    player_get_position(&pos[0], &pos[1]);
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
    u32 seq[4];
    seq[0] = (u32)(pos[0]);
    seq[1] = (u32)(pos[1]);
    seq[2] = (u32)((*save1)->map);
    seq[3] = (u32)((*save1)->bank);
    return tmp_hash(seq, 4) % m;
}


u32 tmp_hash(u32 seq[], size_t size) {
	// Hashing according to https://stackoverflow.com/a/27216842/7292394
	u32 seed = cmem->tmp_hash_seed;

	// Also use "salt" to enlarge the sequence
	u32 salt[4] = {0xffbfa3a1, 0xcfd893ce, 0x121420e0, 0x7e87aa4b};

	for (size_t idx = 0; idx < size + 4; idx++) {
		u32 i = idx < size ? seq[idx] : salt[idx - size];
		seed = (u32)(seed ^ (i + 0x9e3779b9 + (seed << 6) + (seed >> 2)));
	}
	return seed;
}


void tmp_hash_new_seed() {
	cmem->tmp_hash_seed = (u32)((rnd16() << 16) | rnd16());
    rtc_read(&(cmem->a_gen_time));

}

void tmp_flags_reset() {
    int i;
    for (i = 0; i < 16; i++) {
        cmem->trash_flags[i] = 0;
        cmem->any_tmp_flags[i] = 0;
        cmem->dungeon_flags[i] = 0;
    }
}

u32 dungeon_hash(int dungeon_id) {
	u32 seq[1];
	seq[0] = (u32)dungeon_id;
	// Hash the dungeon_id to 0, ..., 126
	return tmp_hash(seq, 1) % 127;
}

bool dungeon_flag_check(int dungeon_id) {
	u32 flag = dungeon_hash(dungeon_id);
	if (flag < 64) {
		// If the dungeon hashes to something < 64, it will be made availible
		int byte_num = (int)flag >> 3;
		int mask = 1 << (flag & 7);
		return (cmem->dungeon_flags[byte_num] & mask) != 0;
	} else {
		// The dungeon is not availible with the current a-vector
		return true;
	}
}

void dungeon_flag_set(int dungeon_id) {
	u32 flag = dungeon_hash(dungeon_id);
	if (flag < 64) {
		// If the dungeon hashes to something < 64, it will be made availible
		int byte_num = (int)flag >> 3;
		int mask = 1 << (flag & 7);
		cmem->dungeon_flags[byte_num] = (u8)(cmem->dungeon_flags[byte_num] | mask);
	}
}


void tmp_hash_update_seed() {
    //cpuset(0, &(cmem->flag_extension[0x40]), CPUSET_WORD | CPUSET_FILL | 8);
    
    rtc_timestamp current_time;
    rtc_read(&current_time);

    int day_difference = (current_time.year * 365 + current_time.month * 30 + current_time.day) -
            (cmem->a_gen_time.year * 365 + cmem->a_gen_time.month * 30 + cmem->a_gen_time.day);
    if (day_difference >= 1) {
        tmp_hash_new_seed();
        tmp_flags_reset();
    }
}


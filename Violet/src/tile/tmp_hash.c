#include "types.h"
#include "save.h"
#include "constants/items.h"
#include "tile/trash.h"
#include "rtc.h"
#include "vars.h"
#include "prng.h"
#include "debug.h"

void trash_get_item() {

    u16 item = 0;
    coordinate_t pos;
    player_get_facing_position(&pos.x, &pos.y);

    if (!trash_checkflag(pos.x, pos.y, save1->bank, save1->map)) {
        u32 r = tile_hash_by_position(pos.x, pos.y, save1->bank, save1->map, 97);
        dprintf("Trash hash value is %d\n", r);
        if (r == 0) {
            // 1 / 97 chance for leftovers
            item = ITEM_UEBERRESTE;
        } else if (r < 10) {
            // 9 / 97 chance for rare berries
            u32 berry_index = tile_hash_by_position(pos.x, pos.y, save1->bank, save1->map, 7);
            item = (u16) (ITEM_LYDZIBEERE + berry_index);
        } else if (r < 25) {
            // 15 / 97 chance for common berries
            u32 berry_index = tile_hash_by_position(pos.x, pos.y, save1->bank, save1->map, 11);
            item = (u16) (ITEM_AMRENABEERE + berry_index);
        }
    }
    *var_access(0x8000) = item;
}

void special_set_trashflag() {
    coordinate_t pos;
    player_get_facing_position(&pos.x, &pos.y);
    trash_setflag(pos.x, pos.y, save1->bank, save1->map);
}

bool trash_checkflag(s16 x, s16 y, u8 bank, u8 map_idx) {
    u32 hashflag = tile_hash_by_position(x, y, bank, map_idx, 127);
    int mask = 1 << (hashflag & 7);
    int value = cmem.trash_flags[hashflag >> 3] & mask;
    return value != 0;
}

void trash_setflag(s16 x, s16 y, u8 bank, u8 map_idx) {
    u32 hashflag = tile_hash_by_position(x, y, bank, map_idx, 127);
    u8 mask = (u8) (1 << (hashflag & 7));
    cmem.trash_flags[hashflag >> 3] |= mask;
}

u16 tile_hash_by_position(s16 x, s16 y, u8 bank, u8 map_idx, size_t m) {
    u32 seq[4] = {
        (u32)x, (u32)y, bank, map_idx,
    };
    u16 hash = (u16)tmp_hash(seq, 4);
    dprintf("Hash value %x\n", hash);
    return (u16)(hash % m);
}


u32 tmp_hash(u32 seq[], size_t size) {
	// Hashing according to https://stackoverflow.com/a/27216842/7292394
	u32 seed = cmem.tmp_hash_seed;

	// Also use "salt" to enlarge the sequence
	u32 salt[4] = {0xffbfa3a1, 0xcfd893ce, 0x121420e0, 0x7e87aa4b};

	for (size_t idx = 0; idx < size + 4; idx++) {
		u32 i = idx < size ? seq[idx] : salt[idx - size];
		seed = (u32)(seed ^ (i + 0x9e3779b9 + (seed << 6) + (seed >> 2)));
	}
	return seed;
}


void tmp_hash_new_seed() {
	cmem.tmp_hash_seed = (u32)((rnd16() << 16) | rnd16());
    time_read(&(cmem.a_gen_time));

}

void tmp_flags_reset() {
    int i;
    for (i = 0; i < 16; i++) {
        cmem.trash_flags[i] = 0;
        cmem.any_tmp_flags[i] = 0;
        cmem.dungeon_flags[i] = 0;
    }
}

u32 dungeon_hash(int dungeon_id) {
	u32 seq[1];
	seq[0] = (u32)dungeon_id;
	// Hash the dungeon_id to 0, ..., 126
	return (u16)tmp_hash(seq, 1) % 127;
}

bool dungeon_flag_check(int dungeon_id) {
	u32 flag = dungeon_hash(dungeon_id);
	if (flag < 64) {
		// If the dungeon hashes to something < 64, it will be made availible
		int byte_num = (int)flag >> 3;
		int mask = 1 << (flag & 7);
		return (cmem.dungeon_flags[byte_num] & mask) != 0;
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
		cmem.dungeon_flags[byte_num] = (u8)(cmem.dungeon_flags[byte_num] | mask);
	}
}


void tmp_hash_update_seed() {
    //cpuset(0, &(cmem.flag_extension[0x40]), CPUSET_WORD | CPUSET_FILL | 8);
    
    rtc_timestamp current_time;
    time_read(&current_time);

    int day_difference = (current_time.year * 365 + current_time.month * 30 + current_time.day) -
            (cmem.a_gen_time.year * 365 + cmem.a_gen_time.month * 30 + cmem.a_gen_time.day);
    if (day_difference >= 1) {
        tmp_hash_new_seed();
        tmp_flags_reset();
    }
}


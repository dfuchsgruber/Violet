#include "types.h"
#include "save.h" 
#include "constants/items.h"
#include "rtc.h"
#include "vars.h"
#include "prng.h"
#include "debug.h"
#include "overworld/misc.h"

u16 tile_hash_by_position(s16 x, s16 y, u8 bank, u8 map_idx, size_t m) {
    u32 seq[4] = {
        (u32)x, (u32)y, bank, map_idx,
    };
    u16 hash = (u16) daily_events_hash(seq, 4);
    dprintf("Hash value %x\n", hash);
    return (u16)(hash % m);
}

u32 daily_events_hash(u32 seq[], size_t size) {
	// Hashing according to https://stackoverflow.com/a/27216842/7292394
	u32 seed = cmem.daily_events_seed;

	// Also use "salt" to enlarge the sequence
	u32 salt[4] = {0xffbfa3a1, 0xcfd893ce, 0x121420e0, 0x7e87aa4b};

	for (size_t idx = 0; idx < size + 4; idx++) {
		u32 i = idx < size ? seq[idx] : salt[idx - size];
		seed = (u32)(seed ^ (i + 0x9e3779b9 + (seed << 6) + (seed >> 2)));
	}
	return seed;
}


void daily_events_new_seed() {
	cmem.daily_events_seed = (u32)((rnd16() << 16) | rnd16());
    time_read(&(cmem.daily_events_last_update));
}

void daily_events_reset() {
    int i;
    for (i = 0; i < 16; i++) {
        cmem.any_tmp_flags[i] = 0;
        cmem.dungeon_flags[i] = 0;
    }
    overworld_misc_intialize();
}

u32 dungeon_hash(int dungeon_id) {
	u32 seq[1];
	seq[0] = (u32)dungeon_id;
	// Hash the dungeon_id to 0, ..., 126
	return (u16)daily_events_hash(seq, 1) % 127;
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


void daily_events_proceed() {
    rtc_timestamp current_time;
    time_read(&current_time);
    u64 seconds_current = rtc_timestamp_to_seconds(&current_time);
    u64 seconds_update = (u64) (rtc_timestamp_to_seconds(&cmem.daily_events_last_update) + 24 * 60 * 60);
    if (seconds_current >= seconds_update) {
        daily_events_new_seed();
        daily_events_reset();
    }
}


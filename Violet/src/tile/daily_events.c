#include "types.h"
#include "save.h" 
#include "constants/items.h"
#include "rtc.h"
#include "vars.h"
#include "prng.h"
#include "debug.h"
#include "overworld/misc.h"
#include "flags.h"

u16 tile_hash_by_position(s16 x, s16 y, u8 bank, u8 map_idx, size_t m) {
    u32 seq[4] = {
        (u32)x, (u32)y, bank, map_idx,
    };
    u16 hash = (u16) daily_events_hash(seq, 4);
    dprintf("Hash value %x\n", hash);
    return (u16)(hash % m);
}

u32 hash_sequence(u32 seq[], size_t size, u32 seed) {
	// Hashing according to https://stackoverflow.com/a/27216842/7292394
	for (size_t idx = 0; idx < size; idx++) {
		u32 i = seq[idx] * 0xdeece66d + 0xb; // The ints are individually hashed to prevent nearby sequences to be close
		seed = (u32)(seed ^ (i + 0x9e3779b9 + (seed << 6) + (seed >> 2)));
	}
	return seed;
}

u32 daily_events_hash(u32 seq[], size_t size) {
	u32 seed = cmem.daily_events_seed;
	return hash_sequence(seq, size, seed);
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
	dprintf("get dungeon flag %d\n", dungeon_id);
	if (dungeon_id < 128) {
		return checkflag((u16)(FLAG_DUNGEON_BASE + dungeon_id));
	}
	return true;
}

void dungeon_flag_set(int dungeon_id) {
	dprintf("Set dungeon flag %d\n", dungeon_id);
	setflag((u16)(FLAG_DUNGEON_BASE + dungeon_id));
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


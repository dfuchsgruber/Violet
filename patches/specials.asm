	
special_table equ 0x0815FCC0

.org (special_table + (0x6 * 4))
        .word spawn_mugshot | 1
        .pool

.org (special_table + (0x7 * 4))
        .word clear_mugshot | 1
        .pool

.org (special_table + (0xC * 4))
	.word special_addkarma_wrap | 1
	.pool
	
.org (special_table + (0x13 * 4))
        .word pokeradar_spawn_pokemon | 1
        .pool

.org (special_table + (0x16 * 4))
	.word special_get_rtc | 1
	.pool
	
.org (special_table +(0x17 * 4))
	.word special_set_trashflag | 1
	.pool
	
.org (special_table +(0x18 * 4))
	.word reset_trash_flags | 1
	.pool

.org (special_table +(0x19 *4))
        .word init_anim_engine_by_table | 1
        .pool

.org (special_table + (0x1A * 4))
        .word special_prepeare_player_facing | 1
        .pool
.org (special_table + (0x1B * 4))
        .word special_move_npc_to_player | 1
        .pool

// NOTE !!!!!!!!!! AFTER 0x1B THERE IS NOT ANYMORE FREE SPECIAL SPACE! !!!!!!!!!!!!!!!!!


/// From 0x24 to (inclusvie) 0x26 are 3 free nullsub specials
.org (special_table + (0x24 * 4))
        .word special_move_npc_to | 1// replace with real special 0x24
        .pool

.org (special_table + (0x25 * 4))
        .word special_gamble_remove | 1
        .pool

.org (special_table + (0x26 * 4))
        .word special_heal_team_index | 1
        .pool

/// From 0x2B are 7 free specials
.org (special_table + (0x2B * 4))
        .word cloud_force | 1
        .pool

.org (special_table + (0x2C * 4))
        .word cloud_enter | 1
        .pool

.org (special_table +(0x36 *4))
        .word special_x36_check_loaded_trainerflag | 1
        .pool


	
special_table equ 0x0815FCC0

.org (special_table + (0x6 * 4))
        .word special_mugshot_show | 1
        .pool

.org (special_table + (0x7 * 4))
        .word special_mugshot_delete | 1
        .pool

.org (special_table + (0x8 * 4))
		.word time_test | 1
		.pool

.org (special_table + (0xC * 4))
	.word special_addkarma_wrap | 1
	.pool

.org (special_table + (0xE * 4))
	.word special_show_name | 1

.org (special_table + (0xF * 4))
	.word special_delete_name | 1
	
.org (special_table + (0x13 * 4))
        .word pokeradar_spawn_pokemon | 1
        .pool

.org (special_table + (0x16 * 4))
	.word special_time_get | 1
	.pool
	
.org (special_table +(0x17 * 4))
	.word special_set_trashflag | 1
	.pool
	
.org (special_table +(0x18 * 4))
	.word tmp_flags_reset | 1
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

.org (special_table + (0x24 * 4))
        .word special_move_npc_to | 1// replace with real special 0x24
        .pool

.org (special_table + (0x25 * 4))
        .word special_gamble_remove | 1
        .pool

.org (special_table + (0x26 * 4))
        .word special_heal_team_index | 1
        .pool

.org (special_table + (0x2B * 4))
        .word cloud_force | 1
        .pool

.org (special_table + (0x2C * 4))
        .word cloud_enter | 1
        .pool

.org (special_table + (0x2D * 4))
        .word warp_to_pos_with_facing | 1
        .pool

.org (special_table +(0x2E *4))
        .word access_card_print_multichoice | 1
        .pool

.org (special_table +(0x2F *4))
        .word access_card_execute_elevator | 1
        .pool

.org (special_table + (0x30 *4))
        .word access_card_init_by_atrium | 1
        .pool
.org (special_table + (0x31 *4))
        .word transparency_load_black_box_pals | 1
        .pool

.org (special_table +(0x36 *4))
        .word special_x36_check_loaded_trainerflag | 1
        .pool

.org (special_table + (0x3E * 4))
        .word fossil_print_multichoice | 1
        .pool

.org (special_table + (0x3F * 4))
        .word fossil_execute | 1
        .pool

.org (special_table + (0x40 * 4))
        .word fossil_is_finished | 1
        .pool

.org (special_table + (0x41 * 4))
        .word pokemon_team_knows_hm | 1
        .pool

.org (special_table + (0x42 * 4))
        .word pokemon_team_remove | 1
        .pool

.org (special_table + (0x43 * 4))
        .word version_init | 1
        .pool

.org (special_table + (0x44 * 4))
        .word version_transfer | 1
        .pool

.org (special_table + (0x46 * 4))
        .word special_ash_can_store | 1
        .pool

.org (special_table + (0x47 * 4))
        .word mushroom_create | 1
        .pool

.org (special_table + (0x48 * 4))
        .word repel_use | 1
        .pool

.org (special_table + (0x49 * 4))
        .word version_is_latest | 1
        .pool

.org (special_table + (0x4A * 4))
        .word special_query_present_code | 1
        .pool

.org (special_table+ (0x4B * 4))
		.word dungeon_map_entrance_get_type | 1
		.pool

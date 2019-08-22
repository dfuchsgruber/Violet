	
special_table equ 0x0815FCC0

.org (special_table + (0x0 * 4))
        .word player_party_heal | 1
        .pool

.org (special_table + (0x6 * 4))
        .word special_mugshot_show | 1
        .pool

.org (special_table + (0x7 * 4))
        .word special_mugshot_delete | 1
        .pool

.org (special_table + (0x8 * 4))
		.word time_test | 1
		.pool

.org (special_table + (0x9 * 4))
		.word rock_climb_block_is_climbable | 1
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
        .word special_player_facing | 1
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
        .word special_player_party_heal_index | 1
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
		.word special_overworld_script_give_egg | 1
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

.org (special_table + (0x4C * 4))
		.word special_overworld_script_give_egg_into_incubator_slots | 1
		.pool

.org (special_table + (0x4D * 4))
		.word player_party_contains_species | 1
		.pool

.org (special_table + (0x4E * 4))
                .word special_daycare_egg_new_into_incubator | 1
                .pool

.org (special_table + (0x4F * 4))
                .word incubator_has_empty_slots | 1
                .pool

.org (special_table + (0x50 * 4))
                .word route_9_cave_puzzle_get_state | 1

.org (special_table + (0x51 * 4))
                .word route_9_cave_puzzle_set_last_rock | 1

.org (special_table + (0x52 * 4))
                .word route_9_cave_puzzle_get_last_rock | 1

.org (special_table + (0x53 * 4))
                .word route_9_cave_puzzle_rock | 1

.org (special_table + (0x54 * 4))
                .word route_9_cave_puzzle_reset | 1

.org (special_table + (0x55 * 4))
                .word ceometria_gym_person_buffer_target_room | 1

.org (special_table + (0x56 * 4))
                .word ceometria_gym_waiting_room_person_get_script | 1

.org (special_table + (0x57 * 4))
                .word ceometria_gym_punishment_room_get_script | 1

.org (special_table + (0x58 * 4))
                .word ceometria_gym_punishment_get_eligible_index | 1

.org (special_table + (0x59 * 4))
                .word ceometria_gym_get_number_waiting_rooms | 1
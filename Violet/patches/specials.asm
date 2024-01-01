	
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
	.word 0
	.pool
	
.org (special_table +(0x18 * 4))
	.word daily_events_reset | 1
	.pool

.org (special_table +(0x19 *4))
        .word special_cutscene_show | 1
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
/** 
.org (special_table + (0x31 *4))
        .word transparency_load_black_box_pals | 1
        .pool
*/
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

.org (special_table + (0x4B * 4))
		.word dungeon2_get_dungeon_type_by_person_faced
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

.org (special_table + (0x5A * 4))
                .word pokemon_has_type | 1

.org (special_table + 91 * 4)
                .word player_party_spells_unown_message | 1

.org (special_table + 97 * 4)
                .word overworld_unown_print_message | 1

.org (special_table + 98 * 4)
                .word overworld_unown_delete_message | 1

.org (special_table + 99 * 4)
                .word npc_move_camera_to | 1

.org (special_table + 100 * 4)
                .word overworld_person_get_position | 1

.org (special_table + 101 * 4)
                .word fishing_start_after_bait_selection | 1

.org (special_table + 102 * 4)
                .word route_7_secret_power_lab_count_missing_species | 1

.org (special_table + 103 * 4)
                .word battle_ally_save_and_setup_party | 1

.org (special_table + 104 * 4)
                .word overworld_target_npc_set_to_var | 1
.org (special_table + 105 * 4)
                .word battle_handicap_set | 1
.org (special_table + 106 * 4)
                .word battle_handicap_clear | 1

.org (special_table + 107 * 4)
        .word special_buffer_badge_name | 1

.org (special_table + 108 * 4)
        .word berry_tree_get_stage | 1
.org (special_table + 109 * 4)
        .word berry_tree_get_item | 1
.org (special_table + 110 * 4)
        .word berry_tree_get_yield | 1
.org (special_table + 111 * 4)
        .word berry_tree_update_gfx | 1
.org (special_table + 112 * 4)
        .word berry_pick | 1
.org (special_table + 113 * 4)
        .word berry_plant | 1
.org (special_table + 114 * 4)
        .word special_berry_tree_grow | 1
.org (special_table + 115 * 4)
        .word aggressive_wild_get_approaching_species | 1
.org (special_table + 116 * 4)
        .word special_mushroom_get_stage | 1
.org (special_table + 117 * 4)
        .word special_shell_get_stage | 1
.org (special_table + 118 * 4)
        .word mushroom_get_encounter | 1


.org (special_table + 134 * 4)
        .word shell_get_encounter | 1
.org (special_table + 135 * 4)
        .word special_overworld_effect_explosion | 1
.org (special_table + 136 * 4)
        .word npc_move_to_block_movements | 1
.org (special_table + 137 * 4)
        .word npc_move_to_unblock_movements | 1
.org (special_table + 138 * 4)
        .word special_map_transition_show_namespace | 1
.org (special_table + 139 * 4)
        .word composter_initialize | 1
.org (special_table + 140 * 4)
        .word berry_is_fertilized | 1
.org (special_table + 143 * 4)
        .word berry_fertilize | 1
.org (special_table + 144 * 4)
        .word special_overworld_person_face_to_person | 1
.org (special_table + 145 * 4)
        .word special_delete_rage_sprite | 1
.org (special_table + 146 * 4)
        .word pal_tmp_synchronize_with_pal_restore | 1

.org (special_table + 172 * 4)
        .word incubator_hatch_egg_backup_player_party | 1
.org (special_table + 173 * 4)
        .word incubator_add_hatched_pokemon_to_party_or_box | 1
.org (special_table + 174 * 4)
        .word incubator_attempt_add_slot | 1
.org (special_table + 175 * 4)
        .word special_overworld_viewport_set_position | 1
.org (special_table + 176 * 4)
        .word overworld_viewport_set_position_to_player | 1
.org (special_table + 177 * 4)
        .word automatic_hm_usage_active | 1
.org (special_table + 178 * 4)
        .word player_pokemon_get_highest_level_flash_user | 1
.org (special_table + 179 * 4)
        .word special_overworld_effect_sound_wave | 1
.org (special_table + 201 * 4)
        .word special_player_get_position_facing | 1
.org (special_table + 202 * 4)
        .word special_buffer_type_name | 1
.org (special_table + 203 * 4)
        .word special_trash_get_type | 1
.org (special_table + 204 * 4)
        .word trash_get_encounter_or_item | 1
.org (special_table + 207 * 4)
        .word special_overworld_effect_lightning | 1
.org (special_table + 208 * 4)
        .word special_item_obtain_show | 1
.org (special_table + 209 * 4)
        .word special_item_obtain_delete | 1
.org (special_table + 210 * 4)
        .word berry_yields_flower | 1
.org (special_table + 211 * 4)
        .word overworld_accessible_move_tutor_select_pokemon | 1
// 207 <= free <= 211

.org (special_table + (0x129 * 4))
                .word special_roamer_reset_and_initialize | 1

.org special_table + 0x138 * 4
                .word wild_battle_legendary_initialize | 1

.org special_table + 224 * 4
        .word move_relearner_initialize | 1

.org special_table + 251 * 4
        .word special_worldmap_ui_std | 1

evolution_table equ 0x9195500
special_table equ 0x0815FCC0

//mega evolution
.org 0x0802E3D0
	ldr r0, =hook_show_mega_icon | 1
	bx r0
	.pool
	
.org 0x0802E9A8
	ldr r0, =mega_hook_hide_icon | 1
	bx r0
	.pool
	
.org 0x0801553c
	.word destroy_mega_triggers | 1
	.pool
	
.org 0x08032A94
	ldr r0, =mega_trigger_reset | 1
	bx r0
	.pool
	
.org 0x0803485C
	ldr r0, =hook_spawn_symbol | 1
	bx r0
	.pool
	
.org 0x0802C150
	ldr r0, =hook_item_swap | 1
	bx r0
	.pool
	
.org 0x08020FDC
	ldr r0, =hook_knock_off | 1
	bx r0
	.pool
	
.org 0x08020D44
	ldr r0, =hook_thief | 1
	bx r0
	.pool

.org 0x08250814
	.word hook_bag_destroy_trigger | 1
	.pool

.org 0x08250818
	.word hook_pokemon_destroy_trigger | 1
	.pool
	
	
// tm hack
.org 0x08132752
	mov r0, #1
	.pool
	
.org 0x0809BD20
	ldr r1, =tm_sale | 1
	bx r1
	.pool
	
.org 0x0809BE44
	ldr r0, =tm_count_arrows | 1
	bx r0
	.pool
	
//transparency
.org 0x08069848
	ldr r0, =transparency_script_handler | 1
	bx r0
	.pool
	
	
//tile
.org 0x0806d684
	ldr r0, =tile_step | 1
	bx r0
	.pool
	
//help menu
.org 0x083CC1A0
	.word 0x088FAEAB
	.word 0x088FB194
	.word 0x088FB19F
	.pool

.org 0x083CC170
	.word 0x088FAEA0
	.pool
	
.org 0x08000652
	mov r0, #0
	.pool
	
	
//misc
.org 0x080C9D84
	.word new_flash_script
	.pool
	
//flash radius in caves will be kept
.org 0x08055CFC
	pop {r0}
	bx r0 
	.pool

//trainer
.org 0x0803D9B8
	ldr r0, =hook_build_trainer_poke | 1
	bx r0
	.pool

//evolutions
.org 0x08045878
	ldr r1, =get_pokemons_basis_stage | 1
	bx r1
	.pool
	
.org 0x08042E98
	ldr r0, =evolutions_evee | 1
	bx r0
	.pool

.org (evolution_table + ((0x10-1) * 4)) //evolution method 0xF, map
	.word evolution_m_map
	.pool

.org (evolution_table + ((0x11-1) * 4)) //evolution method holding item
	.word evolution_m_hitem
	.pool
	
.org (evolution_table + ((0x12-1) * 4)) //evolution method knowing move
	.word evolution_m_know_move
	.pool

.org (evolution_table + ((0x14-1) * 4)) //evolution method link & item hold
	.word 0x08043010
	.pool
	
.org (evolution_table + ((0x15-1) * 4)) //evolution method funkelstein&male
	.word 0x08043010
	.pool
	
.org 0x08043084
	ldr r0, =evolution_m_litem | 1
	bx r0
	.pool
	
.org 0x080419E4
	.word evolution_stone_remove_item
	.pool

//wild poke
.org 0x0803DA0C
	ldr r1, =wild_poke_less_shinies | 1
	bx r1
	.pool


//fp_menu
.org 0x0919D534
	.word init_fp_menu | 1
	.pool

//abilities and items
.org 0x0801A378
	ldr r0, =end_of_turn_ab | 1
	bx r0
	.pool


//scarf
.org 0x8014DC0
	ldr r2, =scarf_poke1_hook | 1
	bx r2
	.pool

.org 0x8014EA4
	ldr r2, =scarf_poke2_hook | 1
	bx r2
	.pool
	
.org 0x0803EE4C
	ldr r0, =choice_band_on_0 | 1
	bx r0
	.pool


//attack split
.org 0x0803EE04
	ldr r1, = physical_special_item_load| 1
	bx r1
	.pool
	
	
//dynamic maps
.org 0x08055258
	ldr r2, =get_mapheader | 1
	bx r2
	.pool

.org 0x080589FC
	ldr r0, =dynamic_block_loader | 1
	bx r0
	.pool
	
.org 0x08055190
	ldr r0, =get_mapfooter | 1
	bx r0
	.pool
	
	
.org 0x08058A58
	ldr r0, =reset_mapchanges_hook | 1
	bx r0
	.pool
	
.org (0x0815F914 + (0x8e * 4))
	.word special_dungeon_warpback | 1
	.pool
	
.org 0x806D154
	ldr r0, =hook_get_behavior_script | 1
	bx r0
	.pool
	
.org (special_table + (0xC * 4))
	.word special_addkarma_wrap | 1
	.pool
	
.org (special_table +(0x16 * 4))
	.word special_get_rtc | 1
	.pool
	
.org (special_table +(0x17 * 4))
	.word special_set_trashflag | 1
	.pool
	
.org (special_table +(0x18 * 4))
	.word reset_trash_flags
	.pool

.org 0x0802596C
	ldr r0, =hook_price_money | 1
	bx r0
	.pool
	
.org 0x08021b60
	ldr r2, =hook_exp | 1
	bx r2
	.pool
	
.org 0x0809a9f0
	ldr r1, =hook_item_prices | 1
	bx r1
	.pool
	
.org 0x080C6F38
	ldr r0, =hook_trainer_items | 1
	bx r0
	.pool

.org 0x080598CC
	ldr r2, =dns_hook_apply_shaders | 1
	bx r2
	.pool
	
.org 0x08059948
	ldr r2, =dns_hook_apply_shaders2 | 1
	bx r2
	.pool
	
.org 0x080834FC
	ldr r1, =dns_hook_apply_shaders3 | 1
	bx r1
	.pool
	
.org 0x08056824
	.word callback_switch_timezone | 1
	.pool
	
.org 0x08056758
	ldr r0, =hook_update_timezone | 1
	bx r0
	.pool
	
.org 0x0800F1E4
	ldr r1, =battle_bg_load | 1
	bx r1
	.pool

.org 0x08059AE4
	ldr r0, =hook_tile_init | 1
	bx r0
	.pool
	
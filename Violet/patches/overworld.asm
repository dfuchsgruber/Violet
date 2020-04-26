overworld_pals equ 0x083A501C

.org 0x0805F2C8
    ldr r1, =overworld_get | 1
    bx r1
    .pool

.org overworld_pals + 8 * 8
    .word gfx_ow_pal_hiroPal

.org overworld_pals + 9 * 8
    .word gfx_ow_pal_hiro_mirrorPal

.org overworld_pals + 0xD * 8
    .word gfx_ow_pal_hiroinePal

.org overworld_pals + 0xE * 8
    .word gfx_ow_pal_hiroine_mirrorPal

.org overworld_pals + 0xB * 8
    .word gfx_ow_pal_violetPal

.org overworld_pals + 0xC * 8
    .word gfx_ow_pal_violet_mirrorPal

.org overworld_pals + 0x10 * 8
    .word gfx_ow_pal_bbshipPal


////////////////////////////////////////////////////////////////////////////////

.org 0x8064540
    .word npc_anims

.org 0x8064584
    .word npc_anims

.org 0x80645B4
    .word npc_anims

.org 0x0805b9d4
    ldr r2, =npc_player_initialize_move_not_biking | 1
    bx r2
    .pool

.org 0x080bd3b4
    ldr r2, = npc_player_initialize_move_on_bike | 1
    bx r2
    .pool

//.org 0x0805ba06
//    ldr r0, =npc_player_initialize_step_movement_hook | 1
//    bx r0
//    .pool

.org 0x0805bba8
    push {r4, lr}
    ldr r4, =npc_player_attempt_step | 1
    bl blxr4_0805bba8
    pop {r4}
    pop {r1}
    bx r1
blxr4_0805bba8:
    bx r4
    .pool

//Bg alignment
.org 0x0805A5F4
    ldr r0, =bg_alignment | 1
    bx r0
    .pool

//Dynamic multichoice
.org 0x0809CB90
    ldr r0, =dynamic_multichoice_hook | 1
    bx r0
    .pool

//Fix for weird overworld of rival in intro...
.org 0x083E18C0
    .word gfx_ow_rival_allTiles

.org 0x083E18C8
    .word gfx_ow_rival_allPal


//Npc Interaction
.org 0x083A543C
    .word ow_hiro_surf_graphics

.org 0x083A54D4
    .word ow_hiro_arrow_graphics

.org 0x083C71E0
    .word ow_hiro_emoji_graphics

.org 0x083A5CD0
    .word ow_hiro_fly_graphics

.org overworld_script_commands + 4 * 0x5C
    .word overworld_script_command_trainerbattle | 1

.org overworld_script_commands + 4 * 0x6E
    .word script_cmd_x6E_yesnobox | 1

.org overworld_script_commands + 4 * 0x6F
    .word script_cmd_x6F_multichoice | 1

.org overworld_script_commands + 4 * 0x70
    .word script_cmd_x70_multichoice_with_default | 1

.org overworld_script_commands + 4 * 0x71
    .word script_cmd_x71_multichoice_grid | 1

.org overworld_script_commands + 4 * 0x77
    .word overworld_script_command_close_braille | 1

.org overworld_script_commands + 4 * 0x78
    .word overworld_script_command_braille | 1

.org overworld_script_commands + 4 * 0x97
    .word script_cmd_x97_fadescreen | 1

.org overworld_script_commands + 4 * 0xA2
    .word overworld_script_command_setmaptile | 1

// Overworld script std strings
.org 0x0806BE74
	.word ow_script_string_stds

// Giveegg
.org 0x080A02A0
	ldr r1, = overworld_script_give_egg | 1
	bx r1
	.pool

// Pokeballs without scripts
.org 0x0805FC20
	ldr r3, =person_get_script | 1
	bx r3
	.pool

.org 0x0807a9f0
    ldr r1, = pal_oam_apply_fading | 1
    bx r1
    .pool

.org 0x0807a55c
    ldr r2, = overworld_weather_static_fog_pal_blend | 1
    bx r2
    .pool

.org 0x0805d0f8
    ldr r1, = player_transition_water_to_land | 1
    bx r1 
    .pool

.org 0x0805d240
    ldr r1, = player_transition_water_to_land_callback_update_npc | 1
_blxr1:
    bx r1
    .pool


.org 0x08122A34
    ldr r3, =pokemon_party_menu_options_build | 1
    bx r3
    .pool

.org 0x8120FA8
    .word pokemon_party_menu_options

.org 0x8121FF0
    .word pokemon_party_menu_options

.org 0x8122D50
    .word pokemon_party_menu_options

.org 0x8122D80
    .word pokemon_party_menu_options

.org 0x080d0a04
    .word ow_script_strength_use

.org 0x0806e074
    ldr r0, =map_reset_temporary_flags_and_vars | 1
    bx r0
    .pool

.org 0x08127b1e
    mov r0, r5
    ldr r1, =pokemon_party_menu_can_switch_into_index | 1
    bl _blxr1
    cmp r0, #0
    bne 0x08127b58
    b 0x08127b36
    .pool

.org 0x0805b9c4
    ldr r1, = npc_player_turn_in_place | 1
    bx r1
    .pool


.org 0x0805b4d4
    ldr r3, =player_npc_move | 1
    bx r3
    .pool
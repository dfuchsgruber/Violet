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



// Dynamic overworld palettes

/** 
// Don't load palettes beforehand...
.org 0x0805f5e8 // player_npc_load_reflection_palettes
    bx lr

.org 0x0805f658 // effect_load_reflection_palettes
    bx lr

.org 0x080db0e8
    bx lr

.org 0x080db144
    bx lr

.org 0x0805f092
    b 0x0805f09e
**/


// Prevent auto-load of overworld palettes
.org 0x0805fecc
    ldr r1, =overworld_npc_palettes_initialize | 1
    bx r1
    .pool

.org 0x0805f4b0
    ldr r1, =overworld_npc_palette_load | 1
    bx r1
    .pool

// When creating a new npc, don't force a palette to a slot. Instead properly allocate a palette
.org 0x0805e5de
    mov r0, r7 // oam template
    ldr r1, =overworld_npc_load_palette_by_template | 1
    bl _blxr1
    b 0x0805e606
    .pool
.org 0x0805e618
    lsl r0, #0 // nop: this replaces setting the template's pal tag to 0xFFFF (instead it associates with the previously allocated pal)
.org 0x0805e6b0
    b 0x0805e6c0 // Don't manually change the palette in the oam_attribute2 (let the engine do its job and find the allocated palette)

// When creating a new npc via the createsprite command, do the same as above essentially.
.org 0x0805ea40 // Nop's out the setting of the template's pal tag to 0xFFFF and allocates the palette
    ldr r2, = hook_overworld_createsprite_load_npc_palette | 1
    bx r2
    .pool
.org 0x0805eaae // Don't manually change the palette in the oam_attribute (let the engine do its job and find the allocated palette)
    b 0x0805eac0
.org 0x0805ead8 // Don't handle reflection palettes here...
    b 0x0805eae4

// I have no clue when this function is even called...
.org 0x0805eeb4 // nops the setting 0xFFFF to the templates tag and also allocates the palette
    mov r0, sp // oam template
    ldr r1, =overworld_npc_load_palette_by_template | 1
    bl _blxr1
    mov r0, sp
    b 0x0805eee0
    .pool
.org 0x0805ef76 // Dont force the slot into the oam attribute
    b 0x0805ef86


.org 0x0805eb78 // This nops the setting 0xFFFF to the templates tag for fame checker and allocates the palette
    ldr r0, =hook_overworld_fame_checker_npc_palette | 1
    bx r0
    .pool
.org 0x0805ebbe // Don't force the slot into the oam attribute
    b 0x0805ebd0


.org 0x080db078
    ldr r2, =overworld_npc_load_reflection_palette | 1
    bx r2
    .pool

.org 0x080db1dc
    lsl r0, #0 // Don't update the palette of the reflection constantly...

.org 0x0805e510
    ldr r1, = npc_free_resources | 1
    bx r1
    .pool

.org 0x080dc620
    ldr r1, =overworld_effect_surfing_pokemon_setup_oam | 1
    bl _blxr1
    b 0x080dc650
    .pool

.org 0x0805f090 // Updating a sprite does not patch the palette, but instead allocates a palette if not present
    mov r0, r6
    mov r1, r4
    ldr r2, =overworld_npc_update_palette | 1
    bl blxr2
    b 0x0805f0b2
    .pool
.org 0x0805f114
    lsl r0, #0 // Don't set the palette slot

.org 0x080870e0
    push {r0}
    ldr r1, =overworld_effect_fly_allocate_pal | 1
    bl _blxr1
    mov r2, r0
    pop {r0}
    b 0x080870fc
    .pool

.org 0x08086cbc
    mov r0, r4
    ldr r1, =overworld_effect_fly_allocate_pal | 1 // who would have thought that I could recycle this?
    bl _blxr1
    mov r2, r0
    b 0x08086cce
    .pool


.org 0x080db400
    ldr r0, =overworld_effect_shadow | 1
    bx r0
    .pool


.org 0x080825c0
    ldr r3, =overworld_effect_emotion_bubble_start | 1
    bx r3
    .pool

.org 0x080db358
    push {lr, r4}
    ldr r4, =overworld_effect_show_warp_arrow | 1
    bl blxr4_0805bba8
    pop {r4}
    pop {r0}
    bx r0
    .pool

.org 0x0813f4bc
    ldr r3, =itemfinder_create_arrow_sprite | 1
    bx r3
    .pool

.org 0x0813f65c
    ldr r0, =item_finder_create_star | 1
    bx r0
    .pool

.org (oam_template_item_finder_arrow + 2)
    .halfword 2000 // Pal tag

.org 0x084658c0
    .word gfx_item_finder_arrowTiles 

.org 0x0813f49c
    ldr r0, =item_finder_load_gfx_and_pal | 1
    bx r0
    .pool

.org 0x0813f4ac
    ldr r0, =item_finder_free_gfx_and_pal | 1
    bx r0
    .pool

.org 0x0807a6ac
    ldr r1, =overworld_weather_static_fog_palette_affected | 1
    bx r1
    .pool

.org 0x0805e758
    ldr r0, =hook_npc_create_by_person | 1
    bx r0
    .pool

.org 0x0805e5d4
    ldr r2, =hook_npc_create_by_npc | 1
    bx r2
    .pool

.org 0x0805ee88
    ldr r2, =hook_npc_create_by_npc2 | 1
    bx r2
    .pool

.org 0x0805eea4
    ldr r0, =hook_npc_create_oam_template | 1
    bx r0
    .pool


.org 0x0805e960
    ldr r3, =overworld_create_oam_template_by_person | 1
    bx r3
    .pool

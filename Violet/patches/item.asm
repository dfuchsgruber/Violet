.org 0x08098a78
    ldr r2, =item_get_resource | 1
    bx r2
    .pool

.org 0x0815F914 + (0x88*4)
    .word script_cmd_x88_pokemart3 | 1

.org 0x0809a988
    ldr r1, =item_idx_saniztize | 1
    bx r1
    .pool

//@Bike sound := 195
.org 0x080A1402
    mov r0, #195


//item table
.org 0x80001c8
	.word items


.org 0x809a9bc
	.word items


.org 0x809a9e0
	.word items


.org 0x809aa04
	.word items


.org 0x809aa28
	.word items


.org 0x809aa4c
	.word items


.org 0x809aa70
	.word items


.org 0x809aa94
	.word items


.org 0x809aab8
	.word items


.org 0x809aadc
	.word items


.org 0x809ab00
	.word items


.org 0x809ab24
	.word items


.org 0x809ab48
	.word items


.org 0x809ab6c
	.word items


.org 0x809ab90
	.word items
    
.org 0x803a1b0
	.word item_effects


.org 0x8041448
	.word item_effects


.org 0x8042424
	.word item_effects


.org 0x8042b30
	.word item_effects


.org 0x8042d3c
	.word item_effects


.org 0x812509c
	.word item_effects


.org 0x812579c
	.word item_effects


.org 0x8126d14
	.word item_effects


// r0-r3 are used already, so the hook is wrapped by something that saves r4
.org 0x080412e4
    push {r1}
    ldr r1, =fmem
    str r0, [r1]
    pop {r1}
    ldr r0, =item_effect_apply | 1
    bx r0
    .pool

    
// r0-r3 are used already, so the hook is wrapped by something that saves r4
.org 0x08042314
    push {r1}
    ldr r1, =fmem
    str r0, [r1]
    pop {r1}
    ldr r0, =item_effect_unapplicable | 1
    bx r0
    .pool


.org 0x08042b08
    ldr r3, =_item_effect_get_hp_healed_offset | 1
    bx r3
    .pool

.org 0x08126cb8
    ldr r1, = item_get_effect_type | 1
    bx r1
    .pool

.org 0x081250a8
    ldr r1, = item_effect_print_result | 1
    bx r1
    .pool

.org 0x08125adc
	.word tm_hm_to_attack

.org 0x08125afc
	.word tm_hm_to_attack

.org 0x080A13A4
	.word str_cant_dismount_cloud

// Prevent the player form dismounting the clound on underwater maps
.org 0x080A133E
	ldr r1, =cloud_not_dismountable | 1
	bl _bxr1
	ldr r1, =0x080A137E | 1
	bx r1
_bxr1:
	bx r1
	.pool

.org 0x08082ac8
    ldr r1, = fishing_create_pokemon | 1
    bx r1 
    .pool

.org 0x0805d2fc
    .word fishing_big_callback_bait | 1

.org 0x0813dc4c
    .word berry_pouch_callbacks

.org 0x0801bce4
    .word hook_battle_item_switch_in_effects

.org 0x0813dd18
    ldr r0, =berry_pouch_get_context_menu_options_standard_hook | 1
    bx r0 
    .pool
    
.org 0x0813dfc8
    ldr r0, =berry_pouch_toss_hook_print_string_how_many | 1
    bx r0
    .pool

.org 0x0813e020
    ldr r0, =berry_pouch_toss_hook_get_string_confirm_quantity_to_toss | 1
    bx r0
    .pool

.org 0x08465430
    .word berry_pouch_toss_or_compost_confirmed | 1

.org 0x08465460
    .word berry_pouch_context_menu_option_compost_text
    .word berry_pouch_context_menu_option_toss

.org 0x0810a3f0
    ldr r1, =bag_item_selected_give | 1
    bx r1
    .pool

.org 0x0810a4e8
    ldr r1, =bag_item_selected_give_from_pc | 1
    bx r1
    .pool


/** POKEBALLS */

.org 0x80f0a0c
	.word pokeball_particles_oam_templates
.org 0x80f0b8c
	.word pokeball_particles_oam_templates
.org 0x80f0c90
	.word pokeball_particles_oam_templates
.org 0x80f0d94
	.word pokeball_particles_oam_templates
.org 0x80f0e98
	.word pokeball_particles_oam_templates
.org 0x80f0fcc
	.word pokeball_particles_oam_templates
.org 0x80f1124
	.word pokeball_particles_oam_templates
.org 0x80f1250
	.word pokeball_particles_oam_templates
.org 0x80f13a8
	.word pokeball_particles_oam_templates

/* 
*/
.org 0x80f04fc
	.word pokeball_particle_animation_idxs
.org 0x80f0a14
	.word pokeball_particle_animation_idxs
.org 0x80f0b90
	.word pokeball_particle_animation_idxs
.org 0x80f0c94
	.word pokeball_particle_animation_idxs
.org 0x80f0d90
	.word pokeball_particle_animation_idxs
.org 0x80f0e9c
	.word pokeball_particle_animation_idxs
.org 0x80f0fc8
	.word pokeball_particle_animation_idxs
.org 0x80f1120
	.word pokeball_particle_animation_idxs
.org 0x80f1258
	.word pokeball_particle_animation_idxs
.org 0x80f13a4
	.word pokeball_particle_animation_idxs
.org 0x80f08f4
	.word pokeball_particles_initializers

.org 0x80f150c
	.word pokeball_open_fade_colors
.org 0x80f1558
	.word pokeball_open_fade_colors
.org 0x80f15bc
	.word pokeball_open_fade_colors
.org 0x80f1698
	.word pokeball_open_fade_colors

.org 0x80f0870
	.word pokeball_particle_palettes
.org 0x80f1490
	.word pokeball_particle_palettes

.org 0x80f0868
	.word pokeball_particle_gfxs
.org 0x80f148c
	.word pokeball_particle_gfxs

.org 0x80001d0
	.word pokeball_gfxs
.org 0x804b9f4
	.word pokeball_gfxs
.org 0x804bc5c
	.word pokeball_gfxs
.org 0x804bf70
	.word pokeball_gfxs
.org 0x804bfa8
	.word pokeball_gfxs

.org 0x80001d4
	.word pokeball_palettes
.org 0x804b9f8
	.word pokeball_palettes
.org 0x804bc60
	.word pokeball_palettes
.org 0x804bf78
	.word pokeball_palettes
.org 0x804bfac
	.word pokeball_palettes

.org 0x804aadc
	.word pokeball_oam_templates
.org 0x804b9fc
	.word pokeball_oam_templates
.org 0x804bc64
	.word pokeball_oam_templates
.org 0x80ef900
	.word pokeball_oam_templates
.org 0x80efa54
	.word pokeball_oam_templates
.org 0x8139ddc
	.word pokeball_oam_templates

.org 0x080ef7b4
    ldr r1, =item_idx_to_pokeball_idx | 1
    bx r1
    .pool

.org 0x080efbfa
	lsl r0, #0 //  No limiting byte for pokeball idxs
.org 0x080f055e
	lsl r0, #0 //  No limiting byte for pokeball idxs

.org 0x0804bf14
	ldr r1, =pokeball_load_gfx | 1
	bx r1
	.pool

// Remove all item_idx -> ball idx translations that are unneccesary, as we now store the ball idx in a pokemon substructure
.org 0x080ef630 // Switch-out animations
	lsl r0, #0
	lsl r0, #0

.org 0x08046088 // Create eggs from script command
	mov r1, #0 // Ball idx 0 

.org 0x08046cd6 // Hatch mon to party
	mov r0, #0 // Ball idx 0

.org 0x0804ac50 // pokefirered's `SpriteCB_TestBallThrow`
	lsl r0, #0
	lsl r0, #0

.org 0x0804b2ac // pokefirered's `SpriteCB_ReleaseMonFromBall`
	lsl r0, #0
	lsl r0, #0

.org 0x0804aa3e // pokefirered's `Task_DoPokeballSendOutAnim`
	lsl r0, #0
	lsl r0, #0

.org 0x08139d76 // Summary screen, pokefirered's `CreateBallIconObj`
	lsl r0, #0
	lsl r0, #0 

.org 0x08043718 // Pokemon add friendship
	cmp r0, #10 // Luxury ball
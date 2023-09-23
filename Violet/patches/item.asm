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
    ldr r1, =hook_tmp
    str r0, [r1]
    pop {r1}
    ldr r0, =item_effect_apply | 1
    bx r0
    .pool

    
// r0-r3 are used already, so the hook is wrapped by something that saves r4
.org 0x08042314
    push {r1}
    ldr r1, =hook_tmp
    str r0, [r1]
    pop {r1}
    ldr r0, =_item_effect_unapplicable_fmem_hooked | 1
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



.org 0x0805d2fc
	.word fishing_big_callback | 1	

/**
.org 0x08082ac8
    ldr r1, = fishing_create_pokemon | 1
    bx r1 
    .pool

.org 0x0805d2fc
    .word fishing_big_callback_bait | 1
*/


.org 0x0801bce4
    .word hook_battle_item_switch_in_effects

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

// Rare candy item callback step does not remove the item
// This functionality is removed to the rare candy item callback instead
.org 0x0812640a
	lsl r0, #0
	lsl r0, #0


.org 0x08099f48
	ldr r0, =bag_set_pocket_pointers | 1
	bx r0
	.pool

.org 0x0809a3c0
	ldr r0, =bag_clear | 1
	bx r0
	.pool


.org 0x0809a8d8
	.word bag_pockets - 8

.org 0x8099f38
	.word bag_pockets
.org 0x8099f88
	.word bag_pockets
.org 0x8099fd4
	.word bag_pockets
.org 0x809a010
	.word bag_pockets
.org 0x809a078
	.word bag_pockets
.org 0x809a138
	.word bag_pockets
.org 0x809a1c4
	.word bag_pockets
.org 0x809a290
	.word bag_pockets
.org 0x809a32c
	.word bag_pockets
.org 0x809a3e4
	.word bag_pockets
.org 0x809a894
	.word bag_pockets
.org 0x809a8bc
	.word bag_pockets
.org 0x81085b8
	.word bag_pockets
.org 0x8108eb8
	.word bag_pockets
.org 0x81096c4
	.word bag_pockets
.org 0x81319dc
	.word bag_pockets + 24
.org 0x8131c90
	.word bag_pockets + 24
.org 0x8131d78
	.word bag_pockets + 24
.org 0x8132168
	.word bag_pockets + 24
.org 0x813d31c
	.word bag_pockets + 32
.org 0x813d9a0
	.word bag_pockets + 32

.org 0x0809a024
	ldr r3, =item_check | 1
	bx r3
	.pool

.org 0x0809a0e4
	ldr r3, =item_has_room | 1
	bx r3
	.pool

.org 0x0809A168
	ldr r3, =item_add | 1
	bx r3
	.pool

.org 0x0809A2BC
	ldr r3, =item_remove | 1
	bx r3
	.pool

.org 0x08099ee4
	ldr r1, =bag_apply_new_encryption | 1
	bx r1
	.pool

// **** Replace old bag functions ***/

.org 0x08108eec
	push {r4, lr}
	ldr r4, =bag_print_string | 1
	bl _blxr4_bag_print_string
	pop {r4}
	pop {r0}
	bx r0
_blxr4_bag_print_string:
	bx r4
	.pool

.org 0x08107e30
	ldr r3, =bag_open | 1
	bx r3
	.pool

.org 0x08108f5c
	ldr r3, = bag_set_continuation | 1
	bx r3
	.pool

.org 0x08108bcc
	ldr r3, =bag_fade_out_and_continuation | 1
	bx r3
	.pool

.org 0x08127a84
	mov r0, #0
	lsl r0, #0 // Always return to the bag (not the tm case or anything...)

.org 0x08124d6a
	mov r0, #0
	lsl r0, #0 // Always return to the bag (not the tm case or anything...)

.org 0x08124d96
	mov r0, #0
	lsl r0, #0 // Always return to the bag (not the tm case or anything...)

.org 0x080a206e
	mov r0, #0
	lsl r0, #0 // Always return the the bag (not the tm case or anything...)

.org 0x080a10dc
	mov r0, #0
	lsl r0, #0 // Always return the the bag (not the tm case or anything...)


.org 0x0810a278
	ldr r1, =bag_close_message_and_return_to_idle_callback | 1
	bx r1
	.pool

.org 0x0809c9c4
	.word berries
	
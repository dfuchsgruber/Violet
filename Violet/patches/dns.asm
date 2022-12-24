.org 0x080598cc
	ldr r2, =pal_apply_shaders | 1
	bx r2
	.pool

.org 0x08059948
	ldr r2, =pal_apply_shaders_by_palette_idx | 1
	bx r2
	.pool

.org 0x080834fc
	ldr r2, =pal_apply_shaders_by_oam_palette_idx | 1
	bx r2
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


.org 0x8059A90
        ldr r3, =tileset_load_pal_as_primary | 1
        bx r3
        .pool

.org 0x8059AA0
        ldr r3, =tileset_load_pal_as_secondary | 1
        bx r3
        .pool

.org 0x080558e4
	ldr r0, =map_transition_update_tilesets | 1
	bl map_transition_update_tilesets_blxr0
	b 0x080558f2
	.pool
map_transition_update_tilesets_blxr0:
	bx r0
.org 0x080558f2
	mov r4, #0 // gamma shift is applied to tsp pals as well

/**
**/
.org 0x08059ad8
	ldr r1, =overworld_load_tileset_pals | 1
	bx r1
	.pool
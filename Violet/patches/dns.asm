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
        ldr r3, =tileset_load_pal_as_ts0 | 1
        bx r3
        .pool

.org 0x8059AA0
        ldr r3, =tileset_load_pal_as_ts1 | 1
        bx r3
        .pool

.org 0x80558EC
        ldr r0, =mapchange_tileset_pal_load_hook | 1
        bx r0
        .pool
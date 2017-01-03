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
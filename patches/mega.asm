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
	
.org 0x08079D20
        ldr r1, =mega_reset | 1
        bx r1
        .pool 
	
// .org 0x0802E9A8
// 	ldr r0, =mega_hook_hide_icon | 1
// 	bx r0
// 	.pool
// 	
// .org 0x0801553c
// 	.word destroy_mega_triggers | 1
// 	.pool
// 	
// .org 0x08032A94
// 	ldr r0, =mega_trigger_reset | 1
// 	bx r0
// 	.pool
// 	
// .org 0x0803485C
// 	ldr r0, =hook_spawn_symbol | 1
// 	bx r0
// 	.pool
// 	
// .org 0x0802C150
// 	ldr r0, =hook_item_swap | 1
// 	bx r0
// 	.pool
// 	
// .org 0x08020FDC
// 	ldr r0, =hook_knock_off | 1
// 	bx r0
// 	.pool
// 	
// .org 0x08020D44
// 	ldr r0, =hook_thief | 1
// 	bx r0 
// 	.pool
// 
// .org 0x08250814
// 	.word hook_bag_destroy_trigger | 1
// 	.pool
// 
// .org 0x08250818
// 	.word hook_pokemon_destroy_trigger | 1
// 	.pool
// 	
// .org 0x08079D20
//         ldr r1, =mega_reset | 1
//         bx r1
//         .pool 
// 
// //prevent pokemon to blur into white after wandler transformation
// .org 0x08034CF0
//         mov r1, r9
//         ldr r0, =hook_wandler_blurr_0 | 1
//         bx r0
//         .pool
// 
// .org 0x08034EFC
//         mov r1, r9
//         ldr r0, =hook_wandler_blurr_1 | 1
//         bx r0
//         .pool

// MEGA2

//.org 0x08032ad0
//	.word _battle_controller_player_choose_action | 1 // Spawns the symbol

// This handler can't be wrapped like the "choose action" handler, as it is reference multiple times
// Thus, a hook to the wrapper. The original routine is recovered by trigger_hook.asm
//.org 0x0802e9a8
//	ldr r0, =_battle_controller_player_choose_move | 1
//	bx r0
//	.pool

	
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

//prevent pokemon to blur into white after wandler transformation
.org 0x08034CF0
        mov r1, r9
        ldr r0, =hook_wandler_blurr_0 | 1
        bx r0
        .pool

.org 0x08034EFC
        mov r1, r9
        ldr r0, =hook_wandler_blurr_1 | 1
        bx r0
        .pool
	
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


.org 0x08032bb4
    ldr r0, = battle_controller_player_init_move_selection_hook | 1
    bx r0
    .pool

.org 0x0802e9a8
    ldr r0, =_battle_controller_player_choose_move | 1
    bx r0
    .pool

.org 0x0802e608
    .word battle_controller_player_choose_target_wrap | 1
.org 0x0802eb44
    .word battle_controller_player_choose_target_wrap | 1


.org 0x0801554c
    ldr r0, = battle_execute_action | 1
    bx r0
    .pool

.org 0x08034912 // Replaces a call to nullsubs
    ldrb r0, [r4] // Battler idx to set-up
    bl _battle_create_mega_indicator
    // break-statement
    ldr r0, =0x080349ba | 1
    bx r0 
_battle_create_mega_indicator:
    ldr r1, =battle_create_mega_indicator | 1
    bx r1
    .pool

.org 0x08078026
    bl _battle_create_mega_indicator
    ldr r0, =0x08078068 | 1
    bx r0 
    .pool

.org 0x0802C150
 	ldr r0, =hook_battlescript_command_item_swap | 1
 	bx r0
 	.pool
 	
.org 0x08020FDC
 	ldr r0, =hook_battlescript_knock_off | 1
 	bx r0
 	.pool
 	
.org 0x08020D44
 	ldr r0, =hook_battlescript_thief | 1
 	bx r0 
 	.pool
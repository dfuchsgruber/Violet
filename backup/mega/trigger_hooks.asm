// This hook replicates what was overwritten of "battle_controller_player_choose_move"
// The routine is wrapped by a handler, that handles L&R input to mark a battler for mega evolution.
// Afterwards, the original function has to be executed, thus it needs to be recovered (by this hook)

.global _battle_controller_player_choose_move_hook

.align 4
.thumb
.thumb_func
_battle_controller_player_choose_move_hook:
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    sub sp, #0x4
    ldr r0, =0x0802e9b0 | 1
    bx r0

// Spawns a mega trigger whenever the player enters move selection

.global battle_controller_player_init_move_selection_hook

.align 4
.thumb
.thumb_func
battle_controller_player_init_move_selection_hook:
    push {lr}
    bl mega_trigger_new_for_active_battler
    bl _battle_selection_display_move_names
    ldr r0, =0x08032bba | 1
    bx r0

_battle_selection_display_move_names:
    ldr r0, =battle_selection_display_move_names
    bx r0

// Triggers mega evolution when opponent selects an action (that is a move)

.global battle_controller_opponent_choose_action_hook

.align 4
.thumb
.thumb_func
battle_controller_opponent_choose_action_hook:
    bl battle_controller_opponent_trigger_mega_evolution
    // Recover original functionality
    ldr r0, =defending_battler
    ldrb r0, [r0]
    lsl r0, #8
    orr r4, r0
    mov r0, #1
    mov r1, #0xa // BATTLE_ACTION_MOVE_CHOOSEN
    mov r2, r4
    ldr r3, =0x08038564 | 1
    bx r3
    

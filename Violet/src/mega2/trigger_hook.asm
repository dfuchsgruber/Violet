// This hook replicates what was overwritten of "battle_controller_player_choose_move"
// The routine is wrapped by a handler, that handles L&R input to mark a battler for mega evolution.
// Afterwards, the original function has to be executed, thus it needs to be recovered (by this hook)

.global battle_controller_player_choose_move

.align 4
.thumb
.thumb_func
battle_controller_player_choose_move:
    push {r4, r5, r6, r7, lr}
    mov r7, r8
    push {r7}
    sub sp, #0x4
    ldr r0, =0x0802e9b0 | 1
    bx r0


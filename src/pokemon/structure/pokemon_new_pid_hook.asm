.align 2
.thumb

.global pokemon_new_pid_hook

.thumb_func
pokemon_new_pid_hook:
bl pokemon_new_pid
mov r4, r0
ldr r0, =0x0803DA12 | 1
bx r0

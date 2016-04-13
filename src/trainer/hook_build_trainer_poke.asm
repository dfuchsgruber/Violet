.align 2
.thumb

.global hook_build_trainer_poke
.thumb_func

hook_build_trainer_poke:
ldr r0, [sp, #0x18]
mov r1, r8
bl build_trainer_poke
add sp, #0x1C
pop {r3}
mov r8, r3
pop {r4-r7}
pop {r0}
bx r0

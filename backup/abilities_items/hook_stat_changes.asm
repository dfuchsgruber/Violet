.global hook_stat_changes

.align 2
.thumb

.thumb_func

hook_stat_changes:
@we get: r7 a_ang, r8 a_sang, r6 fast_ac_a, sp+4 fast_ac_d, sp+0x14 d_def, sp+0x18, d_sdef

mov r8, r3
ldr r0, [sp, #0x4]
ldrh r0, [r0, #0xa]
str r0, [sp, #0x18]

mov r0, r8
bl attacker_modify_satk
mov r8, r0

mov r0, r7
bl attacker_modify_atk
mov r7, r0

ldr r0, [sp, #0x14]
bl defender_modify_def
str r0, [sp, #0x14]

ldr r0, [sp, #0x18]
bl defender_modify_sdef
str r0, [sp, #0x18]

@stats modified
ldr r0, =0x0803EC80 | 1
bx r0


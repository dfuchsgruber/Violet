.global hook_attack_type

.align 2
.thumb

.thumb_func
hook_attack_type:
push {r3} //there, unfortunatly, is no other way to save the register
mov r0, r1
bl attack_type_by_ability
pop {r3}
mov r8, r0
ldr r0, =0x0801E80C | 1
bx r0


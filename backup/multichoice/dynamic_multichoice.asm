.global dynamic_multichoice_hook

@inserted at 0x0809CB90 via blx r0

.align 4
.thumb

.thumb_func
dynamic_multichoice_hook:
str r1, [sp]
mov r0, r10
bl dynamic_multichoice_get_choices
ldr r1, =0x0809CB9A | 1
bx r1



    
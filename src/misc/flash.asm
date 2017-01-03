.align 2
.thumb


.global new_flash_script

.align 2
new_flash_script:
.byte 0x23
.word flash_user_level
.byte 0x21
.hword 0x800D
.hword 0x0
.byte 0x6	@gotoif
.byte 0x1
.word flash_0
.byte 0x21
.hword 0x800D
.hword 0x1
.byte 0x6	@gotoif
.byte 0x1
.word flash_1
.byte 0x21
.hword 0x800D
.hword 0x2
.byte 0x6	@gotoif
.byte 0x1
.word flash_2
.byte 0x21
.hword 0x800D
.hword 0x3
.byte 0x6	@gotoif
.byte 0x1
.word flash_3
.byte 0x2



.align 2
flash_0:
.byte 0x9a
.byte 0x0
.byte 0x99
.hword 0x0
.byte 0x2


.align 2
flash_1:
.byte 0x9a
.byte 0x1
.byte 0x99
.hword 0x1
.byte 0x2

.align 2
flash_2:
.byte 0x9a
.byte 0x2
.byte 0x99
.hword 0x2
.byte 0x2

.align 2
flash_3:
.byte 0x9a
.byte 0x3
.byte 0x99
.hword 0x3
.byte 0x2


.align 2
.thumb
.thumb_func
flash_user_level:
push {lr}
ldr r0, =0x0203B0A9
ldrb r1, [r0]
mov r0, #0x64
mul r1, r0
ldr r0, =0x02024284
add r0, r1
mov r1, #0x38
mov r2, #0
bl _get_pokemons_attribute
mov r2, #3
ldr r1, =0x020370D0
cmp r0, #25
blt store
sub r2, #1
cmp r0, #35
blt store
sub r2, #1
cmp r0, #50
blt store
sub r2, #1
store:
strh r2, [r1]
pop {pc}


.align 2
.thumb
_get_pokemons_attribute:
ldr r3, =get_pokemons_attribute
bx r3


.align 2
.thumb

.global anim_engine_cmdx1A

.thumb_func
anim_engine_cmdx1A:
push {r4-r7, lr}
mov r4, r8
mov r5, r9
mov r6, r10
mov r7, r11
push {r4-r7}


mov r5, r0
bl read_word
mov r4, r0

ldr r1, [r5, #4]
ldrb r6, [r1] @number of additional params
add r1, #1
str r1, [r5, #4]

cmp r6, #0
beq exec

mov r0, r5
bl read_word
mov r7, r0
sub r6, #1

cmp r6, #0
beq exec
mov r0, r5
bl read_word
mov r8, r0
sub r6, #1

cmp r6, #0
beq exec
mov r0, r5
bl read_word
mov r9, r0
sub r6, #1

cmp r6, #0
beq exec
mov r0, r5
bl read_word
mov r10, r0
sub r6, #1

cmp r6, #0
beq exec

@now we loop for the stack


lsl r6, #2
mov r2, r6

mov r1, r6
neg r1, r1
add sp, r1		@stack memory

mov r0, sp
ldr r1, [r5, #4]
bl bytecopy
ldr r1, [r5, #4]
add r1, r6
str r1, [r5, #4]

exec:
mov r0, r7
mov r1, r8
mov r2, r9 
mov r3, r10
bl call_r4
add sp, r6
pop {r4-r7}
mov r8, r4
mov r9, r5
mov r10, r6
mov r11, r7
pop {r4-r7, pc}



call_r4:
bx r4

read_word:
ldr r1, [r0, #4] @current programm
ldrb r2, [r1]
ldrb r3, [r1, #1]
lsl r3, #8
add r2, r3
ldrb r3, [r1, #2]
lsl r3, #16
add r2, r3
ldrb r3, [r1, #3]
lsl r3, #24
add r2, r3
add r1, #4
str r1, [r0, #4]
mov r0, r2
bx lr

bytecopy:
@ r0 dest, r1 source, r2 bytecnt
cmp r2, #0
beq end_cpy
ldrb r3, [r1]
strb r3, [r0]
add r0, #1
add r1, #1
sub r2, #1
b bytecopy
end_cpy:
bx lr






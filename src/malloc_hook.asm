.global malloc_hook
.global free_hook
.global malloc_tail
.global free_tail

.align 4
.thumb

malloc_hook:
mov r2, sp
ldr r2, [r2]
push {lr}
bl malloc_debug
pop {r1}
bx r1   

.align 4
.thumb

.thumb_func

malloc_tail:
push {r4-r7, lr}
mov r5, r1
ldr r2, =0x02020004
str r0, [r2]
ldr r1, =0x08002974 | 1
bx r1

.align 4
.thumb

.thumb_func

free_hook:
mov r2, sp
ldr r2, [r2]
push {lr}
bl free_debug
pop {r0}
bx r0

.align 4
.thumb

.thumb_func

free_tail:
cmp r1, #0
beq locret
push {r4, r5, lr}
mov r5, r0 
ldr r2, =0x08002A0C | 1
bx r2

locret:
    bx lr

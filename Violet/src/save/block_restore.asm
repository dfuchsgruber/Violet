@//this is inspired and taken from JPANs Codes

.equ BLOCK_0_TAIL_OFF, 0x0203c0c8
.equ BLOCK_0_SIZE, 204
.equ BLOCK_1_TAIL_OFF, 0x0203c320
.equ BLOCK_1_SIZE, 600
.equ BLOCK_2_TAIL_OFF, 0x0203cec0
.equ BLOCK_2_SIZE, 2976

.global hook_save_block_load
.global hook_save_block_store

.align 2
.thumb

.thumb_func
hook_save_block_load:
    ldr r1, [r4]
    mov r3, #0xFF
    lsl r3, #0x4
    add r3, r1
    ldrh r0, [r3, #0x4] @current block id
    cmp r0, #0
    beq load_block_0
    cmp r0, #4
    beq load_block_1
    cmp r0, #0xD
    beq load_block_2
    b load_next_block

load_block_0:
    ldr r1, =BLOCK_0_SIZE
    ldr r2, =BLOCK_0_TAIL_OFF
    b load_block

load_block_1:
    ldr r1, =BLOCK_1_SIZE
    ldr r2, =BLOCK_1_TAIL_OFF
    b load_block

load_block_2:
    ldr r1, =BLOCK_2_SIZE
    ldr r2, =BLOCK_2_TAIL_OFF
    b load_block

load_block:
    sub r3, #4
    ldr r0, [r3]
    str r0, [r2]
    sub r2, #4
    sub r1, #4
    cmp r1, #0
    bne load_block

load_next_block:
    cmp r5, #0xD
    ble block_load_loop_head
    mov r0, #1 @/return true
    pop {r3}
    mov r8, r3
    pop {r4-r7}
    pop {r1}
    bx r1

block_load_loop_head: @jumps to the acutal block loading loop head
    ldr r0, =0x080DA094 | 1
    bx r0

.align 2
.thumb

.thumb_func
hook_save_block_store:
    mov r7, #0xFF
    lsl r7, #0x4
    add r7, r1
    strh r0, [r7, #6]
    ldrh r6, [r7, #4]
    cmp r6, #0
    beq store_block_0
    cmp r6, #4
    beq store_block_1
    cmp r6, #0xD
    beq store_block_2
    b block_store_loop_head @jumpts to the actual bloack storeing loop head


block_store_loop_head:
    ldr r0, =0x080D9B46 | 1
    bx r0

store_block_0:
    ldr r3, =BLOCK_0_SIZE
    ldr r2, =BLOCK_0_TAIL_OFF
    b store_block

store_block_1:
    ldr r3, =BLOCK_1_SIZE
    ldr r2, =BLOCK_1_TAIL_OFF
    b store_block

store_block_2:
    ldr r3, =BLOCK_2_SIZE
    ldr r2, =BLOCK_2_TAIL_OFF
    b store_block

store_block:
    sub r7, #4
    ldr r0, [r2]
    str r0, [r7]
    sub r2, #4
    sub r3, #4
    cmp r3, #0
    bne store_block
    b block_store_loop_head


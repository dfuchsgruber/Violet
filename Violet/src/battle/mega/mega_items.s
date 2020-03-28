.align 4
.thumb

.global hook_battlescript_command_item_swap
.global hook_battlescript_knock_off
.global hook_battlescript_thief

.thumb_func
hook_battlescript_command_item_swap:
    ldrb r0, [r7]
    bl battler_can_lose_item
    cmp r0, #0
    beq items_can_not_be_swapped
    ldr r0, =attacking_battler
    ldrb r0, [r0]
    bl battler_can_lose_item
    cmp r0, #0
    beq items_can_not_be_swapped
items_can_be_swapped:
    mov r3, r7
    ldr r7, =defending_battler
    ldrb r0, [r7]
    mul r0, r5
    mov r2, r8
    add r1, r0, r2
    ldr r2, =0x802C158 | 1
    bx r2
items_can_not_be_swapped:
    ldr r0, =0x0802C176 | 1
    bx r0

.align 2
.thumb

.thumb_func
hook_battlescript_knock_off:
    push {r0-r3}	@ ugly af...
    ldrb r0, [r5]
    bl battler_can_lose_item
    cmp r0, #0
    beq item_can_not_be_knocked_off
    pop {r0-r3}
    ldrh r0, [r1, #0x2E]
    cmp r0, #0
    beq item_can_not_be_knocked_off_no_pop
item_can_be_knocked_off:
    mov r0, r3
    ldr r1, =0x08020FE4 | 1
    bx r1

item_can_not_be_knocked_off:
    pop {r0-r3}
item_can_not_be_knocked_off_no_pop:
    ldr r0, =0x08021070 | 1
    bx r0

.align 2
.thumb

.thumb_func
hook_battlescript_thief:
    @check if r3 matches a mega table
    ldr r1, =defending_battler
    ldrb r2, [r1]
    mov r0, #0x58
    mul r0, r2
    ldr r1, =battlers
    add r0, r1
    ldrh r1, [r0, #0x2E] @ item
    cmp r1, #0
    beq thief_failed

    mov r0, r2
    bl battler_can_lose_item
    cmp r0, #0
    beq thief_failed
    mov r3, r4
    mov r4, #0
    mov r0, r3
    sub r0, #0x79
    lsl r0, #16
    lsr r0, #16
    cmp r0, #0xB
    bhi thief_succeded
thief_failed:
    ldr r0, =0x08021070 | 1
    bx r0
thief_succeded:
    ldr r0, =0x08020D58 | 1
    bx r0

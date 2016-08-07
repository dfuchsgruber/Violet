@hookable at: 0806CA94 via r0

.global pokepad_outdoor_trigger

.align 2
.thumb

.thumb_func
pokepad_outdoor_trigger:
    bl pokepad_init_function_outdoor
    cmp r0, #0
    bne ret_1
    ldrb r1, [r5]
    mov r0, #0x40
    and r0, r1
    cmp r0, #0
    beq jmp_loc_806CAD8
    ldr r0, =0x0806CA9D
    bx r0

    ret_1:
    ldr r0, =0x0806CAD1
    bx r0

    jmp_loc_806CAD8:
    ldr r0, =0x0806CAD9
    bx r0

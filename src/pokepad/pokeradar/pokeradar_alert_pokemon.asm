.global pokeradar_alert_pokemon

.align 2
.thumb

.thumb_func
pokeradar_alert_pokemon:
    push {r4-r7, lr}
    lsl r0, #0x18
    lsr r5, r0, #0x18
    mov r0, r5
    bl pokeradar_npc_alert
    cmp r0, #0
    bne ret_1
    mov r0, r5
    ldr r1, =0x08081AF1
    bx r1

    ret_1:
    ldr r0, =0x08081B3F
    bx r0

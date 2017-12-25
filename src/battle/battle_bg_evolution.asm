.include "std.s"

.global battle_bg_evolution1
.global battle_bg_evolution2
.global battle_bg_evolution3

.equ BATTLE_BG_EVO, 13

.align 4
.thumb

.thumb_func
battle_bg_evolution1:
    ldr r0, =BATTLE_BG_OVERRIDE
    ldr r1, =vardecrypt
    bl bxr1
    mov r1, #BATTLE_BG_EVO + 1
    strh r1, [r0]
    mov r0, #0
    ldr r1, =set_callback4
    bl bxr1
    mov r0, #0
    ldr r1, =set_callback3
    bl bxr1
    ldr r1, =0x080CDFC4 | 1
bxr1:
    bx r1

.align 4
.thumb

.thumb_func
battle_bg_evolution2:
    ldr r0, =BATTLE_BG_OVERRIDE
    ldr r1, =vardecrypt
    bl bxr1
    mov r1, #0
    strh r1, [r0]
    pop {r3-r5}
    mov r8, r3
    mov r9, r4
    mov r10, r5
    pop {r4-r7}
    pop {r0}
    bx r0

.align 4
.thumb

.thumb_func
battle_bg_evolution3:
    strh r4, [r0]
    ldr r0, =BATTLE_BG_OVERRIDE
    ldr r1, =vardecrypt
    bl bxr1
    mov r1, #BATTLE_BG_EVO + 1
    strh r1, [r0]
    ldr r1, = 0x0800F2D0 | 1
    bl bxr1
    ldr r1, = 0x0800F3A4 | 1
    bl bxr1
    ldr r0, =BATTLE_BG_OVERRIDE
    ldr r1, =vardecrypt
    bl bxr1
    mov r1, #0
    strh r1, [r0]
    ldr r0, =0x080CE354 | 1
    bx r0

    

.include "vars.s"

.global battle_bg_catch

.equ BATTLE_BG_CATCH, 14

.align 4
.thumb

.thumb_func
battle_bg_catch:
    ldr r0, =BATTLE_BG_OVERRIDE
    ldr r1, =vardecrypt
    bl bxr1
    mov r1, #BATTLE_BG_CATCH + 1
    strh r1, [r0]
    ldr r1, =0x0800F2D0 | 1
    bl bxr1
    ldr r1, =0x0800F3A4 | 1
    bl bxr1
    ldr r0, =BATTLE_BG_OVERRIDE
    ldr r1, =vardecrypt
    bl bxr1
    mov r1, #0
    strh r1, [r0]
    ldr r1, =0x02022980
    mov r2, #0x1
    lsl r2, #8
    mov r0, r2
    strh r0, [r1]
    ldr r1, =0x802DACC | 1
bxr1:
    bx r1

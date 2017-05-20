.global hook_dmg_calc_pick_atk
.global hook_dmg_calc_pick_def

.align 2
.thumb

.thumb_func
hook_dmg_calc_pick_atk:
    cmp r2, r9
    bne attack_boost_scan_next_entry
    ldr r0, [sp, #8] @attack id
    mov r1, #0xC
    mul r0, r1
    ldr r1, =attacks
    add r0, r1
    ldrb r1, [r0, #10]
    cmp r1, #0
    beq atk_physical
atk_special:
    ldr r0, =0x0803EE0E | 1
    bx r0
atk_physical:
    ldr r0, =0x0803ECD4 | 1
    bx r0


attack_boost_scan_next_entry:
    ldr r0, =0x0803EE3C | 1
    bx r0

.thumb_func
hook_dmg_calc_pick_def:
    ldr r0, [sp, #8] @attack id
    mov r1, #0xC
    mul r0, r1
    ldr r1, =attacks
    add r0, r1
    ldrb r1, [r0, #10]
    cmp r1, #0
    beq def_physical
def_special:
    @//skip over the anti-fairy check (attack type 0x9 throws an exception) as well
    ldr r0, =0x0803F29A | 1
    bx r0
def_physical:
    ldr r0, =0x0803F12C | 1
    bx r0


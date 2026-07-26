.global hook_save_block_replace

.align 2
.thumb

.thumb_func
hook_save_block_replace:
    push {r4, lr}

    ldr r0, =save_sector_buffer
    ldr r0, [r0]
    ldr r1, = save_custom_blocks_store + 1
    bl call_r1

    @ Replay the displaced flash erase setup and call.
    ldr r0, =0x03007320
    ldr r1, [r0]
    mov r0, r5
    ldr r2, = 0x081E7A95
    bl call_r2

    pop {r4}
    pop {r0}
    ldr r1, = 0x080D9E33
    bx r1

call_r1:
    bx r1

call_r2:
    bx r2


/* 


.org 0x08007158
    ldr r1, =oam_new_at_hook | 1
    bx r1
    .pool

.org 0x08007014
    push {r4, lr}
    sub sp, #4
    ldr r4, [sp, #12]
    str r4, [sp, #0]
    ldr r4, =oam_new_at | 1
    bl _blxr4_oam
    add sp, #4
    pop {r4}
    pop {r1}
    bx r1
    .pool

_blxr4_oam:
    bx r4

.org 0x08007200
    ldr r1, = oam_delete | 1
    bx r1
    .pool
*/

.org 0x08006f0c
    push {r4, lr}
    ldr r4, =oam_new_forward_search | 1
    bl _blxr4_oam
    pop {r4}
    pop {r1}
    bx r1
    .pool
_blxr4_oam:
    bx r4

.org 0x08006f60
    push {r4, lr}
    ldr r4, =oam_new_backward_search | 1
    bl _blxr4_oam
    pop {r4}
    pop {r1}
    bx r1
    .pool

.org 0x080076f0
    ldr r0, =oam_clear_all | 1
    bx r0
    .pool

.org 0x08006c78
    ldr r0, =oam_sort | 1
    bx r0
    .pool


.org 0x08006b28
    ldr r0, =oam_proceed | 1
    bx r0
    .pool

.org 0x08006b74
    ldr r0, =oam_calculate_position | 1
    bx r0
    .pool

.org 0x08006c38
    ldr r0, =oam_calculate_priority | 1
    bx r0
    .pool

.org 0x8006e84
    ldr r0, =oam_copy_to_oam_buffer | 1
    bx r0
    .pool
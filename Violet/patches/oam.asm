
.org 0x08006c78
    ldr r0, =oam_sort | 1
    bx r0
    .pool

.org 0x0800735c
    ldr r1, =oam_clear | 1
    bx r1
    .pool
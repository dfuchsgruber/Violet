
.align 2
.thumb

.global destroy_mega_triggers

@destroys all fading cbs

.thumb_func
destroy_mega_triggers:

push {lr}

bl destroy_trigger_cbs

exit_loop:

@store the opponents mega evolution at callback space
ldr r0, =trigger_opponents_mega
ldr r1, =0x03004ED4
str r0, [r1]

pop {pc}






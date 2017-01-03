@responsible for triggering choice band only on effect param 0
.align 2
.thumb

.global choice_band_on_0


choice_band_on_0:
ldr r0, [sp, #0x20]
cmp r0, #0
bne check_specs

lsr r0, r7, #1
add r7, r0
b end_choice_band_on_0

check_specs:
cmp r0, #2
bne end_choice_band_on_0

@specs are loaded, we increase satk
mov r0, r8
lsr r1, r0, #1
add r0, r1
mov r8, r0

end_choice_band_on_0:
ldr r0, =0x0803EE59
bx r0

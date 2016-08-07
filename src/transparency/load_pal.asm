.global transparency_load_textbox_pal
.global transparency_load_styled_border_pal

.align 2
.thumb

.thumb_func
transparency_load_textbox_pal:
sub sp, #0x4
str r0, [sp]
bl transparency_load_black_pal
cmp r0, #0
beq tbox_standard
ldr r1, =transparency_black_box_pals
b tbox_end
tbox_standard:
ldr r1, =0x084711DC @standard palettes
tbox_end:
ldr r0, [sp]
add r0, r1
add sp, #4
pop {r1}
bx r1

.align 2
.thumb

.thumb_func
transparency_load_styled_border_pal:

mov r5, r0
bl transparency_load_black_pal
mov r1, r0
mov r0, r5
cmp r1, #0
beq styled_standard
ldr r5, =transparency_black_box_pals
b styled_end
styled_standard:
ldr r5, =0x847127C @standard palettes
styled_end:
lsl r4, #3
add r1, r4, r5
ldr r1, [r1]
mov r2, #0x90
lsl r2, #1
ldr r3, =0x0814fcbF
bx r3

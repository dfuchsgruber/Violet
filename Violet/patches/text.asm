.org 0x08006a0c
    // font 5, latin set
    .word font_unown

.org 0x080069b8
    .word font_unown_glyph_widths
.org 0x08006a14
    .word font_unown_glyph_widths
.org 0x08006a40
    .word font_unown_glyph_widths

/** Determines which fontset and color to use based on the npc the player interacts with */
.org 0x080cbfb8
    mov r0, #3 // the default fallback
    bx lr

/**
Fixes the control code SKIP = FC 12
by updating the current position with the amount of pixels
in the vanilla game SKIP's behaviour is equal to SHIFT_TEXT = FC 0D
 */
.org 0x08005a4e
    ldrb r0, [r6, #8]
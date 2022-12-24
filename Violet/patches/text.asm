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
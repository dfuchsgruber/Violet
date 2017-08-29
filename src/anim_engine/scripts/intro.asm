.include "anim_engine.s"
.include "std.s"

.global ae_script_intro

ae_script_intro:
frame 0
    fadescreen 0 0 512 128 16 8
    endframe

frame 200
    fadescreen 0 0 512 128 8 16
    endframe

frame 329
    song MUS_SPIELHALLE_VERSION_3 0
    bg_override 1 gfx_intro_spaceTiles 0x2000 0 COPYSET
    bg_override 1 gfx_intro_spaceMap 0x800 0 COPYMAP
    loadpal gfx_intro_spacePal 0 32 UNCOMP RESTORE
    script_notify
    endframe

frame 330
    set_io_to_val 0 0x14
    set_io_to_val 0 0x16
    set_io_to_val 0 0x18
    set_io_to_val 0 0x1A
    set_io_to_val 0 0x1C
    set_io_to_val 0 0x1E
    fadescreen 0 0 512 16 16 0
    endframe

frame 340
    text_init 0x8000 0 6 2 18 8 14 4
    text_render 0x8001 0x8000 4 2 0 0 0 0 fmap DISPLAYALL str_intro_0 0 0x10    
    endframe

frame 1100
    text_event 0x8001 EVENT_ENDTEXT
    endframe

frame 1101
    text_clear 0x8000
endframe


frame 1400
    script_notify
    end
    endframe

.align 4
fmap:
    fontmap 0 2 1
    


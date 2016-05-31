.include "anim_engine.s"

.global elite_four_founders

.align 4
elite_four_founders:
frame 0
    fadescreen 0 0 512 256 0
    endframe

frame 128
    bg_reset

    @bg_override 0 gfx_lucius_frontalTiles 0x4B00 0 COPYSET
    @bg_override 0 gfx_lucius_frontalMap 0x800 0 COPYMAP
    fadescreen 0 0 512 128 1
    endframe

frame 256
    end
    endframe
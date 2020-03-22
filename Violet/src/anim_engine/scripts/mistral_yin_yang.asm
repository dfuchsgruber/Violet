.include "anim_engine.s"

.global ae_script_mistral_yin_yang

.align 4
ae_script_mistral_yin_yang:

frame 0
    fadescreen 0 0 512 16 0 16
    endframe

frame 32
    bg_override 0 gfx_yin_yangTiles 0x1000 0 1
    bg_override 0 gfx_yin_yangMap 0x800 0 2
    loadpal gfx_yin_yangPal 13*16 32 1 0
    endframe

frame 33
    fadescreen 0 0 512 16 16 12
    endframe

frame 49
    fadescreen 0 13*16 16 16 12 0
    sound 33
    endframe


frame 184
    fadescreen 0 13*16 16 16 0 12
    endframe

frame 200
    fadescreen 0 0 512 16 12 16
    endframe

frame 216
    bg_clear_map 0 0x800
    endframe

frame 217
    fadescreen 0 0 512 16 16 0
    endframe

frame 240
    script_notify
    end
    endframe


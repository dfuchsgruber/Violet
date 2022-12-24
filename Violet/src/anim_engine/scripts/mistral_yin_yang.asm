.include "anim_engine.s"

.global ae_script_mistral_yin_yang

.align 4
ae_script_mistral_yin_yang:
    fadescreen 0 0 512 16 0 16
    pause 32
    bg_override 0 gfx_yin_yangTiles 0x1000 0 1
    bg_override 0 gfx_yin_yangMap 0x800 0 2
    loadpal gfx_yin_yangPal 13*16 32 1 0
    pause 1
    fadescreen 0 0 512 16 16 12
    pause 16
    fadescreen 0 13*16 16 16 12 0
    sound 33
    pause 128
    fadescreen 0 13*16 16 16 0 12
    pause 16
    fadescreen 0 0 512 16 12 16
    pause 16
    bg_clear_map 0 0x800
    pause 1
    fadescreen 0 0 512 16 16 0
    pause 18
    script_notify
    end
    endframe


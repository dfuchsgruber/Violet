.include "anim_engine.s"

.global ae_script_groudon_fade

.align 4
ae_script_groudon_fade:
frame 0
    fadescreen 0x43C 0 512 64 0 16
    endframe
frame 64
    script_notify
    cry 0x195 0
    endframe
frame 250 
    fadescreen 0x43C 0 512 64 16 0
    endframe
frame 314
    script_notify
    end
    endframe

.include "anim_engine.s"

.global ae_script_darkqueen_fade_to
.global ae_script_darkqueen_fade_from

.align 4
ae_script_darkqueen_fade_to:
frame 0
    fadescreen 0 0 512 64 0 8
    endframe
frame 64
    script_notify
    end
    endframe


ae_script_darkqueen_fade_from:
frame 0
    fadescreen 0 0 512 64 8 0
    endframe
frame 64
    script_notify
    end
    endframe

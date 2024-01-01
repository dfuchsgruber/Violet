.include "anim_engine.s"

.global cutscene_script_darkqueen_fade_to
.global cutscene_script_darkqueen_fade_from

.align 4
cutscene_script_darkqueen_fade_to:
    pal_restore_force_current 0 512
    fadescreen 0 0 512 64 0 8
    pause 64
    script_notify
    end
    endframe


cutscene_script_darkqueen_fade_from:
    fadescreen 0 0 512 64 8 0
    pause 64
    script_notify
    end
    endframe

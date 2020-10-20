.include "anim_engine.s"

.global ae_script_groudon_fade
.global ae_script_groudon_red
.global ae_script_groudon_grey

.align 4
ae_script_groudon_fade:
    fadescreen 0x43C 0 512 64 0 16
    pause 64
    script_notify
    cry 0x195 0
    endframe
    pause 3 * 64
    fadescreen 0x43C 0 512 64 16 0
    pause 64
    script_notify
    end

.align 4
ae_script_groudon_red:
    fadescreen 0x43C 0 512 64 0 4
    pause 64
    script_notify
    end


.align 4
ae_script_groudon_grey:
    spawn_big_cb groudon_cb_grey_fade 0 1
    .hword 0
    pause 16
    script_notify
    end

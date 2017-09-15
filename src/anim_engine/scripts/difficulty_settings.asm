.include "anim_engine.s"

.global ae_script_difficulty_setting
.global ae_script_difficulty_setting_fade_to_dark

ae_script_difficulty_setting:
frame 0
    force_pals_to_black
    endframe
frame 1
    bg_override 1 gfx_difficulty_settingTiles 0x2000 0 COPYSET
    bg_override 1 gfx_difficulty_settingMap 0x800 0 COPYMAP
    loadpal gfx_difficulty_settingPal 0 32 UNCOMP RESTORE
    set_io_to_val 0 0x14
    set_io_to_val 0 0x16
    set_io_to_val 0 0x18
    set_io_to_val 0 0x1A
    set_io_to_val 0 0x1C
    set_io_to_val 0 0x1E
    endframe
frame 2
    fadescreen 0 0 512 16 16 0
    endframe
frame 18
    script_notify
    end
    endframe


ae_script_difficulty_setting_fade_to_dark:
frame 0
    fadescreen 0 0 512 16 0 16
    endframe
frame 17
    force_pals_to_black
    script_notify
    endframe
frame 18
    mapreload
    script_notify
    end
    endframe








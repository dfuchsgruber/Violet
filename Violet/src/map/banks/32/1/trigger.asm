.include "overworld_script.s"
.include "callstds.s"
.include "vars.s"
.include "ordinals.s"
.include "specials.s"

.global ow_script_dark_tower_trigger_left
.global ow_script_dark_tower_trigger_right

ow_script_dark_tower_trigger_left:
    lockall
    compare VAR_DARK_TOWER_TRIGGER_LEFT 0x64
    gotoif EQUAL already_triggered
    setvar VAR_DARK_TOWER_TRIGGER_LEFT 0x64
    call effect
already_triggered:
    releaseall
    end

ow_script_dark_tower_trigger_right:
    lockall
    compare VAR_DARK_TOWER_TRIGGER_RIGHT 0x64
    gotoif EQUAL already_triggered2
    setvar VAR_DARK_TOWER_TRIGGER_RIGHT 0x64
    call effect
already_triggered2:
    releaseall
    end

effect:
    sound 0x2B
    setvar 0x8004 0x1
    setvar 0x8005 0x1
    setvar 0x8006 0x8
    setvar 0x8007 0x3
    special SPECIAL_EARTHQUAKE
    pause 64
    return

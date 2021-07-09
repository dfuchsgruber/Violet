.include "overworld_script.s"
.include "callstds.s"
.include "vars.s"
.include "flags.s"
.include "ordinals.s"
.include "specials.s"

.global ow_script_power_plant_inside_trigger_hide_blue_spark
.global ow_script_power_plant_inside_trigger_hide_yellow_spark

ow_script_power_plant_inside_trigger_hide_blue_spark:
    lockall
    pause 16
    sound 22
    call ow_script_power_plant_inside_hide_blue_sparks
    special SPECIAL_MAP_UPDATE_BLOCKS
    checksound
    pause 16
    setvar 0x4000 1
    releaseall
    end

ow_script_power_plant_inside_trigger_hide_yellow_spark:
    lockall
    pause 16
    sound 22
    call ow_script_power_plant_inside_hide_yellow_sparks
    special SPECIAL_MAP_UPDATE_BLOCKS
    checksound
    pause 16
    setvar 0x4000 0
    releaseall
    end

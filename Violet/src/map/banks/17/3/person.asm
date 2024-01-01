.include "overworld_script.s"
.include "specials.s"

.global ow_script_map_17_3_trainer_0

ow_script_map_17_3_trainer_0:
setvar 0x8004 0x4
special SPECIAL_CUTSCENE_SHOW
waitstate
end
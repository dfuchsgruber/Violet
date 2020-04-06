.include "overworld_script.s"
.include "callstds.s"

.global ow_script_dark_tower_trainer_1

ow_script_dark_tower_trainer_1:
    trainerbattlestd 0 0x182 0 str_before_0 str_after_0
    loadpointer 0 str_after_0
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_before_0:
    .autostring 34 2 "Böse Geister bevölkern diesen Ort!\pIch werde dich das Fürchten lehren!"
str_after_0:
    .autostring 34 2 "Hast du keine Angst vor mir?"

.elseif LANG_EN
.endif
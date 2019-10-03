.include "overworld_script.s"
.include "callstds.s"

.global ow_script_route_8_clouds_trainer_0

ow_script_route_8_clouds_trainer_0:
    trainerbattlestd 0 0x127 0 str_trainer0_challange str_trainer0_defeat
    loadpointer 0 str_trainer0_defeat
    callstd MSG_FACE
    end


.ifdef LANG_GER
str_trainer0_challange:
    .autostring 34 2 "Was zeichnet einen Vogelfänger aus?\pIch werde es dir im Kampf zeigen!"
str_trainer0_defeat:
    .autostring 34 2 "Das, was einen Vogelfänger ausmacht ist, dass er sich auch von einer Niederlage nicht zu Boden reißen lässt."
.elseif LANG_EN
str_trainer0_challange:
    .autostring 34 2 "What makes a great bird catcher?\pI will show you in battle!"
str_trainer0_defeat:
    .autostring 34 2 "What makes a bird catcher great is that even a defeat won't drag him down to the ground."
.endif
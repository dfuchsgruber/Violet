.include "overworld_script.s"
.include "callstds.s"

.global ow_script_route_9_horizontal_clouds_trainer_0

ow_script_route_9_horizontal_clouds_trainer_0:
    trainerbattlestd 0 0x12b 0 str_trainer0_challange str_trainer0_defeat
    loadpointer 0 str_trainer0_defeat
    callstd MSG_FACE
    end


.ifdef LANG_GER
str_trainer0_challange:
    .autostring 34 2 "Mein Freunde haben mir gesagt, ich sei so ein Hitzkopf, dass ich irgendwann abheben müsste!\pNun, was soll ich sagen, hier bin ich nun!"
str_trainer0_defeat:
    .autostring 34 2 "Vielleicht kühlt mich diese Niederlage etwas ab, es wäre wirklich an der Zeit."
.elseif LANG_EN
str_trainer0_challange:
    .autostring 34 2 "My friends told me I was such a hothead that eventually I would take off.\pWhat do I say, here I am!"
str_trainer0_defeat:
    .autostring 34 2 "Maybe my defeat cools me down, it really would be time."
.endif
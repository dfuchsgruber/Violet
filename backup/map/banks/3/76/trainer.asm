.include "callstds.s"
.include "overworld_script.s"

.global ow_script_route_1_clouds_trainer_0
ow_script_route_1_clouds_trainer_0:
    trainerbattlestd 0x0 0x8c 0x0 str_challange_0 str_defeat_0
    loadpointer 0x0 str_defeat_0
    callstd MSG_FACE
    end

.ifdef LANG_GER

str_challange_0:
    .autostring 34 2 "Dich habe ich hier noch nie gesehen!\pWas meinst du, bist du ein starker Kämpfer?"
str_defeat_0:
    .autostring 34 2 "Ui!\pDu scheinst etwas vom Fliegen zu verstehen!"
        
.elseif LANG_EN
str_challange_0:
    .autostring 34 2 "I have never seen you up here!\pDo you think that you are a strong fighter?"
str_defeat_0:
    .autostring 34 2 "Ui!\pYou seem to know a thing or two about battling!"

.endif

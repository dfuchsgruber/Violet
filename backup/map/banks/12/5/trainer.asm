.include "overworld_script.s"
.include "callstds.s"

.global ow_script_laubdorf_clouds_trainer_0

ow_script_laubdorf_clouds_trainer_0:
    trainerbattlestd 0 0x128 0 str_trainer0_challange str_trainer0_defeat
    loadpointer 0 str_trainer0_defeat
    callstd MSG_FACE
    end


.ifdef LANG_GER
str_trainer0_challange:
    .autostring 34 2 "Was diese Luft alles für meine Haut tut!\pUnd von meinem kämpferischen Geschick will ich gar nicht anfangen!"
str_trainer0_defeat:
    .autostring 34 2 "Was ist das?\nEtwa eine Falte?"
.elseif LANG_EN
str_trainer0_challange:
    .autostring 34 2 "What this air has already done for my skin!\pAnd I won't start talking about my skills in battle!"
str_trainer0_defeat:
    .autostring 34 2 "What is that?\nIs my skin getting wrinkled?"
.endif
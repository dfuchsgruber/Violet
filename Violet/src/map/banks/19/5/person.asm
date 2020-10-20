.include "overworld_script.s"
.include "callstds.s"
.include "flags.s"
.include "ordinals.s"
.include "mugshot.s"

.global ow_script_ceometria_gym_referee
.global ow_script_ceometria_gym_entrance_person_0

ow_script_ceometria_gym_referee:
    checkflag FRBADGE_5
    gotoif EQUAL gym_beaten
    loadpointer 0 str_ceometria_gym_referee
    callstd MSG_FACE
    end
gym_beaten:
    loadpointer 0 str_beaten
    callstd MSG_FACE
    end

ow_script_ceometria_gym_entrance_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "In dieser Arena dreht sich alles um die Fähigkeit, dein eigenes Schicksal vorsehen zu können.\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pMan kann es natürlich auch als Glückssache betrachtenDOTS"
str_beaten:
    .autostring 34 2 "Ich kann zwar nicht, wie Teah behauptet, in die Zukunft sehen, aber dass du sie schlagen würdest, wusste ich trotzdem!"
.elseif LANG_EN
str_0:
    .autostring 34 2 "In this gym everything is about how well you can predict your own destiny.\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pOr you can also view it as a matter of luck, of courseDOTS"
.endif



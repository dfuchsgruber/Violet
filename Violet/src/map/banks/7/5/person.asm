.include "overworld_script.s"
.include "callstds.s"
.include "flags.s"
.include "ordinals.s"

.global ow_script_silvania_gym_referee

ow_script_silvania_gym_referee:
    checkflag FRBADGE_2
    gotoif EQUAL gym_beaten
    loadpointer 0 str_silvania_gym_referee
    callstd MSG_FACE
    end
gym_beaten:
    loadpointer 0 str_beaten
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_beaten:
    .autostring 34 2 "Wahnsinn!\nDu hast Mia tatsächlich besiegt.\pIch hab dir das natürlich die ganze Zeit über zugetrautDOTS"
.elseif LANG_EN
.endif
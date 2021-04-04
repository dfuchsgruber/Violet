.include "movements.s"
.include "callstds.s"
.include "ordinals.s"
.include "overworld_script.s"
.include "flags.s"
.include "mugshot.s"

.global ow_script_bluetenbach_gym_leader

ow_script_bluetenbach_gym_leader:
    lock
    faceplayer
    checkflag FRBADGE_3
    gotoif EQUAL done
    loadpointer 0 str_0
    show_mugshot MUGSHOT_MANUS MUGSHOT_RIGHT message_type=MSG
    warpmuted 0x5 0x6 0 0xff 0xff
    release
    end

done:
    loadpointer 0 str_1
    show_mugshot MUGSHOT_MANUS MUGSHOT_RIGHT message_type=MSG
    release
    end


.ifdef LANG_GER
str_0:
    .autostring 34 2 "Hah!\nDass du es bis hierher schaffst, hätte ich wirklich nicht gedacht, Kindchen.\pVielleicht hattest du aber auch bloß GlückDOTS\pDeine Herausforderung!\nIch nehme sie hiermit an!"
str_1:
    .autostring 34 2 "Dein Geist und Körper stehen im absoluten Einklang.\pDas ist deine wahre Stärke, Kindchen!\pVergiss das bloß nicht, ja?"

.elseif LANG_EN

.endif
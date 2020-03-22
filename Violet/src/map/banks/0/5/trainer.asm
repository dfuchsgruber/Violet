.include "callstds.s"
.include "overworld_script.s"


.global ow_script_felsige_oednis_trainer_0

ow_script_felsige_oednis_trainer_0:
trainerbattlestd 0x0 0x168 0x0 str_before0 str_after0
loadpointer 0x0 str_after0
callstd MSG_FACE
end


.ifdef LANG_GER
str_before0:
    .autostring 34 2 "Diese verdammte Finsternis macht mich noch wahnsinnig!"
str_after0:
    .autostring 34 2 "Wenn du einen Ausgang findest, komm zurück und hol mich hier raus!"
.elseif LANG_EN
str_before0:
    .autostring 34 2 "This damn darkness makes me go crazy!"
str_after0:
    .autostring 34 2 "If you find an exit, come back and get me out of here!"

.endif
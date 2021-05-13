.include "callstds.s"
.include "overworld_script.s"
.include "vars.s"
.include "ordinals.s"

.global ow_script_route_5_clouds_person_0
.global ow_script_route_5_clouds_person_1
.global ow_script_route_5_clouds_priest

ow_script_route_5_clouds_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end
ow_script_route_5_clouds_person_1:
    loadpointer 0 str_1
    callstd MSG_FACE
    end
ow_script_route_5_clouds_priest:
    loadpointer 0 str_2
    callstd MSG_YES_NO
    compare LASTRESULT 1
    gotoif EQUAL priest_down
    loadpointer 0 str_4
    callstd MSG
    release
    end

priest_down:
    loadpointer 0 str_3
    callstd MSG
    warpmuted 3 23 0xFF 0xe 0x7
    waitstate
    release
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Ich erforsche die Ruinen hier über den Wolken.\pDie antiken Icognito-Schriftzeichen stehen wohl im Zusammenhang mit den legendären Pokémon."
str_1:
    .autostring 34 2 "Vor langer Zeit hat eine antike Zivilisation im Himmelreich gelebt.\pWas wohl aus ihr geworden ist?"
str_2:
    .autostring 34 2 "Wenn du willst, dass ich dir eine Wolke webe, musst du dir den Wolkenfaden schon selbst beschaffen.\pOder willst du etwa, dass ich dich wieder auf den Boden bringe?"
str_3:
    .autostring 34 2 "Ganz wie du möchtest.\pHalt' dich gut fest, es geht abwärts!"
str_4:
    .autostring 34 2 "Sehr gut!\pDann mal los, oder?\pManche der Käfer-Pokémon in dieser Höhle sind in der Lage, den wertvollen Wolkenfaden herzustellen."
.elseif LANG_EN

str_0:
    .autostring 34 2 "I do reserach on the ruins above the clouds.\pThe ancient Unown letters probably somehow relate to the legendary pokémon."
str_1:
    .autostring 34 2 "A long time ago a civilisation lived in the sky realm.\pWhat could have happened to it?"
.endif
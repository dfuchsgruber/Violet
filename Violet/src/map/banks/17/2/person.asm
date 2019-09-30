.include "callstds.s"
.include "overworld_script.s"

.global ow_script_route_5_clouds_person_0
.global ow_script_route_5_clouds_person_1

ow_script_route_5_clouds_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end
ow_script_route_5_clouds_person_1:
    loadpointer 0 str_1
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Ich erforsche die Ruinen hier über den Wolken.\pDie antiken Icognito-Schriftzeichen stehen wohl im Zusammenhang mit den legendären Pokémon."
str_1:
    .autostring 34 2 "Vor langer Zeit hat eine antike Zivilisation im Himmelreich gelebt.\pWas wohl aus ihr geworden ist?"
.elseif LANG_EN

str_0:
    .autostring 34 2 "I do reserach on the ruins above the clouds.\pThe ancient Unown letters probably somehow relate to the legendary pokémon."
str_1:
    .autostring 34 2 "A long time ago a civilisation lived in the sky realm.\pWhat could have happened to it?"
.endif
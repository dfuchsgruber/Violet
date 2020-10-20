.include "overworld_script.s"
.include "callstds.s"

.global ow_script_route_3_clouds_trainer_0

ow_script_route_3_clouds_trainer_0:
    trainerbattlestd 0 0x124 0 str_trainer0_challange str_trainer0_defeat
    loadpointer 0 str_trainer0_defeat
    callstd MSG_FACE
    end


.ifdef LANG_GER
str_trainer0_challange:
    .autostring 34 2 "Es ist so öde hier obenDOTS\pWie wäre es mit einem Kämpfchen zur Auflockerung?"
str_trainer0_defeat:
    .autostring 34 2 "Huch!\pDas war aber überhaupt nicht nett von dirDOTS"
.elseif LANG_EN
str_trainer0_challange:
    .autostring 34 2 "It is so boring up hereDOTS\pHow about a little fighty to distract ourselves?"
str_trainer0_defeat:
    .autostring 34 2 "Yikes!\pThat wasn't very nice of youDOTS"
.endif
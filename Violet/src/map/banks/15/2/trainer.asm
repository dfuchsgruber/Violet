.include "overworld_script.s"
.include "callstds.s"

.global ow_script_route_3_clouds_trainer_0
.global ow_script_route_4_clouds_swamp_trainer_1

ow_script_route_3_clouds_trainer_0:
    trainerbattlestd 0 0x124 0 str_trainer0_challange str_trainer0_defeat
    loadpointer 0 str_trainer_after_0
    callstd MSG_FACE
    end

ow_script_route_4_clouds_swamp_trainer_1:
    trainerbattlestd 0 0x212 0 str_trainer1_challange str_trainer1_defeat
    loadpointer 0 str_trainer_after_1
    callstd MSG_FACE
    end



.ifdef LANG_GER
str_trainer0_challange:
    .autostring 34 2 "Es ist so öde hier obenDOTS\pWie wäre es mit einem Kämpfchen zur Auflockerung?"
str_trainer0_defeat:
    .autostring 34 2 "Huch!\pDas war aber überhaupt nicht nett von dirDOTS"
str_trainer_after_0:
    .autostring 34 2 "Puh, das war anstrengendDOTS\pIch sollte mich wohl mal wieder mehr bewegen und nicht auf dieser Wolke sitzenDOTS"
str_trainer1_challange:
    .autostring 34 2 "Die Pokémon in diesen Sümpfen sind wirklich stark.\pAber meine sind trotzdem gestohlen!"
str_trainer1_defeat:
    .autostring 34 2 "Zurückgeben?\pNiemals werde ich die Pokémon zurückgeben!"
str_trainer_after_1:
    .autostring 34 2 "Vielleicht sollte ich die Pokémon hier in den Sümpfen fangen, anstatt sie zu stehlenDOTS"

.elseif LANG_EN
str_trainer0_challange:
    .autostring 34 2 "It is so boring up hereDOTS\pHow about a little fighty to distract ourselves?"
str_trainer0_defeat:
    .autostring 34 2 "Yikes!\pThat wasn't very nice of youDOTS"
str_trainer_after_0:
    .autostring 34 2 "Phew, that was exhaustingDOTS\pI should probably get moving more and not just sit on this cloudDOTS"
str_trainer1_challange:
    .autostring 34 2 "The Pokémon in these swamps are really strong.\pBut mine are still stolen!"
str_trainer1_defeat:
    .autostring 34 2 "Return them?\pI will never return the Pokémon!"
str_trainer_after_1:
    .autostring 34 2 "Maybe I should catch the Pokémon here in the swamps instead of stealing themDOTS" 
.endif
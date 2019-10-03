.include "overworld_script.s"
.include "callstds.s"
.include "flags.s"
.include "specials.s"
.include "pokemon_types.s"
.include "items.s"
.include "ordinals.s"
.include "vars.s"

.global ow_script_laubdorf_inside_3_person_0

ow_script_laubdorf_inside_3_person_0:
    checkflag FLAG_LAUBDORF_STAERKE
    gotoif EQUAL done
    lockall
    faceplayer
    loadpointer 0 str_0
    callstd MSG_YES_NO
    compare LASTRESULT 1
    gotoif 1 select
dont_show:
    loadpointer 0 str_1
    callstd MSG_KEEPOPEN
    release
    end

select:
    loadpointer 0 str_select
    callstd MSG_KEEPOPEN
    special SPECIAL_SELECT_PARTY_POKEMON
    waitstate
    lockall
    faceplayer
    compare 0x8004 6
    gotoif HIGHER_OR_EQUAL dont_show
    setvar 0x8005 TYPE_KAMPF
    special2 LASTRESULT SPECIAL_PARTY_POKEMON_HAS_TYPE
    compare LASTRESULT 1
    gotoif EQUAL obtain_strength
    loadpointer 0 str_wrong_type
    callstd MSG_KEEPOPEN
    release
    end

obtain_strength:
    loadpointer 0 str_obtain_strength
    callstd MSG_KEEPOPEN
    copyvarifnotzero 0x8000 ITEM_VM04
	copyvarifnotzero 0x8001 1
	callstd ITEM_OBTAIN
    setflag FLAG_LAUBDORF_STAERKE
    loadpointer 0 str_obtained
    callstd MSG_KEEPOPEN
done:
    loadpointer 0 str_done
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_obtained:
    .autostring 34 2 "Diese VM enthält Stärke, ein Angriff, der nur den wirklich starken Pokémon zugedacht ist."

str_obtain_strength:
    .autostring 34 2 "Oh ja!\nDas ist ein wahrlich starkes Pokémon.\pWeißt du, was zu einem solchen Pokémon passen würde?"

str_1:
    .autostring 34 2 "Keine Schande, Kindchen!\pAber solltest du in den Besitz eines starken Pokémon gelangenDOTS\pDann kannst du es mir gerne zeigen!"

str_wrong_type:
    .autostring 34 2 "Das soll ein starkes Pokémon sein?\pNur Pokémon vom Typ Kampf können auch stark sein, das weiß doch jeder!"

str_select:
    .autostring 34 2 "Wunderbar!\pWelches deiner Pokémon ist stark?"

str_done:
    .autostring 34 2 "Stärke ist ein mächtiger Angriff.\pAußerhalb des Kampfes kannst du damit Felsen bewegen, solltest du den Orden von Ceometria errungen haben."

str_0:
    .autostring 34 2 "Ich bin ein Meister der Stärke!\pAlles an mir verkörpert meine Stärke.\pKannst du mir ein starkes Pokémon zeigen?"


.elseif LANG_EN
str_obtained:
    .autostring 34 2 "This HM contains strength, a powerful move only for strong pokémon."

str_obtain_strength:
    .autostring 34 2 "Oh yes!\nThat really is a strong pokémon.\pDo you know what would fit a pokémon like this?"

str_1:
    .autostring 34 2 "No reason to be ashamed.\pBut if you ever should posess a pokémon that is really strongDOTS\pYou can show it to me for sure!"

str_wrong_type:
    .autostring 34 2 "That is supposed to be a strong pokémon?\pOnly pokémon with the fighting type can be strong, isn't that known?"

str_select:
    .autostring 34 2 "Wonderful!\pWhich of your pokémon is strong?"

str_done:
    .autostring 34 2 "Strengh is a powerful move.\pOutside of battle you can even move rocks with it, given that you posess the badge of Ceometria."

str_0:
    .autostring 34 2 "I am the master of strength.\pEverything on me is an embodyment of strength.\pCan you show me a pokémon of strength?"
.endif
.include "vars.s"
.include "attacks.s"
.include "movements.s"
.include "callstds.s"
.include "ordinals.s"
.include "overworld_script.s"
.include "species.s"

.global ow_script_map_3_41_sign_1
.global ow_script_0x83f7e8
.global ow_script_0x83f87e
.global ow_script_0x83f864
.global ow_script_map_3_7_route_2_east_sign_0
.global ow_script_0x83f857
.global ow_script_0x83f829
.global ow_script_0x83f8bb
.global ow_script_0x83f924
.global ow_script_map_3_41_sign_0
.global ow_script_0x83f871
.global ow_script_map_3_41_sign_2

ow_script_map_3_41_sign_0:
loadpointer 0x0 str_0x8aaf9e
callstd MSG_SIGN
end


.ifdef LANG_GER

str_0x8aaf9e:
    .string "Prof. Tanns Labor"


.elseif LANG_EN

.endif


ow_script_0x83f7e8:
bufferattack 0x0 ATTACK_FASSADE
checkattack ATTACK_FASSADE
compare LASTRESULT 0x6
gotoif EQUAL ow_script_0x83f924
loadpointer 0x0 str_0x83f8bf
callstd MSG_YES_NO
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x83f8bb
setanimation 0x0 0x800d
bufferpartypokemon 0x1 0x800d
loadpointer 0x0 str_0x83f89b
callstd MSG_KEEPOPEN
closeonkeypress
doanimation 0x2
nop
waitstate
goto ow_script_0x83f829


ow_script_0x83f829:
compare PLAYERFACING 0x1
gotoif EQUAL ow_script_0x83f864
compare PLAYERFACING 0x2
gotoif EQUAL ow_script_0x83f857
compare PLAYERFACING 0x3
gotoif EQUAL ow_script_0x83f87e
compare PLAYERFACING 0x4
gotoif EQUAL ow_script_0x83f871
end


ow_script_movs_0x83f88f:
.byte STEP_RIGHT_FAST
.byte STEP_RIGHT_FAST
.byte STOP


ow_script_0x83f871:
applymovement 0xff ow_script_movs_0x83f88f
waitmovement 0x0
releaseall
end


ow_script_movs_0x83f893:
.byte STEP_LEFT_FAST
.byte STEP_LEFT_FAST
.byte STOP


ow_script_0x83f87e:
applymovement 0xff ow_script_movs_0x83f893
waitmovement 0x0
releaseall
end


ow_script_movs_0x83f88b:
.byte STEP_UP_FAST
.byte STEP_UP_FAST
.byte STOP


ow_script_0x83f857:
applymovement 0xff ow_script_movs_0x83f88b
waitmovement 0x0
releaseall
end


ow_script_movs_0x83f897:
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STOP


ow_script_0x83f864:
applymovement 0xff ow_script_movs_0x83f897
waitmovement 0x0
releaseall
end


ow_script_0x83f8bb:
closeonkeypress
releaseall
end


ow_script_0x83f924:
loadpointer 0x0 str_0x83f92e
callstd MSG
end


.ifdef LANG_GER

str_0x83f8bf:
    .string "Die Felswand sieht steinig aus, ein\nPokémon kann hier klettern.\lMöchtest du BUFFER_1 einsetzten?"



str_0x83f89b:
    .string "BUFFER_2 setzt BUFFER_1 ein."



str_0x83f92e:
    .string "Die Felswand sieht steinig aus,\nsodass ein Pokémon bestimmt\lhinaufklettern könnte."


.elseif LANG_EN

.endif


ow_script_map_3_41_sign_2:
loadpointer 0x0 str_0x87aba7
callstd MSG_SIGN
end


.ifdef LANG_GER

str_0x87aba7:
    .autostring 35 2 "Achtung!\pWilde Bibor!\nBei Stichen sofort Gegengift auftragen!"


.elseif LANG_EN

.endif


ow_script_map_3_7_route_2_east_sign_0:
loadpointer 0x0 str_0x88bc91
callstd MSG_SIGN
end


.ifdef LANG_GER

str_0x88bc91:
    .string "Westen: Route 2\nOsten: Meriana City"


.elseif LANG_EN

.endif

@ ToDo: Investigate the letter-casing

ow_script_map_3_41_sign_1:
cry POKEMON_BIBOR 0x0
showpokepic POKEMON_BIBOR 0x0 0x0
loadpointer 0x0 str_0x87aad8
callstd MSG
hidepokepic
end


.ifdef LANG_GER

str_0x87aad8:
    .string "Bibor! Bibor!"


.elseif LANG_EN

.endif
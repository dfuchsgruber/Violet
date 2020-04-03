.include "vars.s"
.include "attacks.s"
.include "movements.s"
.include "callstds.s"
.include "ordinals.s"
.include "overworld_script.s"

.global ow_script_0x83fa17
.global ow_script_0x83fa0a
.global ow_script_map_3_70_sign_0
.global ow_script_0x83f9f0
.global ow_script_0x83fa58
.global ow_script_0x83fac1
.global ow_script_0x83f9fd
.global ow_script_0x83f9c2

ow_script_map_3_70_sign_0:
bufferattack 0x0 ATTACK_FASSADE
checkattack ATTACK_FASSADE
compare LASTRESULT 0x6
gotoif EQUAL ow_script_0x83fac1
loadpointer 0x0 str_0x83fa5c
callstd MSG_YES_NO
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x83fa58
setanimation 0x0 0x800d
bufferpartypokemon 0x1 0x800d
loadpointer 0x0 str_0x83fa38
callstd MSG_KEEPOPEN
closeonkeypress
doanimation 0x2
nop
waitstate
goto ow_script_0x83f9c2


ow_script_0x83f9c2:
compare PLAYERFACING 0x1
gotoif EQUAL ow_script_0x83f9fd
compare PLAYERFACING 0x2
gotoif EQUAL ow_script_0x83f9f0
compare PLAYERFACING 0x3
gotoif EQUAL ow_script_0x83fa17
compare PLAYERFACING 0x4
gotoif EQUAL ow_script_0x83fa0a
end


ow_script_movs_0x83fa29:
.byte STEP_RIGHT_FAST
.byte STEP_RIGHT_FAST
.byte STEP_RIGHT_FAST
.byte STOP


ow_script_0x83fa0a:
applymovement 0xff ow_script_movs_0x83fa29
waitmovement 0x0
releaseall
end


ow_script_movs_0x83fa2e:
.byte STEP_LEFT_FAST
.byte STEP_LEFT_FAST
.byte STEP_LEFT_FAST
.byte STOP


ow_script_0x83fa17:
applymovement 0xff ow_script_movs_0x83fa2e
waitmovement 0x0
releaseall
end


ow_script_movs_0x83fa24:
.byte STEP_UP_FAST
.byte STEP_UP_FAST
.byte STEP_UP_FAST
.byte STOP


ow_script_0x83f9f0:
applymovement 0xff ow_script_movs_0x83fa24
waitmovement 0x0
releaseall
end


ow_script_movs_0x83fa33:
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STOP


ow_script_0x83f9fd:
applymovement 0xff ow_script_movs_0x83fa33
waitmovement 0x0
releaseall
end


ow_script_0x83fa58:
closeonkeypress
releaseall
end


ow_script_0x83fac1:
loadpointer 0x0 str_0x83facb
callstd MSG
end


.ifdef LANG_GER

str_0x83fa5c:
    .string "Die Felswand sieht steinig aus, ein\nPokémon kann hier klettern.\lMöchtest du BUFFER_1 einsetzten?"



str_0x83fa38:
    .string "BUFFER_2 setzt BUFFER_1 ein."



str_0x83facb:
    .string "Die Felswand sieht steinig aus,\nsodass ein Pokémon bestimmt\lhinaufklettern könnte."


.elseif LANG_EN

.endif
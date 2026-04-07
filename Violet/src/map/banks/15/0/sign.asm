.include "callstds.s"
.include "overworld_script.s"

.global ow_script_map_15_0_sign_1
.global ow_script_map_15_0_sign_0
.global ow_script_map_15_0_sign_2
.global ow_script_map_route_4_feeding_trough

ow_script_map_15_0_sign_2:
loadpointer 0x0 str_0x8c7d34
callstd MSG_SIGN
end

ow_script_map_route_4_feeding_trough:
    loadpointer 0 str_feeding_trough
    callstd MSG_SIGN
    end

.ifdef LANG_GER
str_feeding_trough:
    .autostring 34 2 "Eine Futtertränke für Pokemon\pDas Wasser ist trüb und riecht strengDOTS"
.elseif LANG_EN
str_feeding_trough:
    .autostring 34 2 "A feeding trough for Pokemon\pThe water is murky and smells foulDOTS"
.endif

.ifdef LANG_GER

str_0x8c7d34:
    .string "UP_ARROW Kranzwald"


.elseif LANG_EN

.endif


ow_script_map_15_0_sign_0:
loadpointer 0x0 str_0x8f6e7f
callstd MSG_SIGN
end


.ifdef LANG_GER

str_0x8f6e7f:
    .string "DOTSAlte WindmühleDOTS\pDie Schrift ist verblasstDOTS"


.elseif LANG_EN

.endif


ow_script_map_15_0_sign_1:
loadpointer 0x0 str_0x8f7189
callstd MSG_SIGN
end


.ifdef LANG_GER

str_0x8f7189:
    .string "Pokemonzucht an der alten Mühle\pBetreiber: Nick und Rick"


.elseif LANG_EN

.endif
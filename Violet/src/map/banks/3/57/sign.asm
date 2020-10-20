.include "callstds.s"
.include "overworld_script.s"

.global ow_script_map_3_57_sign_0

ow_script_map_3_57_sign_0:
loadpointer 0x0 str_0x8f46ca
callstd MSG_SIGN
end


.ifdef LANG_GER

str_0x8f46ca:
    .string "Trainerschule\nSchulleiter: Faun"
.elseif LANG_EN

str_0x8f46ca:
    .string "Trainerschool\nHeadmaster: Faun"
.endif
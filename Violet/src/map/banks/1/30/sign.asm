.include "callstds.s"
.include "overworld_script.s"

.global ow_script_map_1_30_sign_1
.global ow_script_map_1_30_sign_0

ow_script_map_1_30_sign_1:
loadpointer 0x0 str_0x96afef
callstd MSG_SIGN
end


.ifdef LANG_GER

str_0x96afef:
    .string "Norden: Haus des Glasbläsers\nSüden: Route 6"


.elseif LANG_EN

.endif


ow_script_map_1_30_sign_0:
loadpointer 0x0 str_0x95ffcf
callstd MSG_SIGN
end


.ifdef LANG_GER

str_0x95ffcf:
    .string "Haus des Glasbläsers"


.elseif LANG_EN

.endif
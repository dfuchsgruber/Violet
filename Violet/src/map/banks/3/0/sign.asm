.include "callstds.s"
.include "overworld_script.s"

.global ow_script_map_3_0_sign_0
.global ow_script_map_3_0_sign_1
.global ow_script_map_3_0_sign_2

ow_script_map_3_0_sign_2:
loadpointer 0x0 str_0x80062f
callstd MSG_SIGN
end


.ifdef LANG_GER

str_0x80062f:
    .string "Anemonia"


.elseif LANG_EN

.endif


ow_script_map_3_0_sign_1:
loadpointer 0x0 str_0x800688
callstd MSG_SIGN
end


.ifdef LANG_GER

str_0x800688:
    .string "PLAYERs Haus"


.elseif LANG_EN

.endif


ow_script_map_3_0_sign_0:
loadpointer 0x0 str_0x87aafc
callstd MSG_SIGN
end


.ifdef LANG_GER

str_0x87aafc:
    .string "RIVALs Haus"


.elseif LANG_EN

.endif
.include "callstds.s"
.include "overworld_script.s"

.global ow_script_map_4_2_sign_0

ow_script_map_4_2_sign_0:
loadpointer 0x0 str_0x8f4eff
callstd MSG_SIGN
end


.ifdef LANG_GER

str_0x8f4eff:
    .string "RIVALs Computer scheint das neuste\nModell zu sein!\pDOTS\pIch sollte mich auf den Weg\nmachen."


.elseif LANG_EN

.endif
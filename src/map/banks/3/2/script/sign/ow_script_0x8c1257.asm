.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x8c1257
ow_script_0x8c1257:
loadpointer 0x0 str_0x8ca664
callstd MSG_SIGN
end


.ifdef LANG_GER
.global str_0x8ca664

str_0x8ca664:
    .string "Arena von Aktania\pTyp: Gestein\nLeiter: Lester"
        
        
.elseif LANG_EN

.endif

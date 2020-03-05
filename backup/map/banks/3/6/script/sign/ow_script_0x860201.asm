.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x860201
ow_script_0x860201:
loadpointer 0x0 str_0x86020b
callstd MSG_SIGN
end


.ifdef LANG_GER
.global str_0x86020b

str_0x86020b:
    .string "Arena von Inferior\pTyp: Feuer\nLeiter: Igva"
        
        
.elseif LANG_EN

.endif

.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x1afed8
ow_script_0x1afed8:
loadpointer 0x0 str_0x195c7a
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x195c7a

str_0x195c7a:
    .string "Ich bin erst vor kurzem in diese\nStadt gezogen!"
        
        
.elseif LANG_EN

.endif

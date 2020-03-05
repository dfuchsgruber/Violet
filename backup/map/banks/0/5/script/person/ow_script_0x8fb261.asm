.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x8fb261
ow_script_0x8fb261:
loadpointer 0x0 str_0x8fb26b
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8fb26b

str_0x8fb26b:
    .string "Gemäß Insider-Informationen soll\nman in dieser Höhle Fossilien\lfinden können.\pOb ich eines ergattern kann?"
        
        
.elseif LANG_EN

.endif

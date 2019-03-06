.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x86477a
ow_script_0x86477a:
loadpointer 0x0 str_0x96afef
callstd MSG_SIGN
end


.ifdef LANG_GER
.global str_0x96afef

str_0x96afef:
    .string "Norden: Haus des Glasbläsers\nSüden: Route 6"
        
        
.elseif LANG_EN

.endif

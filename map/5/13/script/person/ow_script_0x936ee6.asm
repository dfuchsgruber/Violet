.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x936ee6
ow_script_0x936ee6:
loadpointer 0x0 str_0x93c067
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x93c067

str_0x93c067:
    .string "Diese Arena ist perfekt geeignet\nzur Mediation und zum Training.\pGeist und Körper können sich hier\nvoll und ganz entfalten."
        
        
.elseif LANG_EN

.endif

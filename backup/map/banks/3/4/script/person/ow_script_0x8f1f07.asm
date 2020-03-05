.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x8f1f07
ow_script_0x8f1f07:
loadpointer 0x0 str_0x8f2194
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8f2194

str_0x8f2194:
    .string "Von einem Untergrundhandel weiß\nich nichtsDOTS\pWie, du hast nicht gefragt?"
        
        
.elseif LANG_EN

.endif

.include "overworld_script.s"

.include "std.s"

.global ow_script_0x84b0f7
ow_script_0x84b0f7:
loadpointer 0x0 str_0x85ffad
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x85ffad

str_0x85ffad:
    .string "Aufgrund meines Alters vergesse ich\nnicht selten Diskretionsabstand\leinzahlten."
        
        
.elseif LANG_EN

.endif

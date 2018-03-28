.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x89a16d
ow_script_0x89a16d:
call ow_script_0x89e1fc
loadpointer 0x0 str_0x8a0590
callstd MSG_FACE
special 0x7
end


.ifdef LANG_GER
.global str_0x8a0590

str_0x8a0590:
    .string "Ja, das ist eigentlich ganz\ngut gelaufen...\lWie ist es dir ergangen?"
        
        
.elseif LANG_EN

.endif

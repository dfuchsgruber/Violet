.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x895a9a
ow_script_0x895a9a:
loadpointer 0x0 str_0x8a200c
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8a200c

str_0x8a200c:
    .string "Dieser Tunnel soll nach Route 2\nführen, aber ich fürchte mich vor\lHöhlen."
        
        
.elseif LANG_EN

.endif

.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x90fff5
ow_script_0x90fff5:
loadpointer 0x0 str_0x936852
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x936852

str_0x936852:
    .string "Der Wasserpfad ist ein\nunterirdischer Tunnel, welcher\lunter einem Flussbett verläuft."
        
        
.elseif LANG_EN

.endif

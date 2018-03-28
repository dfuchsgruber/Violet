.include "overworld_script.s"

.include "std.s"

.global ow_script_0x918a68
ow_script_0x918a68:
loadpointer 0x0 str_0x936eb2
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x936eb2

str_0x936eb2:
    .string "Mein Freund mag die feuchte Luft\nin diesem Tunnel."
        
        
.elseif LANG_EN

.endif

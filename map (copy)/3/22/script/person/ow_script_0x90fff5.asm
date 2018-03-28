.include "overworld_script.s"

.include "std.s"

.global ow_script_0x90fff5
ow_script_0x90fff5:
loadpointer 0x0 str_0x936852
callstd MSG_FACE
end

.global str_0x936852

str_0x936852:
    .string "Der Wasserpfad ist ein\nunterirdischer Tunnel, welcher\lunter einem Flussbett verläuft."
        
        
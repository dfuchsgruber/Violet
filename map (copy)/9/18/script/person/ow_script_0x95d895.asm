.include "overworld_script.s"

.include "std.s"

.global ow_script_0x95d895
ow_script_0x95d895:
loadpointer 0x0 str_0x95d89f
callstd MSG_FACE
end

.global str_0x95d89f

str_0x95d89f:
    .string "Viele Leute werfen Beeren oder\nandere Dinge in den Müll.\pIch habe gehört, dass man im Laufe\neiner Woche sehr viele neue Dinge\lfinden kann."
        
        
.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8dca38
ow_script_0x8dca38:
loadpointer 0x0 str_0x8de6ea
callstd MSG_FACE
end

.global str_0x8de6ea

str_0x8de6ea:
    .string "Jeder korrupte Polizist soll\nbezahlen für seine Taten!"
        
        
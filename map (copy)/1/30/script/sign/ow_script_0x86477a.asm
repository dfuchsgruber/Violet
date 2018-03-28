.include "overworld_script.s"

.include "std.s"

.global ow_script_0x86477a
ow_script_0x86477a:
loadpointer 0x0 str_0x96afef
callstd MSG_SIGN
end

.global str_0x96afef

str_0x96afef:
    .string "Norden: Haus des Glasbläsers\nSüden: Route 6"
        
        
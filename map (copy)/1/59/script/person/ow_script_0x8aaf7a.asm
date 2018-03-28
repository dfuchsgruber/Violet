.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8aaf7a
ow_script_0x8aaf7a:
loadpointer 0x0 str_0x927fbc
callstd MSG
end

.global str_0x927fbc

str_0x927fbc:
    .string "Ihr systemtreuen Narren! Versteht\nihr nicht, dass alles dem\lUntergang geweiht ist?"
        
        
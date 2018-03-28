.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8104f8
ow_script_0x8104f8:
loadpointer 0x0 str_0x8aaf9e
callstd MSG_SIGN
end

.global str_0x8aaf9e

str_0x8aaf9e:
    .string "Prof. Tanns Labor"
        
        
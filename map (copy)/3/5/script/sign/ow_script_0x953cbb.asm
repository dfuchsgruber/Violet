.include "overworld_script.s"

.include "std.s"

.global ow_script_0x953cbb
ow_script_0x953cbb:
loadpointer 0x0 str_0x95587d
callstd MSG_SIGN
end

.global str_0x95587d

str_0x95587d:
    .string "Orina City, die Stadt der\nWolkenkratzer"
        
        
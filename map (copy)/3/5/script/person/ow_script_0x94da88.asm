.include "overworld_script.s"

.include "std.s"

.global ow_script_0x94da88
ow_script_0x94da88:
loadpointer 0x0 str_0x94e243
callstd MSG_FACE
end

.global str_0x94e243

str_0x94e243:
    .string "Die Technologie, die in der\nLaz.Corp entwickelt wird, ist\lihrer Zeit ein halbes Jahrhundert\lvorraus."
        
        
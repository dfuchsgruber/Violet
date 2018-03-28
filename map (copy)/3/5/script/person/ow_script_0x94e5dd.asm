.include "overworld_script.s"

.include "std.s"

.global ow_script_0x94e5dd
ow_script_0x94e5dd:
loadpointer 0x0 str_0x94e5e7
callstd MSG_FACE
end

.global str_0x94e5e7

str_0x94e5e7:
    .string "Mami! Können wir noch ins Museum\ngehen?"
        
        
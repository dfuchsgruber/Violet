.include "overworld_script.s"

.include "std.s"

.global ow_script_0x94e9d2
ow_script_0x94e9d2:
loadpointer 0x0 str_0x94e9dc
callstd MSG_FACE
end

.global str_0x94e9dc

str_0x94e9dc:
    .string "Es ist wichtig, einfach einmal\nabzuschalten und den Geist wandern\lzu lassen..."
        
        
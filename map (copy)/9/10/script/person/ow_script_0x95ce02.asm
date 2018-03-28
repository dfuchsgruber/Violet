.include "overworld_script.s"

.include "std.s"

.global ow_script_0x95ce02
ow_script_0x95ce02:
loadpointer 0x0 str_0x95ce0c
callstd MSG_FACE
end

.global str_0x95ce0c

str_0x95ce0c:
    .string "Bücher sind der Weg, einen Geist\nauch über den Tod hinweg am Leben\lzu erhalten."
        
        
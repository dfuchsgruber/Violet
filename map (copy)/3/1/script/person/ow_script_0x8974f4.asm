.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8974f4
ow_script_0x8974f4:
loadpointer 0x0 str_0x8a2078
callstd MSG_FACE
end

.global str_0x8a2078

str_0x8a2078:
    .string "Versteckte Maschienen ermöglichen\noft den Ort zu sonst\lunzugänglichen Arealen. Manchmal\lfindet man dort tolle Items."
        
        
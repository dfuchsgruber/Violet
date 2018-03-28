.include "overworld_script.s"

.include "std.s"

.global ow_script_0x82a1a8
ow_script_0x82a1a8:
loadpointer 0x0 str_0x8bf9ef
callstd MSG_FACE
end

.global str_0x8bf9ef

str_0x8bf9ef:
    .string "Die Arbeit auf der Farm ist\nKnochenarbeit. Aber sie befreit\lden Geist und bringt einen in\lEinklang mit der Natur. Vor allem\lzu den Voltilamm habe ich eine\lenge Beziehung aufgebaut."
        
        
.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8ef7de
ow_script_0x8ef7de:
trainerbattlestd 0x0 0x49 0x0 str_0x8ef8b7 str_0x8efbc3
loadpointer 0x0 str_0x8efbc3
callstd MSG_FACE
end

.global str_0x8ef8b7

str_0x8ef8b7:
    .string "Ich kämpfe für Frieden und\nOrdnung! Und mein Kampf ist nobel!"
        
        
.global str_0x8efbc3

str_0x8efbc3:
    .string "Als Herrscher der Welt bringen wir\ndie Ordnung!"
        
        
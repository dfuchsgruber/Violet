.include "overworld_script.s"

.include "std.s"

.global ow_script_0x86c216
ow_script_0x86c216:
trainerbattlestd 0x0 0x69 0x0 str_0x922d48 str_0x926a50
loadpointer 0x0 str_0x926a50
callstd MSG_FACE
end

.global str_0x922d48

str_0x922d48:
    .string "Mit meinen Psychokräften kann ich\ndie Täuschungen der Fata Morganas\lleicht bezwingen!"
        
        
.global str_0x926a50

str_0x926a50:
    .string "Ich kann Traum von Wirklichkeit\nunterscheiden, aber den Kampf\lkonnte ich nicht gewinnen."
        
        
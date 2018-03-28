.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8e6a52
ow_script_0x8e6a52:
trainerbattlestd 0x0 0x44 0x0 str_0x8f2b8a str_0x8f3993
loadpointer 0x0 str_0x8f3993
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8f2b8a

str_0x8f2b8a:
    .string "Wir von Team Violet sind daran\ninteressiert, die Welt in einen\lbesseren Ort zu verwandeln.\lMit einem Krieg werden wir Frieden\lstiften!"
        
        
.global str_0x8f3993

str_0x8f3993:
    .string "Du wirst uns nicht aufhalten\nkönnen, der ewige Frieden wird\lkommen!"
        
        
.elseif LANG_EN

.endif

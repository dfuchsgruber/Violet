.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8a2d5a
ow_script_0x8a2d5a:
loadpointer 0x0 str_0x8a359d
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8a359d

str_0x8a359d:
    .string "Mein Vater hat die Mytologie der\nPokémon Welt studiert. Sein Werk\lträgt den Titel QUOTEUnsere Welt - vom\lEi zum PokémonQUOTE und ist weltweit\lein Bestseller. Ich bin sehr stolz\ldeswegen."
        
        
.elseif LANG_EN

.endif

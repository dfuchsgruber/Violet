.include "overworld_script.s"

.include "std.s"

.global ow_script_0x95fb90
ow_script_0x95fb90:
loadpointer 0x0 str_0x9631de
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x9631de

str_0x9631de:
    .string "Ich werde mein ganzes Team aus\nFeuer-Pokémon zusammenstellen.\pDann werde ich der nächste\nArenaleiter von Inferior!"
        
        
.elseif LANG_EN

.endif

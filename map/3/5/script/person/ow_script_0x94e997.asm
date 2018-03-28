.include "overworld_script.s"

.include "std.s"

.global ow_script_0x94e997
ow_script_0x94e997:
loadpointer 0x0 str_0x94e9a1
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x94e9a1

str_0x94e9a1:
    .string "Ob ich in den Blumenkästen\nKäfer-Pokémon finde?"
        
        
.elseif LANG_EN

.endif

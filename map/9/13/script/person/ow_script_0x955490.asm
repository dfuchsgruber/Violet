.include "overworld_script.s"

.include "std.s"

.global ow_script_0x955490
ow_script_0x955490:
loadpointer 0x0 str_0x955c37
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x955c37

str_0x955c37:
    .string "Hast du je von Team Rocket gehört?\nEs heißt, ihnen sei es gelungen,\lein Pokémon zu klonen."
        
        
.elseif LANG_EN

.endif

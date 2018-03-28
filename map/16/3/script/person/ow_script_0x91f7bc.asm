.include "overworld_script.s"

.include "std.s"

.global ow_script_0x91f7bc
ow_script_0x91f7bc:
loadpointer 0x0 str_0x9377fe
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x9377fe

str_0x9377fe:
    .string "Ein Glück ist dieser Tunnel nicht\ndunkel.\pKeines meiner Pokémon kennnt die\nAttacke Blitz!"
        
        
.elseif LANG_EN

.endif

.include "overworld_script.s"

.include "std.s"

.global ow_script_0x95e39d
ow_script_0x95e39d:
loadpointer 0x0 str_0x95e3a7
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x95e3a7

str_0x95e3a7:
    .string "In Hoenn gibt es eine Person, die\naus Asche Flöten herstellen kann.\pDie Klänge sollen Pokémon bei der\nGenesung helfen."
        
        
.elseif LANG_EN

.endif

.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8e1126
ow_script_0x8e1126:
loadpointer 0x0 str_0x8e6626
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8e6626

str_0x8e6626:
    .string "Manchmal findet man hier einige\nGeist Pokémon, die sich von\lCeometria, der Stadt der Toten,\ldie südlich liegt, hierher verirrt\lhaben."
        
        
.elseif LANG_EN

.endif

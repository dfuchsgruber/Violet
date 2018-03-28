.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8fe8bd
ow_script_0x8fe8bd:
loadpointer 0x0 str_0x8febc6
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8febc6

str_0x8febc6:
    .string "Einer Legende nach sind hier die\nSieglkammern eines legendären\lPokémon."
        
        
.elseif LANG_EN

.endif

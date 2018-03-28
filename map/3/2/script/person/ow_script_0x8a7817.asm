.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x8a7817
ow_script_0x8a7817:
loadpointer 0x0 str_0x8c0f86
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8c0f86

str_0x8c0f86:
    .string "Wenn ich ein Pokémon hätte, das\nSurfer beherrscht, dann könnte ich\lauf ihm gen Westen reiten!"
        
        
.elseif LANG_EN

.endif

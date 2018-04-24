.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x94da76
ow_script_0x94da76:
loadpointer 0x0 str_0x94e126
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x94e126

str_0x94e126:
    .string "Ich komme oft hierher, um mir die\nFossilien im Museum anzusehen.\lDass Pokémon vor so vielen\lJahrhunderten unsere Welt\lbesiedelt haben... Unglaublich!"
        
        
.elseif LANG_EN

.endif

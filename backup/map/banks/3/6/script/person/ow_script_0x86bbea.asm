.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x86bbea
ow_script_0x86bbea:
loadpointer 0x0 str_0x86eed0
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x86eed0

str_0x86eed0:
    .string "Ich habe gehört, dass man in den\nThermen besonders gut Pokémon-Eier\lausbrüten kann."
        
        
.elseif LANG_EN

.endif

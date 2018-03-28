.include "overworld_script.s"

.include "std.s"

.global ow_script_0x86bbea
ow_script_0x86bbea:
loadpointer 0x0 str_0x86eed0
callstd MSG_FACE
end

.global str_0x86eed0

str_0x86eed0:
    .string "Ich habe gehört, dass man in den\nThermen besonders gut Pokémon-Eier\lausbrüten kann."
        
        
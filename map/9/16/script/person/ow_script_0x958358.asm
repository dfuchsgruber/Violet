.include "overworld_script.s"

.include "std.s"

.global ow_script_0x958358
ow_script_0x958358:
loadpointer 0x0 str_0x958f48
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x958f48

str_0x958f48:
    .string "Ich habe gehört, dass das Museum\neng mit der Laz.Corp\lzusammenarbeitet.\pGerüchten zufolge geht es um die\nRestauration von ausgestorbenen\lPokémon aus deren Fossilien."
        
        
.elseif LANG_EN

.endif

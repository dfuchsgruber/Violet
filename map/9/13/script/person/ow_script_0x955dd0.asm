.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x955dd0
ow_script_0x955dd0:
loadpointer 0x0 str_0x9581f2
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x9581f2

str_0x9581f2:
    .string "Ich bin dafür verantwortlich, dass\naus den Simuatlionen des\lvirtuellen Pokémons Porygon ein\lmaterielles Objekt entsteht...\pDie Chemie zur Erschaffung eines\nPokémons ist keineswegs trivial."
        
        
.elseif LANG_EN

.endif

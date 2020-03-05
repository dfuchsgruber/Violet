.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x94bf5d
ow_script_0x94bf5d:
loadpointer 0x0 str_0x94dcc8
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x94dcc8

str_0x94dcc8:
    .string "Das Museum von Orina City sollte\nein Punkt auf jeder guten\lSightseeing-Tour sein.\pDie Nachbildungen antiker Pokémon\nsind schlichtweg beeindruckend."
        
        
.elseif LANG_EN

.endif

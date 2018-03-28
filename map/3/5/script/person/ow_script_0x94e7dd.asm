.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x94e7dd
ow_script_0x94e7dd:
loadpointer 0x0 str_0x94e7e7
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x94e7e7

str_0x94e7e7:
    .string "Die Orina City Bank ist gerissen.\nNimmst du dir einen Kredit,\lverlangen sie ein Fünftel als\lZinssatz.\pUnd sie kapseln es klammheimlich\nvon deinem gewonnen Preisgeld ab!\lUnverschämtheit!"
        
        
.elseif LANG_EN

.endif

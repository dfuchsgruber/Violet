.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x95f734
ow_script_0x95f734:
loadpointer 0x0 str_0x95f73e
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x95f73e

str_0x95f73e:
    .string "Von Zeit zu Zeit fliegt ein\nbrennendes Pokémon über die Wipfel\ldes Aschhains.\pIch frage mich, ob es sich um ein\nseltenes Pokémon handelt."
        
        
.elseif LANG_EN

.endif

.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x89aab1
ow_script_0x89aab1:
loadpointer 0x0 str_0x9277cd
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x9277cd

str_0x9277cd:
    .string "Ich habe eine besondere Beziehung\nzu Pflanzen. Ich verstehe sie, ich\lweiß, ich kann mich in sie\lhineinfühlen.\pVielleicht sollte ich nach\nSilvania ziehen. Das Dorf wurde in\lder Lichtung eines Waldes\lerrichtet."
        
        
.elseif LANG_EN

.endif

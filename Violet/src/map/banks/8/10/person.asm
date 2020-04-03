.include "callstds.s"
.include "overworld_script.s"

.global ow_script_map_8_10_person_1
.global ow_script_map_8_10_person_0

ow_script_map_8_10_person_1:
loadpointer 0x0 str_0x9277cd
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x9277cd:
    .string "Ich habe eine besondere Beziehung\nzu Pflanzen. Ich verstehe sie, ich\lweiß, ich kann mich in sie\lhineinfühlen.\pVielleicht sollte ich nach\nSilvania ziehen. Das Dorf wurde in\lder Lichtung eines Waldes\lerrichtet."


.elseif LANG_EN

.endif


ow_script_map_8_10_person_0:
loadpointer 0x0 str_0x9278f8
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x9278f8:
    .string "Im Fernsehen laufen stets\ninteressante Dinge. Nicht zuletzt,\lweil das Programm so vielfältig\list.\pWirf doch auch das eine oder\nandere Mal einen Blick auf einen\lFernseher, vielleicht gefällt dir,\lwas du siehst."


.elseif LANG_EN

.endif
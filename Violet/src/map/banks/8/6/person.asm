.include "callstds.s"
.include "overworld_script.s"

.global ow_script_map_8_6_person_1
.global ow_script_map_8_6_person_0

ow_script_map_8_6_person_0:
loadpointer 0x0 str_0x87f1e8
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x87f1e8:
    .string "Ich liebe den Regen, wenn er auf\ndas Dach niederprasst und dabei\lgemütlich knattert."


.elseif LANG_EN

.endif


ow_script_map_8_6_person_1:
loadpointer 0x0 str_0x87f23e
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x87f23e:
    .string "Es genügt nicht, Gutes zu tun,\nwenn man selbst keine\lBeeinträchtung erfährt.\pTrotz des eigenen Nachteils im\nSinne anderer zu handeln, das ist\lwahre Güte."


.elseif LANG_EN

.endif
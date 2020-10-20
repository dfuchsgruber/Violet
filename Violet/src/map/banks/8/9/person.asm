.include "callstds.s"
.include "overworld_script.s"

.global ow_script_map_8_9_person_2
.global ow_script_map_8_9_person_1
.global ow_script_map_8_9_person_0

ow_script_map_8_9_person_1:
loadpointer 0x0 str_0x92723b
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x92723b:
    .string "Ich habe miterlebt, wie die drei\ngrößten Trainer ihrer Zeit die Top\lVier ins Leben riefen.\pIhre Wege mögen sich getrennt\nhaben, ihr Vermächtnis aber ist\lnoch immer standhaft."


.elseif LANG_EN

.endif


ow_script_map_8_9_person_2:
loadpointer 0x0 str_0x87fba3
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x87fba3:
    .string "Seit einigen Monaten sehe ich hier\nimmer öfter Revolutionäre in ihren\lsmaragdgrünen Roben.\pWas sie wohl hier wollen?"


.elseif LANG_EN

.endif


ow_script_map_8_9_person_0:
loadpointer 0x0 str_0x9272eb
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x9272eb:
    .string "Mein Papa sagt immer, dass ein\nguter Trainer auch ein guter\lMensch sein sollte."


.elseif LANG_EN

.endif
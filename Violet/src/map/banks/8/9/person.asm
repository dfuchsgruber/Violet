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
    .autostring 34 2 "Ich habe noch miterlebt, wie die drei größten Trainer der Geschichte ihrerseits Pokémon-Liga gegründet haben.\pIhre Wege mögen sich heute freilich getrennt haben, aber ihr Vermächtis besteht noch immer."
.elseif LANG_EN

.endif


ow_script_map_8_9_person_2:
loadpointer 0x0 str_0x87fba3
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x87fba3:
    .autostring 34 2 "Meine Oma erzählt uns immer viel von den Gründern der Pokémon-Liga.\pBesonders der Pinke Faun hat es ihr angetan.\pOb sie sich in ihrer Jugend vielleicht in ihn verguckt hatte?"


.elseif LANG_EN

.endif


ow_script_map_8_9_person_0:
loadpointer 0x0 str_0x9272eb
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x9272eb:
    .autostring 34 2 "Meine Omi sagt uns immer, dass ein guter Trainer auch ein guter Mensch sein soll.\pEben genauso, wie der Pinke Faun!\pIst doch klar!"


.elseif LANG_EN

.endif
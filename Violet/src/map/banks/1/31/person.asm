.include "callstds.s"
.include "overworld_script.s"

.global ow_script_map_1_31_trainer_3
.global ow_script_map_1_31_trainer_2
.global ow_script_map_1_31_trainer_0
.global ow_script_map_1_31_trainer_1
.global ow_script_map_1_31_person_0

ow_script_map_1_31_person_0:
loadpointer 0x0 str_0x95f573
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x95f573:
    .string "Der Aschhain ist ein kleiner Wald\nam Fuße eines kleinen Hügels.\pAlles dreht sich um das kleine, an\ndiesem OrtDOTS"


.elseif LANG_EN

.endif


ow_script_map_1_31_trainer_0:
trainerbattlestd 0x0 0x99 0x0 str_0x95f5fd str_0x95f646
loadpointer 0x0 str_0x95f646
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x95f5fd:
    .string "Ah, du willst gegen mich kämpfen?\nIch habe noch keinen Kampf\lverloren!"



str_0x95f646:
    .string "Für alles gibt es ein erstes Mal."


.elseif LANG_EN

.endif


ow_script_map_1_31_trainer_1:
trainerbattlestd 0x0 0x9a 0x0 str_0x95f681 str_0x95f6f4
loadpointer 0x0 str_0x95f6f4
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x95f681:
    .string "Ein Wanderer muss jede Wanderung\nauf sich nehmen.\lSelbst bei der Aussicht zu\lverbrennen, kann ich nicht\lkneifen!"



str_0x95f6f4:
    .string "Deine Herausforderung ist wohl das\nEnde meiner WanderschaftDOTS"


.elseif LANG_EN

.endif


ow_script_map_1_31_trainer_2:
loadpointer 0x0 str_0x95f73e
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x95f73e:
    .string "Von Zeit zu Zeit fliegt ein\nbrennendes Pokémon über die Wipfel\ldes Aschhains.\pIch frage mich, ob es sich um ein\nseltenes Pokémon handelt."


.elseif LANG_EN

.endif


ow_script_map_1_31_trainer_3:
loadpointer 0x0 str_0x95f7e0
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x95f7e0:
    .string "Im Aschhain lebt ein alter Mann,\nder aus Asche Flöten herstellen\lkann.\pEs heißt, dass er der Schüler\neines Meisters aus Hoenn ist."


.elseif LANG_EN

.endif
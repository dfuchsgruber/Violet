.include "callstds.s"
.include "overworld_script.s"
.include "species.s"

.global ow_script_map_3_19_trainer_2
.global ow_script_map_3_19_person_0
.global ow_script_0x8dce51
.global ow_script_map_3_19_trainer_0
.global ow_script_map_3_19_trainer_3
.global ow_script_map_1_59_trainer_1
.global ow_script_0x8f6111
.global ow_script_map_3_19_trainer_1
.global ow_script_map_3_19_trainer_4

ow_script_map_3_19_person_0:
lock
faceplayer
loadpointer 0x0 str_0x804215
callstd MSG
release
end


.ifdef LANG_GER

str_0x804215:
    .string "Ich bin kein Trainer. Da ich kein\nPokémon besitze, können wir auch\lnicht kämpfen."


.elseif LANG_EN

.endif


ow_script_map_3_19_trainer_0:
trainerbattlestd 0x0 0x1 0x0 str_0x8040c2 str_0x804122
loadpointer 0x0 str_0x804122
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8040c2:
    .string "Wenn sich die Blicke zweier Trainer\ntreffen, kommt es unweigerlich zu\leinem Kampf. Los!"



str_0x804122:
    .string "Verliert ein Trainer gegen einen\nanderen, so muss er ihm Preisgeld\lgeben. Das sind die Regeln!"


.elseif LANG_EN

.endif


ow_script_map_3_19_trainer_1:
trainerbattlestd 0x0 0x2 0x0 str_0x804181 str_0x8041dd
loadpointer 0x0 str_0x8041dd
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x804181:
    .string "Mit einem Pokeball kannst du wilde\nPokémon fangen, sodass sie dir\lgehorchen. Toll nicht?"



str_0x8041dd:
    .string "Ich habe mein Pokémon auch mit\neinem Pokeball gefangen."


.elseif LANG_EN

.endif


ow_script_map_3_19_trainer_2:
loadpointer 0x0 str_0x8a0b9e
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8a0b9e:
    .string "Hier im hohen Gras tauchen auf\nverschiedenen Routen verschiedene\lPokémon auf. Man kann sich also\lnie sicher sein, alle Pokémon\lgesehen zu haben. Spannend, nicht?"


.elseif LANG_EN

.endif


ow_script_map_3_19_trainer_3:
trainerbattlestd 0x0 0x3 0x0 str_0x8a09e3 str_0x8a0a35
loadpointer 0x0 str_0x8a0a35
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8a09e3:
    .string "Ein Trainer hat stets viele Tränke\nbei sich, wenn er gut ausgerüstet\lsein will."



str_0x8a0a35:
    .string "Doch die Ausrüstung eines Trainers\nist natürlich nicht alles."


.elseif LANG_EN

.endif


ow_script_map_1_59_trainer_1:
trainerbattlestd 0x0 0x6c 0x0 str_0x927db0 str_0x927d4e
loadpointer 0x0 str_0x927d4e
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x927db0:
    .string "Hey, du da!\nDu kannst da nicht lang, unser\lAnführer hat dort zu tun.\pEr wird die Welt zu einem besseren\nOrt machen, weswegen ich dich\lnicht passieren lassen kann."



str_0x927d4e:
    .string "Wieso widersetzt du dich dem\nRecht, dem Frieden? Träumst du\lnicht auch von einer besseren\lWelt?"


.elseif LANG_EN

.endif


ow_script_0x8dce51:
setvar 0x8000 POKEMON_ENECO
call ow_script_find_egg
end



ow_script_map_3_19_trainer_4:
lockall
trainerbattlecont 0x1 0x2b7 0x0 str_0x8f610c str_0x8f610c ow_script_0x8f6111


ow_script_0x8f6111:
releaseall
end


.ifdef LANG_GER

str_0x8f610c:
    .string "hi"


.elseif LANG_EN

.endif
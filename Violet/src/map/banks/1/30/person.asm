.include "callstds.s"
.include "overworld_script.s"

.global ow_script_map_1_30_trainer_0
.global ow_script_map_1_30_trainer_1
.global ow_script_map_1_30_trainer_4
.global ow_script_map_1_30_trainer_3
.global ow_script_map_1_30_person_0
.global ow_script_map_1_30_trainer_2

ow_script_map_1_30_person_0:
loadpointer 0x0 str_0x95feaf
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x95feaf:
    .string "Bist du mit dem Angriff\nHitzekoller vertraut?\pEr gilt als einer der stärksten\nAngriffe des Typs Feuer."


.elseif LANG_EN

.endif


ow_script_map_1_30_trainer_1:
loadpointer 0x0 str_0x960444
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x960444:
    .string "Der nette Herr in dem Haus dort\nist ein Künstler.\pEr stellt Flöten aus Asche her.\nDu solltest ihn besuchen."


.elseif LANG_EN

.endif


ow_script_map_1_30_trainer_0:
trainerbattlestd 0x0 0x9c 0x0 str_0x95ff17 str_0x95ff6e
loadpointer 0x0 str_0x95ff6e
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x95ff17:
    .string "Denkst du, du kannst mich, einen\nAss-Trainer, so ohne Weiteres\lbesiegen? Komm schon!"



str_0x95ff6e:
    .string "So ist das Leben, mal flach und\nmal eben."


.elseif LANG_EN

.endif


ow_script_map_1_30_trainer_3:
loadpointer 0x0 str_0x962d54
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x962d54:
    .string "Seit vielen Jahren ist dieses\nGebiet unter den Top Vier\lumkämpft.\pDer Schwarze Devin und der Rosa\nFaun haben einst einen Wettkampf\lüber die Herrschaft in diesem\lGebiet abgehalten.\pZwar ist der Schwarze Devin ein\nSchüler Fauns gewesen, doch konnte\ler seinen Meister nicht bezwingen.\pDa sieht man einmal wieder, dass\nman nicht zu überheblich werden\lsollte."


.elseif LANG_EN

.endif


ow_script_map_1_30_trainer_2:
trainerbattlestd 0x0 0x9d 0x0 str_0x962cce str_0x962d24
loadpointer 0x0 str_0x962d24
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x962cce:
    .string "Ich bin eine Lady von hoher\nGeburt. Es geziemt sich, dass du\ldich kampflos ergibst."



str_0x962d24:
    .string "Dir fehlt die Gallanz!\nRüpelhaftes BenehmenDOTS"


.elseif LANG_EN

.endif


ow_script_map_1_30_trainer_4:
trainerbattlestd 0x0 0x9e 0x0 str_0x962eb8 str_0x962f39
loadpointer 0x0 str_0x962f39
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x962eb8:
    .string "Viele kommen hierher in der\nHoffnung, das Pokémon Lavados zu\ltreffen.\lIch erleichtere sie stattdessen um\lihre eigenen Pokémon!"



str_0x962f39:
    .string "In Ordnung, du kannst deine\nPokémon behalten!"


.elseif LANG_EN

.endif
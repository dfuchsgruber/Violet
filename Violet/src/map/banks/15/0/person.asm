.include "vars.s"
.include "movements.s"
.include "map_adjacency_types.s"
.include "callstds.s"
.include "ordinals.s"
.include "map_connections.s"
.include "overworld_script.s"
.include "flags.s"
.include "species.s"
.include "items.s"

.global ow_script_map_15_0_trainer_1
.global ow_script_map_15_0_trainer_7
.global ow_script_0x8296fe
.global ow_script_map_15_0_trainer_2
.global ow_script_map_15_0_trainer_16
.global ow_script_map_15_0_trainer_15
.global ow_script_map_15_0_trainer_19
.global ow_script_map_15_0_trainer_10
.global ow_script_map_15_0_trainer_4
.global ow_script_map_15_0_trainer_13
.global ow_script_0x87aed2
.global ow_script_map_15_0_trainer_12
.global ow_script_map_15_0_trainer_17
.global ow_script_map_15_0_trainer_5
.global ow_script_map_15_0_trainer_3
.global ow_script_map_15_0_trainer_9
.global ow_script_map_15_0_trainer_6
.global ow_script_map_15_0_trainer_18
.global ow_script_map_15_0_trainer_14
.global ow_script_map_15_0_trainer_0
.global ow_script_0x81a42f
.global ow_script_map_15_0_trainer_20
.global ow_script_0x8d48a0
.global ow_script_map_15_0_trainer_11
.global ow_script_map_15_0_person_0
.global ow_script_0x8f3bfd
.global ow_script_map_15_0_person_1
.global ow_script_0x8efcd3
.global ow_script_0x829b7e
.global ow_script_map_15_0_trainer_8
.global str_say_starlili

ow_script_map_15_0_person_0:
cry POKEMON_STARALILI 0x0
loadpointer 0x0 str_say_starlili
showpokepic POKEMON_STARALILI 0x0 0x0
callstd MSG_FACE
hidepokepic
end


.ifdef LANG_GER

str_say_starlili:
    .string "Staralili!"


.elseif LANG_EN

.endif


ow_script_map_15_0_trainer_13:
loadpointer 0x0 str_0x81a262
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x81a262:
    .string "Von Kranzdorf kommt man in den\nZeitwald. Wieso er Zeitwald heißt?\lKeine Ahnung."


.elseif LANG_EN

.endif


ow_script_map_15_0_trainer_4:
trainerbattlestd 0x0 0x18 0x0 str_0x818b9b str_0x818bd9
loadpointer 0x0 str_0x818bd9
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x818b9b:
    .string "Vögel sind zwar schwer zu fangen,\naber die Mühe lohnt sich!"



str_0x818bd9:
    .string "Vögel zu fangen, würde sich auch\nfür dich lohnen."


.elseif LANG_EN

.endif


ow_script_map_15_0_trainer_2:
trainerbattlestd 0x0 0x1e 0x0 str_0x818f6a str_0x818f33
loadpointer 0x0 str_0x818f33
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x818f6a:
    .string "Ein Experte zu sein, bringt viele\nVorteile mit sich."



str_0x818f33:
    .string "Ein Experte zu sein, bringt auch\nNachteile mit sich."


.elseif LANG_EN

.endif


ow_script_map_15_0_trainer_11:
loadpointer 0x0 str_0x8471be
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8471be:
    .string "Rosalie aus Kranzdorf kommt oft hierher\nund überwacht die Vegetation. Ohne\lsie würde die Umwelt hier\lzusammenbrechen."


.elseif LANG_EN

.endif


ow_script_map_15_0_trainer_7:
trainerbattlestd 0x0 0x36 0x0 str_0x819dfa str_0x819e42
loadpointer 0x0 str_0x819e42
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x819dfa:
    .string "Pflanzen können so viel gutes tun.\nMan kann sie sogar rauchenDOTS Ahh!"



str_0x819e42:
    .string "Nicht, als ob ich diese bestimmten\nPflanzen rauchen würde."


.elseif LANG_EN

.endif


ow_script_map_15_0_trainer_8:
trainerbattlestd 0x0 0x1d 0x0 str_0x81a2c9 str_0x81a2ee
loadpointer 0x0 str_0x81a2ee
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x81a2c9:
    .string "Angeln ist nicht das SpannendsteDOTS"



str_0x81a2ee:
    .string "Aber ich habe zu nichts anderem\nTalent."


.elseif LANG_EN

.endif


ow_script_map_15_0_trainer_10:
trainerbattlestd 0x0 0x21 0x0 str_0x81a32e str_0x81a36d
loadpointer 0x0 str_0x81a36d
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x81a32e:
    .string "Ein Angler braucht Geduld, und\nmeist ist der Fang nicht gut."



str_0x81a36d:
    .string "Mein Fang war wohl eher schlecht."


.elseif LANG_EN

.endif


ow_script_0x81a42f:
trainerbattlestd 0x0 0x1c 0x0 str_0x81a447 str_0x81a495
loadpointer 0x0 str_0x81a495
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x81a447:
    .string "Angeln ist nicht leicht. Ich habe\nbeispielsweise einen guten Fang\lgemacht."



str_0x81a495:
    .string "SternduDOTS"


.elseif LANG_EN

.endif


ow_script_map_15_0_person_1:
compare STORY_PROGRESS 0x12
callif HIGHER ow_script_0x8296fe
loadpointer 0x0 str_0x8bf87b
callstd MSG_FACE
singlemovement 0x6 0x2
end


ow_script_0x8296fe:
loadpointer 0x0 str_0x8bf80e
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8bf87b:
    .string "Ich hätte das Zauntor nicht offen\nlassen sollen! Jetzt sind alle\ldiese Voltilamm entlaufen!"



str_0x8bf80e:
    .string "Ich bin froh, dass ich - nach dem\nMalheur mit dem offenen Zauntor -\lnoch immer auf der Farm arbeiten\ldarf."


.elseif LANG_EN

.endif


ow_script_map_15_0_trainer_17:
compare STORY_PROGRESS 0x12
gotoif HIGHER ow_script_0x829b7e
loadpointer 0x0 str_0x8bf98a
callstd MSG_FACE
singlemovement 0x2f 0x2
end


ow_script_0x829b7e:
loadpointer 0x0 str_0x8bf8d8
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8bf98a:
    .string "Es wird wohl sicher noch eine\nWeile dauern, bis wir diese ganzen\lVoltilamm wieder eingezäunt haben."



str_0x8bf8d8:
    .string "Wir züchten alle Arten von\nPokémon. Allen voran Vögel und\lVoltilamm. Wenn wie sie scheren,\lkönnen wir die Wolle teuer\lverkaufen. Und Elektrizität\lstellen sie auch noch bereit."


.elseif LANG_EN

.endif


ow_script_map_15_0_trainer_14:
loadpointer 0x0 str_0x8bf9ef
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8bf9ef:
    .string "Die Arbeit auf der Farm ist\nKnochenarbeit. Aber sie befreit\lden Geist und bringt einen in\lEinklang mit der Natur. Vor allem\lzu den Voltilamm habe ich eine\lenge Beziehung aufgebaut."


.elseif LANG_EN

.endif


ow_script_map_15_0_trainer_18:
loadpointer 0x0 str_0x8bfaa5
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8bfaa5:
    .string "Die Zucht ist eine Wissenschaft.\nWusstest du, dass Pokémon ganz\lpersönliche Gene haben, die über\lihre Fähigkeiten im Kampf\lbestimmen? Diese Gene können dann\lvon den Eltern an ihre Kinder\lvererbt werden. Sogar Angriffe\lsind genetisch bedingt.\pSpannend, nicht?"


.elseif LANG_EN

.endif


ow_script_movs_0x87c241:
.byte SAY_EXCLAM
.byte STOP


ow_script_map_15_0_trainer_15:
pause 0x10
loadpointer 0x0 str_0x87c237
callstd MSG
faceplayer
sound 0x15
applymovement 0x800f ow_script_movs_0x87c241
waitmovement 0x0
trainerbattlecont 0x1 0x28 0x0 str_0x87c116 str_0x87c1a4 ow_script_0x87aed2


ow_script_0x87aed2:
loadpointer 0x0 str_0x87c1da
callstd MSG
fadescreen 0x1
hidesprite 0x800f
fadescreen 0x0
end


.ifdef LANG_GER

str_0x87c237:
    .string "DOTS DOTS"



str_0x87c116:
    .autostring 34 2 "Huh?\pWas willst du, Rotzgöre?\pJa ganz recht!\nIch habe mir von diesem Imker auf Route 3 ein paar Bibor gestohlen.\pUnd weißt du was?\pJetzt werde ich dich mit ihnen besiegen!"

str_0x87c1a4:
    .string "Uff!\nSo war das nicht geplantDOTS"



str_0x87c1da:
    .autostring 34 2 "Schon gut, schon gut!\pDu kannst diese Bibor wiederhabenDOTS\pWie du siehst, taugen sie sowieso nicht zum KämpfenDOTS"
.elseif LANG_EN

.endif


ow_script_map_15_0_trainer_16:
showpokepic POKEMON_VOLTILAMM 0x8 0x3
loadpointer 0x0 str_0x895f45
callstd MSG_FACE
hidepokepic
end


.ifdef LANG_GER

str_0x895f45:
    .string "Voltilamm! Voltilamm!"


.elseif LANG_EN

.endif


ow_script_map_15_0_trainer_0:
trainerbattlestd 0x0 0x1a 0x0 str_0x89837f str_0x89989f
loadpointer 0x0 str_0x89989f
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x89837f:
    .string "Mach dich auf was gefasst! Meine\nPokémon sind süß und gefährlich!"



str_0x89989f:
    .string "Vielleicht sind meine Pokémon auch\ndoch nur süßDOTS"


.elseif LANG_EN

.endif


ow_script_map_15_0_trainer_5:
trainerbattlestd 0x0 0x1b 0x0 str_0x8998d3 str_0x899949
loadpointer 0x0 str_0x899949
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8998d3:
    .string "Wahre Schönheit kommt von Innen.\nEine Naturdame wie ich verzichtet\ldeshalb ganz auf\lumweltverschmutzende Kosmetika!"



str_0x899949:
    .string "Mein Gesicht ist von Natur aus\nschön!"


.elseif LANG_EN

.endif


ow_script_map_15_0_trainer_6:
trainerbattlestd 0x0 0x22 0x0 str_0x8999f3 str_0x899a36
loadpointer 0x0 str_0x899a36
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8999f3:
    .string "Du Einfaltspinsel! Lass mich dir\netwas von meinem Karate zeigen!"



str_0x899a36:
    .string "Ka! Ra! Te! Buhu!"


.elseif LANG_EN

.endif


ow_script_map_15_0_trainer_1:
trainerbattlestd 0x0 0x24 0x0 str_0x899a49 str_0x899ac7
loadpointer 0x0 str_0x899ac7
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x899a49:
    .string "Joggen ist gut für Herz und\nKreislauf! Die Waldluft, die vom\lZeitwald hierher gelangt, befreit\ldie Atemwege meiner Pokémon!"



str_0x899ac7:
    .string "Dann muss ich mein Training wohl\netwas verschärfen!"


.elseif LANG_EN

.endif


ow_script_mart0x8fb16a:
.hword ITEM_TM01
.hword ITEM_TM33
.hword ITEM_TM50
.hword ITEM_VM01
.hword ITEM_NONE


ow_script_map_15_0_trainer_19:
pokemart ow_script_mart0x8fb16a
loadpointer 0x0 str_0x416651
end


.ifdef LANG_GER

str_0x416651:
    .string "Du hast nicht genug Geld.PAUSE_UNTIL_PRESS"


.elseif LANG_EN

.endif


ow_script_map_15_0_trainer_3:
loadpointer 0x0 str_0x8d41a0
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8d41a0:
    .string "Die Region Theto wird von vier\nvoneinander unabhängigen Trainern\lregiert, den Top Vier. Über ihnen\lsteht bloß der Champion."


.elseif LANG_EN

.endif


ow_script_map_15_0_trainer_12:
trainerbattlestd 0x0 0x23 0x0 str_0x8d40f1 str_0x8d4147
loadpointer 0x0 str_0x8d4147
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8d40f1:
    .string "Ich habe bereits zwei Arena-Orden\nerrungen. Was kannst du mir also\lentgegensetzten?"



str_0x8d4147:
    .string "Huch! Du bist recht stark, Junge.\nEinen Trainer wie mich zu\lbesiegen, erfordert Talent."


.elseif LANG_EN

.endif

ow_script_0x8d48a0:
setvar 0x8000 POKEMON_PIKACHU
call ow_script_find_egg
end


ow_script_map_15_0_trainer_9:
trainerbattlestd 0x0 0x20 0x0 str_0x8d491f str_0x8d494b
loadpointer 0x0 str_0x8d494b
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8d491f:
    .string "Oh, ich find dicke Fische einfach\nklasse."



str_0x8d494b:
    .string "Dicke Fische bedeuten aber nicht\nimmer starke Fische."


.elseif LANG_EN

.endif



ow_script_map_15_0_trainer_20:
lock
faceplayer
checkflag POKERADAR
gotoif EQUAL ow_script_0x8efcd3
loadpointer 0x0 str_0x8f3c00
callstd MSG
setvar 0x8004 0x1
special2 0x800d 0xd4
buffernumber 0x2 0x8006
compare 0x8006 0xa
gotoif LESS ow_script_0x8f3bfd
sound 0x15
applymovement 0x800f mov_exclam
waitmovement 0x0
loadpointer 0x0 str_0x8f3cd9
callstd MSG
fanfare 0x13e
lock
faceplayer
loadpointer 0x0 str_0x8f3bc4
callstd MSG_KEEPOPEN
lock
faceplayer
waitfanfare
lock
faceplayer
loadpointer 0x0 str_0x8f3a57
callstd MSG
setflag POKERADAR
release
end


ow_script_0x8f3bfd:
release
end


ow_script_0x8efcd3:
loadpointer 0x0 str_0x8f39d8
callstd MSG_FACE
end

mov_exclam:
    .byte SAY_EXCLAM, STOP


.ifdef LANG_GER

str_0x8f3c00:
    .string "Hallo, ich bin ein Assistent\nProfessor Tanns. Ich helfe\lTrainern, die den Pokedex haben,\lbei der Vervollständigung der\lDaten.\lWenn du 10 verschiedene Pokémon im\lPokedex registriert hast, erhältst\ldu eine Belohnung."



str_0x8f3cd9:
    .string "Sehr gut, du hast bereits\nBUFFER_3 verschiedene Pokémon\lregistriert. Als Belohnung werde\lich die Pokeradar-App auf deinem\lPokepad installieren."



str_0x8f3bc4:
    .string "Deinem Pokepad wurde die\nPokeradar-App hinzugefügt!"



str_0x8f3a57:
    .string "Das Pokeradar kann in der Nähe von\nhohem Graß benutzt werden, um\lseltene Pokémon aufzuspüren.\lSie sind sehr scheu, also gerate\lnicht in ihr Blickfeld, wenn du\lsie fangen möchtest.\lJe öfter du das Pokeradar\leinsetzt, desto höher ist die\lWahrscheinlichkeit, seltene\lPokémon anzutreffen.\lDiese Funktion sollte dir bei der\lvervollständigung des Pokedex\lenorm helfen."



str_0x8f39d8:
    .string "Das Pokeradar findet seltene\nPokémon in deiner Umgebung. Da sie\lsehr scheu sind, solltest du nicht\lin ihr Blickfeld geraten."


.elseif LANG_EN

.endif
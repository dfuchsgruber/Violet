.include "ordinals.s"
.include "vars.s"
.include "movements.s"
.include "callstds.s"
.include "mugshot.s"
.include "flags.s"
.include "overworld_script.s"
.include "species.s"
.include "items.s"
.include "specials.s"

.global ow_script_0x8fe431
.global ow_script_map_0_6_trainer_11
.global ow_script_map_0_6_trainer_1
.global ow_script_0x8fe744
.global ow_script_0x927370
.global ow_script_0x92738e
.global ow_script_map_0_6_trainer_6
.global ow_script_map_0_6_trainer_2
.global ow_script_map_0_6_trainer_5
.global ow_script_map_0_6_trainer_4
.global ow_script_map_0_6_trainer_0
.global ow_script_0x8fe4cc
.global ow_script_map_0_6_trainer_8
.global ow_script_map_0_6_trainer_10
.global ow_script_map_0_6_trainer_3
.global ow_script_0x9270fb
.global ow_script_0x8fb3c3
.global ow_script_0x8fe513
.global ow_script_0x8fe785
.global ow_script_0x8fe4bb
.global ow_script_map_0_6_trainer_9
.global ow_script_0x8fee78
.global ow_script_map_0_6_trainer_7
.global ow_script_0x8fe518
.global ow_script_0x8fb752
.global ow_script_0x8fe2d1
.global ow_script_0x8fe425

ow_script_map_0_6_trainer_9:
trainerbattlestd 0x0 0x59 0x0 str_0x71acf5 str_0x71ad42
loadpointer 0x0 str_0x71ad42
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x71acf5:
    .string "Wo ist denn bloß dieser Ausgang!\nOhne Blitz komme ich nicht voran!"



str_0x71ad42:
    .string "Ich brauche BlitzDOTS"


.elseif LANG_EN

.endif


ow_script_map_0_6_trainer_7:
trainerbattlestd 0x0 0x57 0x0 str_0x71ad57 str_0x71b389
loadpointer 0x0 str_0x71b389
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x71ad57:
    .string "Ich habe viele Jahre gekämpft, und\nmein Pokémon ist äußert selten!"



str_0x71b389:
    .string "Seltenheit bedeutet wohl nicht\nStärkeDOTS"


.elseif LANG_EN

.endif


ow_script_map_0_6_trainer_0:
trainerbattlestd 0x0 0x52 0x0 str_0x7287d7 str_0x72880b
loadpointer 0x0 str_0x72880b
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x7287d7:
    .string "Ich frage mich, wie viele Ebenen\ndiese Höhle hat!"



str_0x72880b:
    .string "Ich hoffe, es sind nicht mehr als\nzwei Ebenen!"


.elseif LANG_EN

.endif


ow_script_map_0_6_trainer_1:
trainerbattlestd 0x0 0x53 0x0 str_0x72883a str_0x72888e
loadpointer 0x0 str_0x72888e
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x72883a:
    .string "Mein Ziel ist es nach Kaskada zu\nkommen, doch dazu muss ich über den\lWüstenpfad."



str_0x72888e:
    .string "Ich frage mich, wie Kaskada wohl so\nist."


.elseif LANG_EN

.endif


ow_script_map_0_6_trainer_6:
trainerbattlestd 0x0 0x56 0x0 str_0x8fb7a5 str_0x8fb810
loadpointer 0x0 str_0x8fb810
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8fb7a5:
    .string "Ich bin hierher gekommen, um mir\neines der seltenen Fossil-Pokémon\lzu beschaffen."



str_0x8fb810:
    .string "Du wirst sie mir nicht wegnehmen,\ndie Fossil-Pokémon!"


.elseif LANG_EN

.endif


ow_script_map_0_6_trainer_2:
loadpointer 0x0 str_0x8fb359
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8fb359:
    .string "Da warme Luft aufsteigt, ist es\nhier in der unteren Ebene der\lHöhle angenehm kühl."


.elseif LANG_EN

.endif

ow_script_0x8fb3c3:
setvar 0x8000 POKEMON_RABAUZ
call ow_script_find_egg
end


ow_script_map_0_6_trainer_11:
loadpointer 0x0 str_0x8fef43
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8fef43:
    .string "Vorhin kam ein äußert mysteriöser\nMann hier entlang. Er erzählte von\lden Missständen in den Top Vier\lund wollte mich überzeugen, der\lRevolutionsarmee beizutreten."


.elseif LANG_EN

.endif


ow_script_map_0_6_trainer_3:
trainerbattlestd 0x0 0x54 0x0 str_0x8fe86e str_0x8feac9
loadpointer 0x0 str_0x8feac9
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8fe86e:
    .string "Da ich nach Kaskada will, muss ich\nmich durch die Wüste kämpfen!"



str_0x8feac9:
    .string "Ein beständiger, ausdauernder\nKampfstil ist der Schlüssel zum\lErfolg!"


.elseif LANG_EN

.endif


ow_script_map_0_6_trainer_5:
checkflag FELSIGE_ODNIS_TM_STEEL_WING
gotoif EQUAL ow_script_0x8fb752
lock
faceplayer
loadpointer 0x0 str_0x8fb630
callstd MSG_KEEPOPEN
copyvarifnotzero 0x8000 ITEM_TM47
copyvarifnotzero 0x8001 1
callstd ITEM_OBTAIN
loadpointer 0x0 str_0x8fb6cf
callstd MSG_KEEPOPEN
closeonkeypress
setflag FELSIGE_ODNIS_TM_STEEL_WING
release
end


ow_script_0x8fb752:
loadpointer 0x0 str_0x8fb75c
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8fb630:
    .string "Kennst du das? Du liebst es,\nFlug-Pokémon zu trainieren und\lwirst ständig von Gestein-Pokémon\lausgebremst?\pDann habe ich hier die perfekte\nAbhilfe für dich!"



str_0x8fb6cf:
    .string "Stahlflügel ist eine Attacke, die\nvon fliegenden Pokémon ausgeführt\lwerden kann und selbst\lGestein-Pokémon sehr effektiv\ltrifft."



str_0x8fb75c:
    .string "Mit Stahlflügel kannst selbst\nlästige Gestein-Pokémon effektiv\ltreffen."


.elseif LANG_EN

.endif


ow_script_map_0_6_trainer_4:
trainerbattlestd 0x0 0x55 0x0 str_0x8feb10 str_0x8feb72
loadpointer 0x0 str_0x8feb72
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8feb10:
    .string "Meine Pflanzen-Pokémon können sich\nmit der Trockenheit einer Wüste\lnicht wirklich anfreundenDOTS"



str_0x8feb72:
    .string "Vielleicht sollte ich einfach hier\nunten bleiben, wo es schön kühl\lund feucht ist."


.elseif LANG_EN

.endif


ow_script_movs_0x8fe753:
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STOP


ow_script_movs_0x8fe741:
.byte STEP_UP
.byte STOP


ow_script_movs_0x8fe73d:
.byte FACE_DOWN
.byte SAY_EXCLAM
.byte STOP


ow_script_map_0_6_trainer_8:
loadpointer 0x0 str_0x8fe75c
callstd MSG
clearflag PKMNMENU
setvar LASTTALKED 0xe
showsprite LASTTALKED
applymovement LASTTALKED ow_script_movs_0x8fe753
waitmovement 0x0
getplayerpos 0x8000 0x8001
compare 0x8000 0x21
callif EQUAL ow_script_0x8fe744
applymovement LASTTALKED ow_script_movs_0x8fe741
waitmovement 0x0
sound 0x15
applymovement 0xff ow_script_movs_0x8fe73d
waitmovement 0x0
checksound
setflag PKMNMENU

loadpointer 0 str_maniac
setvar 0x8000 1
special 0xE
trainerbattlecont 0x1 0x58 0x0 str_0x8fe6cd str_0x8fe674 ow_script_0x8fe2d1


ow_script_movs_0x8fe783:
.byte LOOK_UP
.byte STOP


ow_script_movs_0x8fe47c:
.byte LOOK_UP
.byte STOP


ow_script_0x8fe2d1:


loadpointer 0 str_maniac
setvar 0x8000 1
special 0xE
loadpointer 0x0 str_0x8fe5f1
callstd MSG
special 0xF
goto ow_script_0x8fe785

.align 4
choice2:
    .word str_fossil_choice_2, 0
    .word str_fossil_choice_3, 0


ow_script_0x8fee78:
compare 0x8005 0x20
callif EQUAL ow_script_0x8fe425
compare 0x8005 0x21
callif EQUAL ow_script_0x8fe431

loadpointer 0 str_maniac
setvar 0x8000 1
special 0xE
loadpointer 0x0 str_0x8fe3db
callstd MSG
special 0xF

fadescreen 0x1
hidesprite LASTTALKED
fadescreen 0x0
end


ow_script_movs_0x8fe440:
.byte LOOK_RIGHT
.byte STOP


ow_script_0x8fe431:
applymovement LASTTALKED ow_script_movs_0x8fe440
waitmovement 0x0
return


ow_script_movs_0x8fe43d:
.byte LOOK_LEFT
.byte STOP


ow_script_0x8fe425:
applymovement LASTTALKED ow_script_movs_0x8fe43d
waitmovement 0x0
return


ow_script_0x8fe513:
hidesprite 0xc
return


ow_script_0x8fe518:
hidesprite 0xd
return


ow_script_movs_0x8fe4d8:
.byte STEP_LEFT
.byte STEP_UP
.byte LOOK_RIGHT
.byte STOP


ow_script_0x8fe4cc:
applymovement LASTTALKED ow_script_movs_0x8fe4d8
waitmovement 0x0
return


ow_script_movs_0x8fe4c7:
.byte STEP_RIGHT
.byte STEP_UP
.byte LOOK_LEFT
.byte STOP


ow_script_0x8fe4bb:
applymovement LASTTALKED ow_script_movs_0x8fe4c7
waitmovement 0x0
return


ow_script_0x927370:
bufferitem 0x0 ITEM_WURZELFOSSIL
checkitemroom ITEM_WURZELFOSSIL 0x1
compare LASTRESULT 0x0
callif EQUAL ow_script_0x92738e
additem ITEM_WURZELFOSSIL 0x1
setvar 0x800A, ITEM_WURZELFOSSIL
clearflag CLAW_FOSSIL_TAKEN
return


ow_script_0x92738e:
loadpointer 0x0 str_0x927398
callstd MSG_SIGN
return


ow_script_0x9270fb:
bufferitem 0x0 ITEM_KLAUENFOSSIL
checkitemroom ITEM_KLAUENFOSSIL 0x1
compare LASTRESULT 0x0
callif EQUAL ow_script_0x92738e
additem ITEM_KLAUENFOSSIL 0x1
setvar 0x800A, ITEM_KLAUENFOSSIL
setflag CLAW_FOSSIL_TAKEN
return


ow_script_0x8fe785:
loadpointer 0x0 str_0x8fee9e
show_mugshot MUGSHOT_PLAYER MUGSHOT_LEFT


loadpointer 0 str_maniac
setvar 0x8000 1
special 0xE
loadpointer 0x0 str_0x8fea2c
callstd MSG
special 0xF

applymovement 0xff ow_script_movs_0x8fe783
waitmovement 0x0

loadpointer 0x0 str_0x8fe51d
callstd MSG_KEEPOPEN

setvar DYN_MULTICHOICE_ITEM_CNT 0x2
loadpointer 0x0 choice2
multichoice 0x0 0x0 0x0 0x1
setvar DYN_MULTICHOICE_ITEM_CNT 0x0
copyvar 0x8006 LASTRESULT
compare 0x8006 0x0
callif EQUAL ow_script_0x9270fb
compare 0x8006 0x1
callif EQUAL ow_script_0x927370
getplayerpos 0x8005 0x8004
compare 0x8005 0x20
callif EQUAL ow_script_0x8fe513
compare 0x8005 0x21
callif EQUAL ow_script_0x8fe518
fanfare 0x13e
copyvar 0x8009, 0x8004
copyvar 0x8004, 0x800A
special SPECIAL_ITEM_OBTAIN_SHOW_DESCRIPTION
copyvar 0x8004, 0x8009
loadpointer 0x0 str_0x8fe4dd
callstd MSG_KEEPOPEN
waitfanfare
closeonkeypress
special SPECIAL_ITEM_OBTAIN_DELETE_DESCRIPTION
compare 0x8005 0x20
callif EQUAL ow_script_0x8fe4bb
compare 0x8005 0x21
callif EQUAL ow_script_0x8fe4cc
sound 0x17
checksound
pause 32
compare 0x8005 0x20
callif EQUAL ow_script_0x8fe518
compare 0x8005 0x21
callif EQUAL ow_script_0x8fe513


loadpointer 0 str_maniac
setvar 0x8000 1
special 0xE
loadpointer 0x0 str_0x8fe443
callstd MSG
special 0xF

compare 0x8005 0x20
callif EQUAL ow_script_0x8fe425
compare 0x8005 0x21
callif EQUAL ow_script_0x8fe431


loadpointer 0 str_maniac
setvar 0x8000 1
special 0xE
loadpointer 0x0 str_0x8fe8d0
callstd MSG
special 0xF
fadescreen 0x1
hidesprite LASTTALKED
fadescreen 0x0
end


ow_script_movs_0x8fe750:
.byte STEP_RIGHT
.byte STOP


ow_script_0x8fe744:
applymovement LASTTALKED ow_script_movs_0x8fe750
waitmovement 0x0
return


.ifdef LANG_GER

str_maniac:
	.string "Ruinenmaniac"


str_0x8fe75c:
    .autostring 35 2 "Der Stein sieht aus wie ein FossilDOTS"



str_0x8fe6cd:
    .autostring 35 2 "Du da! Halt!\nDiese Fossilien habe ich bereits seit Jahren gesucht!\pSie stehen mir zu, nicht dir!"



str_0x8fe674:
    .autostring 35 2 "Das DOTS das ist nicht möglich!\pMein Leben lang habe ich nach diesen Fossilien gesucht."



str_0x8fe5f1:
    .autostring 35 2  "Mein ganzes Leben habe ich der Suche nach Fossilien gewidmet und jetzt, da ich sie gefunden habe, kommt ein anderer mir zuvorDOTS"




str_0x8fe57c:
    .autostring 35 2 "Diese Fossilien gehören mir, du hast kein Anrecht darauf!"



str_0x8fe51d:
    .autostring 35 2 "Welches der Fossilien möchtest du\nzuerst aufnehmen?"




str_fossil_choice_2:
    .string "Klauenfossil"



str_fossil_choice_3:
    .string "Wurzelfossil"



str_0x8fe4dd:
    .autostring 35 2 "PLAYER hat das BUFFER_1\nerhalten!"



str_0x8fe47f:
    .autostring 35 2 "Von dir lasse mich mir die Fossilien nicht wegnehmen!"



str_0x8fe443:
    .autostring 35 2 "Der Ruinenmaniac hat das verbleidende Fossil genommen!"



str_0x8fe3db:
    .autostring 35 2 "Du freches Kind!\pDass du die Frechheit besitzt, auch nur eines der Fossilien zu beanspruchen DOTS"



str_0x927398:
    .autostring 35 2 "Das BUFFER_1 zerbröselte, da kein Platz im Beutel ist."



str_0x8fee9e:
    .autostring 35 2 "Ich war vor dir hier, also habe ich auch ein Recht auf die Fossilien.\pAllerdings befinden sich dort ohnehin zwei Stück.\pWie wäre es, wenn jeder ein Fossil erhält?"



str_0x8fea2c:
	.autostring 35 2 "Ah, ich sehe, du lässt mit dir reden.\pAlso gut, dann nimmt jeder ein Fossil.\pIch lasse dir gerne den Vortritt, Kindchen!"


str_0x8fe8d0:
	.autostring 35 2 "Endlich habe ich ein Fossil gefunden!\pDie Laz.Corp in Orina City arbeitet an einem Projekt, bei dem es darum geht, Pokémon aus Fossilien zu restaurieren.\pDu solltest der Firma einen Besuch abstatten!"

.elseif LANG_EN

.endif


ow_script_map_0_6_trainer_10:
trainerbattlestd 0x0 0x5a 0x0 str_0x8fec28 str_0x8fec89
loadpointer 0x0 str_0x8fec89
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8fec28:
    .string "Wieso sollte man seine Pokémon\ntrainieren, wenn man sie einfach\landeren Trainern stehlen kann?"



str_0x8fec89:
    .string "Hätte ich meine Pokémon selbst\ntrainiert, wäre ich vielleicht in\lder Lage gewesen, dich zu\lbesiegen!"


.elseif LANG_EN

.endif
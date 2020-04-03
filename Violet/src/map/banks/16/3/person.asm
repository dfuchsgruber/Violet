.include "vars.s"
.include "specials.s"
.include "callstds.s"
.include "ordinals.s"
.include "overworld_script.s"
.include "flags.s"
.include "movements.s"

.global ow_script_map_16_3_trainer_7
.global ow_script_map_16_3_trainer_8
.global ow_script_0x937c8a
.global ow_script_map_16_3_trainer_1
.global ow_script_map_16_3_trainer_2
.global ow_script_map_16_3_trainer_0
.global ow_script_map_16_3_trainer_3
.global ow_script_map_16_3_trainer_6
.global ow_script_map_16_3_trainer_11
.global ow_script_map_16_3_trainer_12
.global ow_script_map_16_3_trainer_4
.global ow_script_map_16_3_trainer_10
.global ow_script_map_16_3_trainer_5
.global ow_script_0x93814a
.global ow_script_map_16_3_trainer_9
.global ow_script_map_16_3_person_0

ow_script_map_16_3_person_0:
loadpointer 0x0 str_0x936da7
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x936da7:
    .string "Bis vor kurzem war der\nWassertunnel eingestürzt.\pArenaleiter Manus aus Meriana City\nhat ihn wieder errichtet."


.elseif LANG_EN

.endif


ow_script_map_16_3_trainer_1:
loadpointer 0x0 str_0x93767f
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x93767f:
    .string "Im Laufe der Jahrtausende hat das\nWasser diesen Tunnel ausgespült.\lSo viele SackgassenDOTS"


.elseif LANG_EN

.endif


ow_script_map_16_3_trainer_2:
loadpointer 0x0 str_0x936eb2
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x936eb2:
    .string "Mein Freund mag die feuchte Luft\nin diesem Tunnel."


.elseif LANG_EN

.endif


ow_script_map_16_3_trainer_5:
loadpointer 0x0 str_0x9377fe
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x9377fe:
    .string "Ein Glück ist dieser Tunnel nicht\ndunkel.\pKeines meiner Pokémon kennnt die\nAttacke Blitz!"


.elseif LANG_EN

.endif


ow_script_map_16_3_trainer_8:
loadpointer 0x0 str_0x93ba54
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x93ba54:
    .string "Die Wanderung entlang des\nWasserpfades ist sehr beliebt\lunter Wanderern.\pAllein die Vorstellung unter einem\ngewaltigen Fluss zu marschierenDOTS\pUnfassbar, nicht?"


.elseif LANG_EN

.endif


ow_script_map_16_3_trainer_0:
trainerbattlestd 0x0 0x79 0x0 str_0x936e16 str_0x936e78
loadpointer 0x0 str_0x936e78
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x936e16:
    .string "Die Arena von Meriana City ist\neine Pilgerstätte für Kämpfer.\lIch bin auf direktem Weg dorthin!"



str_0x936e78:
    .string "Was? Wie konnte ich gegen einen\nNicht-Kämpfer verlieren?"


.elseif LANG_EN

.endif


ow_script_map_16_3_trainer_12:
loadpointer 0x0 str_0x93bcb5
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x93bcb5:
    .string "Manus wird von vielen für einen\ngroßen Mann gehaltenDOTS\lIch vertrete eine andere\lAuffassung, aber derartiges sollte\lman nicht zu laut sagen."


.elseif LANG_EN

.endif


ow_script_map_16_3_trainer_3:
trainerbattlestd 0x0 0x7a 0x0 str_0x9376da str_0x93771d
loadpointer 0x0 str_0x93771d
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x9376da:
    .string "Hieb und Schlag!\nWie ich\'s mag!\lTritt und Kick!\lHalten mich fit!"



str_0x93771d:
    .string "Wie, was schon aus?\nHast einiges drauf!\lIch lern dazu!\lKarate! Kung Fu!"


.elseif LANG_EN

.endif


ow_script_map_16_3_trainer_4:
trainerbattlestd 0x0 0x7b 0x0 str_0x937767 str_0x9377c1
loadpointer 0x0 str_0x9377c1
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x937767:
    .string "Der Fang in einer Höhle könnte\ndurchaus besser seinDOTS\lOb ich am Fluss mehr Glück habe?"



str_0x9377c1:
    .string "Ich sollte mein Glück am Fluss\nnach Meriana City probieren."


.elseif LANG_EN

.endif


ow_script_map_16_3_trainer_7:
trainerbattlestd 0x0 0x7c 0x0 str_0x9382bb str_0x938319
loadpointer 0x0 str_0x938319
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x9382bb:
    .string "Ich bin ein Schüler von Manus,\ndem größten Kämpfer der Welt!\lDu kannst mich nicht besiegen!"



str_0x938319:
    .string "Was? Aber ich habe doch unter\nManus trainiert!"


.elseif LANG_EN

.endif


ow_script_map_16_3_trainer_9:
trainerbattlestd 0x0 0x7d 0x0 str_0x93baf6 str_0x93bb5e
loadpointer 0x0 str_0x93bb5e
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x93baf6:
    .string "Hey! Diese Waren hat die\nRevolution in Kaskada erworben.\lIch werde sie dir nicht kampflos\lüberlassen!"



str_0x93bb5e:
    .string "Diese Waren sind sehr wertvoll für\nuns, bitte respektiere das!"


.elseif LANG_EN

.endif

ow_script_map_16_3_trainer_6:
lock
faceplayer
checkflag POKEDEX_FEATURE_HABITAT
gotoif EQUAL ow_script_0x937c8a
loadpointer 0x0 str_0x937bb1
callstd MSG_KEEPOPEN
setvar 0x8004 0x1
special2 0x800d SPECIAL_POKEDEX_GET_STATS
buffernumber 0x2 0x8006
compare 0x8006 25
gotoif LESS ow_script_0x8f3bfd
sound 0x15
applymovement 0x800f mov_say_exclam
waitmovement 0x0
loadpointer 0x0 str_0x937ae9
callstd MSG_KEEPOPEN
fanfare 0x13e
lock
faceplayer
loadpointer 0x0 str_0x937b72
callstd MSG_KEEPOPEN
lock
faceplayer
waitfanfare
lock
faceplayer
setflag POKEDEX_FEATURE_HABITAT
goto ow_script_0x937c8a


ow_script_0x937c8a:
lock
faceplayer
loadpointer 0x0 str_0x9381b7
callstd MSG_YES_NO
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x93814a
loadpointer 0x0 str_0x937ed4
callstd MSG_FACE
end


ow_script_0x93814a:
loadpointer 0x0 str_0x938154
callstd MSG_FACE
end

mov_say_exclam:
    .byte SAY_EXCLAM, STOP

.ifdef LANG_GER

str_0x937bb1:
    .string "Hallo, ich bin ein Assistent\nProfessor Tanns. Ich helfe\lTrainern, die den Pokedex haben,\lbei der Vervollständigung der\lDaten.\lWenn du 25 verschiedene Pokémon im\lPokedex registriert hast, erhältst\ldu eine Belohnung."



str_0x937ae9:
    .string "Sehr gut, du hast bereits\nBUFFER_3 verschiedene Pokémon\lregistriert.\pAls Belohnung werde ich deinem\nPokédex die Habitat-Funktion\lhinzufügen."



str_0x937b72:
    .string "Der Pokédex von PLAYER wurde\num die Habitats-Funktion\lerweitert!"



str_0x9381b7:
    .string "Soll ich dir erklären, wie man die\nHabitats-Funktion benutzt?"



str_0x937ed4:
    .string "Wenn du dir den Pokédex-Eintrag zu\neiner bestimmten Spezies ansiehst,\lkannst mithilfe von KEY_A\ldie Habitate der Spezies\lbetrachten.\lDiese leuchten rot auf. Wenn du\lmit dem Cursor auf eines der\lGebiete gehst, wird dir angezeigt,\lwie häufig die Spezies dort\lanzutreffen ist.\pJe größer der Kreis, desto höher\ndie Wahrscheinlichkeit dem Pokémon\lzu begegnen.\lPokémon in Höhlen werden ebenfalls\ldem Gras-Reiter zugeordnet.\pDer Angel-Reiter zeigt an, ob das\nPokémon mit der Angel, Profiangel\loder Superangel zu finden ist.\pDurch die Habitat-Funktion findest\ndu sicherlich jedes Pokémon!\pDu wirst Professor Tann eine große\nHilfe sein!"



str_0x938154:
    .string "Komm jederzeit wieder, wenn du\nHilfe brauchst, die\lHabitats-Funktion deines Pokédex\lzu benutzen."


.elseif LANG_EN

.endif


ow_script_map_16_3_trainer_10:
trainerbattlestd 0x0 0x7e 0x0 str_0x93bb9e str_0x93bbf6
loadpointer 0x0 str_0x93bbf6
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x93bb9e:
    .string "Merk dir meinen Namen, Bursche!\nEines Tages werde ich die ganze\lWelt umwandert haben!"



str_0x93bbf6:
    .string "Merke dir diesen Triumph über\nmich, den Weltumwanderer!"


.elseif LANG_EN

.endif


ow_script_map_16_3_trainer_11:
trainerbattlestd 0x0 0x7f 0x0 str_0x93bc2f str_0x93bc87
loadpointer 0x0 str_0x93bc87
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x93bc2f:
    .string "Alle meine Klassenkameradinen\nhaben bereits einen Freund!\lWie wäre es mit uns beiden?"



str_0x93bc87:
    .string "Soll das heißen, du erteilst mir\neinen Korb?"


.elseif LANG_EN

.endif
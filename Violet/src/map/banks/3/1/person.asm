.include "ordinals.s"
.include "vars.s"
.include "attacks.s"
.include "move_tutor.s"
.include "movements.s"
.include "map_adjacency_types.s"
.include "specials.s"
.include "callstds.s"
.include "songs.s"
.include "mugshot.s"
.include "flags.s"
.include "map_connections.s"
.include "overworld_script.s"
.include "species.s"
.include "items.s"

.global ow_script_0x1c1afb
.global ow_script_map_3_1_person_9
.global ow_script_0x1c19c6
.global ow_script_map_3_1_person_5
.global ow_script_0x8a1a57
.global ow_script_0x1c19d7
.global ow_script_map_3_1_person_4
.global ow_script_map_3_22_trainer_8
.global ow_script_map_3_1_person_7
.global ow_script_map_3_1_person_6
.global ow_script_map_3_1_person_1
.global ow_script_map_3_1_person_17
.global ow_script_map_3_1_person_8
.global ow_script_map_3_1_person_12
.global ow_script_map_3_1_person_3
.global ow_script_map_3_1_person_15
.global ow_script_0x949573
.global ow_script_map_1_81_trainer_4
.global ow_script_map_3_1_person_0
.global ow_script_0x8f5cd8
.global ow_script_0x1c1b04
.global ow_script_0x1c1af7
.global ow_script_0x1aa912
.global ow_script_0x8a28fd
.global ow_script_0x9455d9
.global ow_script_map_3_1_person_2
.global ow_script_0x1c19e1
.global ow_script_0x8faec2
.global ow_script_0x1c1ad9
.global ow_script_map_3_1_person_14
.global ow_script_map_3_1_person_16
.global ow_script_0x87f3c1
.global ow_script_0x9455e4
.global ow_script_map_3_1_person_13
.global ow_script_map_3_1_person_11
.global ow_script_map_3_1_person_10
.global ow_script_0x93d5e1
.global move_tutor_item_check
.global ow_script_move_tutor_do
.global ow_script_move_tutor_pay_items
.global str_move_tutor_pay_items


ow_script_map_3_1_person_0:
special 0x187
compare LASTRESULT 0x2
gotoif EQUAL ow_script_0x1aa912
lockall
checkflag FRBADGE_2
gotoif LESS ow_script_0x1c19d7
checkattack ATTACK_ZERSCHNEIDER
compare LASTRESULT 0x6
gotoif EQUAL ow_script_0x1c19d7
setanimation 0x0 0x800d
bufferpartypokemon 0x0 0x800d
bufferattack 0x1 ATTACK_ZERSCHNEIDER
loadpointer 0x0 str_0x1c19e4
callstd MSG_YES_NO
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x1c19e1
loadpointer 0x0 str_0x1c1a37
callstd MSG_KEEPOPEN
closeonkeypress
doanimation 0x2
nop
waitstate
goto ow_script_0x1c19c6


ow_script_movs_0x1c19d5:
.byte 0x69
.byte STOP


ow_script_0x1c19c6:
applymovement 0x800f ow_script_movs_0x1c19d5
waitmovement 0x0
hidesprite 0x800f
releaseall
end


ow_script_0x1c19e1:
closeonkeypress
releaseall
end


ow_script_0x1c19d7:
loadpointer 0x0 str_0x1c1a48
callstd MSG_SIGN
releaseall
end


.ifdef LANG_GER

str_0x1c19e4:
    .string "Du kannst den Zerschneider hier\neinsetzen!\pMöchtest du den Zerschneider\neinsetzen?"



str_0x1c1a48:
    .string "Der Zerschneider kann hier\neingesetzt werden."


.elseif LANG_EN

.endif


ow_script_map_1_81_trainer_4:
special 0x187
compare LASTRESULT 0x2
gotoif EQUAL ow_script_0x1aa912
lockall
checkflag FRBADGE_6
gotoif LESS ow_script_0x1c1afb
checkattack ATTACK_ZERTRUEMMERER
compare LASTRESULT 0x6
gotoif EQUAL ow_script_0x1c1afb
setanimation 0x0 0x800d
bufferpartypokemon 0x0 0x800d
bufferattack 0x1 ATTACK_ZERTRUEMMERER
loadpointer 0x0 str_0x1c1b07
callstd MSG_YES_NO
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x1c1b04
loadpointer 0x0 str_0x1c1a37
callstd MSG_KEEPOPEN
closeonkeypress
doanimation 0x25
nop
waitstate
goto ow_script_0x1c1ad9


ow_script_movs_0x1c1af9:
.byte 0x68
.byte STOP


ow_script_0x1c1ad9:
applymovement 0x800f ow_script_movs_0x1c1af9
waitmovement 0x0
hidesprite 0x800f
special 0xab
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x1c1af7
waitstate
releaseall
end


ow_script_0x1c1af7:
releaseall
end


ow_script_0x1c1b04:
closeonkeypress
releaseall
end


ow_script_0x1c1afb:
loadpointer 0x0 str_0x1c1b4a
callstd MSG_SIGN
end


ow_script_0x1aa912:
release
end


.ifdef LANG_GER

str_0x1c1b07:
    .string "Dieser Fels ist zerbrechlich. Soll\nZERTRÜMMERER eingesetzt werden?"



str_0x1c1a37:
    .string "BUFFER_1 setzt\nBUFFER_2 ein."



str_0x1c1b4a:
    .string "Ein großer Felsen. Ein Pokémon\nkönnte ihn vielleicht zertrümmern."


.elseif LANG_EN

.endif


ow_script_map_3_22_trainer_8:
givepokemon POKEMON_BISAFLOR 0xa ITEM_NONE 0x0 0x0 0x0
end


ow_script_map_3_1_person_7:
lock
faceplayer
checkflag MERIANA_CITY_BLACK_BELT
gotoif EQUAL ow_script_0x8a28fd
loadpointer 0x0 str_0x8a29c0
callstd MSG_KEEPOPEN
copyvarifnotzero 0x8000 ITEM_SCHWARZGURT
copyvarifnotzero 0x8001 1
callstd ITEM_OBTAIN
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x87f3c1
loadpointer 0x0 str_0x8a2922
callstd MSG_KEEPOPEN
closeonkeypress
release
setflag MERIANA_CITY_BLACK_BELT
end


ow_script_0x87f3c1:
lock
faceplayer
loadpointer 0x0 str_0x87f3ce
callstd MSG
release
end


ow_script_0x8a28fd:
loadpointer 0x0 str_0x8a2907
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8a29c0:
    .string "Hjaaa! Huuu! Baaa! Kara!\nDiese Kampftechnik habe ich eigens\lentwickelt. Eines Tages werde ich\lsogar Manus damit übertrumpfen!\lDOTS\lHier, nimm das und trainiere deine\lPokémon selbst so wie ich es tue!"



str_0x8a2922:
    .string "Das Item Schwarzgurt verstärkt\nalle Kampf-Angriffe eines\lPokémon. Damit werden seine\lSchläge und Tritte noch viel\leffektiver sein!\lHjaaa! Huuu! Baa! Kara!"



str_0x87f3ce:
    .string "Sieht so aus, als hättest du für\nBUFFER_2 keinen Platz!\pKomm wieder, wenn du das Item\naufnehmen kannst."



str_0x8a2907:
    .string "Hjaaa! Huuu! Baaa! Kara!"


.elseif LANG_EN

.endif


ow_script_map_3_1_person_4:
loadpointer 0x0 str_0x8a1f57
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8a1f57:
    .string "QUOTE_STARTDie Stadt der BergeQUOTE_END, nennt man\nMeriana City mancherorts. Es\lheißt, dass hier der Arenaleiter\lKamillo aus Hoenn ausgebildet\lwurde. Seit dem zieht dieser Ort\lviele Kampf-Trainer an."


.elseif LANG_EN

.endif


ow_script_map_3_1_person_2:
loadpointer 0x0 str_0x8a200c
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8a200c:
    .string "Dieser Tunnel soll nach Route 2\nführen, aber ich fürchte mich vor\lHöhlen."


.elseif LANG_EN

.endif


ow_script_map_3_1_person_3:
loadpointer 0x0 str_0x8a2078
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8a2078:
    .string "Versteckte Maschienen ermöglichen\noft den Ort zu sonst\lunzugänglichen Arealen. Manchmal\lfindet man dort tolle Items."


.elseif LANG_EN

.endif


ow_script_map_3_1_person_14:
loadpointer 0x0 str_0x8a20ee
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8a20ee:
    .string "Mit der versteckten Maschiene\nZertrümmerer kann man diese Felsen\lzerschmetternDOTS Jedoch muss der\lTrainer auch die nötige\lQualifikation besitzen, meine ich."


.elseif LANG_EN

.endif


ow_script_map_3_1_person_8:
loadpointer 0x0 str_0x8a27bc
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8a27bc:
    .string "Der Wassertunnel verbindet Meriana\nCity mit Kaskada, der Stadt des\lWassers. Von dort aus erhält auch\ldieser Ort hier seine Versorgung\lmit frischem Wasser."


.elseif LANG_EN

.endif


ow_script_map_3_1_person_6:
loadpointer 0x0 str_0x8a2858
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8a2858:
    .string "Der Wassertunnel ist eingstürzt.\nDer Arenaleiter Manus\larbeitet derzeit an seiner\lReperatur, bitte gedulde dich."


.elseif LANG_EN

.endif


ow_script_map_3_1_person_5:
loadpointer 0x0 str_0x8a2a88
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8a2a88:
    .string "Der Wundertausch ist ein\nausgefallenes System. So kann\ljeder Trainer an die\lverschiedensten Pokémon gelangen.\lSpannend, was?"


.elseif LANG_EN

.endif


ow_script_map_3_1_person_11:
loadpointer 0x0 str_0x8a2b06
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8a2b06:
    .string "Es heißt, die Kampf-Angriffe von\nManus\' Pokémon könnten Felsen\lzertrümmern. Ob das wohl wahr ist?"


.elseif LANG_EN

.endif


ow_script_map_3_1_person_9:
loadpointer 0x0 str_0x8a2b69
callstd MSG
end


.ifdef LANG_GER

str_0x8a2b69:
    .string "Wenn ich so über die Kronen der\nBäume blicke, werde ich ganz\lmelancholisch. Als kleines Mädchen\lhaben ich und mein Pokémon gerne\lim Unterholz gespieltDOTS"


.elseif LANG_EN

.endif


ow_script_map_3_1_person_13:
loadpointer 0x0 str_0x8f6ed0
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8f6ed0:
    .string "Es heißt, dass in Theto einst das\nZeit-Pokémon das Herz der Zeit\lverborgen hat. Solange es schlägt,\lbleibt die Zeit im Fluss."


.elseif LANG_EN

.endif


ow_script_map_3_1_person_12:
loadpointer 0x0 str_0x8a2c84
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8a2c84:
    .string "Ich trainiere hier so lange, bis\nich in der Lage bin, es mit Manus\laufzunehmen."


.elseif LANG_EN

.endif


ow_script_map_3_1_person_10:
loadpointer 0x0 str_0x8a2cd5
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8a2cd5:
    .string "Route 1 liegt direkt am Fuße des\nWassergebirges. Nördlich von hier,\lüber den Wassertunnel, erreicht\lman die Stadt Kaskada."


.elseif LANG_EN

.endif

ow_script_map_3_1_person_1:
loadpointer 0x0 str_0x94568f
callstd MSG_FACE
call move_tutor_item_check
gotoif EQUAL ow_script_0x8faec2
end


say_exclam:
.byte SAY_EXCLAM
.byte STOP


ow_script_0x8faec2:
applymovement 0x800f say_exclam
waitmovement 0x0
loadpointer 0x0 str_0x945eb7
callstd MSG_YES_NO
compare LASTRESULT 0x1
gotoif LESS ow_script_0x8a1a57
loadpointer 0x0 str_0x8a1be6
callstd MSG
setflag TRANS_DISABLE
clearflag TRANS_PALETTE_FETCH
setvar 0x8005 MOVE_TUTOR_STEINHAGEL
call ow_script_move_tutor_do
clearflag TRANS_DISABLE
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x8a1a57
call ow_script_move_tutor_pay_items
loadpointer 0x0 str_move_tutor_pay_items
callstd MSG
end


ow_script_move_tutor_pay_items:
setvar 0x8000 ITEM_RIESENPILZ
setvar 0x8001 0x1
checkitem ITEM_MINIPILZ 0x3
compare LASTRESULT 0x1
gotoif LESS ow_script_0x9455d9
setvar 0x8000 ITEM_MINIPILZ
setvar 0x8001 0x3
removeitem ITEM_MINIPILZ 0x3
goto ow_script_0x9455e4


ow_script_0x9455e4:
bufferitem 0x0 0x8000
buffernumber 0x1 0x8001
return


ow_script_0x9455d9:
removeitem ITEM_RIESENPILZ 0x1
goto ow_script_0x9455e4


ow_script_0x8a1a57:
loadpointer 0x0 str_0x945830
callstd MSG
end


ow_script_move_tutor_do:
special SPECIAL_MOVE_TUTOR_SELECT_POKEMON
waitstate
lock
faceplayer
return


move_tutor_item_check:
setvar 0x8000 ITEM_MINIPILZ
setvar 0x8001 0x3
checkitem ITEM_MINIPILZ 0x3
compare LASTRESULT 0x1
gotoif EQUAL buffer_move_tutor_item
setvar 0x8000 ITEM_RIESENPILZ
setvar 0x8001 0x1
checkitem ITEM_RIESENPILZ 0x1
compare LASTRESULT 0x1
gotoif EQUAL buffer_move_tutor_item
setvar LASTRESULT 0x0
item_check_return:
return


buffer_move_tutor_item:
bufferitem 0x0 0x8000
buffernumber 0x1 0x8001
setvar LASTRESULT 0x1
goto item_check_return


.ifdef LANG_GER

str_0x94568f:
    .string "Hyaa! Hajajaja!\nIn vielen Jahren des harten\lTraining habe ich meine\lKampftechnik so sehr verfeinert,\ldass ich Steine regnen lassen\lkann!\pSoll ich einem deiner Pokémon den\nSteinhagel beibringen?\pDann will ich einen Riesenpilz\noder drei Minipilze als\lGegenleistung!"



str_0x945eb7:
    .string "Hyaa! Vortrefflich!\nDu hast BUFFER_2-mal BUFFER_1\lbei dir!\lAls Gegenleistung bringe ich einem\ldeiner Pokémon Steinhagel bei!\lWas sagst du dazu?"



str_0x8a1be6:
    .string "Schön, schön!\nWelches deiner Pokémon soll\lSteinhagel lernen?"


str_move_tutor_pay_items:
    .string "PLAYER übergibt\nBUFFER_2-mal BUFFER_1."



str_0x945830:
    .string "Hyaa! Wie schade!\pWenn ich einem deiner Pokémon\nSteinhagel beibringen soll, dann\lkomm mit 3 Minipilzen oder einem\lRiesenpilz wieder!"


.elseif LANG_EN

.endif


ow_script_meriana_dummy:
givepokemon POKEMON_EVOLI 0x5 0 0 0 0
givepokemon POKEMON_NINCADA 0x19 0 0 0 0
givepokemon POKEMON_SKORGLA 0x23 0 0 0 0
givepokemon POKEMON_PORYGON2 0x1e ITEM_DUBIOSDISC 0x0 0x0 0x0

copyvarifnotzero 0x8000 ITEM_FUNKELSTEIN
copyvarifnotzero 0x8001 1
callstd ITEM_OBTAIN

copyvarifnotzero 0x8000 ITEM_WASSERSTEIN
copyvarifnotzero 0x8001 1
callstd ITEM_OBTAIN

copyvarifnotzero 0x8000 ITEM_SONDERBONBON
copyvarifnotzero 0x8001 99
callstd ITEM_OBTAIN

copyvarifnotzero 0x8000 ITEM_LINKKABEL
copyvarifnotzero 0x8001 99
callstd ITEM_OBTAIN



end


ow_script_map_3_1_person_16:
loadpointer 0x0 str_0x8de4c9
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8de4c9:
    .string "Brüder und Schwestern, lasst uns\nkämpfen für eine Welt ohne\lUngerechtigkeit und Unterdrückung!"


.elseif LANG_EN

.endif


ow_script_map_3_1_person_15:
special 0x3b
playsong MUS_KAMPF_GEGEN_ARENALEITER_HOENN 0x0
trainerbattlecont 0x1 0x88 0x0 str_0x8f5cda str_0x8f5cda ow_script_0x8f5cd8


ow_script_0x8f5cd8:
end


.ifdef LANG_GER

str_0x8f5cda:
    .string "t"


.elseif LANG_EN

.endif


ow_script_map_3_1_person_17:
lock
faceplayer
buffernumber 0 WONDERTRADE_CNT
loadpointer 0x0 str_0
show_mugshot MUGSHOT_ELISE MUGSHOT_RIGHT
fadescreen 1
hidesprite LASTTALKED
fadescreen 0
release
end


draw_mugshot MUGSHOT_ELISE MUGSHOT_RIGHT
loadpointer 0x0 str_0x949632



.ifdef LANG_GER
str_0:
	.autostring 34 2 "Hallo PLAYER!\nSchön, dich zu sehen!\pIch muss dir noch einmal danken, dass du meinen Vater im Silvania-Wald vor Team Violet beschützt hast.\pIch begreife nicht, warum diese Leute ein Auge auf einen Physiker wie ihn geworfen haben.\pDOTS DOTS DOTS\pBenutzt du den Wundertausch auch?\pIch sehe, du hast bereits BUFFER_1 Pokémon getauscht.\pIst es nicht fantastisch, dass Trainer von überall durch diese App miteinander verbunden sind?\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pAber wie du dir bestimmt denken kannst, habe ich aus einem anderen Grund nach dir gesucht.\pProfessor Tann bricht bald auf eine Expedition auf und will dich und RIVAL davor noch einmal sehen.\pSei doch so nett, und besuche ihn in seinem Labor auf Route 2.\pBis dann, PLAYER!"
.elseif LANG_EN
.endif


callstd MSG_YES_NO
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x949573
setvar BATTLE_SONG_OVERRIDE 0x165
trainerbattlecont 0x1 0x84 0x0 str_0x94948c str_0x949515 ow_script_0x93d5e1


ow_script_0x93d5e1:
loadpointer 0x0 str_0x94918c
show_mugshot MUGSHOT_ELISE MUGSHOT_RIGHT
fadescreen 0x1
hidesprite 0x800f
setflag ROUTE_5_VIOLET_GRUNTS
fadescreen 0x0
release
end


ow_script_0x949573:
loadpointer 0x0 str_0x949581
callstd MSG
hide_mugshot
release
end


.ifdef LANG_GER

str_0x949632:
	.autostring 35 2 "Oh, hallo PLAYER!\nEntschuldige, ich wollte dich nicht überrumpeln.\pBenutzt du auch die Wundertausch-App?\pIch sehe, du hast ihn bereits BUFFER_1 mal verwendet.\pDas freut mich!\pIch habe mich zuletzt selbst auch am Kämpfen versucht.\pNa was sagst du, hättest du Lust auf einen Kampf?"



str_0x94948c:
	.autostring 35 2 "Meine Pokémon habe ich allesamt aus dem Wundertausch erhalten.\pWollen wir doch einmal sehen, wie ich mich so schlage."


str_0x949515:
    .autostring 35 2 "Das überrascht mich nicht.\nMir hätte eigentlich klar sein sollen, dass ein Anfänger wie ich keine Chance hat."



str_0x94918c:
	.autostring 35 2 "Du kämpfst wirklich auserordentlich gut, PLAYER.\pWas meinst du, wie habe ich mich geschlagen?\pVielleicht wird das Kämpfen ja zu meinem neuen Hobby.\pDie viele Forschung kann schon auch einmal recht trocken werden DOTS\pWo wir gerade beim Thema sind.\pDie Laz.Corp, das Unternehmen, bei dem ich beschäftigt bin, hat ein komplett virtuelles Pokémon erschaffen.\pDas dürfte dich interessieren, nicht?\pEs wird auch für deine Pokédex-App interessante Daten liefern.\pDer Hauptsitz der Laz.Corp liegt in Orina City, westlich von Route 2, wo das Labor von Professor Tann ist.\pKomm mich doch dort einmal besuchen.\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pVon mir hast du das mit dem virtuellen Pokémon aber nicht erfahren, ja?"



str_0x949581:
	.autostring 35 2 "Oh, ich verstehe schon.\pDu willst deinen erschöpften Pokémon sicherlich eine Pause gönnen.\pAber ein nein akzeptiere ich als Antwort nicht!\pKomm wieder, wenn du dich erholt hast.\pSolltest du mich schlagen, verrate ich dir auch ein interessantes Geheimnis!"


.elseif LANG_EN

.endif
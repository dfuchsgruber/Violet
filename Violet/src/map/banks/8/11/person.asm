.include "vars.s"
.include "map_adjacency_types.s"
.include "movements.s"
.include "specials.s"
.include "callstds.s"
.include "mugshot.s"
.include "ordinals.s"
.include "map_connections.s"
.include "overworld_script.s"
.include "flags.s"
.include "species.s"
.include "items.s"
.include "pathfinding.s"

.global ow_script_0x8c8786
.global ow_script_0x8a5444
.global ow_script_0x8c86e3
.global ow_script_0x933987
.global ow_script_0x8c8ac3
.global ow_script_map_8_11_person_1
.global ow_script_map_8_11_trainer_10
.global ow_script_0x933ec6
.global ow_script_map_8_11_person_2
.global ow_script_map_8_11_trainer_5
.global ow_script_0x880b64
.global ow_script_map_8_11_person_10
.global ow_script_map_8_11_trainer_0
.global ow_script_map_8_11_person_8
.global ow_script_0x8fadb7
.global ow_script_map_8_11_trainer_2
.global ow_script_0x931ddf
.global ow_script_map_8_11_person_4
.global ow_script_0x8c881e
.global ow_script_0x933e18
.global ow_script_map_8_11_trainer_4
.global ow_script_0x935b66
.global ow_script_map_8_11_person_0
.global ow_script_0x933ebf
.global ow_script_map_8_11_trainer_9
.global ow_script_map_8_11_trainer_1
.global ow_script_0x8fadcc
.global ow_script_0x933ecd
.global ow_script_map_8_11_trainer_3
.global ow_script_map_8_11_trainer_8
.global ow_script_map_8_11_person_5
.global ow_script_0x8c86c2
.global ow_script_0x935ad0
.global ow_script_0x916919
.global ow_script_map_8_11_trainer_7
.global ow_script_map_8_11_person_6
.global ow_script_0x8c8651
.global ow_script_0x8f6d95
.global ow_script_0x8f71d9
.global ow_script_map_8_11_person_3
.global ow_script_map_8_11_person_9
.global ow_script_map_8_11_trainer_6
.global ow_script_0x8d059f
.global ow_script_map_8_11_person_7
.global ow_script_black_market_igva_final

ow_script_map_8_11_trainer_10:
goto ow_script_0x8fadb7


ow_script_0x8fadb7:
compare WONDERTRADE_STEPS_TO_ENABLE 0xfa
gotoif LESS ow_script_0x8f71d9
goto ow_script_0x8f6d95


ow_script_0x8f6d95:
fadescreen 0x1
callasm 0x9198441
sound 0x2
checksound
loadpointer 0x0 str_0x8a5bb9
callstd MSG_YES_NO
compare LASTRESULT 0x1
gotoif EQUAL ow_script_0x8d059f
closeonkeypress
fadescreen 0x1
callasm 0x9198781
special 0xb
end


ow_script_0x8d059f:
closeonkeypress
fadescreen 0x1
callasm 0x919d791
special 0x9f
waitstate
clearflag MAP_BGN_AUTO_ALIGN_OFF
compare 0x8004 0x6
gotoif HIGHER_OR_EQUAL ow_script_0x8a5444
copyvar 0x8005 0x8004
special 0x11
special 0xfe
waitstate
goto ow_script_0x8fadcc


ow_script_0x8fadcc:
callasm 0x9198781
setvar WONDERTRADE_STEPS_TO_ENABLE 0x0
end


ow_script_0x8a5444:
end


ow_script_0x8f71d9:
buffernumber 0x0 0x50e2
loadpointer 0x0 str_0x8fad70
callstd MSG
end


.ifdef LANG_GER

str_0x8a5bb9:
    .string "Die Wundertausch-App wurde\naktiviert.\pMöchtest du einen Wundertausch\ndurchführen?"



str_0x8fad70:
    .string "Die Batterie des Wundertauschs\nbeträgt BUFFER_1/250.\pHab noch etwas Geduld!"


.elseif LANG_EN

.endif


ow_script_map_8_11_person_0:
loadpointer 0x0 str_0x8c830d
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8c830d:
    .string "Als ich mich Team Violet\nangeschlossen habe, wurde ich\lsofort dem Kommandanten der\lzweiten Division zugeteilt,\lMistral.\pEr ist ein äußert ambitionierter\nMann, skrupellos und mächtig."


.elseif LANG_EN

.endif


ow_script_map_8_11_person_2:
loadpointer 0x0 str_0x8c83c5
callstd MSG
end


.ifdef LANG_GER

str_0x8c83c5:
    .string "Ja, diese Lieferung sieht gut aus.\nWir Revolutionäre können derartige\lDinge immer gebrauchenDOTS"


.elseif LANG_EN

.endif


ow_script_map_8_11_person_1:
loadpointer 0x0 str_0x8c8430
callstd MSG
end


.ifdef LANG_GER

str_0x8c8430:
    .string "Die Bezahlung für besagte Waren\nkann ich nur bar entgegennehmenDOTS"


.elseif LANG_EN

.endif


ow_script_map_8_11_person_3:
loadpointer 0x0 str_0x8c847e
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8c847e:
    .string "Streng genommen ist er natürlich\nverboten, Fallen für Käfer-\lPokémon zu kaufenDOTS\pAndererseitsDOTS\pWie sonst soll ich der größte\nKäfersammler aller Zeiten werden?"


.elseif LANG_EN

.endif


ow_script_map_8_11_person_5:
loadpointer 0x0 str_0x8c8aec
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8c8aec:
    .string "Der Untergrund-Markt ist\nunantastbar.\pWenn man den Gerüchten glaubt,\nsteht an seiner Spitze ein\lMitglied der Top Vier selbst."


.elseif LANG_EN

.endif


ow_script_map_8_11_person_6:
loadpointer 0x0 str_0x8c8b6b
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8c8b6b:
    .string "Wieso ich mich Team Violet\nangeschlossen habe?\pMein Leben war bedeutungslos, bis\nman mir die Chance gegeben hat,\ldie Welt zu einem besseren Ort zu\lmachen.\pViele sehen nicht, dass wir der\nWelt Frieden bringen."


.elseif LANG_EN

.endif


ow_script_map_8_11_person_7:
loadpointer 0x0 str_0x8c8c3d
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8c8c3d:
    .string "Der Schwarzmarkt floriert, während\ndie Top Vier ihre Augen\lverschließen.\pIst es nicht ironisch, dass selbst\nRevolutionäre hier verkehren?"


.elseif LANG_EN

.endif


ow_script_map_8_11_person_9:
loadpointer 0x0 str_0x93155a
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x93155a:
	.autostring 35 2 "Sei gegrßt!\pMeine Wenigkeit verkauft leistungsfähige Supermagneten.\pDOTS DOTS DOTS\pDu weißt wohl gar nicht, von was ich spreche, was?"

.elseif LANG_EN

.endif


ow_script_map_8_11_person_4:
    loadpointer 0 str_01
    callstd MSG_FACE
    end

.ifdef LANG_GER

str_01:
    .autostring 34 2 "Hallo!\nWir verkaufen hier seltene und starke Pokémon aus aller Welt.\pDie meisten von ihnen waren lange im Besitz eines Trainers und warten mit besten kämpferischen Fähigkeiten auf.\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pMoment, Kindchen!\pWas hast du hier zu suchen?\pVerschwinde!"
.elseif LANG_EN
.endif

/** 
showmoney 0x0 0x0 0x0
loadpointer 0x0 str_0x8c8907
callstd MSG_KEEPOPEN
setvar DYN_MULTICHOICE_ITEM_CNT 0x6
loadpointer 0x0 choice
multichoice 0xd 0x0 0x0 0x1
setvar DYN_MULTICHOICE_ITEM_CNT 0x0
compare LASTRESULT 0x0
gotoif EQUAL pkmn0
compare LASTRESULT 0x1
gotoif EQUAL pkmn1
compare LASTRESULT 0x2
gotoif EQUAL pkmn2
compare LASTRESULT 0x3
gotoif EQUAL pkmn3
compare LASTRESULT 0x4
gotoif EQUAL pkmn4
goto ow_script_0x8c8ac3



pkmn0:
checkmoney 35000 0x0
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x8c8786
bufferpokemon 0x0 POKEMON_TROPIUS
call ow_script_0x8c86c2
paymoney 35000 0x0
setvar 0x8000 POKEMON_TROPIUS
goto ow_script_0x8c8651

pkmn1:
checkmoney 99999 0x0
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x8c8786
bufferpokemon 0x0 POKEMON_DRATINI
call ow_script_0x8c86c2
paymoney 99999 0x0
setvar 0x8000 POKEMON_DRATINI
goto ow_script_0x8c8651

pkmn2:
checkmoney 15000 0x0
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x8c8786
bufferpokemon 0x0 POKEMON_PERLU
call ow_script_0x8c86c2
paymoney 15000 0x0
setvar 0x8000 POKEMON_PERLU
goto ow_script_0x8c8651

pkmn3:
checkmoney 25000 0x0
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x8c8786
bufferpokemon 0x0 POKEMON_NEBULAK
call ow_script_0x8c86c2
paymoney 25000 0x0
setvar 0x8000 POKEMON_NEBULAK
goto ow_script_0x8c8651

pkmn4:
checkmoney 55000 0x0
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x8c8786
bufferpokemon 0x0 POKEMON_CHANEIRA
call ow_script_0x8c86c2
paymoney 55000 0x0
setvar 0x8000 POKEMON_CHANEIRA
goto ow_script_0x8c8651


.align 4
choice:
    .word str_blackmarket_pkmn0, 0
    .word str_blackmarket_pkmn1, 0
    .word str_blackmarket_pkmn2, 0
    .word str_blackmarket_pkmn3, 0
    .word str_blackmarket_pkmn4, 0
    .word str_blackmarket_back, 0



ow_script_0x8c8651:
updatemoney 0x0 0x0 0x0
sound 0x41
checksound
bufferpokemon 0x0 0x8000
fanfare 0x13e
loadpointer 0x0 str_0x8c86ac
callstd MSG_KEEPOPEN
waitfanfare
givepokemon 0x8000 0x5 ITEM_NONE 0x0 0x0 0x0
call ow_script_0x880b64
clearflag TRANS_DISABLE
goto ow_script_0x8c8ac3


ow_script_0x8c8ac3:
loadpointer 0x0 str_0x8c8683
callstd MSG
hidemoney 0x0 0x0
end


ow_script_0x880b64:
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x880b86
compare LASTRESULT 0x1
gotoif EQUAL ow_script_0x880ba0
compare LASTRESULT 0x2
gotoif EQUAL ow_script_0x880be5
end


ow_script_0x8c86c2:
loadpointer 0x0 str_0x8c8767
callstd MSG_YES_NO
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x8c881e
countpokemon
compare LASTRESULT 0x6
gotoif EQUAL ow_script_0x8c86e3
return


ow_script_0x8c86e3:
hidemoney 0x0 0x0
loadpointer 0x0 str_0x8c86f0
callstd MSG
end


ow_script_0x8c881e:
hidemoney 0x0 0x0
loadpointer 0x0 str_0x8c882b
callstd MSG
end


ow_script_0x8c8786:
hidemoney 0x0 0x0
loadpointer 0x0 str_0x8c8793
callstd MSG
end



.ifdef LANG_GER

str_01:
    .autostring 34 2 "Hallo!\nWir verkaufen hier seltene und starke Pokémon aus aller Welt.\pDie meisten von ihnen waren lange im Besitz eines Trainers und warten mit besten kämpferischen Fähigkeiten auf.\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pMoment, Kindchen!\pWas hast du hier zu suchen?\pVerschwinde!"

str_0x8c8907:
    .string "Hallo! Du siehst aus wie ein\nTrainer, nicht?\pWie wäre es, dein Team mit ein\npaar exklusiven Pokémon\laufzustocken?\pIch verkaufe dir die seltensten\nExemplare zu einem Spottpreis!\pSieh dir mein Sortiment\nruhig an."



str_blackmarket_pkmn0:
    .string "Topius     35.000POKEDOLLAR   "



str_blackmarket_pkmn1:
    .string "Dratini    99.999POKEDOLLAR"



str_blackmarket_pkmn2:
    .string "Perlu      15.000POKEDOLLAR"



str_blackmarket_pkmn3:
    .string "Nebulak    25.000POKEDOLLAR"



str_blackmarket_pkmn4:
    .string "Chaneira   55.000POKEDOLLAR"



str_blackmarket_back:
    .string "Zurück            "



str_0x8c86ac:
    .string "PLAYER hat BUFFER_1\nerhalten!"



str_0x8c8683:
    .string "Vielen Dank! Beehre mich gerne\nwieder!"



str_0x8c8767:
    .string "Das Pokémon BUFFER_1 soll\nes sein?"



str_0x8c86f0:
    .string "Du scheinst nicht genügend Platz\nin deinem Team zu haben.\pKomm wieder, wenn du Platz in\ndeinem Team geschaffen hast."



str_0x8c882b:
    .string "Ganz wie du möchtest.\pKomm jederzeit wieder, falls du es\ndir anders überlegst."



str_0x8c8793:
    .string "Oh, sieht so aus, als hättest du\nnicht genügend Geld bei dir, um\ldir das zu leisten.\pKomm wieder, wenn du dir das\nProdukt kaufen kannst."


.elseif LANG_EN

.endif
*/

ow_script_map_8_11_person_8:
loadpointer 0 str_02
callstd MSG_FACE
end


.ifdef LANG_GER
str_02:
    .autostring 34 2 "Hehe!\pDas hier ist ein wirklich fabelhafter Ort.\pUnter dem Schirm der Top Vier kann man so einiges anstellenDOTS"

.elseif LANG_EN

.endif


ow_script_movs_0x8c8e03:
.byte SAY_EXCLAM
.byte STOP


ow_script_map_8_11_person_10:
loadpointer 0x0 str_0x931867
show_mugshot MUGSHOT_PRIMUS MUGSHOT_LEFT
sound 0x15
applymovement LASTTALKED ow_script_movs_0x8c8e03
waitmovement 0x0
faceplayer
loadpointer 0x0 str_0x931636
show_mugshot MUGSHOT_PRIMUS MUGSHOT_LEFT
lockall
npc_move_to 0xe 0x1c 0x2a
hidesprite LASTTALKED
releaseall
end


.ifdef LANG_GER

str_0x931867:
	.autostring 35 2 "Äh ja, verstehen Sie DOTS\pFür das Portal benötige ich sehr starke Magnetfelder DOTS"



str_0x931636:
	.autostring 35 2 "PLAYER!\nWas treibst du denn an einem solchen Ort?\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pWarum ich hier bin?\nNun, das ist eine ausgezeichnete FrageDOTS\pSieh mal, es ist so, dass viele Dinge, die ich für meine Forschung benötige, nur hier zu finden sindDOTS\pAber bitte, das bleibt unter uns PLAYER, ja?\pIch habe einen Ruf zu verlieren.\pUnd was meine arme Elise von mir halten würde, wenn sie erfahren würde, dass ihr Vater sich Forschungsmittel an einem Ort wie diesem besorgt.\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pDu solltest dich hier nicht zu lange aufhalten, PLAYERDOTS"

.elseif LANG_EN

.endif


ow_script_map_8_11_trainer_1:
loadpointer 0x0 str_0x931979
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x931979:
    .string "Du machst dir also die Mühe, mit\nallen Statisten zu sprechen?\pNein im Ernst, das ist toll!\pIch verrate dir im Gegenzug ein\nGeheimnis. Viele der Stände hier\lwerden erst in späteren Versionen\lsinnvoll besetzt sein.\pGedulde dich einfach ein bisschen!"


.elseif LANG_EN

.endif


ow_script_map_8_11_trainer_3:
loadpointer 0x0 str_0x931aaa
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x931aaa:
    .string "Manus, aus Blütenbach, verkehrt\ndes Öfteren hier.\pWas er hier treibt? Keinen blassen\nSchimmer.\pLegal ist es auf jeden Fall nicht!"


.elseif LANG_EN

.endif


ow_script_map_8_11_trainer_4:
loadpointer 0x0 str_0x931b2f
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x931b2f:
    .string "Ich eine Schwester des Pokéstops?\nDas ist ein Irrtum!\pDas Pokéstop-Franchise steht in\nkeiner Verbindung zu diesem\lSchwarzmarkt! Ehrlich!"


.elseif LANG_EN

.endif


ow_script_map_8_11_trainer_0:
trainerbattlestd 0x0 0x71 0x0 str_0x931930 str_0x9318e0
loadpointer 0x0 str_0x9318e0
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x931930:
    .string "Nja! Du schon wieder!\pDu wirst uns hier nicht auch die\nTour vermasseln!"



str_0x9318e0:
    .string "Was ist dein Antrieb?\pSiehst du nicht, dass wir der Welt\nden Frieden bringen?"


.elseif LANG_EN

.endif


ow_script_map_8_11_trainer_2:
trainerbattlestd 0x0 0x72 0x0 str_0x931a72 str_0x92df3b
loadpointer 0x0 str_0x92df3b
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x931a72:
    .string "Lord Albus ist der Bringer einer\nneuen Welt! Heil ihm!"



str_0x92df3b:
    .string "Hast du nicht genug gesehen?\pStellst du dich uns wieder in die\nQuere?"


.elseif LANG_EN

.endif


ow_script_map_8_11_trainer_7:
loadpointer 0x0 str_0x931edc
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x931edc:
    .string "Die Welt ist kompliziert.\nWenn jemand wie Team Violet\leinfache Lösungen anbietet, wieso\lnicht?"


.elseif LANG_EN

.endif


ow_script_map_8_11_trainer_8:
loadpointer 0x0 str_0x9339fb
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x9339fb:
    .string "Viele Pokéstops werden durch\nsteuerfreie Ware finanziert.\pIn vielen Teilen der Region reicht\noft das Budget der Top Vier nicht\laus.\pBesonders in den Distirkten des\nPinken Faun ist das ein Problem."


.elseif LANG_EN

.endif


ow_script_map_8_11_trainer_5:
draw_mugshot MUGSHOT_BLAISE MUGSHOT_RIGHT
loadpointer 0x0 str_0x931d8f
callstd MSG
faceplayer
loadpointer 0x0 str_0x931bb9
callstd MSG_FACE
hide_mugshot
fadescreen 0x1
hidesprite 0x800f
fadescreen 0x0
release
end


.ifdef LANG_GER

str_0x931d8f:
    .autostring 35 2 "DOTS DOTS DOTS\nDOTS DOTS DOTS"



str_0x931bb9:
	.autostring 34 2 "PLAYER!\nDu hast doch diesen lästigen Felix nicht auch mitgebracht, oder?\pIch war froh, ihn endlich abgeschüttelt zu haben.\pDOTS DOTS DOTS\pDich hätte ich hier nicht erwartet, wenn ich ehrlich bin.\pWeißt du, dieser Ort ist einer der Gründe, warum mein Vater zu Fall gebracht werden muss.\pEr unterhält diesen Schwarzmarkt.\pWenn du so willst, kontrolliert er die Geschehnisse hier.\pUnd er tut all das, obwohl er ein Mitglied der Top Vier ist.\pIch hoffe, dass du nicht wie Felix versuchen willst, mich aufzuhalten.\pIch habe meinen Entschluss gefasst.\pUnd ich werde mich von euch Nervensägen nicht davon abbringen lassen, meinen Vater zu stürzen.\pDOTS DOTS DOTS\nDOTS DOTS DOTS"

.elseif LANG_EN

.endif

ow_script_0x916919:
setvar 0x8000 POKEMON_SHUPPET
call ow_script_find_egg
end


ow_script_map_8_11_trainer_6:
checkflag KASKADA_BLACKMARKET_SCHATTENGLAS
gotoif EQUAL ow_script_0x931ddf
lock
faceplayer
setflag KASKADA_BLACKMARKET_SCHATTENGLAS
loadpointer 0x0 str_0x931e57
callstd MSG_KEEPOPEN
copyvarifnotzero 0x8000 ITEM_SCHATTENGLAS
copyvarifnotzero 0x8001 1
callstd ITEM_OBTAIN
loadpointer 0x0 str_0x931e1e
callstd MSG_FACE
end



ow_script_0x931ddf:
loadpointer 0x0 str_0x931de9
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x931e57:
    .string "Ah, ich sehe, dass du ein\ngerissenes kleines Balg bist."



str_0x931e1e:
    .string "Mit diesen Gläsern siehst du die\nWelt angenehm dunkel."



str_0x931de9:
    .string "Ein düsterer Blick auf alles raubt\ndir Illusionen."


.elseif LANG_EN

.endif


ow_script_map_8_11_trainer_9:
loadpointer 0x0 str_0x93674c
callstd MSG_YES_NO
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x935b66
loadpointer 0x0 str_0x935fb2
callstd MSG_YES_NO
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x935b66
checkmoney 0x1388 0x0
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x935ad0
loadpointer 0x0 str_0x935a97
callstd MSG
setvar 0x8004 0x14
goto ow_script_0x933987


ow_script_0x933987:
buffernumber 0x0 0x8004
loadpointer 0x0 str_0x935a60
callstd MSG_KEEPOPEN
setvar DYN_MULTICHOICE_ITEM_CNT 0x3
loadpointer 0x0 choice_game
multichoice 0x0 0x0 0x0 0x1
compare LASTRESULT 0x0
callif EQUAL ow_script_0x933ebf
compare LASTRESULT 0x1
callif EQUAL ow_script_0x933ec6
compare LASTRESULT 0x2
callif EQUAL ow_script_0x933ecd
special 0x25
setvar DYN_MULTICHOICE_ITEM_CNT 0x0
buffernumber 0x0 0x8005
loadpointer 0x0 str_0x933e82
callstd MSG
compare 0x8004 0x0
gotoif EQUAL ow_script_0x933e18
goto ow_script_0x933987

.align 4
choice_game:
    .word str_blackmarket_1, 0
    .word str_blackmarket_2, 0
    .word str_blackmarket_3, 0

ow_script_0x933e18:
loadpointer 0x0 str_0x933e28
callstd MSG
paymoney 0x1388 0x0
end


ow_script_0x933ecd:
subvar 0x8004 0x3
return


ow_script_0x933ec6:
subvar 0x8004 0x2
return


ow_script_0x933ebf:
subvar 0x8004 0x1
return


ow_script_0x935ad0:
loadpointer 0x0 str_0x935ada
callstd MSG
end


ow_script_0x935b66:
loadpointer 0x0 str_0x9366ff
callstd MSG
end


.ifdef LANG_GER

str_0x93674c:
    .string "Oh hallo!\pHast du Lust auf kleines lustiges\nSpielchen mit einem alten Herren?"



str_0x935fb2:
    .string "Lass mich das Spielchen erklären.\pIch habe hier 20 Murmeln, wir\nbeide nehmen abwechselnd entweder\leine, zwei oder drei Murmeln.\pDer Spieler, der die letzte Murmel\nan sich nimmt, gewinnt das Spiel.\pSimpel, nicht?\pWenn du gewinnst, zahle ich dir\n50 000POKEDOLLAR, anderenfalls schuldest\ldu mir 5 000POKEDOLLAR.\pWas sagst du?"



str_0x935a97:
    .string "Gut, ich bin so freundlich und\nlasse dir den Vortritt."



str_0x935a60:
    .string "BUFFER_1 Murmeln verbleiben.\nWie viele möchtest du nehmen?"



str_blackmarket_1:
    .string "Eine"



str_blackmarket_2:
    .string "Zwei"



str_blackmarket_3:
    .string "Drei"



str_0x933e82:
    .string "Na dann werde ich DOTS äh DOTS\nBUFFER_1 Murmeln nehmen, denke ich."



str_0x933e28:
    .string "Oh, was ein Pech!\pSieht so aus, als hättest du\nverloren!\pDas tut mir aufrichtig leidDOTS"



str_0x935ada:
    .string "Du hast ja nicht einmal genügend\nGeld, deine Schulden zu zahlen!"



str_0x9366ff:
    .string "Oh, das ist aber schade!\nDu hast wohl Angst, gegen mich zu\lverlieren, was?"


.elseif LANG_EN

.endif


ow_script_black_market_igva_final:
	checkflag KASKADA_BLACKMARKET_PRIMUS
	gotoif LESS not_done
	checkflag KASKADA_BLACKMARKET_BLAISE
	gotoif LESS not_done
	checkflag KASKADA_BLACKMARET_BB_SHIP
	gotoif LESS not_done
	lock
	faceplayer
	loadpointer 0 str_0
	show_mugshot MUGSHOT_IGVA MUGSHOT_LEFT message_type=MSG
	clearflag PKMNMENU
	showsprite 29
	showsprite 30
	showsprite 31
	applymovement 29 mov_6u
	applymovement 30 mov_6u
	applymovement 31 mov_6u
	loadpointer 0 str_1
	show_mugshot MUGSHOT_ALBUS MUGSHOT_RIGHT message_type=MSG
	waitmovement 0
	sound 0x15
	applymovement 31 mov_exclam
	waitmovement 0
	checksound
	pause 16
	loadpointer 0 str_2
	show_mugshot MUGSHOT_ALBUS MUGSHOT_RIGHT message_type=MSG
	loadpointer 0 str_3
	show_mugshot MUGSHOT_IGVA MUGSHOT_LEFT message_type=MSG
	loadpointer 0 str_4
	show_mugshot MUGSHOT_ALBUS MUGSHOT_RIGHT message_type=MSG
	loadpointer 0 str_5
	show_mugshot MUGSHOT_IGVA MUGSHOT_LEFT message_type=MSG
	loadpointer 0 str_6
	show_mugshot MUGSHOT_ALBUS MUGSHOT_RIGHT message_type=MSG
	loadpointer 0 str_7
	show_mugshot MUGSHOT_IGVA MUGSHOT_LEFT message_type=MSG
	loadpointer 0 str_8
	show_mugshot MUGSHOT_ALBUS MUGSHOT_RIGHT message_type=MSG
	applymovement 29 mov_6d
	applymovement 30 mov_6d
	applymovement 31 mov_6d
	waitmovement 0
	hidesprite 29
	hidesprite 30
	hidesprite 31
	loadpointer 0 str_9
	show_mugshot MUGSHOT_IGVA MUGSHOT_LEFT message_type=MSG
	fadescreen 1
	hidesprite 32
	fadescreen 0
	release
	end

not_done:
	loadpointer 0 str_not_done
	show_mugshot MUGSHOT_IGVA MUGSHOT_LEFT message_type=MSG_FACE
	end


.ifdef LANG_GER
str_not_done:
	.autostring 34 2 "PLAYER, du solltest dich hier noch ein wenig umsehen."
str_0:
	.autostring 34 2 "Es ist erschreckend, welche Dinge im Untergrund von Theto vor sich gehen, nicht?\pDie Pokémon-Liga ist längst ein Teil dieser verbrecherischen Welt geworden.\pUnd genau deshalbDOTS\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pDOTSist es die Pflicht eines jeden Menschen, sich dagegen aufzulehnen.\pPLAYER, falls du es noch nicht bemerkt hast, ich bin ein Mitglied der Revolutionsbewegung.\pUnd irgendetwas sagt mir, dass du gut in unsere Reihen passen würdest.\pWas sagst du, willst du dich unserer Sache anschließen?"
str_1:
	.autostring 34 2 "Igva, wir brechen aufDOTS"
str_2:
	.autostring 34 2 "PLAYER, was treibst du an einem solchen Ort?\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pEs war wohl Igva, die dich hierher geführt hat, nicht?"
str_3:
	.autostring 34 2 "PLAYER soll sich ein Bild von den Verhältnissen in dieser Region machen."
str_4:
	.autostring 34 2 "Igva, ich freue mich über deine Leidenschaft für unsere Sache.\pAber PLAYER sollte sich Zeit nehmen, sich zu entscheiden, auf wessen Seite er stehen möchte.\pDas letzte Mal, als du jemanden mit so viel Engagement angeworben hastDOTS\pDu weißt ja, wie das ausgegangen ist."
str_5:
	.autostring 34 2 "DOTS DOTS DOTS\nDOTS DOTS DOTS"
str_6:
	.autostring 34 2 "PLAYER.\nJetzt, wo du diesen Ort gesehen hast, ist dir vielleicht ein Stück klarer geworden, weshalb ich mich dazu entschlossen habe, die Pokémon-Liga zu zerschlagen.\pAber ich bleibe dabei, dich nicht zu einer Entscheidung zwingen zu wollen.\pDu bist noch jung und gerade erst ein Trainer geworden.\pDie Welt ist viel größer, beeindruckender und, ja, auch beängstigender, als du es dir jetzt noch vorstellen kannst.\pLass dich nicht von deinem Weg abbringen.\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pIgva, wir ziehen weiter."
str_7:
	.autostring 34 2 "Gib mir noch einen Moment mit PLAYER, bitte."
str_8:
	.autostring 34 2 "Ganz wie du möchtestDOTS"
str_9:
	.autostring 34 2 "PLAYER, ich will ganz offen zu dir sein.\pVor einiger Zeit traf ich jemanden, den ich wie dich für die Revolution gewinnen wollte.\pVielleicht bin ich in der Hinsicht etwas zu eifrigDOTS\pLetztlich muss wohl der Antrieb, sich dieser Sache anzuschließen, von einem selbst kommen.\pSolltest du also je das ehrliche Bedürfnis verspüren, etwas an den bestehenden Verhältnissen zu ändernDOTS\pDann werde ich dich jederzeit mit offenen Armen empfangen, PLAYER.\pIch will, dass du das weißt.\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pIch hoffe, dass wir uns eines Tages wiedersehen, PLAYER!"

.elseif LANG_EN

.endif

mov_6u:
	.byte STEP_UP, STEP_UP, STEP_UP, STEP_UP, STEP_UP, STEP_UP, STOP
mov_6d:
	.byte STEP_DOWN, STEP_DOWN, STEP_DOWN, STEP_DOWN, STEP_DOWN, STEP_DOWN, STOP

mov_exclam:
	.byte SAY_EXCLAM, STOP
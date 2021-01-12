.include "vars.s"
.include "movements.s"
.include "callstds.s"
.include "songs.s"
.include "mugshot.s"
.include "overworld_script.s"
.include "flags.s"
.include "pathfinding.s"


.global ow_script_kaskada_black_market_pirates

ow_script_kaskada_black_market_pirates:
	lockall
	fadesong MUS_PIRATE
	loadpointer 0 str_0
	show_mugshot MUGSHOT_LUCKY MUGSHOT_LEFT mask_name=1
	msgbox_with_name str_1 str_priate 
	loadpointer 0 str_2
	show_mugshot MUGSHOT_LUCKY MUGSHOT_LEFT emotion=MUGSHOT_SCARED
	msgbox_with_name str_3 str_priate
	applymovement 36 mov_fr
	waitmovement 0
	msgbox_with_name str_4 str_priate
	clearflag PKMNMENU
	showsprite 24
	pause 32
	applymovement 36 mov_fu
	waitmovement 0
	sound 0x15
	applymovement 36 mov_exclam
	waitmovement 0
	checksound
	loadpointer 0 str_5
	show_mugshot MUGSHOT_LUCKY MUGSHOT_LEFT emotion=MUGSHOT_SCARED
	applymovement 24 mov_1d
	waitmovement 0
	loadpointer 0 str_6
	show_mugshot MUGSHOT_BLACKBEARD MUGSHOT_RIGHT emotion=MUGSHOT_SCARED hide_mugshot=0 message_type=MSG_KEEPOPEN
	loadpointer 0 str_7
	update_mugshot_emotion MUGSHOT_ANGRY
	callstd MSG_KEEPOPEN
	loadpointer 0 str_8
	update_mugshot_emotion MUGSHOT_NORMAL
	callstd MSG_KEEPOPEN
	closeonkeypress
	hide_mugshot
	applymovement 24 mov_1u
	waitmovement 0
	pause 24
	applymovement 24 mov_fd
	waitmovement 0
	loadpointer 0 str_9
	show_mugshot MUGSHOT_BLACKBEARD MUGSHOT_RIGHT
	applymovement 25 mov_fu
	applymovement 26 mov_fu
	waitmovement 0
	msgbox_with_name str_10 str_priate 
	applymovement 24 mov_fu
	waitmovement 0
	pause 32
	sound 9
	hidesprite 24
	checksound
	applymovement 25 mov_fr
	applymovement 26 mov_fl
	applymovement 36 mov_fl
	waitmovement 0
	pause 48
	applymovement 36 mov_fr
	waitmovement 0
	pause 48
	applymovement 36 mov_fl
	waitmovement 0
	pause 48
	applymovement 36 mov_1u
	waitmovement 0
	applymovement 25 mov_fu
	applymovement 26 mov_fu
	applymovement 36 mov_fd
	waitmovement 0
	loadpointer 0 str_11
	show_mugshot MUGSHOT_LUCKY MUGSHOT_LEFT emotion=MUGSHOT_SCARED
	applymovement 26 mov_force_lucky
	waitmovement 0
	msgbox_with_name str_12 str_priate
	applymovement 26 mov_1u
	applymovement 36 mov_1u
	waitmovement 0
	pause 24
	sound 9
	hidesprite 36
	checksound
	applymovement 26 mov_1u
	applymovement 25 mov_1r
	waitmovement 0
	applymovement 25 mov_1u
	waitmovement 0
	pause 24
	sound 9
	hidesprite 26
	checksound
	applymovement 25 mov_1u
	waitmovement 0
	pause 24
	sound 9
	hidesprite 25
	checksound
	pause 64
	callasm blackbeard_ship_move_left
	setflag KASKADA_BLACKMARET_BB_SHIP
	addvar STORY_PROGRESS 1
	releaseall
	end

mov_force_lucky:
	.byte STEP_LEFT, LOOK_UP, STOP


.ifdef LANG_GER
str_0:
	.autostring 34 2 "Ich sage es euch, Freunde!\pDas ist die Gelegenheit.\pWenn ihr euch unserer Revolutionsbewegung anschließt können wir zusammen die Top Vier klein kriegenDOTS\pDann kann der Kapitän das ganze Meer beherrschen!"
str_1:
	.autostring 34 2 "Na, das hört sich ja alles ganz spannend an, Lucky.\pAber ich glaube, der Kapitän hat mit dir ganz andere Pläne.\pSeit dem Vorfall damalsDOTS"
str_2:
	.autostring 34 2 "A-ach dasDOTS\nDas ist doch längst Schnee von gestern, oder nicht?\pIhr seid doch deswegen nicht immer noch wütend auf mich, oder, Freunde?"
str_3:
	.autostring 34 2 "Nein, wir sind dir nicht böse deswegen.\pAber Blackbeard ist da wohl etwas nachtragender."
str_4:
	.autostring 34 2 "Und dass du so bereitwillig hierher kommst und dich praktisch auslieferstDOTS\pDas fand er wirklich aufmerksam von dir."
str_5:
	.autostring 34 2 "K-Kapitän Blackbeard!\nDOTS\pW-Was für eine Freude, euch wiederzusehen."
str_6:
	.autostring 34 2 "Spar dir das Gesülze, Lucky!"
str_7:
	.autostring 34 2 "Ich hab' nicht vergessen, was du auf meinem Schiff abgezogen hast.\pEine Meuterei gegen den Kapitän anzuzetteln ist unverzeihlich."
str_8:
	.autostring 34 2 "Wir werden eine Menge Spaß zusammen haben, Lucky."
str_9:
	.autostring 34 2 "Bringt ihn an Board und sperrt ihn in irgendeine Zelle."
str_10:
	.autostring 34 2 "Aye, aye, Kapitän!"
str_11:
	.autostring 34 2 "J-Jetzt wartet doch einmal.\pW-Wir können doch sicher über alles reden, oder?\pI-IchDOTS"
str_12:
	.autostring 34 2 "Nichts da, du kommst schön mit unsDOTS"
str_priate:
	.string "Pirat"
.elseif LANG_EN
.endif


.global ow_script_0x93395a
.global ow_script_map_8_11_trigger_0
.global ow_script_0x93154e
.global ow_script_map_8_11_trigger_1

ow_script_map_8_11_trigger_0:
lockall
showsprite 0xc
npc_move_to_player 0xC
faceplayer
loadpointer 0x0 str_0x93144c
show_mugshot MUGSHOT_IGVA MUGSHOT_LEFT
npc_move_to 0xc 0x1b 0x2b waitmovement=0
goto ow_script_0x93154e


ow_script_0x93154e:
waitmovement 0x0
hidesprite 0xC
addvar STORY_PROGRESS 0x1
end


.ifdef LANG_GER

str_0x93144c:
	.autostring 34 2 "Wenn ich es mir recht überlege DOTS\pVielleicht solltest du diesen Ort auf eigene Faust erkunden.\pSo kannst du dir besser selbst ein Bild von den Zuständen in Theto machen.\pKomm einfach zu mir, wenn du dich etwas umgesehen hast.\pAber versuche, nicht zu sehr aufzufallen.\pDie Menschen hierDOTS\nDOTS DOTS DOTS\pSei einfach auf der Hut!"

.elseif LANG_EN

.endif


ow_script_movs_0x9339f0:
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STOP


ow_script_movs_0x933904:
.byte LOOK_UP
.byte SAY_EXCLAM
.byte STOP


ow_script_movs_0x931fc2:
.byte LOOK_UP
.byte STOP


ow_script_movs_0x931fc5:
.byte STEP_UP
.byte STOP


ow_script_map_8_11_trigger_1:
lockall
fadesong MUS_PIRATE
special 0x113
applymovement 0x7f ow_script_movs_0x9339f0
waitmovement 0x0

loadpointer 0 str_pirat
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x93386b
callstd MSG
special 0xF

loadpointer 0 str_pirat
setvar 0x8000 1
special 0xE
loadpointer 0x0 str_0x9337e5
callstd MSG
special 0xF
showsprite 0x1a
pause 0x18

loadpointer 0 str_pirat
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x933908
callstd MSG
special 0xF

sound 0x15
applymovement 0x18 ow_script_movs_0x933904
applymovement 0x19 ow_script_movs_0x933904
waitmovement 0x0

loadpointer 0 str_pirat
setvar 0x8000 1
special 0xE
loadpointer 0x0 str_0x9338d3
callstd MSG
special 0xF

applymovement 0x1a ow_script_movs_0x931fc2
applymovement 0x18 ow_script_movs_0x931fc5
applymovement 0x19 ow_script_movs_0x931fc5
pause 0x38
goto ow_script_0x93395a


ow_script_movs_0x933b99:
.byte STEP_LEFT_VERY_SLOW
.byte STEP_LEFT_VERY_SLOW
.byte STEP_LEFT_VERY_SLOW
.byte STEP_LEFT_VERY_SLOW
.byte STEP_LEFT_VERY_SLOW
.byte STEP_LEFT_VERY_SLOW
.byte STEP_LEFT_VERY_SLOW
.byte STEP_LEFT_VERY_SLOW
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STOP


ow_script_movs_0x9339f6:
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_DOWN
.byte STOP


ow_script_0x93395a:
hidesprite 0x18
hidesprite 0x19
hidesprite 0x1a
applymovement 0x2 ow_script_movs_0x933b99
waitmovement 0x0
hidesprite 0x2
applymovement 0x7f ow_script_movs_0x9339f6
waitmovement 0x0
special 0x114
addvar STORY_PROGRESS 0x1
fadesong MUS_BLACK_MARKET
releaseall
end


.ifdef LANG_GER

str_pirat:
	.string "Pirat"


str_0x93386b:
	.autostring 34 2 "Ich habe mich noch nie so lebendig gefühlt in meinem ganzen Leben.\pAuf Blackbeards Schiff anzuheuern, war die beste Entscheidung meines Lebens."



str_0x9337e5:
	.autostring 34 2 "Ein Beutefeldzug und schon Pirat durch und durch, was?\pLass es dir ja nicht zu gut gehen, wir haben noch einiges vor.\pKapitän Blackbeard plant, die Expidition von Professor Tann zu karpern.\pDas wird sicher ein Spaß!"


str_0x933908:
	.autostring 34 2 "Ahoi, Männer!\pWir stehen ich See!\pWir sind hier fertig."



str_0x9338d3:
    .autostring 34 2 "Aye! Wir haben verstanden!\pAlle Mann an Board!"


.elseif LANG_EN

.endif
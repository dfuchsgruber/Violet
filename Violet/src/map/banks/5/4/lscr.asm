.include "vars.s"

.global lscr_0x71a210

lscr_0x71a210:
	.byte 0x3
.word ow_script_0x16a237
	.byte 0x5
.word ow_script_0x1bf89b
	.byte 0x2
.word lscr_0x718d9c
	.byte 0x0






.align 4
.global lscr_0x718d9c

lscr_0x718d9c:
	.hword STORY_PROGRESS, 0x9
	.word ow_script_0x88832c
	.hword 0x0
.include "vars.s"
.include "healingplaces.s"
.include "movements.s"
.include "specials.s"
.include "songs.s"
.include "callstds.s"
.include "flags.s"
.include "overworld_script.s"
.include "items.s"

.global ow_script_0x8884c3
.global ow_script_0x88832c
.global ow_script_0x16a237
.global ow_script_0x1bf89b
ow_script_0x16a237:
sethealingplace HEALINGPLACE_MERIANA_CITY
end


ow_script_0x1bf89b:
special 0x182
end


ow_script_movs_0x888a24:
.byte SAY_EXCLAM
.byte STOP


ow_script_movs_0x888a27:
.byte LOOK_UP
.byte STOP


ow_script_movs_0x888a2a:
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STOP


ow_script_movs_0x888a2f:
.byte STEP_RIGHT
.byte STEP_UP
.byte STOP


ow_script_movs_0x888a36:
.byte LOOK_RIGHT
.byte STOP


ow_script_movs_0x888a33:
.byte LOOK_LEFT
.byte STOP


ow_script_movs_0x888a40:
.byte STEP_LEFT
.byte STOP


ow_script_movs_0x888a39:
.byte STEP_LEFT
.byte LOOK_UP
.byte STOP


ow_script_movs_0x888a10:
.byte STEP_DOWN
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_UP
.byte STOP


ow_script_movs_0x888a16:
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_UP
.byte LOOK_UP
.byte STOP


ow_script_movs_0x888a1d:
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte LOOK_UP
.byte STOP


ow_script_movs_0x888a08:
.byte STEP_RIGHT
.byte LOOK_UP
.byte STOP


ow_script_movs_0x888a0c:
.byte STEP_RIGHT
.byte LOOK_UP
.byte STOP


ow_script_movs_0x8889e6:
.byte STEP_RIGHT
.byte STEP_DOWN
.byte STOP


ow_script_movs_0x888a04:
.byte STEP_DOWN
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STOP


ow_script_movs_0x888a43:
.byte STEP_IN_PLACE_RIGHT
.byte STOP


ow_script_movs_0x8889fe:
.byte STEP_DOWN
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_UP
.byte STOP


ow_script_movs_0x8889ea:
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_DOWN
.byte STOP


ow_script_movs_0x8889f4:
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_DOWN
.byte STEP_DOWN
.byte STOP


ow_script_movs_0x888a3d:
.byte STEP_DOWN
.byte STOP


ow_script_0x88832c:
sound 0x15
applymovement 0x7 ow_script_movs_0x888a24
waitmovement 0x0
loadpointer 0x0 str_0x8884e2
callstd MSG
applymovement 0x7 ow_script_movs_0x888a27
waitmovement 0x0
loadpointer 0x0 str_0x8884fb
callstd MSG
playsong MUS_KOMMT_MIT_SPIELER_WIRD_HERUMGEFUHRT 0x0
applymovement 0x7 ow_script_movs_0x888a2a
applymovement 0xff ow_script_movs_0x888a2a
waitmovement 0x0
applymovement 0xff ow_script_movs_0x888a2f
waitmovement 0x0
applymovement 0x7 ow_script_movs_0x888a36
applymovement 0xff ow_script_movs_0x888a33
waitmovement 0x0
loadpointer 0x0 str_0x888541
callstd MSG
applymovement 0x7 ow_script_movs_0x888a40
waitmovement 0x0
applymovement 0x7 ow_script_movs_0x888a36
waitmovement 0x0
applymovement 0xff ow_script_movs_0x888a39
waitmovement 0x0
savincrementkey 0xf
loadpointer 0x0 str_0x1a81da
callstd MSG_KEEPOPEN
closeonkeypress
call ow_script_0x8884c3
pause 0x5
special 0x169
pause 0x5
preparemsg str_0x1a8237
waitmsg
applymovement 0x1 ow_script_movs_0x1a951d
waitmovement 0x0
loadpointer 0x0 str_0x1a8219
callstd MSG_KEEPOPEN
applymovement 0xff ow_script_movs_0x888a33
waitmovement 0x0
loadpointer 0x0 str_0x88861b
callstd MSG
applymovement 0x7 ow_script_movs_0x888a10
waitmovement 0x0
applymovement 0x7 ow_script_movs_0x888a16
applymovement 0xff ow_script_movs_0x888a1d
waitmovement 0x0
loadpointer 0x0 str_0x888649
callstd MSG
applymovement 0x7 ow_script_movs_0x8889e6
waitmovement 0x0
applymovement 0x7 ow_script_movs_0x888a04
applymovement 0xff ow_script_movs_0x888a04
waitmovement 0x0
loadpointer 0x0 str_0x888787
callstd MSG
applymovement 0x7 ow_script_movs_0x888a43
waitmovement 0x0
pause 0x20
sound 0x41
checksound
pause 0x10
applymovement 0x7 ow_script_movs_0x888a33
waitmovement 0x0
additem ITEM_TRANK 0x1
fanfare 0x13e
loadpointer 0x0 str_0x8889cd
callstd MSG_KEEPOPEN
waitfanfare
closeonkeypress
loadpointer 0x0 str_0x88887f
callstd MSG
applymovement 0x7 ow_script_movs_0x8889fe
waitmovement 0x0
applymovement 0x7 ow_script_movs_0x8889ea
applymovement 0xff ow_script_movs_0x8889f4
waitmovement 0x0
sound 0x9
hidesprite 0x7
setflag PKMNMENU
clearflag AMONIA_RIVAL_INSIDE_PLAYER_HOUSE
applymovement 0xff ow_script_movs_0x888a3d
waitmovement 0x0
setvar STORY_PROGRESS 0xa
warp 0x3 0x1 0x3 0x0 0x0
end


ow_script_0x8884c3:
applymovement 0x1 ow_script_movs_0x1aa419
waitmovement 0x0
doanimation 0x19
nop
checkanimation 0x19
applymovement 0x1 ow_script_movs_0x1aa41f
waitmovement 0x0
special SPECIAL_HEAL
return



ow_script_movs_0x1a951d:
.byte 0x5b
.byte 0x1a
.byte STOP

ow_script_movs_0x1aa419:
.byte LOOK_LEFT_DELAYED
.byte STOP


ow_script_movs_0x1aa41f:
.byte LOOK_DOWN_DELAYED
.byte STOP

.ifdef LANG_GER

str_0x8884e2:
    .string "Da bist du ja endlich!"



str_0x8884fb:
    .string "Dies ist das Innere eines\nPokéstops. Komm mit, ich zeige dir\lalles."



str_0x888541:
    .string "Die Frau hinter dieser Theke ist\neine ausgebildete Schwester. Sie\lheilt alle Pokémon, die du derzeit\lbei dir im Team hast und verlangt\ldafür nicht einmal Geld. Willst du\les versuchen? Na Los, tu dir\lkeinen Zwang an."



str_0x88861b:
    .string "Siehst du, kinderleicht.\nDOTS\lWeiter geht\'s!"



str_0x888649:
    .string "Das ist hier ist der PC. Dort\nkannst du Pokémon und Items\llagern, wenn du mal keinen Platz\lmehr in deinem Beutel hast."



str_0x8886c2:
    .string "Diese Maschiene wird Kampfautomat\ngenannt. Sie simuliert eine echte\lKampfbegegnung, in der du deine\lPokémon trainieren kannst. Mit dem\lErwerb von Arena-Orden schaltest\ldu neue Simulationen frei."



str_0x888787:
    .string "Das hier ist die Verkaufsabteilung\neines Pokéstops. Hier kannst du\lallerlei nützliche Items kaufen.\lIch hörte, dass das Sortiment in\lallen Pokéstops gleich sein soll,\lauch wenn dieses laufend ergänzt\lwird. Hier, ich werde dir einen\lTrank kaufen."



str_0x8889cd:
    .string "PLAYER hat Trank erhalten."



str_0x88887f:
    .string "Nichts zu danken! Ein Trank füllt\ndie KP eines Pokémon wieder auf.\lWenn also mal kein Pokéstop in der\lNähe ist, sollte man immer einen\lTrank verwenden, um seine Pokémon\lzu erfrischen.\lDOTS\lGut, das sind die wichtigsten\lEinrichtungen innerhalb eines\lPokéstops. Komm mit nach draußen,\les gibt noch eine Sache, die ich\ldir zeigen will."


str_0x1a81da:
    .string "Okay, ich nehme deine Pokémon für\neinen Moment in meine Obhut."


str_0x1a8237:
    .string "Danke!\nDeine Pokémon sind wieder topfit!"
str_0x1a8219:
    .string "Komm jederzeit wieder vorbei!"

.elseif LANG_EN

.endif
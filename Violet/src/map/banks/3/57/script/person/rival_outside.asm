.include "callstds.s"
.include "movements.s"
.include "overworld_script.s"
.include "vars.s"
.include "ordinals.s"
.include "flags.s"
.include "mugshot.s"

.global ow_script_trainerschool_rival_outside
ow_script_trainerschool_rival_outside:
compare TRAINERSCHOOL_PROGRESS 3
gotoif EQUAL make_may_appear
compare TRAINERSCHOOL_PROGRESS 4
gotoif EQUAL will_receive_pkmn
compare TRAINERSCHOOL_PROGRESS 5
gotoif EQUAL catch_pokemon
compare TRAINERSCHOOL_PROGRESS 6
gotoif EQUAL catch_pokemon
compare TRAINERSCHOOL_PROGRESS 7
gotoif EQUAL battle
compare TRAINERSCHOOL_PROGRESS 8
gotoif EQUAL results
compare TRAINERSCHOOL_PROGRESS 8
gotoif HIGHER goodbye
end

goodbye:
lock
faceplayer
loadpointer 0 str_goodbye
show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT
setvar 0x8004 3
setvar 0x8005 0x28
setvar 0x8006 0x14
special 0x24
waitmovement 0
applymovement 3 mov_face_down
waitmovement 0
sound 9
hidesprite 3
checksound
pause 32
addvar TRAINERSCHOOL_GOODBYE_CNT 1
release
goto ow_script_trainerschool_finish

make_may_appear:
@ Check if may already appeared
checkflag TRAINERSCHOOL_MAY_OUTSIDE
gotoif EQUAL may_already_appeared
lock
faceplayer
loadpointer 0 str_make_may_appear
show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT
sound 0x9
checksound
showsprite 0x5
setflag TRAINERSCHOOL_MAY_OUTSIDE
setflag TRAINERSCHOOL_MAY_INSIDE
sound 0x15
applymovement LASTTALKED mov_exclam
waitmovement 0
pause 16
applymovement 0xFF mov_face_down
waitmovement 0
loadpointer 0 str_after_may_appeared
show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT
applymovement 0x3 mov_face_right
applymovement 0xFF mov_face_right
waitmovement 0

@ Move may to 0x2A, 0x12
setvar 0x8004 0x5
setvar 0x8005 0x2A
setvar 0x8006 0x11
special 0x24
waitmovement 0x0
applymovement 0x5 mov_face_left
waitmovement 0
release
end

may_already_appeared:
loadpointer 0 str_after_may_appeared_2
show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT MSG_FACE
releaseall
end

will_receive_pkmn:
loadpointer 0 str_will_receive_pkmn
show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT MSG_FACE
applymovement 0x3 mov_face_down
waitmovement 0
end

catch_pokemon:
loadpointer 0 str_catch_pkmn
show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT MSG_FACE
applymovement 0x3 mov_face_up
waitmovement 0
end


battle:
loadpointer 0 str_battle
show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT MSG_FACE
end

results:
loadpointer 0 str_results
show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT MSG_FACE
applymovement 0x3 mov_face_up
waitmovement 0
end

mov_exclam:
	.byte LOOK_DOWN, SAY_EXCLAM, STOP

mov_face_down:
	.byte LOOK_DOWN, STOP

mov_face_right:
	.byte LOOK_RIGHT, STOP

mov_face_left:
	.byte LOOK_LEFT, STOP

mov_face_up:
	.byte LOOK_UP, STOP

.ifdef LANG_GER
str_make_may_appear:
	.autostring 35 2 "PLAYER, da bist du ja!\nMal ehrlich, dieser Test war doch lachhaft, oder?\pWer soll auf solche Fragen denn antworten könnenDOTS"

str_after_may_appeared:
	.autostring 35 2 "Sieh mal, da ist Maike.\pWie es ihr wohl in dem Test ergangen ist?"

str_after_may_appeared_2:
	.autostring 35 2 "Wo bleibt denn nun Faun?\nIch bin schon ganz heiß auf diesen Feldtest!"

str_will_receive_pkmn:
	.autostring 35 2 "PLAYER! Auf jetzt!\pIch habe nicht den ganzen Tag Zeit, auf deine Entscheidung zu warten. Ich will auch ein Pokémon haben!"

str_catch_pkmn:
	.autostring 35 2 "Du brauchst für alles eine Ewigkeit!\pLos, mach schon! Fang das Pokémon ein!"

str_battle:
	.autostring 35 2 "Na los, PLAYER!\nWorauf wartest du? Ab mit dir auf deine Position und dann zeige ich dir einmal, was mein Talent alles bewirken kann!"

str_results:
	.autostring 35 2 "Viel Glück, PLAYER!\nDu wirst es brauchen!"

str_goodbye:
	.autostring 35 2 "Endlich, PLAYER! Es ist soweit! Wir sind beide Trainer!\pNun können wir endlich unseren Traum leben! Die Welt ist ein einziges Abenteuer, das wir nun endlich bestreiten dürfen!\pBist du nicht auch aufgeregt?\pNatürlich werde ich dir immer ein wenig voraus sein, das ist dir wohl klar, oder?\pWenn du mich einholen willst, solltest du dich beeilen!"

.elseif LANG_EN

.endif

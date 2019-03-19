.include "callstds.s"
.include "movements.s"
.include "overworld_script.s"
.include "vars.s"
.include "ordinals.s"
.include "flags.s"
.include "mugshot.s"

.global ow_script_trainerschool_felix_outside
ow_script_trainerschool_felix_outside:
compare TRAINERSCHOOL_PROGRESS 3
gotoif EQUAL make_faun_appear
compare TRAINERSCHOOL_PROGRESS 4
gotoif EQUAL has_received_pkmn
compare TRAINERSCHOOL_PROGRESS 5
gotoif EQUAL catch_pkmn
compare TRAINERSCHOOL_PROGRESS 6
gotoif EQUAL catch_pkmn
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
show_mugshot MUGSHOT_FELIX MUGSHOT_RIGHT
setvar 0x8004 7
setvar 0x8005 0x29
setvar 0x8006 0x14
special 0x24
waitmovement 0
applymovement 5 mov_face_down
waitmovement 0
sound 9
hidesprite 7
checksound
pause 32
addvar TRAINERSCHOOL_GOODBYE_CNT 1
release
goto ow_script_trainerschool_finish

make_faun_appear:
lock
faceplayer
loadpointer 0 str_before_faun_appeared
show_mugshot MUGSHOT_FELIX MUGSHOT_RIGHT
setflag TRAINERSCHOOL_TALKED_TO_FELIX
checkflag TRAINERSCHOOL_TALKED_TO_BLAISE
gotoif EQUAL ow_script_trainerschool_outside_faun_appears
release
end

has_received_pkmn:
loadpointer 0 str_has_received_pkmn
show_mugshot MUGSHOT_FELIX MUGSHOT_RIGHT MSG_FACE
applymovement 0x7 mov_face_down
waitmovement 0
end

catch_pkmn:
loadpointer 0 str_catch_pkmn
show_mugshot MUGSHOT_FELIX MUGSHOT_RIGHT MSG_FACE
applymovement 0x7 mov_face_up
waitmovement 0
end


battle:
loadpointer 0 str_battle
show_mugshot MUGSHOT_FELIX MUGSHOT_RIGHT MSG_FACE
end

results:
loadpointer 0 str_results
show_mugshot MUGSHOT_FELIX MUGSHOT_RIGHT MSG_FACE
applymovement 0x7 mov_face_up
waitmovement 0
end

mov_face_down:
	.byte LOOK_DOWN, STOP

mov_face_up:
	.byte LOOK_UP, STOP

.ifdef LANG_GER
str_before_faun_appeared:
	.autostring 35 2 "Opi ist manchmal schon ein seltsamer KauzDOTS\pAber vielleicht ist er gerade deshalb ein guter Lehrer!"

str_has_received_pkmn:
	.autostring 35 2 "Opi ist oft sehr streng, aber dafür ein herzensguter Mensch!\pEr ist sogar bereit, uns seine seltensten Pokémon anzuvertrauen!"

str_catch_pkmn:
	.autostring 35 2 "Keine Sorge, PLAYER.\nEs ist wirklich kinderleicht! Nur keine Scheu!"

str_battle:
	.autostring 35 2 "Lass uns unser Bestes geben, PLAYER.\pMehr können wir ohnehin nicht tun."

str_results:
	.autostring 35 2 "Ich bin ja so glücklich!\nOpi ist sicherlich stolz auf mich!"

str_goodbye:
	.autostring 35 2 "Da sind wir, PLAYER!\pWas tun wir nun?\nHast du Pläne?\pIch denke, ich werde mich auf die Suche nach Blaise machen.\pEr mag zwar wie ein Idiot wirken, aber im Grunde ist auch er nur Opfer der Tyrannei seines Vaters.\pWas solche Menschen brauchen, sind Freunde, die trotz allem zu ihnen stehen.\pFreundschaft! Das ist es, worauf es ankommt.\pMeinst du nicht auch, PLAYER?\pVielleicht werden wir uns wieder begegnen. Ich freue mich schon darauf!"

.elseif LANG_EN

.endif

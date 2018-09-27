.include "callstds.s"
.include "movements.s"
.include "overworld_script.s"
.include "vars.s"
.include "ordinals.s"
.include "flags.s"

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
call ow_script_0x89e1fc
loadpointer 0 str_goodbye
callstd MSG
special 0x7
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

results:
call ow_script_0x89e1fc
loadpointer 0 str_results
callstd MSG_FACE
special 0x7
end


battle:
call ow_script_0x89e1fc
loadpointer 0 str_battle
callstd MSG_FACE
special 0x7
end

make_faun_appear:
lock
faceplayer
call ow_script_0x89e1fc
loadpointer 0 str_before_faun_appeared
callstd MSG
special 0x7
setflag TRAINERSCHOOL_TALKED_TO_FELIX
checkflag TRAINERSCHOOL_TALKED_TO_BLAISE
gotoif EQUAL ow_script_trainerschool_outside_faun_appears
release
end

has_received_pkmn:
call ow_script_0x89e1fc
loadpointer 0 str_has_received_pkmn
callstd MSG_FACE
special 0x7
end

catch_pkmn:
call ow_script_0x89e1fc
loadpointer 0 str_catch_pkmn
callstd MSG_FACE
special 0x7
end

mov_face_down:
	.byte LOOK_DOWN, STOP

.ifdef LANG_GER
str_before_faun_appeared:
	.autostring 36 2 "Opi ist manchmal schon ein seltsamer KauzDOTS\pAber vielleicht ist er gerade deshalb ein guter Lehrer!"

str_has_received_pkmn:
	.autostring 36 2 "Opi ist oft sehr streng, aber dafür ein herzensguter Mensch!\pEr ist sogar bereit, uns seine seltensten Pokémon anzuvertrauen!"

str_catch_pkmn:
	.autostring 36 2 "Keine Sorge, PLAYER.\nEs ist wirklich kinderleicht! Nur keine Scheu!"

str_battle:
	.autostring 36 2 "Lass uns unser Bestes geben, PLAYER.\pMehr können wir ohnehin nicht tun."

str_results:
	.autostring 36 2 "Ich bin ja so glücklich!\nOpi ist sicherlich stolz auf mich!"

str_goodbye:
	.autostring 36 2 "Da sind wir, PLAYER!\pWas tun wir nun?\nHast du Pläne?\pIch denke, ich werde mich auf die Suche nach Blaise machen.\pEr mag zwar wie ein Idiot wirken, aber im Grunde ist auch er nur Opfer der Tyrannei seines Vaters.\pWas solche Menschen brauchen, sind Freunde, die trotz allem zu ihnen stehen.\pFreundschaft! Das ist es, worauf es ankommt.\pMeinst du nicht auch, PLAYER?\pVielleicht werden wir uns wieder begegnen. Ich freue mich schon darauf!"

.elseif LANG_EN

.endif

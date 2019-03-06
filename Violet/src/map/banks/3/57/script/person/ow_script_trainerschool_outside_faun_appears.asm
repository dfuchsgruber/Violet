.include "callstds.s"
.include "movements.s"
.include "overworld_script.s"
.include "vars.s"
.include "ordinals.s"
.include "flags.s"

.global ow_script_trainerschool_outside_faun_appears
ow_script_trainerschool_outside_faun_appears:
lockall
showsprite 4
sound 9
checksound
setflag TRAINERSCHOOL_FAUN_OUTSIDE
setflag TRAINERSCHOOL_FAUN_INSIDE
sound 0x15
applymovement 0xFF mov_exclam
applymovement 3 mov_exclam
applymovement 5 mov_exclam
applymovement 6 mov_exclam
applymovement 7 mov_exclam
waitmovement 0x0

call ow_script_0x89c5ee
loadpointer 0 str_faun_appears
callstd MSG
special 0x7

@ Move npcs into a row
applymovement 3 mov_2l_2d
applymovement 5 mov_1d
setvar 0x8004 0xFF
setvar 0x8005 0x27
setvar 0x8006 0x12
special 0x24
waitmovement 0x0
applymovement 0x3 mov_face_down
applymovement 0x5 mov_face_down
applymovement 0xFF mov_face_down
waitmovement 0x0
call ow_script_0x89c5ee
loadpointer 0 str_faun_announces_pkmn
callstd MSG
special 0x7
lockall // prevents the 'moonwalk bug'
pause 40
applymovement 4 mov_smile
waitmovement 0
call ow_script_0x89c5ee
loadpointer 0 str_call_blaise
callstd MSG
special 0x7

@ Move Blaise to Faun
applymovement 6 mov_1d
waitmovement 0
pause 32
applymovement 6 mov_dinplace
waitmovement 0
call ow_script_0x89e33c
loadpointer 0 str_blaise_received_pkmn
callstd MSG
special 0x7
applymovement 6 mov_blaise_back
waitmovement 0

call ow_script_0x89c5ee
loadpointer 0 str_call_felix
callstd MSG
special 0x7

@ Move Felix to Faun
applymovement 7 mov_felix_to_faun
waitmovement 0
pause 32
applymovement 7 mov_dinplace
waitmovement 0
call ow_script_0x89e1fc
loadpointer 0 str_felix_received_pkmn
callstd MSG
special 0x7
sound 0x15
applymovement 4 mov_double_exclam
waitmovement 4
call ow_script_0x89c5ee
loadpointer 0 str_angry_at_felix
callstd MSG
special 0x7
call ow_script_0x89e1fc
loadpointer 0 str_felix_apologize
callstd MSG
special 0x7
call ow_script_0x89c5ee
loadpointer 0 str_after_felix
callstd MSG
special 0x7
applymovement 7 mov_felix_back
waitmovement 0

call ow_script_0x89c5ee
loadpointer 0 str_call_player
callstd MSG
special 0x7
addvar TRAINERSCHOOL_PROGRESS 1
releaseall
end

mov_felix_back:
	.byte STEP_LEFT, STEP_UP, LOOK_DOWN, STOP

mov_felix_to_faun:
	.byte STEP_DOWN, STEP_RIGHT, LOOK_DOWN, STOP

mov_blaise_back:
	.byte STEP_UP, LOOK_DOWN, STOP

mov_dinplace:
	.byte STEP_IN_PLACE_DOWN, STEP_IN_PLACE_DOWN, STOP

mov_smile:
	.byte SAY_SMILE, STOP

mov_1d:
	.byte STEP_DOWN, STOP

mov_2l_2d:
	.byte STEP_LEFT, STEP_LEFT, STEP_DOWN, STEP_DOWN, STOP

mov_exclam:
	.byte LOOK_DOWN, SAY_EXCLAM, STOP

mov_double_exclam:
	.byte SAY_DOUBLE_EXCLAM, STOP

mov_face_down:
	.byte LOOK_DOWN, STOP


.ifdef LANG_GER
str_faun_appears:
	.autostring 35 2 "So, ihr Grünschnäbel!\pJetzt wird es ernst, wir beginnen mit dem Feldtest.\pAlle in einer Reihe aufstellen!"

str_faun_announces_pkmn:
	.autostring 35 2 "Der Feldtest setzt sich aus zwei Komponenten zusammen.\pZuerst müsst ihr ein wildes Pokémon einfangen.\pIm Anschluss werdet ihr dann gegeneinander im Kampf antreten.\pZuallererst aber erhaltet ihr von mir ein Pokémon, das euch fortan unterstützen wird. Es ist von nun an euer wichtigster Partner und Freund, den ihr zu respektieren habt."

str_call_blaise:
	.autostring 35 2 "Blaise, du bist der Erste.\pKomm nach vorne und wähle eines der Pokémon, die ich mitgebracht habe."

str_blaise_received_pkmn:
	.autostring 35 2 "Ich bin wirklich überrascht, dass man uns so seltene Examplare anvertrautDOTS"

str_call_felix:
	.autostring 35 2 "Als nächstes bist du an der Reihe, Felix.\pKomm zu mir und such dir ein Pokémon aus, Kleiner!"

str_felix_received_pkmn:
	.autostring 35 2 "Alles klar, Opi!\nIch wähle dieses hier!"

str_angry_at_felix:
	.autostring 35 2 "Ich habe dir schon tausendmal gesagt, dass du mich hier Herr Faun zu nennen hast, Rotzlöffel!"

str_felix_apologize:
	.autostring 35 2 "ÄhmDOTS Tut mir wirklich leid, Herr Faun! Ehrlich!"

str_after_felix:
	.autostring 35 2 "Schon gut, schon gutDOTS\pZurück mit dir in die Reihe, Felix!"

str_call_player:
	.autostring 35 2 "Nun denn, PLAYER, komm zu mir!"

.elseif LANG_EN

.endif

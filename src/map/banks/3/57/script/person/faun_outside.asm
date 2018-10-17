.include "callstds.s"
.include "movements.s"
.include "overworld_script.s"
.include "vars.s"
.include "ordinals.s"
.include "flags.s"
.include "items.s"
.include "songs.s"

.global ow_script_trainerschool_faun_outside
ow_script_trainerschool_faun_outside:
compare TRAINERSCHOOL_PROGRESS 4
gotoif EQUAL receive_pkmn
compare TRAINERSCHOOL_PROGRESS 5
gotoif EQUAL receive_pokeballs
compare TRAINERSCHOOL_PROGRESS 6
gotoif EQUAL catch_pokemon
compare TRAINERSCHOOL_PROGRESS 7
gotoif EQUAL battle
compare TRAINERSCHOOL_PROGRESS 8
gotoif EQUAL results
end

results:
lock
faceplayer
buffernumber 0 TRAINERSCHOOL_CORRECT_ANSWERS
call ow_script_0x89c5ee
loadpointer 0 str_results_player
callstd MSG
special 0x7
fanfare 0x13E
waitfanfare
call ow_script_0x89c5ee
loadpointer 0 str_player_back
callstd MSG
special 0x7
setvar 0x8004 0xFF
setvar 0x8005 0x29
setvar 0x8006 0x11
special 0x24
waitmovement 0
applymovement 0xFF mov_face_up
applymovement 4 mov_face_down
waitmovement 0
applymovement 3 mov_result_rival_to_faun
waitmovement 0
call ow_script_0x89ba6e
loadpointer 0 str_rival_results
callstd MSG
special 0x7
call ow_script_0x89c5ee
loadpointer 0 str_results_rival
callstd MSG
special 0x7
fanfare 0x13E
waitfanfare
call ow_script_0x89ba6e
loadpointer 0 str_rival_glad
callstd MSG
special 0x7
applymovement 3 mov_result_rival_back
waitmovement 0
call ow_script_0x89c5ee
loadpointer 0 str_call_may
callstd MSG
special 0x7
call ow_script_0x89db71
loadpointer 0 str_may_insecure
callstd MSG
special 0x7
applymovement 5 mov_result_may_to_faun
waitmovement 0
call ow_script_0x89c5ee
loadpointer 0 str_results_may
callstd MSG
special 0x7
call ow_script_0x89db71
loadpointer 0 str_may_understands
callstd MSG
special 0x7
call ow_script_0x89c5ee
loadpointer 0 str_results_may2
callstd MSG
special 0x7
fanfare 0x13E
waitfanfare
call ow_script_0x89db71
loadpointer 0 str_may_glad
callstd MSG
special 0x7
applymovement 5 mov_result_may_back
waitmovement 0
call ow_script_0x89c5ee
loadpointer 0 str_final_talk
callstd MSG
special 0x7
applymovement 4 mov_faun_leaves
waitmovement 0
applymovement 3 mov_face_down
applymovement 5 mov_face_down
applymovement 7 mov_face_down
applymovement 0xFF mov_face_down
waitmovement 0
sound 0x9
hidesprite 4
checksound
pause 32
addvar TRAINERSCHOOL_PROGRESS 1
release
end

battle:
call ow_script_0x89c5ee
loadpointer 0 str_battle
callstd MSG_FACE
special 0x7
end

receive_pkmn:
call ow_script_0x89c5ee
loadpointer 0 str_show_player_pkmn
callstd MSG
special 0x7
callasm trainerschool_selection_init
waitstate
copyvar 0x8004 LASTRESULT
bufferpokemon 0x0 LASTRESULT
givepokemon 0x8004 0x5 ITEM_SINELBEERE 0x0 0x0 0x0
fanfare 0x13e
loadpointer 0x0 str_player_received_b1
callstd MSG_KEEPOPEN
waitfanfare
closeonkeypress
call ow_script_0x893bb5
setflag PKMNMENU
special 0x16F

@ player has received their pkmn, move them back

call ow_script_0x89c5ee
loadpointer 0 str_player_received_pkmn
callstd MSG
special 0x7
setvar 0x8004 0xFF
setvar 0x8005 0x27
setvar 0x8006 0x12
special 0x24
waitmovement 0
applymovement 0xFF mov_face_down
waitmovement 0

call ow_script_0x89c5ee
loadpointer 0 str_rival_picks
callstd MSG
special 0x7
applymovement 0x3 mov_rival_to_faun
waitmovement 0x0
pause 32
applymovement 0x3 mov_dinplace
waitmovement 0
call ow_script_0x89ba6e
loadpointer 0 str_rival_says_thanks
callstd MSG
special 0x7
applymovement 0x3 mov_rival_back
waitmovement 0

@ May comes to Faun
call ow_script_0x89c5ee
loadpointer 0 str_may_picks
callstd MSG
special 0x7
call ow_script_0x89db71
loadpointer 0 str_may_disappointed
callstd MSG
special 0x7
applymovement 0x5 mov_may_to_faun
waitmovement 0
pause 32
applymovement 0x5 mov_dinplace
waitmovement 0
call ow_script_0x89c5ee
loadpointer 0 str_may_received_pkmn
callstd MSG
special 0x7
call ow_script_0x89db71
loadpointer 0 str_may_dots
callstd MSG
special 0x7
applymovement 0x5 mov_may_back
waitmovement 0

@ Initiate the catch sequence
call ow_script_0x89c5ee
loadpointer 0 str_to_tall_grass
callstd MSG
special 0x7

@ Move the npcs to the tall grass
applymovement 0x4 mov_faun_to_grass_1
waitmovement 0
applymovement 0x3 mov_rival_to_grass
applymovement 0x5 mov_may_to_grass
applymovement 0x6 mov_rival_to_grass @ same movement as rival
applymovement 0x7 mov_blaise_to_grass
applymovement 0x4 mov_faun_to_grass_2
applymovement 0xFF mov_player_to_grass
waitmovement 0
call ow_script_0x89c5ee
loadpointer 0 str_tall_grass
callstd MSG
special 0x7
@ Blaise leaves
fadesong 0
pause 64
call ow_script_0x89c5ee
loadpointer 0 str_call_blaise
callstd MSG
special 0x7
pause 32
call ow_script_0x89e33c
loadpointer 0 str_blaise_refuses
callstd MSG
special 0x7
sound 0x15
applymovement 0x4 mov_exclam
applymovement 0x3 mov_right_exclam
applymovement 0xFF mov_right_exclam
applymovement 0x5 mov_left_exclam
applymovement 0x7 mov_right_exclam
waitmovement 0
call ow_script_0x89c5ee
loadpointer 0 str_call_blaise_again
callstd MSG
special 0x7
call ow_script_0x89e33c
loadpointer 0 str_blaise_leaves
callstd MSG
special 0x7
applymovement 0x3 mov_face_down
applymovement 0xFF mov_face_down
applymovement 0x5 mov_face_down
applymovement 0x7 mov_face_down
applymovement 0x6 mov_blaise_away
waitmovement 0
sound 0x9
hidesprite 0x6
checksound
pause 32
call ow_script_0x89c5ee
loadpointer 0 str_faun_angry_at_blaise
callstd MSG
special 0x7
pause 40
fadesong MUS_TRAINERSCHOOL

@ Continue with field test
applymovement 0x3 mov_face_up
applymovement 0xFF mov_face_up
applymovement 0x5 mov_face_up
applymovement 0x7 mov_face_up
call ow_script_0x89c5ee
loadpointer 0 str_continue_with_field_test
callstd MSG
special 0x7
@ Felix catches his pkmn
call ow_script_0x89e1fc
loadpointer 0 str_felix_starts_test
callstd MSG
special 0x7
applymovement 0x7 mov_felix_to_faun
waitmovement 0
call ow_script_0x89c5ee
loadpointer 0 str_hand_felix_balls
callstd MSG
special 0x7
applymovement 0x7 mov_uinplace
waitmovement 0x0
applymovement 0x4 mov_face_up
applymovement 0x7 mov_felix_into_grass
waitmovement 0
pause 40
sound 10
applymovement 0x7 mov_double_jump
waitmovement 0
checksound
sound 10
applymovement 0x7 mov_double_jump
waitmovement 0
checksound
call ow_script_0x89e1fc
loadpointer 0 str_felix_done_catching
callstd MSG
special 0x7
call ow_script_0x89c5ee
loadpointer 0 str_faun_admires_felix
callstd MSG
special 0x7
applymovement 0x4 mov_face_down
applymovement 0x7 mov_felix_catching_back
waitmovement 0
call ow_script_0x89c5ee
loadpointer 0 str_faun_calls_player
callstd MSG
special 0x7
addvar TRAINERSCHOOL_PROGRESS 1
releaseall
end

receive_pokeballs:
@ This state means you receive pokeballs from him
lock
faceplayer
setflag BLACKOUT_BYPASS
setflag CAUGHT_POKEDEX_DISABLE
removeitem ITEM_POKEBALL 5
call ow_script_0x89c5ee
loadpointer 0 str_player_receives_pokeballs
callstd MSG
special 0x7
additem ITEM_POKEBALL 5
fanfare 0x101
loadpointer 0x0 str_pokeball_obtention_message
callstd MSG_KEEPOPEN
waitfanfare
closeonkeypress
addvar TRAINERSCHOOL_PROGRESS 1
setvar TRAINERSCHOOL_ALLOWED_TO_ENTER_GRASS 1
releaseall
end

catch_pokemon:
@ This state means the player is to catch wild pokemon as he already has balls
call ow_script_0x89c5ee
loadpointer 0 str_player_has_to_catch
callstd MSG_FACE
special 0x7
end

mov_faun_leaves:
	.byte STEP_LEFT, STEP_LEFT, STEP_DOWN, STEP_DOWN, STEP_DOWN, STEP_DOWN, STEP_RIGHT, STEP_DOWN, STOP

mov_result_may_back:
	.byte STEP_RIGHT, STEP_RIGHT, STEP_DOWN, LOOK_UP, STOP

mov_result_may_to_faun:
	.byte STEP_UP, STEP_LEFT, STEP_LEFT, LOOK_UP, STOP

mov_result_rival_back:
	.byte STEP_LEFT, STEP_DOWN, LOOK_UP, STOP

mov_result_rival_to_faun:
	.byte STEP_UP, STEP_RIGHT, LOOK_UP, STOP

mov_felix_catching_back:
	.byte STEP_DOWN, STEP_DOWN, STEP_RIGHT, STEP_DOWN, LOOK_UP, STOP

mov_double_jump:
	.byte JUMP_IN_PLACE_FACE_UP, STOP

mov_felix_into_grass:
	.byte STEP_LEFT, STEP_UP, STEP_UP, STOP

mov_face_up:
	.byte LOOK_UP, STOP

mov_felix_to_faun:
	.byte STEP_UP, STOP

mov_blaise_away:
	.byte STEP_DOWN, STEP_DOWN, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STEP_DOWN, STEP_DOWN, STOP

mov_right_exclam:
	.byte LOOK_RIGHT, SAY_EXCLAM, STOP

mov_left_exclam:
	.byte LOOK_LEFT, SAY_EXCLAM, STOP

mov_exclam:
	.byte SAY_EXCLAM, STOP

mov_faun_to_grass:
	.byte STEP_UP, STEP_UP, STOP

mov_blaise_to_grass:
	.byte STEP_UP, STEP_LEFT, STEP_LEFT, STEP_LEFT, STEP_LEFT, STEP_LEFT, STEP_UP, STOP

mov_may_to_grass:
	.byte STEP_LEFT, STEP_LEFT, STEP_LEFT, STEP_UP, STEP_LEFT, STEP_LEFT, STEP_UP, STOP

mov_player_to_grass:
	.byte STEP_LEFT, STEP_UP, STEP_LEFT, STEP_LEFT, STEP_LEFT, STEP_LEFT, STEP_UP, STOP

mov_rival_to_grass:
	.byte STEP_LEFT, STEP_LEFT, STEP_LEFT, STEP_LEFT, STEP_LEFT, STEP_UP, STEP_UP, STOP

mov_faun_to_grass_2:
	.byte STEP_UP, STEP_UP, STEP_LEFT, STEP_UP, LOOK_DOWN, STOP

mov_faun_to_grass_1:
	.byte STEP_UP, STEP_LEFT, STEP_LEFT, STEP_LEFT, STEP_LEFT, STEP_LEFT, STEP_UP, STEP_UP, STOP

mov_rival_back:
	.byte STEP_LEFT, STEP_LEFT, STEP_LEFT, STEP_UP, LOOK_DOWN, STOP

mov_face_down:
	.byte LOOK_DOWN, STOP

mov_rival_to_faun:
	.byte STEP_DOWN, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, LOOK_DOWN, STOP

mov_dinplace:
	.byte STEP_IN_PLACE_DOWN, STEP_IN_PLACE_DOWN, STOP

mov_uinplace:
	.byte STEP_IN_PLACE_UP, STEP_IN_PLACE_UP, STOP

mov_may_to_faun:
	.byte STEP_DOWN, STEP_LEFT, LOOK_DOWN, STOP

mov_may_back:
	.byte STEP_RIGHT, STEP_UP, LOOK_DOWN, STOP

.ifdef LANG_GER

str_show_player_pkmn:
	.autostring 36 2 "Also PLAYER, bleiben noch drei Pokémon, aus denen du wählen kannst. Triff deine Entscheidung mit Bedacht!"

str_player_received_b1:
    .string "PLAYER hat ein BUFFER_1\nerhalten!"

str_player_received_pkmn:
	.autostring 36 2 "Ah, ein BUFFER_1,\neine sehr gute Wahl!\pNun aber zurück mit dir in die Reihe!"

str_rival_picks:
	.autostring 36 2 "So, RIVAL, jetzt ist es an der Zeit für dich, zu wählen!"

str_rival_says_thanks:
	.autostring 36 2 "Dieses Pokémon ist perfekt. Damit werde ich unschlagbar sein!"

str_may_picks:
	.autostring 36 2 "Nun denn, Maike, zuletzt bist du an der Reihe."

str_may_disappointed:
	.autostring 36 2 "Dass auch ausgerechnet ich das letzte Pokémon bekommen mussDOTS"

str_may_received_pkmn:
	.autostring 36 2 "Ich hoffe, dass du mit deinem Pokemon zufrieden bist."

str_may_dots:
	.autostring 36 2 "DOTS\nSicher, Herr Faun!"

str_to_tall_grass:
	.autostring 36 2 "Dann hätten wir das erledigt!\pBeginnen wir mit dem ersten Feldtest. Folgt mir zum hohen Gras."

str_tall_grass:
	.autostring 36 2 "Im ersten Teil der Feldprüfung werdet ihr ein wildes Pokémon einfangen. Ihr habt alle gelernt, wie das funktioniert. Ich erwarte, dass ihr das ohne Mühe auf die Reihe bekommt!\pBlaise, du beginnst."

str_call_blaise:
	.autostring 36 2 "Blaise, na wird's bald?\pBeweg dich hierher, du kleiner Rotzlöffel!"

str_blaise_refuses:
	.autostring 36 2 "Nein, ich denke eher nicht."

str_call_blaise_again:
	.autostring 36 2 "Wie bitte? Du undankbares Gör! Wer glaubst du denn, dass du bist? Meinst du, dein Vater wird es gerne hören, dass du mir Ungehorsam leistest?"

str_blaise_leaves:
	.autostring 36 2 "Es ist mir herzlich egal, was mein Vater denkt. Ich habe beschlossen, mich nicht länger von ihm kontrollieren zu lassen. Also ist mir Ihre Abschlussprüfung ebenfalls gleichgültig. Natürlich danke ich Ihnen auch, für das Pokémon, das sie mir anvertraut haben. Allerdings halte ich nichts von dieser Schule oder anderen Institutionen, in denen mein Vater seine Finger im Spiel hat.\pIn diesem Sinne, lebt wohl!"

str_faun_angry_at_blaise:
	.autostring 36 2 "Dieser verdammte Bengel! Devin wird außer sich sein!"

str_continue_with_field_test:
	.autostring 36 2 "DOTS DOTS\nSein Vater wird dem Jungen schon noch Vernunft beibringen.\pLassen wir uns aber von diesem Vorfall nicht irritieren.\pFelix, dann beginnst du eben die Prüfung."

str_felix_starts_test:
	.autostring 36 2 "Jawohl, Opi -\nÄhmDOTS Herr Faun!"

str_hand_felix_balls:
	.autostring 36 2 "Du erhältst von mir fünf Pokébälle.\pVersuche, ein Pokémon mit ihnen einzufangen."

str_felix_done_catching:
	.autostring 36 2 "Geschafft!"

str_faun_admires_felix:
	.autostring 36 2 "Sehr gut, Kleiner! So will ich das sehen!\pZurück mit dir in die Reihe!"

str_faun_calls_player:
	.autostring 36 2 "PLAYER, jetzt musst du dein Können unter Beweis stellen.\pKomm her zu mir."

str_player_receives_pokeballs:
	.autostring 36 2 "PLAYER, du erhältst jetzt von mir fünf Pokébälle.\pVersuche auch du, das Pokémon einzufangen!"

str_pokeball_obtention_message:
	.autostring 36 2 "Fünf Pokébälle erhalten."

str_player_has_to_catch:
	.autostring 36 2 "PLAYER! Begib dich endlich ins hohe Gras!"

str_battle:
	.autostring 36 2 "Was treibst du denn da, PLAYER?\pAb mit dir auf deine Position!"

str_results_player:
	.autostring 36 2 "Na, wollen wir doch mal sehen, PLAYER!\pDie theoretische Prüfung hast du mit BUFFER_1 korrekten Antworten absolviert.\pDu konntest ein Pokémon fangen und hast dich im Kampf bewiesen!\pAuch dir darf ich gratulieren, Kind!\pDu bist nun ein echter Trainer!"

str_player_back:
	.autostring 36 2 "Reihe dich wieder ein, PLAYER.\pAls nächstes ist RIVAL dran!"

str_rival_results:
	.autostring 36 2 "Diese Spannung ist ja kaum auszuhalten!"

str_results_rival:
	.autostring 36 2 "Im schriftlichen Test hast du keine einzige Frage richtig beantwortetDOTS\pDafür warst du ein echtes Naturtalent im Umgang mit Pokémon.\pWeder Kämpfen noch Fangen haben dir Schwierigkeiten bereitet.\pWeil du dein kümmerliches Wissen offenbar recht gut mit Fertigkeiten ausgleichen kannst, bin ich gewillt, auch dir zu gratulieren.\pAuch du darfst dich reinsten Gewissens einen Trainer nennen!"

str_rival_glad:
	.autostring 36 2 "Alles andere hätte mich auch überrascht!\pDanke, Herr Faun!"

str_call_may:
	.autostring 36 2 "Also dann! Zum Schluss bist du an der Reihe, Maike.\pKomm zu mir!"

str_may_insecure:
	.autostring 36 2 "O-Ojee!"

str_results_may:
	.autostring 36 2 "Nun gut.\nIm schriftlichen Test hast du immerhin drei Antworten richtig beantworten können.\pIm Feldtest hast du dich nicht schlecht geschlagen, aber du bist nicht besonders sicher im Umgang mit Pokémon.\pMaike! Wenn du als Trainer bestehen willst, musst du Vertrauen in dich und deine Pokémon finden."

str_may_understands:
	.autostring 36 2 "I-Ich verstehe, Herr FaunDOTS\pEs t-tut mir leid."

str_results_may2:
	.autostring 36 2 "Ich bin aber überzeugt, dass du das Zeug hast, ein erfolgreicher Pokémon-Trainer zu sein.\pImmerhin warst du meine Schülerin.\pDaher darf ich auch dir gratulieren, du hast deine Prüfungen bestanden!"

str_may_glad:
	.autostring 36 2 "W-Wirklich?\nDas ist fantastisch!\pJetzt werde ich meinen Freund aus Hoenn aufholen können!"

str_final_talk:
	.autostring 36 2 "Hach! Wie die Zeit an einem vorbeifliegt!\pFür mich seid ihr noch immer die kleinen Rotzlöffel, die leichtsinnig ins hohe Gras gerannt wären, hätte man sie nicht davon abgehalten.\pAber nunDOTS\nSeid ihr zu fähigen Trainern herangewachsen.\pIch könnte nicht zufriedener mit euch sein. Allerdings ist dies erst der Anfang, ihr Bälger!\pWenn ihr diese Schule heute verlasst, werdet ihr auf euch allein gestellt sein.\pWobei auch das nicht ganz zutrifft, denn ihr habt nun eure Pokémon als Partner an eurer Seite.\pWisst diesen besonderen Bund zwischen Trainer und Pokémon zu schätzen, Kinder!\pIch bin überzeugt, dass ihr es weit bringen könnt.\pMacht mich stolz, euer Lehrer gewesen zu sein!\pIn diesem Sinne, viel Erfolg auf eurer Reise, Kinder!"

.elseif LANG_EN

.endif

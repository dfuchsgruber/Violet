.include "vars.s"
.include "movements.s"
.include "callstds.s"
.include "songs.s"
.include "mugshot.s"
.include "ordinals.s"
.include "overworld_script.s"
.include "flags.s"
.include "items.s"

.global ow_script_trainerschool_rival_outside
.global ow_script_trainerschool_faun_outside
.global ow_script_trainerschool_maike_outside
.global ow_script_trainerschool_blaise_outside
.global ow_script_trainerschool_felix_outside


ow_script_trainerschool_blaise_outside:
compare TRAINERSCHOOL_PROGRESS 3
gotoif EQUAL make_faun_appear_outside
compare TRAINERSCHOOL_PROGRESS 4
gotoif EQUAL has_received_pkmn


make_faun_appear_outside:
lock
faceplayer
loadpointer 0 str_before_faun_appeared
show_mugshot MUGSHOT_BLAISE MUGSHOT_RIGHT
setflag TRAINERSCHOOL_TALKED_TO_BLAISE
checkflag TRAINERSCHOOL_TALKED_TO_FELIX
gotoif EQUAL ow_script_trainerschool_outside_faun_appears
release
end

has_received_pkmn:
lock
loadpointer 0 str_has_received_pkmn
show_mugshot MUGSHOT_BLAISE MUGSHOT_RIGHT MSG_FACE
applymovement 0x6 mov_face_down
waitmovement 0
release
end

.ifdef LANG_GER
str_before_faun_appeared:
	.autostring 35 2 "Wirklich eine Unverschämtheit, dass uns der Knacker nach diesem Test auch noch warten lässtDOTS\pMein Vater hätte mich nie auf diese Schule schicken dürfenDOTS"

str_has_received_pkmn:
	.autostring 35 2 "Scheint, als hätte diese Schule doch ihr Gutes.\pEin solches Pokémon sieht man nicht alle TageDOTS"

.elseif LANG_EN

.endif

ow_script_trainerschool_faun_outside:
compare TRAINERSCHOOL_PROGRESS 4
gotoif EQUAL receive_pkmn
compare TRAINERSCHOOL_PROGRESS 5
gotoif EQUAL receive_pokeballs
compare TRAINERSCHOOL_PROGRESS 6
gotoif EQUAL catch_pokemon
compare TRAINERSCHOOL_PROGRESS 7
gotoif EQUAL battle_faun
compare TRAINERSCHOOL_PROGRESS 8
gotoif EQUAL results
end

results:
lock
faceplayer
buffernumber 0 TRAINERSCHOOL_CORRECT_ANSWERS
loadpointer 0 str_results_player
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
fanfare 0x13E
waitfanfare
loadpointer 0 str_player_back
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
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
loadpointer 0 str_rival_results
show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT
loadpointer 0 str_results_rival2
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
fanfare 0x13E
waitfanfare
loadpointer 0 str_rival_glad
show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT
applymovement 3 mov_result_rival_back
waitmovement 0
loadpointer 0 str_call_may
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
loadpointer 0 str_may_insecure
show_mugshot MUGSHOT_MAY MUGSHOT_RIGHT
applymovement 5 mov_result_may_to_faun
waitmovement 0
loadpointer 0 str_results_may
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
loadpointer 0 str_may_understands
show_mugshot MUGSHOT_MAY MUGSHOT_RIGHT
loadpointer 0 str_results_may2
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
fanfare 0x13E
waitfanfare
loadpointer 0 str_may_glad
show_mugshot MUGSHOT_MAY MUGSHOT_RIGHT
applymovement 5 mov_result_may_back
waitmovement 0
loadpointer 0 str_final_talk
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
applymovement 4 mov_faun_leaves_1
waitmovement 0
applymovement 3 mov_face_down
applymovement 5 mov_face_down
applymovement 7 mov_face_down
applymovement 0xFF mov_face_down
applymovement 4 mov_faun_leaves_2
waitmovement 0
sound 0x9
hidesprite 4
checksound
pause 32
addvar TRAINERSCHOOL_PROGRESS 1
release
end

battle_faun:
loadpointer 0 str_battle_faun
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT MSG_FACE
end

receive_pkmn:
loadpointer 0 str_show_player_pkmn
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
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
call ow_script_set_nickname
setflag PKMNMENU
special 0x16F

@ player has received their pkmn, move them back

loadpointer 0 str_player_received_pkmn
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
setvar 0x8004 0xFF
setvar 0x8005 0x27
setvar 0x8006 0x12
special 0x24
waitmovement 0
applymovement 0xFF mov_face_down
waitmovement 0

loadpointer 0 str_rival_picks
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
applymovement 0x3 mov_rival_to_faun
waitmovement 0x0
pause 32
applymovement 0x3 mov_dinplace
waitmovement 0
loadpointer 0 str_rival_says_thanks
show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT
applymovement 0x3 mov_rival_back
waitmovement 0

@ May comes to Faun
loadpointer 0 str_may_picks
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
loadpointer 0 str_may_disappointed
show_mugshot MUGSHOT_MAY MUGSHOT_RIGHT
applymovement 0x5 mov_may_to_faun
waitmovement 0
pause 32
applymovement 0x5 mov_dinplace
waitmovement 0
loadpointer 0 str_may_received_pkmn
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
loadpointer 0 str_may_dots
show_mugshot MUGSHOT_MAY MUGSHOT_RIGHT
applymovement 0x5 mov_may_back
waitmovement 0

@ Initiate the catch sequence
loadpointer 0 str_to_tall_grass
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT

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
loadpointer 0 str_tall_grass
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
@ Blaise leaves
fadesong 0
pause 64
loadpointer 0 str_call_blaise
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
pause 32
loadpointer 0 str_blaise_refuses
show_mugshot MUGSHOT_BLAISE MUGSHOT_RIGHT
sound 0x15
applymovement 0x4 mov_exclam
applymovement 0x3 mov_right_exclam
applymovement 0xFF mov_right_exclam
applymovement 0x5 mov_left_exclam
applymovement 0x7 mov_right_exclam
waitmovement 0
loadpointer 0 str_call_blaise_again
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
loadpointer 0 str_blaise_leaves
show_mugshot MUGSHOT_BLAISE MUGSHOT_RIGHT
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
loadpointer 0 str_faun_angry_at_blaise
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
pause 40
fadesong MUS_TRAINERSCHOOL

@ Continue with field test
applymovement 0x3 mov_face_up
applymovement 0xFF mov_face_up
applymovement 0x5 mov_face_up
applymovement 0x7 mov_face_up
loadpointer 0 str_continue_with_field_test
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
@ Felix catches his pkmn
loadpointer 0 str_felix_starts_test
show_mugshot MUGSHOT_FELIX MUGSHOT_RIGHT
applymovement 0x7 mov_felix_to_faun2
waitmovement 0
loadpointer 0 str_hand_felix_balls
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
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
loadpointer 0 str_felix_done_catching
show_mugshot MUGSHOT_FELIX MUGSHOT_RIGHT
loadpointer 0 str_faun_admires_felix
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
applymovement 0x4 mov_face_down
applymovement 0x7 mov_felix_catching_back
waitmovement 0
loadpointer 0 str_faun_calls_player
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
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
loadpointer 0 str_player_receives_pokeballs
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
additem ITEM_POKEBALL 5
fanfare 0x101
loadpointer 0x0 str_pokeball_obtention_message
callstd MSG_KEEPOPEN
waitfanfare
closeonkeypress
applymovement 0x4 mov_face_up
waitmovement 0x0
addvar TRAINERSCHOOL_PROGRESS 1
setvar TRAINERSCHOOL_ALLOWED_TO_ENTER_GRASS 1
releaseall
end

catch_pokemon:
@ This state means the player is to catch wild pokemon as he already has balls
loadpointer 0 str_player_has_to_catch
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT MSG_FACE
applymovement 0x4 mov_face_up
waitmovement 0x0
end

mov_faun_leaves_1:
	.byte STEP_LEFT, STEP_LEFT, STEP_DOWN, STEP_DOWN, STOP

mov_faun_leaves_2:
	.byte STEP_DOWN, STEP_DOWN, STEP_RIGHT, STEP_DOWN, STOP

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

mov_felix_to_faun2:
	.byte STEP_UP, STOP

mov_blaise_away:
	.byte STEP_DOWN, STEP_DOWN, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STEP_DOWN, STEP_DOWN, STOP

mov_right_exclam:
	.byte LOOK_RIGHT, SAY_EXCLAM, STOP

mov_left_exclam:
	.byte LOOK_LEFT, SAY_EXCLAM, STOP

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
	.autostring 35 2 "Also PLAYER, bleiben noch drei Pokémon, aus denen du wählen kannst. Triff deine Entscheidung mit Bedacht!"

str_player_received_b1:
    .string "PLAYER hat ein BUFFER_1\nerhalten!"

str_player_received_pkmn:
	.autostring 35 2 "Ah, ein BUFFER_1,\neine sehr gute Wahl!\pNun aber zurück mit dir in die Reihe!"

str_rival_picks:
	.autostring 35 2 "So, RIVAL, jetzt ist es an der Zeit für dich, zu wählen!"

str_rival_says_thanks:
	.autostring 35 2 "Dieses Pokémon ist perfekt. Damit werde ich unschlagbar sein!"

str_may_picks:
	.autostring 35 2 "Nun denn, Maike, zuletzt bist du an der Reihe."

str_may_disappointed:
	.autostring 35 2 "Dass auch ausgerechnet ich das letzte Pokémon bekommen mussDOTS"

str_may_received_pkmn:
	.autostring 35 2 "Ich hoffe, dass du mit deinem Pokemon zufrieden bist."

str_may_dots:
	.autostring 35 2 "DOTS\nSicher, Herr Faun!"

str_to_tall_grass:
	.autostring 35 2 "Dann hätten wir das erledigt!\pBeginnen wir mit dem ersten Feldtest. Folgt mir zum hohen Gras."

str_tall_grass:
	.autostring 35 2 "Im ersten Teil der Feldprüfung werdet ihr ein wildes Pokémon einfangen. Ihr habt alle gelernt, wie das funktioniert. Ich erwarte, dass ihr das ohne Mühe auf die Reihe bekommt!\pBlaise, du beginnst."

str_call_blaise:
	.autostring 35 2 "Blaise, na wird's bald?\pBeweg dich hierher, du kleiner Rotzlöffel!"

str_blaise_refuses:
	.autostring 35 2 "Nein, ich denke eher nicht."

str_call_blaise_again:
	.autostring 35 2 "Wie bitte? Du undankbares Gör! Was glaubst du denn, wer du bist? Meinst du, dein Vater wird es gerne hören, dass du mir Ungehorsam leistest?"

str_blaise_leaves:
	.autostring 35 2 "Es ist mir herzlich egal, was mein Vater denkt. Ich habe beschlossen, mich nicht länger von ihm kontrollieren zu lassen. Also ist mir Ihre Abschlussprüfung ebenfalls gleichgültig. Natürlich danke ich Ihnen auch, für das Pokémon, das Sie mir anvertraut haben. Allerdings halte ich nichts von dieser Schule oder anderen Institutionen, in denen mein Vater seine Finger im Spiel hat.\pIn diesem Sinne, lebt wohl!"

str_faun_angry_at_blaise:
	.autostring 35 2 "Dieser verdammte Bengel! Devin wird außer sich sein!"

str_continue_with_field_test:
	.autostring 35 2 "DOTS DOTS\nSein Vater wird dem Jungen schon noch Vernunft beibringen.\pLassen wir uns aber von diesem Vorfall nicht irritieren.\pFelix, dann beginnst du eben die Prüfung."

str_felix_starts_test:
	.autostring 35 2 "Jawohl, Opi -\nÄhmDOTS Herr Faun!"

str_hand_felix_balls:
	.autostring 35 2 "Du erhältst von mir fünf Pokébälle.\pVersuche, ein Pokémon mit ihnen einzufangen."

str_felix_done_catching:
	.autostring 35 2 "Geschafft!"

str_faun_admires_felix:
	.autostring 35 2 "Sehr gut, Kleiner! So will ich das sehen!\pZurück mit dir in die Reihe!"

str_faun_calls_player:
	.autostring 35 2 "PLAYER, jetzt musst du dein Können unter Beweis stellen.\pKomm her zu mir."

str_player_receives_pokeballs:
	.autostring 35 2 "PLAYER, du erhältst jetzt von mir fünf Pokébälle.\pVersuche auch du, das Pokémon einzufangen!"

str_pokeball_obtention_message:
	.autostring 35 2 "Fünf Pokébälle erhalten."

str_player_has_to_catch:
	.autostring 35 2 "PLAYER! Begib dich endlich ins hohe Gras!"

str_battle_faun:
	.autostring 35 2 "Was treibst du denn da, PLAYER?\pAb mit dir auf deine Position!"

str_results_player:
	.autostring 35 2 "Na, wollen wir doch mal sehen, PLAYER!\pDie theoretische Prüfung hast du mit BUFFER_1 korrekten Antworten absolviert.\pDu konntest ein Pokémon fangen und hast dich im Kampf bewiesen!\pAuch dir darf ich gratulieren, Kind!\pDu bist nun ein echter Trainer!"

str_player_back:
	.autostring 35 2 "Reihe dich wieder ein, PLAYER.\pAls nächstes ist RIVAL dran!"

str_rival_results:
	.autostring 35 2 "Diese Spannung ist ja kaum auszuhalten!"

str_results_rival2:
	.autostring 35 2 "Im schriftlichen Test hast du keine einzige Frage richtig beantwortetDOTS\pDafür warst du ein echtes Naturtalent im Umgang mit Pokémon.\pWeder Kämpfen noch Fangen haben dir Schwierigkeiten bereitet.\pWeil du dein kümmerliches Wissen offenbar recht gut mit Fertigkeiten ausgleichen kannst, bin ich gewillt, auch dir zu gratulieren.\pAuch du darfst dich reinsten Gewissens einen Trainer nennen!"

str_rival_glad:
	.autostring 35 2 "Alles andere hätte mich auch überrascht!\pDanke, Herr Faun!"

str_call_may:
	.autostring 35 2 "Also dann! Zum Schluss bist du an der Reihe, Maike.\pKomm zu mir!"

str_may_insecure:
	.autostring 35 2 "O-Ojee!"

str_results_may:
	.autostring 35 2 "Nun gut.\nIm schriftlichen Test hast du immerhin drei Fragen richtig beantworten können.\pIm Feldtest hast du dich nicht schlecht geschlagen, aber du bist nicht besonders sicher im Umgang mit Pokémon.\pMaike! Wenn du als Trainer bestehen willst, musst du Vertrauen in dich und deine Pokémon finden."

str_may_understands:
	.autostring 35 2 "I-Ich verstehe, Herr FaunDOTS\pEs t-tut mir leid."

str_results_may2:
	.autostring 35 2 "Ich bin aber überzeugt, dass du das Zeug hast, ein erfolgreicher Pokémon-Trainer zu sein.\pImmerhin warst du meine Schülerin.\pDaher darf ich auch dir gratulieren, du hast deine Prüfungen bestanden!"

str_may_glad:
	.autostring 35 2 "W-Wirklich?\nDas ist fantastisch!\pJetzt werde ich meinen Freund aus Hoenn einholen können!"

str_final_talk:
	.autostring 35 2 "Hach! Wie die Zeit an einem vorbeifliegt!\pFür mich seid ihr noch immer die kleinen Rotzlöffel, die leichtsinnig ins hohe Gras gerannt wären, hätte man sie nicht davon abgehalten.\pAber nunDOTS\nSeid ihr zu fähigen Trainern herangewachsen.\pIch könnte nicht zufriedener mit euch sein. Allerdings ist dies erst der Anfang, ihr Bälger!\pWenn ihr diese Schule heute verlasst, werdet ihr auf euch allein gestellt sein.\pWobei auch das nicht ganz zutrifft, denn ihr habt nun eure Pokémon als Partner an eurer Seite.\pWisst diesen besonderen Bund zwischen Trainer und Pokémon zu schätzen, Kinder!\pIch bin überzeugt, dass ihr es weit bringen könnt.\pMacht mich stolz, euer Lehrer gewesen zu sein!\pIn diesem Sinne, viel Erfolg auf eurer Reise, Kinder!"

.elseif LANG_EN

.endif

ow_script_trainerschool_felix_outside:
compare TRAINERSCHOOL_PROGRESS 3
gotoif EQUAL make_faun_appear
compare TRAINERSCHOOL_PROGRESS 4
gotoif EQUAL has_received_pkmn_felix
compare TRAINERSCHOOL_PROGRESS 5
gotoif EQUAL catch_pkmn_felix
compare TRAINERSCHOOL_PROGRESS 6
gotoif EQUAL catch_pkmn_felix
compare TRAINERSCHOOL_PROGRESS 7
gotoif EQUAL battle_felix
compare TRAINERSCHOOL_PROGRESS 8
gotoif EQUAL results_felix
compare TRAINERSCHOOL_PROGRESS 8
gotoif HIGHER goodbye_felix
end

goodbye_felix:
lock
faceplayer
loadpointer 0 str_goodbye_felix
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
loadpointer 0 str_before_faun_appeared_felix
show_mugshot MUGSHOT_FELIX MUGSHOT_RIGHT
setflag TRAINERSCHOOL_TALKED_TO_FELIX
checkflag TRAINERSCHOOL_TALKED_TO_BLAISE
gotoif EQUAL ow_script_trainerschool_outside_faun_appears
release
end

has_received_pkmn_felix:
loadpointer 0 str_has_received_pkmn_felix
show_mugshot MUGSHOT_FELIX MUGSHOT_RIGHT MSG_FACE
applymovement 0x7 mov_face_down
waitmovement 0
end

catch_pkmn_felix:
loadpointer 0 str_catch_pkmn_felix
show_mugshot MUGSHOT_FELIX MUGSHOT_RIGHT MSG_FACE
applymovement 0x7 mov_face_up
waitmovement 0
end


battle_felix:
loadpointer 0 str_battle_felix
show_mugshot MUGSHOT_FELIX MUGSHOT_RIGHT MSG_FACE
end

results_felix:
loadpointer 0 str_results_felix
show_mugshot MUGSHOT_FELIX MUGSHOT_RIGHT MSG_FACE
applymovement 0x7 mov_face_up
waitmovement 0
end


.ifdef LANG_GER
str_before_faun_appeared_felix:
	.autostring 35 2 "Opi ist manchmal schon ein seltsamer KauzDOTS\pAber vielleicht ist er gerade deshalb ein guter Lehrer!"

str_has_received_pkmn_felix:
	.autostring 35 2 "Opi ist oft sehr streng, aber dafür ein herzensguter Mensch!\pEr ist sogar bereit, uns seine seltensten Pokémon anzuvertrauen!"

str_catch_pkmn_felix:
	.autostring 35 2 "Keine Sorge, PLAYER.\nEs ist wirklich kinderleicht! Nur keine Scheu!"

str_battle_felix:
	.autostring 35 2 "Lass uns unser Bestes geben, PLAYER.\pMehr können wir ohnehin nicht tun."

str_results_felix:
	.autostring 35 2 "Ich bin ja so glücklich!\nOpi ist sicherlich stolz auf mich!"

str_goodbye_felix:
	.autostring 35 2 "Da sind wir, PLAYER!\pWas tun wir nun?\nHast du Pläne?\pIch denke, ich werde mich auf die Suche nach Blaise machen.\pEr mag zwar wie ein Idiot wirken, aber im Grunde ist auch er nur Opfer der Tyrannei seines Vaters.\pWas solche Menschen brauchen, sind Freunde, die trotz allem zu ihnen stehen.\pFreundschaft! Das ist es, worauf es ankommt.\pMeinst du nicht auch, PLAYER?\pVielleicht werden wir uns wieder begegnen. Ich freue mich schon darauf!"

.elseif LANG_EN

.endif

ow_script_trainerschool_finish:
compare TRAINERSCHOOL_GOODBYE_CNT 3
gotoif EQUAL finish
end

finish:
@ Trainerschool done
addvar TRAINERSCHOOL_PROGRESS 1
addvar STORY_PROGRESS 1
setvar TRAINERSCHOOL_ALLOWED_TO_ENTER_GRASS 1
setvar TRAINERSCHOOL_DONE 1
end

ow_script_trainerschool_maike_outside:
compare TRAINERSCHOOL_PROGRESS 3
gotoif EQUAL make_felix_and_blaise_appear
compare TRAINERSCHOOL_PROGRESS 4
gotoif EQUAL will_receive_pkmn_may
compare TRAINERSCHOOL_PROGRESS 5
gotoif EQUAL catch_pkmn_may
compare TRAINERSCHOOL_PROGRESS 6
gotoif EQUAL catch_pkmn_may
compare TRAINERSCHOOL_PROGRESS 7
gotoif EQUAL battle_may
compare TRAINERSCHOOL_PROGRESS 8
gotoif EQUAL results_may
compare TRAINERSCHOOL_PROGRESS 8
gotoif HIGHER goodbye_may
end

goodbye_may:
lock
faceplayer
loadpointer 0 str_goodbye_may
show_mugshot MUGSHOT_MAY MUGSHOT_RIGHT
setvar 0x8004 5
setvar 0x8005 0x29
setvar 0x8006 0x14
special 0x24
waitmovement 0
applymovement 5 mov_face_down
waitmovement 0
sound 9
hidesprite 5
checksound
pause 32
addvar TRAINERSCHOOL_GOODBYE_CNT 1
release
goto ow_script_trainerschool_finish

make_felix_and_blaise_appear:
@ Check if may already appeared
checkflag TRAINERSCHOOL_FELIX_OUTSIDE
gotoif EQUAL felix_already_appeared
lock
faceplayer
loadpointer 0 str_make_both_appear
show_mugshot MUGSHOT_MAY MUGSHOT_RIGHT
sound 0x9
checksound
showsprite 0x7
showsprite 0x6
setflag TRAINERSCHOOL_BLAISE_INSIDE
setflag TRAINERSCHOOL_BLAISE_OUTSIDE
setflag TRAINERSCHOOL_FELIX_INSIDE
setflag TRAINERSCHOOL_FELIX_OUTSIDE
sound 0x15
applymovement 0xFF mov_exclam
applymovement 0x3 mov_exclam
applymovement 0x5 mov_exclam
waitmovement 0
pause 16
loadpointer 0 str_after_both_appeared
show_mugshot MUGSHOT_MAY MUGSHOT_RIGHT

applymovement 0x6 mov_1u
applymovement 0x7 mov_1u
waitmovement 0
release
end

mov_1u:
	.byte STEP_UP, STEP_UP, STOP

felix_already_appeared:
loadpointer 0 str_after_both_appeared_2
show_mugshot MUGSHOT_MAY MUGSHOT_RIGHT MSG_FACE
releaseall
end

will_receive_pkmn_may:
loadpointer 0 str_will_receive_pkmn_may
show_mugshot MUGSHOT_MAY MUGSHOT_RIGHT MSG_FACE
applymovement 0x5 mov_face_down
waitmovement 0
end

catch_pkmn_may:
loadpointer 0 str_catch_pkmn_may
show_mugshot MUGSHOT_MAY MUGSHOT_RIGHT MSG_FACE
applymovement 0x5 mov_face_up
waitmovement 0
end

battle_may:
loadpointer 0 str_battle_may
show_mugshot MUGSHOT_MAY MUGSHOT_RIGHT MSG_FACE
end

results_may:
loadpointer 0 str_results_may3
show_mugshot MUGSHOT_MAY MUGSHOT_RIGHT MSG_FACE
applymovement 0x5 mov_face_up
waitmovement 0
end



.ifdef LANG_GER
str_make_both_appear:
	.autostring 35 2 "Oh, hallo PLAYERDOTS\nIch bin immer noch am Boden zerstört wegen dieses schriftlichen TestsDOTS\pWeißt du, mein Freund aus Hoenn, er ist so ein talentierter Trainer und ich bin dagegenDOTS"

str_after_both_appeared:
	.autostring 35 2 "Also sind jetzt auch Felix und Blaise auf dem Hof, fehlt nur noch Herr FaunDOTS"

str_after_both_appeared_2:
	.autostring 35 2 "Wenn ich diesen Test heute vergeige, kann ich meinem Freund nicht mehr unter die Augen tretenDOTS"

str_will_receive_pkmn_may:
	.autostring 35 2 "Ich bin schon ganz gespannt, welches Pokémon ich bekomme!\pIch will ein so starker Trainer werden, wie mein Freund aus Hoenn."

str_catch_pkmn_may:
	.autostring 35 2 "Dass man mir das letzte Pokémon einfach aufzwingt, gefällt mir nicht, PLAYER.\pVielleicht kann ich ja ein anderes Pokémon einfangen, das mir gefälltDOTS"

str_battle_may:
	.autostring 35 2 "AchDOTS ich will eigentlich gar nicht kämpfenDOTS\pWeißt du, PLAYER, ich traue mir das ganze Trainer-Sein ehrlich gesagt noch nicht zuDOTS"

str_results_may3:
	.autostring 35 2 "Ich bin sehr nervösDOTS\pImmerhin konnte ich Felix nicht besiegen.\pIch hoffe nur, dass ich nicht durch die Prüfung gefallen bin!"

str_goodbye_may:
	.autostring 35 2 "PLAYERDOTS\nIch bin glücklich und ängstlich zugleich.\pDer Schatten meines Freundes aus Hoenn reicht sehr weitDOTS\pOb ich jemals mit ihm auf Augenhöhe sein werde?\pIch frage mich, ob ich dem gewachsen bin, was vor mir liegt.\pAber ich muss mein Leben allein bewältigen, meinst du nicht, PLAYER?\pJa, Verantwortung, die muss ich jetzt übernehmen.\pWir werden uns sicher wiedersehen.\pLebe wohl, bis dahin, PLAYER!"

.elseif LANG_EN

.endif

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

loadpointer 0 str_faun_appears
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT

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
loadpointer 0 str_faun_announces_pkmn
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
lockall // prevents the 'moonwalk bug'
pause 40
applymovement 4 mov_smile
waitmovement 0
loadpointer 0 str_call_blaise2
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT

@ Move Blaise to Faun
applymovement 6 mov_1d
waitmovement 0
pause 32
applymovement 6 mov_dinplace
waitmovement 0
loadpointer 0 str_blaise_received_pkmn
show_mugshot MUGSHOT_BLAISE MUGSHOT_RIGHT
applymovement 6 mov_blaise_back
waitmovement 0

loadpointer 0 str_call_felix
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT

@ Move Felix to Faun
applymovement 7 mov_felix_to_faun
waitmovement 0
pause 32
applymovement 7 mov_dinplace
waitmovement 0
loadpointer 0 str_felix_received_pkmn
show_mugshot MUGSHOT_FELIX MUGSHOT_RIGHT
sound 0x15
applymovement 4 mov_double_exclam
waitmovement 4
loadpointer 0 str_angry_at_felix
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
loadpointer 0 str_felix_apologize
show_mugshot MUGSHOT_FELIX MUGSHOT_RIGHT
loadpointer 0 str_after_felix
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
applymovement 7 mov_felix_back
waitmovement 0

loadpointer 0 str_call_player
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
addvar TRAINERSCHOOL_PROGRESS 1
releaseall
end

mov_felix_back:
	.byte STEP_LEFT, STEP_UP, LOOK_DOWN, STOP

mov_felix_to_faun:
	.byte STEP_DOWN, STEP_RIGHT, LOOK_DOWN, STOP

mov_blaise_back:
	.byte STEP_UP, LOOK_DOWN, STOP

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


.ifdef LANG_GER
str_faun_appears:
	.autostring 35 2 "So, ihr Grünschnäbel!\pJetzt wird es ernst, wir beginnen mit dem Feldtest.\pAlle in einer Reihe aufstellen!"

str_faun_announces_pkmn:
	.autostring 35 2 "Der Feldtest setzt sich aus zwei Komponenten zusammen.\pZuerst müsst ihr ein wildes Pokémon einfangen.\pIm Anschluss werdet ihr dann gegeneinander im Kampf antreten.\pZuallererst aber erhaltet ihr von mir ein Pokémon, das euch fortan unterstützen wird. Es ist von nun an euer wichtigster Partner und Freund, den ihr zu respektieren habt."

str_call_blaise2:
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

ow_script_trainerschool_rival_outside:
compare TRAINERSCHOOL_PROGRESS 3
gotoif EQUAL make_may_appear
compare TRAINERSCHOOL_PROGRESS 4
gotoif EQUAL will_receive_pkmn_rival
compare TRAINERSCHOOL_PROGRESS 5
gotoif EQUAL catch_pokemon_rival
compare TRAINERSCHOOL_PROGRESS 6
gotoif EQUAL catch_pokemon_rival
compare TRAINERSCHOOL_PROGRESS 7
gotoif EQUAL rival_battle
compare TRAINERSCHOOL_PROGRESS 8
gotoif EQUAL rival_results
compare TRAINERSCHOOL_PROGRESS 8
gotoif HIGHER rival_goodbye
end

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

will_receive_pkmn_rival:
loadpointer 0 str_will_receive_pkmn_rival
show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT MSG_FACE
applymovement 0x3 mov_face_down
waitmovement 0
end

catch_pokemon_rival:
loadpointer 0 str_catch_pkmn_rival
show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT MSG_FACE
applymovement 0x3 mov_face_up
waitmovement 0
end


rival_battle:
loadpointer 0 str_battle_rival
show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT MSG_FACE
end

rival_results:
loadpointer 0 str_results_rival
show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT MSG_FACE
applymovement 0x3 mov_face_up
waitmovement 0
end

rival_goodbye:
lock
faceplayer
loadpointer 0 str_goodbye_rival
show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT
setvar 0x8004 3
setvar 0x8005 0x28
getplayerpos 0x8005 0x8006
compare 0x8006 0x12
callif EQUAL rearrange_coordinate
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

rearrange_coordinate:
@ Rearrange the x-coordinate to move the rival to
setvar 0x8005 0x29
return


.ifdef LANG_GER
str_make_may_appear:
	.autostring 35 2 "PLAYER, da bist du ja!\nMal ehrlich, dieser Test war doch lachhaft, oder?\pWer soll auf solche Fragen denn antworten könnenDOTS"

str_after_may_appeared:
	.autostring 35 2 "Sieh mal, da ist Maike.\pWie es ihr wohl in dem Test ergangen ist?"

str_after_may_appeared_2:
	.autostring 35 2 "Wo bleibt denn nun Faun?\nIch bin schon ganz heiß auf diesen Feldtest!"

str_will_receive_pkmn_rival:
	.autostring 35 2 "PLAYER! Auf jetzt!\pIch habe nicht den ganzen Tag Zeit, auf deine Entscheidung zu warten. Ich will auch ein Pokémon haben!"

str_catch_pkmn_rival:
	.autostring 35 2 "Du brauchst für alles eine Ewigkeit!\pLos, mach schon! Fang das Pokémon ein!"

str_battle_rival:
	.autostring 35 2 "Na los, PLAYER!\nWorauf wartest du? Ab mit dir auf deine Position und dann zeige ich dir einmal, was mein Talent alles bewirken kann!"

str_results_rival:
	.autostring 35 2 "Viel Glück, PLAYER!\nDu wirst es brauchen!"

str_goodbye_rival:
	.autostring 35 2 "Endlich, PLAYER! Es ist soweit! Wir sind beide Trainer!\pNun können wir endlich unseren Traum leben! Die Welt ist ein einziges Abenteuer, das wir nun endlich bestreiten dürfen!\pBist du nicht auch aufgeregt?\pNatürlich werde ich dir immer ein wenig voraus sein, das ist dir wohl klar, oder?\pWenn du mich einholen willst, solltest du dich beeilen!"

.elseif LANG_EN

.endif

mov_face_right:
	.byte LOOK_RIGHT, STOP

mov_face_left:
	.byte LOOK_LEFT, STOP
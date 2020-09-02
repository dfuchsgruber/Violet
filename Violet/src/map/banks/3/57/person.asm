.include "vars.s"
.include "movements.s"
.include "callstds.s"
.include "songs.s"
.include "mugshot.s"
.include "ordinals.s"
.include "overworld_script.s"
.include "flags.s"
.include "items.s"
.include "pathfinding.s"

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
	.autostring 35 2 "Ich kann es wirklich kaum erwarten, diesen Kindergarten hier hinter mir zu lassen.\pDiesen ganzen Unsinn habe ich meinem Vater zu verdankenDOTS"
str_has_received_pkmn:
	.autostring 35 2 "So wenig ich für den altne Knacker übrig habeDOTS\pDas Pokémon, das er mir gegeben hat, ist nicht von schlechten Eltern!"

.elseif LANG_EN
str_before_faun_appeared:
	.autostring 35 2 "I really can't wait to leave this kindergarden behind.\pAll this nonsense is only because of my fatherDOTS"
str_has_received_pkmn:
	.autostring 35 2 "I don't particularly like this old geezerDOTS\pBut the Pokémon he gave me really isn't all that bad!"


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
loadpointer 0 str_passed
fanfare 0x13E
callstd MSG_KEEPOPEN
waitfanfare
closeonkeypress
loadpointer 0 str_player_back
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
npc_move_to 0xFF 0x29 0x11
applymovement 0xFF mov_face_up
applymovement 4 mov_face_down
waitmovement 0
applymovement 3 mov_result_rival_to_faun
waitmovement 0
loadpointer 0 str_rival_results
show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT emotion=MUGSHOT_SCARED
loadpointer 0 str_results_rival2
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
fanfare 0x13E
waitfanfare
loadpointer 0 str_rival_glad
show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT emotion=MUGSHOT_HAPPY
applymovement 3 mov_result_rival_back
waitmovement 0
loadpointer 0 str_call_may
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
loadpointer 0 str_may_insecure
show_mugshot MUGSHOT_MAY MUGSHOT_RIGHT emotion=MUGSHOT_SCARED
applymovement 5 mov_result_may_to_faun
waitmovement 0
loadpointer 0 str_results_may
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
loadpointer 0 str_may_understands
show_mugshot MUGSHOT_MAY MUGSHOT_RIGHT emotion=MUGSHOT_SAD
loadpointer 0 str_results_may2
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
fanfare 0x13E
waitfanfare
loadpointer 0 str_may_glad
show_mugshot MUGSHOT_MAY MUGSHOT_RIGHT emotion=MUGSHOT_SHOCKED
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
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT MSG_FACE emotion=MUGSHOT_ANGRY
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
npc_move_to 0xFF 0x27 0x12
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
show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT emotion=MUGSHOT_HAPPY
applymovement 0x3 mov_rival_back
waitmovement 0

@ May comes to Faun
loadpointer 0 str_may_picks
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
loadpointer 0 str_may_disappointed
show_mugshot MUGSHOT_MAY MUGSHOT_RIGHT emotion=MUGSHOT_SAD
applymovement 0x5 mov_may_to_faun
waitmovement 0
pause 32
applymovement 0x5 mov_dinplace
waitmovement 0
loadpointer 0 str_may_received_pkmn
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
loadpointer 0 str_may_dots
show_mugshot MUGSHOT_MAY MUGSHOT_RIGHT emotion=MUGSHOT_SAD
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
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT emotion=MUGSHOT_ANGRY
loadpointer 0 str_blaise_leaves
show_mugshot MUGSHOT_BLAISE MUGSHOT_RIGHT emotion=MUGSHOT_ANGRY
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
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT emotion=MUGSHOT_ANGRY
applymovement 0x3 mov_face_up
applymovement 0xFF mov_face_up
applymovement 0x5 mov_face_up
applymovement 0x7 mov_face_up
loadpointer 0 str_continue_with_field_test
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT message_type=MSG_KEEPOPEN emotion=MUGSHOT_ANGRY hide_mugshot=0
update_mugshot_emotion MUGSHOT_NORMAL
loadpointer 0 str_continue_with_field_test2
callstd MSG_KEEPOPEN
closeonkeypress
hide_mugshot
@ Continue with field test
pause 40
fadesong MUS_TRAINERSCHOOL
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
show_mugshot MUGSHOT_FELIX MUGSHOT_RIGHT emotion=MUGSHOT_HAPPY
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
setflag FLAG_SCRIPTED_WILD_BATTLES_LOSABLE
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
	.byte JUMP_IN_PLACE_FACE_UP, PAUSE_32, STOP

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
	.autostring 35 2 "Also PLAYER, bleiben noch drei Pokémon, aus denen du wählen kannst.\pTriff deine Entscheidung mit Bedacht!"
str_player_received_b1:
    .string "PLAYER hat ein BUFFER_1\nerhalten!"
str_player_received_pkmn:
	.autostring 35 2 "BUFFER_1!\nEine sehr gute Wahl!\pNun aber zurück mit dir in die Reihe!"
str_rival_picks:
	.autostring 35 2 "So, RIVAL, jetzt darfst du dir ein Pokémon aussuchen!"
str_rival_says_thanks:
	.autostring 35 2 "Dieses Pokémon ist perfekt.\pDamit werde ich unschlagbar sein!"
str_may_picks:
	.autostring 35 2 "Also, Maike, jetzt bist auch du noch an der Reihe."
str_may_disappointed:
	.autostring 35 2 "Mir bleibt ja nur noch dieses eine hierDOTS"
str_may_received_pkmn:
	.autostring 35 2 "Ich hoffe, dass du mit deinem Pokemon zufrieden bist."
str_may_dots:
	.autostring 35 2 "DOTS\nSicher, Herr Faun!"
str_to_tall_grass:
	.autostring 35 2 "Dann hätten wir das erledigt!\pBeginnen wir mit dem Feldtest.\pFolgt mir zum hohen Gras!"
str_tall_grass:
	.autostring 35 2 "Im ersten Teil der Feldprüfung werdet ihr ein wildes Pokémon einfangen\pIch erwarte von euch, dass ihr das mühelos bewältigt!\pBlaise, du bist als erstes an der Reihe!"
str_call_blaise:
	.autostring 35 2 "Blaise?\nNa wird's bald?\pBeweg deinen Hintern hierher, du kleiner Rotzlöffel!"
str_blaise_refuses:
	.autostring 35 2 "Ich verzichte, danke."
str_call_blaise_again:
	.autostring 35 2 "Wie bitte?\pWas denkst du denn, wer du glaubst zu sein, du Göre!\pWas meinst du, wie dein Vater reagieren wird, wenn er hiervon erfährt?"
str_blaise_leaves:
	.autostring 35 2 "Ich habe beschlossen, dass mir das egal ist.\pIch lasse mich nicht länger herumkommandieren.\pWeder von Ihnen noch von meinem Vater.\pIch habe lange genug meine Zeit mit diesem Unsinn hier verschwendet.\pDamit ist jetzt Schluss."
str_faun_angry_at_blaise:
	.autostring 35 2 "Dieser verdammte Bengel!\pWas fällt ihm einDOTS"
str_continue_with_field_test:
	.autostring 35 2 "DOTS DOTS DOTS\nDOTS DOTS DOTS\pDas wird ein Nachspiel habenDOTS\pDOTS DOTS DOTS\nDOTS DOTS DOTS"
str_continue_with_field_test2:
	.autostring 34 2 "Lassen wir uns davon nicht beirrenDOTS\pDann machst du eben den Anfang, Felix."
str_felix_starts_test:
	.autostring 35 2 "Jawohl, Opi -\nÄhmDOTS, ich meine natürlich, Herr Faun!"
str_hand_felix_balls:
	.autostring 35 2 "Du erhältst von mir fünf Pokébälle.\pVersuche, ein Pokémon mit ihnen einzufangen."
str_felix_done_catching:
	.autostring 35 2 "Geschafft!"
str_faun_admires_felix:
	.autostring 35 2 "Sehr gut, Kleiner!\nSo will ich das sehen!\pZurück mit dir in die Reihe!"
str_faun_calls_player:
	.autostring 35 2 "PLAYER, jetzt musst du dein Können unter Beweis stellen.\pKomm her zu mir."
str_player_receives_pokeballs:
	.autostring 35 2 "PLAYER, du erhältst jetzt von mir fünf Pokébälle.\pVersuche, das Pokémon einzufangen!"
str_pokeball_obtention_message:
	.autostring 35 2 "Fünf Pokébälle erhalten."
str_player_has_to_catch:
	.autostring 35 2 "PLAYER!\nAb mit dir ins hohe Gras!"
str_battle_faun:
	.autostring 35 2 "Was treibst du denn da, PLAYER?\pAb mit dir auf deine Position!"
str_results_player:
	.autostring 35 2 "Na, wollen wir doch mal sehen, PLAYER!\pIn der theoretischen Prüfung waren BUFFER_1 deiner Antworten richtig.\pUnd beim Feldtest hast du dich auch nicht übel angestellt.\pIch würde sagen, dass das ausreicht."
str_passed:
	.autostring 34 2 "Herzlichen Glückwunsch, du hast die Prüfung bestanden!"
str_player_back:
	.autostring 35 2 "Reihe dich wieder ein, PLAYER.\pAls nächstes ist RIVAL dran!"
str_rival_results:
	.autostring 35 2 "Diese Spannung ist ja kaum auszuhalten!"
str_results_rival2:
	.autostring 35 2 "Im schriftlichen Test hast du keine einzige Frage richtig beantwortetDOTS\pDafür warst du ein echtes Naturtalent im Umgang mit Pokémon.\pWeder Kämpfen noch Fangen haben dir Schwierigkeiten bereitet.\pWeil du dein kümmerliches Wissen offenbar recht gut mit praktischen Fertigkeiten ausgleichen kannst, lasse ich ausnahmsweise auch dich bestehen.\pWas sagst du dazu, RIVAL?"
str_rival_glad:
	.autostring 35 2 "Toll!\nAlles andere hätte mich auch überrascht!\pDanke, Herr Faun!"
str_call_may:
	.autostring 35 2 "Also dann!\nZum Schluss bist du an der Reihe, Maike.\pKomm zu mir!"
str_may_insecure:
	.autostring 35 2 "O-Ojee!"
str_results_may:
	.autostring 35 2 "Gut, gut.\nDer schriftliche Test war auch bei dir eher durchwachsen.\pUnd auch der Feldtest war keine überragende Leistung."
str_may_understands:
	.autostring 35 2 "Ich verstehe, Herr FaunDOTS\pEs tut mir leid."
str_results_may2:
	.autostring 35 2 "Ich weiß, dass du das Zeug zum Trainer hast, Maike.\pAnderenfalls hätte ich dich niemals an meiner Schule aufgenommen.\pAber du musst endlich anfangen, selbst an dich zu glauben.\pWie sollen deine Pokémon sonst hinter dir stehen?\pAlles in allem, Mädchen, werde ich aber auch dich nicht durchfallen lassen.\pIch denke, es tut dir ganz gut, nicht mehr nur die Schulbank zu drücken, sondern da draußen in der echten Welt Erfahrungen zu sammeln."
str_may_glad:
	.autostring 35 2 "Wirklich?\nDas ist fantastisch!\pIch habe doch tatsächlich bestandenDOTS"
str_final_talk:
	.autostring 35 2 "Ähm, gutDOTS\pWie ihr vielleicht bemerkt habt, bin ich kein Mann großer Worte.\pUnd ich werde euch sicher keine Abschiedsrede halten, ihr Gören, verstanden?\pAber ich würde euch nicht hier abgehen lassen, wenn ich nicht davon überzeugt wäre, dass ihr da draußen bestehen könnt.\pJetzt beginnt für euch ein ganz neues Kapitel.\pUnd auch wenn da draußen viele Gefahren auf euch warten, wird es doch vor allem ein Riesenspaß werden, da bin ich mir sicher!\pEnttäuscht mich ja nicht, verstanden?\pSonst redet man noch schlecht von meiner SchuleDOTS\pLebt wohl, Kinder!"
.elseif LANG_EN

	.autostring 35 2 "Ok PLAYER, three Pokémon to choose from remain.\pTake your time to pick one of them!"
str_player_received_b1:
    .string "PLAYER received a\nBUFFER_1!"
str_player_received_pkmn:
	.autostring 35 2 "BUFFER_1!\nAn excellent choice.\pGet back in line!"
str_rival_picks:
	.autostring 35 2 "Now, RIVAL, its your turn to chose!"
str_rival_says_thanks:
	.autostring 35 2 "This Pokémon is just perfect.\pNo one will be able to defeat me now!"
str_may_picks:
	.autostring 35 2 "Ok May, finally you may also choose a Pokémon."
str_may_disappointed:
	.autostring 35 2 "Well, this is the only one left, right?"
str_may_received_pkmn:
	.autostring 35 2 "I hope you're satisfied with that Pokémon, May."
str_may_dots:
	.autostring 35 2 "DOTS\nOf course, Mr. Faun!"
str_to_tall_grass:
	.autostring 35 2 "Ok, that's that.\pLet's start with the field test.\pFollow me to the tall grass."
str_tall_grass:
	.autostring 35 2 "In this first part of your examination you will catch a wild Pokémon.\pI except all of you to get that done without any problems whatsoever.\pBlaise, you may start."
str_call_blaise:
	.autostring 35 2 "Blaise?\nDid I stutter?\pMove it and come here!"
str_blaise_refuses:
	.autostring 35 2 "No, I don't think I will."
str_call_blaise_again:
	.autostring 35 2 "Come again?\pDarn spoiled brat!\pWho do you think you are?\pCan you imagine how your father will react if he hears about that?"
str_blaise_leaves:
	.autostring 35 2 "I just decided that I don't care anymore.\pI won't be pushed arround anymore, neither by you nor by my father.\pI wasted enough time with this nonsense here already.\pBut that ends now."
str_faun_angry_at_blaise:
	.autostring 35 2 "Unbelievable!\nWhat an idiot!\pWhat audacity!"
str_continue_with_field_test:
	.autostring 35 2 "DOTS DOTS DOTS\nDOTS DOTS DOTS\pThat's gonna have consequencesDOTS\pDOTS DOTS DOTS\nDOTS DOTS DOTS"
str_continue_with_field_test2:
	.autostring 34 2 "Anyways, let's not get distracted by that little, er, incident.\pThen you will be the first one to take the test, Felix."
str_felix_starts_test:
	.autostring 35 2 "Sure, grandpa -\nerDOTS, I mean Mr. Faun!"
str_hand_felix_balls:
	.autostring 35 2 "You will get some Pokéballs.\pTry to catch the wild Pokémon!"
str_felix_done_catching:
	.autostring 35 2 "Done!"
str_faun_admires_felix:
	.autostring 35 2 "Well done, little one!\pThat's how I like to see it!\pGet back in line!"
str_faun_calls_player:
	.autostring 35 2 "PLAYER, its your turn to prove your abilities now.\pCome here!"
str_player_receives_pokeballs:
	.autostring 35 2 "PLAYER, you will get five Pokéballs from my with which you will try to capture that wild Pokémon, ok?"
str_pokeball_obtention_message:
	.autostring 35 2 "PLAYER received five Pokéballs!"
str_player_has_to_catch:
	.autostring 35 2 "PLAYER!\nGo into the tall grass!"
str_battle_faun:
	.autostring 35 2 "What are you doing, PLAYER!\pGet into battle position!"
str_results_player:
	.autostring 35 2 "Let's see, PLAYER.\pIn the written test you got BUFFER_1 answers right.\pYour performance in the practical part also was quite convincing.\pI'd say that's sufficient."
str_passed:
	.autostring 34 2 "Congratulations, you passed the exam!"
str_player_back:
	.autostring 35 2 "Back in line with you, PLAYER.\pRIVAL, you're up next."
str_rival_results:
	.autostring 35 2 "The tension!"
str_results_rival2:
	.autostring 35 2 "You didn't get a single question right in the written test, RIVAL.\pRegardless your pracitical abilities dealing with Pokémon really were impressive.\pNeither catching nor battling did give you any difficulties whatsoever.\pBecause you compesated your poor knowledge with an impressive overall skillset, I'd be willing to make an exception and also let you pass.\pWhat do you think?"
str_rival_glad:
	.autostring 35 2 "Nice!\nEverything else would have been a suprise to me!\pThank you, Mr. Faun!"
str_call_may:
	.autostring 35 2 "Ok then.\nLastly it's your turn, May.\pPlease come to me."
str_may_insecure:
	.autostring 35 2 "H-Here goesDOTS"
str_results_may:
	.autostring 35 2 "Well, well.\pThe written test wasn't that great for you either.\pAnd also the practical part wasn't that impressive."
str_may_understands:
	.autostring 35 2 "In understand, Mr. Faun.\pI am sorryDOTS"
str_results_may2:
	.autostring 35 2 "But I know that you got what is needed to become a successful trainer, May!\pOtherwise I wouldn't have made you my pupil!\pYou have to start believing in yourself!\pHow can you expect your Pokémon to trust in you, when youself can't even do it?\pHaving said that, girl, I won't let you fail this exam.\pI think it will do you more good to finally leave the school and instead gather hands-on experience out there in the real world."
str_may_glad:
	.autostring 35 2 "Really?\nThat's fantastic!\pI really did itDOTS"
str_final_talk:
	.autostring 35 2 "Er, ok.\nAs you might have noticed I am not a man of many words.\pAnd I won't give any sort of goodbye-speech to you brats, got that?\pBut I wouldn't let you graduate if I wasn't convinced that all of you were able to succed out there.\pNow a new chapter begins for every single one of you.\pAnd even though there are many dangers out there waiting for you, I positive that it will more than everything be so much fun!\pDon't you dare to dissapoint me though!\pOtherwise people might talk bad about my school.\pGoodbye, you brats!"
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
npc_move_to 7 0x29 0x14
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
	.autostring 35 2 "Jetzt können wir Opi beweisen, aus welchem Holz wir geschnitzt sind, PLAYER!\pImmerhin hatten wir einen ausgezeichneten Lehrer, nicht wahr?"
str_has_received_pkmn_felix:
	.autostring 35 2 "Opi mag zwar ein strenger Lehrer sein.\pAber dass er uns so seltene Pokémon anvertraut, zeigt doch eigentlich auch, wie viel er von uns hält, oder?"
str_catch_pkmn_felix:
	.autostring 35 2 "Keine Sorge, PLAYER.\nEs ist wirklich kinderleicht!"
str_battle_felix:
	.autostring 35 2 "Lass uns unser Bestes geben, PLAYER!"
str_results_felix:
	.autostring 35 2 "Ich bin ja so glücklich!\nOpi ist bestimmt stolz auf mich!"
str_goodbye_felix:
	.autostring 35 2 "Großartig, was?\pJetzt sind wir alle also Trainer!\pIch kann mir vorstellen, dass du es jetzt auf die Arena-Orden abgesehen hast.\pDa will ich dich auch gar nicht aufhalten.\pIch für meinen Teil denke aber, dass ich mich irgendwo nützlich machen will.\pAnderen Menschen helfen, und soDOTS\pWeißt du, das ist doch das, was einen Trainer ausmacht, oder?\pUnd ich bin mir sicher, dass unser Abschied heute bloß vorrübergehend ist.\pBis wir uns wiedersehen, wünsche ich dir alles Gute, PLAYER!\pPass auf dich auf!"

.elseif LANG_EN
str_before_faun_appeared_felix:
	.autostring 35 2 "Now we can show grandpa what we're made of, PLAYER!\pAfter all we had an excellent teacher, right?"
str_has_received_pkmn_felix:
	.autostring 35 2 "Grandpa may be a strict teacher.\pBut the fact that he entrusted us with these rare Pokémon shows that he has a lot of faith in us, doesn't it?"
str_catch_pkmn_felix:
	.autostring 35 2 "No worries, PLAYER!\pIt's super easy!"
str_battle_felix:
	.autostring 35 2 "Let's try our bests, PLAYER!"
str_results_felix:
	.autostring 35 2 "I am just so happy!\pGrandpa surely is proud of me!"
str_goodbye_felix:
	.autostring 35 2 "Great, right?\pNow everyone of us is a trainer!\pI can imagine that you will be going after the gym badges, right?\pI surely won't try to stop you, PLAYER.\pBut for my part, I think I want to make my self useful.\pHelp other people, you know?\pI guess that's what makes a good trainer.\pAnd I am certain that our goodbye is nothing permanent.\pUntil we meet each other again I wish you all the best, PLAYER!\pTake care of yourself!"

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
npc_move_to 5 0x29 0x14
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
show_mugshot MUGSHOT_MAY MUGSHOT_RIGHT emotion=MUGSHOT_SAD
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
show_mugshot MUGSHOT_MAY MUGSHOT_RIGHT MSG_FACE emotion=MUGSHOT_SAD
releaseall
end

will_receive_pkmn_may:
loadpointer 0 str_will_receive_pkmn_may
show_mugshot MUGSHOT_MAY MUGSHOT_RIGHT MSG_FACE emotion=MUGSHOT_SAD
applymovement 0x5 mov_face_down
waitmovement 0
end

catch_pkmn_may:
loadpointer 0 str_catch_pkmn_may
show_mugshot MUGSHOT_MAY MUGSHOT_RIGHT MSG_FACE emotion=MUGSHOT_SAD
applymovement 0x5 mov_face_up
waitmovement 0
end

battle_may:
loadpointer 0 str_battle_may
show_mugshot MUGSHOT_MAY MUGSHOT_RIGHT MSG_FACE emotion=MUGSHOT_SAD
end

results_may:
loadpointer 0 str_results_may3
show_mugshot MUGSHOT_MAY MUGSHOT_RIGHT MSG_FACE emotion=MUGSHOT_HAPPY
applymovement 0x5 mov_face_up
waitmovement 0
end



.ifdef LANG_GER
str_make_both_appear:
	.autostring 35 2 "Bist du wegen des schriftlichen Tests auch so niedergeschlagen, PLAYER?\pIch glaube wirklich, dass ich durchgefallen bin, egal, wie ich mich hier jetzt schlageDOTS"
str_after_both_appeared:
	.autostring 35 2 "Ah, da sind auch schon Felix und Blaise.\pFehlt also nur noch Herr FaunDOTS"
str_after_both_appeared_2:
	.autostring 35 2 "Es würde mich nicht wundern, wenn ich als einzige den Test heute vergeigeDOTS"
str_will_receive_pkmn_may:
	.autostring 35 2 "Welches Pokémon ich wohl kriege?\pVermutlich ist das sowieso egal, wenn ich den Test nicht besteheDOTS"
str_catch_pkmn_may:
	.autostring 35 2 "Es war sicherlich Absicht, dass man mir das letzte Pokémon gibt.\pEiner Niete wie mir will man natürlich kein starkes Pokémon anvertrauenDOTS"
str_battle_may:
	.autostring 35 2 "Ich habe wirklich Muffensausen vor diesen KampfDOTS\pIch glaube nicht, dass ich Felix besiegen kann.\pImmerhin ist er ja auch der Enkel von Herr FaunDOTS"
str_results_may3:
	.autostring 35 2 "Ich habe gegen Felix verlorenDOTS"
str_goodbye_may:
	.autostring 35 2 "Ich hätte wirklich nicht gedacht, dass ich den Test bestehe, PLAYER!\pAber es freut mich, ehrlich.\pVielleicht ist das jetzt ein Wendepunkt in meinem Leben.\pIch werde mir wirklich Mühe geben.\pHoffentlich wird aus mir ja doch ein anständiger Pokémon-Trainer!"
.elseif LANG_EN
str_make_both_appear:
	.autostring 35 2 "Did that written exam also make you somewhat depressed, PLAYER?\pI just really don't think that I can pass anymore, no matter how the field test goesDOTS"
str_after_both_appeared:
	.autostring 35 2 "Ah, there are Felix and Blaise.\pI guess now we only have to wait for Mr. FaunDOTS"
str_after_both_appeared_2:
	.autostring 35 2 "I wouldn't be suprised if I was the only one to fail today's examDOTS"
str_will_receive_pkmn_may:
	.autostring 35 2 "I wonder which Pokémon I will get.\pProbably it doesn't really matter when I fail the testDOTS"
str_catch_pkmn_may:
	.autostring 35 2 "They gave me the last Pokémon on purpose, I guess.\pDoesn't make much sense to let a wimp have a strong Pokémon, right?"
str_battle_may:
	.autostring 35 2 "I am almost dying of fear right now.\pI don't believe I can defeat Felix.\pHe is the grandson of Mr. Faun after all."
str_results_may3:
	.autostring 35 2 "I lost to FelixDOTS"
str_goodbye_may:
	.autostring 35 2 "I really didn't think I'd make it, PLAYER!\pBut I am happy, honestly!\pMaybe that's a turning point in my life.\pI definitely will try my best.\pHopefully I can become a somewhat competent Pokémon-Trainer. in my life.\pI definitely will try my best.\pHopefully I can become a somewhat competent Pokémon-Trainer."

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
npc_move_to 0xFF 0x27 0x12
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
show_mugshot MUGSHOT_BLAISE MUGSHOT_RIGHT emotion=MUGSHOT_SHOCKED
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
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT emotion=MUGSHOT_ANGRY
loadpointer 0 str_felix_apologize
show_mugshot MUGSHOT_FELIX MUGSHOT_RIGHT emotion=MUGSHOT_SCARED
loadpointer 0 str_after_felix
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT emotion=MUGSHOT_ANGRY
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
	.autostring 35 2 "Der Feldtest besteht aus zwei Teilen.\pZuerst werdet ihr ein Pokémon einfangen, dann werdet ihr gegeinander kämpfen.\pAber zuallererst braucht ihr natürlich ein Pokémon, oder?"
str_call_blaise2:
	.autostring 35 2 "Blaise, du bist der Erste.\pKomm her und nimm dir eines der Pokémon, die ich mitgebracht habe."
str_blaise_received_pkmn:
	.autostring 35 2 "Unglaublich, dass man uns so seltene Pokémon anvertrautDOTS"
str_call_felix:
	.autostring 35 2 "Als nächstes bist du an der Reihe, Felix.\pKomm zu mir und such dir ein Pokémon aus, Kleiner!"
str_felix_received_pkmn:
	.autostring 35 2 "Alles klar, Opi!\nIch wähle dieses hier!"
str_angry_at_felix:
	.autostring 35 2 "Ich habe dir schon tausendmal gesagt, dass du mich in der Schule Herr Faun zu nennen hast, du Rotzlöffel!"
str_felix_apologize:
	.autostring 35 2 "ÄhmDOTS\nTut mir wirklich leid, Herr Faun!\pEhrlich!"
str_after_felix:
	.autostring 35 2 "GrrDOTS\nZurück mit dir in die Reihe, Felix!"
str_call_player:
	.autostring 35 2 "Nun denn, PLAYER, komm zu mir!"
.elseif LANG_EN
str_faun_appears:
	.autostring 35 2 "Ok, fledgelings.\pNow we are getting serious.\nThe field examiation will now begin.\pGet in line!"
str_faun_announces_pkmn:
	.autostring 35 2 "The field test consists of two parts.\pFirst, you will catch a Pokémon and then you will battle one another.\pBut before that you obviously need a Pokémon, right?"
str_call_blaise2:
	.autostring 35 2 "Blaise, you're first.\pCome here and take one of these Pokémon that I brought for you."
str_blaise_received_pkmn:
	.autostring 35 2 "Incredible, that you give us such rare PokémonDOTS"
str_call_felix:
	.autostring 35 2 "You're next, Felix.\pCome here and choose a Pokémon, little one!"
str_felix_received_pkmn:
	.autostring 35 2 "Alright, grandpa!\pI'll take that one!"
str_angry_at_felix:
	.autostring 35 2 "I told you a thousand times that you are supposed to call me Mr. Faun in school, you brat!"
str_felix_apologize:
	.autostring 35 2 "ErDOTS\nI am really sorry, Mr. Faun!\pI mean it!"
str_after_felix:
	.autostring 35 2 "GrrDOTS\nGet back in line!"
str_call_player:
	.autostring 35 2 "Now then, PLAYER, your turn!"
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
npc_move_to 0x5 0x2A 0x11
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
show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT MSG_FACE emotion=MUGSHOT_ANNOYED
applymovement 0x3 mov_face_down
waitmovement 0
end

catch_pokemon_rival:
loadpointer 0 str_catch_pkmn_rival
show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT MSG_FACE emotion=MUGSHOT_ANNOYED
applymovement 0x3 mov_face_up
waitmovement 0
end


rival_battle:
loadpointer 0 str_battle_rival
show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT MSG_FACE emotion=MUGSHOT_ANNOYED
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
show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT emotion=MUGSHOT_HAPPY
setvar 0x8004 3
setvar 0x8005 0x28
getplayerpos 0x8005 0x8006
compare 0x8006 0x12
callif EQUAL rearrange_coordinate
setvar 0x8006 0x14
setvar 0x8007 A_STAR_SPEED_NORMAL
special SPECIAL_NPC_MOVE_TO
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
	.autostring 35 2 "PLAYER, da bist du ja!\nMal ehrlich, dieser Test war doch seltsam, oder?\pWer soll auf solche Fragen denn antworten könnenDOTS"
str_after_may_appeared:
	.autostring 35 2 "Sieh mal, da ist Maike.\pWie es ihr wohl nach dem Test geht?"
str_after_may_appeared_2:
	.autostring 35 2 "Wo bleibt denn nun Faun?\nIch bin schon ganz heiß auf diesen Feldtest!"
str_will_receive_pkmn_rival:
	.autostring 35 2 "PLAYER!\nMach jetzt!\pIch habe nicht den ganzen Tag Zeit, auf deine Entscheidung zu warten.\pIch will auch ein Pokémon haben!"
str_catch_pkmn_rival:
	.autostring 35 2 "Du brauchst für alles eine Ewigkeit!\pLos, mach schon!\nFang das Pokémon ein!"
str_battle_rival:
	.autostring 35 2 "Na los, PLAYER!\nWorauf wartest du?\pIch bin schon ganz heiß drauf, gegen dich zu kämpfen!"
str_results_rival:
	.autostring 35 2 "Viel Glück, PLAYER!\nDu wirst es brauchen!"
str_goodbye_rival:
	.autostring 35 2 "Also, PLAYER!\nJetzt sind wir beide Trainer, hu?\pDu weißt was das heißt, oder?\pJetzt kann uns nichts mehr aufhalten.\pWenn du mich einholen willst, solltest du dich besser ranhalten!"
.elseif LANG_EN
str_make_may_appear:
	.autostring 35 2 "PLAYER, there you are.\pLet's be honest, that exam was weird, wasn't it?\pI mean, who could have answered these questions?"
str_after_may_appeared:
	.autostring 35 2 "Look, that's May.\pI wonder how she's doing after that testDOTS"
str_after_may_appeared_2:
	.autostring 35 2 "Where the heck is Faun?\pI want to do the field test!"
str_will_receive_pkmn_rival:
	.autostring 35 2 "PLAYER!\nHurry up!\pI don't have all day to wait for your decision.\pI also want to have Pokémon!"
str_catch_pkmn_rival:
	.autostring 35 2 "You always need for ever, PLAYER!\pHurry up, catch that Pokémon!"
str_battle_rival:
	.autostring 35 2 "Come on, PLAYER!\pWhat are you waiting for?\pI can't wait to battle you!"
str_results_rival:
	.autostring 35 2 "Good luck, PLAYER!\pYou will need it!"
str_goodbye_rival:
	.autostring 35 2 "So, PLAYER!\nNow the two of as are trainers, huh?\pYou know what that means, right?\pNow we can't be stopped!\pTry catching up to me if you can!"

.endif

mov_face_right:
	.byte LOOK_RIGHT, STOP

mov_face_left:
	.byte LOOK_LEFT, STOP

.include "ordinals.s"
.include "vars.s"
.include "movements.s"
.include "callstds.s"
.include "mugshot.s"
.include "flags.s"
.include "overworld_script.s"
.include "items.s"
.include "levelscript_types.s"
.include "healingplaces.s"
.include "story_states.s"
.include "specials.s"

.global lscr_0x718dc8

lscr_0x718dc8:
	.byte 0x2
	.word lscr_0x71a5df
	.byte LEVELSCRIPT_TYPE_ON_TRANSITION
    .word script_set_healingplace
	.byte 0x0


script_set_healingplace:
	// sethealingplace HEALINGPLACE_TANNS_LAB
    setworldmapflag WM_TANNS_LAB
end


.align 4
.global lscr_0x71a5df

lscr_0x71a5df:
	.hword STORY_PROGRESS, 0xe
	.word ow_script_0x8a7586
	.hword 0x0

.global ow_script_0x8ab100
.global ow_script_0x8a7586
.global ow_script_0x8a9640
.global ow_script_0x8aac32
.global ow_script_0x8a934f
.global ow_script_0x8ad21f

ow_script_movs_0x8a820e:
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STOP


ow_script_movs_0x8a8214:
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_LEFT
.byte STEP_UP
.byte STOP


ow_script_movs_0x80358f:
.byte LOOK_UP
mov_exclam:
.byte SAY_EXCLAM
.byte STOP


ow_script_movs_0x8a7f34:
    .byte STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT
    .byte STEP_UP, STEP_UP
    .byte STOP


ow_script_movs_0x8a7f2b:
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte FACE_DOWN
.byte STOP


ow_script_movs_0x8a794f:
.byte SAY_QUESTION
.byte STOP


ow_script_movs_0x8a792d:
.byte LOOK_LEFT
.byte STOP


ow_script_movs_0x8a78ed:
.byte SAY_EXCLAM
.byte STOP


ow_script_0x8a7586:
applymovement 0x3 mov_3u
applymovement 0xff ow_script_movs_0x8a8214
waitmovement 0x0
loadpointer 0x0 str_0x8a7f97
show_mugshot MUGSHOT_TANN MUGSHOT_RIGHT message_type=MSG_KEEPOPEN hide_mugshot=0
update_mugshot_emotion MUGSHOT_RUMINATIVE
loadpointer 0 str_0x8a7f97_2
callstd MSG
hide_mugshot
loadpointer 0 str_rival_1
show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT message_type=MSG emotion=MUGSHOT_ANGRY
loadpointer 0 str_prof_response
show_mugshot MUGSHOT_TANN MUGSHOT_RIGHT message_type=MSG emotion=MUGSHOT_RUMINATIVE
loadpointer 0 str_rival_2
show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT message_type=MSG emotion=MUGSHOT_SHOCKED
loadpointer 0 str_prof_response2
show_mugshot MUGSHOT_TANN MUGSHOT_RIGHT message_type=MSG_KEEPOPEN emotion=MUGSHOT_RUMINATIVE hide_mugshot=0
update_mugshot_emotion MUGSHOT_HAPPY
loadpointer 0 str_prof_response3
callstd MSG_KEEPOPEN
update_mugshot_emotion MUGSHOT_RUMINATIVE
loadpointer 0 str_prof_response4
callstd MSG
hide_mugshot
pause 16
applymovement 2 mov_fr
waitmovement 0
loadpointer 0 str_elise_interrupts
show_mugshot MUGSHOT_ELISE MUGSHOT_RIGHT message_type=MSG emotion=MUGSHOT_ANNOYED
pause 16

sound 0x15
applymovement 1 mov_exclam
waitmovement 0
checksound
loadpointer 0 str_0x8a7f97_3
show_mugshot MUGSHOT_TANN MUGSHOT_RIGHT message_type=MSG emotion=MUGSHOT_HAPPY hide_mugshot=0
update_mugshot_emotion MUGSHOT_NORMAL
loadpointer 0 str_0x8a7f97_4
callstd MSG
hide_mugshot

applymovement 3 mov_fd
applymovement 0xFF mov_fd
waitmovement 0
applymovement 0x2 ow_script_movs_0x8a7f34
waitmovement 0x0

loadpointer 0x0 str_0x8a7e8d
show_mugshot MUGSHOT_TANN MUGSHOT_RIGHT
loadpointer 0x0 str_0x8a7dbf
show_mugshot MUGSHOT_ELISE MUGSHOT_RIGHT
loadpointer 0x0 str_0x8a78f1
show_mugshot MUGSHOT_TANN MUGSHOT_RIGHT emotion=MUGSHOT_ANNOYED
sound 0x15
applymovement 0x2 ow_script_movs_0x8a78ed
waitmovement 0x0
checksound
loadpointer 0x0 str_0x8a7830
show_mugshot MUGSHOT_ELISE MUGSHOT_RIGHT emotion=MUGSHOT_SCARED
loadpointer 0x0 str_0x8a77ae
show_mugshot MUGSHOT_TANN MUGSHOT_RIGHT
applymovement 3 mov_fu
applymovement 0xFF mov_fu
waitmovement 0

loadpointer 0x0 str_0x8a7789
show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT
loadpointer 0x0 str_0x8a776a
show_mugshot MUGSHOT_PLAYER MUGSHOT_LEFT MSG_FACE
goto ow_script_0x8a934f


ow_script_movs_0x8a7761:
.byte STEP_RIGHT
.byte LOOK_UP
.byte STEP_IN_PLACE_UP
.byte STEP_IN_PLACE_UP
.byte STOP

ow_script_movs_0x8a774a:
.byte STEP_UP
.byte STEP_UP
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_DOWN
.byte STOP


ow_script_movs_0x803489:
.byte LOOK_UP
.byte STOP


ow_script_movs_0x8aa36d:
.byte STEP_IN_PLACE_DOWN
.byte STEP_IN_PLACE_DOWN
.byte STEP_IN_PLACE_DOWN
.byte STOP

mov_to_player:
    .byte STEP_LEFT, LOOK_DOWN, STOP

ow_script_movs_0x8aa1b5:
.byte LOOK_LEFT
.byte STOP

mov_face_down:
.byte FACE_DOWN
.byte STOP


ow_script_movs_0x8a9a49:
.byte LOOK_RIGHT
.byte STOP

mov_elise_to_boxes:
    .byte STEP_DOWN
    .byte STEP_LEFT, STEP_LEFT
    .byte STEP_DOWN
    .byte STOP

mov_elise_back:
    .byte STEP_UP
    .byte STEP_RIGHT
    .byte STEP_UP
    .byte STOP

ow_script_0x8a934f:
applymovement 3 mov_fd
applymovement 0xFF mov_fd
waitmovement 0
applymovement 2 mov_elise_to_boxes
waitmovement 0
pause 16
sound 23
checksound
pause 16
applymovement 2 mov_elise_back
waitmovement 0

fanfare 0x13e
loadpointer 0x0 str_0x8aa319
callstd MSG_KEEPOPEN
setflag POKEDEX
closeonkeypress
waitfanfare
applymovement 2 mov_elise_to_rival
waitmovement 0

loadpointer 0x0 str_0x8a7751
show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT
applymovement 3 mov_fu
applymovement 0xFF mov_fu
waitmovement 0
loadpointer 0x0 str_0x8a76ee
show_mugshot MUGSHOT_TANN MUGSHOT_RIGHT
loadpointer 0x0 str_0x8aabee
show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT

loadpointer 0x0 str_0x8aa57d
show_mugshot MUGSHOT_ELISE MUGSHOT_RIGHT emotion=MUGSHOT_ANNOYED
loadpointer 0x0 str_0x8aa381
show_mugshot MUGSHOT_TANN MUGSHOT_RIGHT emotion=MUGSHOT_HAPPY hide_mugshot=0 message_type=MSG_KEEPOPEN
update_mugshot_emotion MUGSHOT_NORMAL
loadpointer 0 str_0x8aa381_2
callstd MSG
hide_mugshot
loadpointer 0x0 str_0x8aa372
show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT emotion=MUGSHOT_RUMINATIVE hide_mugshot=0 message_type=MSG_KEEPOPEN
update_mugshot_emotion MUGSHOT_HAPPY
loadpointer 0 str_0x8aa372_2
callstd MSG
hide_mugshot
applymovement 0x1 ow_script_movs_0x8aa36d
waitmovement 0x0
pause 32

applymovement 0x1 mov_to_player
waitmovement 0x0

fanfare 0x13e
applymovement 0x1 ow_script_movs_0x8aa36d
loadpointer 0x0 str_0x8aa338
callstd MSG_KEEPOPEN
waitfanfare
waitmovement 0
loadpointer 0x0 str_0x8aa27f
show_mugshot MUGSHOT_TANN MUGSHOT_RIGHT
loadpointer 0x0 str_0x8aa22a
show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT

loadpointer 0x0 str_0x8aa1b8
show_mugshot MUGSHOT_ELISE MUGSHOT_RIGHT emotion=MUGSHOT_SHOCKED

loadpointer 0x0 str_0x8aa184
show_mugshot MUGSHOT_TANN MUGSHOT_RIGHT emotion=MUGSHOT_HAPPY

loadpointer 0x0 str_0x8a9a4c
show_mugshot MUGSHOT_TANN MUGSHOT_RIGHT
loadpointer 0x0 str_0x8a99f1
show_mugshot MUGSHOT_ELISE MUGSHOT_RIGHT
loadpointer 0x0 str_0x8a9950
show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT MSG_FACE emotion=MUGSHOT_HAPPY
goto ow_script_0x8a9640


ow_script_movs_0x8ab040:
.byte FACE_DOWN
.byte STOP


ow_script_movs_0x8aafce:
    .byte STEP_DOWN, STEP_DOWN
    .byte STEP_LEFT, STEP_LEFT, STEP_LEFT, STEP_LEFT, STEP_LEFT
    .byte STOP


ow_script_0x8aac32:
loadpointer 0x0 str_0x8ab043
show_mugshot MUGSHOT_TANN MUGSHOT_RIGHT
loadpointer 0x0 str_0x8aafd4
show_mugshot MUGSHOT_ELISE MUGSHOT_RIGHT

loadpointer 0 str_tann_end
show_mugshot MUGSHOT_TANN MUGSHOT_RIGHT emotion=MUGSHOT_ANGRY hide_mugshot=0 message_type=MSG_KEEPOPEN

loadpointer 0 str_tann_end_happy
update_mugshot_emotion MUGSHOT_HAPPY
callstd MSG
hide_mugshot


loadpointer 0x0 str_elise_end
show_mugshot MUGSHOT_ELISE MUGSHOT_RIGHT emotion=MUGSHOT_ANNOYED

applymovement 3 mov_fd
applymovement 0xFF mov_fd
waitmovement 0

loadpointer 0 str_elise_end4
show_mugshot MUGSHOT_ELISE MUGSHOT_RIGHT emotion=MUGSHOT_NORMAL message_type=MSG
applymovement 0x2 ow_script_movs_0x8aafce
waitmovement 0x0
setflag ROUTE_2_RIVAL_INSIDE_LAB
setvar STORY_PROGRESS 0xf
setvar VAR_STORY_STATE STORY_STATE_ROUTE_2_TANN_DONE
sound 0x15
applymovement 3 mov_fu
applymovement 0xFF mov_fu
waitmovement 0
applymovement 1 mov_exclam
waitmovement 0
checksound
loadpointer 0 str_tann_transition
show_mugshot MUGSHOT_TANN MUGSHOT_RIGHT emotion=MUGSHOT_NORMAL message_type=MSG
applymovement 1 mov_tann_away
waitmovement 0
sound 9
hidesprite 1
checksound
releaseall
end

ow_script_0x8a9640:
goto ow_script_0x8aac32


ow_script_0x8ab100:
fanfare 0x13e
additem ITEM_POKEBALL 0x5
setvar 0x8004, ITEM_POKEBALL
special SPECIAL_ITEM_OBTAIN_SHOW_DESCRIPTION
loadpointer 0x0 str_0x8ad201
callstd MSG_KEEPOPEN
closeonkeypress
waitfanfare
special SPECIAL_ITEM_OBTAIN_DELETE_DESCRIPTION
return


ow_script_movs_0x8037d2:
.byte FACE_DOWN
.byte STOP

mov_elise_to_rival:
    .byte STEP_RIGHT
    .byte STEP_IN_PLACE_UP, STEP_IN_PLACE_UP
    .byte STOP

mov_tann_away:
    .byte STEP_RIGHT, STEP_UP, STOP

.ifdef LANG_GER

str_0x8a7f97:
    .autostring 34 2 "PLAYER und RIVAL!\pFrisch gebackene Trainer und schon helft ihr diesem alten Herren aus der Patsche!"
str_0x8a7f97_2:	
    .autostring 34 2 "Diese Violet LeuteDOTS\pSeit einiger Zeit stiften sie hier in Theto UnruheDOTS"
str_rival_1:
    .autostring 34 2 "Aber was wollten diese Leute denn von dir, Papa?"
str_prof_response:
    .autostring 34 2 "Na, das ist eine gute FrageDOTS\pSie haben mich wegen eines Artifakts bedrängt, das man den Zeitstein nenntDOTS"
str_rival_2:
    .autostring 34 2 "Den was?"
str_prof_response2:
    .autostring 34 2 "Schön, dass du fragst!\pEr wird in einigen alten Texten der antiken Zivilisation, die früher Theto bewohnt hat, erwähnt.\pIhm werden viele mystische Kräfte zugeschriebenDOTS"
str_prof_response3:
    .autostring 34 2 "Es gibt nicht viele ernsthafte Forscher, die daran glauben!"
str_prof_response4:
    .autostring 34 2 "Die Geschichte um den Stein ist wahnsinnig aufregend.\pLaut einer Reihe von alten Texten, die ich unlängst entdeckt habe, nutzte man vor dem Verhängnis den Stein, um Dinge aus der Vergangenheit und Zukunft zu sehen.\pUnd als dann die Katastrophe hereinbrach-"
str_elise_interrupts:
    .autostring 34 2 "Professor, Sie driften wieder einma abDOTS"
str_0x8a7f97_3:
    .autostring 34 2 "Oh, natürlich!\pIch lasse mich immer so hinreißenDOTS"
str_0x8a7f97_4:
    .autostring 34 2 "Das erinnert michDOTS\pWürdest du einmal herkommen, Elise?"

str_0x8a7e8d:
	.autostring 34 2 "Darf ich vorstellen?\nDas ist Elise, eine Gastforscherin in meinem Labor und ein wahres Naturtalent, wenn es um die Erforschung von Pokémon geht.\pSie arbeitet für die Laz. Corp an der Virtualisierung von Pokémon.\pDas PC-System wurde von ihr maßgeblich mitentwickelt."
str_0x8a7dbf:
	.autostring 34 2 "Freut mich außerordentlich!\pEndlich lerne ich dich einmal kennen, RIVAL!\pDein Vater hat schon so viel von dir erzählt!\pDu scheinst ja genauso ein Hitzkopf zu sein."
str_0x8a78f1:
    .autostring 34 2 "Was soll das denn heißen?"
str_0x8a7830:
	.autostring 34 2 "Naja, ähDOTS"
str_0x8a77ae:
    .autostring 34 2 "Würdest du bitte, naja, du weißt-schon-was holen?\pIch möchte euch nämlich ein Geschenk machen, RIVAL und PLAYER!"
str_0x8a7789:
    .autostring 34 2 "Wirklich? Fantastisch, Papi!"
str_0x8a776a:
    .autostring 34 2 "Vielen Dank, Professor Tann."
str_0x8aa319:
    .autostring 34 2 "PLAYER hat das Poképad erhalten!"
str_0x8a7751:
    .autostring 34 2 "Danke, Elise!"
str_0x8a76ee:
    .autostring 34 2 "Das Ganze ist allerdings mit einer Bitte verbunden."
str_0x8aabee:
    .autostring 34 2 "Och, du bist ein immer so ein Spielverderber, Papi!"
str_0x8aa57d:
    .autostring 34 2 "Der Apfel fällt nicht weit vom StammDOTS"
str_0x8aa381:
	.autostring 34 2 "Du bist wirklich unmöglich, RIVAL!"
str_0x8aa381_2:
    .autostring 34 2 "Wie bereits gesagt, forscht Elise an der Virtualisierung von Pokémon.\pUnd dafür benötigt sie jede Menge Daten über allerlei verschiedene Spezies.\pAls Gegenleistung für das Poképad bitte ich euch, die Daten der Pokémon, die ihr einfangt, in der Pokédex-App zu registrieren."
str_0x8aa372:
    .autostring 34 2 "Wir sollen Pokémon fangen?"
str_0x8aa372_2:
    .autostring 34 2 "Sag das doch gleich!\pDas geht in Ordnung, Papi!"
str_0x8aa338:
    .autostring 34 2 "Die Pokedex-App wurde auf dem Poképad installiert!"
str_0x8aa305:
    .autostring 34 2 "Dankesehr!"
str_0x8aa27f:
	.autostring 34 2 "Ich wusste, dass ich mich auf euch verlassen kann.\pIch hoffe doch, der alte Faun hat euch in der Trainerschule beigebracht, wie man ein Pokémon fängt?"
str_0x8aa22a:
    .autostring 34 2 "Natürlich, Papi!\pWas für eine Frage!"
str_0x8aa1b8:
    .autostring 34 2 "Ihr seid Schüler vom Pinken Faun?"
str_0x8aa184:
    .autostring 34 2 "Für meinen Sohn nur die besten Lehrer!"
str_0x8a9f82:
	.autostring 34 2 "Aber es ist gut zu hören, dass ihr wisst, wie man Pokémon einfängt.\pDann werdet ihr sicher wissen, was mit denen hier zu tun ist, nicht?"
str_0x8a9c83:
    .autostring 34 2 "RIVAL hat 5 Pokebälle erhalten!"
str_0x8a9a4c:
    .autostring 34 2 "Ich bin wirklich stolz auf dich, RIVAL!"
str_0x8a99f1:
    .autostring 34 2 "Und denkt daran, so viele verschiedene Pokémon wie möglich zu fangen!"
str_0x8a9950:
    .autostring 34 2 "Aber sicher!\nImmerhin werde ich eines Tages der größte Trainer dieser Region sein.\pDa muss man sich mit einer Menge Pokémon auskennen!"
str_0x8ad201:
    .autostring 34 2 "PLAYER hat fünf\nPokébälle erhalten!"
str_0x8ab043:
    .autostring 34 2 "Und dir auch alles Gute, PLAYER, ja?"
str_0x8aafd4:
	.autostring 34 2 "Und nehmt euch in Acht vor solchen Leuten wie diese Violet Rüpel.\pErst die Revolutionsbewegung und dann diese TypenDOTS\pEs ist keine Schande, einem gefährlichen Kampf auch einmal aus dem Weg zu gehen."
str_tann_end:
    .autostring 34 2 "Quatsch!\pLasst euch von niemanden etwas einreden!\pSteht für eure Ziele und Träume ein, verstanden?"
str_tann_end_happy:
    .autostring 34 2 "Ihr beide habt ein riesiges Potenzial!"
str_elise_end:
    .autostring 34 2 "Wie verantwortungslosDOTS"
str_elise_end4:
    .autostring 34 2 "Gebt einfach etwas auf euch Acht ja?\pUnd wenn ihr mir mit dem Vervollständigen des Pokédex helfen könnt, wäre ich euch sehr dankbar!\pViel Glück euch beiden!"
str_tann_transition:
    .autostring 34 2 "Also gut!\pMeine Arbeit wartet!\pGebt stets euer Bestes, ja?"
.elseif LANG_EN

.endif
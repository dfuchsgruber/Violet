.include "items.s"
.include "callstds.s"
.include "flags.s"
.include "movements.s"
.include "overworld_script.s"
.include "mugshot.s"
.include "specials.s"
.include "battle/battle_handicaps.s"

.global ow_script_inferior_gym_battle
ow_script_inferior_gym_battle:
lockall
pause 0x10
special 0x113
applymovement 0x7f mov_camera
waitmovement 0x0
special 0x114
pause 0x10
applymovement 0x1 mov_referee_down
waitmovement 0x0
loadpointer 0x0 str_referee
callstd MSG
applymovement 0x2 mov_igva
applymovement 0xff mov_player
waitmovement 0x0
draw_mugshot MUGSHOT_IGVA MUGSHOT_LEFT
special SPECIAL_BATTLE_HANDICAP_CLEAR
setvar 0x8004 BATTLE_HANDICAP_EXTREME_HEAT
special SPECIAL_BATTLE_HANDICAP_SET
trainerbattlecont 0x1 0xc4 0x0 str_challange str_defeat ow_script_after_battle
ow_script_after_battle:
loadpointer 0 str_after_battle
show_mugshot MUGSHOT_IGVA MUGSHOT_LEFT
loadpointer 0x0 str_receive_badge
fanfare 0x104
callstd MSG_KEEPOPEN
waitfanfare
closeonkeypress
setflag FRBADGE_4
loadpointer 0 str_tm
show_mugshot MUGSHOT_IGVA MUGSHOT_LEFT
copyvarifnotzero 0x8000 ITEM_TM50
copyvarifnotzero 0x8001 1
callstd ITEM_OBTAIN
loadpointer 0 str_leave
show_mugshot MUGSHOT_IGVA MUGSHOT_LEFT
cleartrainerflag 0xBF
cleartrainerflag 0xC0
cleartrainerflag 0xC1
cleartrainerflag 0xC2
cleartrainerflag 0xC3
warpmuted 3 6 0 0 0
waitstate
releaseall
end

.ifdef LANG_GER

str_referee:
	.autostring 34 2 "Hiermit eröffne ich den Kampf zwischen PLAYER und Igva um den Vulkanorden!"
str_challange:
	.autostring 34 2 "Also PLAYER!\nIch werde dich nicht schonen.\pMeine Pokémon brennen darauf, es mit deinen aufzunehmen!\pJetzt wird es extra heiß!"
str_defeat:
	.autostring 34 2 "Wahnsinn!\pDu konntest selbst in der Hitze des Gefechts noch Ruhe bewahren."
str_after_battle:
	.autostring 34 2 "Es überrascht mich nun ganz und gar nicht mehr, dass du es selbst mit einem legendären Pokémon aufnehmen konntest.\pDu bist wirklich ein äußert talentierter Trainer.\pIch überreiche dir den Vulkanorden wirklich gerne!"
str_receive_badge:
	.autostring 34 2 "PLAYER hat den Vulkanorden von Igva erhalten!"
str_tm:
	.autostring 34 2 "Dieser Orden erlaubt es dir, die Versteckte Maschine Surfer außerhalb des Kampfes einzusetzten.\pAußerdem gehorchen dir getauschte Pokémon bis Level 60.\pAls Dankeschön für deine Hilfe vorhin, möchte ich dir außerdem noch das hier geben."
str_leave:
	.autostring 34 2 "Diese Tm enthält Hitzekoller.\pDer Angriff ist enorm wirkungsvoll, verlangt dem Anwender aber auch einiges ab.\pNutze die Attacke mit Bedacht, PLAYER.\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pWas wirst du nun tun?\nMistral ist immer noch da draußen.\pIch denke nicht, dass er so schnell nachgeben wird.\pEr war mir früher einmal sehr wichtig.\pBevor er sich in seinen Phantasien von Macht und Stärke verloren hat, war er ein mutiger und talentierter TrainerDOTS\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pDu erinnerst mich ein bisschen an ihn, weißt du, PLAYERDOTS\pEs wäre mir ein persönliches Anliegen, wenn du dich seiner annehmen könntest.\pIch weiß, dass ich viel verlange, PLAYER, aber ich weiß, dass wenn es jemandem gelingen kann, du es bist.\pIch hoffe, wir sehen uns eines Tages wieder, PLAYER.\pBis dahin, wünsche ich dir nur das Beste!"

.elseif LANG_EN

str_referee:
	.autostring 34 2 "Hereby I announce the fight between Igva and PLAYER for the Vulcano Badge!"
str_challange:
	.autostring 34 2 "Now PLAYER!\pI will not go easy on you.\pMy Pokémon are burning to fight yours!\pNow it's getting extra hot!"
str_defeat:
	.autostring 34 2 "Amazing!\pEven in the heat of the fight you stayed calm and cool."
str_after_battle:
	.autostring 34 2 "It doesn't suprise me at all now that you were able to defeat even a legendary Pokémon.\pYou are an extraordinarily talented trainer.\pWith much pleasure I will hand you over the Vulcano Badge!"
str_receive_badge:
	.autostring 34 2 "PLAYER received the Vulcano Badge from Igva!"
str_tm:
	.autostring 34 2 "This badge allows you to use the Hidden Machine Surfer outside of a battle.\pFurthermore, traded Pokémon up to level 60 will obey you.\pAs an additional thank you I want to provide you with this as well."
str_leave:
	.autostring 34 2 "This Tm contains Overheat.\pIts a very powerfull move that however requires equally much from its user.\pUtilize it carefully, PLAYER.\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pWhat will you do now?\nMistral is still out there.\pI don't think he will stop anytime soon.\pIn the past he was very important to meDOTS\pBefore he lost himself in phatasies of power and strength, he was a courageous and talented trainerDOTS\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pYou are somewhat like him, you know, PLAYER?\pIt is a matter of my heart if you could handle him.\pI know, that if anyone could succeed in this task, it would be you.\pProbably I am demanding too much, PLAYER, but I am positive you can do it.\pI really hope we will see one day, PLAYER.\pUntil then I wish you nothing but the very best."
.endif

mov_camera:
	.byte STEP_LEFT, STEP_LEFT, STEP_LEFT, STEP_LEFT, STEP_LEFT, STOP

mov_referee_down:
	.byte STEP_DOWN, STOP

mov_player:
	.byte STEP_LEFT, STOP

mov_igva:
	.byte STEP_RIGHT, STOP


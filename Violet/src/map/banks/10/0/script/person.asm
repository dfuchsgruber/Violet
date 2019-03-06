.include "overworld_script.s"
.include "callstds.s"
.include "flags.s"
.include "ordinals.s"

.global ow_script_inferior_gym_trainer_0
ow_script_inferior_gym_trainer_0:
trainerbattlestd 0 0xbf 0 str_trainer0_challange str_trainer0_defeat
loadpointer 0 str_trainer0_defeat
callstd MSG_FACE
end

.ifdef LANG_GER

str_trainer0_challange:
	.autostring 34 2 "In dieser Arena glüht einem der Schädel!\pIch werde dich zum Kochen bringen, Kindchen!"

str_trainer0_defeat:
	.autostring 34 2 "Wah! Mir wird ganz schwindligDOTS"

.elseif LANG_EN
str_trainer0_challange:
	.autostring 34 2 "In this gym one's head is heating pretty fast!\pI will make your senses boil, you brat!"

str_trainer0_defeat:
	.autostring 34 2 "Woah! I am feeling dizzyDOTS"
.endif


.global ow_script_inferior_gym_trainer_1
ow_script_inferior_gym_trainer_1:
trainerbattlestd 0 0xc0 0 str_trainer1_challange str_trainer1_defeat
loadpointer 0 str_trainer1_defeat
callstd MSG_FACE
end

.ifdef LANG_GER

str_trainer1_challange:
	.autostring 34 2 "Findest du nicht, dass meine Haut bei dieser Hitze wunderschön glänzt?\pWie eine Perle funkelt sie!"

str_trainer1_defeat:
	.autostring 34 2 "UrghDOTS\nSchweiß? Niemals würde jemand wie ich ins Schwitzen kommenDOTS"

.elseif LANG_EN
str_trainer1_challange:
	.autostring 34 2 "Don't you think my skin is sparkling beautifully in this heat?\pAlmost like a pearl!"

str_trainer1_defeat:
	.autostring 34 2 "UrghDOTS\nSweat? Never would someone like me be sweatingDOTS"
.endif

.global ow_script_inferior_gym_trainer_2
ow_script_inferior_gym_trainer_2:
trainerbattlestd 0 0xc1 0 str_trainer2_challange str_trainer2_defeat
loadpointer 0 str_trainer2_defeat
callstd MSG_FACE
end

.ifdef LANG_GER

str_trainer2_challange:
	.autostring 34 2 "Igva ist oft auf Reisen, um ihre Pokémon zu trainieren.\pSie ist unschlagbar!"

str_trainer2_defeat:
	.autostring 34 2 "Huch, du bist ganzschön stark!"

.elseif LANG_EN
str_trainer2_challange:
	.autostring 34 2 "Igva often is traveling to train her Pokémon.\pShe is invincible!"

str_trainer2_defeat:
	.autostring 34 2 "Huh, you're pretty strong!"
.endif

.global ow_script_inferior_gym_trainer_3
ow_script_inferior_gym_trainer_3:
trainerbattlestd 0 0xc2 0 str_trainer3_challange str_trainer3_defeat
loadpointer 0 str_trainer3_defeat
callstd MSG_FACE
end

.ifdef LANG_GER

str_trainer3_challange:
	.autostring 34 2 "Igva ist eine herzensgute Frau.\pWie sie versuche ich stets, für die gerechte Sache zu kämpfen!"

str_trainer3_defeat:
	.autostring 34 2 "Bist du gekommen, um sie zu stürzen?"

.elseif LANG_EN
str_trainer3_challange:
	.autostring 34 2 "Igva is an honest person.\pLike her, I am always eager to fight for the righteous cause!"

str_trainer3_defeat:
	.autostring 34 2 "Have you come to overthrow her?"
.endif


.global ow_script_inferior_gym_trainer_4
ow_script_inferior_gym_trainer_4:
trainerbattlestd 0 0xc3 0 str_trainer4_challange str_trainer4_defeat
loadpointer 0 str_trainer4_defeat
callstd MSG_FACE
end

.ifdef LANG_GER

str_trainer4_challange:
	.autostring 34 2 "Drachen-Pokémon sind in der Lage, die heißesten Flammen zu speien!\pSehen wir mal, ob du dem standhalten kannst!"

str_trainer4_defeat:
	.autostring 34 2 "Du bist ziemlich hitzeresistent, Kindchen!"

.elseif LANG_EN
str_trainer4_challange:
	.autostring 34 2 "Dragon-Pokémon are capable to breathe the most hot flames!\pLet's see if you can withstand them!"

str_trainer4_defeat:
	.autostring 34 2 "You are somewhat heatproof, kiddy!"
.endif

.global ow_script_inferior_gym_igva
ow_script_inferior_gym_igva:
checkflag FRBADGE_4
gotoif EQUAL badge_obtained
lock
faceplayer
call ow_script_0x92f097
loadpointer 0x0 str_igva_before_battle
callstd MSG
special 0x7
warpmuted 10 1 255 0xF 0x4
waitstate
release
end

badge_obtained:
call ow_script_0x92f097
loadpointer 0x0 str_igva_after_battle
callstd MSG_FACE
special 0x7
end

.ifdef LANG_GER

str_igva_before_battle:
	.autostring 34 2 "PLAYER.\nIch bin dir für deine Hilfe am Volcano unendlich dankbar.\pOhne dich wären die Dinge vielleicht nicht so gut ausgegangen.\pIch habe aber auch nicht vergessen, dass du eigentlich gekommen bist, um mich herauszufordern.\pEs ist das Mindeste, was ich für dich tun kann.\pMach dich auf etwas gefasst, PLAYER!"

str_igva_after_battle:
	.autostring 34 2 "Was wirst du nun tun, PLAYER?\pWirst du versuchen, Mistral aufzuhalten?"

.elseif LANG_EN
str_igva_before_battle:
	.autostring 34 2 "PLAYER.\nI am very grateful for your help on the Volcano peak.\pWithout you things wouldn't have turned out so well, I guess.\pBut I did not forget why you came here.\pYou want to a fight, right?\nIt's the least I can do for you.\pPrepeare yourself, PLAYER!"

str_igva_after_battle:
	.autostring 34 2 "What will you do now, PLAYER?\pDo you want to stop Mistral?"
.endif

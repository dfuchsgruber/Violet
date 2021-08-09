.include "vars.s"
.include "overworld_script.s"
.include "flags.s"
.include "callstds.s"
.include "ordinals.s"
.include "attacks.s"

.global ow_script_dungeon_item

ow_script_dungeon_item:
	copyvarifnotzero 0x8004 LASTTALKED
	callasm dungeon_special_item_by_overworld_idx
	copyvarifnotzero 0x8000 0x8005
	copyvarifnotzero 0x8001 1
	callstd ITEM_FIND
	end

.global ow_script_dungeon_encounter

ow_script_dungeon_encounter:
	lock
	faceplayer
	cry DUNGEON_OVERWORLD_SPECIES 0
	waitcry
	callasm dungeon2_set_encounter
	dowildbattle
	fadescreen 1
	hidesprite LASTTALKED
	fadescreen 0
	release
	end

.global ow_script_dungeon_enter
.global ow_script_dungeon_enter_field

ow_script_dungeon_enter:
	special2 0x8004 0x4B
	compare 0x8004 1
	gotoif EQUAL ow_script_dungeon2_enter_forest
	compare 0x8004 2
	gotoif EQUAL ow_script_dungeon2_enter_cave
	compare 0x8004 3
	gotoif EQUAL ow_script_dungeon2_enter_ocean
	end

ow_script_dungeon_enter_field:
	setanimation 0x0 LASTRESULT
	bufferpartypokemon 0x0 LASTRESULT
	bufferattack 0x1 ATTACK_GEHEIMPOWER
	special2 0x8004 0x4B
	compare 0x8004 1
	gotoif EQUAL ow_script_dungeon2_enter_forest_field
	compare 0x8004 2
	gotoif EQUAL ow_script_dungeon2_enter_cave_field
	compare 0x8004 3
	gotoif EQUAL ow_script_dungeon2_enter_ocean_field
	end

.global ow_script_dungeon_trainer_0
.global ow_script_dungeon_trainer_1
.global ow_script_dungeon_trainer_2
.global ow_script_dungeon_trainer_3

ow_script_dungeon_trainer_0:
	trainerbattlestd 0 0x1e0 0 str_before_0 str_after_0
	loadpointer 0 str_later_0
	callstd MSG_FACE
	end
ow_script_dungeon_trainer_1:
	trainerbattlestd 0 0x1e1 0 str_before_1 str_after_1
	loadpointer 0 str_later_1
	callstd MSG_FACE
	end
ow_script_dungeon_trainer_2:
	trainerbattlestd 0 0x1e2 0 str_before_2 str_after_2
	loadpointer 0 str_later_2
	callstd MSG_FACE
	end
ow_script_dungeon_trainer_3:
	trainerbattlestd 0 0x1e3 0 str_before_3 str_after_3
	loadpointer 0 str_later_3
	callstd MSG_FACE
	end

.ifdef LANG_GER
str_before_0:
	.autostring 34 2 "Wir Ranger nutzen Geheimpower, um verborgene Areale zu erkunden.\pMeinst du, du bist dieser Herausforderung gewachsen?"
str_after_0:
	.autostring 34 2 "Na gut, ich sehe es einDOTS\pDu bist ganz gut."
str_later_0:
	.autostring 34 2 "Du bist wirklich stark genug, um an diesem Ort zu sein.\pAber pass trotzdem auf dich auf."
str_before_1:
	.autostring 34 2 "Heh!\nIch hatte nicht damit gerechnet, hier auf ein Kind zu treffen."
str_after_1:
	.autostring 34 2 "Du hast mehr auf dem Kasten, als man vermuten würdeDOTS"
str_later_1:
	.autostring 34 2 "Meistens triffst du hier nur auf Ranger, die unerschlossene Gebiete erkunden.\pDiese verborgenen Orte hier sind ganz schön gefährlich."
str_before_2:
	.autostring 34 2 "Du benutzt also auch Geheimpower?\pZeig mir, wie stark du bist!"
str_after_2:
	.autostring 34 2 "Deine Geheimpower ist stärker als meineDOTS"
str_later_2:
	.autostring 34 2 "Es ist doch wirklich spannend, mit Geheimpower schwer zugängliche Areale zu erschließen, oder nicht?"
str_before_3:
	.autostring 34 2 "Was machst du denn hier?\pIch dachte, nur die Pokémon-Ranger benutzen Geheimpower.\pAber du bist keiner von ihnen!"
str_after_3:
	.autostring 34 2 "Hast was auf dem Kasten.\nNicht schlecht!"
str_later_3:
	.autostring 34 2 "Ich benutze Geheimpower, um seltene Pokémon zu finden.\pDas ist wirklich ein großer Spaß."
.elseif LANG_EN

.endif
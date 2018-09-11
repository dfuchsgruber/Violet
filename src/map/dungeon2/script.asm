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

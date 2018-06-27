.include "vars.s"
.include "overworld_script.s"
.include "flags.s"
.include "callstds.s"

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


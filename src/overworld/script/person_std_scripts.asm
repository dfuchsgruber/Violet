.include "callstds.s"
.include "overworld_script.s"

.global ow_script_person_pokeball
.global ow_script_person_egg

ow_script_person_pokeball:
	callstd ITEM_FIND
	end

ow_script_person_egg:
	call ow_script_find_egg
	end
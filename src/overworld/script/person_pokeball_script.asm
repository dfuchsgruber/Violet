.include "callstds.s"
.include "overworld_script.s"

.global ow_script_person_pokeball

ow_script_person_pokeball:
	callstd ITEM_FIND
	end

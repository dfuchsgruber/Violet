.include "callstds.s"
.include "overworld_script.s"

.global ow_script_clock_master_house_sign

ow_script_clock_master_house_sign:
	loadpointer 0 str
	callstd MSG_SIGN
	end

str:
	.autostring 35 2 "Haus des Uhrenmachers"
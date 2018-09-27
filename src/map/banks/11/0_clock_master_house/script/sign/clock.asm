.include "overworld_script.s"
.include "callstds.s"
.include "vars.s"
.include "time_types.s"
.include "ordinals.s"

.global ow_script_clock
ow_script_clock:
special2 LASTRESULT 0x8
compare LASTRESULT 0
gotoif EQUAL broken
callasm buffer_time
loadpointer 0 str_clock
callstd MSG
end


broken:
loadpointer 0 str_broken
callstd MSG
end



.ifdef LANG_GER
.global str_0x95c5d4

str_broken:
	.autostring 35 2 "Die Uhr scheint stehengeblieben zu sein DOTS"

str_clock:
	.string "Es ist BUFFER_1:BUFFER_2 Uhr."

.elseif LANG_EN

.endif

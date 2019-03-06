.include "overworld_script.s"
.include "callstds.s"
.include "flags.s"

.global ow_script_egg_hatch
ow_script_egg_hatch:
lockall
setflag TRANS_DISABLE
loadpointer 0 str_wie
callstd MSG_KEEPOPEN
special 0xC2
waitstate
clearflag TRANS_DISABLE
releaseall
end

.ifdef LANG_GER
str_wie:
	.autostring 35 2 "Wie?"
.elseif LANG_EN
str_wie:
	.autostring 35 2 "Huh?"
.endif


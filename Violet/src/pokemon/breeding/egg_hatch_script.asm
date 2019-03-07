.include "overworld_script.s"
.include "callstds.s"
.include "flags.s"
.include "vars.s"
.include "ordinals.s"

.global ow_script_egg_hatch
ow_script_egg_hatch:
lockall
compare 0x8004 6
gotoif HIGHER_OR_EQUAL incubator_hatchable
setflag TRANS_DISABLE
loadpointer 0 str_wie
callstd MSG_KEEPOPEN
special 0xC2
waitstate
clearflag TRANS_DISABLE
releaseall
end

incubator_hatchable:
loadpointer 0 str_incubator_hatchable
callstd MSG_KEEPOPEN
closeonkeypress
releaseall
end

.ifdef LANG_GER
str_wie:
	.autostring 35 2 "Wie?"
str_incubator_hatchable:
	.autostring 34 2 "Ein Ei im Inkubator scheint bald zu schlüpfen!"
.elseif LANG_EN
str_wie:
	.autostring 35 2 "Huh?"
str_incubator_hatchable:
	.autostring 34 2 "An egg inside the incubator seems to be hatching soon!"
.endif


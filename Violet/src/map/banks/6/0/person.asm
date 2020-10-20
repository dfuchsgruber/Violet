.include "vars.s"
.include "callstds.s"
.include "ordinals.s"
.include "overworld_script.s"
.include "flags.s"
.include "items.s"

.global ow_script_map_6_0_person_0

ow_script_map_6_0_person_0:
loadpointer 0 str
callstd MSG_FACE
end


.ifdef LANG_GER
str:
	.autostring 34 2 "Es ist deprimierend, was aus diesem einst so schönen Ort geworden istDOTS\pBruchfels ist nur noch ein Schatten seines früheren GlanzesDOTS"
.elseif LANG_EN
str:
	.autostring 34 2 "It's depressing what became of this once so beautiful placeDOTS\pBrokenrock is all but a shadow of its former gloryDOTS"
.endif
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
	.autostring 34 2 "Lester ist ein guter Junge.\pSein Vater wäre sicher stolz, zu sehen, wie er auf das Vermächtnis seiner Familie aufpasst."
.elseif LANG_EN
str:
	.autostring 34 2 "Lester is a good boy.\pHis father would be proud to see him care for the heritage of his family."
.endif
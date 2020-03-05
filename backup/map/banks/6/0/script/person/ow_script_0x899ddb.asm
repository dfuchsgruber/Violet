.include "flags.s"
.include "items.s"
.include "callstds.s"
.include "vars.s"
.include "ordinals.s"
.include "overworld_script.s"


.global ow_script_0x899ddb
ow_script_0x899ddb:
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

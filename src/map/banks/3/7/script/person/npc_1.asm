.include "callstds.s"
.include "overworld_script.s"
.include "vars.s"
.include "ordinals.s"

.global ow_script_route_2_east_npc_1
ow_script_route_2_east_npc_1:
loadpointer 0 str
callstd MSG_FACE
end


.ifdef LANG_GER

str:
	.autostring 35 2 "Irgendwo hier auf Route 2 hat Professor Tann sein Labor.\pEr ist Archäologe und das Museum in Orina City hat ihm bereits viele Ausstellungsstücke zu verdanken."
.elseif LANG_EN

.endif

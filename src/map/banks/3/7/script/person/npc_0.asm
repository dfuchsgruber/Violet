.include "callstds.s"
.include "overworld_script.s"
.include "vars.s"
.include "ordinals.s"

.global ow_script_route_2_east_npc_0
ow_script_route_2_east_npc_0:
loadpointer 0 str
callstd MSG_FACE
end


.ifdef LANG_GER

str:
	.autostring 35 2 "Route 2 gilt als eine der längsten Routen Thetos.\pSie ist ein zentraler Knotenpunkt dieser Region, da man in alle Himmelsrichtungen angebunden ist."

.elseif LANG_EN

.endif

.include "callstds.s"
.include "overworld_script.s"
.include "vars.s"
.include "ordinals.s"

.global ow_script_route_2_east_npc_2
ow_script_route_2_east_npc_2:
loadpointer 0 str
callstd MSG_FACE
end


.ifdef LANG_GER

str:
	.autostring 35 2 "Ich finde es spannend, durch Versteckte Maschinen geheime Areale zu erkunden!\pMeinst du nicht auch, dass das aufregend ist?"

.elseif LANG_EN

.endif

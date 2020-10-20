.include "vars.s"
.include "callstds.s"
.include "ordinals.s"
.include "overworld_script.s"
.include "flags.s"
.include "species.s"
.include "items.s"

.global ow_script_route_2_scientist
.global ow_script_route_2_east_npc_0
.global ow_script_route_2_east_npc_1
.global ow_script_route_2_east_npc_2


ow_script_route_2_east_npc_0:
loadpointer 0 str1
callstd MSG_FACE
end

.ifdef LANG_GER

str1:
	.autostring 35 2 "Route 2 gilt als eine der längsten Routen Thetos.\pSie ist ein zentraler Knotenpunkt dieser Region, da man in alle Himmelsrichtungen angebunden ist."

.elseif LANG_EN
str1:
	.autostring 34 2 "Route 2 is said to be one of the longest routes in Theto.\pIt is a central hub of this region, since you are connected in each direction."
.endif

ow_script_route_2_east_npc_1:
loadpointer 0 str2
callstd MSG_FACE
end


.ifdef LANG_GER

str2:
	.autostring 35 2 "Irgendwo hier auf Route 2 hat Professor Tann sein Labor.\pEr ist Archäologe und das Museum in Orina City hat ihm bereits viele Ausstellungsstücke zu verdanken."
.elseif LANG_EN
str2:
	.autostring 34 2 "Somewhere here on Route 2 Professor Fig has his laboratory.\pHe is an archeologist and most of the exhibition in the Orina City Museum is due to him."
.endif

ow_script_route_2_east_npc_2:
loadpointer 0 str3
callstd MSG_FACE
end


.ifdef LANG_GER

str3:
	.autostring 35 2 "Ich finde es spannend, durch Versteckte Maschinen geheime Areale zu erkunden!\pMeinst du nicht auch, dass das aufregend ist?"

.elseif LANG_EN
str3:
	.autostring 34 2 "I think it is very exciting to explore areas using Hidden Machines.\pDon't you think so too?"
.endif

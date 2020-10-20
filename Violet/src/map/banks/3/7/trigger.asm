.include "ordinals.s"
.include "vars.s"
.include "callstds.s"
.include "mugshot.s"
.include "overworld_script.s"
.include "pathfinding.s"


.global ow_script_route_2_felix

ow_script_route_2_felix:
	addvar STORY_PROGRESS 1
	releaseall
	end

/** 
.global ow_script_route_2_felix

ow_script_route_2_felix:
lockall
npc_move_to_player 3
setvar LASTTALKED 0x3
faceplayer
loadpointer 0 str_hello
show_mugshot MUGSHOT_FELIX MUGSHOT_RIGHT
call ow_script_healing_sequence
loadpointer 0 str_after_healing
show_mugshot MUGSHOT_FELIX MUGSHOT_RIGHT
npc_move_to 3 0x7 0x19
hidesprite 3
addvar STORY_PROGRESS 1
releaseall
end

.ifdef LANG_GER


str_hello:
	.autostring 35 2 "Hallo, PLAYER!\nRoute 2 ist als eine der längsten Routen Thetos bekannt.\pDu solltest dir zuerst eine kleine Pause gönnen, wenn du es bis zum Ende schaffen möchtest."

str_after_healing:
	.autostring 35 2 "Bist zu zufällig Blaise begegnet?\pIch möchte mit ihm reden und ihn zur Vernunft bringen DOTS\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pWie schade!\nAber wenn er tatsächlich vorhaben sollte, sich mit seinem Vater anzulegen DOTS\pDOTS kann das böse ins Auge gehen.\pDOTS DOTS DOTS\pNa, wie auch immer, PLAYER!\pUnsere Wege trennen sich hier wieder.\pPass auf dich auf!"

.elseif LANG_EN

.endif

*/
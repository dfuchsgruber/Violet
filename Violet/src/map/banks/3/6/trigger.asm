.include "vars.s"
.include "callstds.s"
.include "mugshot.s"
.include "overworld_script.s"
.include "flags.s"
.include "pathfinding.s"

.global ow_script_map_3_6_trigger_0

ow_script_map_3_6_trigger_0:
lockall
clearflag PKMNMENU
showsprite 0x1
setvar LASTTALKED 0x1
npc_move_to_player 1
faceplayer
loadpointer 0x0 str_0x963705
show_mugshot MUGSHOT_IGVA MUGSHOT_LEFT
npc_move_to 1 0x22 0x19
hidesprite LASTTALKED
setflag PKMNMENU
addvar STORY_PROGRESS 0x1
setworldmapflag WM_INFERIOR
releaseall
end


.ifdef LANG_GER

str_0x963705:
	.autostring 35 2 "Hallo PLAYER.\pWillkommen in Inferior.\pDu wirst leider keine Zeit haben, meine schöne Stadt zu bewundern.\pDie Rüpel von hier zu vertreiben, wird nichts nützen, solange der Kommandant von Team Violet noch sein Unwesen treibt.\pWir sollten uns auf zum Vulcano machen."


.elseif LANG_EN

.endif
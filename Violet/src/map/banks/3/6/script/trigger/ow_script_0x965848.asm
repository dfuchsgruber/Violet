.include "callstds.s"
.include "flags.s"
.include "vars.s"
.include "overworld_script.s"
.include "mugshot.s"


.global ow_script_0x965848
ow_script_0x965848:
lockall
clearflag PKMNMENU
showsprite 0x1
setvar LASTTALKED 0x1
setvar 0x8004 0x1
special 0x1b
waitmovement 0x0
faceplayer
loadpointer 0x0 str_0x963705
show_mugshot MUGSHOT_IGVA MUGSHOT_LEFT
setvar 0x8004 0x1
setvar 0x8005 0x22
setvar 0x8006 0x19
special 0x24
waitmovement 0x0
hidesprite 0x800f
setflag PKMNMENU
addvar STORY_PROGRESS 0x1
setworldmapflag WM_INFERIOR
releaseall
end


.ifdef LANG_GER
.global str_0x963705

str_0x963705:
	.autostring 35 2 "Hallo PLAYER.\pWillkommen in Inferior.\pDu wirst leider keine Zeit haben, meine schöne Stadt zu bewundern.\pDie Rüpel von hier zu vertreiben, wird nichts nützen, solange der Kommandant von Team Violet noch sein Unwesen treibt.\pWir sollten uns auf zum Vulcano machen."

        
.elseif LANG_EN

.endif

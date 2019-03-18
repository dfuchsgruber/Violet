.include "callstds.s"
.include "overworld_script.s"
.include "vars.s"
.include "ordinals.s"
.include "mugshot.s"

.global ow_script_route_2_felix
ow_script_route_2_felix:
lockall
setvar 0x8004 0x3
special 0x1B
waitmovement 0
setvar LASTTALKED 0x3
faceplayer
loadpointer 0 str_hello
show_mugshot MUGSHOT_FELIX MUGSHOT_RIGHT
call ow_script_healing_sequence
loadpointer 0 str_after_healing
show_mugshot MUGSHOT_FELIX MUGSHOT_RIGHT
setvar 0x8004 0x36
setvar 0x8005 0x7
setvar 0x8006 0x19
special 0x24
waitmovement 0
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

.include "vars.s"
.include "movements.s"
.include "callstds.s"
.include "mugshot.s"
.include "flags.s"
.include "overworld_script.s"

.global ow_script_map_3_2_trigger_0



ow_script_movs_0x8bfd27:
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STOP


ow_script_map_3_2_trigger_0:
lockall
clearflag PKMNMENU
showsprite 0x6
setvar LASTTALKED 0x6
setvar 0x8004 0x6
special 0x1b
waitmovement 0x0
faceplayer
loadpointer 0x0 str_0x8c0738
show_mugshot MUGSHOT_LESTER MUGSHOT_LEFT
applymovement 0x6 ow_script_movs_0x8bfd27
waitmovement 0x0
hidesprite 0x6
releaseall
setvar STORY_PROGRESS 0x12
end



.ifdef LANG_GER

str_0x8c0738:
	.autostring 35 2 "Oh, wieder ein neues Gesicht in dieser Stadt.\pDas geschieht in letzter Zeit ungewöhnlich häufig.\pDOTS DOTS DOTS\nEntschuldige, ich habe mich noch gar nicht vorgestellt.\pMein Name ist Lester und ich bin der Arenaleiter dieser DOTS DOTS DOTS\pdieser Überreste einer einst wundervollen Stadt.\pNun ist diese Insel ein trostloser Ort, aber es ist mein Vermächtnis, über Aktania zu wachen.\pIch vermute, dass ein Trainer wie du mich herausfordern möchte.\pSollte dies der Fall sein, komm in den Tempel im Osten der Stadt.\pDort können wir einen Kampf austragen, solltest du darauf aus sein.\pUnd vielleicht kannst du diesem Ort ja doch etwas abgewinnen und deinen Aufenthalt zumindest ein wenig genießen."


.elseif LANG_EN

.endif
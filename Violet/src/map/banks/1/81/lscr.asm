
.global lscr_0x71d854

lscr_0x71d854:
	.byte 0x2
.word lscr_0x71d836
	.byte 0x0


.align 4
.global lscr_0x71d836

lscr_0x71d836:
	.hword 0x32, 0x4051
	.word ow_script_0x858dec
	.hword 0x0
.include "callstds.s"
.include "overworld_script.s"
.include "vars.s"
.include "mugshot.s"

.global ow_script_0x858dec

ow_script_0x858dec:
lockall
loadpointer 0x0 str_0x864813
show_mugshot MUGSHOT_IGVA MUGSHOT_LEFT
setvar 0x8004 0xd
setvar LASTTALKED 0xd
setvar 0x8005 0x1c
setvar 0x8006 0x1b
special 0x24
waitmovement 0x0
hidesprite 0x800f
addvar STORY_PROGRESS 0x1
releaseall
end


.ifdef LANG_GER

str_0x864813:
	.autostring 35 2 "PLAYER, wir sollten uns beeilen.\pWeißt du, der Kommandant, mit dem wir es sicherlich noch zu tun bekommen DOTS\pEr war auch einmal Teil der Revolutionsbewegung DOTS\pDOTS und ein enger Freund von mir.\pDoch er hat uns im Stich gelassen DOTS\pDieser Kerl DOTS\nDOTS ist äußerst gefährlich.\pUm seine Ziele zu erreichen, schreckt er vor nichts zurück.\pWir müssen vorsichtig sein."

.elseif LANG_EN

.endif
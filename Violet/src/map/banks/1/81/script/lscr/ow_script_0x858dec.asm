.include "callstds.s"
.include "vars.s"
.include "overworld_script.s"


.global ow_script_0x858dec
ow_script_0x858dec:
lockall
call ow_script_0x92f097
loadpointer 0x0 str_0x864813
callstd MSG
special 0x7
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
.global str_0x864813

str_0x864813:
	.autostring 35 2 "PLAYER, wir sollten uns beeilen.\pWeißt du, der Kommandant, mit dem wir es sicherlich noch zu tun bekommen DOTS\pEr war auch einmal Teil der Revolutionsbewegung DOTS\pDOTS und ein enger Freund von mir.\pDoch er hat uns im Stich gelassen DOTS\pDieser Kerl DOTS\nDOTS ist äußerst gefährlich.\pUm seine Ziele zu erreichen, schreckt er vor nichts zurück.\pWir müssen vorsichtig sein."

.elseif LANG_EN

.endif

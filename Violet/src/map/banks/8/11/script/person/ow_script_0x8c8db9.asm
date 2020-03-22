.include "callstds.s"
.include "movements.s"
.include "overworld_script.s"
.include "mugshot.s"


.global ow_script_movs_0x8c8e03
ow_script_movs_0x8c8e03:
.byte SAY_EXCLAM
.byte STOP


.global ow_script_0x8c8db9
ow_script_0x8c8db9:
loadpointer 0x0 str_0x931867
show_mugshot MUGSHOT_PRIMUS MUGSHOT_LEFT
sound 0x15
applymovement 0x800f ow_script_movs_0x8c8e03
waitmovement 0x0
faceplayer
loadpointer 0x0 str_0x931636
show_mugshot MUGSHOT_PRIMUS MUGSHOT_LEFT
lockall
setvar 0x8004 0xe
setvar 0x8005 0x1c
setvar 0x8006 0x2a
special 0x24
waitmovement 0x0
hidesprite 0x800f
releaseall
end


.ifdef LANG_GER
.global str_0x931867

str_0x931867:
	.autostring 35 2 "Äh ja, verstehen Sie DOTS\pFür das Portal benötige ich sehr starke Magnetfelder DOTS"
        
        
.global str_0x931636

str_0x931636:
	.autostring 35 2 "PLAYER!\nWas treibst du denn an einem solchen Ort?\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pWarum ich hier bin?\nNun, das ist eine ausgezeichnete FrageDOTS\pSieh mal, es ist so, dass viele Dinge, die ich für meine Forschung benötige, nur hier zu finden sindDOTS\pAber bitte, das bleibt unter uns PLAYER, ja?\pIch habe einen Ruf zu verlieren.\pUnd was meine arme Elise von mir halten würde, wenn sie erfahren würde, dass ihr Vater sich Forschungsmittel an einem Ort wie diesem besorgt.\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pDu solltest dich hier nicht zu lange aufhalten, PLAYERDOTS"
        
.elseif LANG_EN

.endif

.include "callstds.s"
.include "movements.s"
.include "overworld_script.s"


.global ow_script_movs_0x8c8e03
ow_script_movs_0x8c8e03:
.byte SAY_EXCLAM
.byte STOP


.global ow_script_0x8c8db9
ow_script_0x8c8db9:
call ow_script_0x8f4d04
loadpointer 0x0 str_0x931867
callstd MSG
special 0x7
sound 0x15
applymovement 0x800f ow_script_movs_0x8c8e03
waitmovement 0x0
faceplayer
call ow_script_0x8f4d04
loadpointer 0x0 str_0x931636
callstd MSG
special 0x7
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
	.autostring 35 2 "PLAYER!\nWas treibst du denn an einem solchen Ort?\pHier treibt sich doch nur Gesindel und Abschaum herum.\pDOTS DOTS DOTS\nWas ich hier tue?\pÄhm DOTS DOTS DOTS\nDOTS DOTS DOTS\pEs ist nicht so, dass Supermagneten auf dem legalen Markt zu kostspielig wären DOTS DOTS\pDOTS so ist es gewiss nicht!\pIch DOTS DOTS DOTS\nbin nur zufällig hier DOTS\pDa fällt mir ein, dass ich einen wichtigen Termin habe.\pMeine Forschungen dudlen keinen Auschub.\pGrüß meine Tochter Elise von mir, PLAYER!"
        
.elseif LANG_EN

.endif

.include "overworld_script.s"

.include "std.s"

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
    .string "Äh ja, verstehen\nSie, ich will Transformationen\lerzielen, ich benötige hohe\lEnergien. Können Sie nicht..."
        
        
.global str_0x931636

str_0x931636:
    .string "Oh, hallo PLAYER!\pIch hatte dich ... äh ... an einem\nOrt wie diesem nicht erwartet.\pWas treibst du hier auch?\nNur Ganoven und anderes Gesindel\lkommt hier zusammen, nicht aber\lLeute von deinem Schlag!\p...\n...\pWas ich hier tue?\pNun ... äh ... ja ...\nIch erwerbe hier gewisse ... äh\p... Gerätschaften ...\pNicht, weil sie auf dem legalen\nMarkt zu teuer wären ...\pIch ... äh ...\nIch habe ganz vergessen, dass ich\leinen wichtigen Termin habe.\pMeine Forschungen dulden keinen\nAufschub.\p...\pAuf Wiedersehen, PLAYER!\nUnd grüße doch bitte Elise, mein\lkleines Mädchen, von mir."
        
        
.elseif LANG_EN

.endif

.include "overworld_script.s"

.include "std.s"

.global ow_script_movs_0x95db3c
ow_script_movs_0x95db3c:
.byte FACE_DOWN
.byte STOP


.global ow_script_0x95dad0
ow_script_0x95dad0:
lockall
sound 0x9
clearflag PKMNMENU
showsprite 0x1
pause 0x20
setvar 0x8004 0x1
special 0x1b
waitmovement 0x0
faceplayer
call ow_script_0x89e33c
loadpointer 0x0 str_0x95dbb7
callstd MSG_KEEPOPEN
loadpointer 0x0 str_0x95dd1d
callstd MSG_KEEPOPEN
loadpointer 0x0 str_0x95db3f
callstd MSG
special 0x7
setvar 0x8004 0x1
setvar 0x8005 0x13
setvar 0x8006 0x10
special 0x24
waitmovement 0x0
applymovement 0x1 ow_script_movs_0x95db3c
waitmovement 0x0
pause 0x10
hidesprite 0x1
sound 0x9
pause 0x10
addvar STORY_PROGRESS 0x1
releaseall
end


.ifdef LANG_GER
.global str_0x95dbb7

str_0x95dbb7:
    .string "Hallo PLAYER.\nIch bin gerade deinem kleinen\lFreund RIVAL über den Weg\lgelaufen.\pEr scheint sich gemacht zu haben,\nganz ähnlich wie du.\pBist du deinem Ziel näher\ngekommen?\lOder fühlst du dich deinem Traum\lferner als zuvor?\pIch habe eine Niederlage erlitten,\neine vernichtende, wie man meinen\lkönnte.\pMein Vater ist ein Gegner, den ich\nunterschätzt habe..."
        
        
.global str_0x95dd1d

str_0x95dd1d:
    .string "Und dennoch oder gerade deswegen\nwerde ich nicht aufgeben.\pMein Vater hat es verdient,\nvernichtet zu werden. Von mir.\pIch war zu nachlässig, zu weich.\nSei gnadenlos, rücksichtslos.\pIch halte nicht viel von\nFreundschaften, dieser nervige\lFelix Bengel sollte das begriffen\lhaben.\pIch frage mich, ob wir kämpfen\nsollten, ob ich mich dir stellen\lwill und komme zu dem Schluss,\ldass ich auch dich unterschätzt\lhaben könnte.\pWenn ich meinen Vater gestürzt\nhabe, PLAYER - und das ist ein\lVersprechen - werde ich dich\lzerstampfen und nach dir den Rest\lder Welt."
        
        
.global str_0x95db3f

str_0x95db3f:
    .string "Jede Niederlage bringt mich dem\nendgültigen Sieg näher.\pUnd vor diesem Tag solltest du,\nsollte sich jeder fürchten..."
        
        
.elseif LANG_EN

.endif

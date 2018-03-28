.include "callstds.s"
.include "movements.s"
.include "overworld_script.s"


.global ow_script_movs_0x87c241
ow_script_movs_0x87c241:
.byte SAY_EXCLAM
.byte STOP


.global ow_script_0x87aea5
ow_script_0x87aea5:
pause 0x10
loadpointer 0x0 str_0x87c237
callstd MSG
faceplayer
sound 0x15
applymovement 0x800f ow_script_movs_0x87c241
waitmovement 0x0
trainerbattlecont 0x1 0x28 0x0 str_0x87c116 str_0x87c1a4 ow_script_0x87aed2


.global ow_script_0x87aed2
ow_script_0x87aed2:
loadpointer 0x0 str_0x87c1da
callstd MSG
fadescreen 0x1
hidesprite 0x800f
fadescreen 0x0
end


.ifdef LANG_GER
.global str_0x87c237

str_0x87c237:
    .string "... ..."
        
        
.global str_0x87c116

str_0x87c116:
    .string "Du schon wieder! Du hast mich zwar\nauf Route 2 besiegt, aber mit\lmeinen neuen Bibor werde ich dich\lbesiegen, ob sie nun wollen oder\lnicht!"
        
        
.global str_0x87c1a4

str_0x87c1a4:
    .string "Zwei Niederlagen an einem Tag!"
        
        
.global str_0x87c1da

str_0x87c1da:
    .string "Gut! Nimm die dummen Bibor, sie\nsind sowieso nicht zum kämpfen\lgeeignet! Ich verzieh mich."
        
        
.elseif LANG_EN

.endif

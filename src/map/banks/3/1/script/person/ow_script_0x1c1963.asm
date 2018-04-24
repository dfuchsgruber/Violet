.include "flags.s"
.include "attacks.s"
.include "movements.s"
.include "callstds.s"
.include "vars.s"
.include "ordinals.s"
.include "overworld_script.s"


.global ow_script_0x1c1963
ow_script_0x1c1963:
special 0x187
compare LASTRESULT 0x2
gotoif EQUAL ow_script_0x1aa912
lockall
checkflag FRBADGE_2
gotoif LESS ow_script_0x1c19d7
checkattack ATTACK_ZERSCHNEIDER
compare LASTRESULT 0x6
gotoif EQUAL ow_script_0x1c19d7
setanimation 0x0 0x800d
bufferpartypokemon 0x0 0x800d
bufferattack 0x1 ATTACK_ZERSCHNEIDER
loadpointer 0x0 str_0x1c19e4
callstd MSG_YES_NO
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x1c19e1
loadpointer 0x0 str_0x1c1a37
callstd MSG_KEEPOPEN
closeonkeypress
doanimation 0x2
nop
waitstate
goto ow_script_0x1c19c6


.global ow_script_movs_0x1c19d5
ow_script_movs_0x1c19d5:
.byte 0x69
.byte STOP


.global ow_script_0x1c19c6
ow_script_0x1c19c6:
applymovement 0x800f ow_script_movs_0x1c19d5
waitmovement 0x0
hidesprite 0x800f
releaseall
end


.global ow_script_0x1c19e1
ow_script_0x1c19e1:
closeonkeypress
releaseall
end


.global ow_script_0x1c19d7
ow_script_0x1c19d7:
loadpointer 0x0 str_0x1c1a48
callstd MSG_SIGN
releaseall
end


.ifdef LANG_GER
.global str_0x1c19e4

str_0x1c19e4:
    .string "Du kannst den Zerschneider hier\neinsetzen!\pMöchtest du den Zerschneider\neinsetzen?"
        
        
.global str_0x1c1a48

str_0x1c1a48:
    .string "Der Zerschneider kann hier\neingesetzt werden."
        
        
.elseif LANG_EN

.endif

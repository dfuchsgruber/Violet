.include "overworld_script.s"

.include "std.s"

.global ow_script_0x1c1a76
ow_script_0x1c1a76:
special 0x187
compare LASTRESULT 0x2
gotoif EQUAL ow_script_0x1aa912
lockall
checkflag FRBADGE_6
gotoif LESS ow_script_0x1c1afb
checkattack ATTACK_ZERTRUEMMERER
compare LASTRESULT 0x6
gotoif EQUAL ow_script_0x1c1afb
setanimation 0x0 0x800d
bufferpartypokemon 0x0 0x800d
bufferattack 0x1 ATTACK_ZERTRUEMMERER
loadpointer 0x0 str_0x1c1b07
callstd MSG_YES_NO
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x1c1b04
loadpointer 0x0 str_0x1c1a37
callstd MSG_KEEPOPEN
closeonkeypress
doanimation 0x25
nop
waitstate
goto ow_script_0x1c1ad9


.global ow_script_movs_0x1c1af9
ow_script_movs_0x1c1af9:
.byte 0x68
.byte STOP


.global ow_script_0x1c1ad9
ow_script_0x1c1ad9:
applymovement 0x800f ow_script_movs_0x1c1af9
waitmovement 0x0
hidesprite 0x800f
special 0xab
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x1c1af7
waitstate
releaseall
end


.global ow_script_0x1c1af7
ow_script_0x1c1af7:
releaseall
end


.global ow_script_0x1c1b04
ow_script_0x1c1b04:
closeonkeypress
releaseall
end


.global ow_script_0x1c1afb
ow_script_0x1c1afb:
loadpointer 0x0 str_0x1c1b4a
callstd MSG_SIGN
end


.global ow_script_0x1aa912
ow_script_0x1aa912:
release
end

.global str_0x1c1b07

str_0x1c1b07:
    .string "Dieser Fels ist zerbrechlich. Soll\nZERTRÜMMERER eingesetzt werden?"
        
        
.global str_0x1c1a37

str_0x1c1a37:
    .string "BUFFER_1 setzt\nBUFFER_2 ein."
        
        
.global str_0x1c1b4a

str_0x1c1b4a:
    .string "Ein großer Felsen. Ein Pokémon\nkönnte ihn vielleicht zertrümmern."
        
        
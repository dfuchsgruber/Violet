.include "overworld_script.s"

.include "std.s"

.global ow_script_movs_0x86d5b0
ow_script_movs_0x86d5b0:
.byte LOOK_UP
.byte STOP


.global ow_script_0x86d40b
ow_script_0x86d40b:
lockall
faceplayer
checkflag FRBADGE_5
gotoif EQUAL ow_script_0x86d439
loadpointer 0x0 str_0x86d444
callstd MSG
applymovement 0x1 ow_script_movs_0x86d5b0
waitmovement 0x0
hidesprite 0x1
pause 0x10
releaseall
warp 0xa 0x7 0x0 0x0 0x0
end


.global ow_script_0x86d439
ow_script_0x86d439:
loadpointer 0x0 str_0x86d584
callstd MSG
releaseall
end

.global str_0x86d444

str_0x86d444:
    .string "PLAYER! Freut mich, dich zu\nsehen. Im Namen der Stadt INFERIOR\lund der ganzen Region möchte ich\ldir für deine Unterstützung am\lVULCANO danken. Ich bin\lzuversichtlich, dass du es schaffen\lwirst, den Orden zu erinngen. Wenn\ldu aber glaubst, ich würde nicht\lalles geben, dann irrst du dich,\lkomm mit mir!"
        
        
.global str_0x86d584

str_0x86d584:
    .string "Das war der heißeste Kampf meines\nLebens!"
        
        
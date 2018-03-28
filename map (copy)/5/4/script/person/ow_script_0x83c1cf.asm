.include "overworld_script.s"

.include "std.s"

.global ow_script_0x83c1cf
ow_script_0x83c1cf:
goto ow_script_0x1a9429


.global ow_script_0x1a9429
ow_script_0x1a9429:
special 0x187
compare LASTRESULT 0x2
gotoif EQUAL ow_script_0x1aa912
preparemsg str_0x1a8188
waitmsg
multichoice 0x13 0x8 0x0 0x2
copyvar 0x8000 LASTRESULT
compare 0x8000 0x0
gotoif EQUAL ow_script_0x877467
compare 0x8000 0x1
gotoif EQUAL ow_script_0x949710
compare 0x8000 0x7f
gotoif EQUAL ow_script_0x949710
end


.global ow_script_0x949710
ow_script_0x949710:
loadpointer 0x0 str_0x1a8219
callstd MSG
end


.global ow_script_0x877467
ow_script_0x877467:
savincrementkey 0xf
loadpointer 0x0 str_0x1a81da
callstd MSG_KEEPOPEN
closeonkeypress
call ow_script_0x1a947f
pause 0x5
special 0x169
pause 0x5
goto ow_script_0x1a949d


.global ow_script_0x1a949d
ow_script_0x1a949d:
special2 0x800d 0x1b1
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x1a94ce
special2 0x800d 0x183
copyvar 0x8008 LASTRESULT
compare 0x8008 0x0
gotoif EQUAL ow_script_0x1a94ce
compare 0x8008 0x1
gotoif EQUAL ow_script_0x1a94e7
end


.global ow_script_movs_0x1a951d
ow_script_movs_0x1a951d:
.byte 0x5b
.byte 0x1a
.byte STOP


.global ow_script_0x1a94e7
ow_script_0x1a94e7:
checkflag 0x842
gotoif EQUAL ow_script_0x949719
loadpointer 0x0 str_0x1a8237
callstd MSG_KEEPOPEN
setflag 0x842
preparemsg str_0x1c067a
waitmsg
applymovement 0x800f ow_script_movs_0x1a951d
waitmovement 0x0
loadpointer 0x0 str_0x1a8219
callstd MSG_KEEPOPEN
end


.global ow_script_0x949719
ow_script_0x949719:
preparemsg str_0x1a8237
waitmsg
applymovement 0x800f ow_script_movs_0x1a951d
waitmovement 0x0
loadpointer 0x0 str_0x1a8219
callstd MSG
end


.global ow_script_0x1a94ce
ow_script_0x1a94ce:
preparemsg str_0x1a8237
waitmsg
applymovement 0x800f ow_script_movs_0x1a951d
waitmovement 0x0
loadpointer 0x0 str_0x1a8219
callstd MSG
end


.global ow_script_movs_0x1aa419
ow_script_movs_0x1aa419:
.byte LOOK_LEFT_DELAYED
.byte STOP


.global ow_script_movs_0x1aa41f
ow_script_movs_0x1aa41f:
.byte LOOK_DOWN_DELAYED
.byte STOP


.global ow_script_0x1a947f
ow_script_0x1a947f:
applymovement 0x800f ow_script_movs_0x1aa419
waitmovement 0x0
doanimation 0x19
nop
checkanimation 0x19
applymovement 0x800f ow_script_movs_0x1aa41f
waitmovement 0x0
special 0x0
return

.global str_0x1a8188

str_0x1a8188:
    .string "Willkommen im Pokestop!\pWir heilen deine Pokémon und\nmachen sie wieder fit!"
        
        
.global str_0x1a8219

str_0x1a8219:
    .string "Komm jederzeit wieder vorbei!"
        
        
.global str_0x1a81da

str_0x1a81da:
    .string "Okay, ich nehme deine Pokémon für\neinen Moment in meine Obhut."
        
        
.global str_0x1a8237

str_0x1a8237:
    .string "Danke!\nDeine Pokémon sind wieder topfit!"
        
        
.global str_0x1c067a

str_0x1c067a:
    .string "Es scheint, als ob BUFFER_1 gerade\nspielt.\lLos!"
        
        
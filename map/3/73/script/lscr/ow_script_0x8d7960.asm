.include "overworld_script.s"

.include "std.s"

.global ow_script_movs_0x8d79c9
ow_script_movs_0x8d79c9:
.byte FACE_DOWN
.byte SAY_EXCLAM
.byte STOP

.global ow_script_movs_0x8d7ba7
ow_script_movs_0x8d7ba7:
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STOP


.global ow_script_movs_0x8d7e90
ow_script_movs_0x8d7e90:
.byte STEP_UP_SLOW
.byte STEP_UP_SLOW
.byte STEP_UP_SLOW
.byte STEP_UP_SLOW
.byte STEP_UP_SLOW
.byte STEP_UP_SLOW
.byte STEP_UP_SLOW
.byte STEP_UP_SLOW
.byte STEP_UP_SLOW
.byte STEP_UP_SLOW
.byte STEP_UP_SLOW
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STOP


.global ow_script_movs_0x8d7b4e
ow_script_movs_0x8d7b4e:
.byte STEP_UP_SLOW
.byte STEP_UP_SLOW
.byte STEP_UP_SLOW
.byte STEP_UP_SLOW
.byte STEP_UP_SLOW
.byte STEP_UP_SLOW
.byte STEP_UP_SLOW
.byte STEP_UP_SLOW
.byte STEP_UP_SLOW
.byte STEP_UP_SLOW
.byte STEP_UP_SLOW
.byte STOP



.global ow_script_0x8d7960
ow_script_0x8d7960:

call ow_script_0x8a1cc9
loadpointer 0x0 str_0x8d79cd
callstd MSG
special 0x7
lockall
call ow_script_0x8d7a10
sound 0x15
applymovement 0x1 ow_script_movs_0x8d79c9
applymovement 0x2 ow_script_movs_0x8d79c9
applymovement 0x3 ow_script_movs_0x8d79c9
applymovement 0x4 ow_script_movs_0x8d79c9
applymovement 0x5 ow_script_movs_0x8d79c9
waitmovement 0x0
lockall
checksound
pause 0x24
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x8d79fe
callstd MSG
special 0x7
fadescreen 0x1
setflag TRANS_DISABLE
clearflag TRANS_PALETTE_FETCH
goto ow_script_0x8d7bed


.global ow_script_0x8d7bed
ow_script_0x8d7bed:
setvar STORY_PROGRESS 0x14
setvar 0x8004 0x10
special 0x19
waitstate
clearflag TRANS_DISABLE
setvar STORY_PROGRESS 0x14
special 0xb
lockall
fadescreen 0x0
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x8d7bbb
callstd MSG
special 0x7
special 0x113
applymovement 0x7f ow_script_movs_0x8d7ba7
waitmovement 0x0
playsong MUS_DEOXYS_ERSCHEINT 0x0
cry POKEMON_DEOXYS 0x0
waitcry
call ow_script_0x8d7a10
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x8d7b5b
callstd MSG
special 0x7
cry POKEMON_DEOXYS 0x0
waitcry
cry POKEMON_DEOXYS 0x0
waitcry
applymovement 0x7f ow_script_movs_0x8d7e90
applymovement 0x9 ow_script_movs_0x8d7b4e
waitmovement 0x0
cry POKEMON_DEOXYS 0x0
waitcry
call ow_script_0x8d7a10
call ow_script_0x8d7b1f
call ow_script_0x8d7b1f
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x8d7ae9
callstd MSG
special 0x7
cry POKEMON_DEOXYS 0x0
waitcry
call ow_script_0x8d7a10
sound 0x50
fadescreen 0x2
checksound
sound 0x50
fadescreen 0x2
call ow_script_0x8d7a10
sound 0x50
fadescreen 0x3
hidesprite 0x1
hidesprite 0x2
hidesprite 0x3
hidesprite 0x4
hidesprite 0x5
setweather 0x5
doweather
fadescreen 0x2
goto ow_script_0x8d7d8a


.global ow_script_movs_0x8d7e5d
ow_script_movs_0x8d7e5d:
.byte STEP_UP_SLOW
.byte STEP_UP_SLOW
.byte STEP_UP_SLOW
.byte STEP_UP_SLOW
.byte STEP_UP_SLOW
.byte STOP


.global ow_script_movs_0x8d7e64
ow_script_movs_0x8d7e64:
.byte STEP_UP_SLOW
.byte STEP_UP_SLOW
.byte STEP_UP_SLOW
.byte STEP_UP_SLOW
.byte STEP_UP_SLOW
.byte STEP_UP_SLOW
.byte STEP_UP_SLOW
.byte STEP_UP_SLOW
.byte STEP_UP_SLOW
.byte STEP_UP_SLOW
.byte STEP_UP_SLOW
.byte STEP_UP_SLOW
.byte STEP_UP_SLOW
.byte STEP_UP_SLOW
.byte STEP_UP_SLOW
.byte STEP_UP_SLOW
.byte STEP_UP_SLOW
.byte STEP_UP_SLOW
.byte STOP


.global ow_script_0x8d7d8a
ow_script_0x8d7d8a:
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x8d7ed8
callstd MSG
special 0x7
cry POKEMON_DEOXYS 0x0
call ow_script_0x8d7a10
waitcry
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x8d7eab
callstd MSG
special 0x7
applymovement 0x9 ow_script_movs_0x8d7e5d
applymovement 0x7f ow_script_movs_0x8d7e5d
waitmovement 0x0
cry POKEMON_DEOXYS 0x0
applymovement 0x9 ow_script_movs_0x8d7e64
applymovement 0x7f ow_script_movs_0x8d7e64
waitmovement 0x0
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x8d7e03
callstd MSG
special 0x7
cry POKEMON_DEOXYS 0x0
call ow_script_0x8d7a10
goto ow_script_0x8d7f2e


.global ow_script_movs_0x8d8111
ow_script_movs_0x8d8111:
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STOP


.global ow_script_movs_0x8d80fd
ow_script_movs_0x8d80fd:
.byte STEP_DOWN
.byte STOP


.global ow_script_0x8d7f2e
ow_script_0x8d7f2e:
hidesprite 0x6
hidesprite 0x7
hidesprite 0x8
hidesprite 0xa
applymovement 0x7f ow_script_movs_0x8d8111
waitmovement 0x0
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x8d8100
callstd MSG
special 0x7
showsprite 0xa
applymovement 0xa ow_script_movs_0x8d80fd
waitmovement 0x0
fadesong MUS_0
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x8d80ca
callstd MSG
special 0x7
call ow_script_0x8c09e6
loadpointer 0x0 str_0x8d803f
callstd MSG
special 0x7
playsong MUS_SPIELHALLE_VERSION_3 0x0
call ow_script_0x8c09e6
loadpointer 0x0 str_0x8d7fa0
callstd MSG
special 0x7
goto ow_script_0x8d9328


.global ow_script_0x8d9328
ow_script_0x8d9328:
goto ow_script_0x8e09b9


.global ow_script_0x8e09b9
ow_script_0x8e09b9:
special 0x114
setvar 0x8004 0x11
special 0x19
waitstate
showsprite 0x13
goto ow_script_0x8dbff9


.global ow_script_movs_0x8dc3fb
ow_script_movs_0x8dc3fb:
.byte STEP_LEFT_FAST
.byte STEP_LEFT_FAST
.byte STEP_LEFT_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STOP


.global ow_script_0x8dbff9
ow_script_0x8dbff9:
clearflag PKMNMENU
setweather 0x5
doweather
call ow_script_0x8d7a10
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x8dc40d
callstd MSG
special 0x7
special 0x114
special 0x113
applymovement 0x7f ow_script_movs_0x8dc3fb
waitmovement 0x0
sound 0x50
fadescreen 0x2
call ow_script_0x8c09e6
loadpointer 0x0 str_0x8dc39d
callstd MSG
special 0x7
sound 0x50
fadescreen 0x2
call ow_script_0x8d7a10
sound 0x50
fadescreen 0x2
cry POKEMON_REGIROCK 0x0
waitcry
sound 0x50
fadescreen 0x2
sound 0x50
fadescreen 0x3
showsprite 0x6
fadescreen 0x2
call ow_script_0x8d7a10
sound 0x50
fadescreen 0x2
call ow_script_0x8c09e6
loadpointer 0x0 str_0x8dc346
callstd MSG
special 0x7
sound 0x50
fadescreen 0x2
call ow_script_0x8d7a10
sound 0x50
fadescreen 0x2
cry POKEMON_REGICE 0x0
waitcry
sound 0x50
fadescreen 0x2
sound 0x50
fadescreen 0x3
showsprite 0xf
fadescreen 0x2
call ow_script_0x8d7a10
sound 0x50
fadescreen 0x2
call ow_script_0x8c09e6
loadpointer 0x0 str_0x8dc2ea
callstd MSG
special 0x7
sound 0x50
fadescreen 0x2
call ow_script_0x8d7a10
sound 0x50
fadescreen 0x2
cry POKEMON_REGISTEEL 0x0
waitcry
sound 0x50
fadescreen 0x2
sound 0x50
fadescreen 0x3
showsprite 0x8
fadescreen 0x2
call ow_script_0x8d7a10
goto ow_script_0x8e1584


.global ow_script_movs_0x8e1959
ow_script_movs_0x8e1959:
.byte 0xa4
.byte STOP


.global ow_script_0x8e1584
ow_script_0x8e1584:
call ow_script_0x8c09e6
loadpointer 0x0 str_0x8e195c
callstd MSG
special 0x7
cry POKEMON_DEOXYS 0x0
waitcry
sound 0x80
applymovement 0x13 ow_script_movs_0x8e1959
waitmovement 0x0
call ow_script_0x8d7a10
sound 0x80
applymovement 0x6 ow_script_movs_0x8e1959
applymovement 0x8 ow_script_movs_0x8e1959
applymovement 0xf ow_script_movs_0x8e1959
waitmovement 0x0
goto ow_script_0x8e1a27


.global ow_script_0x8e1a27
ow_script_0x8e1a27:
hidesprite 0x6
hidesprite 0x8
hidesprite 0xf
hidesprite 0x13


setflag TRANS_DISABLE
clearflag TRANS_PALETTE_FETCH
setvar STORY_PROGRESS 0x14
setvar 0x8004 0x12
special 0x19
waitstate
clearflag TRANS_DISABLE

goto ow_script_0x8e1aa9


.global ow_script_0x8e1aa9
ow_script_0x8e1aa9:
pause 0x1
cry POKEMON_DEOXYS 0x0
call ow_script_0x8d7a10
waitcry
cry POKEMON_REGISTEEL 0x0
call ow_script_0x8d7a10
waitcry
call ow_script_0x8d7a10
call ow_script_0x8d7a10
cry POKEMON_DEOXYS 0x0
waitcry
fadescreen 0x1
//callasm 0x919d791
writebytetooffset 0x0 0x2036e28
goto ow_script_0x92df2f


.global ow_script_0x92df2f
ow_script_0x92df2f:
setflag AKTANIA_FLASHBACK_DONE
warpmuted 0xf 0x0 0xff 0x2e 0x2c
end


.global ow_script_0x8d7a10
ow_script_0x8d7a10:
setvar 0x8004 0x4
setvar 0x8005 0x5
setvar 0x8006 0x14
setvar 0x8007 0x4
special 0x136
waitstate
lockall
return


.global ow_script_movs_0x8d7b4b
ow_script_movs_0x8d7b4b:
.byte JUMP_IN_PLACE_FACE_DOWN
.byte STOP


.global ow_script_0x8d7b1f
ow_script_0x8d7b1f:
sound 0xa
applymovement 0x1 ow_script_movs_0x8d7b4b
applymovement 0x2 ow_script_movs_0x8d7b4b
applymovement 0x3 ow_script_movs_0x8d7b4b
applymovement 0x4 ow_script_movs_0x8d7b4b
applymovement 0x5 ow_script_movs_0x8d7b4b
waitmovement 0x0
checksound
return

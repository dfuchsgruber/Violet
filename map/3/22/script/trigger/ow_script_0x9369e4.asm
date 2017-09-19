.include "overworld_script.s"

.include "std.s"

.global ow_script_0x9369e4
ow_script_0x9369e4:
lockall
clearflag PKMNMENU
showsprite 0xb
setvar 0x8004 0xb
special 0x1b
waitmovement 0x0
faceplayer
fadesong MUS_0
call ow_script_0x936c1c
loadpointer 0x0 str_0x936bf6
callstd MSG
special 0x7
setflag TRANS_DISABLE
clearflag TRANS_PALETTE_FETCH
setvar 0x8004 0x3
special 0x19
waitstate
clearflag TRANS_DISABLE
call ow_script_0x936c1c
loadpointer 0x0 str_0x936ba2
callstd MSG_KEEPOPEN
playsong MUS_MISTRAL 0x0
loadpointer 0x0 str_0x936c2f
callstd MSG
special 0x7
goto ow_script_0x937652


.global ow_script_0x937652
ow_script_0x937652:
setflag TRANS_DISABLE
clearflag TRANS_PALETTE_FETCH
setvar SONG_OVERRIDE 0x16b
setvar 0x8004 0x0
special 0x19
waitstate
clearflag TRANS_DISABLE
setvar SONG_OVERRIDE 0x0
goto ow_script_0x936d7a


.global ow_script_0x936d7a
ow_script_0x936d7a:
call ow_script_0x936c1c
loadpointer 0x0 str_0x937369
callstd MSG
special 0x7
setvar 0x8004 0xb
setvar 0x8005 0xf
setvar 0x8006 0x16
special 0x24
waitmovement 0x0
hidesprite 0xb
goto ow_script_0x937675


.global ow_script_0x937675
ow_script_0x937675:
fadesong MUS_ROUTE_1_AND_TUNNELPFAD
addvar STORY_PROGRESS 0x1
releaseall
end


.global ow_script_0x936c1c
ow_script_0x936c1c:
setvar 0x8000 0x0
setvar 0x8001 0x2
setvar 0x8002 0xe
special 0x6
return

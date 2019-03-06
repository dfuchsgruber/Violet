.include "flags.s"
.include "songs.s"
.include "callstds.s"
.include "vars.s"


.global ow_script_0x9730ba

ow_script_0x9730ba:
call ow_script_0x936c1c
loadpointer 0x0 str_0x971e16
callstd MSG
special 0x7
pause 0x1
call ow_script_0x97231c
loadpointer 0x0 str_0x971d73
callstd MSG
special 0x7
pause 0x1
setvar SONG_OVERRIDE 0x0
playsong MUS_PUNKTLOCH_AND_TANIBOSCHLUSSEL_AND_ICOGNITO_KAMMERN 0x0
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x971d60
callstd MSG
special 0x7
pause 0x1
applymovement 0x1 ow_moves_0x971d5d
waitmovement 0x0
call ow_script_0x97231c
loadpointer 0x0 str_0x971c82
callstd MSG
special 0x7
pause 0x1
call ow_script_0x936c1c
loadpointer 0x0 str_0x971c05
callstd MSG
special 0x7
call ow_script_0x97231c
loadpointer 0x0 str_0x953d08
callstd MSG
special 0x7
pause 0x1
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x9718d8
callstd MSG
special 0x7
pause 0x1
call ow_script_0x97231c
loadpointer 0x0 str_0x9717c3
callstd MSG
special 0x7
pause 0x1
playsong MUS_SPIELHALLE_VERSION_3 0x0
fadescreen 0x1
call ow_script_0x97231c
loadpointer 0x0 str_0x971424
callstd MSG_KEEPOPEN
loadpointer 0x0 str_0x96fd7a
callstd MSG
special 0x7
pause 0x1
fadesong MUS_PUNKTLOCH_AND_TANIBOSCHLUSSEL_AND_ICOGNITO_KAMMERN
fadescreen 0x0
call ow_script_0x936c1c
loadpointer 0x0 str_0x96fa81
callstd MSG
special 0x7
pause 0x1
call ow_script_0x97231c
loadpointer 0x0 str_0x96f811
callstd MSG
special 0x7
pause 0x1
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x96f680
callstd MSG
special 0x7
pause 0x1
call ow_script_0x97231c
loadpointer 0x0 str_0x96f55c
callstd MSG
special 0x7
pause 0x1
call ow_script_0x936c1c
loadpointer 0x0 str_0x96f427
callstd MSG
special 0x7
applymovement 0xff ow_moves_0x96eff0
waitmovement 0x0
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x96ef94
callstd MSG
special 0x7
pause 0x1
applymovement 0xff ow_moves_0x96ef91
waitmovement 0x0
call ow_script_0x97231c
loadpointer 0x0 str_0x96edc1
callstd MSG_KEEPOPEN
loadpointer 0x0 str_0x96ef26
callstd MSG_KEEPOPEN
loadpointer 0x0 str_0x96ef5f
callstd MSG
special 0x7
pause 0x1
addvar STORY_PROGRESS 0x1
setflag PKMNMENU
setflag PKMNMENU
goto ow_script_0x953cf2

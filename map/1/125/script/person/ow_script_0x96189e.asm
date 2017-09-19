.include "overworld_script.s"

.include "std.s"

.global ow_script_0x96189e
ow_script_0x96189e:
lock
faceplayer
loadpointer 0x0 str_0x962c48
callstd MSG_KEEPOPEN
checkflag ASHBAG_RECEIVED
gotoif LESS ow_script_0x961ce9
buffernumber 0x0 0x50d0
loadpointer 0x0 str_0x961ca8
callstd MSG_KEEPOPEN
setvar DYN_MULTICHOICE_ITEM_CNT 0x6
loadpointer 0x0 str_0x961bfb
multichoice 0x0 0x0 0x0 0x0
setvar DYN_MULTICHOICE_ITEM_CNT 0x0
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x961913
compare LASTRESULT 0x1
gotoif EQUAL ow_script_0x96194d
compare LASTRESULT 0x2
gotoif EQUAL ow_script_0x961987
compare LASTRESULT 0x3
gotoif EQUAL ow_script_0x9619c1
compare LASTRESULT 0x4
gotoif EQUAL ow_script_0x9619fb
loadpointer 0x0 str_0x961baf
callstd MSG_FACE
end


.global ow_script_0x9619fb
ow_script_0x9619fb:
compare ASH 0x3e8
gotoif LESS ow_script_0x961b55
checkitemroom ITEM_SCHW_FLOETE 0x1
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x961af3
loadpointer 0x0 str_0x961ab8
callstd MSG_KEEPOPEN
copyvarifnotzero 0x8000 ITEM_SCHW_FLOETE
copyvarifnotzero 0x8001 ITEM_MEISTERBALL
callstd ITEM_OBTAIN
subvar ASH 0x3e8
goto ow_script_0x961a35


.global ow_script_0x961a35
ow_script_0x961a35:
loadpointer 0x0 str_0x961a3f
callstd MSG_FACE
end


.global ow_script_0x961af3
ow_script_0x961af3:
loadpointer 0x0 str_0x961afd
callstd MSG_FACE
end


.global ow_script_0x961b55
ow_script_0x961b55:
loadpointer 0x0 str_0x961b67
callstd MSG_KEEPOPEN
loadpointer 0x0 str_0x961baf
callstd MSG_FACE
end


.global ow_script_0x9619c1
ow_script_0x9619c1:
compare ASH 0x3e8
gotoif LESS ow_script_0x961b55
checkitemroom ITEM_WEISSE_FLOETE 0x1
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x961af3
loadpointer 0x0 str_0x961ab8
callstd MSG_KEEPOPEN
copyvarifnotzero 0x8000 ITEM_WEISSE_FLOETE
copyvarifnotzero 0x8001 ITEM_MEISTERBALL
callstd ITEM_OBTAIN
subvar ASH 0x3e8
goto ow_script_0x961a35


.global ow_script_0x961987
ow_script_0x961987:
compare ASH 0x1f4
gotoif LESS ow_script_0x961b55
checkitemroom ITEM_GELBE_FLOETE 0x1
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x961af3
loadpointer 0x0 str_0x961ab8
callstd MSG_KEEPOPEN
copyvarifnotzero 0x8000 ITEM_GELBE_FLOETE
copyvarifnotzero 0x8001 ITEM_MEISTERBALL
callstd ITEM_OBTAIN
subvar ASH 0x1f4
goto ow_script_0x961a35


.global ow_script_0x96194d
ow_script_0x96194d:
compare ASH 0x1f4
gotoif LESS ow_script_0x961b55
checkitemroom ITEM_ROTE_FLOETE 0x1
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x961af3
loadpointer 0x0 str_0x961ab8
callstd MSG_KEEPOPEN
copyvarifnotzero 0x8000 ITEM_ROTE_FLOETE
copyvarifnotzero 0x8001 ITEM_MEISTERBALL
callstd ITEM_OBTAIN
subvar ASH 0x1f4
goto ow_script_0x961a35


.global ow_script_0x961913
ow_script_0x961913:
compare ASH 0xfa
gotoif LESS ow_script_0x961b55
checkitemroom ITEM_BLAUE_FLOETE 0x1
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x961af3
loadpointer 0x0 str_0x961ab8
callstd MSG_KEEPOPEN
copyvarifnotzero 0x8000 ITEM_BLAUE_FLOETE
copyvarifnotzero 0x8001 ITEM_MEISTERBALL
callstd ITEM_OBTAIN
subvar ASH 0xfa
goto ow_script_0x961a35


.global ow_script_0x961ce9
ow_script_0x961ce9:
loadpointer 0x0 str_0x961d40
callstd MSG_FACE
end

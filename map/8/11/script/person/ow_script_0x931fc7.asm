.include "overworld_script.s"

.include "std.s"

.global ow_script_0x931fc7
ow_script_0x931fc7:
loadpointer 0x0 str_0x93674c
callstd MSG_YES_NO
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x935b66
loadpointer 0x0 str_0x935fb2
callstd MSG_YES_NO
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x935b66
checkmoney 0x1388 0x0
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x935ad0
loadpointer 0x0 str_0x935a97
callstd MSG
setvar 0x8004 0x14
goto ow_script_0x933987


.global ow_script_0x933987
ow_script_0x933987:
buffernumber 0x0 0x8004
loadpointer 0x0 str_0x935a60
callstd MSG_KEEPOPEN
setvar DYN_MULTICHOICE_ITEM_CNT 0x3
loadpointer 0x0 choice
multichoice 0x0 0x0 0x0 0x1
compare LASTRESULT 0x0
callif EQUAL ow_script_0x933ebf
compare LASTRESULT 0x1
callif EQUAL ow_script_0x933ec6
compare LASTRESULT 0x2
callif EQUAL ow_script_0x933ecd
special 0x25
setvar DYN_MULTICHOICE_ITEM_CNT 0x0
buffernumber 0x0 0x8005
loadpointer 0x0 str_0x933e82
callstd MSG
compare 0x8004 0x0
gotoif EQUAL ow_script_0x933e18
goto ow_script_0x933987

.align 4
choice:
    .word str_blackmarket_1, 0
    .word str_blackmarket_2, 0
    .word str_blackmarket_3, 0

.global ow_script_0x933e18
ow_script_0x933e18:
loadpointer 0x0 str_0x933e28
callstd MSG
paymoney 0x1388 0x0
end


.global ow_script_0x933ecd
ow_script_0x933ecd:
subvar 0x8004 0x3
return


.global ow_script_0x933ec6
ow_script_0x933ec6:
subvar 0x8004 0x2
return


.global ow_script_0x933ebf
ow_script_0x933ebf:
subvar 0x8004 0x1
return


.global ow_script_0x935ad0
ow_script_0x935ad0:
loadpointer 0x0 str_0x935ada
callstd MSG
end


.global ow_script_0x935b66
ow_script_0x935b66:
loadpointer 0x0 str_0x9366ff
callstd MSG
end


.ifdef LANG_GER
.global str_0x93674c

str_0x93674c:
    .string "Oh hallo!\pHast du Lust auf kleines lustiges\nSpielchen mit einem alten Herren?"
        
        
.global str_0x935fb2

str_0x935fb2:
    .string "Lass mich das Spielchen erklären.\pIch habe hier 20 Murmeln, wir\nbeide nehmen abwechselnd entweder\leine, zwei oder drei Murmeln.\pDer Spieler, der die letzte Murmel\nan sich nimmt, gewinnt das Spiel.\pSimpel, nicht?\pWenn du gewinnst, zahle ich dir\n50 000POKEDOLLAR, anderenfalls schuldest\ldu mir 5 000POKEDOLLAR.\pWas sagst du?"
        
        
.global str_0x935a97

str_0x935a97:
    .string "Gut, ich bin so freundlich und\nlasse dir den Vortritt."
        
        
.global str_0x935a60

str_0x935a60:
    .string "BUFFER_1 Murmeln verbleiben.\nWie viele möchtest du nehmen?"
        
        
.global str_blackmarket_1

str_blackmarket_1:
    .string "Eine"
        
        
.global str_blackmarket_2

str_blackmarket_2:
    .string "Zwei"
        
        
.global str_blackmarket_3

str_blackmarket_3:
    .string "Drei"
        
        
.global str_0x933e82

str_0x933e82:
    .string "Na dann werde ich ... äh ...\nBUFFER_1 Murmeln nehmen, denke ich."
        
        
.global str_0x933e28

str_0x933e28:
    .string "Oh, was ein Pech!\pSieht so aus, als hättest du\nverloren!\pDas tut mir aufrichtig leid..."
        
        
.global str_0x935ada

str_0x935ada:
    .string "Du hast ja nicht einmal genügend\nGeld, deine Schulden zu zahlen!"
        
        
.global str_0x9366ff

str_0x9366ff:
    .string "Oh, das ist aber schade!\nDu hast wohl Angst, gegen mich zu\lverlieren, was?"
        
        
.elseif LANG_EN

.endif

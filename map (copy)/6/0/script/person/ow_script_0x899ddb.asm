.include "overworld_script.s"

.include "std.s"

.global ow_script_0x899ddb
ow_script_0x899ddb:
lock
faceplayer
checkflag AKTANIA_GENGARNITE
gotoif EQUAL ow_script_0x899e4b
loadpointer 0x0 str_0x89a9bb
callstd MSG_YES_NO
compare LASTRESULT 0x1
gotoif LESS ow_script_0x89a97b
special 0x9f
waitstate
lock
faceplayer
copyvar 0x800a 0x8004
special2 0x800d 0x84
compare 0x8004 0x6
gotoif HIGHER_OR_EQUAL ow_script_0x89a97b
special2 0x8005 0xba
setvar 0x8004 0x5e
comparevars 0x8005 0x8004
gotoif EQUAL ow_script_0x87f879
goto ow_script_0x89a97b


.global ow_script_0x89a97b
ow_script_0x89a97b:
loadpointer 0x0 str_0x89a986
callstd MSG
release
end


.global ow_script_0x87f879
ow_script_0x87f879:
loadpointer 0x0 str_0x89a91d
callstd MSG
bufferitem 0x0 ITEM_GENGARNIT
copyvarifnotzero 0x8000 ITEM_GENGARNIT
copyvarifnotzero 0x8001 1
callstd ITEM_OBTAIN
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x87f3c1
setflag AKTANIA_GENGARNITE
goto ow_script_0x899e4b


.global ow_script_0x899e4b
ow_script_0x899e4b:
loadpointer 0x0 str_0x89a88b
callstd MSG_FACE
end

.global str_0x89a9bb

str_0x89a9bb:
    .string "Gengar ist der König unter den\nGeistpokemon. Seine\lGeschwindigkeit und Stärke sind\lüberragend, findest du nicht auch?\lWenn du mir ein Gengar zeigen\lkannst, werde ich dir einen Weg\lverraten, es stärker zu machen!\pKannst du mir ein Gengar\nzeigen?"
        
        
.global str_0x89a986

str_0x89a986:
    .string "Komm wieder, wenn du mir ein\nGengar zeigen kannst!"
        
        
.global str_0x89a91d

str_0x89a91d:
    .string "Wahrhaftig! Das ist ein Gengar.\nNun möchte ich dir das geben, was\lich dir versprochen habe."
        
        
.global str_0x89a88b

str_0x89a88b:
    .string "Dieses Item nennt sich BUFFER_1.\nEs ist ein Stein in dessen\lGegenwart sich Gengar seltsam\lverhält. Ich weiß jedoch nicht\lgenau, wie man ihn benuzt..."
        
        
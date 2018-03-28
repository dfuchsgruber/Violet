.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8e2ce6
ow_script_0x8e2ce6:
checkflag FELSIGE_ODNIS_BEERENSAFT_QUEST_DONE
gotoif EQUAL ow_script_0x8e305a
checkflag FELSIGE_ODNIS_BEERENSAFT_QUEST_ACCEPTED
gotoif EQUAL ow_script_0x8e601c
lock
faceplayer
loadpointer 0x0 str_0x8e2f49
callstd MSG_YES_NO
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x8e2d6f
loadpointer 0x0 str_0x8e2d1b
callstd MSG
setflag FELSIGE_ODNIS_BEERENSAFT_QUEST_ACCEPTED
release
end


.global ow_script_0x8e2d6f
ow_script_0x8e2d6f:
loadpointer 0x0 str_0x8e2d79
callstd MSG_FACE
end


.global ow_script_0x8e601c
ow_script_0x8e601c:
checkitem ITEM_SINELBEERE 0x19
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x8e2f3f
removeitem ITEM_SINELBEERE 0x19
lock
faceplayer
loadpointer 0x0 str_0x8e2f06
callstd MSG
lock
loadpointer 0x0 str_0x8e2ee7
callstd MSG_KEEPOPEN
lock
closeonkeypress
lock
loadpointer 0x0 str_0x8e2e62
callstd MSG_KEEPOPEN
copyvarifnotzero 0x8000 ITEM_BEERENSAFT
copyvarifnotzero 0x8001 ITEM_TOP_BELEBER
callstd ITEM_OBTAIN
loadpointer 0x0 str_0x8e3064
callstd MSG
setflag FELSIGE_ODNIS_BEERENSAFT_QUEST_DONE
release
end


.global ow_script_0x8e2f3f
ow_script_0x8e2f3f:
loadpointer 0x0 str_0x8e2d1b
callstd MSG_FACE
end


.global ow_script_0x8e305a
ow_script_0x8e305a:
loadpointer 0x0 str_0x8e3064
callstd MSG_FACE
end

.global str_0x8e2f49

str_0x8e2f49:
    .string "Mein Hobby ist es, Beerensaft\nherzustellen. Gerade arbeite ich\lan einem Saft, der aus dem Extrakt\lvon Sinelbeeren hergestellt wird.\lWenn du mir genügend Sinelbeeren\lbesorgst, habe ich ein Geschenk\lfür dich.\pIch brauche - ähm - sagen wir etwa\l25 Stück.\pWas sagst du dazu?"
        
        
.global str_0x8e2d1b

str_0x8e2d1b:
    .string "Etwa 25 Sinelbeeren sollten\nausreichen, um meine neuste\lKreation fertigzustellen."
        
        
.global str_0x8e2d79

str_0x8e2d79:
    .string "Das ist äußerst schade. Wir beide\nwürden davon profitieren. Was ich\ldir zu bieten habe, ist für jeden\lTrainer sehr begehrenswert."
        
        
.global str_0x8e2f06

str_0x8e2f06:
    .string "Oh, wie wunderbar! Du hast mir 25\nSinelbeeren besorgt!"
        
        
.global str_0x8e2ee7

str_0x8e2ee7:
    .string "PLAYER übergibt die\nSinelbeeren."
        
        
.global str_0x8e2e62

str_0x8e2e62:
    .string "Sei unbesorgt, ich werde nun auch\nmeinen Teil der Vereinbarung\lerfüllen. Nimm diese versteckte\lMaschine als Zeichen meines\lDankes!"
        
        
.global str_0x8e3064

str_0x8e3064:
    .string "Beerensaft heilt die Kraftpunkte\ndeines Pokémons im Kampf und\lschmeckt dazu auch noch äußert\lgut!"
        
        
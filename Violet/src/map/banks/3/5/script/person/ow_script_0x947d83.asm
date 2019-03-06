.include "flags.s"
.include "songs.s"
.include "movements.s"
.include "items.s"
.include "callstds.s"
.include "vars.s"
.include "ordinals.s"
.include "overworld_script.s"


.global ow_script_movs_0x95a473
ow_script_movs_0x95a473:
.byte SAY_EXCLAM
.byte STOP


.global ow_script_0x947d83
ow_script_0x947d83:

loadpointer 0 str_pirate
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x95a476
callstd MSG
special 0xF

sound 0x15
faceplayer
applymovement 0x800f ow_script_movs_0x95a473
waitmovement 0x0
checkflag ROUTE_3_MILL_SAVED_ALTARIA_EGG
gotoif EQUAL ow_script_0x95a390
showmoney 0x0 0x0 0x0
loadpointer 0 str_pirate
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x95a1e9
callstd MSG_YES_NO
special 0xF

compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x95a0f6
checkmoney 0xc350 0x0
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x95a030
sound 0x41
paymoney 0xc350 0x0
updatemoney 0x0 0x0 0x0
checksound
fadesong MUS_PIRATE

loadpointer 0 str_pirate
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x959ff5
callstd MSG
special 0xF

hidemoney 0x0 0x0
lockall
copyvar 0x8004 LASTTALKED
setvar 0x8005 0x1a
setvar 0x8006 0x2e
special 0x24
pause 0x30
fadescreen 0x1
waitmovement 0x0

loadpointer 0 str_pirate
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x959fdb
callstd MSG
special 0xF

copyvar 0x8004 LASTTALKED
special 0x1b
fadescreen 0x0
waitmovement 0x0
faceplayer

loadpointer 0 str_pirate
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x959fa0
callstd MSG_KEEPOPEN
special 0xF
copyvarifnotzero 0x8000 ITEM_ITEM_10B
copyvarifnotzero 0x8001 1
callstd ITEM_OBTAIN

loadpointer 0 str_pirate
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x959f24
callstd MSG
special 0xF
fadescreen 0x1
hidesprite 0x800f
setflag ORINA_CITY_WOLKENHERZ_STOLEN
fadesong MUS_AZURIA_CITY_AND_FEUERHOHLE_AND_FUCHSANIA_CITY
fadescreen 0x0
releaseall
end


.global ow_script_movs_0x95a10d
ow_script_movs_0x95a10d:
.byte LOOK_RIGHT
.byte STOP


.global ow_script_0x95a030
ow_script_0x95a030:
hidemoney 0x0 0x0
loadpointer 0 str_pirate
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x95a047
callstd MSG
special 0xF
applymovement 0x800f ow_script_movs_0x95a10d
waitmovement 0x0
end


.global ow_script_0x95a0f6
ow_script_0x95a0f6:
hidemoney 0x0 0x0
loadpointer 0 str_pirate
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x95a110
callstd MSG
special 0xF
applymovement 0x800f ow_script_movs_0x95a10d
waitmovement 0x0
end


.global ow_script_0x95a390
ow_script_0x95a390:
loadpointer 0x0 str_0x95a3a2
callstd MSG
fadescreen 0x1
hidesprite 0x800f
fadescreen 0x0
releaseall
end


.ifdef LANG_GER
.global str_0x95a476

str_pirate:
	.string "Pirat"

str_0x95a476:
    .string "Soll ich es tunDOTS\nSoll ich es tun?\lWarum sollte ich es tun?"
        
        
.global str_0x95a1e9

str_0x95a1e9:
    .string "Hey, ich bin ein Pirat aus\nBlackbeards Crew!\pIch bin gerade im Begriff DOTS\nähDOTS\pIch bin mir absolut sicher, dass\nich dieses Museum ausrauben werde!\pDOTS\nDu siehst aus, wie jemand, der an\leinem Ausstellungsstück Interesse\lhätte.\pWas sagst du dazu, wenn ich dir\ndas Wolkenherz beschaffe, das dort\lausgestellt ist?\pHAAALT! Nicht so hastig!\nMein Preis ist hoch, denn die\lArbeit ist DOTS äh DOTS gefährlich.\lSagen wir, 50.000POKEDOLLAR?"
        
        
.global str_0x959ff5

str_0x959ff5:
    .string "Hehe! So sei es dann! Ich werde\ndir das Ding beschaffen!"
        
        
.global str_0x959fdb

str_0x959fdb:
    .string "DOTS DOTS DOTS\nDOTS DOTS DOTS"
        
        
.global str_0x959fa0

str_0x959fa0:
    .string "Na, du feiger Verbrecher!\nHehe! Ich habe, was du willst."
        
        
.global str_0x959f24

str_0x959f24:
    .string "Das ist doch ein Geschäft!\pJetzt kann ich zu Kaptain\nBlackbeard voller Stolz\lzurückkehren!\pHehe! Du Landrattfratz!\nAdieu!"
        
        
.global str_0x95a047

str_0x95a047:
    .string "Oh, du bist ja so pleite wie ein\nGrypheldis!\pHehehe! Ich werde dir das\nWolkenherz sicherlich nicht\lumsonst besorgen.\pLeih dir doch etwas Geld von der\nOrina City Bank! Hehe!"
        
        
.global str_0x95a110

str_0x95a110:
    .string "Pah! Na gut, dann werde ich eben\nwarten, bis du es dir anders\lüberlegst.\pMir scheint so, als würdest du\ndieses Wolkenherz ziemlich\ldringend gebrauchen können!\pLeih dir doch etwas Geld von der\nOrina City Bank! Hehe!"
        
        
.global str_0x95a3a2

str_0x95a3a2:
    .string "Nein, ich kann kein Musem\nausrauben, ohne dafür einen\lwirklichen Grund zu habenDOTS\pWer weiß, ob ich mit der Beute\nüberhaupt Geld verdienen könnte.\pDanke, du hast mir bei dir\nrichtigen Entscheidung geholfen!"
        
        
.elseif LANG_EN

.endif

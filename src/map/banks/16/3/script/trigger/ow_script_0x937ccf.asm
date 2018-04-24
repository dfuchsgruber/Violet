.include "callstds.s"
.include "flags.s"
.include "vars.s"
.include "ordinals.s"
.include "overworld_script.s"


.global ow_script_0x937ccf
ow_script_0x937ccf:
lockall
clearflag PKMNMENU
showsprite 0xe
setvar 0x8004 0xe
special 0x1b
waitmovement 0x0
faceplayer
loadpointer 0x0 str_0x93824f
callstd MSG_KEEPOPEN
showmoney 0xc 0x0 0x0
goto ow_script_0x937cf4


.global ow_script_0x937cf4
ow_script_0x937cf4:
loadpointer 0x0 str_0x938223
callstd MSG_KEEPOPEN
setvar DYN_MULTICHOICE_ITEM_CNT 0x4
loadpointer 0x0 choice
multichoice 0x0 0x0 0x0 0x1
setvar DYN_MULTICHOICE_ITEM_CNT 0x0
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x937da7
compare LASTRESULT 0x1
gotoif EQUAL ow_script_0x937d59
compare LASTRESULT 0x2
gotoif EQUAL ow_script_0x937d80
checkmoney 0x2710 0x0
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x937e5f
paymoney 0x2710 0x0
setvar MONEY_GIFT_FOR_HOMELESS 0x3
setvar 0x8005 0x10
goto ow_script_0x937df9


.align 4
choice:
.word str_route_4_homeless_choice0, 0
.word str_route_4_homeless_choice1, 0
.word str_route_4_homeless_choice2, 0
.word str_route_4_homeless_choice3, 0

.global ow_script_0x937df9
ow_script_0x937df9:
sound 0x41
updatemoney 0xc 0x0 0x0
loadpointer 0x0 str_0x937e0e
callstd MSG
goto ow_script_0x937e34


.global ow_script_0x937e34
ow_script_0x937e34:
hidemoney 0x0 0x0
special2 0x8005 0xc
setvar 0x8004 0xe
setvar 0x8005 0xb
setvar 0x8006 0x1a
special 0x24
waitmovement 0x0
hidesprite 0xe
setflag PKMNMENU
addvar STORY_PROGRESS 0x1
releaseall
end


.global ow_script_0x937e5f
ow_script_0x937e5f:
loadpointer 0x0 str_0x937e6d
callstd MSG_KEEPOPEN
goto ow_script_0x937cf4


.global ow_script_0x937d80
ow_script_0x937d80:
checkmoney 0x3e8 0x0
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x937e5f
paymoney 0x3e8 0x0
setvar MONEY_GIFT_FOR_HOMELESS 0x2
setvar 0x8005 0x8
goto ow_script_0x937df9


.global ow_script_0x937d59
ow_script_0x937d59:
checkmoney 0x64 0x0
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x937e5f
paymoney 0x64 0x0
setvar MONEY_GIFT_FOR_HOMELESS 0x1
setvar 0x8005 0x4
goto ow_script_0x937df9


.global ow_script_0x937da7
ow_script_0x937da7:
setvar MONEY_GIFT_FOR_HOMELESS 0x0
setvar 0x8005 0xfff8
loadpointer 0x0 str_0x937dbf
callstd MSG
goto ow_script_0x937e34


.ifdef LANG_GER
.global str_0x93824f

str_0x93824f:
    .string "-Hust-\n-Keuch-\lArgh! Ich bin ...\lHast du vielleicht etwas Geld für\lmich?\lBitte, ich habe Hunger und Durst!"
        
        
.global str_0x938223

str_0x938223:
    .string "Wie viel POKEDOLLAR möchtest du dem\nFremden geben?"
        
        
.global str_route_4_homeless_choice0

str_route_4_homeless_choice0:
    .string "Nichts"
        
        
.global str_route_4_homeless_choice1

str_route_4_homeless_choice1:
    .string "100POKEDOLLAR"
        
        
.global str_route_4_homeless_choice2

str_route_4_homeless_choice2:
    .string "1.000POKEDOLLAR"
        
        
.global str_route_4_homeless_choice3

str_route_4_homeless_choice3:
    .string "10.000POKEDOLLAR"
        
        
.global str_0x937e0e

str_0x937e0e:
    .string "Vielen ...\n-Hust-\l-Keuch-\lDank ...."
        
        
.global str_0x937e6d

str_0x937e6d:
    .string "Du hast nicht genügend POKEDOLLAR."
        
        
.global str_0x937dbf

str_0x937dbf:
    .string "-Keuch-\nHerzloser Junge...\l... Kein Respekt ...\l-Keuch-"
        
        
.elseif LANG_EN

.endif

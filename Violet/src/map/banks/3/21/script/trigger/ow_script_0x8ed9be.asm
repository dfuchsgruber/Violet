.include "flags.s"
.include "movements.s"
.include "items.s"
.include "callstds.s"
.include "vars.s"
.include "ordinals.s"
.include "overworld_script.s"


.global ow_script_movs_0x8ffc55
ow_script_movs_0x8ffc55:
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STOP


.global ow_script_0x8ed9be
ow_script_0x8ed9be:
lockall
showsprite 0x4
setflag PKMNMENU
setvar LASTTALKED 0x4
getplayerpos 0x8004 0x8005
compare 0x8004 0xc
callif EQUAL ow_script_0x8ffc6d
compare 0x8004 0xe
callif EQUAL ow_script_0x8ffc7c
compare 0x8004 0xf
callif EQUAL ow_script_0x8ffc5d
applymovement 0x800f ow_script_movs_0x8ffc55
waitmovement 0x0
call ow_script_0x8bf7fb
compare STARTER_SELECTED 0x0
gotoif EQUAL ow_script_0x8ffc2d
compare STARTER_SELECTED 0x1
gotoif EQUAL ow_script_0x8ffc41
trainerbattlecont 0x1 0x5e 0x0 str_0x8eda29 str_0x8edae8 ow_script_0x8edb20


.global ow_script_movs_0x8ede0c
ow_script_movs_0x8ede0c:
.byte SAY_EXCLAM
.byte STOP


.global ow_script_0x8edb20
ow_script_0x8edb20:
call ow_script_0x8bf7fb
loadpointer 0x0 str_0x8ffbb5
callstd MSG
special 0x7
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x8ffb51
callstd MSG
special 0x7
call ow_script_0x8bf7fb
loadpointer 0x0 str_0x8ff97b
callstd MSG
special 0x7
pause 0x20
sound 0x15
applymovement 0x800f ow_script_movs_0x8ede0c
waitmovement 0x0
checksound
call ow_script_0x8bf7fb
loadpointer 0x0 str_0x8edd68
callstd MSG_KEEPOPEN
special 0x7
copyvarifnotzero 0x8000 ITEM_EP_TEILER
copyvarifnotzero 0x8001 1
callstd ITEM_OBTAIN
call ow_script_0x8bf7fb
loadpointer 0x0 str_0x8edba7
callstd MSG
special 0x7
goto ow_script_0x926a3c


.global ow_script_movs_0x8edb9f
ow_script_movs_0x8edb9f:
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_DOWN
.byte STOP


.global ow_script_0x926a3c
ow_script_0x926a3c:
applymovement 0x800f ow_script_movs_0x8edb9f
waitmovement 0x0
hidesprite 0x800f
addvar STORY_PROGRESS 0x1
releaseall
end


.global ow_script_0x8ffc41
ow_script_0x8ffc41:
trainerbattlecont 0x1 0x5d 0x0 str_0x8eda29 str_0x8edae8 ow_script_0x8edb20


.global ow_script_0x8ffc2d
ow_script_0x8ffc2d:
trainerbattlecont 0x1 0x5c 0x0 str_0x8eda29 str_0x8edae8 ow_script_0x8edb20


.global ow_script_movs_0x8ffc69
ow_script_movs_0x8ffc69:
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STOP


.global ow_script_0x8ffc5d
ow_script_0x8ffc5d:
applymovement 0x800f ow_script_movs_0x8ffc69
waitmovement 0x0
return


.global ow_script_movs_0x8ffc88
ow_script_movs_0x8ffc88:
.byte STEP_RIGHT
.byte STOP


.global ow_script_0x8ffc7c
ow_script_0x8ffc7c:
applymovement 0x800f ow_script_movs_0x8ffc88
waitmovement 0x0
return


.global ow_script_movs_0x8ffc79
ow_script_movs_0x8ffc79:
.byte STEP_LEFT
.byte STOP


.global ow_script_0x8ffc6d
ow_script_0x8ffc6d:
applymovement 0x800f ow_script_movs_0x8ffc79
waitmovement 0x0
return


.ifdef LANG_GER
.global str_0x8eda29

str_0x8eda29:
	.autostring 35 2 "Hallo PLAYER!\pDu bist wohl auch auf dem Weg nach Kaskada, oder?\pIch sage dir eins, diese Wüste ist wirklich eine Hölle DOTS\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pWas sagst du? DOTS\pWürdest du bitte noch einmal gegen mich kämpfen?"
        
.global str_0x8edae8

str_0x8edae8:
    .autostring 35 2 "Wieso verliere ich so viele Kämpfe\pDOTS DOTS DOTS"
        
        
.global str_0x8ffbb5

str_0x8ffbb5:
	.autostring 35 2 "DOTS DOTS DOTS\pIch weiß wirklich nicht DOTS\pOb es noch einen Sinn hat DOTS\pWeiterzumachen DOTS\pDOTS DOTS DOTS"
        
.global str_0x8ffb51

str_0x8ffb51:
    .autostring 35 2 "Lass dich nicht unterkriegen, Maike!\pDu musst nur mit mehr Selbstvertrauen kämpfen!"
        
        
.global str_0x8ff97b

str_0x8ff97b:
	.autostring 35 2 "Selbstvertrauen?\pAber wie soll ich Selbstvertrauen aufbauen, wenn ich andauernd verliere?\pMein Freund aus Hoenn DOTS\pIch werde niemals auf einer Augenhöhe mit ihm sein DOTS\pIch bin einfach nicht für dieses Leben gemacht DOTS\pDOTS DOTS DOTS"

.global str_0x8edd68

str_0x8edd68:
	.autostring 35 2 "Weißt du, PLAYER DOTS\pIch finde, dass ich dir das hier geben sollte DOTS"
        
.global str_0x8edba7

str_0x8edba7:
	.autostring 35 2 "Der EP-Teiler war ein Geschenk meines Freundes aus Hoenn DOTS\pAber so ein nützliches Item ist in deinen fähigen Händen sicher besser aufgehoben DOTS\pAn mir wäre er nur verschwendet DOTS DOTS DOTS\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pDOTS DOTS DOTS"
        
.elseif LANG_EN

.endif

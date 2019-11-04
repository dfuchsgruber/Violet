.include "flags.s"
.include "movements.s"
.include "callstds.s"
.include "vars.s"
.include "ordinals.s"
.include "overworld_script.s"
.include "mugshot.s"


.global ow_script_0x947b53
ow_script_0x947b53:
setvar LASTTALKED 0x1
lockall
loadpointer 0 str_dieb
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x8d4859
callstd MSG
special 0xF

applymovement 1 mov_2

loadpointer 0 str_dieb
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x8d4782
callstd MSG
special 0xF
goto ow_script_0x8d44b9

mov_2:
.byte 2, STOP



.global ow_script_0x8d4513
ow_script_0x8d4513:
fadescreen 0x1
hidesprite 0x1
pause 0x18
fadescreen 0x0
setvar ROUTE_3_MILL_ALTARIA_EGG_SCRIPT 0x1
releaseall
end


.global ow_script_0x8d44b9
ow_script_0x8d44b9:
loadpointer 0x0 str_0x8d4644
show_mugshot MUGSHOT_PLAYER MUGSHOT_LEFT
loadpointer 0 str_dieb
setvar 0x8000 0
special 0xE
trainerbattlecont 0x1 0x26 0x0 str_0x8d4604 str_0x8d469f ow_script_0x8d44f8


.global ow_script_0x8d44f8
ow_script_0x8d44f8:
setflag ROUTE_3_MILL_SAVED_ALTARIA_EGG
loadpointer 0x0 str_0x8d4525
callstd MSG
goto ow_script_0x8d4513




.ifdef LANG_GER
.global str_0x8d4859

str_dieb:
	.string "Dieb"

str_0x8d4859:
	.autostring 35 2 "Hehe!\nJetzt kann ich mir endlich dieses Ei unter den Nagel reißen!"
        
.global str_0x8d4782

str_0x8d4782:
	.autostring 35 2 "Was? Wer bist du denn?\pWeißt du etwa auch von dem goldenen Altaria, das hier nistet?\pKeine Chance, sein Ei ist kostbar und ich werde es mir unter den Nagel reißen!"
        
.global str_mill_choice_0

str_mill_choice_0:
    .string "Ei selbst nehmen"
        
        
.global str_mill_choice_1

str_mill_choice_1:
    .string "Ei beschützen"
        
        
.global str_0x8d46e0

str_0x8d46e0:
    .autostring 35 2 "Denkst du, ich überlasse dir das Ei einfach so?\pGanz schön naiv, von dir!"
        
        
.global str_0x8d46bb

str_0x8d46bb:
    .autostring 35 2 "Du bist ja gerissen!\pAber nichts da!\pIch habe das Prachtstück schon länger im Auge!"
        
        
.global str_0x8d469f

str_0x8d469f:
    .autostring 35 2 "Verdammt!\nDas schöne Ei DOTS"
        
        
.global str_0x8d4585

str_0x8d4585:
    .autostring 35 2 "Wah!\nDu bist zu stark!\pDann nimm dir das verdammte Ei doch!\pMir hätte es sowieso nur Ärger gemacht!"
        
        
.global str_0x8d4644

str_0x8d4644:
    .autostring 35 2 "Ich werde nicht zulassen, dass dem Altaria sein Ei stiehlst!"
        
        
.global str_0x8d4604

str_0x8d4604:
    .autostring 35 2 "Hehe!\pDann wirst du es wohl verteidigen müssen!"
        
        
.global str_0x8d4525

str_0x8d4525:
    .autostring 35 2 "Urgh!\pWas hast du denn davon dieses dumme Ei zu beschützen?\pDOTS DOTS DOTS\pIch verziehe michDOTS"
        
        
.elseif LANG_EN

.endif

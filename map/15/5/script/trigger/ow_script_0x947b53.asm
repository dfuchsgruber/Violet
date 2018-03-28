.include "overworld_script.s"

.include "std.s"

.global ow_script_0x947b53
ow_script_0x947b53:
setvar LASTTALKED 0x1
lockall
loadpointer 0x0 str_0x8d4859
callstd MSG
applymovement 1 mov_2
loadpointer 0x0 str_0x8d4782
callstd MSG
setvar DYN_MULTICHOICE_ITEM_CNT 0x2
loadpointer 0x0 choice
multichoice 0x0 0x0 0x0 1
setvar DYN_MULTICHOICE_ITEM_CNT 0x0
compare LASTRESULT 0x1
gotoif LESS ow_script_0x8d44b9
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x8d46e0
callstd MSG
special 0x7
trainerbattlecont 0x1 0x26 0x0 str_0x8d46bb str_0x8d469f ow_script_0x8d44dd

mov_2:
.byte 2, STOP

.align 4
choice:
    .word str_mill_choice_1, 0
    .word str_mill_choice_0, 0

.global ow_script_0x8d44dd
ow_script_0x8d44dd:
clearflag ROUTE_3_MILL_SAVED_ALTARIA_EGG
setvar 0x8000 0xfff8
special2 0x8000 0xc
loadpointer 0x0 str_0x8d4585
callstd MSG
goto ow_script_0x8d4513


.global ow_script_0x8d4513
ow_script_0x8d4513:
fadescreen 0x1
hidesprite 0x1
pause 0x18
fadescreen 0x0
setvar ROUTE_3_MILL_ALTARIA_EGG 0x1
releaseall
end


.global ow_script_0x8d44b9
ow_script_0x8d44b9:
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x8d4644
callstd MSG
special 0x7
trainerbattlecont 0x1 0x26 0x0 str_0x8d4604 str_0x8d469f ow_script_0x8d44f8


.global ow_script_0x8d44f8
ow_script_0x8d44f8:
setflag ROUTE_3_MILL_SAVED_ALTARIA_EGG
setvar 0x8000 0x7
special2 0x8000 0xc
loadpointer 0x0 str_0x8d4525
callstd MSG
goto ow_script_0x8d4513




.ifdef LANG_GER
.global str_0x8d4859

str_0x8d4859:
    .string "Kekeke! Jetzt werde ich mir dieses\nAltaria-Ei unter den Nagel reißen!"
        
        
.global str_0x8d4782

str_0x8d4782:
    .string "Wer bist du denn?\nWeißt du, hier nistet ein goldenes\lAltaria und scheinbar hat es ein\lEi gelegt. Was denkst du, wie viel\lwohl so ein goldenes Wablu wert\list?\lAber du kriegst nichts davon! Das\list mein Ei!"
        
        
.global str_mill_choice_0

str_mill_choice_0:
    .string "Ei nehmen"
        
        
.global str_mill_choice_1

str_mill_choice_1:
    .string "Ei beschützen"
        
        
.global str_0x8d46e0

str_0x8d46e0:
    .string "Du denkst also, dass du dieses Ei\neinfach so nehmen kannst?\pNichts da, ich werde mir das\nPrachtstück holen."
        
        
.global str_0x8d46bb

str_0x8d46bb:
    .string "Was? Unsinn! Dieses Ei gehört mir!"
        
        
.global str_0x8d469f

str_0x8d469f:
    .string "Unmöglich! Das schöne Ei!"
        
        
.global str_0x8d4585

str_0x8d4585:
    .string "Wah! Du bist stark. Gegen dich\nkann ich nichts ausrichten. Nimm\ldir doch dieses dumme Ei, ich\lwollte es ohnehin nicht haben!"
        
        
.global str_0x8d4644

str_0x8d4644:
    .string "Dieses Ei gehört der Mutter und du\nwirst es ihr nicht wegnehmen.\lDafür werde ich sorgen."
        
        
.global str_0x8d4604

str_0x8d4604:
    .string "Kekeke! Dieses Ei wirst du mir\nschon wegnehmen müssen, Junge!"
        
        
.global str_0x8d4525

str_0x8d4525:
    .string "Wah! Du bist stark! Was hast du\ndenn davon, dieses blöde Ei zu\lbeschützen?\pIch verzieh\ mich!"
        
        
.elseif LANG_EN

.endif

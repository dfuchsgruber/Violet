.include "songs.s"
.include "movements.s"
.include "callstds.s"
.include "vars.s"
.include "ordinals.s"
.include "overworld_script.s"
.include "mugshot.s"


.global ow_script_movs_0x92e99c
ow_script_movs_0x92e99c:
.byte LOOK_UP
.byte STOP


.global ow_script_0x92de82
ow_script_0x92de82:
lock
faceplayer
loadpointer 0x0 str_0x92ea1b
callstd MSG_YES_NO
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x92e99f
playsong MUS_DARK_QUEEN 0x0
applymovement 0x800f ow_script_movs_0x92e99c
waitmovement 0x0
setvar 0x8004 0x1
special 0x19
waitstate
loadpointer 0x0 str_0x92e752
callstd MSG
setvar 0x8004 0x2
special 0x19
waitstate
goto ow_script_0x92eaa9


.global ow_script_0x92eaa9
ow_script_0x92eaa9:
fadesong MUS_ROUTE_24_25
compare KARMA_VALUE 0xff81
gotoif EQUAL ow_script_0x92ded4
loadpointer 0x0 str_0x92e6f1
callstd MSG_FACE
end


.global ow_script_0x92ded4
ow_script_0x92ded4:
faceplayer
loadpointer 0x0 str_0x92df22
callstd MSG
loadpointer 0x0 str_0x92def0
show_mugshot MUGSHOT_PLAYER MUGSHOT_LEFT
release
end


.global ow_script_0x92e99f
ow_script_0x92e99f:
loadpointer 0x0 str_0x92e9aa
callstd MSG
release
end


.ifdef LANG_GER
.global str_0x92ea1b

str_0x92ea1b:
    .string "Oh, du nennst mich eine Hexe!\pHehehe!\pHehehe!\pDas ist wahr! Ich bin eine Hexe!\pIch kenne viele Hexengeschichten.\nSoll ich dir eine erzählen?"
        
        
.global str_0x92e752

str_0x92e752:
    .string "Vor vielen Jahren, vor Äonen, als\ndie Legendären Pokemon die Welt\lkreierten, da existierte ein\lMensch mit der Ambition,\lunsterblich zu werden.\pSie war die dunkle Königin, die\nVerkörperung der Nacht, ein\lSchatten.\pIm Laufe der Zeit erwarb sie die\nFähigkeit, Seelen zu verschlingen,\lsie sich einzuverleiben und zu\lverbrauchen.\pBald regierte sie das ganze Land\nund war selbst den Schöpfern der\lWelt ebenbürtig.\pEines Tages aber gelang es einem\nTrainer, die finstere Königin zu\lversiegeln.\pSeit je her sind wir Hexen auf der\nSuche nach einem Weg, ihre\lunsterbliche Seele\lzurückzubringen."
        
        
.global str_0x92e6f1

str_0x92e6f1:
    .string "Eine spannende Geschichte, nicht?\pEines steht jedenfalls fest, sie\nist irgendwo da draußenDOTS "
        
        
.global str_0x92df22

str_0x92df22:
    .string "DOTS DOTS DOTS"
        
        
.global str_0x92def0

str_0x92def0:
    .string "DOTS DOTS DOTS\pErkennst du mich nicht?\pDOTS DOTS DOTS"
        
        
.global str_0x92e9aa

str_0x92e9aa:
    .string "Nah! Wie auch immer! Wir Hexen\nhaben eine uralte Geschichte und\lTraditionDOTS\pEs lohnt sich, darüber zu wissen."
        
        
.elseif LANG_EN

.endif

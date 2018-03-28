.include "overworld_script.s"

.include "std.s"

.global ow_script_movs_0x9665c2
ow_script_movs_0x9665c2:
.byte FACE_DOWN
.byte STOP


.global ow_script_0x966529
ow_script_0x966529:
applymovement 0xff ow_script_movs_0x9665c2
waitmovement 0x0
lockall
clearflag PKMNMENU
showsprite 0x2
setvar LASTTALKED 0x2
setvar 0x8004 0x2
special 0x1b
waitmovement 0x0
faceplayer
call ow_script_0x92f097
loadpointer 0x0 str_0x9665c5
callstd MSG
special 0x7
fadescreen 0x1
special 0x0
fanfare 0x19
waitfanfare
fadescreen 0x0
call ow_script_0x92f097
loadpointer 0x0 str_0x96659a
callstd MSG
special 0x7
setvar 0x8004 0x2
setvar 0x8005 0x1c
setvar 0x8006 0x5
special 0x24
waitmovement 0x0
sound 0x9
hidesprite 0x800f
checksound
addvar STORY_PROGRESS 0x1
releaseall
end

.global str_0x9665c5

str_0x9665c5:
    .string "PLAYER,\ndu bist wirklich kaum aufzuhalten.\pIch konnte dich gar nicht\neinholen, so schnell hast du\ldiesem Violet-Pack eingeheizt!\pVor uns liegt der Gipfel des\nVolcanos...\pMistral hat ihn unglücklicherweise\nwohl schon erreicht.\pWir sollten uns beeilen, ehe es\nzum Schlimmsten kommt.\pIch werde mich um deine\nangeschlagenen Pokémon kümmern..."
        
        
.global str_0x96659a

str_0x96659a:
    .string "Los, wir dürfen keine Zeit\nverlieren!"
        
        
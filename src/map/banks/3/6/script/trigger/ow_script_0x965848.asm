.include "callstds.s"
.include "flags.s"
.include "vars.s"
.include "overworld_script.s"


.global ow_script_0x965848
ow_script_0x965848:
lockall
clearflag PKMNMENU
showsprite 0x1
setvar LASTTALKED 0x1
setvar 0x8004 0x1
special 0x1b
waitmovement 0x0
faceplayer
call ow_script_0x92f097
loadpointer 0x0 str_0x963705
callstd MSG
special 0x7
setvar 0x8004 0x1
setvar 0x8005 0x22
setvar 0x8006 0x19
special 0x24
waitmovement 0x0
hidesprite 0x800f
setflag PKMNMENU
addvar STORY_PROGRESS 0x1
setworldmapflag WM_INFERIOR
releaseall
end


.ifdef LANG_GER
.global str_0x963705

str_0x963705:
    .string "Hallo PLAYER.\nDas hier ist mein Reich, die Welt\lder Flammen und der aufstrebenden\lGemüter und Geister.\pAber lass uns keine Zeit\nverlieren.\pDie Rüpel aus dieser Stadt zu\nvertreiben, wird nichts nützen,\lsolange Mistral noch immer in der\lNähe ist.\pWir sollten den Volcano erklimmen\nund ihn dort stellen.\pFolge mir einfach, wenn du bereit\nbist, aber beeile dich."
        
        
.elseif LANG_EN

.endif

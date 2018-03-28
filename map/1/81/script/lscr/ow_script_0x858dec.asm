.include "overworld_script.s"

.include "std.s"

.global ow_script_0x858dec
ow_script_0x858dec:
lockall
call ow_script_0x92f097
loadpointer 0x0 str_0x864813
callstd MSG
special 0x7
setvar 0x8004 0xd
setvar LASTTALKED 0xd
setvar 0x8005 0x1c
setvar 0x8006 0x1b
special 0x24
waitmovement 0x0
hidesprite 0x800f
addvar STORY_PROGRESS 0x1
releaseall
end


.ifdef LANG_GER
.global str_0x864813

str_0x864813:
    .string "PLAYER, wir sollten uns\nbeeilen.\pMistral befindet sich auf dem Weg\nin Richtung Gipfel.\pWir dürfen ihm nicht gestatten,\ndiesen Ort zu erreichen.\pAber sei auf der Hut:\nMistral war selbst Teil der\lRevolutionsbewegung, ehe er uns im\lStich gelassen hat.\pEr ist stark und zielstrebig, wir\nmüssen vorsichtig sein."
        
        
.elseif LANG_EN

.endif

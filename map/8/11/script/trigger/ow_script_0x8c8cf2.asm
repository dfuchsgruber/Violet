.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8c8cf2
ow_script_0x8c8cf2:
lockall
clearflag PKMNMENU
showsprite 0xc
setvar 0x8004 0xc
special 0x1b
waitmovement 0x0
faceplayer
call ow_script_0x92f097
loadpointer 0x0 str_0x93144c
callstd MSG
special 0x7
setvar 0x8005 0x1b
setvar 0x8006 0x2b
special 0x24
goto ow_script_0x93154e


.global ow_script_0x93154e
ow_script_0x93154e:
waitmovement 0x0
hidesprite 0xc
addvar STORY_PROGRESS 0x1
end


.ifdef LANG_GER
.global str_0x93144c

str_0x93144c:
    .string "Wenn ich es mir recht\nüberlege...\pVielleicht sollte ich dich diesen\nOrt doch besser auf eigene Faust\lerkunden lassen.\pImmerhin sollst du selbst die\ndunklen Geheimnisse unserer Welt\lenthüllen.\pSuch mich einfach, wenn du dich\nhier etwas umgesehen hast."
        
        
.elseif LANG_EN

.endif

.include "callstds.s"
.include "overworld_script.s"


.global ow_script_0x916258
ow_script_0x916258:
call ow_script_0x89e33c
loadpointer 0x0 str_0x931d8f
callstd MSG
faceplayer
loadpointer 0x0 str_0x931bb9
callstd MSG_FACE
special 0x7
fadescreen 0x1
hidesprite 0x800f
fadescreen 0x0
release
end


.ifdef LANG_GER
.global str_0x931d8f

str_0x931d8f:
    .autostring 35 2 "DOTS DOTS DOTS\nDOTS DOTS DOTS"
        
        
.global str_0x931bb9

str_0x931bb9:
	.autostring 35 2 "PLAYER, dich hätte ich hier sicherlich nicht erwartet.\pDu fragst dich bestimmt, was ich hier treibe, nicht?\pDOTS DOTS DOTS\pWeißt du, dass dieser illegale Untergrundmarkt von einem Mitglied der Top Vier betrieben wird?\pDas klingt lächerlich, nicht?\pAber es ist wahr.\pMein Vater ist für diesen Untergrundmarkt verantwortlich.\pUnd genau deshalb, werde ich ihn zerstören.\pIch werde alles zerstören, was mein Vater sich aufgebaut hat.\pDas ist mein großes Ziel."
        
.elseif LANG_EN

.endif

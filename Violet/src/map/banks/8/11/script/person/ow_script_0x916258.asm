.include "callstds.s"
.include "overworld_script.s"
.include "mugshot.s"


.global ow_script_0x916258
ow_script_0x916258:
draw_mugshot MUGSHOT_BLAISE MUGSHOT_RIGHT
loadpointer 0x0 str_0x931d8f
callstd MSG
faceplayer
loadpointer 0x0 str_0x931bb9
callstd MSG_FACE
hide_mugshot
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
	.autostring 34 2 "PLAYER!\nDu hast doch diesen lästigen Felix nicht auch mitgebracht, oder?\pIch war froh, ihn endlich abgeschüttelt zu haben.\pDOTS DOTS DOTS\pDich hätte ich hier nicht erwartet, wenn ich ehrlich bin.\pWeißt du, dieser Ort ist einer der Gründe, warum mein Vater zu Fall gebracht werden muss.\pEr unterhält diesen Schwarzmarkt.\pWenn du so willst, kontrolliert er die Geschehnisse hier.\pUnd er tut all das, obwohl er ein Mitglied der Top Vier ist.\pIch hoffe, dass du nicht wie Felix versuchen willst, mich aufzuhalten.\pIch habe meinen Entschluss gefasst.\pUnd ich werde mich von euch Nervensägen nicht davon abbringen lassen, meinen Vater zu stürzen.\pDOTS DOTS DOTS\nDOTS DOTS DOTS"
        
.elseif LANG_EN

.endif

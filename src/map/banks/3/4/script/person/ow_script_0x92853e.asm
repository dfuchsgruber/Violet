.include "callstds.s"
.include "flags.s"
.include "vars.s"
.include "ordinals.s"
.include "overworld_script.s"


.global ow_script_0x92853e
ow_script_0x92853e:
lock
faceplayer
call ow_script_0x92f097
loadpointer 0x0 str_0x92ee2b
callstd MSG_YES_NO
special 0x7
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x945ea6
call ow_script_0x92f097
loadpointer 0x0 str_0x92ecf0
callstd MSG
special 0x7
setflag KASKADA_BLACKMARKET_RECEIVED_PAROLE
fadescreen 0x1
hidesprite 0x800f
fadescreen 0x0
release
end


.global ow_script_0x92f097
ow_script_0x92f097:
setvar 0x8000 0x0
setvar 0x8001 0x19
setvar 0x8002 0xe
special 0x6
return


.global ow_script_0x945ea6
ow_script_0x945ea6:
call ow_script_0x92f097
loadpointer 0x0 str_0x92edce
callstd MSG_FACE
special 0x7
end


.ifdef LANG_GER
.global str_0x92ee2b

str_0x92ee2b:
    .string "Nah, hallo!\pDein Auftreten, deine\nAusstrahlung...\pDu musst PLAYER sein!\nUm dich kursieren bereits einige\lspannende Gerüchte.\pIn Kreisen der Arenaleiter loben\nLester aus Aktania und Mia aus\lSilvania dein Talent.\pUnd selbst in anderer Gesellschaft\nsind bereits die einen oder\landeren Augen auf deine Generation\lgerichtet...\p...\n...\pWie stehst du zu dieser Welt?\nWie stehst du zu dem System, das\luns beherrscht?\lHast du deine Entscheidung bereits\lgefällt?\lWeißt du, auf welcher Seite du\lkämpfen wirst?\pBevor du antwortest, solltest du\naber die ganze Wahrheit kennen.\pLass mich dir das wahre Gesicht\nunserer Welt zeigen."
        
        
.global str_0x92ecf0

str_0x92ecf0:
    .string "Wusste ich doch, dass du darauf\neingehen würdest!\pKomm einfach zu dem exklusiven\nKlubhaus im Südosten Kaskadas.\lDie geheime Eintrittsparole lautet\lKrieg den Schwachen.\p...\n...\pOh, und mein Name ist Igva!"
        
        
.global str_0x92edce

str_0x92edce:
    .string "Huh. Ich hätte dich anders\neingeschätzt.\pKomm wieder, wenn du es dir anders\nüberlegt hast."
        
        
.elseif LANG_EN

.endif

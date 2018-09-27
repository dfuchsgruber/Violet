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
	.autostring 35 2 "Nah, hallo!\nSo wie du mir aussiehst, könntest du doch glatt DOTS\pDOTS DOTS DOTS\pDu musst PLAYER sein, nicht?\pÜber dich kursieren schon spannende Gerüchte!\pStimmt es, dass du einen Kommandanten von Team Violet besiegt hast?\pWirklich interessant!\nDOTS DOTS DOTS\pSag mir einmal, was hältst du von der Revolution?\pWas hältst du von den Top Vier?\pWärst du bereit, einen Schritt weiterzugehen, und in die dunklen Geheimnisse dieser Region einzutauchen?"
.global str_0x92ecf0

str_0x92ecf0:
	.autostring 35 2 "Ich wusste, dass du darauf eingehen würdest.\pKomm zum Klubhaus im Südosten der Stadt.\pDie geheime Eintrittsparole lautet QUOTE_STARTNachtschwarzQUOTE_END.\pDOTS DOTS DOTS\pWer ich bin?\nMein Name ist Igva!"

.global str_0x92edce

str_0x92edce:
    .autostring 35 2 "Ich hätte dich anders eingeschätzt.\pKomm zu mir, wenn du deine Meinung geändert hast DOTS"
        
.elseif LANG_EN

.endif

.include "vars.s"
.include "movements.s"
.include "callstds.s"
.include "mugshot.s"
.include "ordinals.s"
.include "overworld_script.s"
.include "flags.s"

.global ow_script_map_16_3_trigger_1
.global ow_script_map_16_3_trigger_0
// Removed this script, trigger remains for var consistency among versions

ow_script_map_16_3_trigger_0:
addvar STORY_PROGRESS 1
end



ow_script_movs_0x93be3f:
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_DOWN
.byte STOP


ow_script_movs_0x93bf7b:
.byte STEP_DOWN
.byte STEP_LEFT
.byte STEP_DOWN
.byte STOP


ow_script_movs_0x93bf53:
.byte LOOK_UP
.byte SAY_EXCLAM
.byte STOP


ow_script_movs_0x93be44:
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STOP


ow_script_movs_0x93be49:
.byte FACE_DOWN
.byte STOP


ow_script_map_16_3_trigger_1:
lockall
special 0x113
applymovement 0x7f ow_script_movs_0x93be3f
waitmovement 0x0
loadpointer 0x0 str_0x93c76b
show_mugshot MUGSHOT_LARISSA MUGSHOT_RIGHT

loadpointer 0 str_manus
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x93c7d3
callstd MSG
special 0xF

loadpointer 0x0 str_0x93c80f
show_mugshot MUGSHOT_LARISSA MUGSHOT_RIGHT

loadpointer 0 str_manus
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x93c62b
callstd MSG
special 0xF

loadpointer 0x0 str_0x93c56c
show_mugshot MUGSHOT_LARISSA MUGSHOT_RIGHT

loadpointer 0 str_manus
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x93c4d7
callstd MSG
special 0xF

loadpointer 0x0 str_0x93c41a
show_mugshot MUGSHOT_LARISSA MUGSHOT_RIGHT

loadpointer 0 str_manus
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x93c1f6
callstd MSG
special 0xF

loadpointer 0x0 str_0x93bf80
show_mugshot MUGSHOT_LARISSA MUGSHOT_RIGHT
applymovement 0x17 ow_script_movs_0x93bf7b
waitmovement 0x0
sound 0x9
checksound
hidesprite 0x17

loadpointer 0 str_manus
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x93bf57
callstd MSG
special 0xF

pause 32

sound 0x15
applymovement 0x16 ow_script_movs_0x93bf53
waitmovement 0x0

loadpointer 0 str_manus
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x93bf25
callstd MSG
special 0xF

applymovement 0x7f ow_script_movs_0x93be44
waitmovement 0x0
special 0x114
setvar 0x8004 0x16
special 0x1b
waitmovement 0x0
faceplayer

loadpointer 0 str_manus
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x93be4c
callstd MSG
special 0xF

sound 0x15
applymovement 0x16 mov_exclam
waitmovement 0
checksound
pause 16


loadpointer 0 str_manus
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_last
callstd MSG
special 0xF

setvar 0x8004 0x16
setvar 0x8005 0x18
setvar 0x8006 0x4b
special 0x24
waitmovement 0x0
applymovement 0x16 ow_script_movs_0x93be49
waitmovement 0x0
sound 0x9
hidesprite 0x16
checksound
addvar STORY_PROGRESS 0x1
releaseall
end

mov_exclam:
	.byte SAY_EXCLAM, STOP


.ifdef LANG_GER

str_0x93c76b:
	.autostring 34 2 "Du bist wohl Manus, der Arenaleiter von Blütenbach, nicht?"

str_manus:
	.string "Manus"


str_0x93c7d3:
	.autostring 34 2 "Das mag schon sein, Mädchen.\pUnd wer bist du bitte?"



str_0x93c80f:
	.autostring 34 2 "Mein Name ist Larissa und mein Ziel ist es, die Dinge in dieser Region zum Besseren zu wenden."



str_0x93c62b:
	.autostring 34 2 "Haha!\nViel Glück dabei, Kindchen.\pFalls es dir nicht aufgefallen ist, Theto ist nicht mehr zu retten.\pSeitdem der Lucius, der ehemalige Champion geschlagen wurde, tobt das Chaos.\pTeam Violet terrorisiert die Bürger, und die wissen nichts besseres zu tun, als eine Revolution gegen die zu beginnen, unter deren Schutz sie stehen.\pDOTS DOTS DOTS\nVersteh einer Welt!"



str_0x93c56c:
	.autostring 34 2 "Was für eine billige Ausrede, selbst nichts unternehmen zu müssen.\pEs ist leicht, einfach die Schuld irgendwem in die Schuhe zu schieben und sich bequem hinter dem eigenen Zynismus zu verbergen.\pDu bist ein Arenaleiter und damit Teil der Pokémon-Liga.\pDu solltest vor allem dein Möglichstes tun, die Dinge zu verändern!"



str_0x93c4d7:
	.autostring 34 2 "Was fällt dir eigentlich ein, du dumme Göre?\pDu sprichst hier mit einem Arenaleiter!\pIch könnte dich an Ort und Stelle in Grund und Boden stampfen, Mädchen!"



str_0x93c41a:
	.autostring 34 2 "Habe ich einen Nerv getroffen?\pDu solltest dir meinen Ratschlag zu Herzen nehmen, Manus."


str_0x93c1f6:
	.autostring 34 2 "Was für eine Anmaßung!\pWenn du jemanden für all das verantwortlich machen möchtest, dann doch bitte nicht mich.\pErst, seitdem unser alter Champion Lucius geschlagen wurde, tobt das Chaos in dieser Region.\pUnd was treibt der neue Inhaber dieses Titels?\pEr macht sich aus dem Staub!\püberlässt die Region den Schergen der Revolution und Team Violet.\pUnd ich soll jetzt verantwortlich sein?\pGeh mir aus den Augen, du Göre!"



str_0x93bf80:
	.autostring 34 2 "DOTS DOTS DOTS\nDOTS DOTS DOTS\pDu willst deine eigene Verantwortung wohl um keinen Preis wahrhaben.\pAber früher oder später musst du einsehen, dass die Probleme Thetos nur gelöst werden können, wenn alle an einem Strang ziehen.\pWir werden uns wiedersehen, Manus, das kann ich dir versprechen."


str_0x93bf57:
    .autostring 34 2 "Was für ein unverschämtes Mädchen!"



str_0x93bf25:
    .autostring 34 2 "Hey, du da!\nHast du uns etwa belauscht?"


str_0x93be4c:
	.autostring 34 2 "DOTS DOTS DOTS\nDOTS DOTS DOTS"

str_last:
	.autostring 34 2 "Du bist ja nicht im Geringsten eingeschüchtert!\pHaha!\nDas gefällt mir!\pDie meisten Menschen sind bei meinem Anblick verängstigt!\pAber du hast echten Mumm!\nDa vergessen wir doch, dass du mich gerade so dreist belauscht hast!\pIch bin nämlich eine Kämpfernatur!\pUnd in dir, da sehe ich eine Menge Kampfgeist!\pMein Name ist Manus, und ich bin der Arenaleiter von Blütenbach.\pIch war einige Zeit lang damit beschäftigt, diesen Tunnel freizuräumen.\pEin Erdbeben hatte ihn verschüttet.\pUnd das mit bloßer Muskelkraft!\pHaha!\nKomm in meine Arena und fordere mich zu einem Kampf heraus.\pIch bin gespannt, ob deine Fähigkeiten deinem Auftreten gerecht werden, Kindchen!"


.elseif LANG_EN

.endif
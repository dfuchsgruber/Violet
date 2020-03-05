.include "movements.s"
.include "callstds.s"
.include "vars.s"
.include "overworld_script.s"
.include "mugshot.s"


.global ow_script_movs_0x93be3f
ow_script_movs_0x93be3f:
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_DOWN
.byte STOP


.global ow_script_movs_0x93bf7b
ow_script_movs_0x93bf7b:
.byte STEP_DOWN
.byte STEP_LEFT
.byte STEP_DOWN
.byte STOP


.global ow_script_movs_0x93bf53
ow_script_movs_0x93bf53:
.byte LOOK_UP
.byte SAY_EXCLAM
.byte STOP


.global ow_script_movs_0x93be44
ow_script_movs_0x93be44:
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STOP


.global ow_script_movs_0x93be49
ow_script_movs_0x93be49:
.byte FACE_DOWN
.byte STOP


.global ow_script_0x93bd44
ow_script_0x93bd44:
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


.ifdef LANG_GER
.global str_0x93c76b

str_0x93c76b:
	.autostring 35 2 "Du bist wohl Manus, der Arenaleiter von Meriana City, nicht?"
        
str_manus:
	.string "Manus"
        
.global str_0x93c7d3

str_0x93c7d3:
	.autostring 35 2 "Das mag schon sein, Mädchen.\pUnd wer bist du bitte?"
        
        
.global str_0x93c80f

str_0x93c80f:
	.autostring 35 2 "Mein Name ist Larissa DOTS\pUnd ich habe den Vorsatz, die Dinge in Theto zum Besseren zu wenden.\pIch werde Tugend und Ehre wieder zurück in diese Welt bringen."
        
        
.global str_0x93c62b

str_0x93c62b:
	.autostring 35 2 "Haha!\nViel Glück dabei, Kindchen.\pFalls es dir nicht aufgefallen ist, Theto ist nicht mehr zu retten.\pSeitdem der Lucius, der ehemalige Champion geschlagen wurde, tobt das Chaos.\pTeam Violet terrorisiert die Bürger, und die wissen nichts besseres zu tun, als eine Revolution gegen die zu beginnen, unter deren Schutz sie stehen.\pDOTS DOTS DOTS\nVersteh einer Welt!"

        
.global str_0x93c56c

str_0x93c56c:
	.autostring 35 2 "Das sagt sich so leicht, Manus.\pAber die Wahrheit ist doch, dass auch du Verantwortung für die Zustände trägst.\pBist du nicht als Arenaleiter auch dazu verpflichtet, die Lage Thetos zum Besseren zu wenden?\pUnd es nicht sogar so, dass du selbst eine nicht unbedeutende Figur im Untergrundhandel bist?\pDen Gerüchten zufolge gehören du und Devin von den Top Vier zu einem kleinen Kreis sehr gefährlicher und korrupter Menschen DOTS"

        
.global str_0x93c4d7

str_0x93c4d7:
	.autostring 35 2 "Was fällt dir eigentlich ein, du dumme Göre?\pDu sprichst hier mit einem Arenaleiter!\pIch sollte dich an Ort und Stelle zur Rechenschaft ziehen, du freches Balg!"

        
.global str_0x93c41a

str_0x93c41a:
	.autostring 35 2 "Also habe ich Recht damit?\pDOTS DOTS DOTS\pHier in Theto muss wirklich einiges getan werden DOTS"

.global str_0x93c1f6

str_0x93c1f6:
	.autostring 35 2 "So etwas Lächerliches!\pSuch doch erst einmal den neuen Champion.\pSoll der sich endlich seiner Aufgabe stellen und Ordnung in diese Region bringen.\pAber nein, der hat sich ja aus dem Staub gemacht.\pErst vertreibt er Lucius, dann überlässt er Theto den Händen der Revolution.\pGeh mir aus den Augen, Kind!"

        
.global str_0x93bf80

str_0x93bf80:
	.autostring 35 2 "DOTS DOTS DOTS\pIch kann sehr gut verstehen, wie du dich fühlst.\pDas gibt dir aber nicht das Recht, selbst alle Verantwortung, die du als Arenaleiter trägst, aufzugeben.\pDu wirst noch von mir hören, Manus."

.global str_0x93bf57

str_0x93bf57:
    .autostring 35 2 "Was fällt diesem unverschämten Mädchen eigentlich ein?"
        
        
.global str_0x93bf25

str_0x93bf25:
    .autostring 35 2 "Hey, du da!\nHast du uns etwa belauscht?"
        
.global str_0x93be4c

str_0x93be4c:
	.autostring 35 2 "Was hältst du von dem, was diese einfältige Göre da zum Besten gegeben hat?\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pAch, was rede ich denn da!\pWas interessieren solche Dinge einen Trainer, wie du es bist.\pIn deinen Augen sehe ich Kampfgeist, und das gefällt mir!\pDu bist sicher gekommen, um mich herauszufordern.\pAls Arenaleiter von Meriana City nehme ich diese Herausforderung selbstverständlich an!\pKomm in meine Arena und wir können unseren Kampf austragen, Kindchen!"

        
.elseif LANG_EN

.endif

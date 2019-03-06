.include "movements.s"
.include "callstds.s"
.include "vars.s"
.include "ordinals.s"
.include "overworld_script.s"


.global ow_script_movs_0x91fece
ow_script_movs_0x91fece:
.byte SAY_EXCLAM
.byte STOP


.global ow_script_0x8ffe00
ow_script_0x8ffe00:
loadpointer 0 str_violet
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x91fed1
callstd MSG
special 0xF
lock
sound 0x15
applymovement 0x800f ow_script_movs_0x91fece
waitmovement 0x0
faceplayer

loadpointer 0 str_violet
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x91fcc4
callstd MSG
special 0xF
setvar DYN_MULTICHOICE_ITEM_CNT 0x2
loadpointer 0x0 choice
multichoice 0x0 0x0 0x0 0x1
setvar DYN_MULTICHOICE_ITEM_CNT 0x0
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x90fdce
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x90fd48
callstd MSG
special 0x7
loadpointer 0 str_violet
setvar 0x8000 0
special 0xE
trainerbattlecont 0x1 0x64 0x0 str_0x8fff26 str_0x8fff9c ow_script_0x8ffe63

.align 4
choice:
    .word str_violet_grunt_choice_0, 0
    .word str_violet_grunt_choice_1, 0

.global ow_script_0x8ffe63
ow_script_0x8ffe63:
lock
faceplayer
loadpointer 0 str_violet
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x8ffe77
callstd MSG
special 0xF
fadescreen 0x1
hidesprite 0x800f
fadescreen 0x0
release
end


.global ow_script_0x90fdce
ow_script_0x90fdce:
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x90fe3d
callstd MSG
special 0x7

loadpointer 0 str_violet
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x90fdef
callstd MSG
special 0xF
fadescreen 0x1
hidesprite 0x800f
fadescreen 0x0
end


.ifdef LANG_GER
str_violet:
	.string "Team Violet Rüpel"

.global str_0x91fed1

str_0x91fed1:
    .autostring 35 2 "DOTS Ich habe wohl den Rest der Division verloren in all der Aufregung DOTS"
        
        
.global str_0x91fcc4

str_0x91fcc4:
	.autostring 35 2 "Hey du!\pIch kenne dich aus dem Silvania-Wald!\pWas willst du denn von mir?\pKannst du denn nicht verstehen, warum ich mich Team Violet angeschlossen habe?\pDavor war ich bloß Teil des Abschaums der Gesellschaft.\pEin niemand!\pAber jetzt bin ich Teil von etwas Großem.\pUnd dafür kämpfe ich mit meinem ganzen Herzen!"
        
.global str_violet_grunt_choice_0

str_violet_grunt_choice_0:
    .string "Rüpel gehen lassen"
        
        
.global str_violet_grunt_choice_1

str_violet_grunt_choice_1:
    .string "Rüpel bekämpfen"
        
        
.global str_0x90fd48

str_0x90fd48:
	.autostring 35 2 "Nur weil du dich wertlos fühlst, gibt dir das nicht das Recht, Gewalt gegen andere anzuwenden!"
        
        
.global str_0x8fff26

str_0x8fff26:
	.autostring 35 2 "Gegen dich zu kämpfen, bedeutet, Rins großem Ziel von der Herrschaft über Theto einen Schritt näherzukommen!"
        
        
.global str_0x8fff9c

str_0x8fff9c:
    .autostring 35 2 "Meine Niederlage DOTS\nDein Sieg DOTS DOTS DOTS\pDas alles hat keine Bedeutung DOTS"
        
        
.global str_0x8ffe77

str_0x8ffe77:
	.autostring 35 2 "Am Ende wird es Team Violet sein, das über den Kontinent herrscht.\pUnd dann werde ich endlich meinen Platz in dieser Welt haben!"
        
.global str_0x90fe3d

str_0x90fe3d:
    .autostring 35 2 "Hör mal DOTS\pIch kann verstehen, dass es nicht einfach ist, seinen Platz in der Welt zu finden DOTS\pAber merkst du nicht, dass du von Team Violet bloß benutzt wirst?\pDu bist für diese Organisation nichts als ein Bauernopfer.\pKomm zur Vernunft!"
        
.global str_0x90fdef

str_0x90fdef:
    .autostring 35 2 "DOTS DOTS DOTS\pVielleicht hast du recht.\pIch weiß nicht, woran ich glauben soll DOTS\pIch werde einiges überdenken müssen DOTS DOTS"
        
        
.elseif LANG_EN

.endif

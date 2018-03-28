.include "overworld_script.s"

.include "std.s"

.global ow_script_movs_0x8dea30
ow_script_movs_0x8dea30:
.byte FACE_DOWN
.byte STOP


.global ow_script_0x92eca8
ow_script_0x92eca8:
lock
faceplayer
call ow_script_0x8e63f4
loadpointer 0x0 str_0x8e225d
callstd MSG_KEEPOPEN
multichoice 8 8 0 1
compare LASTRESULT 0x1
gotoif EQUAL ow_script_0x947e76
playsong MUS_REVOLUTION 0x0
applymovement 0x800f ow_script_movs_0x8dea30
waitmovement 0x0
loadpointer 0x0 str_0x8e1e69
callstd MSG_KEEPOPEN
faceplayer
loadpointer 0x0 str_0x8de830
callstd MSG
special 0x7
fadescreen 0x1
hidesprite 0x800f
fadescreen 0x0
fadesong MUS_ROUTE_24_25
release
end


.global ow_script_0x947e76
ow_script_0x947e76:
loadpointer 0x0 str_0x9312b4
callstd MSG_FACE
special 0x7
end


.global ow_script_0x8e63f4
ow_script_0x8e63f4:
setvar 0x8000 0x0
setvar 0x8001 0x14
setvar 0x8002 0xe
special 0x6
return

.global str_0x8e225d

str_0x8e225d:
    .string "Sei gegrüßt, junger Trainer.\nLass mich dir etwas über unsere\lWelt erzählen, wenn du erlaubst.\lLass mich deinen Horizont\lerweitern."
        
        
.global str_0x8e1e69

str_0x8e1e69:
    .string "Du musst wissen, dass sich in\nTheto einst die fünf mächtigsten\laller Trainer vereint hatten, um\ldem Kontinent Stabilität und\lIntegrität zu verschaffen.\lSo entstand ein Herrschaftssystem,\lan dessen Spitze der Champion\lsteht. Ihm untergeordnet sind die\lTop Vier, mächtige Trainer, unter\ldenen das Gebiet Theto aufgeteilt\lwurde. Jeder von ihnen beherrscht\leinen Teil.\pDie Top Vier, die derzeit\nregieren, sind \Der Pinke\, \Die\lBlaue\, \Die Violette\ und \Der\lSchwarze\.\pNun rivalisieren diese vier aber\num die Vorherrschaft, sie sind\luntereinander teils sogar\lverfeindet. Die Bevölkerung sind\ldie leidtragenden. Korruption,\lAusbeutung und Unterdrückung sind\ldie Resultate dieses Systems,\lwelches von der Polizei geschützt\lwird.\pSag mir, ist es nicht die eines\njeden Menschen Aufgabe, sich gegen\ldie Missstände aufzulehnen?\pIch bin ein Revolutionär und\nkämpfe für Gerechtigkeit. Die Welt\lsieht uns als Verbrecher, doch\lsind wir in Wahrheit Erlöser."
        
        
.global str_0x8de830

str_0x8de830:
    .string "Es wird eine Zeit kommen, sich zu\nentscheiden, zwischen den Top Vier\lund der Revolution.\pEgal, welchen Entschluss du auch\nfasst, folge deinem Gewissen.\lDas wollte ich dir mit auf den Weg\lgeben, junger Trainer, in der\lHoffnung, es möge dich erleuchten."
        
        
.global str_0x9312b4

str_0x9312b4:
    .string "Nun, du musst dir deiner\nEntscheidungen bewusst sein...\pKomm jederzeit zu mir, wenn du es\ndir anders überlegt hast."
        
        
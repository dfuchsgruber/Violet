.include "songs.s"
.include "movements.s"
.include "callstds.s"
.include "vars.s"
.include "ordinals.s"
.include "overworld_script.s"


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
closeonkeypress
special 0x7
special 0x113
applymovement 0x7F mov_cam
waitmovement 0

fadesong MUS_REVOLUTION
applymovement 0x800f ow_script_movs_0x8dea30
waitmovement 0x0
call ow_script_0x8e63f4
loadpointer 0x0 str_0x8e1e69
callstd MSG
special 0x7
applymovement 0x7F mov_cam_back
waitmovement 0
special 0x114
faceplayer
call ow_script_0x8e63f4
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

mov_cam:
	.byte STEP_DOWN, STEP_DOWN, STEP_DOWN, STOP

mov_cam_back:
	.byte STEP_UP, STEP_UP, STEP_UP, STOP


.ifdef LANG_GER
.global str_0x8e225d

str_0x8e225d:
	.autostring 35 2 "Hallo, junger Trainer.\pBist du auch gekommen, um den Blick aufs Meer zu genießen?\pHast du vielleicht die Zeit, ein wenig dem Schwachsinn eines alten Mannes zu lauschen?"
        
.global str_0x8e1e69

str_0x8e1e69:
	.autostring 35 2 "Weißt du, wie das Regierungssystem in Theto entstanden ist?\pVor einiger Zeit taten sich drei äußerst starke Trainer zusammen und begannen den Kontinent gewaltsam zu erobern.\pEs dauerte nicht lange, da hatten sie die Herrschaft über Theto errungen.\pZwischenzeitlich hatten sich aber einige andere Trainer dem Trio angeschlossen, sodass der Kontinent schließlich unter den Stärksten von ihnen aufgeteilt wurde.\pAn ihrer Spitze stand der mächtigste Trainer, der sich fortan Champion nannte.\pTheto selbst unterteilte man in vier Gebiete, jedes von einem enorm mächtigen Trainer regiert, dessen Aufgabe es war, der Region Schutz zu bieten.\pDiese vier Trainer nennen wir heute die Top Vier und zusammen mit dem Champion bilden sie die Pokémon-Liga.\pSpäter installierte man Instiutionen wie die Landespolizei, die als Arm der Top Vier für Recht und Ordnung sorgen sollten.\pDoch im Laufe der Zeit DOTS DOTS DOTS\pAls neue Trainertalente die Posten der Top Vier besetzten, geriet das System langsam aber sicher außer Kontrolle.\pKorruption und Machtgier sowie Konflikte unter den Top Vier brachten den Bürgern viel Leid.\pDie Missstände in Theto werden von Tag zu Tag untragbarerDOTS DOTS\pUnd darum haben die Menschen irgendwann begonnen, gegen die Top Vier aufzubegehren.\pAus diesem Aufbegehren enstand schließlich die Revolutionsbewegung."
        
        
.global str_0x8de830

str_0x8de830:
	.autostring 35 2 "Wir alle müssen irgendwann entscheiden, wem wir unsere Treue leisten.\pDen Top Vier, deren Stärke der Region Stabilität sichert, oder den Bürgern, die ihn bewohnen.\pEgal, wie du dich entscheidest, Kind, lass es eine Entscheidung des Gewissens sein.\pDOTS DOTS DOTS\pNun habe ich aber genug sinniert, ich lasse dich nun wieder in Ruhe.\pVielleicht begnenen wir uns noch einmal, das kann man nie wissen."

.global str_0x9312b4

str_0x9312b4:
    .autostring 35 2 "DOTS DOTS DOTS\pDas kann ich dir natürlich nicht verübeln.\pGeh nur, ich werde es einem Kind schon nachsehenDOTS"
        
        
.elseif LANG_EN

.endif

.include "movements.s"
.include "callstds.s"
.include "flags.s"
.include "vars.s"
.include "overworld_script.s"


.global ow_script_movs_0x8ec5cb
ow_script_movs_0x8ec5cb:
.byte SAY_EXCLAM
.byte STOP


.global ow_script_0x8e6a88
ow_script_0x8e6a88:
lockall
sound 0x15
applymovement 0x800f ow_script_movs_0x8ec5cb
waitmovement 0x0
faceplayer
call ow_script_0x89c5ee
loadpointer 0x0 str_0x8ec458
callstd MSG_FACE
special 0x7
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x8e8f9d
callstd MSG_FACE
special 0x7
call ow_script_0x89c5ee
loadpointer 0x0 str_0x8e8da8
callstd MSG_FACE
special 0x7
fadescreen 0x1
hidesprite 0x800f
clearflag SILVANIA_FAUN_AND_MIA
addvar STORY_PROGRESS 0x1
fadescreen 0x0
releaseall
end


.ifdef LANG_GER
.global str_0x8ec458

str_0x8ec458:
    .string "Oh, hallo PLAYER!\nIch habe gerade alle Hände voll zu\ltun. Es heißt, der Anführer der\lRevoultion sei hier gesichtet\lworden.\lDie Revolutionsarmee strebt einen\lSturz der Top Vier an, um eine\lneue Weltordnung der Gerechtigkeit\lzu errichten. Ihre Ideale mögen\lnoch so nobel sein, bedeutet eine\lRevolution doch Krieg und Krieg\lbedeutet, dass die Bevölkerung\lThetos leiden."
        
        
.global str_0x8e8f9d

str_0x8e8f9d:
    .string "Herr Faun, ich komme aus einem\nanderen Grund. Team Violet\lbelagert den Silvania-Wald und die\lArenaleiterin Mia ist nirgends\laufzufinden."
        
        
.global str_0x8e8da8

str_0x8e8da8:
    .string "Team Violet!? Diese Gruppierung\nsind ebenso Schurken. An ihrer\lSpitze stehen einige,\lambitionierte Männer und Frauen,\ldie der Masse einreden, die Welt\lmüsse gewaltsam unterworfen\lwerden. Sie geben den Mitgliedern\ldas Gefühl von Zugehörigkeit und\lwerben so immer weitere\lGefolgsleute an.\lDieser Bedrohung müssen wir uns\lunbedingt annehmen. Der Champion\lselbst hat verlauten lassen, Team\lViolet höchste Priorität zu\lschenken.\lIch werde nach Mia suchen,\lPLAYER. Wir treffen uns in ihrem Haus,\lin Silvania."
        
        
.elseif LANG_EN

.endif

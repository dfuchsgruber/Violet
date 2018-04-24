.include "flags.s"
.include "movements.s"
.include "callstds.s"
.include "vars.s"
.include "ordinals.s"
.include "overworld_script.s"


.global ow_script_movs_0x8e07eb
ow_script_movs_0x8e07eb:
.byte SAY_EXCLAM
.byte STOP


.global ow_script_0x8e1e30
ow_script_0x8e1e30:
checkflag MERIANA_CITY_REVOLUTIONARIES
gotoif LESS ow_script_0x8de301
checkflag MERIANA_CITY_BLOCKING_REVOLUTIONARIES
gotoif EQUAL ow_script_0x8de4b5
loadpointer 0x0 str_0x8e07ee
callstd MSG_KEEPOPEN
sound 0x15
faceplayer
applymovement 0x800f ow_script_movs_0x8e07eb
waitmovement 0x0
loadpointer 0x0 str_0x8e066f
callstd MSG_KEEPOPEN
clearflag MERIANA_CITY_REVOLUTIONARIES
addvar MERIANA_CITY_REVOLUTIONARY 0x1
closeonkeypress
end


.global ow_script_0x8de4b5
ow_script_0x8de4b5:
compare STORY_PROGRESS 0x7f
gotoif EQUAL ow_script_0x8de66e
loadpointer 0x0 str_0x8de630
callstd MSG_FACE
end


.global ow_script_0x8de66e
ow_script_0x8de66e:
loadpointer 0x0 str_0x8e1de2
callstd MSG_FACE
end


.global ow_script_0x8de301
ow_script_0x8de301:
checkflag MERIANA_CITY_BLOCKING_REVOLUTIONARIES
gotoif EQUAL ow_script_0x8de4b5
loadpointer 0x0 str_0x8de430
callstd MSG_FACE
end


.ifdef LANG_GER
.global str_0x8e07ee

str_0x8e07ee:
    .string "... Korruptes Gesindel ...\p....\p....."
        
        
.global str_0x8e066f

str_0x8e066f:
    .string "Wer bist du?\n...\lDu hast also den Streit zwischen\lmir und Marq mit angehört?\lNun, die Sache ist die, dass Marq\ldie rechte Hand des Wachtmeisters\lHarrenfeld ist. Ein ganz hohes\lTier also.\lDoch er nutzt seine Macht aus. Er\lerpresst die Menschen, die hier\lleben. Nur können wir nichts gegen\ldieses korrupte Schwein\lunternehmen. Wenn wir ihn nur auf\lfrischer Tat ertappen würden..."
        
        
.global str_0x8de630

str_0x8de630:
    .string "Vielen, vielen Dank, dass du uns\narme Bürger gerettet hast!"
        
        
.global str_0x8e1de2

str_0x8e1de2:
    .string "Es wird wohl niemand den Anstand\naufbringen können, Marq zu Fall zu\lbringen."
        
        
.global str_0x8de430

str_0x8de430:
    .string "Man müsste diesen korrupten Marq\nnur auf frischer Tat ertappen.\lDann hätten wir Dorfbewohner\lendlich etwas gegen ihn in der\lHand..."
        
        
.elseif LANG_EN

.endif

.include "overworld_script.s"

.include "std.s"

.global ow_script_0x9369e4
ow_script_0x9369e4:
lockall
clearflag PKMNMENU
showsprite 0xb
setvar 0x8004 0xb
special 0x1b
waitmovement 0x0
faceplayer
fadesong MUS_0
call ow_script_0x936c1c
loadpointer 0x0 str_0x936bf6
callstd MSG
special 0x7
setflag TRANS_DISABLE
clearflag TRANS_PALETTE_FETCH
setvar 0x8004 0x3
special 0x19
waitstate
clearflag TRANS_DISABLE
call ow_script_0x936c1c
loadpointer 0x0 str_0x936ba2
callstd MSG_KEEPOPEN
playsong MUS_MISTRAL 0x0
loadpointer 0x0 str_0x936c2f
callstd MSG
special 0x7
goto ow_script_0x937652


.global ow_script_0x937652
ow_script_0x937652:
setflag TRANS_DISABLE
clearflag TRANS_PALETTE_FETCH
setvar SONG_OVERRIDE 0x16b
setvar 0x8004 0x0
special 0x19
waitstate
clearflag TRANS_DISABLE
setvar SONG_OVERRIDE 0x0
goto ow_script_0x936d7a


.global ow_script_0x936d7a
ow_script_0x936d7a:
call ow_script_0x936c1c
loadpointer 0x0 str_0x937369
callstd MSG
special 0x7
setvar 0x8004 0xb
setvar 0x8005 0xf
setvar 0x8006 0x16
special 0x24
waitmovement 0x0
hidesprite 0xb
goto ow_script_0x937675


.global ow_script_0x937675
ow_script_0x937675:
fadesong MUS_ROUTE_1_AND_TUNNELPFAD
addvar STORY_PROGRESS 0x1
releaseall
end


.global ow_script_0x936c1c
ow_script_0x936c1c:
setvar 0x8000 0x0
setvar 0x8001 0x2
setvar 0x8002 0xe
special 0x6
return

.global str_0x936bf6

str_0x936bf6:
    .string "... ... Du ...\n... ... ... ..."
        
        
.global str_0x936ba2

str_0x936ba2:
    .string "Du hast das auch gespürt,\nnicht?\pDu bist so gar nicht wie all die\nanderen..."
        
        
.global str_0x936c2f

str_0x936c2f:
    .string "Erlaube mir, mich vorzustellen.\pMein Name ist Mistral, und ich bin\n... ein Suchender, so würde ich es\lnennen.\pIch suche nach einer Bestimmung,\neinem Sinn und einer Aufgabe.\pEtwas in dieser Welt, das mich\ngrößer macht, das mich erhöht.\p... ...\n... ...\pHast du je von den drei legendären\nTrainern gehört?\pIch werde es dir erzählen."
        
        
.global str_0x937369

str_0x937369:
    .string "Die drei legendären Trainer haben\nsich wahrlich einen Namen gemacht.\nUnd ich werde ihnen nachfolgen.\pMein Interesse gilt den legendären\nPokémon und ihrer Macht.\pUnd ich bin durch und durch\nPragmat. Ich werde vor nichts\lzurückschrecken, um diese Macht zu\lerlangen...\pIch weiß nicht, wieso ich dir all\ndas erzähle, aber ich spüre eine\lVerbindung unserer Schicksale...\pDabei bin ich nicht einmal\nüberzeugt, ob es etwas wie das\lSchicksal wirklich gibt...\pVerrätst du mir noch deinen Namen?\n...\pPLAYER, also.\pIn dir lodert das selbe Feuer wie\nin meiner Seele.\pDu bist ebenso ambitioniert wie\nich.\pIrgendwann in naher Zukunft werden\nwir kämpfen.\pBis dahin will ich, dass du zu\neiner Herausforderung wirst.\lVersprich mir das."
        
        
.include "vars.s"
.include "callstds.s"
.include "songs.s"
.include "mugshot.s"
.include "flags.s"
.include "overworld_script.s"
.include "pathfinding.s"

.global ow_script_0x937675
.global ow_script_0x936d7a
.global ow_script_map_3_22_trigger_0
.global ow_script_0x937652

ow_script_map_3_22_trigger_0:
addvar STORY_PROGRESS 1
end
 // This entire cutscene is to be moved, I suppose...

setflag TRANS_DISABLE
clearflag TRANS_PALETTE_FETCH
setvar 0x8004 0x3
special 0x19
waitstate
clearflag TRANS_DISABLE
loadpointer 0x0 str_0x936ba2
show_mugshot MUGSHOT_MISTRAL MUGSHOT_LEFT
addvar STORY_PROGRESS 1
end




lockall
clearflag PKMNMENU
showsprite 0xb
npc_move_to_player 0xb
faceplayer
fadesong 0
loadpointer 0x0 str_0x936bf6
show_mugshot MUGSHOT_MISTRAL MUGSHOT_LEFT
setflag TRANS_DISABLE
clearflag TRANS_PALETTE_FETCH
setvar 0x8004 0x3
special 0x19
waitstate
clearflag TRANS_DISABLE
draw_mugshot MUGSHOT_MISTRAL MUGSHOT_LEFT
loadpointer 0x0 str_0x936ba2
callstd MSG_KEEPOPEN
playsong MUS_MISTRAL 0x0
loadpointer 0x0 str_0x936c2f
callstd MSG
hide_mugshot
goto ow_script_0x937652


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


ow_script_0x936d7a:
loadpointer 0x0 str_0x937369
show_mugshot MUGSHOT_MISTRAL MUGSHOT_LEFT
npc_move_to 0xb 0xf 0x16
hidesprite 0xb
goto ow_script_0x937675


ow_script_0x937675:
fadesong MUS_ROUTE_1_AND_TUNNELPFAD
addvar STORY_PROGRESS 0x1
releaseall
end


.ifdef LANG_GER

str_0x936bf6:
    .autostring 35 2 "DOTS DOTS DOTS\nDOTS DOTS DOTS"



str_0x936ba2:
    .autostring 35 2 "Was DOTS\nDOTS DOTS DOTS\pDOTS war das für ein seltsames Gefühl?"



str_0x936c2f:
	.autostring 35 2 "Mein Name ist Mistral.\pIch bin auf der Suche nach einer Macht, wie sie noch kein Trainer vor mir je besessen hat.\pHast du je von den drei legendären Trainern gehört, die vor vielen Jahren die Pokémon-Liga gegründet haben?"


str_0x937369:
	.autostring 35 2 "Diese drei Trainer haben die Welt verändert.\pUnd das will auch ich tun.\pUm aber etwas zu bewirken, muss man Macht besitzen.\pUnd diese Macht liegt bei den legendären Pokémon.\pWer diese Pokémon kontrolliert, wird zum Herrscher über den Rest der Welt.\pDOTS DOTS DOTS\pIch weiß gar nicht, warum ich dir das überhaupt erzähle DOTS\pAber irgendetwas sagt mir, dass sich unsere Wege schon bald wieder kreuzen werden DOTS"

.elseif LANG_EN

.endif
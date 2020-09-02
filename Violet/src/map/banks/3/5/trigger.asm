.include "vars.s"
.include "movements.s"
.include "callstds.s"
.include "mugshot.s"
.include "flags.s"
.include "overworld_script.s"
.include "items.s"
.include "pathfinding.s"

.global ow_script_map_3_5_trigger_0
.global ow_script_map_3_5_trigger_1

ow_script_movs_0x95590a:
.byte STEP_DOWN
.byte STOP


ow_script_map_3_5_trigger_0:
lockall
npc_move_to_player 0x26
faceplayer

loadpointer 0 str_police
setvar 0x8000 1
special 0xe
loadpointer 0x0 str_0x95590d
callstd MSG
special 0xf

applymovement 0xff ow_script_movs_0x95590a
waitmovement 0x0
npc_move_to 0x26 0x24 0x2
releaseall
end


.ifdef LANG_GER

str_police:
.string "Polizist"


str_0x95590d:
	.autostring 35 2 "Ich bin untröstlich, aber es wurde eine Straßensperre angeordnet, um die zwei Divisionen von Team Violet, die sich derzeit im Osten Thetos aufhalten, dingfest zu machen.\pIch kann dich nicht passieren lassen!"
.elseif LANG_EN

.endif


ow_script_map_3_5_trigger_1:
addvar STORY_PROGRESS 0x1
end

// Moved to the lab of the professor

lockall
clearflag PKMNMENU
showsprite 0x27
npc_move_to_player 0x27
faceplayer
loadpointer 0x0 str_0x955b31
show_mugshot MUGSHOT_ELISE MUGSHOT_RIGHT MSG_KEEPOPEN
copyvarifnotzero 0x8000 ITEM_ZUGANGSKARTE
copyvarifnotzero 0x8001 1
callstd ITEM_OBTAIN
loadpointer 0x0 str_0x955a4c
show_mugshot MUGSHOT_ELISE MUGSHOT_RIGHT
npc_move_to 0x27 0x3c 0x1f
hidesprite 0x27
addvar STORY_PROGRESS 0x1
releaseall
end


.ifdef LANG_GER

str_0x955b31:
	.autostring 35 2 "Ah, PLAYER!\nWie ich sehe, hast du hergefunden.\pIm Norden der Stadt befindet sich die Laz.Corp, wo mein Vater und ich arbeiten.\pKomm mich dort besuchen und ich zeige dir das künstliche Pokémon.\pDafür wirst du natürlich diese Zugangskarte benötigen."



str_0x955a4c:
	.autostring 35 2 "Die Zugangskarte ermöglicht dir den Zutritt zu verschiedenen Stockwerken der Laz.Corp.\pIch konnte dir natürlich nur Zutritt zum Cyberlabor verschaffen, die anderen Stockwerke kannst du daher nicht besuchen.\pDas verstehst du sicher, nicht PLAYER?\pAlso, ich erwarte dich im Cyberlabor!"

.elseif LANG_EN

.endif
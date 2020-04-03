.include "ordinals.s"
.include "vars.s"
.include "songs.s"
.include "callstds.s"
.include "mugshot.s"
.include "flags.s"
.include "overworld_script.s"
.include "items.s"

.global ow_script_0x95f001
.global ow_script_0x95efaa
.global ow_script_map_3_24_trigger_0
.global ow_script_0x95efbe

ow_script_map_3_24_trigger_0:
lockall
clearflag PKMNMENU
showsprite 0x3
setflag PKMNMENU
playsong MUS_RIVALE_ERSCHEINT_GARY 0x0
setvar 0x8004 0x3
special 0x1b
waitmovement 0x0
faceplayer
draw_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT
compare STARTER_SELECTED 0x0
gotoif EQUAL ow_script_0x95efaa
compare STARTER_SELECTED 0x1
gotoif EQUAL ow_script_0x95efbe
trainerbattlecont 0x1 0xbe 0x0 str_0x95f326 str_0x95efd2 ow_script_0x95f001


ow_script_0x95f001:
loadpointer 0x0 str_0x95f255
show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT MSG_KEEPOPEN
copyvarifnotzero 0x8000 ITEM_VM03
copyvarifnotzero 0x8001 1
callstd ITEM_OBTAIN
loadpointer 0x0 str_0x95f051
show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT
fadescreen 0x1
hidesprite 0x3
fadescreen 0x0
addvar STORY_PROGRESS 0x1
releaseall
end


ow_script_0x95efbe:
trainerbattlecont 0x1 0xbd 0x0 str_0x95f326 str_0x95efd2 ow_script_0x95f001


ow_script_0x95efaa:
trainerbattlecont 0x1 0xbc 0x0 str_0x95f326 str_0x95efd2 ow_script_0x95f001


.ifdef LANG_GER

str_0x95f326:
	.autostring 34 2 "PLAYER!\nKeine Sorge, ich habe mich etwas abgeregt, seit Papa uns von seiner Expedition erzählt hat.\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pIch habe wohl ein wenig überreagiert.\pNichts desto trotz war ich hinterher nicht nur deswegen sauer, sondern auch, weil ich eigentlich die Gelegenheit nutzen wollte, um dich zum Kampf herauszufordern.\pDas passiert mir aber kein zweites Mal!"


str_0x95efd2:
    .autostring 34 2 "Was?\nIch habe verloren?\pDu hast wirklich eine Glückssträhne, PLAYER!"



str_0x95f255:
	.autostring 34 2 "Alle Achtung, nicht schlecht gekämpft, PLAYER!\pWenn ich alles gegeben hätte, wäre das ganze natürlich anders ausgegangen.\pIch habe dich nämlich gewinnen lassen!\pJa, so ist das DOTS\pAuf jeden Fall wirst du so niemals den Vulkan-Orden bekommen.\pLass mich dir etwas helfen, PLAYER DOTS"


str_0x95f051:
    .autostring 34 2 "Diese Versteckte Maschine enthält Surfer, die perfekte Waffe im Kampf gegen das Feuer.\pDu brauchst mir nicht zu danken, immerhin will ich ja, dass du auch weiterhin ein interessanter Gegner bleibst DOTS\pUnd beim nächsten Mal werde ich alles geben.\pDa kannst du jede Hilfe brauchen!\pMan sieht sich, PLAYER!"


.elseif LANG_EN

.endif
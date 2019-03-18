.include "flags.s"
.include "songs.s"
.include "items.s"
.include "callstds.s"
.include "vars.s"
.include "ordinals.s"
.include "overworld_script.s"
.include "mugshot.s"


.global ow_script_0x95ef61
ow_script_0x95ef61:
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


.global ow_script_0x95f001
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


.global ow_script_0x95efbe
ow_script_0x95efbe:
trainerbattlecont 0x1 0xbd 0x0 str_0x95f326 str_0x95efd2 ow_script_0x95f001


.global ow_script_0x95efaa
ow_script_0x95efaa:
trainerbattlecont 0x1 0xbc 0x0 str_0x95f326 str_0x95efd2 ow_script_0x95f001


.ifdef LANG_GER
.global str_0x95f326

str_0x95f326:
	.autostring 35 2 "PLAYER!\nLange nicht gesehen, du altes Bummelz!\pDu bist wohl auf dem Weg nach Inferior, um dir den Vulkan-Orden zu ergattern?\pDa bin ich dir wohl schon zuvor gekommen.\pWollen wir doch mal sehen, ob überhaupt für diese Arena bereit bist!"

.global str_0x95efd2

str_0x95efd2:
    .autostring 35 2 "Was?\nIch habe verloren?\pDu hast wirklich eine Glückssträhne, PLAYER!"
        
        
.global str_0x95f255

str_0x95f255:
	.autostring 35 2 "Alle Achtung, nicht schlecht gekämpft, PLAYER!\pWenn ich alles gegeben hätte, wäre das ganze natürlich anders ausgegangen.\pIch habe dich nämlich gewinnen lassen!\pJa, so ist das DOTS\pAuf jeden Fall wirst du so niemals den Vulkan-Orden bekommen.\pLass mich dir etwas helfen, PLAYER DOTS"

.global str_0x95f051

str_0x95f051:
    .autostring 35 2 "Diese Versteckte Maschine enthält Surfer, die perfekte Waffe im Kampf gegen das Feuer.\pDu brauchst mir nicht zu danken, immerhin will ich ja, dass du auch weiterhin ein interessanter Gegner bleibst DOTS\pUnd beim nächsten Mal werde ich alles geben.\pDa kannst du jede Hilfe brauchen!\pMan sieht sich, PLAYER!"
        
        
.elseif LANG_EN

.endif

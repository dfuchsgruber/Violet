.include "items.s"
.include "callstds.s"
.include "flags.s"
.include "vars.s"
.include "overworld_script.s"
.include "mugshot.s"


.global ow_script_0x9559ed
ow_script_0x9559ed:
addvar STORY_PROGRESS 0x1
end

// Moved to the lab of the professor

lockall
clearflag PKMNMENU
showsprite 0x27
setvar 0x8004 0x27
special 0x1b
waitmovement 0x0
faceplayer
loadpointer 0x0 str_0x955b31
show_mugshot MUGSHOT_ELISE MUGSHOT_RIGHT MSG_KEEPOPEN
copyvarifnotzero 0x8000 ITEM_ZUGANGSKARTE
copyvarifnotzero 0x8001 1
callstd ITEM_OBTAIN
loadpointer 0x0 str_0x955a4c
show_mugshot MUGSHOT_ELISE MUGSHOT_RIGHT
setvar 0x8004 0x27
setvar 0x8005 0x3c
setvar 0x8006 0x1f
special 0x24
waitmovement 0x0
hidesprite 0x27
addvar STORY_PROGRESS 0x1
releaseall
end


.ifdef LANG_GER
.global str_0x955b31

str_0x955b31:
	.autostring 35 2 "Ah, PLAYER!\nWie ich sehe, hast du hergefunden.\pIm Norden der Stadt befindet sich die Laz.Corp, wo mein Vater und ich arbeiten.\pKomm mich dort besuchen und ich zeige dir das künstliche Pokémon.\pDafür wirst du natürlich diese Zugangskarte benötigen."

        
.global str_0x955a4c

str_0x955a4c:
	.autostring 35 2 "Die Zugangskarte ermöglicht dir den Zutritt zu verschiedenen Stockwerken der Laz.Corp.\pIch konnte dir natürlich nur Zutritt zum Cyberlabor verschaffen, die anderen Stockwerke kannst du daher nicht besuchen.\pDas verstehst du sicher, nicht PLAYER?\pAlso, ich erwarte dich im Cyberlabor!"

.elseif LANG_EN

.endif

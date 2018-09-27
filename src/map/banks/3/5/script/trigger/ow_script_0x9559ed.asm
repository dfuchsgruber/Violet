.include "items.s"
.include "callstds.s"
.include "flags.s"
.include "vars.s"
.include "overworld_script.s"


.global ow_script_0x9559ed
ow_script_0x9559ed:
lockall
clearflag PKMNMENU
showsprite 0x27
setvar 0x8004 0x27
special 0x1b
waitmovement 0x0
faceplayer
call ow_script_0x8a7f80
loadpointer 0x0 str_0x955b31
callstd MSG_KEEPOPEN
special 0x7
copyvarifnotzero 0x8000 ITEM_EICHS_PAKET
copyvarifnotzero 0x8001 1
callstd ITEM_OBTAIN
call ow_script_0x8a7f80
loadpointer 0x0 str_0x955a4c
callstd MSG
special 0x7
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

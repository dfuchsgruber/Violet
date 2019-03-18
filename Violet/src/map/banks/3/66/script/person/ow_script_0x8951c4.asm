.include "callstds.s"
.include "flags.s"
.include "songs.s"
.include "overworld_script.s"
.include "mugshot.s"


.global ow_script_0x8951c4
ow_script_0x8951c4:
lockall
faceplayer
loadpointer 0x0 str_0x843a47
show_mugshot MUGSHOT_TANN MUGSHOT_RIGHT

call ow_script_healing_sequence

checkflag MERIANA_CITY_VIOLET_GRUNTS
playsong MUS_VERTANIA_CITY_AND_MARMORIA_CITY_AND_SAFFRONIA_CITY 0x0
loadpointer 0x0 str_0x843aba
show_mugshot MUGSHOT_TANN MUGSHOT_RIGHT MSG_FACE
releaseall
end


.ifdef LANG_GER
.global str_0x843a47

str_0x843a47:
	.autostring 35 2 "Du und deine Pokémon sehen ja schrecklich erschöpft aus!\pSetz dich doch erst einmal eine Weile hin und ruh dich aus!"
        
        
.global str_0x843aba

str_0x843aba:
	.autostring 35 2 "Na siehst du?\pDu und deine Pokémon sehen schon wieder ganz fit aus!"
        
        
.elseif LANG_EN

.endif

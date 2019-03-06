.include "callstds.s"
.include "flags.s"
.include "songs.s"
.include "overworld_script.s"


.global ow_script_0x8951c4
ow_script_0x8951c4:
lockall
faceplayer
call ow_script_0x895cf9
loadpointer 0x0 str_0x843a47
callstd MSG
special 0x7

call ow_script_healing_sequence

checkflag MERIANA_CITY_VIOLET_GRUNTS
playsong MUS_VERTANIA_CITY_AND_MARMORIA_CITY_AND_SAFFRONIA_CITY 0x0
call ow_script_0x895cf9
loadpointer 0x0 str_0x843aba
callstd MSG_FACE
special 0x7
releaseall
end


.global ow_script_0x895cf9
ow_script_0x895cf9:
setvar 0x8000 0x1
setvar 0x8001 0xb
setvar 0x8002 0xe
special 0x6
return


.ifdef LANG_GER
.global str_0x843a47

str_0x843a47:
	.autostring 35 2 "Du und deine Pokémon sehen ja schrecklich erschöpft aus!\pSetz dich doch erst einmal eine Weile hin und ruh dich aus!"
        
        
.global str_0x843aba

str_0x843aba:
	.autostring 35 2 "Na siehst du?\pDu und deine Pokémon sehen schon wieder ganz fit aus!"
        
        
.elseif LANG_EN

.endif

.include "callstds.s"
.include "flags.s"
.include "vars.s"
.include "ordinals.s"
.include "overworld_script.s"


.global ow_script_0x8a5564
ow_script_0x8a5564:
lock
faceplayer
checkflag WONDERTRADE
gotoif EQUAL ow_script_0x8a5ccb
call ow_script_0x8a7343
release
end


.global ow_script_0x8a7343
ow_script_0x8a7343:
call ow_script_0x8a7f80
loadpointer 0x0 str_0x8aac71
callstd MSG
special 0x7
fanfare 0x13e
loadpointer 0x0 str_0x8aa801
callstd MSG_KEEPOPEN
closeonkeypress
waitfanfare
setflag WONDERTRADE
call ow_script_0x8a7f80
loadpointer 0x0 str_0x8ab119
callstd MSG_FACE
special 0x7
setvar STORY_PROGRESS 0x10
return


.global ow_script_0x8a5ccb
ow_script_0x8a5ccb:
call ow_script_0x8a7f80
loadpointer 0x0 str_0x8a7951
callstd MSG
special 0x7
release
end


.ifdef LANG_GER
.global str_0x8aac71

str_0x8aac71:
	.autostring 35 2 "Ohje, PLAYER!\nBeinahe hätte ich vergessen, dass auch ich für euch noch ein Geschenk habe.\pSeit einiger Zeit widme ich mich nämlich einem System, das helfen soll, Trainer von überall miteinander zu verbinden.\pDieses System heißt Wundertausch und das Ganze ist, um ehrlich zu sein, unglaublich aufregend!\pMan bietet eines seiner Pokémon zum Tausch an.\pDann wird es an einen Trainer irgendwo auf der Welt versandt und man erhält dessen verschicktes Pokémon.\pMan weiß nie, wen dein Pokémon erreicht!\pSpannend nicht?\pIch werde die Wundertausch-App auf deinem Poképad installieren."
        
.global str_0x8aa801

str_0x8aa801:
    .autostring 35 2 "Elise hat die Wundertausch-App auf dem Pokepad installiert!"
        
        
.global str_0x8ab119

str_0x8ab119:
	.autostring 35 2 "Eine Sache noch.\pJe öfter du den Wundertausch benutzt, desto höher steigt dein Level.\pMit einem hohen Wundertausch-Level kannst du mit anderen erfahrenen Trainern tauschen, sodass du häufiger seltene Pokémon mit besonderen Fähigkeiten erhältst.\pDadurch lohnt es sich für jeden, die App häufig zu benutzen und die Menschen der Welt zu verbinden.\pDas ist mein großer Traum.\pIch würde mich freuen, wenn du mir hilfst, ihn zu verwirklichen und den Wundertausch oft benutzt."
        
.global str_0x8a7951

str_0x8a7951:
    .autostring 35 2 "Bald schon werden alle Trainer dieser Welt den Wundertausch benutzen!\pDavon bin ich fest überzeugt!"
        
        
.elseif LANG_EN

.endif

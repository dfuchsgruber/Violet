.include "overworld_script.s"
.include "callstds.s"
.include "flags.s"
.include "items.s"
.include "vars.s"
.include "ordinals.s"

.global ow_script_feslige_oednis_clouds_person_0
.global ow_script_feslige_oednis_clouds_person_1
.global ow_script_feslige_oednis_clouds_person_2
.global ow_script_tafelberg_clouds_west_bait_gift

ow_script_tafelberg_clouds_west_bait_gift:
    checkflag FLAG_TAFELBERG_CLOUDS_BAIT
    gotoif EQUAL bait_done
    lock
    faceplayer
    loadpointer 0 str_bait_give
    callstd MSG_KEEPOPEN
    copyvarifnotzero 0x8000 ITEM_ELITEKOEDER
	copyvarifnotzero 0x8001 5
	callstd ITEM_OBTAIN
    compare LASTRESULT 0
    gotoif EQUAL bait_no_space
    setflag FLAG_TAFELBERG_CLOUDS_BAIT
bait_done:
    loadpointer 0 str_bait_done
    callstd MSG_FACE
    end
bait_no_space:
    loadpointer 0 str_no_space
    callstd MSG_FACE
    end

ow_script_feslige_oednis_clouds_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end
ow_script_feslige_oednis_clouds_person_1:
    loadpointer 0 str_1
    callstd MSG_FACE
    end
ow_script_feslige_oednis_clouds_person_2:
    loadpointer 0 str_2
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_bait_give:
    .autostring 34 2 "Ein Trainer, huh?\pDu hoffst wohl, hier oben 'nen besseren Fang zu machen, oder?\pIch verrate dir mal etwasDOTS\pDen Unterschied macht der Köder.\pProbier diesen hier, er hat mir gute Dienste erwiesen."
str_bait_done:
    .autostring 34 2 "Mit diesem Köder beißen weitaus stärkere Pokémon, vertrau mir!"
str_no_space:
    .autostring 34 2 "Eine volle Ködertasche, was?\pDann kannst du meinen Köder wohl gar nicht gebrauchenDOTS"
str_0:
    .autostring 34 2 "In meiner Jugend wollte ich diese Himmelsinseln erobern.\pAber das Balg Lucius ist mir zuvor gekommen.\pWas soll ich sagenDOTS\pEr hat es schließlich bis zum Titel des Champion geschafft.\pAber auch er ist irgendwann von seinem Thron gefallen, oder?\pWeißt du, wer sein Nachfolger ist?"
str_1:
    .autostring 34 2 "Immer wenn man denkt, man hätte hier oben alles gesehen, wird man eines Besseren belehrt.\pHast du zum Beispiel schon die funkelnden Kristalle gefunden, die hier oben gewachsen sind?"
str_2:
    .autostring 34 2 "Bist schon einmal diesen sogenannten Kryptikern begegnet?\pDiese Leute machen mich verrückt.\pHaben nichts im Kopf als ihre seltsame antike Sprache.\pWen interessiert es, was die Inschriften auf den Ruinen hier oben bedeuten?"
.elseif LANG_EN

.endif
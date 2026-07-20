.include "overworld_script.s"
.include "callstds.s"
.include "vars.s"

.global ow_script_laz_corp_clouds_lab_person_0
.global ow_script_laz_corp_clouds_lab_person_1
.global ow_script_laz_corp_clouds_lab_person_2
.global ow_script_laz_corp_clouds_lab_weather_egg_recipe

ow_script_laz_corp_clouds_lab_person_0:
    loadpointer 0x0 str_0
    callstd MSG_FACE
    end

ow_script_laz_corp_clouds_lab_person_1:
    loadpointer 0x0 str_1
    callstd MSG_FACE
    end

ow_script_laz_corp_clouds_lab_person_2:
    loadpointer 0x0 str_2
    callstd MSG_FACE
    end

ow_script_laz_corp_clouds_lab_weather_egg_recipe:
    lockall
	hidesprite LASTTALKED
    fanfare 261
	loadpointer 0 str_player_found_recipe
	callstd MSG_KEEPOPEN
	waitfanfare
	loadpointer 0 str_recipe_can_be_used
	callstd MSG_KEEPOPEN
	releaseall
	end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Ich bin der Laborleiter dieser Forschungsgruppe.\pWir erforschen das Wetter und welche Auswirkungen bestimmte Faktoren darauf haben.\pUnser Ziel ist es, das Wetter selbst beeinflussen zu können."
str_1:
    .autostring 34 2 "Vor einiger Zeit haben wir Eier entwickelt, die kurzfristig ein bestimmtes Wetterereignis auslösen können.\pNun gilt es, eine Technologie zu entwerfen, die diesen Effekt langfristig aufrechterhalten kann."
str_2:
    .autostring 34 2 "Unsere Arbeit zur Klima- und Wetterforschung wird seit geraumer Zeit von Priestern eines längst vergangenen Zeitalters bekämpft.\pSie halten es für Anmaßung, dass wir versuchen, das Wetter zu beeinflussen.\pAber Sonnenschein erzeugt günstige Energie und Regen sorgt für Wachstum auf den Feldern.\pIst es wirklich falsch, das Wetter zu unserem Vorteil zu nutzen?"
str_player_found_recipe:
    .autostring 34 2 "PLAYER hat das Rezept zur Herstellung von Wetter-Eiern erhalten."
.elseif LANG_EN
.endif
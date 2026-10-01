.include "overworld_script.s"
.include "callstds.s"
.include "flags.s"
.include "ordinals.s"
.include "vars.s"

.global tv_show_text_swarm
.global tv_show_text_weather_forecast_sunny
.global tv_show_text_weather_forecast_rainy
.global tv_show_text_weather_forecast_snowy
.global tv_show_text_weather_forecast_unknown
.global tv_show_text_new_champ
.global tv_show_tann_done_text
.global tv_show_bruchfels_done_text
.global tv_show_felsige_oednis_rival_done
.global tv_show_silvania_forest_done
.global tv_show_kuestenberg_done
.global tv_show_bluetenbach_gym_done
.global tv_show_mistral_igva_done
.global tv_show_volcano_done

.global tv_show_default_text

.global ow_script_tv

ow_script_tv:
    lockall
    callasm special_get_tv_broadcast_is_on
    compare LASTRESULT 0
    gotoif EQUAL watched_show
    callasm tv_load_text
    callstd MSG_KEEPOPEN
    setflag FLAG_TV_DAILY_SHOW_SEEN
    release
    end
watched_show:
    loadpointer 0 str_watched_show
    callstd MSG_KEEPOPEN
    release
    end

.ifdef LANG_GER

tv_show_text_swarm:
    .autostring 34 2 "Brennende Neuigkeiten für alle Pokémon-Fans da draußen!\pAuf BUFFER_1 haben unsere Reporter Schwärme von BUFFER_2 gesehen!\pAlso schnell, schnappt euch euer Pokémon und macht euch auf den Weg nach BUFFER_1!"
tv_show_text_weather_forecast_sunny:
    .autostring 34 2 "Die Wettervorhersage für heute lautet: Starker Sonnenschein auf BUFFER_1.\pZieht euch also Sonnenbrillen an und vergesst nicht, euch einzucremen!"
tv_show_text_weather_forecast_rainy:
    .autostring 34 2 "Die Wettervorhersage für heute lautet: Starker Regen auf BUFFER_1.\pVergesst also nicht, eure Regenschirme mitzunehmen!"
tv_show_text_weather_forecast_snowy:
    .autostring 34 2 "Die Wettervorhersage für heute lautet: Starker Schneefall auf BUFFER_1.\pZieht euch also warm an und vergesst nicht, eure Schneeschuhe mitzunehmen!"
tv_show_text_weather_forecast_unknown:
    .autostring 34 2 "Die Wettervorhersage für heute lautet: Unbekanntes Wetter auf BUFFER_1.\pWir können euch auch nichts Genaueres sagen, also zieht euch einfach an, wie ihr wollt!"
tv_show_text_new_champ:
    .autostring 34 2 "Was wissen wir denn nun über unseren neuen Champion?\pNun, seitdem unser alter Champion Lucius besiegt wurde, scheint der Thron leerzustehen.\pWir wissen praktisch nichts über den NachfolgerDOTS\pIst es ein Mann oder eine Frau?\pIst die Person ein etablierter Trainer oder ein Newcomer?\pHoffentlich werden wir bald mehr erfahren!\pUnd was aus Lucius wird?\pNun, wen kümmert das noch ernsthaft, wo wir doch einen neuen stärkeren Trainer an der Spitze haben!"
tv_show_default_text:
    .autostring 34 2 "Es läuft die Wiederholung einer Sendung, die du schon oft gesehen hastDOTS\pEs lohnt sich nicht, sie noch einmal anzusehen."
tv_show_tann_done_text:
    .autostring 34 2 "Eilmeldung!\pWir berichten vom Kraftwerk aus Hochpolis-City, wo es zu einem Zwischenfall gekommen ist.\pMitglieder Revolutionsbewegung haben das Kraftwerk infiltriert und die Stromversorgung der Stadt lahmgelegt.\pDie Polizei ist vor Ort und versucht, die Situation unter Kontrolle zu bringen.\pWir halten euch auf dem Laufenden!"
tv_show_bruchfels_done_text:
    .autostring 34 2 "Bald exklusiv im Interview: Professor Tann.\pWir sprechen mit dem renomierten Archäologen über seine jüngsten Entdeckungen.\pIn seinem neuesten Buch enthüllt Professor Tann Geheimnisse einer alten Zivilisation, die vor vielen Jahren auf im Himmel fliegenden Inseln lebte.\pEr befasst sich mit den Ursachen ihres Untergangs und seinen bemerkenswerten Funden in den Ruinen dieser verlorenen Welt.\pWir sind gespannt, welche weiteren Erkenntnisse Professor Tann in Zukunft noch mit uns teilen wird!"
tv_show_felsige_oednis_rival_done:
    .autostring 34 2 "In Gedenken an die Tragödie, die Bruchfels vor vielen Jahren heimgesucht hat.\pAus dem einstigen Ferienparadis ist nun ein Ort der Trauer geworden.\pDie meisten Bewohner sind inzwischen weggezogen, aber einige wenige haben ihre Häuser trotz des immerwährenden Unwetters behalten.\pWir sprechen mit dem Arenaleiter der Stadt, dessen Vater bei dem Unglück ums Leben kam.\pUnd danach erzählt uns Professor Primus von der Laz. Corp. über die fasziniernden Annomalien, die Bruchfels seit dem Unglück heimsuchen.\pWir hoffen, dass die Stadt eines Tages wieder zu ihrem alten Glanz zurückfinden wird."
tv_show_silvania_forest_done:
    .autostring 34 2 "Bald exklusiv im Interview: Devin von den Top Vier.\pWir sprechen über die Bedrohungen für Theto unserer Zeit.\pWie können wir die Region vor der stetig wachsenen Revolutionsbewegung schützen?\pUnd warum gewinnt die Gruppe immer mehr Anhänger, die sich gegen die Regierung der Top Vier auflehnen?"
tv_show_kuestenberg_done:
    .autostring 34 2 "Sehen Sie nur exklusiv bei uns: Die Verfilmung der Geschichte der Pokémon-Liga.\pVon den drei legendären Trainern, die die Top Vier gegründet haben.\pVon den Anfängen der Liga und den ersten Arenaleitern.\pErleben sie den Pinken Faun, den Stillen Albus, und den Großen Lucius hautnah.\pWas ist aus den Gründervätern der Pokémon-Liga geworden?\pFaun führt inzwischen eine Schule bei Anemonia und bildet die neue Generation an Trainern aus.\pAlbus dagegen führt die Revolution gegen seine ehemaligen Kameraden ins Feld und gilt als der gefährlichste Kriminelle unserer Zeit.\pUnd Lucius, unser einstiger Champion?\pWas ist aus ihm geworden?\pGerüchten zufolge hat er sich auf seine Burg Ardeal zurückgezogen.\pWas hat er nun vor?\pDas und viele weitere spannende Fragen sehen Sie bald bei uns im Programm."
tv_show_bluetenbach_gym_done:
    .autostring 34 2 "Eilmeldung: Ein ehemaliges Mitglied der Revolutionsbewegung erhebt schwere Vorwürfe gegen Devin von den Top Vier.\pEr behauptet, dass Devin ein kriminelles Untergrundnetzwerk mit engen Verbindungen zur Revolutionsbewegung und den Blackbeard Piraten unterhält.\pDevin dagegen streitet alle Vorwürfe entschieden ab.\pAber die Ermittlungen der Polizei beginnen gerade erst.\pWir halten euch auf dem Laufenden!"
tv_show_mistral_igva_done:
    .autostring 34 2 "Sehen Sie bald unsere Reportage zum kürzlichen Raub im Museum von Hochpolis City.\pEin Mann namens Mistral soll das Magmaherz entwendet haben.\pZuvor hat er sich als hochrangiges Mitglied der Revolutionsbewegung einen Namen gemacht.\pIst die Pokémon-Liga noch in der Lage, uns vor solchen Verbrechern zu beschützen?\pGerät die Situation außer Kontrolle?"
tv_show_volcano_done:
    .autostring 34 2 "Im Profil: Danica, das jüngste Mitglied der Top Vier.\pDie ehemalige Schülerin des einstigen Champs Lucius.\pMan sagt, dass ihr Blick dem eines Drachen-Pokémon gleicht.\pDoch wer ist diese mysteriöse junge Trainerin, die so erfolgreich bereits über einen Teil der Region herrscht?\pErfahren sie es bei uns in unserer nächsten Spezialsendung."


str_watched_show:
    .autostring 34 2 "Du hast dir heute schon eine Sendung angesehen.\pVielleicht läuft morgen etwas Interessantes!"
.elseif LANG_EN
.endif
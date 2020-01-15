.include "overworld_script.s"
.include "callstds.s"

.global ow_script_route_7_person_16
.global ow_script_route_7_person_17
.global ow_script_route_7_person_18
.global ow_script_route_7_person_19
.global ow_script_route_7_person_20
.global ow_script_route_7_person_21
.global ow_script_route_7_person_22

ow_script_route_7_person_16:
    loadpointer 0 str_0
    callstd MSG_FACE
    end
ow_script_route_7_person_17:
    loadpointer 0 str_1
    callstd MSG_FACE
    end
ow_script_route_7_person_18:
    loadpointer 0 str_2
    callstd MSG_FACE
    end
ow_script_route_7_person_19:
    loadpointer 0 str_3
    callstd MSG_FACE
    end
ow_script_route_7_person_20:
    loadpointer 0 str_4
    callstd MSG_FACE
    end
ow_script_route_7_person_21:
    loadpointer 0 str_5
    callstd MSG_FACE
    end
ow_script_route_7_person_22:
    loadpointer 0 str_6
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Was den Menschen heutzutage fehlt, ist, einfach einmal für einige Stunden den Geist ins Nichts wandern zu lassen.\pNur den Horizont betrachten, und die Sonne, die auf- und untergehtDOTS"
str_1:
    .autostring 34 2 "Hast du dich gefragt, ob manche Menschen Kokowei mit einer Palme verwechseln?"
str_2:
    .autostring 34 2 "Lass mich in Ruhe, ich sonne mich gerade!\pWo hast du deine Höflichkeit gelassen?"
str_3:
    .autostring 34 2 "Die Top Vier können einem eine Menge Angst einjagen, so mächtig, wie sie sind.\pBesonders der Schwarze Devin ist mir überhaupt nicht geheuerDOTS"
str_4:
    .autostring 34 2 "Hast du schon vom legendären Angler gehört?\pEr lebt direkt dort in dem Strandhaus.\pDu solltest ihn besuchen."
str_5:
    .autostring 34 2 "Ich habe den ganzen Tag gekämpftDOTS\pJetzt muss ich mich etwas ausruhen."
str_6:
    .autostring 34 2 "Mein Schwimmreifen hat ein LochDOTS\pJetzt kann ich nicht mehr planschenDOTS"

.elseif LANG_EN
str_0:
    .autostring 34 2 "What people lack nowadays is the ability to let your mind wander into nothingness for a few hours.\pJust glaring at the horizon and the sun, rising and sinkingDOTS"
str_1:
    .autostring 34 2 "Did you ever wonder if people confuse Exeggutor with a palmtree?"
str_2:
    .autostring 34 2 "Leave me alone, I am taking a sunbath!\pWhere did you lose your etiquette?"
str_3:
    .autostring 34 2 "The Elite Four can be quite intimidating looking at their power.\pIn particular, the Black Devin is suspicious to meDOTS"
str_4:
    .autostring 34 2 "Did you hear about the legendary fisherman?\pHe lives in that beach house right over there.\pYou should visit him."
str_5:
    .autostring 34 2 "I fought all dayDOTS\pNow I am tired and have to rest."
str_6:
    .autostring 34 2 "There's a hole in my rubber ringDOTS\pNow I can't splash anymoreDOTS"

.endif
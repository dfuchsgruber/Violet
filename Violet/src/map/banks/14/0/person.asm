.include "overworld_script.s"
.include "callstds.s"
.include "flags.s"
.include "vars.s"
.include "specials.s"
.include "ordinals.s"
.include "treasure_map.s"

.global ow_script_route_10_clouds_person_0
.global ow_script_route_10_clouds_person_1
.global ow_script_route_10_clouds_person_2
.global ow_script_route_10_clouds_person_3
.global ow_script_route_10_tann_assistant

ow_script_route_10_clouds_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end

ow_script_route_10_clouds_person_1:
    loadpointer 0 str_1
    callstd MSG_FACE
    end

ow_script_route_10_clouds_person_2:
    loadpointer 0 str_2
    callstd MSG_FACE
    end
    
ow_script_route_10_clouds_person_3:
    loadpointer 0 str_3
    callstd MSG_FACE
    end

ow_script_route_10_tann_assistant:
    checkflag FLAG_TREASURE_MAPS_APP
    gotoif 1 map_app_received
    lock
    faceplayer
    loadpointer 0 str_check_dex
    callstd MSG
    setvar 0x8004 1
    special2 LASTRESULT SPECIAL_POKEDEX_GET_STATS
    compare 0x8006 30
    gotoif LESS end_assistant
    buffernumber 0 0x8006
    sound 0x15
    applymovement LASTTALKED mov_exclam
    waitmovement 0
    checksound
    loadpointer 0 str_has_caught_enough
    callstd MSG_KEEPOPEN
    fanfare 0x13E
    loadpointer 0 str_received_app
    callstd MSG_KEEPOPEN
    waitfanfare
    setflag FLAG_TREASURE_MAPS_APP
    loadpointer 0 str_explain_map_app
    callstd MSG_KEEPOPEN
    give_treasure_map treasure_map_idx=3 give_type=TREASURE_MAP_OBTAIN
    lock
    faceplayer
    loadpointer 0 str_gave_map
    callstd MSG_KEEPOPEN
    release
    end
map_app_received:
    loadpointer 0 str_explain_map_app_after
    callstd MSG_FACE
    end
end_assistant:
    release
    end

.ifdef LANG_GER
str_check_dex:
    .autostring 34 2 "Hallo, PLAYER!\pIch bin ein Assistent von Professor Tann.\pWenn du 30 verschiedene Pokémon gefangen hast, soll ich dir ein Geschenk geben."
str_has_caught_enough:
    .autostring 34 2 "Fantastisch!\pDu hast bereits BUFFER_1 Pokémon in der Pokédex-App registriert.\pAls Belohnung werde ich eine neue App auf deinem Poképad installieren."
str_received_app:
    .autostring 34 2 "Die Karten-App wurde auf dem Poképad installiert!"
str_explain_map_app:
    .autostring 34 2 "Mit dieser Map können Schatzkarten, die von der antiken Ziviliastion auf den Wolkeninseln hinterlassen wurden, entschlüsselt werden.\pIch gebe dir gleich noch eine Karte, die wir erst kürzlich auf einer Ausgrabung entdeckt haben."
str_gave_map:
    .autostring 34 2 "Die Karte zeigt dir, wo ein Schatz vergraben liegt.\pEs ist trotz unserer Technologie nicht immer einfach, den Ort auch wirklich zu findenDOTS\pAber ich bin guter Dinge, dass du viele Schätze aufspüren wirst!\pUnd wenn du die App benutzt, hilfst du Professor Tann bei der Erforschung der antiken Zivilisation hier oben!"
str_explain_map_app_after:
    .autostring 34 2 "Die Karten-App zeigt dir, wo Schätze vergraben liegen.\pProfessor Tann glaubt, dass die Zivilisation, die einmal hier oben gelebt haben muss, sie zurückgelassen hat."
str_0:
    .autostring 34 2 "Unter den Wolkenreitern erzählt man sich von einem großen grünen Drachen, der durch die Ozonschicht streift.\pIch würde zugerne wissen, ob an der Legende etwas Wahres istDOTS"
str_1:
    .autostring 34 2 "Die Höhlensysteme in dieser Schlucht gleichen einem Labyrinth.\pIch habe mich dort einmal für mehrere Tage verirrtDOTS"
str_2:
    .autostring 34 2 "Ich habe wirklich vorhin den Schrei eines Ursaring gehörtDOTS\pJetzt bloß keine falschen BewegungenDOTS"
str_3:
    .autostring 34 2 "Diese Schlucht ist wirklich ein beeindruckendes Naturschauspiel.\pDie schwebenden Inseln hier oben sind wirklich etwas anderes, als die Welt unten auf dem BodenDOTS"
.elseif LANG_EN
str_0:
    .autostring 34 2 "A story among cloud riders tells about a great grean dragon that wanders through the ozon.\pI really want to know if there is any truth to this legendDOTS"
.endif

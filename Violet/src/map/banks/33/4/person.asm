.include "overworld_script.s"
.include "callstds.s"



.global ow_script_blackbeard_ship_deck_person0
.global ow_script_blackbeard_ship_deck_person1
.global ow_script_blackbeard_ship_deck_person2
.global ow_script_blackbeard_ship_deck_person3
.global ow_script_blackbeard_ship_deck_person4
.global ow_script_blackbeard_ship_deck_person5
.global ow_script_blackbeard_ship_deck_person6
.global ow_script_blackbeard_ship_deck_person7
.global ow_script_blackbeard_ship_deck_person8
.global ow_script_blackbeard_ship_deck_person9

ow_script_blackbeard_ship_deck_person0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end
ow_script_blackbeard_ship_deck_person1:
    loadpointer 0 str_1
    callstd MSG_FACE
    end
ow_script_blackbeard_ship_deck_person2:
    loadpointer 0 str_2
    callstd MSG_FACE
    end
ow_script_blackbeard_ship_deck_person3:
    loadpointer 0 str_3
    callstd MSG_FACE
    end
ow_script_blackbeard_ship_deck_person4:
    loadpointer 0 str_4
    callstd MSG_FACE
    end
ow_script_blackbeard_ship_deck_person5:
    loadpointer 0 str_5
    callstd MSG_FACE
    end
ow_script_blackbeard_ship_deck_person6:
    loadpointer 0 str_6
    callstd MSG_FACE
    end
ow_script_blackbeard_ship_deck_person7:
    loadpointer 0 str_7
    callstd MSG_FACE
    end
ow_script_blackbeard_ship_deck_person8:
    loadpointer 0 str_8
    callstd MSG_FACE
    end
ow_script_blackbeard_ship_deck_person9:
    loadpointer 0 str_9
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Mein Kartenglück scheint mich verlassen zu habenDOTS\pAber wie heißt es doch so schön?\pPech im Spiel, Glück inDOTS?"
str_1:
    .autostring 34 2 "Gibt es etwas ergreiferenderes, als in die endlose Weite zu starren?\pSorglos ins Irgendwo segeln!\pDas ist es, was das Piratenleben ausmacht!"
str_2:
    .autostring 34 2 "Pah!\nMeinen ganzen Anteil an der letzten Beute hab ich verspieltDOTS\pDas verdammte GlücksspielDOTS"
str_3:
    .autostring 34 2 "Es ist wirklich ein Segen, wenn Blackbeard nicht am Tisch sitzt.\pWenn du ihn abzockst, stehen die Chancen nicht gerade schlecht, dass man dich über Board wirft!"
str_4:
    .autostring 34 2 "Das Deck zu schrubben ist eine leidige Arbeit.\pAber als Neuling wird man zu solchen Aufgaben degradiertDOTS"
str_5:
    .autostring 34 2 "Wann immer wir ein feindliches Schiff entdecken, feuern wir aus allen Rohren!\pZurecht erzittern alle Seefahrer in dieser Region, wenn sie die Schattenflut erblicken."
str_6:
    .autostring 34 2 "Mein Gold ist längst futschDOTS\pOb ich eines meiner Pokémon als Einsatz anbieten sollte?"
str_7:
    .autostring 34 2 "Wir haben die interessantesten Gefangenen hier an Board.\pProfessor Tann allerdings scheint ganz besonders die Aufmerksamkeit des Kapitäns erregt zu haben."
str_8:
    .autostring 34 2 "Ein Pirat kriegt niemals den Hals voll.\pGanz egal, ob es um Essen, Schätze oder Raublust geht!"
str_9:
    .autostring 34 2 "Seit Stunden kein Land in Sicht.\pIch hätte gerne einen Abstecher bei dieser seltsamen Burg auf Route 7 gemacht, aber der Kapitän meinte, dass wir uns von diesem Ort lieber fernhalten solltenDOTS"


.elseif LANG_EN
.endif
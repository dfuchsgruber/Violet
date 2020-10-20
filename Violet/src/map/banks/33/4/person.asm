.include "overworld_script.s"
.include "callstds.s"
.include "flags.s"
.include "ordinals.s"


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
.global ow_script_blackbeard_ship_deck_person_with_treasure_room_keys

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

ow_script_blackbeard_ship_deck_person_with_treasure_room_keys:
    checkflag FLAG_BBSHIP_KEY_TO_TREASURE_ROOM
    gotoif EQUAL got_keys_already
    lock
    faceplayer
    trainerbattlecont 1 0x198 0 str_before str_after key_cont
key_cont:
    lock
    faceplayer
    loadpointer 0 str_get_key
    callstd MSG
    fanfare 257
    loadpointer 0 str_receive_key
    callstd MSG
    waitfanfare
    setflag FLAG_BBSHIP_KEY_TO_TREASURE_ROOM
    release
    end

got_keys_already:
    loadpointer 0 str_got_key
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
str_before:
    .autostring 34 2 "Was?\nIch habe keinen Schlüssel!\pErst recht nicht den, für die Schatzkammer!\pVerstanden?\pDOTS DOTS\pDu bist immer noch da?\pKampflos werde ich dir den Schlüssel nicht überlassen!"
str_after:
    .autostring 34 2 "Auweia!\nDas gibt ÄrgerDOTS"
str_get_key:
    .autostring 34 2 "Zum ersten Mal vertraut man mir solche wichtigen Dinge an, und ich vermassel es gleich wiederDOTS\pNa gut, du kannst den Schlüssel haben."
str_receive_key:
    .autostring 34 2 "PLAYER erhält den Schlüssel zur Schatzkammer der Schattenflut.\pEr wird dem Schlüsselbund hinzugefügt."
str_got_key:
    .autostring 34 2 "Wenn der Kapitän herauskriegt, dass ich den Schlüssel zur Schatzkammer verloren habeDOTS"


.elseif LANG_EN
str_before:
    .autostring 34 2 "What?\nI don't have any keys with me.\pAnd even if, it wouldn't be the keys to the treasure room.\pGot it?\pDOTS DOTS\nWhy, you're still here?\pI won't hand those keys over without a fight!"
str_after:
    .autostring 34 2 "Oh man, I'm in big troubleDOTS"
str_get_key:
    .autostring 34 2 "First time I am entrusted with something this important and I screw it up in an instantDOTS\pWell, you can have the keysDOTS"
str_receive_key:
    .autostring 34 2 "PLAYER received the keys to the treasure room.\pThey are added to the keychain."
str_got_key:
    .autostring 34 2 "When the captain finds out that I lost the keys to the treasure roomDOTS"

.endif
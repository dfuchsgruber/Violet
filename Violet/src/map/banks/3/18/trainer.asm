
.include "overworld_script.s"
.include "callstds.s"

.global ow_script_route_7_trainer_9
.global ow_script_route_7_trainer_10
.global ow_script_route_7_trainer_11
.global ow_script_route_7_trainer_12
.global ow_script_route_7_trainer_13
.global ow_script_route_7_trainer_14
.global ow_script_route_7_trainer_26
.global ow_script_route_7_trainer_27

ow_script_route_7_trainer_9:
    trainerbattlestd 0x0 0x148 0 str_before_0 str_after_0
    loadpointer 0x0 str_after_0
    callstd MSG_FACE
    end
ow_script_route_7_trainer_10:
    trainerbattlestd 0x0 0x149 0 str_before_1 str_after_1
    loadpointer 0x0 str_after_1
    callstd MSG_FACE
    end
ow_script_route_7_trainer_11:
    trainerbattlestd 0x0 0x14a 0 str_before_2 str_after_2
    loadpointer 0x0 str_after_2
    callstd MSG_FACE
    end
ow_script_route_7_trainer_12:
    trainerbattlestd 0x0 0x14b 0 str_before_3 str_after_3
    loadpointer 0x0 str_after_3
    callstd MSG_FACE
    end
ow_script_route_7_trainer_13:
    trainerbattlestd 0x0 0x14c 0 str_before_4 str_after_4
    loadpointer 0x0 str_after_4
    callstd MSG_FACE
    end
ow_script_route_7_trainer_14:
    trainerbattlestd 0x0 0x14d 0 str_before_5 str_after_5
    loadpointer 0x0 str_after_5
    callstd MSG_FACE
    end
ow_script_route_7_trainer_26:
    trainerbattlestd 0x0 0x17a 0 str_before_6 str_after_6
    loadpointer 0x0 str_after_6
    callstd MSG_FACE
    end
ow_script_route_7_trainer_27:
    trainerbattlestd 0x0 0x17b 0 str_before_7 str_after_7
    loadpointer 0x0 str_after_7
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_before_0:
    .autostring 34 2 "Ich bin schon seit Stunden am trainieren!\pEs wird Zeit, für etwas Abwechslung!"
str_after_0:
    .autostring 34 2 "UffDOTS\pWar mein ganzes Training nicht genug?"
str_before_1:
    .autostring 34 2 "Mein Papi ist ein großartiger Schwimmer!\pUnd ich werde in seine Fußstapfen treten!"
str_after_1:
    .autostring 34 2 "Meinst du, es ist ein Problem, dass ich nicht schwimmen kann?"
str_before_2:
    .autostring 34 2 "Die Gegend um Haweiland ist ein Geheimtipp unter Anglern.\pNirgends sonst beißen die Pokémon so gut!\pIch werde dir zeigen, was für ein Prachtexemplar ich an Land gezogen habe!"
str_after_2:
    .autostring 34 2 "Warte du nur ab!\pBald habe ich noch mehr starke Pokémon geangeltDOTS"
str_before_3:
    .autostring 34 2 "Ich bin stinksauer, weil meine Picknickdecke sandig geworden ist!\pUnd jetzt musst eben du herhalten!"
str_after_3:
    .autostring 34 2 "Erst eine Decke voller Sand und dann diese NiederlageDOTS"
str_before_4:
    .autostring 34 2 "Dieser reudige Pirat Blackbeard hat vor einigen Tagen unser Schiff geentert und unsere Güter gestohlen.\pWenn ich diesen Halkunen in die Finger kriege!\pIch zeige dir, was ich mit ihm machen werde, Kindchen!"
str_after_4:
    .autostring 34 2 "Bitte was?\pIch habe jetzt auch noch gegen ein Kind verloren?"
str_before_5:
    .autostring 34 2 "Ob das Angeln nicht langweilig wird?\pLassen wir doch unsere Pokémon entscheiden!"
str_after_5:
    .autostring 34 2 "Das ging ins AugeDOTS"
str_before_6:
    .autostring 34 2 "Es gibt keinen Augenblick, in dem meine Schönheit mehr strahlt, als im Kampf!"
str_after_6:
    .autostring 34 2 "Wiebitte?\nDu hast dich von meinem makellosen Äußeren nicht ablenken lassen?"
str_before_7:
    .autostring 34 2 "Hier ist alles so sandigDOTS\pIch bin wirklich schlecht gelaunt!"
str_after_7:
    .autostring 34 2 "Jetzt ist ist meine ganze Kleidung sandigDOTS"

.elseif LANG_EN
str_before_0:
    .autostring 34 2 "I have been working out for hours now!\pTime for something else!"
str_after_0:
    .autostring 34 2 "UffDOTS\pSo all my training hasn't been enough?"
str_before_1:
    .autostring 34 2 "My dad is a great swimmer!\pAnd I will follow his footsteps!"
str_after_1:
    .autostring 34 2 "Do you think it will be a problem that I can't swim?"
str_before_2:
    .autostring 34 2 "The area around Haweiland is a secret tipp for fishermen.\pNowhere else Pokémon are bite this well!\pI will show what kind of Pokémon I managed to pull out of the ocean!"
str_after_2:
    .autostring 34 2 "Just you wait!\pSoon I will have fished for even more strong PokémonDOTS"
str_before_3:
    .autostring 34 2 "I am very angry because my picnic blanket got all sandy.\pAnd now you will have to pay for that!"
str_after_3:
    .autostring 34 2 "First a blanket full of sand and now this defeatDOTS"
str_before_4:
    .autostring 34 2 "This dirty pirate Blackbeard boarded our ship a few days ago and stole all our goods.\pIf I get my hands on this scoundrelDOTS\pI will show you what I will do to him, kiddy!"
str_after_4:
    .autostring 34 2 "Come again?\pNow I also lost against a child?"
str_before_5:
    .autostring 34 2 "If fishing isn't way to boring?\pHow about we let our Pokémon decide?"
str_after_5:
    .autostring 34 2 "That didn't end well for sureDOTS"
.endif
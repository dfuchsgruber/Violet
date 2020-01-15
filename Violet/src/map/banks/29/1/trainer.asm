
.include "overworld_script.s"
.include "callstds.s"

.global ow_script_route_7_trainer_15
.global ow_script_route_7_trainer_16
.global ow_script_route_7_trainer_17
.global ow_script_route_7_trainer_18
.global ow_script_route_7_trainer_19
.global ow_script_route_7_trainer_20
.global ow_script_route_7_trainer_21
.global ow_script_route_7_trainer_22
.global ow_script_route_7_trainer_23
.global ow_script_route_7_trainer_24
.global ow_script_route_7_trainer_25

ow_script_route_7_trainer_15:
    trainerbattlestd 0x0 0x14e 0 str_before_0 str_after_0
    loadpointer 0x0 str_after_0
    callstd MSG_FACE
    end
ow_script_route_7_trainer_16:
    trainerbattlestd 0x0 0x14f 0 str_before_1 str_after_1
    loadpointer 0x0 str_after_1
    callstd MSG_FACE
    end
ow_script_route_7_trainer_17:
    trainerbattlestd 0x0 0x150 0 str_before_2 str_after_2
    loadpointer 0x0 str_after_2
    callstd MSG_FACE
    end
ow_script_route_7_trainer_18:
    trainerbattlestd 0x0 0x151 0 str_before_3 str_after_3
    loadpointer 0x0 str_after_3
    callstd MSG_FACE
    end
ow_script_route_7_trainer_19:
    trainerbattlestd 0x0 0x152 0 str_before_4 str_after_4
    loadpointer 0x0 str_after_4
    callstd MSG_FACE
    end
ow_script_route_7_trainer_20:
    trainerbattlestd 0x0 0x153 0 str_before_5 str_after_5
    loadpointer 0x0 str_after_5
    callstd MSG_FACE
    end
ow_script_route_7_trainer_21:
    trainerbattlestd 0x0 0x154 0 str_before_6 str_after_6
    loadpointer 0x0 str_after_6
    callstd MSG_FACE
    end
ow_script_route_7_trainer_22:
    trainerbattlestd 0x0 0x155 0 str_before_7 str_after_7
    loadpointer 0x0 str_after_7
    callstd MSG_FACE
    end
ow_script_route_7_trainer_23:
    trainerbattlestd 0x0 0x156 0 str_before_8 str_after_8
    loadpointer 0x0 str_after_8
    callstd MSG_FACE
    end
ow_script_route_7_trainer_24:
    trainerbattlestd 0x0 0x157 0 str_before_9 str_after_9
    loadpointer 0x0 str_after_9
    callstd MSG_FACE
    end
ow_script_route_7_trainer_25:
    trainerbattlestd 0x0 0x158 0 str_before_10 str_after_10
    loadpointer 0x0 str_after_10
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_before_0:
    .autostring 34 2 "Mein Pokémon ist in der Lage, jedes andere Pokémon, das ich an Land ziehe, zu besiegen!"
str_after_0:
    .autostring 34 2 "Unfassbar!\pDu hast mein unbesiegbares Pokémon geschlagen!"
str_before_1:
    .autostring 34 2 "Meine Eltern machen Urlaub in Haweiland!\pIch habe aber viel mehr Lust auf einen Kampf, als mich an den Strand zu legen!"
str_after_1:
    .autostring 34 2 "Wenn ich es mir so überlegeDOTS\pWäre eine Pause am Strand vielleicht doch das BesteDOTS"
str_before_2:
    .autostring 34 2 "In meiner Jugend habe ich gegen Albus gekämpft.\pSeit dieser Niederlage bin ich bedeutend stärker geworden."
str_after_2:
    .autostring 34 2 "Du bist starkDOTS\pAber nichts im Vergleich zu AlbusDOTS"
str_before_3:
    .autostring 34 2 "Ich habe auf dem Expeditionsschiff von Professor Tann angeheuert.\pJetzt, da wir von Blackbeard überfallen worden sind, will ich seiner Crew beitreten!"
str_after_3:
    .autostring 34 2 "Ob ich jetzt noch Blackbeards Crew beitreten kann?"
str_before_4:
    .autostring 34 2 "Ich bin den ganzen Weg von Ceometria hierher geschwommen.\pDa kann ich es auch mit einem Kind aufnehmen!"
str_after_4:
    .autostring 34 2 "Moment!\nWie hast du mich besiegt?"
str_before_5:
    .autostring 34 2 "Mein Pokémon ist das knuffigste Ding auf der ganzen Welt!\pAber es hat es auch faustig hinter den Ohren!"
str_after_5:
    .autostring 34 2 "Mein armes PokémonDOTS"
str_before_6:
    .autostring 34 2 "Was soll ich hier an diesem Strand?\pDie Sonne brennt auf meiner Haut!\pIch will zurück in mein Zimmer!"
str_after_6:
    .autostring 34 2 "Lass mich bloß in Ruhe!"
str_before_7:
    .autostring 34 2 "Den ganzen Tag in die Wellen zu starrenDOTS\pDas ist ermüdendDOTS\pKannst du Abhilfe verschaffen?"
str_after_7:
    .autostring 34 2 "Zack!\nSo schnell reißt einen die Realität zurück ins kalte Wasser!"
str_before_8:
    .autostring 34 2 "Wasser-Pokémon sind so faszinierend!\pIch wünschte, dass mir Kiemen wachsen würden!"
str_after_8:
    .autostring 34 2 "Was für eine EnttäuschungDOTS\pWeder besitze ich Kiemen, noch habe ich gewonnenDOTS"
str_before_9:
    .autostring 34 2 "Als Schwimmer bin ich ein Meister der Koordination.\pMeine Pokémon stehen mir in der Beziehung in Nichts nach!"
str_after_9:
    .autostring 34 2 "Meine Pokémon und ich haben koordiniert verlorenDOTS"
str_before_10:
    .autostring 34 2 "Es heißt, dass es Schwimmer gäbe, die Wasserfälle hinaufschwimmen können.\pOb ich bereits stark dafür bin?"
str_after_10:
    .autostring 34 2 "Mit dieser Stärke werde ich keine Wasserfälle erklimmen könnenDOTS"

.elseif LANG_EN
str_before_0:
    .autostring 34 2 "My Pokémon is able to defeat every other Pokémon I pull ashore!"
str_after_0:
    .autostring 34 2 "Unbelievable!\pHow could you defeat my unbeaten Pokémon?"
str_before_1:
    .autostring 34 2 "My parents are on vacation in Haweiland.\pBut I'd much rather fight than lying on a beach!"
str_after_1:
    .autostring 34 2 "If I think about itDOTS\pMaybe lying on a beach and taking a rest would be best for nowDOTS"
str_before_2:
    .autostring 34 2 "I once battled Albus during my younger days.\pEver since this crushing defeat I have become significantly stronger!"
str_after_2:
    .autostring 34 2 "You are strongDOTS\pBut nothing compared to Albus stillDOTS"
str_before_3:
    .autostring 34 2 "I worked onboard the expedition vessel that belongs to Professor Tann.\pNow, that we were raided by Blackbeard, I want to join his crew instead!"
str_after_3:
    .autostring 34 2 "Do you think I still can get hired on Blackbeard's ship?"
str_before_4:
    .autostring 34 2 "I swam all the way here from Ceometria.\pNow I can as well fight a little child, I suppose!"
str_after_4:
    .autostring 34 2 "Wait a second!\nHow did I lose now?"
str_before_5:
    .autostring 34 2 "My Pokémon is the most fluffy thing in the entire world!\pBut it also can strike pretty hard!"
str_after_5:
    .autostring 34 2 "My poor little thingDOTS"
str_before_6:
    .autostring 34 2 "What am I supposed to do at this beach?\pThe sun is burning my skin!\pI want to go back to my room!"
str_after_6:
    .autostring 34 2 "Just leave me alone!"
str_before_7:
    .autostring 34 2 "Just staring into the water all day longDOTS\pIt's so tiresomeDOTS\pCan you help me out here?"
str_after_7:
    .autostring 34 2 "Whosh!\nThat's how quickly reality throws you back into the cold water!"
str_before_8:
    .autostring 34 2 "Water-Pokémon are so fascinating.\pI wish I would grow gills!"
str_after_8:
    .autostring 34 2 "What a disappointment.\pNeither did I grow gills nor could I win the battleDOTS"
str_before_9:
    .autostring 34 2 "As a swimmer I am a master of coordination.\pMy Pokémon are similar to me in that respect!"
str_after_9:
    .autostring 34 2 "My Pokémon and I lost well coordinatedDOTS"
str_before_10:
    .autostring 34 2 "People say there are swimmers strong enough to climb waterfalls.\pI wonder if I am strong enough for that!"
str_after_10:
    .autostring 34 2 "I probably can't climb any waterfall being this weakDOTS"
.endif
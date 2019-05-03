.include "overworld_script.s"
.include "callstds.s"

.global ow_script_forest_cemetery_trainer_0
.global ow_script_forest_cemetery_trainer_1
.global ow_script_forest_cemetery_trainer_2
.global ow_script_forest_cemetery_trainer_3
.global ow_script_forest_cemetery_trainer_4
.global ow_script_forest_cemetery_trainer_5
.global ow_script_forest_cemetery_trainer_6
.global ow_script_forest_cemetery_trainer_7
.global ow_script_forest_cemetery_trainer_8

ow_script_forest_cemetery_trainer_0:
    trainerbattlestd 0 0xea 0 str_trainer0_challange str_trainer0_defeat
    loadpointer 0 str_trainer0_defeat
    callstd MSG_FACE
    end
ow_script_forest_cemetery_trainer_1:
    trainerbattlestd 0 0xeb 0 str_trainer1_challange str_trainer1_defeat
    loadpointer 0 str_trainer1_defeat
    callstd MSG_FACE
    end
ow_script_forest_cemetery_trainer_2:
    trainerbattlestd 0 0xec 0 str_trainer2_challange str_trainer2_defeat
    loadpointer 0 str_trainer2_defeat
    callstd MSG_FACE
    end
ow_script_forest_cemetery_trainer_3:
    trainerbattlestd 0 0xed 0 str_trainer3_challange str_trainer3_defeat
    loadpointer 0 str_trainer3_defeat
    callstd MSG_FACE
    end
ow_script_forest_cemetery_trainer_4:
    trainerbattlestd 0 0xee 0 str_trainer4_challange str_trainer4_defeat
    loadpointer 0 str_trainer4_defeat
    callstd MSG_FACE
    end
ow_script_forest_cemetery_trainer_5:
    trainerbattlestd 0 0xef 0 str_trainer5_challange str_trainer5_defeat
    loadpointer 0 str_trainer5_defeat
    callstd MSG_FACE
    end
ow_script_forest_cemetery_trainer_6:
    trainerbattlestd 0 0xf0 0 str_trainer6_challange str_trainer6_defeat
    loadpointer 0 str_trainer6_defeat
    callstd MSG_FACE
    end
ow_script_forest_cemetery_trainer_7:
    trainerbattlestd 0 0xf1 0 str_trainer7_challange str_trainer7_defeat
    loadpointer 0 str_trainer7_defeat
    callstd MSG_FACE
    end
ow_script_forest_cemetery_trainer_8:
    trainerbattlestd 0 0xf2 0 str_trainer8_challange str_trainer8_defeat
    loadpointer 0 str_trainer8_defeat
    callstd MSG_FACE
    end


.ifdef LANG_GER
str_trainer0_challange:
    .autostring 34 2 "Die Geister der Erde finden hier ihre Ruhe.\pFür eine Hexe ist dieser Ort das Paradies."
str_trainer0_defeat:
    .autostring 34 2 "Übernimm dich nicht, Kind.\pEin Ruhepol im Herzen kann deinen Geist befreien."
str_trainer1_challange:
    .autostring 34 2 "Käfer-Pokémon sind faszinierend.\pSowohl im Schwarm als auch alleine ähneln sie uns Menschen ungemein."
str_trainer1_defeat:
    .autostring 34 2 "Ich muss noch einiges von den Käfer-Pokémon lernen."
str_trainer2_challange:
    .autostring 34 2 "In jedem Geist steckt Bosheit.\pIch werde dir deine austreiben!"
str_trainer2_defeat:
    .autostring 34 2 "Du hast Glück, deine Seele ist nun wieder rein."
str_trainer3_challange:
    .autostring 34 2 "Ein gestandener Trainer muss seine Furcht in den Griff kriegen.\pDeshalb trainiere ich hier bereits seit einiger Zeit!"
str_trainer3_defeat:
    .autostring 34 2 "Ein kurzer Moment des Zögerns, ein Augenblick der Angst.\pDas war bereits zu vielDOTS"
str_trainer4_challange:
    .autostring 34 2 "Ich kann die Geister, die dich auf deinem Weg begleiten, sehen.\pAber im Kampf werden sie dir nichts nützen."
str_trainer4_defeat:
    .autostring 34 2 "Deine Kraft gründet aus weitaus mehr, als den Geister um dich."
str_trainer5_challange:
    .autostring 34 2 "Manche nennen mich das Orakel, denn ich kann die Zukunft sehen.\pUnd für dich zeigt mein drittes Auge mir eine Niederlage!"
str_trainer5_defeat:
    .autostring 34 2 "Ich irre mich nicht.\pDeine Niederlage steht dir erst noch bevor."
str_trainer6_challange:
    .autostring 34 2 "Nur derjenige, der die Finsternis mit offenem Herzen empfängt, kann so mächtig werden, wie Königin der Nacht."
str_trainer6_defeat:
    .autostring 34 2 "Offenbar bin ich noch nicht im Stande, mich den Schatten völlig hinzugebenDOTS"
str_trainer7_challange:
    .autostring 34 2 "Rin ist eine unfassbar willenstarke Frau.\pSie wird immer erreichen, was sie sich vornimmt."
str_trainer7_defeat:
    .autostring 34 2 "Bist du das Kind, dass sich ihr schon einmal in den Weg gestellt hat?"
str_trainer8_challange:
    .autostring 34 2 "Die Arbeit in Team Violet ist immer interessant und abwechslungsreich.\pWas wir nun im Schilde führen?\pWieso sollte ich dir das erzählen?"
str_trainer8_defeat:
    .autostring 34 2 "Ich verrate es dir!\pWir sind auf der Suche nach einer versunkenen Stadt!"
.elseif LANG_EN
str_trainer0_challange:
    .autostring 34 2 "The ghosts of all earth find rest in this place.\pHere is a witch's paradise."
str_trainer0_defeat:
    .autostring 34 2 "Don't overdo it, kid.\pA place of rest in your heart can free your soul."
str_trainer1_challange:
    .autostring 34 2 "Bug Pokémon are fascinating.\pNo matter if in a swarm or alone they are much alike us humans."
str_trainer1_defeat:
    .autostring 34 2 "I still have to learn much from Bug Pokémon."
str_trainer2_challange:
    .autostring 34 2 "In every mind there is wickedness.\nI will rid you of yours."
str_trainer2_defeat:
    .autostring 34 2 "You are lucky.\pYour soul has been purged."
str_trainer3_challange:
    .autostring 34 2 "A seasoned trainer has to master his own fear.\pThat's why I am training here for some time!"
str_trainer3_defeat:
    .autostring 34 2 "A brief moment of hesitation, a glimpse of fear.\pThat already was too muchDOTS"
str_trainer4_challange:
    .autostring 34 2 "I can see the spirits accompanying you on your journey.\pBut they won't help you in this battle."
str_trainer4_defeat:
    .autostring 34 2 "Your power comes from much more than just the spirits arround you."
str_trainer5_challange:
    .autostring 34 2 "Some call me the oracle, because I can see into the future.\pAnd your's is painted by the color of defeat."
str_trainer5_defeat:
    .autostring 34 2 "I am never wrong.\pYour defeat definitely is coming."
str_trainer6_challange:
    .autostring 34 2 "Only those who can embrace the darkness with their entire heart can be as powerful as the Queen of the Night."
str_trainer6_defeat:
    .autostring 34 2 "Appearently I am not yet ready to give myself into the darkness entirelyDOTS"
str_trainer7_challange:
    .autostring 34 2 "Rin is a woman of imense willpower.\pShe will always achieve what she desires."
str_trainer7_defeat:
    .autostring 34 2 "Are you the brat who was in her way that time before?"
str_trainer8_challange:
    .autostring 34 2 "The work for Team Violet always is exciting.\pWhat we are up to now?\pWhy would I tell you?"
str_trainer8_defeat:
    .autostring 34 2 "Fine, I will tell you!\pWe are looking for a sunken city!"
.endif
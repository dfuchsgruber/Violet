.include "overworld_script.s"
.include "callstds.s"


.global ow_script_route_2_clouds_trainer_2
.global ow_script_route_2_clouds_trainer_3
.global ow_script_route_2_clouds_trainer_4
.global ow_script_route_2_clouds_trainer_5
.global ow_script_route_2_clouds_trainer_6
.global ow_script_route_2_clouds_trainer_7
.global ow_script_route_2_clouds_trainer_8
.global ow_script_route_2_clouds_trainer_9

ow_script_route_2_clouds_trainer_2:
    trainerbattlestd 0 0x113 0 str_trainer2_challange str_trainer2_defeat
    loadpointer 0 str_later_2
    callstd MSG_FACE
    end
ow_script_route_2_clouds_trainer_3:
    trainerbattlestd 0 0x114 0 str_trainer3_challange str_trainer3_defeat
    loadpointer 0 str_later_3
    callstd MSG_FACE
    end
ow_script_route_2_clouds_trainer_4:
    trainerbattlestd 0 0x115 0 str_trainer4_challange str_trainer4_defeat
    loadpointer 0 str_later_4
    callstd MSG_FACE
    end
ow_script_route_2_clouds_trainer_5:
    trainerbattlestd 0 0x1f2 0 str_before_5 str_after_5
    loadpointer 0 str_later_5
    callstd MSG_FACE
    end
ow_script_route_2_clouds_trainer_6:
    trainerbattlestd 0 0x1f3 0 str_before_6 str_after_6
    loadpointer 0 str_later_6
    callstd MSG_FACE
    end
ow_script_route_2_clouds_trainer_7:
    trainerbattlestd 0 0x1f4 0 str_before_7 str_after_7
    loadpointer 0 str_later_7
    callstd MSG_FACE
    end
ow_script_route_2_clouds_trainer_8:
    trainerbattlestd 0 0x1f5 0 str_before_8 str_after_8
    loadpointer 0 str_later_8
    callstd MSG_FACE
    end
ow_script_route_2_clouds_trainer_9:
    trainerbattlestd 0 0x1f6 0 str_before_9 str_after_9
    loadpointer 0 str_later_9
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_trainer2_challange:
    .autostring 34 2 "Wenn heute der Himmel auf die Welt herabfälltDOTS\pDOTSich habe den Faden verloren!"
str_trainer2_defeat:
    .autostring 34 2 "DOTSIch kann mich einfach nicht erinnern, was ich zu sagen hatteDOTS"
str_later_2:
    .autostring 34 2 "Wenn heute der Faden auf dem Himmel fälltDOTS\pMomentDOTS\nDu bringst mich ganz durcheinander!"
str_trainer3_challange:
    .autostring 34 2 "Das Wolkenvolk existiert seit Jahrhunderten.\pIch zeige dir, wie diese Menschen gekämpft haben!"
str_trainer3_defeat:
    .autostring 34 2 "Du bist sicherlich würdig, in solchen Höhen umherzustreifen, Kindchen!"
str_later_3:
    .autostring 34 2 "Du scheinst ein Naturtalent zu sein, über den Wolken zu kämpfen.\pWer hat dir das beigebracht?"
str_trainer4_challange:
    .autostring 34 2 "Wo könnte man besser Vögel fangen, als über den Wolken?"
str_trainer4_defeat:
    .autostring 34 2 "Hast du größere Vögel gefangen als ich?"
str_later_4:
    .autostring 34 2 "Ich habe hier oben schon so manchen großen Vogel eingefangen.\pAber dir machen sie keine KonkurrenzDOTS"
str_before_5:
    .autostring 34 2 "Hier tummeln sich die Vogelfänger nur.\pAber ich bin sicherlich der Beste unter allen!"
str_after_5:
    .autostring 34 2 "Hiervon erzählst du aber nicht den anderen Vogelfängern, oder?"
str_later_5:
    .autostring 34 2 "Dass ich gegen dich verloren habe, sagt gar nichts!\pImmerhin hast du ja auch gegen die anderen Vogelfänger hier oben keine Niederlage einstecken müssen, oder?"
str_before_6:
    .autostring 34 2 "Es ist selten, dass sich ein Angler hierher verirrt.\pUmso besser ist folglich meine Ausbeute!"
str_after_6:
    .autostring 34 2 "UffDOTS\nDas hatte ich mir doch anders vorgestelltDOTS"
str_later_6:
    .autostring 34 2 "Die Pokémon in diesem Teich sammeln sich um einen großen Kristall in der MitteDOTS\pVielleicht sollte ich dort angelnDOTS"
str_before_7:
    .autostring 34 2 "Ich verrate dir ein Geheimnis!\pIch bin nicht auf einer Wolke hierher gekommen, sondern habe meine telekinetischen Fähigkeiten benutzt, um zu schweben!"
str_after_7:
    .autostring 34 2 "A-Auszeit!\pIch muss mich neu sammelnDOTS"
str_later_7:
    .autostring 34 2 "Na gut, ich habe dich angeflunkert.\pIch bin bei einem Wolkenreiter mitgeflogen, um hierzu kommen.\pJetzt hoffe ich, dass mich bald auch einer wieder herunter bringtDOTS"
str_before_8:
    .autostring 34 2 "Alle Berge der Region zu erklimmen ist das Ziel der meisten Wanderer.\pIch werde der erste sein, der diese Himmels-Inseln bestiegen hat!"
str_after_8:
    .autostring 34 2 "Vielleicht sollte ich mir eine Pause gönnen.\pImmerhin ist mir ja niemand auf dem FersenDOTS"
str_later_8:
    .autostring 34 2 "Ich bin ganz schön erschöpft.\pAber ich habe Angst, dass, wenn ich raste, ein anderer zuerst alle Gipfel hier oben erklimmt!"
str_before_9:
    .autostring 34 2 "Die Natur hier oben hat einen ganz eigenen Charakter.\pIn so einer Umgebung kann ich nicht verlieren!"
str_after_9:
    .autostring 34 2 "Was?\nWie konnte ich trotz dieser prächtigen Natur besiegt werden?"
str_later_9:
    .autostring 34 2 "Es scheint, dass ich mich von der Schönheit dieser Natur zu sehr ablenken habe lassen.\pBeim nächsten Mal wird mir das nicht passieren!"
.elseif LANG_EN
str_trainer2_challange:
    .autostring 34 2 "If today the sky would fall down\pDOTSnow I lost itDOTS"
str_trainer2_defeat:
    .autostring 34 2 "DOTSI just can't remember what I wanted to sayDOTS"
str_trainer3_challange:
    .autostring 34 2 "The people of the clouds have been existing for hundreds of years.\pI show you, how they fought!"
str_trainer3_defeat:
    .autostring 34 2 "You certainly are worthy to wander these heights, kid!"
str_trainer4_challange:
    .autostring 34 2 "Where to catch larger birds than above the clouds?"
str_trainer4_defeat:
    .autostring 34 2 "Did you catch larger birds than me?"
.endif
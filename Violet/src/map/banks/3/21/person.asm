.include "vars.s"
.include "movements.s"
.include "callstds.s"
.include "mugshot.s"
.include "ordinals.s"
.include "overworld_script.s"

.global ow_script_map_3_21_trainer_1
.global ow_script_map_3_21_trainer_2
.global ow_script_map_3_21_trainer_8
.global ow_script_map_3_21_person_2
.global ow_script_map_3_21_trainer_15
.global ow_script_0x90fdce
.global ow_script_map_3_21_trainer_6
.global ow_script_map_3_21_trainer_12
.global ow_script_map_3_21_trainer_11
.global ow_script_map_3_21_trainer_13
.global ow_script_map_3_21_trainer_5
.global ow_script_map_3_21_person_0
.global ow_script_map_3_21_trainer_0
.global ow_script_map_3_21_trainer_9
.global ow_script_map_3_21_trainer_10
.global ow_script_0x73ced1
.global ow_script_map_3_21_trainer_7
.global ow_script_0x8ffe63
.global ow_script_map_3_21_trainer_4
.global ow_script_map_3_21_trainer_14
.global ow_script_map_3_21_trainer_3
.global ow_script_map_3_21_person_1

ow_script_map_3_21_trainer_10:
    trainerbattlestd 0x0 0x66 0x0 str_0x72458c str_0x7245ea
    loadpointer 0x0 str_0x7245ea
    callstd MSG_FACE
    end


.ifdef LANG_GER
str_0x72458c:
    .autostring 34 2 "Ich habe so einen DurstDOTS\pHast du etwas zu trinken für mich?"
str_0x7245ea:
    .autostring 34 2 "W-Wo ist denn hier etwas WasserDOTS"
.elseif LANG_EN
.endif


ow_script_map_3_21_trainer_0:
    trainerbattlestd 0x0 0x61 0x0 str_0x8ede71 str_0x8edee6
    loadpointer 0x0 str_0x8edee6
    callstd MSG_FACE
    end


.ifdef LANG_GER
str_0x8ede71:
    .autostring 34 2 "Das hier muss der trockenste Ort der ganzen Region sein!\pPass auf, dass du nicht auch vertrocknest!"
str_0x8edee6:
    .autostring 34 2 "UffDOTS\pWoher hast du die ganze Kraft in so einer Hitze?"
.elseif LANG_EN

.endif


ow_script_map_3_21_trainer_2:
    trainerbattlestd 0x0 0x60 0x0 str_0x743970 str_0x8ede0e
    loadpointer 0x0 str_0x8ede0e
    callstd MSG_FACE
    end


.ifdef LANG_GER
str_0x743970:
    .autostring 34 2 "Ich verrate dir einmal etwas!\pIch habe mich gerade an einem Brunnen erfrischt!\pDu kannst mich gar nicht schlagen!"
str_0x8ede0e:
    .autostring 34 2 "Vielleicht habe ich mir diesen Brunnen doch nur eingebildetDOTS"
.elseif LANG_EN

.endif


ow_script_map_3_21_trainer_11:
    trainerbattlestd 0x0 0x63 0x0 str_0x73cdd2 str_0x73ce20
    loadpointer 0x0 str_0x73ce20
    callstd MSG_FACE
    end


.ifdef LANG_GER

str_0x73cdd2:
    .autostring 34 2 "Hier gibt es nicht außer KakteenDOTS\pDiese Wüste ist so öde!\pWie wäre es mit einem Kampf?"
str_0x73ce20:
    .autostring 34 2 "Ich glaube, ich breche hier noch zusammenDOTS"
.elseif LANG_EN
.endif


ow_script_0x73ced1:
    trainerbattlestd 0x0 0x1c7 0x0 str_0x743d3a str_0x743d7f
    loadpointer 0x0 str_0x743d7f
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0x743d3a:
    .autostring 34 2 "Du fragst dich sicher, was eine Exorizistin wie ich in dieser Wüste verloren hat?\pNunDOTS\pDas wüsste ich auch gerne!"
str_0x743d7f:
    .autostring 34 2 "UffDOTS\pDu hast mir den Kampfgeist ausgetrieben."
.elseif LANG_EN
.endif

ow_script_map_3_21_trainer_3:
    trainerbattlestd 0x0 0x68 0x0 str_0x744635 str_0x7446c2
    loadpointer 0x0 str_0x7446c2
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0x744635:
    .autostring 34 2 "Diese goldenen Kakteen sind tückisch.\pMich hat ein Pokémon angegriffen, als ich dem Kaktus zu Nahe gekommen bin.\pJetzt werde ich es gegen dich einsetzen!"
str_0x7446c2:
    .autostring 34 2 "Autsch!\nPass doch auf, dieses Pokémon piekst!"
.elseif LANG_EN
.endif

ow_script_map_3_21_trainer_5:
    trainerbattlestd 0x0 0x5f 0x0 str_0x74476a str_0x7453a9
    loadpointer 0x0 str_0x7453a9
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0x74476a:
    .autostring 34 2 "Das ist kein Ort für ein Mädchen, haben sie mir gesagt!\pDenen werde ich es zeigen!"
str_0x7453a9:
    .autostring 34 2 "Auszeit!\nIch habe Sand in meinen SchuhenDOTS\pDas krazt ganz übelDOTS"
.elseif LANG_EN

.endif


ow_script_map_3_21_trainer_8:
    trainerbattlestd 0x0 0x62 0x0 str_0x81fc71 str_0x8ffccf
    loadpointer 0x0 str_0x8ffccf
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0x81fc71:
    .autostring 34 2 "Ein Picknick in der Wüste!\pKannst du dir etwas Besseres vorstellen?"
str_0x8ffccf:
    .autostring 34 2 "Na gut, vielleicht ist ein Wüstenpicknick nicht mein bester Einfall gewesenDOTS"
.elseif LANG_EN

.endif


ow_script_map_3_21_trainer_6:
    trainerbattlestd 0x0 0x67 0x0 str_0x81fb0d str_0x81fb69
    loadpointer 0x0 str_0x81fb69
    callstd MSG_FACE
    end


.ifdef LANG_GER
str_0x81fb0d:
    .autostring 34 2 "M-Mir ist so schwindlig!\pIch habe seit Stunden keinen Tropfen Wasser mehr getrunkenDOTS\pH-Hast du etwas gegen meinen Durst?"
str_0x81fb69:
    .autostring 34 2 "O-OhDOTS\nS-So durstigDOTS"
.elseif LANG_EN

.endif


ow_script_map_3_21_person_1:
    loadpointer 0x0 str_0x81fc05
    callstd MSG_FACE
    end


.ifdef LANG_GER

str_0x81fc05:
    .autostring 34 2 "Ich weiß nicht, was mich geritten hat, in diese Wüste zu kommen.\pAus irgendeinem Grund habe ich mir eingebildet, das schaffen zu können.\pAber diese Hitze setzt einem Mann in meinem Alter ganz schön zuDOTS"
.elseif LANG_EN

.endif


ow_script_map_3_21_person_2:
loadpointer 0x0 str_0x86c9f0
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x86c9f0:
    .autostring 34 2 "Diese Wüste ist voller Tücken.\pDie eigenen Augen spielen einem hier Streiche.\pMan denkt, einen Brunnen entdeckt zu habenDOTS\pUnd dann muss man feststellen, dass es bloß eine Fata Morgana war."
.elseif LANG_EN

.endif


ow_script_map_3_21_trainer_1:
loadpointer 0x0 str_0x8ffd29
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8ffd29:
    .autostring 34 2 "Obwohl es nun doch schon einige Jahre zurückliegt, erinnern sich noch viele Trainer an die Gründung der Pokémon-Liga.\pDrei talentierte junge Trainer, die sich in den Kopf gesetzt hatten, diese Region zu erobern.\pHeute allerdingsDOTS\pNun, bloß einer von ihnen ist noch Teil der Pokémon-Liga.\pDu hast vielleicht schon vom Rosa Faun gehört?"

.elseif LANG_EN

.endif


ow_script_map_3_21_trainer_13:
loadpointer 0x0 str_0x86c1ad
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x86c1ad:
    .autostring 34 2 "Nach all den Strapazen und falschen BrunnenDOTS\pEndlich habe ich einen echten Wasserbrunnen gefunden!"

.elseif LANG_EN

.endif


ow_script_map_3_21_trainer_7:
trainerbattlestd 0x0 0x65 0x0 str_0x90ff68 str_0x91ff1b
loadpointer 0x0 str_0x91ff1b
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x90ff68:
    .autostring 34 2 "In dieser Wüste soll sich das Grabmal eines antiken Pokémon befinden.\pWenn ich diese Grotte finde, werde ich mir das Pokémon unter den Nagel reißen!"
str_0x91ff1b:
    .autostring 34 2 "Na, du magst vielleicht gewonnen haben.\pAber das antike Pokémon wird jemand wie du ganz sicher nicht finden!"
.elseif LANG_EN
.endif

ow_script_map_3_21_trainer_12:
    loadpointer 0x0 str_0x91ff57
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0x91ff57:
    .autostring 34 2 "Der Weg von Kranzdorf nach Kaskada ist wirklich eine Kraftprobe.\pErst quält man sich durch eine finstere Höhle, dann schleppt man sich durch eine Wüste.\pUnd alles nur, um sich dann wieder vor einem Höhleneingang zu finden."
.elseif LANG_EN
.endif


ow_script_map_3_21_trainer_9:
    loadpointer 0x0 str_0x86ca74
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0x86ca74:
    .autostring 34 2 "I-Immer wenn ich mich diesem Brunnen nähereDOTS\pVerschwindet er vor meinen Augen!\pWas für eine Frechheit!"
.elseif LANG_EN
.endif


ow_script_map_3_21_trainer_14:
    trainerbattlestd 0x0 0x69 0x0 str_0x922d48 str_0x926a50
    loadpointer 0x0 str_0x926a50
    callstd MSG_FACE
    end


.ifdef LANG_GER
str_0x922d48:
    .autostring 34 2 "Eine Fata Morgana kann mir nichts anhaben.\pIch habe meinen Geist jahrelang trainiert!\pAlso zeig mir, was du gegen die Tücken dieser Wüste ausrichten kannst!"
str_0x926a50:
    .autostring 34 2 "Denk' ja nicht, dass ich wegen eines verwirrten Geistes verloren hätteDOTS"
.elseif LANG_EN

.endif


ow_script_map_3_21_trainer_15:
loadpointer 0x0 str_0x926aaa
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x926aaa:
    .autostring 34 2 "Ist es nicht wirklich herausragend, dass einige Pokémon in einer so lebensfeindlichen Region überleben können?"
.elseif LANG_EN

.endif


ow_script_map_3_21_trainer_4:
    trainerbattlestd 0x0 0x6a 0x0 str_0x926c12 str_0x926c67
    loadpointer 0x0 str_0x926c67
    callstd MSG_FACE
    end


.ifdef LANG_GER

str_0x926c12:
    .autostring 34 2 "Man muss hier auf jeden seiner Schritte aufpassen.\pIm Sand verstecken sich die tückischsten Pokémon.\pUnd in gewisser Weise bist auch du mir direkt in die Falle gegangen!"
str_0x926c67:
    .autostring 34 2 "N-Na gut, du hast dich aus meiner Falle befreit, was?"
.elseif LANG_EN

.endif


ow_script_movs_0x91fece:
.byte SAY_EXCLAM
.byte STOP


ow_script_map_3_21_person_0:
    end
/*
loadpointer 0 str_violet
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x91fed1
callstd MSG
special 0xF
lock
sound 0x15
applymovement 0x800f ow_script_movs_0x91fece
waitmovement 0x0
faceplayer

loadpointer 0 str_violet
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x91fcc4
callstd MSG
special 0xF
setvar DYN_MULTICHOICE_ITEM_CNT 0x2
loadpointer 0x0 choice
multichoice 0x0 0x0 0x0 0x1
setvar DYN_MULTICHOICE_ITEM_CNT 0x0
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x90fdce
loadpointer 0x0 str_0x90fd48
show_mugshot MUGSHOT_PLAYER MUGSHOT_LEFT
loadpointer 0 str_violet
setvar 0x8000 0
special 0xE
trainerbattlecont 0x1 0x64 0x0 str_0x8fff26 str_0x8fff9c ow_script_0x8ffe63

.align 4
choice:
    .word str_violet_grunt_choice_0, 0
    .word str_violet_grunt_choice_1, 0

ow_script_0x8ffe63:
lock
faceplayer
loadpointer 0 str_violet
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x8ffe77
callstd MSG
special 0xF
fadescreen 0x1
hidesprite 0x800f
fadescreen 0x0
release
end


ow_script_0x90fdce:
loadpointer 0x0 str_0x90fe3d
show_mugshot MUGSHOT_PLAYER MUGSHOT_LEFT

loadpointer 0 str_violet
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_0x90fdef
callstd MSG
special 0xF
fadescreen 0x1
hidesprite 0x800f
fadescreen 0x0
end


.ifdef LANG_GER
str_violet:
	.string "Team Violet Rüpel"


str_0x91fed1:
    .autostring 35 2 "DOTS Ich habe wohl den Rest der Division verloren in all der Aufregung DOTS"



str_0x91fcc4:
	.autostring 35 2 "Hey du!\pIch kenne dich aus dem Kranzwald!\pWas willst du denn von mir?\pKannst du denn nicht verstehen, warum ich mich Team Violet angeschlossen habe?\pDavor war ich bloß Teil des Abschaums der Gesellschaft.\pEin niemand!\pAber jetzt bin ich Teil von etwas Großem.\pUnd dafür kämpfe ich mit meinem ganzen Herzen!"


str_violet_grunt_choice_0:
    .string "Rüpel gehen lassen"



str_violet_grunt_choice_1:
    .string "Rüpel bekämpfen"



str_0x90fd48:
	.autostring 35 2 "Nur weil du dich wertlos fühlst, gibt dir das nicht das Recht, Gewalt gegen andere anzuwenden!"



str_0x8fff26:
	.autostring 35 2 "Gegen dich zu kämpfen, bedeutet, Rins großem Ziel von der Herrschaft über Theto einen Schritt näherzukommen!"



str_0x8fff9c:
    .autostring 35 2 "Meine Niederlage DOTS\nDein Sieg DOTS DOTS DOTS\pDas alles hat keine Bedeutung DOTS"



str_0x8ffe77:
	.autostring 35 2 "Am Ende wird es Team Violet sein, das über den Kontinent herrscht.\pUnd dann werde ich endlich meinen Platz in dieser Welt haben!"


str_0x90fe3d:
    .autostring 35 2 "Hör mal DOTS\pIch kann verstehen, dass es nicht einfach ist, seinen Platz in der Welt zu finden DOTS\pAber merkst du nicht, dass du von Team Violet bloß benutzt wirst?\pDu bist für diese Organisation nichts als ein Bauernopfer.\pKomm zur Vernunft!"


str_0x90fdef:
    .autostring 35 2 "DOTS DOTS DOTS\pVielleicht hast du recht.\pIch weiß nicht, woran ich glauben soll DOTS\pIch werde einiges überdenken müssen DOTS DOTS"


.elseif LANG_EN

.endif
*/
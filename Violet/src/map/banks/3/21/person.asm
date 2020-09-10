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
    .string "Soll ich dir ein Geheimnis über\ndiese Wüste verraten? Ich sags dir,\lwenn du mich besiegst!"



str_0x7245ea:
    .string "Gut, das Geheimnis ist, dass es\nhier 2 Brunnen geben soll! Bisher\lhabe ich aber noch keinen\lgefundenDOTS"


.elseif LANG_EN

.endif


ow_script_map_3_21_trainer_0:
trainerbattlestd 0x0 0x61 0x0 str_0x8ede71 str_0x8edee6
loadpointer 0x0 str_0x8edee6
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8ede71:
    .string "Wie kann es hier so trocken sein,\nwährend Kaskada die Stadt der\lWasserquellen genannt wird?"



str_0x8edee6:
    .string "Kaskada und diese Wüste liegen\nnahezu unmittelbar nebeneinander."


.elseif LANG_EN

.endif


ow_script_map_3_21_trainer_2:
trainerbattlestd 0x0 0x60 0x0 str_0x743970 str_0x8ede0e
loadpointer 0x0 str_0x8ede0e
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x743970:
    .string "Ich habe meine Pokémon gerade am\nBrunnen erfrischt! Ich bin so gut\lgestärkt, ich kann nicht verliern!"



str_0x8ede0e:
    .string "Am Brunnen konnte ich meine\nPokémon heilenDOTS\pVielleicht war es aber auch bloß\neine Fata Morgana."


.elseif LANG_EN

.endif


ow_script_map_3_21_trainer_11:
trainerbattlestd 0x0 0x63 0x0 str_0x73cdd2 str_0x73ce20
loadpointer 0x0 str_0x73ce20
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x73cdd2:
    .string "Hier ist das Kaktus Labyrinth! Ich\nwerde den Ausgang in Windeseile\lfinden!"



str_0x73ce20:
    .string "Der AusgangDOTS"


.elseif LANG_EN

.endif


ow_script_0x73ced1:
trainerbattlestd 0x0 0x1c7 0x0 str_0x743d3a str_0x743d7f
loadpointer 0x0 str_0x743d7f
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x743d3a:
    .string "Was eine Exorzistin in der Wüste zu\nsuchen hat? Ich weiß es nicht!"



str_0x743d7f:
    .string "Hinterfrage nie die Gedanken\nunseres Schöfpers!"


.elseif LANG_EN

.endif


ow_script_map_3_21_trainer_3:
trainerbattlestd 0x0 0x68 0x0 str_0x744635 str_0x7446c2
loadpointer 0x0 str_0x7446c2
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x744635:
    .string "Als ich mich in der Nähe eines\ngoldenen Kaktusses aufgehalten\lhabe, hat mich ein Tuska\langefallen.\lIch habe es gefangen!"



str_0x7446c2:
    .string "Mein TuskaDOTS."


.elseif LANG_EN

.endif


ow_script_map_3_21_trainer_5:
trainerbattlestd 0x0 0x5f 0x0 str_0x74476a str_0x7453a9
loadpointer 0x0 str_0x7453a9
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x74476a:
    .string "Meine kleine, rebellische Schwester\nist vor kurzem auch Trainer\lgeworden! DOTS Sie trainiert auf\lRoute 2!"



str_0x7453a9:
    .string "HmpfDOTS Ich dachte, ich hätte eine\nChance!"


.elseif LANG_EN

.endif


ow_script_map_3_21_trainer_8:
trainerbattlestd 0x0 0x62 0x0 str_0x81fc71 str_0x8ffccf
loadpointer 0x0 str_0x8ffccf
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x81fc71:
    .string "Ich hätte mir einen besseren Ort\nfür mein Picknick aussuchen\lkönnen."



str_0x8ffccf:
    .string "Doch wer kann schon von sich\nbehaupten, in der Wüste ein\lPicknick veranstaltet zu haben?"


.elseif LANG_EN

.endif


ow_script_map_3_21_trainer_6:
trainerbattlestd 0x0 0x67 0x0 str_0x81fb0d str_0x81fb69
loadpointer 0x0 str_0x81fb69
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x81fb0d:
    .string "Diese Wüste ist die Hölle, ich hab\nso einen Durst!"



str_0x81fb69:
    .string "WasserDOTS. Wasser!!"


.elseif LANG_EN

.endif


ow_script_map_3_21_person_1:
loadpointer 0x0 str_0x81fc05
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x81fc05:
    .string "Diese Wüste ist nichts für mein\nHerz. Die ständigen Täuschungen\lder Fata Morganas belasten mich zu\lsehrDOTS"


.elseif LANG_EN

.endif


ow_script_map_3_21_person_2:
loadpointer 0x0 str_0x86c9f0
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x86c9f0:
    .string "Ich habe gehört, dass es in dieser\nWüste goldene Kakteen geben soll.\pSchüttelt man an ihnen, so soll\nman Pokémon antreffen können."


.elseif LANG_EN

.endif


ow_script_map_3_21_trainer_1:
loadpointer 0x0 str_0x8ffd29
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8ffd29:
    .string "Vor vielen Jahren herrschte in\ndieser Region ein schrecklicher\lKrieg.\lDrei engagierte Trainer aber\lbezwangen die Unruhen und riefen\ldie Pokémon-Liga und das System\lder Top Vier ins Leben."


.elseif LANG_EN

.endif


ow_script_map_3_21_trainer_13:
loadpointer 0x0 str_0x86c1ad
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x86c1ad:
    .string "An Brunnen wie diesen können\nTrainer ihre erschöpften Pokémon\lheilen."


.elseif LANG_EN

.endif


ow_script_map_3_21_trainer_7:
trainerbattlestd 0x0 0x65 0x0 str_0x90ff68 str_0x91ff1b
loadpointer 0x0 str_0x91ff1b
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x90ff68:
    .string "Ich habe gehört, dass sich\nirgendwo in dieser Wüste das\lGrabmal eines legendären Pokémon\lbefindet. Ob an diesen Geschichten\letwas dran ist?"



str_0x91ff1b:
    .string "Ich würde gerne einemal einem\nlegendären Pokémon begegnen."


.elseif LANG_EN

.endif


ow_script_map_3_21_trainer_12:
loadpointer 0x0 str_0x91ff57
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x91ff57:
    .string "Endlich! Nach tagelanger Suche\nhabe ich den Weg nach Kaskada\lwieder gefunden. Nur zögere ich,\lmich erneut in eine Höhle zu\lbegebenDOTS"


.elseif LANG_EN

.endif


ow_script_map_3_21_trainer_9:
loadpointer 0x0 str_0x86ca74
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x86ca74:
    .string "Verdammt, immer wenn ich dem\nBrunnen zu nahe komme,\lverschwindet er wieder!"


.elseif LANG_EN

.endif


ow_script_map_3_21_trainer_14:
trainerbattlestd 0x0 0x69 0x0 str_0x922d48 str_0x926a50
loadpointer 0x0 str_0x926a50
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x922d48:
    .string "Mit meinen Psychokräften kann ich\ndie Täuschungen der Fata Morganas\lleicht bezwingen!"



str_0x926a50:
    .string "Ich kann Traum von Wirklichkeit\nunterscheiden, aber den Kampf\lkonnte ich nicht gewinnen."


.elseif LANG_EN

.endif


ow_script_map_3_21_trainer_15:
loadpointer 0x0 str_0x926aaa
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x926aaa:
    .string "Interessant sind die goldenen\nKakteen in dieser Wüstenregion. In\lihnen leben manchmal Pokémon."


.elseif LANG_EN

.endif


ow_script_map_3_21_trainer_4:
trainerbattlestd 0x0 0x6a 0x0 str_0x926c12 str_0x926c67
loadpointer 0x0 str_0x926c67
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x926c12:
    .string "Oh, ich verdurste hier noch in\ndieser trockenen Ödnis!"



str_0x926c67:
    .string "Wo, wo ist nur ein Brunnen!"


.elseif LANG_EN

.endif


ow_script_movs_0x91fece:
.byte SAY_EXCLAM
.byte STOP


ow_script_map_3_21_person_0:
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
	.autostring 35 2 "Hey du!\pIch kenne dich aus dem Kranzdorf-Wald!\pWas willst du denn von mir?\pKannst du denn nicht verstehen, warum ich mich Team Violet angeschlossen habe?\pDavor war ich bloß Teil des Abschaums der Gesellschaft.\pEin niemand!\pAber jetzt bin ich Teil von etwas Großem.\pUnd dafür kämpfe ich mit meinem ganzen Herzen!"


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
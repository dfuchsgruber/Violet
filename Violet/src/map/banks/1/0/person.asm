.include "vars.s"
.include "attacks.s"
.include "movements.s"
.include "callstds.s"
.include "ordinals.s"
.include "overworld_script.s"
.include "flags.s"
.include "items.s"
.include "mugshot.s"
.include "species.s"

.global ow_script_silvania_forest_rival_beaten
.global ow_script_silvania_forest_grunt_1
.global ow_script_silvania_forest_grunt_2
.global ow_script_silvania_forest_felix
.global ow_script_silvania_forest_rosalie
.global ow_script_silvania_forest_elise
.global ow_script_silvania_forest_lickitung
.global ow_script_silvania_forest_ludicullo
.global ow_script_map_1_0_trainer_0
.global ow_script_map_1_0_trainer_3
.global ow_script_map_1_0_trainer_12
.global ow_script_map_1_0_trainer_6
.global ow_script_map_1_0_trainer_16
.global ow_script_map_1_0_trainer_18
.global ow_script_map_1_0_trainer_15
.global ow_script_map_1_0_trainer_1
.global ow_script_map_1_0_person_0
.global ow_script_map_1_0_trainer_7
.global ow_script_map_1_0_trainer_19
.global ow_script_map_1_0_trainer_4
.global ow_script_map_1_0_trainer_11
.global ow_script_map_1_0_trainer_13
.global ow_script_map_1_0_trainer_5
.global ow_script_map_1_0_trainer_2
.global ow_script_map_1_0_trainer_10
.global ow_script_map_1_0_trainer_14
.global ow_script_map_1_0_trainer_8
.global ow_script_map_1_0_trainer_9
.global ow_script_map_1_0_trainer_17
.global ow_script_silvania_wald_person_28

ow_script_movs_0x8ecd19:
.byte SAY_EXCLAM
.byte STOP


ow_script_map_1_0_trainer_5:
lock
faceplayer
applymovement 0x800f ow_script_movs_0x8ecd19
waitmovement 0x0
loadpointer 0x0 str_0x8f4305
callstd MSG_KEEPOPEN
copyvarifnotzero 0x8000 ITEM_TM46
copyvarifnotzero 0x8001 1
callstd ITEM_OBTAIN
compare LASTRESULT 0x0
gotoif EQUAL ow_script_no_room_for_giveitem
lock
faceplayer
loadpointer 0x0 str_0x8ef5ca
callstd MSG
fadescreen 0x1
hidesprite 0x800f
fadescreen 0x0
release
end

.ifdef LANG_GER
str_0x8f4305:
    .autostring 34 2 "Du schon wieder!\pHast mich auf Route 2 ganz schön blamiert, als ich Professor Tann hopsnehmen wollteDOTS\pAber der Fehler passiert mir kein zweites Mal.\pNimm das hier und lass mich gefälligst in Ruhe, ja?"
str_0x8ef5ca:
    .autostring 34 2 "Unfassbar, dass ich mich von einem Kind so demütigen lasseDOTS"
.elseif LANG_EN
.endif


ow_script_map_1_0_trainer_18:
loadpointer 0x0 str_0x8ef577
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8ef577:
    .autostring 34 2 "Hier im Kranzwald funkelt alles so schön.\pIch frage mich, woher dieses Glitzern kommt."
.elseif LANG_EN

.endif


ow_script_map_1_0_person_0:
loadpointer 0x0 str_0x8ef678
callstd MSG_FACE
end


.ifdef LANG_GER
str_0x8ef678:
    .autostring 34 2 "Wusstest du, dass es hier einen Schrein geben soll?\pMan hat ihn errichtet, um einem Pokémon zu huldigen, das durch die Zeit reisen kann."
.elseif LANG_EN
.endif


ow_script_map_1_0_trainer_17:
trainerbattlestd 0x0 0x41 0x0 str_0x88ae2e str_0x8e6b0e
loadpointer 0x0 str_0x8e6b0e
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x88ae2e:
    .autostring 34 2 "Ich gehe nicht mehr in die Schule!\pDer Unterricht ist so öde!"
str_0x8e6b0e:
    .autostring 34 2 "Meinst du, ich hätte in der Schule gelernt, wie ich dich besiege?"
.elseif LANG_EN

.endif


ow_script_map_1_0_trainer_14:
trainerbattlestd 0x0 0x42 0x0 str_0x8f2a42 str_0x8f2adf
loadpointer 0x0 str_0x8f2adf
callstd MSG_FACE
end


.ifdef LANG_GER


str_0x8f2a42:
    .autostring 34 2 "Wenn ich etwas nicht gut finde, dann sollte man es verbieten.\pUnd ich dulde keinen Widerspruch!"
str_0x8f2adf:
    .autostring 34 2 "So wie du kämpfstDOTS\pDas sollte verboten werden!"
.elseif LANG_EN

.endif


ow_script_map_1_0_trainer_10:
loadpointer 0x0 str_0x8f2b00
callstd MSG_FACE
end


.ifdef LANG_GER
str_0x8f2b00:
    .autostring 34 2 "Es soll hier ein Pokémon geben, das durch die Zeit reisen kann.\pEs kennt also sowohl die Vergangenheit als auch die Zukunft.\pEs wäre sicher spannend, auch solche Fähigkeiten zu besitzen, nicht?"
.elseif LANG_EN
.endif


ow_script_map_1_0_trainer_12:
loadpointer 0x0 str_0x8f384c
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8f384c:
    .autostring 34 2 "Hast du auch mitbekommen, dass der Champion von einem Kind besiegt worden sein soll?\pIch frage mich, ob dieses Kind jetzt unser neuer Champion istDOTS"
.elseif LANG_EN

.endif


ow_script_map_1_0_trainer_11:
trainerbattlestd 0x0 0x43 0x0 str_0x8ef778 str_0x8ef878
loadpointer 0x0 str_0x8ef878
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8ef778:
    .autostring 34 2 "Käfer-Pokémon sollen schwach sein?\pVon wegen!\nIch werde dir zeigen, welches Potenzial sie haben!"
str_0x8ef878:
    .autostring 34 2 "Das beweist gar nichts!\pKäfer-Pokémon sind sehr stark!"
.elseif LANG_EN

.endif


ow_script_map_1_0_trainer_13:
loadpointer 0x0 str_0x8f38f8
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8f38f8:
    .autostring 34 2 "Hast du von der Revolutionsbewegung gehört?\pSie kleiden sich in grüne Mäntel und kämpfen gegen Korruption und Unterdrückung.\pWenn man bedenkt, wie sich die Welt entwickelt hat, sind das doch gar keine schlechten Ziele, oder?"

.elseif LANG_EN

.endif


ow_script_map_1_0_trainer_19:
loadpointer 0x0 str_0x8ef978
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8ef978:
    .autostring 34 2 "Diese Team Violet Punks werben überall in der Region Mitglieder an.\pDie haben was ganz Großes vor, sag ich dir."
.elseif LANG_EN

.endif


ow_script_map_1_0_trainer_15:
loadpointer 0x0 str_0x8ecc17
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8ecc17:
    .autostring 34 2 "Der Westen von Theto wird vom Pinken Faun regiert.\pEr war auch einer der drei Gründer dieser Regierung.\pJetzt soll er aber auch irgendwo in einer Schule unterrichten, habe ich gehört."
.elseif LANG_EN

.endif


ow_script_map_1_0_trainer_16:
loadpointer 0x0 str_0x8f4254
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8f4254:
    .autostring 34 2 "Der Kranzwald strozt nur so vor Lebenskraft, was?\pAber wenn man weiter westwärts läuft, erreicht man eine staubtrockene Wüste.\pIrrsinnigerweise ist Kaskada, die Stadt der Wasserfälle, nicht weit von dort."
.elseif LANG_EN
.endif


ow_script_map_1_0_trainer_0:
trainerbattlestd 0x0 0x44 0x0 str_0x8f2b8a str_0x8f3993
loadpointer 0x0 str_0x8f3993
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8f2b8a:
    .autostring 34 2 "All die Jahre hat man mich erniedrigt.\pJetzt werde ich es der Welt heimzahlen!\pTeam Violet wird diese Region unterwerfen und du Rotzlöffel kannst nicht dagegen tun!"
str_0x8f3993:
    .autostring 34 2 "Dein Sieg bedeutet gar nichts.\pWenn wir unser Ziel erst erreicht haben, kann uns keiner mehr aufhalten."
.elseif LANG_EN

.endif


ow_script_map_1_0_trainer_1:
trainerbattlestd 0x0 0x45 0x0 str_0x8efa78 str_0x8efb78
loadpointer 0x0 str_0x8efb78
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8efa78:
    .autostring 34 2 "Seit der ehemalige Champion gestürzt wurde, schafft es die Polizei nicht mehr, für Recht und Ordnung zu sorgen.\pDa kommen wir Ranger ins Spiel!"
str_0x8efb78:
    .autostring 34 2 "Du bist stark!\pWillst du nicht auch ein Ranger werden?"

.elseif LANG_EN

.endif


ow_script_map_1_0_trainer_3:
trainerbattlestd 0x0 0x46 0x0 str_0x8efc78 str_0x8f0916
loadpointer 0x0 str_0x8f0916
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8efc78:
    .autostring 34 2 "He, du!\pDu kannst hier nicht durch!\pUnsere Kommandantin hat hier etwas Wichtiges zu erledigen!"
str_0x8f0916:
    .autostring 34 2 "Mach dich auf was gefasst!\pUnserer Kommandantin bist du lange nicht gewachsen!"

.elseif LANG_EN

.endif


ow_script_map_1_0_trainer_2:
trainerbattlestd 0x0 0x47 0x0 str_0x8f4388 str_0x8f43ce
loadpointer 0x0 str_0x8f43ce
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8f4388:
    .autostring 34 2 "Ich habe meine Flug-Pokémon hier lange trainiert!\pWir machen kurzen Prozess mit allen Käfer- und Pflanzen-Pokémon!"

str_0x8f43ce:
    .autostring 34 2 "Uff\nFür solche Gegner sind meine Pokémon nicht stark genugDOTS"


.elseif LANG_EN

.endif


ow_script_map_1_0_trainer_9:
loadpointer 0x0 str_0x8f4419
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8f4419:
    .autostring 34 2 "In diesem Wald hat man das Gefühl, dass die Zeit langsamer vergeht.\pWenn man meint, hier bloß einige Stunden verbracht zu haben, ist draußen bereits der ganze Tag vorbei.\pIch frage mich, ob das bloß Einbildung istDOTS"
.elseif LANG_EN
.endif


ow_script_map_1_0_trainer_6:
trainerbattlestd 0x0 0x48 0x0 str_0x8f448d str_0x8f4519
loadpointer 0x0 str_0x8f4519
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8f448d:
    .autostring 34 2 "Du hältst mich wohl für einen Rowdy, was?\pAber eines Tages werden wir die Kontrolle über diese Region haben.\pUnd dann sehen wir ja, wer die Gesetzlosen sind!"
str_0x8f4519:
    .autostring 34 2 "Nenn mich ruhig einen Schurken!\pWenn wir unser Ziel erreichen, werden wir die Helden sein und du bist der Verbrecher, Kindchen!"
.elseif LANG_EN

.endif


ow_script_map_1_0_trainer_4:
loadpointer 0x0 str_0x8f455c
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8f455c:
    .autostring 34 2 "Ich suche hier nach dem Pokémon Knilz.\pMan Vater liebt dieses Pokémon und ich will ihm eines zeigen!"
.elseif LANG_EN

.endif


ow_script_map_1_0_trainer_7:
loadpointer 0x0 str_0x8f45a3
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8f45a3:
    .autostring 34 2 "Warst du schon in Laubkind-Dorf?\pDort gibt es eine Pokémon-Pension.\pDie Leute da sind so nett!"

.elseif LANG_EN

.endif


ow_script_map_1_0_trainer_8:
trainerbattlestd 0x0 0x49 0x0 str_0x8ef8b7 str_0x8efbc3
loadpointer 0x0 str_0x8efbc3
callstd MSG_FACE
end


.ifdef LANG_GER

str_0x8ef8b7:
    .autostring 34 2 "Unser Projekt wird Team Violet zur mächtigsten Gruppe der Welt machen.\pDa lasse ich ein Kind doch nicht unsere Pläne durchkreuzen!"
str_0x8efbc3:
    .autostring 34 2 "Meine Niederlage macht auch keinen Unterschied mehrDOTS\pDu kannst uns nicht aufhalten!"


.elseif LANG_EN

.endif



ow_script_silvania_wald_person_28:
    loadpointer 0 str_0
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Mir kommt es immer wieder vor, als würde die Zeit hier im Wald stillstehenDOTS"

.elseif LANG_EN
str_0:
    .autostring 34 2 "From time to time I feel like the time in this forest would stand stillDOTS"
.endif

ow_script_silvania_forest_felix:
    loadpointer 0 str_felix
    show_mugshot MUGSHOT_FELIX MUGSHOT_RIGHT message_type=MSG_FACE
    applymovement LASTTALKED mov_fu
    waitmovement 0
    end
ow_script_silvania_forest_rosalie:
    loadpointer 0 str_rosalie
    show_mugshot MUGSHOT_ROSALIE MUGSHOT_RIGHT message_type=MSG_FACE emotion=MUGSHOT_SAD
    applymovement LASTTALKED mov_fu
    waitmovement 0
    end
ow_script_silvania_forest_elise:
    loadpointer 0 str_elise
    show_mugshot MUGSHOT_ELISE MUGSHOT_RIGHT message_type=MSG_FACE emotion=MUGSHOT_SAD
    end
ow_script_silvania_forest_ludicullo:
    bufferpokemon 0 POKEMON_KAPPALORES
ow_script_extinguish:
    loadpointer 0 str_extinguish
    callstd MSG
    end
ow_script_silvania_forest_lickitung:
    bufferpokemon 0 POKEMON_SCHLURP
    goto ow_script_extinguish

ow_script_silvania_forest_grunt_1:
    trainerbattlestd 0x0 0x4a 0x0 str_grunt_before_1 str_grunt_after_1
    loadpointer 0x0 str_grunt_after_1
    callstd MSG_FACE
    end

ow_script_silvania_forest_grunt_2:
    trainerbattlestd 0x0 0x4b 0x0 str_grunt_before_2 str_grunt_after_2
    loadpointer 0x0 str_grunt_after_2
    callstd MSG_FACE
    end

ow_script_silvania_forest_rival_beaten:
    loadpointer 0 str_rival_beaten
    show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT message_type=MSG_FACE emotion=MUGSHOT_BEATEN
    end


.ifdef LANG_GER
str_felix:
    .autostring 34 2 "PLAYER!\pBeeil dich und hilf RIVAL dabei, diese Kommandantin aufzuhalten.\pRosalie und ich halten das Feuer in Schach!"
str_rosalie:
    .autostring 34 2 "Mein schöner Wald!\pIch darf nicht zulassen, dass er niederbrennt!"
str_elise:
    .autostring 34 2 "Ich habe solche Angst um meinen Vater!\pWas diese Frau ihm alles antun könnteDOTS"
str_extinguish:
    .autostring 34 2 "Das BUFFER_1 benutzt Aquawelle, um die Flammen zu löschen."
str_grunt_before_1:
    .autostring 34 2 "Schon immer haben Leute wie wir den Kürzeren gezogen.\pAber jetzt wehren wir uns endlich!"
str_grunt_after_1:
    .autostring 34 2 "Deine Überheblichkeit kannst du dir sparen!\pDein dämliches Grinsen wird dir schon noch vergehen!"
str_grunt_before_2:
    .autostring 34 2 "Wenn unser Plan aufgeht, liegt uns die Region ruckzuck zu Füßen.\pDa lasse ich dich nicht dazwischen funken!"
str_grunt_after_2:
    .autostring 34 2 "Wenigstens konnte ich ein wenig Zeit kaufenDOTS"
str_rival_beaten:
    .autostring 34 2 "DOTS DOTS DOTS\nDOTS DOTS DOTS"
.elseif LANG_EN
.endif
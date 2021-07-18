.include "overworld_script.s"
.include "callstds.s"

.global ow_script_route_6_trainer_0
.global ow_script_route_6_couple
.global ow_script_route_6_trainer_2
.global ow_script_route_6_trainer_3
.global ow_script_route_6_trainer_4
.global ow_script_route_6_trainer_5
.global ow_script_route_6_trainer_6
.global ow_script_route_6_trainer_7
.global ow_script_route_6_trainer_8
.global ow_script_route_6_trainer_9
.global ow_script_route_6_trainer_10
.global ow_script_route_6_trainer_11

ow_script_route_6_trainer_0:
    trainerbattlestd 0 0x16e 0 str_before0 str_after0
    loadpointer 0 str_later_0
    callstd MSG_FACE
    end

ow_script_route_6_couple:
    trainerbattledouble 4 0x16f 0 str_before1 str_after1 str_cant_battle1
    loadpointer 0 str_later_1
    callstd MSG_FACE
    end

ow_script_route_6_trainer_2:
    trainerbattlestd 0x0 0x94 0x0 str_before_2 str_after_2
    loadpointer 0x0 str_later_2
    callstd MSG_FACE
    end

ow_script_route_6_trainer_3:
    trainerbattlestd 0x0 0x95 0x0 str_before_3 str_after_3
    loadpointer 0x0 str_later_3
    callstd MSG_FACE
    end

ow_script_route_6_trainer_4:
    trainerbattlestd 0x0 0x96 0x0 str_before_4 str_after_4
    loadpointer 0x0 str_later_4
    callstd MSG_FACE
    end

ow_script_route_6_trainer_5:
    trainerbattlestd 0x0 0x97 0x0 str_before_5 str_after_5
    loadpointer 0x0 str_later_5
    callstd MSG_FACE
    end

ow_script_route_6_trainer_6:
    trainerbattlestd 0x0 0x98 0x0 str_before_6 str_after_6
    loadpointer 0x0 str_later_6
    callstd MSG_FACE
    end

ow_script_route_6_trainer_7:
    trainerbattlestd 0x0 0x9f 0x0 str_before_7 str_after_7
    loadpointer 0x0 str_later_7
    callstd MSG_FACE
    end

ow_script_route_6_trainer_8:
    trainerbattlestd 0x0 0xa0 0x0 str_before_8 str_after_8
    loadpointer 0x0 str_later_8
    callstd MSG_FACE
    end

ow_script_route_6_trainer_9:
    trainerbattlestd 0x0 0xa1 0x0 str_before_9 str_after_9
    loadpointer 0x0 str_later_9
    callstd MSG_FACE
    end

ow_script_route_6_trainer_10:
    trainerbattlestd 0x0 0xa2 0x0 str_before_10 str_after_10
    loadpointer 0x0 str_later_10
    callstd MSG_FACE
    end

ow_script_route_6_trainer_11:
    trainerbattlestd 0x0 0x93 0x0 str_before_11 str_after_11
    loadpointer 0x0 str_later_11
    callstd MSG_FACE
    end


.ifdef LANG_GER
str_before0:
    .autostring 34 2 "Kampfsport in dieser Hitze fordert den Körper!\pIch bin wie im Fieber!"
str_after0:
    .autostring 34 2 "UffDOTS\pVielleicht brauche ich erst einmal etwas kühles WasserDOTS"
str_before1:
    .autostring 34 2 "Wollen wir gegen diesen Trainer kämpfen, Schatzi?\pNatürlich fordern wir dich heraus!"
str_after1:
    .autostring 34 2 "Wie, Schatzi?\pHaben wir etwa verloren?"
str_cant_battle1:
    .autostring 34 2 "Schatzi und ich kämpfen nur im Doppel!\pWenn du mit uns kämpfen willst, brauchst du zwei kampffähige Pokémon!"
str_later_0:
    .autostring 34 2 "Ein kühles Wasser würde ich jetzt sicherlich nicht verpöhnenDOTS"
str_later_1:
    .autostring 34 2 "A-Aber Schatzi!\pWie konnten wir denn bloß gegen ein Kind verlieren?"
str_before_2:
    .autostring 34 2 "Hier ist es so unfassbar heißDOTS\pAber weißt du, was noch heißer ist?\pDu stehst ihr gegenüber!"
str_after_2:
    .autostring 34 2 "Soll das bedeuten, du findest mich nicht heiß?"
str_later_2:
    .autostring 34 2 "Meine SchönheitDOTS\pSie ist wohl etwas abgekühlt."
str_before_3:
    .autostring 34 2 "Was für eine Idee von mirDOTS\pEin Campingtrip mitten in diesen Vulkangebieten!\pIch könnte austicken!"
str_after_3:
    .autostring 34 2 "Argh!\pIch bin stinksauer!"
str_later_3:
    .autostring 34 2 "Diese Gegend taugt einfach nicht zum Campen!\pÜberall nur Asche und FeuerDOTS"
str_before_4:
    .autostring 34 2 "Ich persönlich finde diesen Ort abscheulich.\pAber meinem Pokémon zu liebe, gehe ich hier mit ihm Spazieren.\pDann musst du eben meine Verägerung ausbaden, Kindchen."
str_after_4:
    .autostring 34 2 "So ein scheußlicher KampfDOTS"
str_later_4:
    .autostring 34 2 "Was ich nicht alles für meinen Pokémon tueDOTS\pEs liebt diesen Ort über alles."
str_before_5:
    .autostring 34 2 "Die Hitze härtet viele Pokémon ab!\pDas ist ein wahrer Geheimtipp, ein hartgesottenes Team an Pokémon aufzustellen!"
str_after_5:
    .autostring 34 2 "Du hast der Kraft der Hitze widerstanden?"
str_later_5:
    .autostring 34 2 "Puh!\nDu wirst selber ganz schön abgehärtet.\pWo hast du trainiert?"
str_before_6:
    .autostring 34 2 "Hier draußen ereignen sich unzählige Unfälle!\pKinder wie du sollten sich von solchen Orten fernhalten!"
str_after_6:
    .autostring 34 2 "Da hab ich dich wohl etwas unterschätzt."
str_later_6:
    .autostring 34 2 "Ist schon in Ordnung, denke ich.\pDu bist stark genug, an so einem Ort auf dich selbst aufzupassen."
str_before_7:
    .autostring 34 2 "Ich habe das Pokémon-Züchten in Laubdorf gelernt.\pViele der Exemplare, die ich züchte, verschicke ich im Wundertausch.\pAber starke Pokémon ziehe ich zum Kampf auf!"
str_after_7:
    .autostring 34 2 "Beeindruckend!\pHast du deine Pokémon selbst aufgezogen?"
str_later_7:
    .autostring 34 2 "Willst du mir nicht eines deiner Pokémon überlassen?\pDu hast da einige echt starke Exemplare aufgezogen!"
str_before_8:
    .autostring 34 2 "Hier zu wandern stärkt den eigenen Körper und den Geist!\pKannst du da noch mithalten?"
str_after_8:
    .autostring 34 2 "UffDOTS\pIch kann nicht mehrDOTS"
str_later_8:
    .autostring 34 2 "Ich bin wirklich ausgelaugtDOTS\pVielleicht sollte ich eine Pause einlegenDOTS"
str_before_9:
    .autostring 34 2 "Meine Eltern sagen immer, dass ich nicht im Aschegras picknicken soll!\pWas wissen die schon?"
str_after_9:
    .autostring 34 2 "HustDOTS\nHust hust hustDOTS"
str_later_9:
    .autostring 34 2 "Was soll schon passieren, wenn ich im Aschegras picknicke?\pHust hust hustDOTS"
str_before_10:
    .autostring 34 2 "Meine Pokémon sind wirklich das Stärkste!\pSie können so gar Feuer speien!\pWas willst du da noch entgegenbringen?"
str_after_10:
    .autostring 34 2 "UffDOTS\pDu bist meinen Flammen aber gut ausgewichen!"
str_later_10:
    .autostring 34 2 "Wuah!\nDein Feuer hat deutlich heißer gebrannt als meines."
str_before_11:
    .autostring 34 2 "Manchmal fliegt hier ein riesiges brennendes Vogel-Pokémon vorbei.\pAber niemand will mir glauben!\pDas macht mir stinksauer!"
str_after_11:
    .autostring 34 2 "Glaubst du mir auch nicht?"
str_later_11:
    .autostring 34 2 "Wenn ich es dir doch sage!\pEs ist wahr!\pManchmal fliegt hier ein unglaublich großes in Flammen stehendes Pokémon am HimmelDOTS"
.elseif LANG_EN
.endif
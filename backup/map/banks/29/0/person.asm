.include "overworld_script.s"
.include "callstds.s"
.include "flags.s"
.include "ordinals.s"

.global ow_script_haweiland_cargo_hall_person_0
.global ow_script_haweiland_cargo_hall_person_1
.global ow_script_haweiland_cargo_hall_person_2
.global ow_script_haweiland_cargo_hall_person_3


ow_script_haweiland_cargo_hall_person_0:
    checkflag FLAG_HAWEILAND_CARGO_HALL_DONE
    gotoif EQUAL done_0
    loadpointer 0 str_0
    callstd MSG_FACE
    end
done_0:
    loadpointer 0 str_0_done
    callstd MSG_FACE
    end

ow_script_haweiland_cargo_hall_person_1:
    checkflag FLAG_HAWEILAND_CARGO_HALL_DONE
    gotoif EQUAL done_1
    loadpointer 0 str_1
    callstd MSG_FACE
    end
done_1:
    loadpointer 0 str_1_done
    callstd MSG_FACE
    end

ow_script_haweiland_cargo_hall_person_2:
    loadpointer 0 str_2
    callstd MSG_FACE
    end
ow_script_haweiland_cargo_hall_person_3:
    checkflag FLAG_HAWEILAND_CARGO_HALL_DONE
    gotoif EQUAL done_3
    loadpointer 0 str_3
    callstd MSG_FACE
    end
done_3:
    loadpointer 0 str_3_done
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Diese vermaledeiten Piraten!\pWochenlang waren wir mit Professor Tann auf einer Expedition und jetzt wollen sie uns die Funde rauben!"
str_0_done:
    .autostring 34 2 "Dass Blackbeard mit der Alten Karte davon gekommen ist, das ist wirklich ärgerlich.\pDabei haben wir noch nicht einmal eine Idee, wie diese Karte überhaupt zu lesen ist."
str_1:
    .autostring 34 2 "Ich habe keine Angst vor Piraten.\pAber im Kampf wurde ich geschlagen, da nützt mir mein Mut rein gar nichtsDOTS"
str_1_done:
    .autostring 34 2 "Der Vorfall mit Blackbeard hat mir gezeigt, dass ich hart trainieren muss, wenn ich diese Lagerhalle beschützen will."
str_2:
    .autostring 34 2 "Es ist eine Schande, dass uns die Alte Karte gestohlen wurde.\pWie lange habe ich gemeinsam mit Professor Tann danach gesucht.\pUnd jetzt soll sie weg sein?"
str_3:
    .autostring 34 2 "Ich habe einen dieser Piraten besiegt, als mir Blackbeard angeboten hat, seiner Crew beizutreten.\pWeißt du, was ich zu ihm gesagt habe?\pDass die sieben Weltmeere seine räuberische Seele verschlingen sollen, auf dass er elendig ersäuft!\pHat ihm nicht gefallen, also hat er mich im Kampf auf Übelste bloßgestelltDOTS"
str_3_done:
    .autostring 34 2 "Ich schäme mich nicht, gegen Blackbeard verloren zu haben.\pIch bin meinen Überzeugungen treu geblieben und für sie eingetreten.\pWegen was sollte ich also ein schlechtes Gewissen haben?"

.elseif LANG_EN
str_0:
    .autostring 34 2 "These damned pirates!\pFor weeks we were on an expedition with Professor Fir and now they want to steal our findings!"
str_0_done:
    .autostring 34 2 "How annyoing that Blackbeard got away with the Old Map.\pWe didn't even figure out how to read itDOTS"
str_1:
    .autostring 34 2 "I am not afraid of pirates.\pBut I was defeated in battle, so my courage is most uselessDOTS"
str_1_done:
    .autostring 34 2 "The incident with Blackbeard showed me that I still have to train a lot if I want to be able to protect this cargo hall."
str_2:
    .autostring 34 2 "What a shame that the Old Map was stolen from us.\pFor how long did I look for it together with Professor Fir.\pAnd now it is goneDOTS"
str_3:
    .autostring 34 2 "I defeated one of those pirates, when Blackbeard offered me to join his crew.\pDo you know what I replied?\pThat the seven seas can swallow his thievish soul for that he might drown dreadfully!\pDidn't like that for sure, this Blackbeard, so he took me down in a battle."
str_3_done:
    .autostring 34 2 "I am not ashamed of losing against Blackbeard.\pI stayed true to my values and fought for them.\pSo what could I possible regret about this?"


.endif

.include "overworld_script.s"
.include "flags.s"
.include "vars.s"
.include "callstds.s"
.include "mugshot.s"
.include "ordinals.s"
.include "movements.s"

.global ow_script_kaskada_tea_house_person_0
.global ow_script_kaskada_tea_house_person_1
.global ow_script_kaskada_tea_house_person_2
.global ow_script_kaskada_tea_house_person_3
.global ow_script_kaskada_tea_house_person_4
.global ow_script_kaskada_tea_house_person_5
.global ow_script_kaskada_tea_house_person_6
.global ow_script_kaskada_tea_house_person_7
.global ow_script_kaskada_tea_house_person_8
.global ow_script_kaskada_tea_house_igva

ow_script_kaskada_tea_house_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end
ow_script_kaskada_tea_house_person_1:
    loadpointer 0 str_1
    callstd MSG_FACE
    end
ow_script_kaskada_tea_house_person_2:
    loadpointer 0 str_2
    callstd MSG_FACE
    end
ow_script_kaskada_tea_house_person_3:
    loadpointer 0 str_3
    callstd MSG_FACE
    end
ow_script_kaskada_tea_house_person_4:
    loadpointer 0 str_4
    callstd MSG_FACE
    end
ow_script_kaskada_tea_house_person_5:
    loadpointer 0 str_5
    callstd MSG_FACE
    end
ow_script_kaskada_tea_house_person_6:
    loadpointer 0 str_6
    callstd MSG_FACE
    end
ow_script_kaskada_tea_house_person_7:
    loadpointer 0 str_7
    callstd MSG_FACE
    end
ow_script_kaskada_tea_house_person_8:
    checkflag FLAG_KASKADA_TEAHOUSE_BLACK_MARKET_UNLOCKED
    gotoif EQUAL unlocked
    loadpointer 0 str_8
    callstd MSG_FACE
    end
unlocked:
    loadpointer 0 str_9
    callstd MSG_FACE
    end
ow_script_kaskada_tea_house_igva:
    faceplayer
    loadpointer 0 str_igva_0
    show_mugshot MUGSHOT_IGVA MUGSHOT_RIGHT message_type=MSG
    applymovement 11 mov_fu
    applymovement 1 mov_fd
    waitmovement 0
    pause 48
    applymovement 11 mov_step_inplace
    waitmovement 0
    pause 48
    applymovement 1 mov_1r
    waitmovement 0
    applymovement 1 mov_fl
    waitmovement 0
    pause 48
    faceplayer
    loadpointer 0 str_igva_1
    show_mugshot MUGSHOT_IGVA MUGSHOT_RIGHT message_type=MSG
    applymovement 11 mov_2u
    waitmovement 0
    sound 9
    hidesprite 11
    checksound
    setflag FLAG_KASKADA_TEAHOUSE_BLACK_MARKET_UNLOCKED
    setflag (FLAG_KASKADA_IGVA_TEAHOUSE | 0x8000)
    release
    end

mov_step_inplace:
    .byte STEP_IN_PLACE_UP, STEP_IN_PLACE_UP, STOP

.ifdef LANG_GER
str_igva_0:
    .autostring 34 2 "Ich werde dir jetzt einmal ein Geheimnis verraten, PLAYER!\pHinter dem Teehaus hier steckt viel mehr, als der Anschein verraten mag.\pDu musst nämlich wissen, dass es hier im Untergrund einen Handelsplatz gibt.\pNatürlich kommt man da nicht einfach so hinein.\pAber mit mir zusammen ist das gar kein Problem.\pPass mal auf!"
str_igva_1:
    .autostring 34 2 "Siehst du?\nGanz leicht, oder?\pJetzt müssen wir uns aber beeilen, wenn wir unseren Anführer noch treffen wollenDOTS"
str_0:
    .autostring 34 2 "Im Teehaus ist immer sehr viel los.\pAn manchen Wochenenden bekommt man nicht einmal mehr einen Platz.\pAber das ist kaum verwunderlich bei all dem guten Tee hier!"
str_1:
    .autostring 34 2 "Es gibt wirklich keinen besseren Ort für ein Date als das Teehaus in Kaskada.\pDa fühlt man sich so richtig wohl."
str_2:
    .autostring 34 2 "Ich führe alle Mädchen, die ich kennenlerne ins Teehaus aus.\pDas ist eine narrensichere Masche.\pKannst du mir ruhig glauben."
str_3:
    .autostring 34 2 "Meine Arbeit als Polizist ist sehr hart.\pWir haben mächtig Probleme mit der RevolutionsbewegungDOTS\pUnd jetzt tauchen auch noch diese Team Violet Leute überall auf.\pDa freut man sich umso mehr darüber, seinen Feierabend im Teehaus verbringen zu können."
str_4:
    .autostring 34 2 "Herzlich willkommen im Teehaus von Kaskada.\pWir sind das beliebteste Geschäft der ganzen Stadt.\pDu solltest wirklich einmal unser großartiges Angebot verschiedener Teesorten betrachten."
str_5:
    .autostring 34 2 "Nach der Schule treffen wir uns öfter hier im Teehaus, um gemütlich einen heißen Tee zu schlürfen.\pDas lässt einen auch über schlechte Tage hinwegsehen."
str_6:
    .autostring 34 2 "Früher mal, bevor Devin von den Top Vier diesen Laden gekauft hat, war es deutlich ruhiger.\pJetzt tauchen hier immer wieder ganz seltsame Leute auf und verschwinden in den LagerraumDOTS"
str_7:
    .autostring 34 2 "Du kannst dir gar nicht vorstellen, wie anstrengend es ist, in einem so belebten Geschäft der einzige Kellner zu seinDOTS"
str_8:
    .autostring 34 2 "Hey, im Lagerraum hast du nichts zu suchen, verstanden?\pDer ist nämlich nur für besondere Gäste zugänglichDOTS"
str_9:
    .autostring 34 2 "Wenn man den ganzen Tag hier den Lagerraum bewachen muss, wird man sehr durstig.\pWas für ein Zufall, dass ich gerade in einem Teehaus arbeite."
.elseif LANG_EN
.endif
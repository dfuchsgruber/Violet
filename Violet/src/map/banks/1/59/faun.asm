.include "flags.s"
.include "movements.s"
.include "callstds.s"
.include "vars.s"
.include "ordinals.s"
.include "overworld_script.s"
.include "mugshot.s"
.include "specials.s"
.include "songs.s"
.include "trainer_backsprites.s"
.include "pathfinding.s"

.global ow_script_tafelberg_faun

ow_script_tafelberg_faun:
    pause 16
    playsong MUS_REVOLUTION 0
    call look_at_faun
    loadpointer 0 str_0
    show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT message_type=MSG_KEEPOPEN emotion=MUGSHOT_SERIOUS
    call look_at_albus
    loadpointer 0 str_1
    show_mugshot MUGSHOT_ALBUS MUGSHOT_LEFT message_type=MSG_KEEPOPEN
    call look_at_faun
    loadpointer 0 str_2
    show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT message_type=MSG_KEEPOPEN emotion=MUGSHOT_ANGRY
    call look_at_albus
    loadpointer 0 str_3
    show_mugshot MUGSHOT_ALBUS MUGSHOT_LEFT message_type=MSG_KEEPOPEN emotion=MUGSHOT_SAD
    loadpointer 0 str_4
    show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT message_type=MSG_KEEPOPEN emotion=MUGSHOT_ANGRY
    loadpointer 0 str_5
    show_mugshot MUGSHOT_ALBUS MUGSHOT_LEFT message_type=MSG_KEEPOPEN
    loadpointer 0 str_4
    show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT message_type=MSG_KEEPOPEN emotion=MUGSHOT_SERIOUS
    loadpointer 0 str_6
    show_mugshot MUGSHOT_ALBUS MUGSHOT_LEFT message_type=MSG
    pause 32
    loadpointer 0 str_7
    show_mugshot MUGSHOT_ALBUS MUGSHOT_LEFT message_type=MSG_KEEPOPEN emotion=MUGSHOT_SAD hide_mugshot=0
    update_mugshot_emotion MUGSHOT_NORMAL
    loadpointer 0 str_8
    callstd MSG_KEEPOPEN
    hide_mugshot
    closeonkeypress
    pause 16
    applymovement 11 mov_fu
    waitmovement 0
    pause 16
    applymovement 9 mov_2u
    waitmovement 0
    applymovement 9 mov_fd
    waitmovement 0
    applymovement 11 mov_albus_to_head_away
    waitmovement 0
    pause 32
    applymovement 0xFF mov_fu
    applymovement 43 mov_fu
    applymovement 11 mov_fd
    waitmovement 0
    loadpointer 0 str_9
    show_mugshot MUGSHOT_ALBUS MUGSHOT_LEFT message_type=MSG
    applymovement 11 mov_albus_away
    applymovement 9 mov_revo1_away
    applymovement 42 mov_revo2_away
    waitmovement 42
    hidesprite 11
    hidesprite 9
    hidesprite 42
    pause 16
    fadesong MUS_ROUTE_24_25
    pause 16
    applymovement 43 mov_fd
    applymovement 0xFF mov_fl
    loadpointer 0 str_10
    show_mugshot MUGSHOT_FELIX MUGSHOT_LEFT message_type=MSG_KEEPOPEN emotion=MUGSHOT_RUMINATIVE
    applymovement 12 mov_fu
    waitmovement 0
    loadpointer 0 str_11
    show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT message_type=MSG_KEEPOPEN emotion=MUGSHOT_SERIOUS
    applymovement 12 mov_fr
    waitmovement 0
    loadpointer 0 str_12
    show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT message_type=MSG_KEEPOPEN emotion=MUGSHOT_SERIOUS
    applymovement 12 mov_fu
    waitmovement 0
    loadpointer 0 str_13
    show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT message_type=MSG emotion=MUGSHOT_SERIOUS
    sound 0x15
    applymovement 43 mov_exclam
    waitmovement 0
    checksound
    loadpointer 0 str_14
    show_mugshot MUGSHOT_FELIX MUGSHOT_LEFT message_type=MSG_KEEPOPEN emotion=MUGSHOT_SHOCKED
    loadpointer 0 str_15
    show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT message_type=MSG_KEEPOPEN emotion=MUGSHOT_ANGRY hide_mugshot=0
    applymovement 12 mov_fl
    waitmovement 0
    update_mugshot_emotion MUGSHOT_SERIOUS
    loadpointer 0 str_16
    callstd MSG_KEEPOPEN
    applymovement 12 mov_fu
    waitmovement 0
    loadpointer 0 str_17
    callstd MSG_KEEPOPEN
    hide_mugshot
    loadpointer 0 str_18
    show_mugshot MUGSHOT_FELIX MUGSHOT_LEFT message_type=MSG emotion=MUGSHOT_ANGRY
    sound 0x15
    applymovement 12 mov_double_exclam
    waitmovement 0
    checksound
    loadpointer 0 str_19
    show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT message_type=MSG_KEEPOPEN emotion=MUGSHOT_ANGRY
    loadpointer 0 str_20
    show_mugshot MUGSHOT_FELIX MUGSHOT_LEFT message_type=MSG emotion=MUGSHOT_SCARED
    pause 24
    applymovement 12 mov_1l
    waitmovement 0
    applymovement 43 mov_fl
    waitmovement 0
    pause 16
    loadpointer 0 str_21
    show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT message_type=MSG emotion=MUGSHOT_SERIOUS
    applymovement 12 mov_fr
    waitmovement 0
    loadpointer 0 str_22
    show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT message_type=MSG emotion=MUGSHOT_SERIOUS
    loadpointer 0 str_23
    show_mugshot MUGSHOT_FELIX MUGSHOT_LEFT message_type=MSG_KEEPOPEN hide_mugshot=0
    applymovement 43 mov_fd
    applymovement 0xFF mov_fu
    waitmovement 0
    update_mugshot_emotion MUGSHOT_HAPPY
    loadpointer 0 str_24
    callstd MSG
    hide_mugshot
    sound 0x15
    applymovement 12 mov_exclam
    waitmovement 0
    checksound
    applymovement 43 mov_fl
    waitmovement 0
    applymovement 12 mov_1r
    waitmovement 0
    applymovement 43 mov_fd
    applymovement 0xFF mov_fl
    waitmovement 0
    pause 64
    applymovement 12 mov_fu
    waitmovement 0
    pause 64
    loadpointer 0 str_25
    show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT message_type=MSG_KEEPOPEN hide_mugshot=0
    update_mugshot_emotion MUGSHOT_SERIOUS
    loadpointer 0 str_26
    callstd MSG
    hide_mugshot
    pause 4
    loadpointer 0 str_27
    show_mugshot MUGSHOT_FELIX MUGSHOT_LEFT message_type=MSG emotion=MUGSHOT_ANNOYED
    loadpointer 0 str_28
    show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT message_type=MSG
    loadpointer 0 str_29
    show_mugshot MUGSHOT_FELIX MUGSHOT_LEFT message_type=MSG emotion=MUGSHOT_HAPPY
    loadpointer 0 str_30
    show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT message_type=MSG
    applymovement 12 mov_faun_away
    waitmovement 0
    hidesprite 12
    pause 32
    applymovement 43 mov_fd
    applymovement 0xFF mov_fu
    loadpointer 0 str_31
    show_mugshot MUGSHOT_FELIX MUGSHOT_LEFT message_type=MSG_KEEPOPEN emotion=MUGSHOT_RUMINATIVE hide_mugshot=0
    update_mugshot_emotion MUGSHOT_NORMAL
    loadpointer 0 str_32
    callstd MSG_KEEPOPEN
    update_mugshot_emotion MUGSHOT_HAPPY
    loadpointer 0 str_33
    callstd MSG_KEEPOPEN
    update_mugshot_emotion MUGSHOT_NORMAL
    loadpointer 0 str_34
    callstd MSG
    hide_mugshot
    applymovement 43 mov_felix_away
    waitmovement 0
    hidesprite 43
    clearflag (KASKADA_IGVA | 0x8000)
    releaseall
    end

mov_albus_to_head_away:
    .byte STEP_UP, STEP_UP, STEP_RIGHT, STEP_UP, STOP
mov_albus_away:
    .byte STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STEP_UP, STEP_UP, STEP_UP, STEP_UP, STOP
mov_revo1_away:
    .byte STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STEP_UP, STEP_UP, STEP_UP, STEP_UP, STOP
mov_revo2_away:
    .byte STEP_UP, STEP_UP, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STEP_UP, STEP_UP, STEP_UP, STEP_UP, STOP
mov_faun_away:
    .byte STEP_LEFT, STEP_UP, STEP_UP, STEP_UP, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STEP_UP, STEP_UP, STEP_UP, STEP_UP, STOP
mov_felix_away:
    .byte STEP_UP, STEP_UP, STEP_UP, STEP_RIGHT, STEP_RIGHT, STEP_UP, STEP_UP, STEP_UP, STEP_UP, STOP

look_at_faun:
    applymovement 42 mov_fr
    applymovement 9 mov_fr
    applymovement 43 mov_fd
    applymovement 0xFF mov_fl
    applymovement 11 mov_fr
    waitmovement 0
    return

look_at_albus:
    applymovement 42 mov_fr
    applymovement 9 mov_fd
    applymovement 43 mov_fl
    applymovement 0xFF mov_fl
    applymovement 12 mov_fl
    waitmovement 0
    return

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Was ist denn in dich gefahren, Albus?\pWillst du all das, was wir zusammen aufgebaut haben, einfach so niederbrennen?"
str_1:
    .autostring 34 2 "Faun!\pIch wünschte, es gäbe einen anderen Weg.\pAber die Pokémon-LigaDOTS\pSie ist nicht mehr zu rettenDOTS\pKorruption und Machtgier haben sie zugrunde gerichtetDOTS"
str_2:
    .autostring 34 2 "Ach ja?\pWas soll dieser Unsinn denn heißen, Albus?\pUnd selbst wenn du damit recht haben solltestDOTS\pSoll diese sogenannte Revolutionsbewegung etwa die Lösung sein?"
str_3:
    .autostring 34 2 "Ich sehe, dass du noch nicht bereit bist, der Wahrheit ins Auge zu blicken, FaunDOTS"
str_4:
    .autostring 34 2 "DOTSTEXT_DELAY_SHORT DOTSTEXT_DELAY_SHORT DOTSTEXT_DELAY_SHORT"
str_5:
    .autostring 34 2 "Und was nun?\pWillst du gegen mich kämpfen, Faun?"
str_6:
    .autostring 34 2 "Das habe ich mir gedacht."
str_7:
    .autostring 34 2 "Ich kann dich ja verstehen, Faun.\pGanz ehrlich.\pDenkst du, es ist mir leicht gefallen, der Pokémon Liga den Rücken zu kehren?"
str_8:
    .autostring 34 2 "Aber diese RevolutionDOTS\pIst notwendig, mein alter Freund.\pIch hoffe ehrlich, dass wir am Ende am gleichen Strang ziehenDOTS\pDiese Revolution wird jemanden wie dich mit offenen Armen aufnehmen.\pBis dahinDOTS"
str_9:
    .autostring 34 2 "Alles Gute, FaunDOTS"
str_10:
    .autostring 34 2 "Was war das denn für eine seltsame Nummer?\pKennst du diesen Typen etwa, Opi?"
str_11:
    .autostring 34 2 "FelixDOTS"
str_12:
    .autostring 34 2 "PLAYERDOTS"
str_13:
    .autostring 34 2 "Dieser MannDOTS\pEr war einmal ein sehr guter FreundDOTS\pAls man mir erzählt hat, dass erDOTS\pIch konnte es nicht glaubenDOTS\pDOTSTEXT_DELAY_SHORT DOTSTEXT_DELAY_SHORT DOTSTEXT_DELAY_SHORT\pAber er ist der Anführer der Revolutionsbewegung."
str_14:
    .autostring 34 2 "Was?\nIst das dein Ernst?\pDieser Typ war der Anführer der Revolutionäre?\pWarum hast du ihn denn dann laufen lassen?"
str_15:
    .autostring 34 2 "So einfach ist das nicht, Felix!"
str_16:
    .autostring 34 2 "Du hältst Albus sicherlich für einen VerbrecherDOTS\pUnd bei allem, was die Revolutionsbewegung in der letzten Zeit angestellt hat, kann man dir das auch nicht verübelnDOTS\pAber Albus ist kein schlechter Mensch.\pEr ist mein Freund."
str_17:
    .autostring 34 2 "Als ich gehört habe, dass er sich in der Nähe von Kaskada aufhält, wollte ich keine Zeit verlieren.\pIch hatte die Hoffnung, dass ich meinem alten Freund ins Gewissen reden könnteDOTS\pDass ich ihn wieder zur Vernunft bringen würdeDOTS"
str_18:
    .autostring 34 2 "Aber deswegen kannst du den Kopf der Revolutionsbewegung doch nicht einfach entkommen lassen!"
str_19:
    .autostring 34 2 "Was erlaubst du Rotzlöffel dir eigentlich, so mit mir zu reden?\pIch bin immer noch dein Großvater und Lehrer!"
str_20:
    .autostring 34 2 "E-Entschuldige bitte, OpiDOTS"
str_21:
    .autostring 34 2 "Aber du hast recht, FelixDOTS\pAls Mitglied der Pokémon-Liga muss ich den Anführer der Revolutionsbewegung festnehmenDOTS"
str_22:
    .autostring 34 2 "Aber gegen einen guten Freund zu kämpfenDOTS"
str_23:
    .autostring 34 2 "Na, das ist doch ganz klar, Opi!\pEs würde mir auch nicht leicht fallen, gegen PLAYER zu kämpfen.\pAber mach dir keine Sorgen.\pWir beide werden uns diesen Albus schon vorknöpfen und du bist fein raus!"
str_24:
    .autostring 34 2 "Nicht wahr, PLAYER?"
str_25:
    .autostring 34 2 "Ach ihr beidenDOTS\pIhr habt das Herz am rechten Fleck."
str_26:
    .autostring 34 2 "Aber werdet nicht übermütig.\pIhr seid sicherlich schon stärker geworden, aber Albus ist ein Kaliber zu groß für euch.\pSogar für mich wäre es eine Herausforderung, gegen ihn zu kämpfen.\pAlso versprecht mir, dass ihr euch nicht mit ihm anlegt, ja?\pÜberlasst das den Top Vier."
str_27:
    .autostring 34 2 "Na gut, Opi.\pWir versprechen es, ja?"
str_28:
    .autostring 34 2 "Ausgezeichnet!\pJunge Trainer wie ihr sollten sich ohnehin nicht mit den Problem alter Männer befassen müssen!\pIch werde mich selbst um die Geschichte mit Albus kümmern.\pUnd ihr bestreitet euer eigenes Abenteuer!"
str_29:
    .autostring 34 2 "Genau, Opi!"
str_30:
    .autostring 34 2 "Macht eurem altern Lehrer ja keine Schande, ihr Gören!"
str_31:
    .autostring 34 2 "Was sagst du dazu, PLAYER?\pWir können diesen Albus doch nicht einfach so laufen lassen, oder?\pAuch wenn wir Opi etwas anderes gesagt habenDOTSTEXT_DELAY_SHORT\pSollten wir diesen Revolutionsanführer Hops nehmen."
str_32:
    .autostring 34 2 "Und außerdemDOTS"
str_33:
    .autostring 34 2 "Habe ich sowieso die Finger gekreuzt, als ich mein Versprechen gegeben habe."
str_34:
    .autostring 34 2 "Lass uns diesen Albus in die Mangel nehmen.\pWeit kann er ja nicht gekommen sein!"
.elseif LANG_EN
str_0:
    .autostring 34 2 "What has gotten into you, Albus?\pDo you want to simply burn down everything we've built together?"
str_1:
    .autostring 34 2 "Faun!\pI wish there was another way.\pBut the Pokémon LeagueDOTS\pIt's beyond savingDOTS\pCorruption and greed have destroyed it."
str_2:
    .autostring 34 2 "Oh really?\pWhat does this nonsense even mean, Albus?\pAnd even if you're rightDOTS\pIs this so-called revolution the solution?"
str_3:
    .autostring 34 2 "I see that you're not ready to face the truth yet, FaunDOTS"
str_4:
    .autostring 34 2 "DOTSTEXT_DELAY_SHORT DOTSTEXT_DELAY_SHORT DOTSTEXT_DELAY_SHORT"
str_5:
    .autostring 34 2 "And now what?\pDo you want to fight me, Faun?"
str_6:
    .autostring 34 2 "I thought so."
str_7:
    .autostring 34 2 "I understand you, Faun.\pHonestly.\pDo you think it was easy for me to turn my back on the Pokémon League?"
str_8:
    .autostring 34 2 "But this revolutionDOTS\pIs necessary, my old friend.\pI sincerely hope that in the end, we'll be on the same sideDOTS\pThis revolution will welcome someone like you with open arms.\pUntil thenDOTS"
str_9:
    .autostring 34 2 "Goodbye, FaunDOTS"
str_10:
    .autostring 34 2 "What was that strange act?\pDo you know that guy, Grandpa?"
str_11:
    .autostring 34 2 "FelixDOTS"
str_12:
    .autostring 34 2 "PLAYERDOTS"
str_13:
    .autostring 34 2 "This manDOTS\pHe used to be a very good friendDOTS\pWhen I heard that heDOTS\pI couldn't believe itDOTS\pDOTSTEXT_DELAY_SHORT DOTSTEXT_DELAY_SHORT DOTSTEXT_DELAY_SHORT\pBut he's the leader of the revolution."
str_14:
    .autostring 34 2 "What?\nAre you serious?\pThis guy was the leader of the revolutionaries?\pWhy did you let him go then?"
str_15:
    .autostring 34 2 "It's not that simple, Felix!"
str_16:
    .autostring 34 2 "You surely consider Albus a criminalDOTS\pAnd with everything the revolution has done lately, it's hard to blame youDOTS\pBut Albus is not a bad person.\pHe's my friend."
str_17:
    .autostring 34 2 "When I heard that he was in the vicinity of Cascade, I didn't want to waste any time.\pI had hope that I could talk some sense into my old friendDOTS\pThat I could bring him back to reasonDOTS"
str_18:
    .autostring 34 2 "But you can't just let the head of the revolution escape because of that!"
str_19:
    .autostring 34 2 "Who do you think you are, kid, talking to me like that?\pI'm still your grandfather and teacher!"
str_20:
    .autostring 34 2 "S-Sorry, GrandpaDOTS"
str_21:
    .autostring 34 2 "But you're right, FelixDOTS\pAs a member of the Pokémon League, I have to arrest the leader of the revolutionDOTS"
str_22:
    .autostring 34 2 "But to fight against a good friendDOTS"
str_23:
    .autostring 34 2 "Well, that's obvious, Grandpa!\pI wouldn't find it easy to fight against PLAYER either.\pBut don't worry.\pWe'll take care of this Albus and you'll be fine!"
str_24:
    .autostring 34 2 "Isn't that right, PLAYER?"
str_25:
    .autostring 34 2 "Oh you twoDOTS\pYou have a good heart."
str_26:
    .autostring 34 2 "But don't get too cocky.\pYou've surely become stronger, but Albus is a challenge too big for you.\pEven for me, it would be a challenge to fight him.\pSo promise me that you won't confront him, okay?\pLeave that to the Elite Four."
str_27:
    .autostring 34 2 "Alright, Grandpa.\pWe promise, okay?"
str_28:
    .autostring 34 2 "Excellent!\pYoung trainers like you shouldn't have to deal with the problems of old men!\pI'll take care of the situation with Albus myself.\pAnd you go on your own adventure!"
str_29:
    .autostring 34 2 "Exactly, Grandpa!"
str_30:
    .autostring 34 2 "Don't bring shame to your old teacher, you brats!"
str_31:
    .autostring 34 2 "What do you say, PLAYER?\pWe can't just let this Albus go, right?\pEven if we told Grandpa something elseDOTSTEXT_DELAY_SHORT\pWe should catch this leader of the revolution."
str_32:
    .autostring 34 2 "And besidesDOTS"
str_33:
    .autostring 34 2 "I had my fingers crossed when I made that promise anyway."
str_34:
    .autostring 34 2 "Let's corner this Albus.\pHe can't have gone far!"
.endif
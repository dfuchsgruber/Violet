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
    clearflag KASKADA_IGVA
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
    .autostring 34 2 "Was soll dieser ganze Wahnsinn denn, mein alter Freund?\pWillst du all das, was wir zusammen aufgebaut haben, einfach so niederbrennen?"
str_1:
    .autostring 34 2 "Faun!\pIch wünschte, es gäbe einen anderen Weg.\pAber die Pokémon-LigaDOTS\pSie ist nicht mehr zu rettenDOTS\pKorruption und Machtgier haben aus ihre eine regelrechte Unterdrückungsherrschaft gemachtDOTS"
str_2:
    .autostring 34 2 "Ach ja?\pWer gibt dir das Recht, das zu entscheiden, Albus?\pUnd selbst wenn du damit recht haben solltestDOTS\pSoll deine fanatische Revolutionsbewegung etwa die Lösung sein?"
str_3:
    .autostring 34 2 "Ich sehe, dass du noch nicht bereit bist, die Wahrheit zu akzeptieren, FaunDOTS"
str_4:
    .autostring 34 2 "DOTSTEXT_DELAY_SHORT DOTSTEXT_DELAY_SHORT DOTSTEXT_DELAY_SHORT"
str_5:
    .autostring 34 2 "Und was nun?\pWillst du gegen mich kämpfen, Faun?"
str_6:
    .autostring 34 2 "Das habe ich mir gedacht."
str_7:
    .autostring 34 2 "Ich kann dich ja verstehen, Faun.\pGanz ehrlich.\pDenkst du, es ist mir leicht gefallen, der Pokémon Liga den Rücken zu kehren?"
str_8:
    .autostring 34 2 "Aber diese RevolutionDOTS\pIst notwendig, mein alter Freund.\pIch hoffe, dass wir uns in diesem Kampf am Ende nicht als Gegner gegenüberstehen werdenDOTS\pDiese Revolution kann jemanden wie dich jederzeit in ihren Reihen gebrauchen.\pBis dahinDOTS"
str_9:
    .autostring 34 2 "Leb wohl, FaunDOTS"
str_10:
    .autostring 34 2 "Was war das denn für eine seltsame Nummer?\pKennst du diesen Typen etwa, Opi?"
str_11:
    .autostring 34 2 "FelixDOTS"
str_12:
    .autostring 34 2 "PLAYERDOTS"
str_13:
    .autostring 34 2 "Dieser Mann war einmal ein sehr guter Freund von mirDOTS\pAußerdem ist er derDOTS\nDOTSTEXT_DELAY_SHORT DOTSTEXT_DELAY_SHORT DOTSTEXT_DELAY_SHORT\pAnführer der Revolutionsbewegung."
str_14:
    .autostring 34 2 "Was?\nIst das dein Ernst?\pDieser Typ war der Anführer der Revolutionäre?\pWarum hast du ihn denn dann laufen lassen?"
str_15:
    .autostring 34 2 "So einfach ist das nicht, Felix!"
str_16:
    .autostring 34 2 "Du hältst Albus wohl für einen durchtriebenen VerbrecherDOTS\pUnd bei allem, was die Revolutionsbewegung in der letzten Zeit angestellt hat, kann man dir das auch nicht verübelnDOTS\pAber Albus ist im Grunde kein schlechter Mensch.\pUnd außerdem ist er mein Freund."
str_17:
    .autostring 34 2 "Als ich gehört habe, dass er sich in der Nähe von Kaskada aufhält, wollte ich keine Zeit verlieren.\pIch hatte die Hoffnung, dass ich meinem alten Freund ins Gewissen reden könnteDOTS\pDass ich ihn wieder zur Vernunft bringen würdeDOTS"
str_18:
    .autostring 34 2 "Aber deswegen kannst du den Kopf der Revolutionsbewegung doch nicht einfach entkommen lassen!\pIst dir denn nicht klar, welchen Schaden diese Revolutionäre anrichten, Opi?"
str_19:
    .autostring 34 2 "Was erlaubst du Rotzlöffel dir eigentlich, so mit mir zu reden?\pIch bin dein Großvater!"
str_20:
    .autostring 34 2 "E-Entschuldige bitte, OpiDOTS"
str_21:
    .autostring 34 2 "Aber du hast ja recht, FelixDOTS\pAls Mitglied der Pokémon-Liga wäre es meine Aufgabe gewesen, den Anführer der Revolutionsbewegung festzunehmenDOTS"
str_22:
    .autostring 34 2 "Aber gegen einen Freund zu kämpfenDOTS\pDas ist nicht immer leicht, verstanden?"
str_23:
    .autostring 34 2 "Na, das ist doch ganz klar, Opi!\pEs würde mir auch nicht leicht fallen, gegen PLAYER zu kämpfen.\pAber mach dir keine Sorgen.\pWir beide werden uns diesen Albus schon vorknöpfen."
str_24:
    .autostring 34 2 "Nicht wahr, PLAYER?"
str_25:
    .autostring 34 2 "Ihr beidenDOTS\pIhr habt das Herz am rechten Fleck."
str_26:
    .autostring 34 2 "Aber werdet nicht übermütig.\pIhr seid sicherlich schon sehr stark geworden, aber Albus ist eine Hausnummer zu groß für euch.\pSelbst ich weiß nicht, ob ich einen Kampf gegen ihn gewinnen könnte.\pAlso versprecht mir, dass ihr euch nicht mit ihm anlegt, ja?"
str_27:
    .autostring 34 2 "Na gut, Opi.\pWir versprechen es, ja?"
str_28:
    .autostring 34 2 "Ausgezeichnet!\pJunge Trainer wie ihr sollten sich ohnehin nicht mit den Problem alter Knacker befassen müssen!\pIch werde mich schon um die Geschichte mit Albus kümmern.\pUnd ihr habt währenddessen einfach Spaß auf eurem Abenteuer, ja?"
str_29:
    .autostring 34 2 "Natürlich, Opi!"
str_30:
    .autostring 34 2 "Macht eurem altern Lehrer keine Schande!"
str_31:
    .autostring 34 2 "Was sagst du dazu, PLAYER?\pWir können diesen Albus doch nicht einfach so laufen lassen, oder?\pAuch wenn wir Opi etwas anderes gesagt habenDOTSTEXT_DELAY_SHORT\pSollten wir diesen Revolutionsanführer Hops nehmen."
str_32:
    .autostring 34 2 "Und außerdemDOTS"
str_33:
    .autostring 34 2 "Habe ich sowieso die Finger gekreuzt, als ich mein Versprechen gegeben habe."
str_34:
    .autostring 34 2 "Lass uns diesen Albus in die Mangel nehmen.\pWeit kann er ja nicht gekommen sein!"
.elseif LANG_EN
.endif
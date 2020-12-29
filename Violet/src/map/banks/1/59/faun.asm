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
    .autostring 34 2 "Aber diese RevolutionDOTS\pIst notwendig, mein alter Freund.\pIch hoffe, dass wir uns in diesem Kampf nicht als Gegner gegenüberstehen müssenDOTS\pDiese Revolution kann jemanden wie dich jederzeit in ihren Reihen gebrauchen.\pBis dahinDOTS"
str_9:
    .autostring 34 2 "Leb wohl, FaunDOTS"

.elseif LANG_EN
.endif
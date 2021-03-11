.include "overworld_script.s"
.include "callstds.s"
.include "mugshot.s"
.include "flags.s"
.include "movements.s"
.include "vars.s"
.include "ordinals.s"


.global ow_script_route_4_south_cave_person_0
.global ow_script_route_4_south_cave_person_1
.global ow_script_route_4_south_cave_larissa_and_manuel

ow_script_route_4_south_cave_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end
ow_script_route_4_south_cave_person_1:
    loadpointer 0 str_1
    callstd MSG_FACE
    end

ow_script_route_4_south_cave_larissa_and_manuel:
    pause 48
    sound 124
    applymovement 5 mov_rock_smash
    waitmovement 0x0
    hidesprite 5
    pause 32
    loadpointer 0 str_2
    show_mugshot MUGSHOT_LARISSA MUGSHOT_RIGHT
    pause 32
    sound 124
    applymovement 6 mov_rock_smash
    waitmovement 0x0
    hidesprite 6
    pause 32
    loadpointer 0 str_3
    show_mugshot MUGSHOT_MANUS MUGSHOT_RIGHT emotion=MUGSHOT_HAPPY
    applymovement 11 mov_fl
    waitmovement 0
    loadpointer 0 str_4
    show_mugshot MUGSHOT_MANUS MUGSHOT_RIGHT
    applymovement 10 mov_fr
    waitmovement 0
    loadpointer 0 str_5
    show_mugshot MUGSHOT_LARISSA MUGSHOT_RIGHT
    pause 32
    sound 0x15
    applymovement 10 mov_fu
    applymovement 11 mov_fu
    waitmovement 0
    applymovement 10 mov_exclam
    applymovement 11 mov_exclam
    waitmovement 0
    checksound
    loadpointer 0 str_6
    show_mugshot MUGSHOT_LARISSA MUGSHOT_RIGHT hide_mugshot=0 message_type=MSG_KEEPOPEN
    loadpointer 0 str_7
    update_mugshot_emotion MUGSHOT_HAPPY
    callstd MSG_KEEPOPEN
    hide_mugshot
    closeonkeypress
	checkgender
    compare LASTRESULT 0x0
    callif EQUAL buffer_he
	compare LASTRESULT 0x1
	callif EQUAL buffer_she
    applymovement 11 mov_fl
    waitmovement 0
    loadpointer 0 str_8
    show_mugshot MUGSHOT_MANUS MUGSHOT_RIGHT
    applymovement 10 mov_fr
    waitmovement 0
    loadpointer 0 str_9
    show_mugshot MUGSHOT_LARISSA MUGSHOT_RIGHT
    applymovement 10 mov_fu
    applymovement 11 mov_fu
    loadpointer 0 str_10
    show_mugshot MUGSHOT_MANUS MUGSHOT_RIGHT
    applymovement 10 mov_fr
    loadpointer 0 str_11
    show_mugshot MUGSHOT_LARISSA MUGSHOT_RIGHT
    applymovement 10 mov_fu
    loadpointer 0 str_12
    show_mugshot MUGSHOT_MANUS MUGSHOT_RIGHT
    applymovement 11 mov_6d
    waitmovement 0
    hidesprite 11
    loadpointer 0 str_13
    show_mugshot MUGSHOT_LARISSA MUGSHOT_RIGHT emotion=MUGSHOT_HAPPY hide_mugshot=0
    update_mugshot_emotion MUGSHOT_NORMAL
    loadpointer 0 str_14
    callstd MSG_KEEPOPEN
    update_mugshot_emotion MUGSHOT_RUMINATIVE
    loadpointer 0 str_15
    callstd MSG_KEEPOPEN
    update_mugshot_emotion MUGSHOT_HAPPY
    loadpointer 0 str_16
    callstd MSG_KEEPOPEN
    update_mugshot_emotion MUGSHOT_NORMAL
    loadpointer 0 str_17
    callstd MSG_KEEPOPEN
    hide_mugshot
    closeonkeypress
    applymovement 10 mov_6d
    waitmovement 0
    hidesprite 10
    releaseall
    end

mov_rock_smash:
    .byte 0x68, STOP

buffer_he:
	bufferstring 0 str_he
	bufferstring 1 str_him
	return
buffer_she:
	bufferstring 0 str_she
	bufferstring 1 str_her
	return

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Meine alten müden Knochen haben mich früher ohne Mühe den Küstenberg hinaufgetragen.\pJetzt schaffe ich es kaum einige Meter weit von Blütenbach wegDOTS"
str_1:
    .autostring 34 2 "Ich bin schwer beeindruckt von all den Kämpfern, die hier trainieren.\pDie meisten von ihnen versuchen stark genug zu werden, um von Manuel als Schüler aufgenommen zu werden."
str_2:
    .autostring 34 2 "Das ist wirklich ein Kinderspiel."
str_3:
    .autostring 34 2 "Damit wäre der Weg wieder freigeräumt."
str_4:
    .autostring 34 2 "Ich muss mich wirklich bei dir bedanken, Mädchen.\pOhne dich hätte das ganze hier sicher viel länger gedauert."
str_5:
    .autostring 34 2 "Ach, das ist doch nicht der Rede wert.\pIch hatte ohnehin das Gefühl vor Langeweile zu sterben."
str_6:
    .autostring 34 2 "PLAYER!\pDas ist ja eine Überraschung."
str_7:
    .autostring 34 2 "Du siehst aus, als wärst du um einiges stärker geworden, seit wir uns das letzte Mal gesehen haben.\pHabe ich recht?"
str_8:
    .autostring 34 2 "Dieses Kind?\pBUFFER_1 soll ein starker Trainer sein?"
str_9:
    .autostring 34 2 "Du würdest dich wundern, Manuel."
str_10:
    .autostring 34 2 "Das glaube ich erst, wenn ich es selbst gesehen habe.\pMein Name ist Manuel und ich bin der Arenaleiter von Blütenbach.\pNormalerweise würde ich jemanden wie dich gar nicht erst in meiner Arena antreten lassen.\pAber Larissa scheint etwas auf dich zu halten.\pUnd weil sie mir beim Freiräumen dieses Weges geholfen hat, bin ich es ihr wohl schuldig, deine Herausforderung zumindest anzunehmen.\pWenn du den Mumm haben solltest, gegen mich zu kämpfen.\pWas sagst du?"
str_11:
    .autostring 34 2 "Natürlich wird PLAYER gegen dich kämpfen!"
str_12:
    .autostring 34 2 "Na dann ist es ausgemacht.\pIch werde dich in meiner Arena erwarten, Kindchen.\pLass mich ja warten, verstanden?"
str_13:
    .autostring 34 2 "Da sind wohl etwas die Ponitas mit mir durchgegangen.\pEntschudlige bitte, dass ich dich eben so bevormundet habe."
str_14:
    .autostring 34 2 "Es ist einfach so aufregend, zu sehen, wie sehr du dich weiterentwickelt hast.\pDir selbst mag das vielleicht nicht aufgefallen seinDOTS\pAber alles an dir schreit inzwischen nach Trainer."
str_15:
    .autostring 34 2 "Sicherlich hast du noch einen weiten Weg vor dirDOTS"
str_16:
    .autostring 34 2 "Aber ich kann es kaum abwarten, zu erfahren, wie weit du es bringen wirst."
str_17:
    .autostring 34 2 "Und Manuel ist niemand, den man unterschätzen sollte.\pAlso gib dein Bestes, ja?"
str_he:
    .string "Der"
str_him:
    .string "hin"
str_she:
    .string "Die"
str_her:
    .string "sie"
.elseif LANG_EN
.endif
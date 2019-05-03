.include "overworld_script.s"
.include "callstds.s"
.include "mugshot.s"
.include "vars.s"
.include "flags.s"
.include "movements.s"
.include "specials.s"
.include "songs.s"

.global ow_script_forest_cemetery_rin_event

ow_script_forest_cemetery_rin_event:
    lockall
    playsong MUS_VIOLET_ENCOUNTER 0
    loadpointer 0 str_teah_0
    show_mugshot MUGSHOT_TEAH alignment=MUGSHOT_RIGHT message_type=MSG_KEEPOPEN mask_name=1
    loadpointer 0 str_rin_0
    show_mugshot MUGSHOT_RIN alignment=MUGSHOT_RIGHT message_type=MSG_KEEPOPEN mask_name=0
    loadpointer 0 str_teah_1
    show_mugshot MUGSHOT_TEAH alignment=MUGSHOT_RIGHT message_type=MSG_KEEPOPEN mask_name=1
    loadpointer 0 str_rin_1
    show_mugshot MUGSHOT_RIN alignment=MUGSHOT_RIGHT message_type=MSG_KEEPOPEN mask_name=0
    sound 0x15
    applymovement 25 mov_exclam_down
    applymovement 26 mov_exclam_down
    waitmovement 0
    loadpointer 0 str_rin_2
    show_mugshot MUGSHOT_RIN alignment=MUGSHOT_RIGHT message_type=MSG_KEEPOPEN mask_name=0
    closeonkeypress
    setvar 0x8004 0xFF
    setvar 0x8005 0x3D
    setvar 0x8006 0x8
    special SPECIAL_NPC_MOVE_TO
    waitmovement 0
    applymovement 0xFF mov_face_up
    waitmovement 0
    loadpointer 0 str_teah_2
    show_mugshot MUGSHOT_TEAH alignment=MUGSHOT_RIGHT message_type=MSG_KEEPOPEN mask_name=1
    loadpointer 0 str_rin_3
    show_mugshot MUGSHOT_RIN alignment=MUGSHOT_RIGHT message_type=MSG mask_name=0
    fadesong 0
    pause 64
    loadpointer 0 str_narcissa_0
    show_mugshot MUGSHOT_NARCISSA alignment=MUGSHOT_RIGHT message_type=MSG mask_name=1
    sound 0x15
    applymovement 25 mov_exclam_down
    applymovement 25 mov_exclam_down
    applymovement 0xFF mov_exclam_down
    waitmovement 0
    clearflag (15 | 0x8000)
    showsprite 27
    special SPECIAL_OVERWORLD_VIEWPORT_UNLOCK
    applymovement 0x7F mov_camera_down
    waitmovement 0
    playsong MUS_FOREST_CEMETERY 0
    pause 80
    applymovement 0x7F mov_camera_up
    applymovement 27 mov_camera_up
    waitmovement 0
    special SPECIAL_OVERWORLD_VIEWPORT_LOCK
    applymovement 27 mov_narcissa_to_event
    waitmovement 0
    applymovement 0xFF mov_face_left
    waitmovement 0
    loadpointer 0 str_rin_4
    show_mugshot MUGSHOT_RIN alignment=MUGSHOT_RIGHT message_type=MSG_KEEPOPEN mask_name=0
    applymovement 26 mov_face_left
    waitmovement 0
    loadpointer 0 str_teah_3
    show_mugshot MUGSHOT_TEAH alignment=MUGSHOT_RIGHT message_type=MSG_KEEPOPEN mask_name=0
    applymovement 26 mov_face_down
    waitmovement 0
    loadpointer 0 str_narcissa_1
    show_mugshot MUGSHOT_NARCISSA alignment=MUGSHOT_RIGHT message_type=MSG mask_name=0
    sound 0x15
    applymovement 26 mov_exclam_down
    waitmovement 0
    loadpointer 0 str_teah_4
    show_mugshot MUGSHOT_TEAH alignment=MUGSHOT_RIGHT message_type=MSG_KEEPOPEN mask_name=0
    loadpointer 0 str_rin_5
    show_mugshot MUGSHOT_RIN alignment=MUGSHOT_RIGHT message_type=MSG_KEEPOPEN mask_name=0
    loadpointer 0 str_narcissa_2
    show_mugshot MUGSHOT_NARCISSA alignment=MUGSHOT_RIGHT message_type=MSG_KEEPOPEN mask_name=0
    loadpointer 0 str_teah_5
    show_mugshot MUGSHOT_TEAH alignment=MUGSHOT_RIGHT message_type=MSG_KEEPOPEN mask_name=0
    loadpointer 0 str_narcissa_3
    show_mugshot MUGSHOT_NARCISSA alignment=MUGSHOT_RIGHT message_type=MSG_KEEPOPEN mask_name=0
    loadpointer 0 str_rin_6
    show_mugshot MUGSHOT_RIN alignment=MUGSHOT_RIGHT message_type=MSG mask_name=0
    applymovement 0xFF mov_face_down
    applymovement 27 mov_face_down
    waitmovement 0
    setvar 0x8004 25
    setvar 0x8005 0x3c
    setvar 0x8006 0xf
    special SPECIAL_NPC_MOVE_TO
    waitmovement 0
    hidesprite 25
    pause 64
    applymovement 0xFF mov_face_up
    applymovement 27 mov_face_up
    waitmovement 0
    loadpointer 0 str_teah_6
    show_mugshot MUGSHOT_TEAH alignment=MUGSHOT_RIGHT message_type=MSG_KEEPOPEN mask_name=0
    loadpointer 0 str_narcissa_4
    show_mugshot MUGSHOT_NARCISSA alignment=MUGSHOT_RIGHT message_type=MSG mask_name=0
    sound 0x15
    applymovement 27 mov_exclam_right
    waitmovement 0
    loadpointer 0 str_narcissa_5
    show_mugshot MUGSHOT_NARCISSA alignment=MUGSHOT_RIGHT message_type=MSG_KEEPOPEN mask_name=0
    applymovement 0xFF mov_face_left
    waitmovement 0
    loadpointer 0 str_player_0
    show_mugshot MUGSHOT_PLAYER alignment=MUGSHOT_RIGHT message_type=MSG_KEEPOPEN mask_name=0
    applymovement 0xFF mov_face_up
    waitmovement 0
    loadpointer 0 str_teah_7
    show_mugshot MUGSHOT_TEAH alignment=MUGSHOT_RIGHT message_type=MSG_KEEPOPEN mask_name=0
    applymovement 0xFF mov_face_left
    waitmovement 0
    loadpointer 0 str_narcissa_6
    show_mugshot MUGSHOT_NARCISSA alignment=MUGSHOT_RIGHT message_type=MSG_KEEPOPEN mask_name=0
    applymovement 0xFF mov_face_up
    waitmovement 0
    loadpointer 0 str_teah_8
    show_mugshot MUGSHOT_TEAH alignment=MUGSHOT_RIGHT message_type=MSG mask_name=0
    applymovement 0xff mov_face_down
    applymovement 27 mov_face_down
    waitmovement 0
    setvar 0x8004 26
    setvar 0x8005 0x3d
    setvar 0x8006 0xf
    special SPECIAL_NPC_MOVE_TO
    waitmovement 0
    hidesprite 26
    pause 40
    applymovement 0xFF mov_face_left
    applymovement 27 mov_face_right
    waitmovement 0
    loadpointer 0 str_narcissa_7
    show_mugshot MUGSHOT_NARCISSA alignment=MUGSHOT_RIGHT message_type=MSG mask_name=0
    setvar 0x8004 27
    setvar 0x8005 0x3c
    setvar 0x8006 0xf
    special SPECIAL_NPC_MOVE_TO
    waitmovement 0
    hidesprite 27
    setflag FLAG_FOREST_CEMETERY_DONE
    addvar STORY_PROGRESS 1
    release
    end
mov_exclam_down:
    .byte LOOK_DOWN, SAY_EXCLAM, STOP
mov_face_up:
    .byte LOOK_UP, STOP
mov_face_left:
    .byte LOOK_LEFT, STOP
mov_face_down:
    .byte LOOK_DOWN, STOP
mov_camera_down:
    .byte STEP_DOWN, STEP_DOWN, STEP_DOWN, STEP_DOWN, STEP_DOWN, STOP
mov_camera_up:
    .byte STEP_UP, STEP_UP, STEP_UP, STEP_UP, STEP_UP, STOP
mov_narcissa_to_event:
    .byte STEP_UP, STEP_UP, STOP
mov_exclam_right:
    .byte LOOK_RIGHT, SAY_EXCLAM, STOP
mov_face_right:
    .byte LOOK_RIGHT, STOP

.ifdef LANG_GER
str_teah_0:
    .autostring 34 2 "Und du bist der Meinung, dass du mir Befehle erteilen kannst, Mädchen?"
str_rin_0:
    .autostring 34 2 "Weißt du, mit wem du es zu tun hast?\pDu magst zwar eine Arenaleiterin sein, aber gegen unsere zahlenmäßige Übermacht kannst du nichts ausrichten.\pEin Wink von mir und meine Rüpel legen machen aus deinem Wald und seinem ach so schönen Friedhof ein Leuchtfeuer!"
str_teah_1:
    .autostring 34 2 "Du kannst so viel drohen, wie du möchtest, aber ich besitze die Gabe in die Zukunft zu sehen.\pUnd dieser Wald, er wird noch viele Jahrhunderte erhalten bleiben.\pHierher zu kommen war ein großer Fehler."
str_rin_1:
    .autostring 34 2 "Du kleine Hexe!\pDu bist so überzeugt von dir.\pAber was willst du schon ausrichten?\pIch verlange doch gar nicht viel von dirDOTS\pSag mir einfach, wo diese untergegangene Stadt liegt und wir haben keine Schwierigkeiten.\pWas meinst du?"
str_rin_2:
    .autostring 34 2 "PLAYER!\nDu schon wieder.\pWir haben uns lange nicht gesehen.\pUnd es ist noch eine offene Rechnung, die zwischen uns steht, nicht, du Rotzgöre?"
str_teah_2:
    .autostring 34 2 "Wer bist du denn?\pBist du ein Verbündeter dieser schrecklich heißblütigen Frau hier?\pHabt ihr keinen Anstand, diesen Ort des Friedens so zu entweihen?\pIch bin Teah, die Arenaleiterin von Ceometria.\pUnd als solche werde ich all denen, die diesen Ort entehren, mit ganzer Kraft engegentreten."
str_rin_3:
    .autostring 34 2 "Ein Verbündeter?\pDieses Kind hier hat mir schon einmal einen Strich durch die Rechnung gemacht.\pEin zweites Mal, werde ich das nicht zulassen.\pUnsere liebe Teah hier weigert sich nämlich, zu kooperieren.\pNur, wenn sie mir nicht sagt, wo ich die versunkene Stadt finde, werde ich ihren geliebten Waldfriedhof zu einem netten kleinen Lagerfeuer umfunktionieren."
str_narcissa_0:
    .autostring 34 2 "Du klingst wie immer lächerlich, Rin."
str_rin_4:
    .autostring 34 2 "Narzissa?\nWas willst du denn hier?"
str_teah_3:
    .autostring 34 2 "Wie ich es dir vorhergesagt hatte, bist du chancenlos.\pJetzt wo Narzissa, ein Mitglied der Top Vier, hier ist, wirst du gar nichts mehr ausrichten können, du vorlautes Mädchen!"
str_narcissa_1:
    .autostring 34 2 "Was ich hier tue, meine kleine Rin?\pDies hier ist mein Herrschaftsbereich und Teah ist eine meiner engsten Freundinnen.\pIch sollte eher dich fragen, was du hier willst.\pDu bist auch nach all den Jahren kein Stück besser geworden.\pDeiner kleiner trotziger Feldzug mit diesem Violet AbschaumDOTS\pWas denkst du dir nur bei solchen Dummheiten, kleine Schwester?"
str_teah_4:
    .autostring 34 2 "Wiebitte?\nDiese abscheuliche Frau ist deine Schwester, Narzissa?\pWie kann denn soetwas sein?"
str_rin_5:
    .autostring 34 2 "Ja, unsere große perfekte Narzissa hier, sie ist meine Schwester.\pNicht jeder kann so perfekt sein, wie sie, nicht wahr?\pOh, wie schändlich bin ich doch in ihrem Schatten, ihrem großen großen Diva-Schatten!\pIch werde dir etwas sagen, Zissy.\pDass du eine der Top Vier bist, interessiert mich nicht.\pWas du tust, interessiert mich ebenfalls nicht.\pDu warst nie eine große Schwester für michDOTS\pUnd ich habe für dich nicht das Geringste übrig!"
str_narcissa_2:
    .autostring 34 2 "Du bist immer noch das trotzige kleine Gör von früher.\pWenn du etwas nicht haben kannst, dann willst du alles andere um dich herum zerstören.\pDu warst schon immer schrecklich Rin.\pWas hast du denn vor?\pWillst du gegen mich kämpfen und ein weiteres Mal verlieren?"
str_teah_5:
    .autostring 34 2 "Diese Verrückte wollte mich dazu bringen, ihr zu verraten, wo irgendeine versunkene Stadt liegen soll.\pIch habe nichts für Seefahrer-Märchen übrig, aber selbst wenn ich es wüsste, hätte ich dieser grauenvollen Frau nichts gesagt.\pIch bin furchtlos, auch im Angesicht eines Team Violet Vorstandes."
str_narcissa_3:
    .autostring 34 2 "Der Titel eines Team Violet Vorstandes wird maßlos überschätzt.\pEs sollen ja nun schon Kinder herum laufen, die diesen erbärmlichen Schurken zeigen, wo es langgeht.\pUnd dass du dich nun mit solchen Dummheiten wie versunkenen Städten beschäftigst, bestätigt nur ein weiteres Mal, dass aus dir nie etwas werden wird.\pDu bist eine Schande für unsere Familie."
str_rin_6:
    .autostring 34 2 "DOTS DOTS DOTS DOTS DOTS DOTS\nDOTS DOTS DOTS DOTS DOTS DOTS\pIch bilde mir nicht ein, dass ich dich hier besiegen kann, Narzissa.\pUnd auch wenn du mein Vorhaben für lächerlich hältstDOTS\pDu siehst nur das große Bild nicht.\pWir werden schon bald im Besitz einer so schrecklichen Waffe sein, dass selbst ihr von den Top Vier völlig machtlos dastehen werdet.\pJa, und mit dieser Waffe, werde ich dir dann alles heimzahlen!\pAll die Jahre immer die nutzlose kleine Schwester seinDOTS\pDOTSDu wirst schon sehen, was du davon hast, Zissy!"
str_teah_6:
    .autostring 34 2 "NarzissaDOTS\pHättest du sie nicht aufhalten sollen?\pImmerhin hat sie sich viel zu Schulden kommen lassen.\pSie laufen zu lassenDOTS\nDOTSich sehe voraus, dass das keine gute Entscheidung warDOTS"
str_narcissa_4:
    .autostring 34 2 "Du überschätzt meine kleine Schwester.\pSo großartig ich bin, so niederträchtig ist sie.\pAußer großen Tönen bringt sie nicht viel zustande.\pSoll sich jemand anderes um sie kümmernDOTS"
str_narcissa_5:
    .autostring 34 2 "Huch?\nDas Kind hier habe ich ja gar nicht bemerkt.\pWer bist du denn bitte nun?"
str_player_0:
    .autostring 34 2 "Mein Name ist PLAYER und ich habe Rin bereits zuvor besiegt.\pIch werde Team Violet aufhalten."
str_teah_7:
    .autostring 34 2 "Du bist das Kind, das Rin im Silvania-Wald besiegt hat?\pUnd auch das legendäre Pokémon Groudon sollst du bezwungen haben.\pIch habe deine Ankunft vorhergesehen.\pDu wirst einen interessanten Gegner abgeben."
str_narcissa_6:
    .autostring 34 2 "PLAYER also.\pJa, der Name kommt mir nicht unbekannt vor.\pWie schön, dass du dich Team Violets annimmst.\pJemand, der in der Lage ist, ein legendäres Pokémon zu besiegen, kann es weit bringen.\pDu könntest dir von meiner Großartigkeit einiges abschauen!"
str_teah_8:
    .autostring 34 2 "EigenartigDOTS\nIch kann für PLAYER keine Zukunft erkennenDOTS\pAls würde etwas meinen Blick trübenDOTS\pBesitzt du etwa kein Schicksal?\pDu bist eine interessante Person.\pIch erwarte dich in meiner Arena.\pIch rechne damit, dass du mir einen würdigen Kampf liefern wirst."
str_narcissa_7:
    .autostring 34 2 "Es kann frustrierend sein, jemandem wie mir nachzueifern.\pGröße und Eleganz sind unter anderem auch angeboren.\pRin besitzt sie beide nicht.\pAber duDOTS\nDOTSdu könntest eines Tages vielleicht sogar bei uns großen Trainern mitspielen, wer weißDOTS\pAm Besten hältst du Rin auf, bevor sie ihre versunkene Stadt findet.\pWer weiß, was für niederträchtige Pläne diese Gruppe hat."

.elseif LANG_EN
str_teah_0:
    .autostring 34 2 "So, you think that you can give orders to me, girl?"
str_rin_1:
    .autostring 34 2 "Do you know who you are talking to?\pYou may be a gym leader, but against our numbers you are without any chance.\pOne whim of mine and my grunts will turn your forest and its beloved cemetery into a nice little bonfire!"
str_teah_1:
    .autostring 34 2 "You can threaten me as much as you like, but I possess the gift of future sight.\pAnd this forest, it will remain alive for many years.\pIt was a great mistake for you to come here."
str_rin_1:
    .autostring 34 2 "You little witch!\pYou are so full of yourself.\pBut what can you even do?\pI don not demand much!\pJust tell me where the sunken city lies and we won't have any problems.\pWhat do you say?"
str_rin_2:
    .autostring 34 2 "PLAYER!\nYou again.\pLong time no see.\pAnd we still have open issues to settle, right, you little brat?"
str_teah_2:
    .autostring 34 2 "And who are you?\pAre you an ally of this terribly heated women?\pDon't you have no decency to descrate this holy place of peace?\pI am Teah, the Gymleader of Ceometria, and with those who are indecent on this holy ground I will have no mercy."
str_rin_3:
    .autostring 34 2 "An ally?\pThis child here has interfered with my plans once.\pA second time this won't happen, I guarantee you that.\pOur beloved Teah here is unwilling to cooperate.\pBut, if she refuses to tell me where to find the sunken city, I will turn her beloved Forest Cemeterey into a nice little campfire."
str_narcissa_0:
    .autostring 34 2 "As always, you sound ridiculous, Rin."
str_rin_4:
    .autostring 34 2 "Narcissa?\pWhat do you want here?"
str_teah_3:
    .autostring 34 2 "As I foresaw it, you have no chances.\pNow that Naricissa of the Elite Four is here, you won't be able to do anything, you insolent girl!"
str_narcissa_1:
     .autostring 34 2 "What I am doing here, my little Rin?\pThis is my territory and Teah happens to be one of my closest friends.\pI should rather ask what in the world you are doing here.\pEven after all this years you have not grown better the slightest.\pYour little defiant campaign alongside this Violet scumDOTS\pWhat are you thinking, little sister?"
str_teah_4:
    .autostring 34 2 "Come again?\nThis terrible woman is your sister, Narcissa?\pHow can something like that be a thing?"
str_rin_5:
    .autostring 34 2 "Yes, our great perfect Narcissa here, she is my sister.\pNot everyone can be as perfect as she is, am I right?\pOh, how shameful am I in her shadow, her great great diva-shadow!\pI will tell you something, Cissy.\pI don't care that you are one of the Elite Four.\pI don't care about what you are doing either.\pYou never were a big sister to meDOTS\pAnd I don't care about you at all!"
str_narcissa_2:
    .autostring 34 2 "You still are that little defiant brat from years ago.\pWhen you can't have something, you want to destroy everything else arround.\pYou have always been a terrible person.\pWhat is your plan?\pDo you want to battle me once again and lose another time?"
str_teah_5:
    .autostring 34 2 "This crazy women here wanted to make me tell her about the whereabouts of some sunken city.\pI don't care about pirate-fairytales, and even if I knew about it, I wouldn't have told this awful women anything at all.\pI am without fear, even in the face of a Team Violet executive."
str_narcissa_3:
    .autostring 34 2 "The title of a Team Violet executive is highly overrated.\pIt is said that even children are able to put these pityful evildoers into their places.\pAnd the fact that you are working on some nonesense like sunken cities only proves once more that you will never get anywhere.\pYou are the black sheep of our family."
str_rin_6:
    .autostring 34 2 "DOTS DOTS DOTS DOTS DOTS DOTS\nDOTS DOTS DOTS DOTS DOTS DOTS\pI don't think that I can defeat you here, Narcissa.\pAnd even if you think of my plans as sillyDOTS\pYou just can't see the greater picture.\pSoon we will be in posession of a terrible weapon, such that even you of the Elite Four will be without any chance.\pYes, and with this weapon I will give you a nice payback!\pAll these years of being the useles little sisterDOTS\pDOTSYou will see what you will get from that, Cissy!"
str_teah_6:
    .autostring 34 2 "NarcissaDOTS\pShouldn't you have stopped her?\pShe has done much bad in the last time.\pTo let her runDOTS\nDOTSI foresee that this was not a good decisionDOTS"
str_narcissa_4:
    .autostring 34 2 "You overestimate my little sister.\pAs much as I am great she is despicable.\pApart from big talk she has not much done in her life.\pSomebody else take her of herDOTS"
str_narcissa_5
    .autostring 34 2 "Huh?\nThis child here I did not even notice.\pWho are you now?"
str_player_0:
    .autostring 34 2 "My name is PLAYER and I have defeated Rin once before.\pI will stop Team Violet."
str_teah_7:
    .autostring 34 2 "You are the child that defeated Rin in the Silvania-Forest?\pAnd also it is said that you overcame the legendary Pokémon Groudon.\pI have forseen your arrival.\pYou will make an interesting opponent."
str_narcissa_6:
    .autostring 34 2 "PLAYER it is.\pYes, this name is not entirely unknown to me.\pHow nice of you to take on Team Violet.\pSomeone who was able to defeat a legendary Pokémon surely has some potential.\pYou could learn a lot of my greatness!"
str_teah_8:
    .autostring 34 2 "How curiousDOTS\nI can't see your future, PLAYERDOTS\pIt's like something would darken my sight.\pDon't you have a destiny?\pYou are an interesting person.\pI await you in my gym.\pI know that you will provide me with a proper fight!"
str_narcissa_7:
    .autostring 34 2 "It can be frustrating to emulate somebody like me.\pPeople are partly born with greatness and elegance.\pRin doesn't have either of those.\pYou on the other sideDOTS\nDOTSyou could one day even play with us great trainers, who knowsDOTS\pThe best would be to stop Rin before she finds her sunken city.\pWho knows what spiteful schemes this Team Violet group has woven."
.endif
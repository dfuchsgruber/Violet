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
    hidesprite 23
    hidesprite 24
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
    .autostring 34 2 "Ein Verbündeter?\pDieses Kind hier hat mir schon einmal einen Strich durch die Rechnung gemacht.\pEin zweites Mal, werde ich das nicht zulassen."
str_narcissa_0:
    .autostring 34 2 "Du klingst wie immer lächerlich, Rin."
str_rin_4:
    .autostring 34 2 "Narzissa?\nWas willst du denn hier?"
str_teah_3:
    .autostring 34 2 "Wie ich es dir vorhergesagt hatte, bist du chancenlos.\pJetzt wo Narzissa, ein Mitglied der Top Vier, hier ist, wirst du gar nichts mehr ausrichten können, du vorlautes Mädchen!"
str_narcissa_1:
    .autostring 34 2 "Was ich hier tue, liebe Rin?\pDas selbe könnte ich dich fragen!\pIch bin ein Mitglied der Top Vier und das hier ist mein Herrschaftsbereich.\pDOTS DOTS DOTS DOTS\nDOTS DOTS DOTS\pAuch nach all den Jahren hast du dich kein Stück verändert.\pDu bist immer noch das selbe trotzige Kind, das um sich schlägt, wenn es etwas nicht haben kann.\pWas denkst du dir dabei, dich diesem Team Violet Abschaum anzuschließen, kleine Schwester?"
str_teah_4:
    .autostring 34 2 "Wiebitte?\nDiese abscheuliche Frau ist deine Schwester, Narzissa?\pWie kann denn soetwas sein?"
str_rin_5:
    .autostring 34 2 "Ja, die perfekte, großartige Narzissa hierDOTS\pDOTSsie ist meine Schwester.\pAber nicht jeder kann so ein unvergleichlich atemberaubender Mensch sein, nicht wahr?\pMeine Schwester hat Zeit ihres Lebens geglänzt.\pDer Schatten, den sie geworfen hatDOTS\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pIch sage dir etwas, Zissy!\pDass du Teil der Top Vier bist, interessiert mich nicht.\pUm ehrlich zu sein, könnte mich auf dieser Welt nichts weniger interessieren."
str_narcissa_2:
    .autostring 34 2 "Was?\nWillst du etwa gegen mich kämpfen und ein weiteres Mal verlieren?\pIch kann schon nicht mehr mitzählen, wie viele Niederlagen ich dir schon beigebracht habe.\pDu bist ein schrecklicher Mensch und eine noch schrecklichere Trainerin.\pMach dich nicht lächerlich."
str_teah_5:
    .autostring 34 2 "Deine Schwester hat mir von Seefahrer-Märchen und irgendeiner versunkenen Stadt erzählt.\pSie wollte, dass ich meine hellseherischen Gaben nutze, herauszufinden, wo sich diese befindet.\pSelbst wenn ich das könnte, hätte ich ihr nichts gesagt.\pVon einer solchen Göre lasse ich mich nicht einschüchtern."
str_narcissa_3:
    .autostring 34 2 "Der Titel eines Team Violet Vorstandes wird maßlos überschätzt.\pEs sollen ja nun schon Kinder herum laufen, die diesen erbärmlichen Schurken zeigen, wo es langgeht.\pUnd dass du dich nun mit solchen Dummheiten wie versunkenen Städten beschäftigst, bestätigt nur ein weiteres Mal, dass aus dir nie etwas werden wird.\pDu bist eine Schande für unsere Familie."
str_rin_6:
    .autostring 34 2 "DOTS DOTS DOTS DOTS DOTS DOTS\nDOTS DOTS DOTS DOTS DOTS DOTS\pIch bilde mir nicht ein, dass ich dich hier besiegen kann, Narzissa.\pUnd auch wenn du mein Vorhaben für lächerlich hältstDOTS\pDu siehst nur das große Bild nicht.\pWir werden schon bald im Besitz einer so schrecklichen Waffe sein, dass selbst ihr von den Top Vier völlig machtlos dastehen werdet.\pUnd dann wird sich, ganz schlagartig, das Blatt endlich wenden, Zissy."
str_teah_6:
    .autostring 34 2 "NarzissaDOTS\pHättest du sie nicht aufhalten sollen?\pImmerhin hat sie sich viel zu Schulden kommen lassen.\pSie laufen zu lassenDOTS\nDOTSich sehe voraus, dass das keine gute Entscheidung warDOTS"
str_narcissa_4:
    .autostring 34 2 "Du überschätzt meine kleine Schwester.\pSie hat nichts von meiner Anmut oder Stärke.\pSie ist völlig harmlos, auch wenn sie große zornige Reden schwingt."
str_narcissa_5:
    .autostring 34 2 "Huch?\nDas Kind hier habe ich ja gar nicht bemerkt.\pWer bist du denn bitte nun?"
str_player_0:
    .autostring 34 2 "Mein Name ist PLAYER und ich habe Rin bereits zuvor besiegt."
str_teah_7:
    .autostring 34 2 "Du bist das Kind, das Rin im Silvania-Wald besiegt hat?\pStimmt es, dass du einen Kampf gegen das legendäre Pokémon Groudon bestritten hast?\pMerkwürdig, dass ich deine Ankunft nicht kommen gesehen habeDOTS"
str_narcissa_6:
    .autostring 34 2 "PLAYER also!\pJa, diesen Namen habe ich in letzter Zeit häufiger gehört.\pDu bist ein Schüler vom alten Faun, nicht wahr?\pDu sorgst für reichlich aufsehen.\pJemand mit deiner Ausstrahlung könnte es weit bringen!"
str_teah_8:
    .autostring 34 2 "EigenartigDOTS\pIch kann deine Zukunft nicht erkennen.\pEs ist, als besäßest du überhaupt kein Schicksal.\pWie interessant.\pIch bin wirklich neugierig, ob du deinem Ruf gerecht wirst, PLAYER.\pDu willst mich sicher in einem Kampf herausfordern, und diesem Wunsch werde ich nachkommen.\pIch erwarte dich in der Arena von Ceometria."
str_narcissa_7:
    .autostring 34 2 "Hab etwas Nachsicht mit Rin.\pEs ist nicht leicht, jemanden, der so brilliant und charismatisch ist, zur großen Schwester zu haben.\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pAllerdings bin ich vielleicht etwas nachlässig gewesen.\pVielleicht sollte ich doch einmal im Auge behalten, was meine Schwester vorhatDOTS\pIch bin gespannt auf unser nächstes Treffen, PLAYER.\pLass dir nur den Rat geben, dich nicht zu überschätzen!\pUm in meiner Liga mitzuspielen, bist du  noch viel zu schwach.\pAdieu!"

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
    .autostring 34 2 "What I am doing here, beloved Rin?\pI could ask you the same!\pI am a member of the Elite Four and this is my dominion.\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pYou are just the way you were back then.\pJust a little child that goes insane when it can't have its way.\pYou haven't changed a bit.\pWhat did you think joining this Team Violet scum, little sister?"
str_teah_4:
    .autostring 34 2 "Come again?\nThis terrible woman is your sister, Narcissa?\pHow can something like that be a thing?"
str_rin_5:
    .autostring 34 2 "Yes, the perfect, great Narcissa hereDOTS\pDOTSshe is my sister.\pBut not everbody can be such a breathtaking being, am I right?\pMy sister has always shined, for her entire life.\pThe shadow she threwDOTS\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pI tell you something, Cissy!\pI don't care that you are a member of the Elite Four.\pTo be quite frank, there isn't much I could care less about."
str_narcissa_2:
    .autostring 34 2 "Hu?\nDo you want to challange me and lose another time?\pI can't even count anymore how many defeats you have suffered already against me.\pYou are a terrible person and a even terrible trainer.\pDon't embarras yourself even further."
str_teah_5:
    .autostring 34 2 "Your sister told me something about pirate-fairytales and a sunken city.\pShe wanted me to use my abilities to locate this legendary place.\pEven if was able to do that, I wouldn't have told her a thing.\pI won't be intimedated by such a little lass!"
str_narcissa_3:
    .autostring 34 2 "The title of a Team Violet executive is highly overrated.\pIt is said that even children are able to put these pityful evildoers into their places.\pAnd the fact that you are working on some nonesense like sunken cities only proves once more that you will never get anywhere.\pYou are the black sheep of our family."
str_rin_6:
    .autostring 34 2 "DOTS DOTS DOTS DOTS DOTS DOTS\nDOTS DOTS DOTS DOTS DOTS DOTS\pI don't think that I can defeat you here, Narcissa.\pAnd even if you think of my plans as sillyDOTS\pYou just can't see the greater picture.\pSoon we will be in posession of a terrible weapon, such that even you of the Elite Four will be without any chance.\pAnd then, all of a sudden, the tables will have turned, Cissy!"
str_teah_6:
    .autostring 34 2 "NarcissaDOTS\pShouldn't you have stopped her?\pShe has done much bad in the last time.\pTo let her runDOTS\nDOTSI foresee that this was not a good decisionDOTS"
str_narcissa_4:
    .autostring 34 2 "You overestimate my little sister.\pShe hasn't got any of my grace or strength.\pShe is totally harmless even though she likes to give angry speeches."
str_narcissa_5
    .autostring 34 2 "Huh?\nThis child here I did not even notice.\pWho are you now?"
str_player_0:
    .autostring 34 2 "My name is PLAYER and I have defeated Rin once before."
str_teah_7:
    .autostring 34 2 "You are the child that defeated Rin in the Silvania-Forest?\pIs it true that you fought a battle against the legendary Pokémon Groudon?\pHow strange that I have not foressen your arrival."
str_narcissa_6:
    .autostring 34 2 "PLAYER it is!\pYes, I heard of this name a lot recently.\pYou are a pupil of the old faun, aren't you?\pYou gathered a lot of attention in the recent past.\pSomeone with your charisma could make it to the top!"
str_teah_8:
    .autostring 34 2 "How oddDOTS\pI can't foresee your future.\pIt is as if your destiny wasn't decided yet.\pHow very interesting\pI am genuinely curious if you can live up to your reputation, PLAYER.\pYou probably wan't to challange me to a battle and I am willing to fulfil this wish of yours.\pI will be waiting for you in the gym of Ceometria."
str_narcissa_7:
    .autostring 34 2 "Be lenient with Rin.\pIt isn't easy to have someone this brilliant and charismatic as a great sister.\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pThen again, maybe I wasn't strict enough.\pMaybe I should keep an eye on what my sister is plottingDOTS\pI am already looking forward when we meet the next time, PLAYER.\pLet me give you this piece of advice however to not overestimate yourself.\pTo play in my league you are still way too weak.\pAdieu!"
.endif
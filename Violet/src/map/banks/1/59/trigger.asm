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

.global ow_script_tafelberg_trigger_felix

ow_script_tafelberg_trigger_felix:
    lockall
    pause 32
    sound 0x15
    applymovement 13 mov_fd
    waitmovement 0
    applymovement 13 mov_exclam
    waitmovement 0
    npc_move_to_player 13
    applymovement 13 mov_fd
    waitmovement 0
    lockall
    loadpointer 0 str_f0
    show_mugshot MUGSHOT_FELIX MUGSHOT_LEFT message_type=MSG_KEEPOPEN hide_mugshot=0
    update_mugshot_emotion MUGSHOT_ANGRY
    loadpointer 0 str_f1
    callstd MSG_KEEPOPEN
    update_mugshot_emotion MUGSHOT_HAPPY
    loadpointer 0 str_f2
    callstd MSG_KEEPOPEN
    update_mugshot_emotion MUGSHOT_NORMAL
    loadpointer 0 str_f3
    callstd MSG_KEEPOPEN
    update_mugshot_emotion MUGSHOT_RUMINATIVE
    loadpointer 0 str_f4
    callstd MSG_KEEPOPEN
    update_mugshot_emotion MUGSHOT_NORMAL
    loadpointer 0 str_f5
    callstd MSG_KEEPOPEN
    hide_mugshot
    closeonkeypress
    // npc_move_to 13 0x37 0x11 waitmovement=1
    applymovement 13 mov_6u
    waitmovement 0
    hidesprite 13
    addvar STORY_PROGRESS 1
    releaseall
    end

.ifdef LANG_GER
str_f0:
    .autostring 34 2 "Hey, PLAYER!\pWie immer kommst du zum perfekten Zeitpunkt."
str_f1:
    .autostring 34 2 "Mir liegt es immer noch schwer im Magen, dass wir die Team Violet Kommandantin im Zeitwald nicht geschnappt habenDOTS"
str_f2:
    .autostring 34 2 "Aber es scheint so, als würden wir hier eine zweite Chance bekommen!"
str_f3:
    .autostring 34 2 "Hier lungern überall Leute von der Revolutionsbewegung herum.\pDieses Pack will die Pokémon-Liga stürzen und die Region in einen Bürgerkrieg stoßen.\pAls Polizist kann ich das natürlich nicht zulassen.\pUnd gerade als Schüler von Opi, einem Mitglied der Top Vier, ist es quasi unsere Pflicht, diese Unruhestifter in die Schranken zu weisen, meinst du nicht?"
str_f4:
    .autostring 34 2 "Ich frage michDOTS\pDOTSob wir vielleicht sogar ein hochrangiges Mitglied dieser Bewegung dingfest machen könnenDOTS"
str_f5:
    .autostring 34 2 "Lass uns am Besten keine Zeit verlieren!"
.elseif LANG_EN
.endif

.global ow_script_tafelberg_trigger_battle

ow_script_tafelberg_trigger_battle:
    lockall
    loadpointer 0 str_0
    show_mugshot MUGSHOT_FELIX MUGSHOT_LEFT message_type=MSG_KEEPOPEN
    closeonkeypress
    sound 0x15
    applymovement 43 mov_fu
    waitmovement 0
    applymovement 43 mov_exclam
    waitmovement 0
    checksound
    loadpointer 0 str_1
    show_mugshot MUGSHOT_FELIX MUGSHOT_LEFT message_type=MSG_KEEPOPEN
    closeonkeypress
    npc_move_to 0xFF 0x24 0x22 waitmovement=1
    applymovement 43 mov_fd
    waitmovement 0
select:
    loadpointer 0 str_select
    callstd MSG_KEEPOPEN
    special SPECIAL_SELECT_HALF_PARTY
    waitstate
    compare LASTRESULT 0
    gotoif EQUAL have_to_select
    setvar SONG_OVERRIDE 0
    setvar VAR_ALLY 0x169
    special SPECIAL_ALLY_BATTLE_SAVE_AND_SETUP_PARTY
    applymovement 43 mov_fl
    waitmovement 0
    loadpointer 0 str_lets_go
    show_mugshot MUGSHOT_FELIX MUGSHOT_LEFT
    applymovement 43 mov_fd
    waitmovement 0
    pause 32
// goto after_battle
    playsong MUS_REVOLUTION 0
    loadpointer 0 str_revo
    setvar 0x8000 MUGSHOT_RIGHT
    special SPECIAL_NAME_SHOW
    setvar SONG_OVERRIDE MUS_REVOLUTION
    trainerbattleallytwotrainers 0x16A 0x1c0 0x169 42 TRAINER_BACKSPRITE_FELIX 1 str_before str_after1 str_after2 after_battle
after_battle:
    msgbox_with_name str_2 str_revo alignment=MUGSHOT_RIGHT message_type=MSG
    applymovement 42 mov_revo1_to_albus
    applymovement 9 mov_revo1_to_albus
    waitmovement 0
    applymovement 42 mov_fr
    waitmovement 0
    fadesong MUS_ROUTE_24_25
    pause 16
    applymovement 0xFF mov_fr
    applymovement 43 mov_fl
    loadpointer 0 str_3
    show_mugshot MUGSHOT_FELIX MUGSHOT_LEFT message_type=MSG_KEEPOPEN emotion=MUGSHOT_RUMINATIVE
    closeonkeypress
    sound 0x15
    applymovement 43 mov_fd
    waitmovement 0
    applymovement 43 mov_exclam
    waitmovement 0
    loadpointer 0 str_4
    show_mugshot MUGSHOT_FELIX MUGSHOT_LEFT message_type=MSG_KEEPOPEN emotion=MUGSHOT_SHOCKED
    closeonkeypress
    applymovement 43 run_to_faun
    waitmovement 0
    addvar STORY_PROGRESS 1
    setvar SONG_OVERRIDE 0
    releaseall
    end

have_to_select:
    applymovement 43 mov_fl
    waitmovement 0
    loadpointer 0 str_have_to_select
    show_mugshot MUGSHOT_FELIX MUGSHOT_LEFT
    goto select

mov_revo1_to_albus:
    .byte STEP_LEFT, STEP_LEFT, STEP_LEFT, STEP_DOWN, STOP
run_to_faun:
    .byte STEP_DOWN_FAST, STEP_DOWN_FAST, STEP_LEFT_FAST, STEP_LEFT, LOOK_DOWN, STOP

.ifdef LANG_GER
str_0:
    .autostring 34 2 "So, jetzt geht es ans Eingemachte!\pIm Namen der Polizei von Theto und der Pokémon-LiagDOTS\pSeid ihr hiermit verhaf-"
str_1:
    .autostring 34 2 "Da bist du ja endlich, PLAYER!\pIch bin gerade im Begriff, diese beiden Revolutionäre festzunehmen.\pLass uns doch gemeinsam gegen sie kämpfen, was sagst du?"
str_select:
    .autostring 34 2 "Welche Pokémon willst du in den Kampf schicken?"
str_have_to_select:
    .autostring 34 2 "Hey, PLAYER!\pDu machst wohl Scherze, oder?\pLass uns diesen Revolutionären in den Hintern treten."
str_before:
    .autostring 34 2 "Hey, du Grünschnabel willst ein Polizist sein?\pMit euch werden wir im Handumdrehen fertig!"
str_after1:
    .autostring 34 2 "Das war eine AbreibungDOTS"
str_after2:
    .autostring 34 2 "Hab ich euch wohl unterschätztDOTS\pAber das spielt keine RolleDOTS"
str_lets_go:
    .autostring 34 2 "Also gut, PLAYER!\pGib dein Bestes, ja?"
str_revo:
    .string "Revolutionär"
str_2:
    .autostring 34 2 "Pah!\nNa gut, ihr habt uns besiegtDOTS\pAber das nützt euch gar nichtsDOTS\pDenn gegen unseren Anführer könnt ihr gar nichts ausrichten!"
str_3:
    .autostring 34 2 "Was haben diese Revolutionäre da gesagt?"
str_4:
    .autostring 34 2 "Schau mal drüben!\pDa ist ja Opi!"
.elseif LANG_EN
.endif

/* 


.global ow_script_0x93a667
.global ow_script_0x92d67a
.global ow_script_0x92dc84
.global ow_script_0x941cae
.global ow_script_0x92df8a
.global ow_script_0x9283a5
.global ow_script_kuestenberg_event

ow_script_kuestenberg_event:
    applymovement 13 mov_fl
    pause 16
    applymovement 13 mov_fr
    pause 32
    sound 0x15
    applymovement 13 mov_fd_exclam
    waitmovement 0
    checksound
    pause 32
    npc_move_to_player 13
    applymovement 13 mov_fd
    waitmovement 0
    loadpointer 0 str_0
    show_mugshot MUGSHOT_FELIX MUGSHOT_LEFT
    npc_move_to 13 0x1F 0xE waitmovement=0
    npc_move_to 0xFF 0x1F 0xF waitmovement=0
    waitmovement 0
    applymovement 0xFF mov_fl
    applymovement 13 mov_fl
    pause 32
    sound 0x15
    applymovement 24 mov_fr_exclam
    applymovement 10 mov_fr_exclam
    waitmovement 0
    checksound
    playsong MUS_REVOLUTION 0
    pause 32
    msgbox_with_name str_1 str_revo alignment=MUGSHOT_RIGHT message_type=MSG
    pause 16
    applymovement 13 mov_fd
    applymovement 0xFF mov_fu
    waitmovement 0
    loadpointer 0 str_2
    show_mugshot MUGSHOT_FELIX MUGSHOT_LEFT
    setvar SONG_OVERRIDE MUS_REVOLUTION
select:
    setflag TRANS_DISABLE
    clearflag TRANS_PALETTE_FETCH
    loadpointer 0 str_select
    callstd MSG_KEEPOPEN
    special SPECIAL_SELECT_HALF_PARTY
    waitstate
    clearflag TRANS_DISABLE
    compare LASTRESULT 0
    gotoif EQUAL have_to_select
    setvar SONG_OVERRIDE 0
    setvar VAR_ALLY 0x169
    special SPECIAL_ALLY_BATTLE_SAVE_AND_SETUP_PARTY
    loadpointer 0 str_lets_go
    show_mugshot MUGSHOT_FELIX MUGSHOT_LEFT
    applymovement 0xFF mov_fl
    applymovement 13 mov_fl
    applymovement 24 mov_d_fr
    applymovement 10 mov_2u_fr
    waitmovement 0
// goto after_battle
    loadpointer 0 str_revo
    setvar 0x8000 MUGSHOT_RIGHT
    special SPECIAL_NAME_SHOW
    trainerbattleallytwotrainers 0x16A 0x6e 0x169 43 TRAINER_BACKSPRITE_FELIX 1 str_before str_after1 str_after2 after_battle
after_battle:
    applymovement 13 mov_fd
    applymovement 0xFF mov_fu
    waitmovement 0
    loadpointer 0 str_3
    show_mugshot MUGSHOT_FELIX MUGSHOT_LEFT
    applymovement 13 mov_stairs_felix
    applymovement 0xFF mov_stairs_player
    waitmovement 0
    pause 32
    special SPECIAL_OVERWORLD_VIEWPORT_UNLOCK
    applymovement 0x7F mov_2d
    waitmovement 0
    loadpointer 0 str_4
    show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
    loadpointer 0 str_5
    show_mugshot MUGSHOT_ALBUS MUGSHOT_RIGHT
    loadpointer 0 str_6
    show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
    loadpointer 0 str_7
    show_mugshot MUGSHOT_ALBUS MUGSHOT_RIGHT
    pause 24
    sound 0x15
    applymovement 11 mov_fu_exclam
    applymovement 12 mov_fu_exclam
    checksound
    applymovement 0x7F mov_2u
    waitmovement 0
    special SPECIAL_OVERWORLD_VIEWPORT_LOCK
    loadpointer 0 str_8
    show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
    applymovement 13 mov_1d
    waitmovement 0
    loadpointer 0 str_9
    show_mugshot MUGSHOT_FELIX MUGSHOT_LEFT
    loadpointer 0 str_10
    show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
    loadpointer 0 str_11
    show_mugshot MUGSHOT_FELIX MUGSHOT_LEFT
    loadpointer 0 str_12
    show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
    loadpointer 0 str_13
    show_mugshot MUGSHOT_ALBUS MUGSHOT_RIGHT
    loadpointer 0 str_14
    show_mugshot MUGSHOT_FELIX MUGSHOT_LEFT
    loadpointer 0 str_15
    show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
    loadpointer 0 str_16
    show_mugshot MUGSHOT_ALBUS MUGSHOT_RIGHT
    applymovement 11 mov_fr
    waitmovement 0
    loadpointer 0 str_16b
    show_mugshot MUGSHOT_ALBUS MUGSHOT_RIGHT
    pause 64
    loadpointer 0 str_16c
    show_mugshot MUGSHOT_ALBUS MUGSHOT_RIGHT
    applymovement 11 mov_albus_away
    pause 64
    waitmovement 0
    hidesprite 11
    pause 16
    loadpointer 0 str_17
    show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
    loadpointer 0 str_18
    show_mugshot MUGSHOT_FELIX MUGSHOT_LEFT
    loadpointer 0 str_19
    show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
    applymovement 12 mov_faun_away
    waitmovement 0
    hidesprite 12
    pause 16
    fadesong MUS_ROUTE_24_25
    pause 16
    loadpointer 0 str_20
    show_mugshot MUGSHOT_FELIX MUGSHOT_LEFT
    applymovement 13 mov_fu
    pause 16
    loadpointer 0 str_21
    show_mugshot MUGSHOT_FELIX MUGSHOT_LEFT
    applymovement 13 mov_felix_away
    waitmovement 0
    fadescreen 0x1
    hidesprite 13
    showsprite 0xe
    showsprite 0x10
    showsprite 0x11
    showsprite 0x12
    showsprite 0x13
    showsprite 0x14
    showsprite 0x15
    hidesprite 1
    hidesprite 2
    hidesprite 3
    hidesprite 4
    hidesprite 5
    hidesprite 6
    hidesprite 7
    hidesprite 8
    hidesprite 9
    hidesprite 10
    hidesprite 24
    clearflag KASKADA_IGVA
    clearflag KASKADA_FELIX_DONE
    fadescreen 0x0
    addvar STORY_PROGRESS 1
    end


have_to_select:
    loadpointer 0 str_have_to_select
    show_mugshot MUGSHOT_FELIX MUGSHOT_LEFT
    goto select



.ifdef LANG_GER 
str_0:
    .autostring 34 2 "PLAYER!\nDa bist du ja.\pDas Geschehen ist hier bereits in vollem Gange.\pPolizisten kämpfen erbittert gegen Revolutionäre.\pOpi wird wohl schon weiter vorgedrungen sein.\pWir sollten uns beeilen!"
str_1:
    .autostring 34 2 "Hey, was habt ihr Kinder hier zu suchen?\pDas hier ist kein Spielplatz!\pVerschwindet wieder!"
str_2:
    .autostring 34 2 "Also gut PLAYER, diese beiden Verbrecher hier werden uns sicherlich nicht einfach durchlassen.\pDas heißt, dass wir sie zusammen bekämpfen müssen.\pIst das nicht aufregend?\pWir kämpfen gemeinsam gegen die Revolutionsbewegung?"
str_select:
    .autostring 34 2 "Welche Pokémon willst du in den Kampf schicken?"
str_have_to_select:
    .autostring 34 2 "PLAYER!\pWir müssen gemeinsam gegen diese verbrecherischen Revolutionäre vorgehen!\pOpi würde wollen, dass wir ihn unterstützen!"
str_lets_go:
    .autostring 34 2 "Los gehts, PLAYER!"
str_before:
    .autostring 34 2 "Wir werden euch zwei Rotznasen auf gar keinen Fall vorbeilassen!"
str_after1:
    .autostring 34 2 "Wieso stellt ihr euch gegen eine gerechtere Welt?"
str_after2:
    .autostring 34 2 "Ihr steht auf der falschen Seite!"
str_3:
    .autostring 34 2 "Das war große Klasse, PLAYER!\pLass uns keine Zeit verlieren!"
str_4:
    .autostring 34 2 "Albus, mein alter Freund!\pWie kannst du dich ernsthaft gegen das System stellen, das wir einmal zusammen aufgebaut haben?\pDu verrätst dein eigenes Vermächtnis!"
str_5:
    .autostring 34 2 "Ach FaunDOTS\nDu warst schon immer ein sehr naiver Mensch.\pIst dir etwa entgangen, zu was dieses System verkommen ist?\pIst dir etwa nicht aufgefallen, wie weit die Top Vier heute sich von den Werten entfernt haben, die wir damals in dieser Region etablieren wollten?\pDie Pokémon-Liga dient schon längst nicht mehr den Bürgern Thetos.\pGanz im Gegenteil, sie beutet sie aus.\pDas System ist zersetzt von Korruption und Egoismus.\pEs ist geradezu meine Pflicht, mich gegen diese Verhältnisse aufzulehnen.\pDas ist mein wahres Vermächtnis, Faun."
str_6:
    .autostring 34 2 "Du verrennst dich da in etwas, Albus!\pSicherlich läuft nicht immer alles optimal, aber was du über diese Region bringst, ist ein Bürgerkrieg.\pDenkst du, dass so irgendtwas für die Bürger Thetos erreicht wird?\pAlbus!\nDiese Revolution ist Irrsinn!"
str_7:
    .autostring 34 2 "FaunDOTS\nIch sehe, dass wir einander nicht überzeugen können.\pUnd damit stehen wir uns hier als Feinde gegenüber.\pWirst du versuchen, mich aufzuhalten?"
str_8:
    .autostring 34 2 "PLAYER, Felix!\nWas treibt ihr denn hier?"
str_9:
    .autostring 34 2 "Warum wohl, Opi?\nWir sind natürlich hier, um dich im Kampf gegen die Revolutionäre zu unterstützen.\pPLAYER und ich werden den Revolutionsführer Albus besiegen!"
str_10:
    .autostring 34 2 "Werd' nicht albern, Felix!\pIch bin wirklich geschmeichelt, dass ihr mir altem Knacker unter die Arme greifen wollt, aber das hier ist ein paar Nummer zu groß für euch.\pAlbus war auch einmal ein Mitglied der Top-Vier.\pIhr hättet nicht den Hauch einer Chance, ihn zu besiegen."
str_11:
    .autostring 34 2 "Was soll das heißen Opi?\nDu weißt doch gar nicht, wie stark PLAYER und ich inzwischen geworden sind!\pWir können auch ein Mitglied der Top Vier besiegen!"
str_12:
    .autostring 34 2 "Nun lass gut sein, Felix!\pIch habe sehr lange Zeit zusammen mit Albus gekämpft.\pIch kann dir versichern, dass ihr zwei Rotznasen ihm nicht gewachsen wärt."
str_13:
    .autostring 34 2 "PLAYER?\nDu bist ein Schüler von Faun?\pEigentlich hätte es mir bereits bei unserer Begegnung auf Route 2 klar werden müssen.\pDieses Funkeln in deinen Augen strahlt den selben Optimismus aus, den auch Faun immer in seinem Herzen getragen hat.\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pIch kann nachvollziehen, dass du dich dazu hingezogen, ja vielleicht sogar verpflichtet fühlst, deinen Mentor zu unterstützen.\pUnd ich werde dich auch nicht bitten, dich der Revolutionsbewegung anzuschließen.\pStattdessen appelliere ich daran, dass du tief in dich gehst und dir Zeit nimmst, eine Entscheidung zu treffen.\pMach dir selbst ein Bild von den Verhältnissen in Theto.\pUnd erst, wenn du ganz ohne jedes Gefühl einer Verpflichtung zu einem Entschluss gekommen bist, werde dir entweder als Feind gegenüberstehen oder dich in meinen Reihen aufnehmen."
str_14:
    .autostring 34 2 "Du tickst wohl nicht mehr ganz richtig, was?\pAls ob PLAYER sich deiner verbrecherischen Revolution anschließen würde!\pWir stehen hinter Opi, komme was wolle!"
str_15:
    .autostring 34 2 "Felix, sei jetzt endlich still!"
str_16:
    .autostring 34 2 "Und du musst dann wohl der Enkel von Faun sein, nicht?\pDu kommst ganz nach ihm, mit deiner unbedingten Loyalität.\pDas ist ein sehr lobenswerter Charakterzug, Kleiner!"
str_16b:
    .autostring 34 2 "Faun, mein Freund.\nWenn du nicht gegen mich kämpfen willst, werde ich weiterziehen."
str_16c:
    .autostring 34 2 "Das dachte ich mir bereits.\pIch hoffe wirklich, dass wir eines Tages wieder Seite an Seite kämpfen können, alter Freund."
str_17:
    .autostring 34 2 "Ich kann es einfach nicht über mich bringen, einem alten Freund als Feind gegenüberzutreten.\pGerade seitdem Lucius kein Teil der Pokémon-Liga mehr istDOTS\pKinder, ich will euch eines mit auf den Weg geben.\pIn der Region mag es Probleme geben.\pEs mag auch bösartige Menschen geben, sicherlich auch innerhalb der Pokémon-Liga.\pUnd für diese Probleme muss man Lösungen finden.\pAlbus aber sucht nicht nach einer Lösung.\pEr erklärt unserer Regierung den Krieg.\pAuch er kann nicht mit einer echten Alternative aufwarten.\pAber er ist kein schlechter Mensch.\pEr ist lediglich im Glauben, das Richtige zu tun.\pUnd das macht ihn vielleicht sogar noch gefährlicherDOTS\pIhr solltet euch nicht in diesen Kampf einmischen.\pAlbus und ich sind alte Freunde, und wir werden das unter uns austragen.\pHabt ihr verstanden Kinder?"
str_18:
    .autostring 34 2 "Aber Opi, wir müssen doch hinter dir stehen.\pWir sind deine Schüler!"
str_19:
    .autostring 34 2 "Ich dulde keine Widerrede, Felix!\pIhr haltet euch da raus, verstanden?\pIhr seid weder alt noch stark genug, euch mit solchen Leuten anzulegen.\pIhr habt euer Trainerdasein noch vor euch und müsst kleinere Schritte machen, wenn ihr nicht stolpern wollt.\pIch hoffe, ich habe mich deutlich genug ausgedrückt!\pHaltet die Ohren steif!"
str_20:
    .autostring 34 2 "Es ist frustrierend, von Opi nicht ernst genommen zu werden, findest du nicht auch?"
str_21:
    .autostring 34 2 "Wir sind beide starke Trainer geworden!\pDu hast sogar einen Kommandanten von Team Violet besiegt.\pAber er will das nicht sehen.\pVielleicht hat Opi ja auch recht und Trainer wie er oder Albus spielen tatsächlich in einer ganz anderen Liga.\pIch frage mich, wie wir zu solchen Trainern werden können, PLAYER.\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pUnd gleichzeit mache ich mir auch Gedanken darüber, welchen Weg wir einschlagen.\pSieh dir zum Beispiel Blaise an.\pFür was kämpft er?\pWir sollten unser Bestes geben, einen Weg für uns zu finden.\pUnd wenn wir einem Freund wie Blaise dabei helfen können, einen besseren Weg einzuschlagen, sollten wir alles daran setzten, ihn vom Feldzug gegen seinen Vater abzubringen, meinst du nicht?\pWie könnten wir uns seine Freunde nennen, wenn wir nicht alles daran setzten, ihm zu helfen?\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pIch werde keine Zeit verlieren, PLAYER!\pLass uns nach Blaise suchen."

str_revo:
    .autostring 34 2 "Revolutionär"

.elseif LANG_EN
.endif


mov_fd_exclam:
    .byte LOOK_DOWN, SAY_EXCLAM, STOP
mov_fd:
    .byte LOOK_DOWN, STOP
mov_fr:
    .byte LOOK_RIGHT, SAY_EXCLAM, STOP
mov_fu:
    .byte LOOK_UP, STOP
mov_d_fr:
    .byte STEP_DOWN, LOOK_RIGHT, STOP
mov_2u_fr:
    .byte STEP_UP, STEP_UP, LOOK_RIGHT, STOP
mov_fl:
    .byte LOOK_LEFT, STOP
mov_fr_exclam:
    .byte LOOK_RIGHT, SAY_EXCLAM, STOP
mov_stairs_felix:
    .byte STEP_DOWN, STEP_DOWN, STEP_LEFT, STEP_LEFT, STEP_LEFT, STEP_DOWN, STEP_DOWN, STEP_DOWN, STEP_DOWN, STEP_DOWN, STEP_DOWN, STEP_DOWN, STEP_DOWN, STEP_DOWN, STEP_DOWN, STOP
mov_stairs_player:
    .byte STEP_DOWN, STEP_LEFT, STEP_LEFT, STEP_LEFT, STEP_DOWN, STEP_DOWN, STEP_DOWN, STEP_DOWN, STEP_DOWN, STEP_DOWN, STEP_DOWN, STEP_DOWN, STEP_DOWN, STEP_DOWN, STEP_LEFT, LOOK_DOWN, STOP
mov_fu_exclam:
    .byte LOOK_UP, SAY_EXCLAM, STOP
mov_1d:
    .byte STEP_DOWN, STOP
mov_albus_away:
    .byte STEP_DOWN, STEP_RIGHT, STEP_RIGHT, STEP_UP, STEP_UP, STEP_UP, STEP_LEFT, STEP_UP, STEP_UP, STEP_UP, STEP_UP, STEP_UP, STEP_UP, STOP
mov_faun_away:
    .byte STEP_RIGHT, STEP_UP, STEP_UP, STEP_LEFT, STEP_UP, STEP_UP, STEP_UP, STEP_UP, STEP_UP, STEP_UP, STEP_UP, STOP
mov_felix_away:
    .byte STEP_UP, STEP_UP, STEP_UP, STEP_UP, STEP_UP, STEP_UP, STEP_UP, STOP
mov_2d:
    .byte STEP_DOWN, STEP_DOWN, STOP
mov_2u:
    .byte STEP_UP, STEP_UP, STOP

ow_script_movs_0x92d0b8:
.byte STEP_DOWN
.byte STEP_DOWN
.byte STOP


ow_script_movs_0x928a7c:
.byte FACE_DOWN
.byte STOP


ow_script_movs_0x928a0e:
.byte LOOK_UP
.byte STOP


ow_script_movs_0x9288c3:
.byte STEP_UP
.byte STEP_UP
.byte STOP


ow_script_movs_0x9288bf:
.byte LOOK_UP
.byte SAY_EXCLAM
.byte STOP


ow_script_movs_0x9288ba:
.byte STEP_UP
.byte STEP_RIGHT
.byte LOOK_UP
.byte STOP


ow_script_movs_0x9286d6:
.byte STEP_RIGHT
.byte LOOK_LEFT
.byte STOP


ow_script_movs_0x9312ac:
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STOP


ow_script_movs_0x92e56b:
.byte STEP_UP
.byte STEP_UP
.byte LOOK_RIGHT
.byte STOP


ow_script_0x9283a5:
lockall
playsong MUS_REVOLUTION 0x0
special 0x113
applymovement 0x7f ow_script_movs_0x92d0b8
waitmovement 0x0
special 0x114
loadpointer 0x0 str_0x92d01d
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
loadpointer 0x0 str_0x92cf46
show_mugshot MUGSHOT_ALBUS MUGSHOT_LEFT
loadpointer 0x0 str_0x92ce82
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
loadpointer 0x0 str_0x928b41
show_mugshot MUGSHOT_ALBUS MUGSHOT_LEFT
loadpointer 0x0 str_0x928a7f
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
applymovement 0xc ow_script_movs_0x928a7c
waitmovement 0x0
applymovement 0xb ow_script_movs_0x92d0b8
waitmovement 0x0
loadpointer 0x0 str_0x928a11
show_mugshot MUGSHOT_ALBUS MUGSHOT_LEFT
applymovement 0xb ow_script_movs_0x928a0e
waitmovement 0x0
loadpointer 0x0 str_0x9288c7
show_mugshot MUGSHOT_ALBUS MUGSHOT_LEFT
applymovement 0xb ow_script_movs_0x9288c3
waitmovement 0x0
sound 0x15
applymovement 0xb ow_script_movs_0x9288bf
applymovement 0xc ow_script_movs_0x9288bf
waitmovement 0x0
special 0x113
applymovement 0x7f ow_script_movs_0x9288c3
applymovement 0xb ow_script_movs_0x9288ba
waitmovement 0x0
special 0x114
loadpointer 0x0 str_0x9286da
show_mugshot MUGSHOT_ALBUS MUGSHOT_LEFT
applymovement 0xff ow_script_movs_0x9286d6
waitmovement 0x0
applymovement 0xb ow_script_movs_0x9312ac
pause 0x40
loadpointer 0x0 str_0x9286b8
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
applymovement 0xc ow_script_movs_0x92e56b
waitmovement 0x0
loadpointer 0x0 str_0x928594
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
goto ow_script_0x92d67a


ow_script_movs_0x92dc7e:
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_DOWN
.byte STOP


ow_script_movs_0x92dc7a:
.byte LOOK_UP
.byte SAY_EXCLAM
.byte STOP


ow_script_movs_0x92db7c:
.byte LOOK_UP
.byte STOP


ow_script_movs_0x92da68:
.byte FACE_DOWN
.byte STOP


ow_script_movs_0x92da70:
.byte STEP_LEFT
.byte LOOK_RIGHT
.byte STOP


ow_script_movs_0x92da6b:
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_DOWN
.byte STOP


ow_script_movs_0x92d849:
.byte STEP_RIGHT
.byte STEP_UP
.byte STEP_UP
.byte FACE_DOWN
.byte STOP


ow_script_movs_0x92d7a5:
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STOP


ow_script_movs_0x93a4d4:
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte LOOK_LEFT
.byte STOP


ow_script_movs_0x92d7b6:
.byte STEP_DOWN
.byte FACE_DOWN
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte LOOK_LEFT
.byte STOP


ow_script_0x92d67a:
showsprite 0xd
applymovement 0xd ow_script_movs_0x92dc7e
waitmovement 0x0
sound 0x15
applymovement 0xc ow_script_movs_0x92dc7a
applymovement 0xff ow_script_movs_0x92dc7a
waitmovement 0x0
loadpointer 0x0 str_0x92dc49
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
loadpointer 0x0 str_0x92dbcf
show_mugshot MUGSHOT_FELIX MUGSHOT_RIGHT
loadpointer 0x0 str_0x92db7f
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
applymovement 0xd ow_script_movs_0x92db7c
waitmovement 0x0
loadpointer 0x0 str_0x92db39
show_mugshot MUGSHOT_FELIX MUGSHOT_RIGHT
applymovement 0xd ow_script_movs_0x92da68
waitmovement 0x0
loadpointer 0x0 str_0x92db05
show_mugshot MUGSHOT_FELIX MUGSHOT_RIGHT
loadpointer 0x0 str_0x935f18
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
applymovement 0xc ow_script_movs_0x92da70
waitmovement 0x0
applymovement 0xd ow_script_movs_0x92da6b
waitmovement 0x0
applymovement 0xff ow_script_movs_0x92da68
applymovement 0xc ow_script_movs_0x92da68
waitmovement 0x0
loadpointer 0x0 str_0x92d98d
show_mugshot MUGSHOT_FELIX MUGSHOT_RIGHT
loadpointer 0x0 str_0x936ef3
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
applymovement 0xc ow_script_movs_0x92d849
waitmovement 0x0
applymovement 0xd ow_script_movs_0x92db7c
applymovement 0xff ow_script_movs_0x92db7c
waitmovement 0x0
loadpointer 0x0 str_0x92d7c0
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
applymovement 0xc ow_script_movs_0x92d7a5
waitmovement 0x0
applymovement 0xff ow_script_movs_0x93a4d4
applymovement 0xd ow_script_movs_0x92d7b6
waitmovement 0x0
goto ow_script_0x92dc84


ow_script_movs_0x92e6ec:
.byte LOOK_UP
.byte STOP


ow_script_movs_0x92e6ef:
.byte FACE_DOWN
.byte STOP


ow_script_0x92dc84:
pause 0x40
loadpointer 0x0 str_0x93a4de
show_mugshot MUGSHOT_FELIX MUGSHOT_RIGHT
applymovement 0xd ow_script_movs_0x92e6ec
applymovement 0xff ow_script_movs_0x92e6ef
loadpointer 0x0 str_0x92e6d7
show_mugshot MUGSHOT_FELIX MUGSHOT_RIGHT MSG_YES_NO
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x93a667
loadpointer 0x0 str_0x92e662
show_mugshot MUGSHOT_PLAYER MUGSHOT_LEFT
draw_mugshot MUGSHOT_FELIX MUGSHOT_RIGHT
loadpointer 0x0 str_0x92e5ea
callstd MSG
goto ow_script_0x92df8a


ow_script_movs_0x92e21e:
.byte LOOK_LEFT
.byte STOP


ow_script_movs_0x92e021:
.byte LOOK_RIGHT
.byte STOP


ow_script_movs_0x93c1e9:
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STOP


ow_script_0x92df8a:
loadpointer 0x0 str_0x92e221
callstd MSG
hide_mugshot
applymovement 0xd ow_script_movs_0x92e21e
applymovement 0xff ow_script_movs_0x92e21e
loadpointer 0x0 str_0x92e138
show_mugshot MUGSHOT_FELIX MUGSHOT_RIGHT
applymovement 0xd ow_script_movs_0x92e6ec
applymovement 0xff ow_script_movs_0x92e6ef
loadpointer 0x0 str_0x92e024
show_mugshot MUGSHOT_FELIX MUGSHOT_RIGHT
applymovement 0xff ow_script_movs_0x92e021
waitmovement 0x0
applymovement 0xd ow_script_movs_0x93c1e9
waitmovement 0x0
hidesprite 0x1
hidesprite 0x2
hidesprite 0x3
hidesprite 0x4
hidesprite 0x5
hidesprite 0x6
hidesprite 0x7
hidesprite 0x8
hidesprite 0x9
hidesprite 0xa
hidesprite 0xb
hidesprite 0xc
hidesprite 0xd
goto ow_script_0x941cae


ow_script_0x941cae:
fadescreen 0x1
showsprite 0xe
showsprite 0x10
showsprite 0x11
showsprite 0x12
showsprite 0x13
showsprite 0x14
showsprite 0x15
clearflag KASKADA_IGVA
clearflag KASKADA_FELIX_DONE
fadescreen 0x0
fadesong MUS_ROUTE_24_25
addvar STORY_PROGRESS 0x1
releaseall
end


ow_script_0x93a667:
loadpointer 0x0 str_0x92e4e6
show_mugshot MUGSHOT_PLAYER MUGSHOT_LEFT
draw_mugshot MUGSHOT_FELIX MUGSHOT_RIGHT
loadpointer 0x0 str_0x92e56f
callstd MSG_KEEPOPEN
goto ow_script_0x92df8a


.ifdef LANG_GER

str_0x92d01d:
	.autostring 35 2 "DOTS DOTS DOTS\pAlbus!\nDOTS DOTS DOTS\pDass wir uns nach all der Zeit unter solchen Umständen wieder begegnen DOTS\pDOTS DOTS DOTS\nDOTS DOTS DOTS"




str_0x92cf46:
	.autostring 35 2 "Faun, mein alter Freund.\pEs tut mir wirklich im Herzen weh, dass wir uns hier als Feinde gegenüberstehen.\pAber du weißt so gut wie ich, dass das System, das wir selbst einst erschaffen haben, uns längst schon entglitten ist."




str_0x92ce82:
	.autostring 35 2 "Entglitten?\nDas ist eine sehr bequeme Ausrede, sich vor der Aufgabe zu drücken, einen Kontinent zu regieren.\pErinnerst du dich nicht an früher?\pSollte die Pokémon-Liga nicht unser Vermächtnis sein?"


str_0x928b41:
	.autostring 35 2 "Es ist keine Ausrede, Faun.\pIch habe so lange für die Pokémon-Liga gekämpft, wie ich es mit meinem Gewissen vereinbaren konnte.\pAber Korruption und Machtsucht haben unsere Ideale von damals infiziert DOTS\pErkennst du es nicht?\nDiese Regierung ist nicht mehr zu retten.\pEs ist heute wie damals unsere Pflicht, diese Welt zu verändern.\pUnd für die Veränderung zum Besseren werden wir kämpfen.\pDu, Faun, solltest an meiner Seite dafür eintreten DOTS"


str_0x928a7f:
	.autostring 35 2 "Du irrst dich, Albus.\pIch kann verstehen, warum du dich gegen Thetos Regierung auflehnst.\pIch kann es wirklich sehr gut verstehen.\pAber du bringst den Menschen einen Krieg, in dem es keine Gewinner gibt.\pSelbst, wenn dein Vorhaben gelingen sollte DOTS\pWas kommt danach?\pWer sagt dir, dass nicht eben das gleiche System wieder entsteht?\pWir haben Verantwortung für das Land, das wir damals erobert haben.\pDiese Verantwortung jetzt einfach aufzugeben DOTS DOTS DOTS\pIst feige!"



str_0x928a11:
	.autostring 35 2 "DOTS DOTS DOTS\nDOTS DOTS DOTS\pVielleicht ist es das, Faun DOTS\pDOTS DOTS DOTS\nDOTS DOTS DOTS"



str_0x9288c7:
	.autostring 35 2 "Faun.\nWir du bist für mich wie ein Bruder.\pAuch, wenn wir in diesem Krieg nicht auf der selben Seite stehen DOTS\pIch werde niemals gegen dich kämpfen.\pAber ich werde mein Vorhaben auch nicht einfach aufgeben.\pIch weiß, dass ich im Recht bin.\pDu bist ein gutherziger Mensch, Faun.\pVielleicht siehst du auch eines Tages ein, dass die Revolution notwendig ist DOTS"


str_0x9286da:
	.autostring 35 2 "Hu?\nDu bist doch das Kind, dem ich auf Route 2 begegnet bin?\pDu bist also ein Schüler von Faun?\pIch hoffe, dass du nicht mit der Absicht gekommen bist, dich unserer Sache in den Weg zu stellen.\pWie du sicherlich inzwischen bemerkt hast, bin ich der Anführer der Revolutionsbewegung.\pVielleicht kommst du ja, anders als dein Lehrer, zur Erkenntnis, dass das System der Top Vier gestürzt werden muss.\pEines Tages wirst du dich entscheiden müssen, auf wessen Seite du stehst.\pDOTS DOTS DOTS\nAber ich will dich nicht überrumpeln.\pLeb wohl, junger Trainer."



str_0x9286b8:
    .autostring 35 2 "Albus, warte DOTS DOTS"



str_0x928594:
	.autostring 35 2 "PLAYER.\nDer Mann, dem du eben begegnet bist, ist Albus, der Anführer der Revolutionsbewegung.\pEr ist DOTS\nDOTS DOTS DOTS\pDOTS er war ein enger Freund von mir, aber das liegt eine Ewigkeit zurück.\pGemeinsam waren wir an der Gründung der Pokémon-Liga beteiligt.\pAber jetzt stellt Albus sich gegen das System, das er selbst mitaufgebaut hat DOTS"


str_0x92dc49:
    .autostring 35 2 "Felix?\nDu bist auch hier?"



str_0x92dbcf:
	.autostring 35 2 "Aber sicher doch, Opi!\pIch bin gekommen, um dir im Kampf gegen die Revolutionäre zu helfen!"



str_0x92db7f:
    .autostring 35 2 "He!\nDa bist zu spät dran, Junge.\pIhr Anführer ist mir eben durch die Lappen gegangen."



str_0x92db39:
    .autostring 35 2 "Was?\nIhr Anführer?\pSag mir nicht, dass das der Mann in Grün war, der eben auf dem Berg an mir vorbeigegangen ist!"



str_0x92db05:
    .autostring 35 2 "Mist!\nIch hätte ihn überwältigen sollen!"



str_0x935f18:
	.autostring 35 2 "Hahaha!\nRede doch keinen Unfug, Bursche!\pAlbus Fertigkeiten sind deinen weit voraus.\pEr hätte dich im Handumdrehen erledigt."


str_0x92d98d:
	.autostring 35 2 "Du unterschätzt mich ja immer noch Opi!\pIch habe schon zwei Arena-Orden errungen!\pUnd du denkst immer noch, dass ihr Erwachsenen uns überlegen sind?\pDu hast doch gar keine Vorstellung davon, wie stark ich inzwischen geworden bin!\pPLAYER hier hat es sogar geschafft, einen Kommandanten von Team Violet zu besiegen!"


str_0x936ef3:
	.autostring 35 2 "Hahaha!\nHahaa DOTS\pNun mach mal halblang, du Rotzlöffel.\pIhr beide seid sicherlich auf einem guten Weg, starke Trainer zu werden, aber Leuten wie Albus oder mir könnt ihr noch lange nicht das Wasser reichen."


str_0x92d7c0:
	.autostring 35 2 "Bis der Tag kommt, an dem ihr in der Lage seid, solche Kaliber herauszufordern, müsst ihr noch einiges leisten!\pAber ich bin sicher, dass ihr das Zeug dazu habt!"


str_0x93a4de:
	.autostring 35 2 "Es ist unfair, dass Opi uns immer noch wie kleine Kinder behandelt DOTS\pWir sind mittlerweile ernstzunehmende Trainer geworden, meinst du nicht?\pDOTS DOTS DOTS\pAber wenn wir ihm das nicht zeigen, werden wir seinen Respekt nie verdienen!\pWir müssen einfach noch stärker werden, PLAYER.\pUnd dann werden wir eines Tages selbst den Champion herausfordern!"


str_0x92e6d7:
    .autostring 35 2 "Was sagst du dazu?"



str_0x92e662:
	.autostring 35 2 "Wir werden auf jeden Fall die großen Trainer unserer Zeit übertreffen.\pDaran führt kein Weg vorbei!"



str_0x92e5ea:
    .autostring 35 2 "Das ist die richtige Einstellung!\pIn ein paar Jahren wird man sich von uns Geschichten erzählen, wie man sie von Opi kennt!"



str_0x92e221:
	.autostring 35 2 "DOTS DOTS DOTS\nDOTS DOTS DOTS\pÜbrigens PLAYER,\nhast du je etwas von einer Technik namens Mega-Evolution gehört?\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pDas dachte ich mir bereits.\pOpi hat uns in der Schule nichts darüber beigebracht.\pDoch wenn man dem, was ich gehört habe, Glauben schenkt, handelt es sich um eine Möglichkeit, durch die enge Freundschaft zwischen Trainer und Pokémon im Kampf dessen verstecktes Potenzial zum Vorschein zu bringen.\pDOTS DOTS DOTS\pWas meinst du, wie stark wir erst werden, wenn wir diese Technik beherrschen?"


str_0x92e138:
	.autostring 35 2 "Es gibt noch so viel, dass wir nicht über die Welt der Pokémon wissen.\pUnd genau das macht das Abenteuer so unglaublich spannend!"



str_0x92e024:
	.autostring 35 2 "Aber lass uns die eigentlichen Probleme nicht aus den Augen verlieren, PLAYER!\pWir sollten uns gegen diese Revolutionsbewegung kämpfen!\pAm besten suchen wir in Kaskada nach Albus, ihrem Anführer.\pWenn wir ihn gemeinsam besiegen könnten, wäre Opi sicherlich schwer beeindruckt!"


str_0x92e4e6:
    .autostring 35 2 "Und du meinst, wir sind stark genug, es mit dem Anführer der Revolutionsbewegung aufzunehmen?"



str_0x92e56f:
    .autostring 35 2 "Willst du damit sagen, dass du denkst, wir wären zu schwach für so ein Vorhaben?\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pDas können wir nur herausfinden, wenn wir es versuchen!"


.elseif LANG_EN

.endif

*/
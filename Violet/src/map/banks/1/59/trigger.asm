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
    setvar 0x8004 13
    special SPECIAL_NPC_MOVE_TO_PLAYER
    waitmovement 0
    applymovement 13 mov_fd
    waitmovement 0
    loadpointer 0 str_0
    show_mugshot MUGSHOT_FELIX MUGSHOT_LEFT
    setvar 0x8004 13
    setvar 0x8005 0x1F
    setvar 0x8006 0xE
    special SPECIAL_NPC_MOVE_TO
    setvar 0x8004 0xFF
    setvar 0x8005 0x1F
    setvar 0x8006 0xF
    special SPECIAL_NPC_MOVE_TO
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
.include "overworld_script.s"
.include "callstds.s"
.include "flags.s"
.include "items.s"
.include "vars.s"
.include "ordinals.s"
.include "movements.s"

.global ow_script_feslige_oednis_clouds_person_0
.global ow_script_feslige_oednis_clouds_person_1
.global ow_script_feslige_oednis_clouds_person_2
.global ow_script_tafelberg_clouds_west_bait_gift
.global ow_script_tafelberg_clouds_west_cryptics

ow_script_tafelberg_clouds_west_bait_gift:
    checkflag FLAG_TAFELBERG_CLOUDS_BAIT
    gotoif EQUAL bait_done
    lock
    faceplayer
    loadpointer 0 str_bait_give
    callstd MSG_KEEPOPEN
    copyvarifnotzero 0x8000 ITEM_ELITEKOEDER
	copyvarifnotzero 0x8001 5
	callstd ITEM_OBTAIN
    compare LASTRESULT 0
    gotoif EQUAL bait_no_space
    setflag FLAG_TAFELBERG_CLOUDS_BAIT
bait_done:
    loadpointer 0 str_bait_done
    callstd MSG_FACE
    end
bait_no_space:
    loadpointer 0 str_no_space
    callstd MSG_FACE
    end

ow_script_feslige_oednis_clouds_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end
ow_script_feslige_oednis_clouds_person_1:
    loadpointer 0 str_1
    callstd MSG_FACE
    end
ow_script_feslige_oednis_clouds_person_2:
    loadpointer 0 str_2
    callstd MSG_FACE
    end
ow_script_tafelberg_clouds_west_cryptics:
    lock
    faceplayer
    loadpointer 0 str_ask_battle
    callstd MSG_YES_NO
    compare LASTRESULT 0
    gotoif EQUAL dont_battle_cryptics
    trainerbattlecont 0x1 0x202 12 str_before_first str_after_first later_first
later_first:
    loadpointer 0 str_later_first
    callstd MSG
    applymovement 12 mov_1u_and_hide
    waitmovement 0
    sound 9
    checksound
    pause 40
    sound 9
    applymovement 12 mov_show_and_1d
    waitmovement 0
    checksound
    faceplayer
    trainerbattlecont 0x1 0x203 12 str_before_second str_after_second later_second
later_second:
    loadpointer 0 str_later_second
    callstd MSG
    applymovement 12 mov_1u_and_hide
    waitmovement 0
    sound 9
    checksound
    pause 40
    sound 9
    applymovement 12 mov_show_and_1d
    waitmovement 0
    checksound
    faceplayer
    trainerbattlecont 0x1 0x204 12 str_before_third str_after_third later_third
later_third:
    loadpointer 0 str_later_third
    callstd MSG
    applymovement 12 mov_1u_and_hide
    waitmovement 0
    sound 9
    checksound
    pause 40
    sound 9
    applymovement 12 mov_show_and_1d
    waitmovement 0
    checksound
    faceplayer
    trainerbattlecont 0x1 0x205 12 str_before_fourth str_after_fourth later_fourth
later_fourth:
    loadpointer 0 str_later_fourth
    callstd MSG
    applymovement 12 mov_1u_and_hide
    waitmovement 0
    sound 9
    checksound
    hidesprite 9
    setflag FLAG_TAFELBERG_CLOUDS_CRYPTICS
    release
    end

dont_battle_cryptics:
    loadpointer 0 str_dont_battle
    callstd MSG_KEEPOPEN
    release
    end

mov_1u_and_hide:
    .byte STEP_UP, HIDE_SPRITE, STOP
mov_show_and_1d:
    .byte LOOK_DOWN, SHOW_SPRITE, STEP_DOWN, STOP


.ifdef LANG_GER
str_bait_give:
    .autostring 34 2 "Ein Trainer, huh?\pDu hoffst wohl, hier oben 'nen besseren Fang zu machen, oder?\pIch verrate dir mal etwasDOTS\pDen Unterschied macht der Köder.\pProbier diesen hier, er hat mir gute Dienste erwiesen."
str_bait_done:
    .autostring 34 2 "Mit diesem Köder beißen weitaus stärkere Pokémon, vertrau mir!"
str_no_space:
    .autostring 34 2 "Eine volle Ködertasche, was?\pDann kannst du meinen Köder wohl gar nicht gebrauchenDOTS"
str_0:
    .autostring 34 2 "In meiner Jugend wollte ich diese Himmelsinseln erobern.\pAber das Balg Lucius ist mir zuvor gekommen.\pWas soll ich sagenDOTS\pEr hat es schließlich bis zum Titel des Champion geschafft.\pAber auch er ist irgendwann von seinem Thron gefallen, oder?\pWeißt du, wer sein Nachfolger ist?"
str_1:
    .autostring 34 2 "Immer wenn man denkt, man hätte hier oben alles gesehen, wird man eines Besseren belehrt.\pHast du zum Beispiel schon die funkelnden Kristalle gefunden, die hier oben gewachsen sind?"
str_2:
    .autostring 34 2 "Bist schon einmal diesen sogenannten Kryptikern begegnet?\pDiese Leute machen mich verrückt.\pHaben nichts im Kopf als ihre seltsame antike Sprache.\pWen interessiert es, was die Inschriften auf den Ruinen hier oben bedeuten?"
str_ask_battle:
    .autostring 34 2 "Hey, Moment mal!\pDas hier ist der Hauptsitz der selbsternannten Kryptiker-Vereinigung.\pHier dürfen nur Mitglieder hinein.\pAußer natürlichDOTS\pDu schaffst es, gegen uns alle in Folge zu gewinnen.\pDenkst du, du hast dazu überhaupt den Mumm?"
str_dont_battle:
    .autostring 34 2 "Das habe ich mir gedacht.\pImmerhin sind wir die selbsternannte Vereinigung der Kryptiker!"
str_before_first:
    .autostring 34 2 "Oho!\pDu traust dich was.\pAber wir Kryptiker benutzen eine ganz bestimmte Art von Pokémon.\pSieh dich vor!"
str_after_first:
    .autostring 34 2 "W-Was?\nMeine Strategie konnte dir nichts anhaben?"
str_later_first:
    .autostring 34 2 "Na gut, vielleicht hattest du einfach nur Glück, oder?\pDen nächsten von uns wirst du nicht so leicht schlagen."
str_before_second:
    .autostring 34 2 "Du bist also das Kind, das hier Unruhe stiften will?\pIch zeige dir in guter alter Kryptiker Manier, wie man hier mit solchen Störenfrieden umgeht!"
str_after_second:
    .autostring 34 2 "OuchDOTS\nDu bist ganz schon starkDOTS"
str_later_second:
    .autostring 34 2 "Bild' dir darauf ja nichts ein!\pEs gibt noch mehr von uns!"
str_before_third:
    .autostring 34 2 "Was fällt dir ein, unsere Gruppe so bloßzustellen?\pIch werde hier kurzen Prozess machen."
str_after_third:
    .autostring 34 2 "Das war ein kurzer ProzessDOTS\pAber für michDOTS"
str_later_third:
    .autostring 34 2 "Noch bist du nicht aus dem Schneider.\pWir haben noch ein Ass im Ärmel."
str_before_fourth:
    .autostring 34 2 "Meine Mitglieder hast du ja ganz schön vorgeführt.\pDamit ist aber jetzt Schluss.\pDu hattest lange genug deinen Spaß."
str_after_fourth:
    .autostring 34 2 "UffDOTS"
str_later_fourth:
    .autostring 34 2 "Du hast doch tatsächlich alle Kryptiker hier besiegt.\pIch schätze, damit kann ich dir nicht länger verbieten, in unser Hauptquartier zu kommenDOTS"


.elseif LANG_EN

.endif
.include "ordinals.s"
.include "vars.s"
.include "movements.s"
.include "specials.s"
.include "songs.s"
.include "callstds.s"
.include "mugshot.s"
.include "flags.s"
.include "overworld_script.s"
.include "story_states.s"
.include "species.s"
.include "map_weathers.s"
.include "pathfinding.s"
.include "person_behaviours.s"
.include "story_states.s"

.global ow_script_silvania_forest_rin_0

ow_script_silvania_forest_rin_0:
    lockall
    playsong MUS_VIOLET_ENCOUNTER 0
    playsong2 MUS_VIOLET_ENCOUNTER
    special SPECIAL_OVERWORLD_VIEWPORT_UNLOCK
    applymovement 0x7F mov_2r
    waitmovement 0
    loadpointer 0 str_0
    show_mugshot MUGSHOT_ELISE MUGSHOT_LEFT emotion=MUGSHOT_SAD message_type=MSG_KEEPOPEN
    loadpointer 0 str_1
    show_mugshot MUGSHOT_RIN MUGSHOT_RIGHT message_type=MSG_KEEPOPEN mask_name=1
    loadpointer 0 str_2
    show_mugshot MUGSHOT_RIVAL MUGSHOT_LEFT message_type=MSG_KEEPOPEN
    loadpointer 0 str_3
    show_mugshot MUGSHOT_RIN MUGSHOT_RIGHT message_type=MSG_KEEPOPEN mask_name=1 hide_mugshot=0
    loadpointer 0 str_4
    update_mugshot_emotion MUGSHOT_ANGRY
    callstd MSG_KEEPOPEN
    closeonkeypress
    hide_mugshot
    clearflag (FLAG_SILVANIA_FOREST_SEQUENCE_1_NPCS | 0x8000)
    showsprite 42
    showsprite 43
    applymovement 42 mov_felix_to
    applymovement 43 mov_felix_to
    waitmovement 0
    applymovement 36 mov_fl
    applymovement 41 mov_fl
    applymovement 0xFF mov_fl
    loadpointer 0 str_5
    show_mugshot MUGSHOT_FELIX MUGSHOT_LEFT message_type=MSG_KEEPOPEN
    loadpointer 0 str_6
    show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT message_type=MSG_KEEPOPEN hide_mugshot=0
    applymovement 41 mov_fr
    loadpointer 0 str_7
    callstd MSG_KEEPOPEN
    loadpointer 0 str_8
    update_mugshot_emotion MUGSHOT_RUMINATIVE
    callstd MSG_KEEPOPEN
    hide_mugshot
    closeonkeypress
    applymovement 36 mov_fr
    loadpointer 0 str_9
    show_mugshot MUGSHOT_ELISE MUGSHOT_LEFT message_type=MSG_KEEPOPEN emotion=MUGSHOT_ANGRY
    applymovement 0xFF mov_fr
    loadpointer 0 str_10
    show_mugshot MUGSHOT_RIN MUGSHOT_RIGHT message_type=MSG_KEEPOPEN mask_name=1
    loadpointer 0 str_11
    show_mugshot MUGSHOT_PRIMUS MUGSHOT_RIGHT message_type=MSG_KEEPOPEN emotion=MUGSHOT_SCARED
    applymovement 5 mov_fr
    waitmovement 0
    loadpointer 0 str_11_2 
    show_mugshot MUGSHOT_RIN MUGSHOT_RIGHT message_type=MSG_KEEPOPEN mask_name=1 emotion=MUGSHOT_SHOCKED hide_mugshot=0
    loadpointer 0 str_12
    update_mugshot_emotion MUGSHOT_NORMAL
    callstd MSG_KEEPOPEN
    applymovement 5 mov_fl
    waitmovement 0
    loadpointer 0 str_13
    callstd MSG_KEEPOPEN
    closeonkeypress
    hide_mugshot
    loadpointer 0 str_14
    show_mugshot MUGSHOT_ROSALIE MUGSHOT_LEFT message_type=MSG_KEEPOPEN emotion=MUGSHOT_ANGRY 
    loadpointer 0 str_15
    show_mugshot MUGSHOT_RIN MUGSHOT_RIGHT message_type=MSG mask_name=1
    // Show Seviper
	pause 32
	setflag 13
	showsprite 44
	sound 15
	fadescreen 3
	hidesprite 44
	setflag 14
	showsprite 45
	fadescreen 2
    cry POKEMON_VIPITIS 0
	checksound
    waitcry
    pause 16
    loadpointer 0 str_16
    show_mugshot MUGSHOT_RIN MUGSHOT_RIGHT message_type=MSG mask_name=1
    applymovement 45 mov_fu
    waitmovement 0
    cry POKEMON_VIPITIS 0
    waitcry
    sound 137
    setweather MAP_WEATHER_OUTSIDE
    doweather
    pause 32 // Remove the darkening effect
    
    callasm weather_burning_trees_update_pal_restore_and_tmp
    pause 1
    fadescreen 2
    setmaptile 0x32 0x11 0x377 1
    special SPECIAL_MAP_UPDATE_BLOCKS

    checksound
    pause 32
    applymovement 45 mov_fl
    waitmovement 0 
    pause 32
    setmaptile 0x31 0x11 0x376 1
    special SPECIAL_MAP_UPDATE_BLOCKS
    loadpointer 0 str_17
    show_mugshot MUGSHOT_ROSALIE MUGSHOT_LEFT message_type=MSG emotion=MUGSHOT_SCARED
    sound 15
    fadescreen 3
    hidesprite 45
    fadescreen 2
    checksound
    pause 32
    loadpointer 0 str_18
    show_mugshot MUGSHOT_RIN MUGSHOT_RIGHT message_type=MSG mask_name=1
    applymovement 5 mov_rin_leads
    waitmovement 0
    setmaptile 0x31 0xf 0x387 1
    special SPECIAL_MAP_UPDATE_BLOCKS
    applymovement 5 mov_7r
    applymovement 30 mov_7r
    applymovement 31 mov_7r
    applymovement 32 mov_7r
    waitmovement 0
    hidesprite 5
    hidesprite 30
    hidesprite 31
    hidesprite 32
    applymovement 0x7F mov_2l
    waitmovement 0
    special SPECIAL_OVERWORLD_VIEWPORT_LOCK
    setflag FLAG_SILVANIA_FOREST_BURNING
    setmaptile 0x2f 0xf 0x387 1
    special SPECIAL_MAP_UPDATE_BLOCKS
    pause 32
    applymovement 0xFF mov_fl
    applymovement 36 mov_fl
    applymovement 41 mov_fl
    setweather MAP_WEATHER_BURNING_TREES
    doweather
    loadpointer 0 str_19
    show_mugshot MUGSHOT_ELISE MUGSHOT_RIGHT emotion=MUGSHOT_SCARED message_type=MSG_KEEPOPEN
    loadpointer 0 str_20
    show_mugshot MUGSHOT_ROSALIE MUGSHOT_LEFT emotion=MUGSHOT_SCARED message_type=MSG_KEEPOPEN
    call ow_script_silvania_forest_setmaptiles_burning_trees
    special SPECIAL_MAP_UPDATE_BLOCKS
    loadpointer 0 str_21
    show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT emotion=MUGSHOT_ANGRY message_type=MSG_KEEPOPEN
    loadpointer 0 str_22
    show_mugshot MUGSHOT_FELIX MUGSHOT_LEFT emotion=MUGSHOT_ANGRY message_type=MSG
    sound 0x15
    applymovement 42 mov_fu
    waitmovement 0
    applymovement 0xFF mov_exclam
    applymovement 36 mov_exclam
    applymovement 41 mov_exclam
    applymovement 42 mov_exclam
    waitmovement 0
    checksound
    pause 32
    loadpointer 0 str_23
    show_mugshot MUGSHOT_FELIX MUGSHOT_LEFT message_type=MSG_KEEPOPEN
    loadpointer 0 str_24
    show_mugshot MUGSHOT_ROSALIE MUGSHOT_LEFT message_type=MSG_KEEPOPEN
    loadpointer 0 str_25
    show_mugshot MUGSHOT_FELIX MUGSHOT_LEFT message_type=MSG_KEEPOPEN
    loadpointer 0 str_26
    show_mugshot MUGSHOT_ROSALIE MUGSHOT_LEFT message_type=MSG_KEEPOPEN
    loadpointer 0 str_27
    show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT message_type=MSG_KEEPOPEN hide_mugshot=0
    applymovement 41 mov_fd
    applymovement 36 mov_fu
    applymovement 42 mov_fr
    applymovement 43 mov_fr
    applymovement 0xFF mov_fr
    waitmovement 0
    loadpointer 0 str_28
    callstd MSG
    hide_mugshot
    applymovement 41 mov_rival_run_right
    loadpointer 0 str_29
    show_mugshot MUGSHOT_FELIX MUGSHOT_LEFT hide_mugshot=0 message_type=MSG_KEEPOPEN emotion=MUGSHOT_ANNOYED
    waitmovement 41
    hidesprite 41
    closeonkeypress
    hide_mugshot
    pause 64
    applymovement 0xFF mov_fl
    applymovement 36 mov_fr
    applymovement 41 mov_fr
    waitmovement 0
    loadpointer 0 str_30
    show_mugshot MUGSHOT_FELIX MUGSHOT_LEFT message_type=MSG_KEEPOPEN emotion=MUGSHOT_ANNOYED hide_mugshot=0
    applymovement 35 mov_fl
    applymovement 36 mov_fl
    applymovement 41 mov_fl
    loadpointer 0 str_31
    waitmovement 0
    update_mugshot_emotion MUGSHOT_NORMAL
    callstd MSG_KEEPOPEN
    hide_mugshot
    closeonkeypress
    applymovement 42 mov_fu
    applymovement 43 mov_fd
    waitmovement 0
    loadpointer 0 str_32
    show_mugshot MUGSHOT_FELIX MUGSHOT_LEFT message_type=MSG_KEEPOPEN
    loadpointer 0 str_33
    show_mugshot MUGSHOT_ROSALIE MUGSHOT_LEFT message_type=MSG
    npc_move_to 42 0x2d 0x13 waitmovement=0
    waitmovement 0
    applymovement 42 mov_fu
    
    // Show Ludicullo
	clearflag (17 | 0x8000)
	showsprite 46
	sound 15
	fadescreen 3
	hidesprite 46
	showsprite 49
    special SPECIAL_PAL_TMP_SYNCHRONIZE_WITH_PAL_RESTORE // prepeare for fading back, there now is a new pal
	fadescreen 2
    cry POKEMON_KAPPALORES 0
	checksound
    waitcry
    pause 32


    npc_move_to 43 0x31 0x14 waitmovement=0
    waitmovement 0
    applymovement 43 mov_fu
    waitmovement 0
    // Show Lickitung
	clearflag (18 | 0x8000)
	showsprite 47
	sound 15
	fadescreen 3
	hidesprite 47
	showsprite 48
    special SPECIAL_PAL_TMP_SYNCHRONIZE_WITH_PAL_RESTORE // prepeare for fading back, there now is a new pal
	fadescreen 2
    cry POKEMON_SCHLURP 0
	checksound
    waitcry


    pause 32
    loadpointer 0 str_34
    show_mugshot MUGSHOT_ROSALIE MUGSHOT_LEFT message_type=MSG
    pause 16
    sound 117
    pause 8
    setflag FLAG_SILVANIA_FOREST_HYDRO_PUMP_0
    sound 117
    pause 8
    sound 117
    checksound
    pause 32
    loadpointer 0 str_34
    show_mugshot MUGSHOT_FELIX MUGSHOT_LEFT message_type=MSG
    pause 16
    sound 117
    pause 8
    setflag FLAG_SILVANIA_FOREST_HYDRO_PUMP_1
    sound 117
    pause 8
    sound 117
    checksound
    pause 32
    applymovement 0xFF mov_fr
    waitmovement 0
    applymovement 36 mov_fl
    waitmovement 0
    loadpointer 0 str_36
    show_mugshot MUGSHOT_ELISE MUGSHOT_RIGHT emotion=MUGSHOT_SAD message_type=MSG
    releaseall
    addvar STORY_PROGRESS 1
    setvar VAR_STORY_STATE STORY_STATE_SILVANIA_FOREST_DONE
	movesprite 42 0x2d 0x13
	movesprite 43 0x31 0x14
	movesprite2 42 0x2d 0x13
	movesprite2 43 0x31 0x14
	spritebehave 42 BEHAVIOUR_FACE_UP
	spritebehave 43 BEHAVIOUR_FACE_UP
    releaseall
    end

move_player_down:
    applymovement 0xFF mov_1d
    return

mov_felix_to:
    .byte STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STEP_DOWN, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STOP
mov_rin_leads:
    .byte STEP_DOWN, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STEP_UP, STOP
mov_rival_run_right:
    .byte STEP_RIGHT_FAST, STEP_RIGHT_FAST, STEP_RIGHT_FAST, STEP_RIGHT_FAST, STEP_RIGHT_FAST, STEP_RIGHT_FAST, STEP_RIGHT_FAST, STEP_RIGHT_FAST, STOP



.ifdef LANG_GER
str_0:
    .autostring 34 2 "B-Bitte!\pLassen Sie meinen Vater gehen!"
str_1:
    .autostring 34 2 "Ihn gehen lassen?\pDas ist zu komisch.\pWas denkst du, was hier vor sich geht, du dummes Mädchen?"
str_2:
    .autostring 34 2 "Jetzt reicht es mir, du Schnepfe!\pDu lässt sofort den Professor in Ruhe!"
str_3:
    .autostring 34 2 "Da bekomme ich es aber mit der Angst zu tun!\pEin kleiner Rotzbengel will mir drohen.\pGlaub ja nicht, dass ich ein Problem damit hätte, ein Kind fertig zu machen."
str_4:
    .autostring 34 2 "Professor Primus und ich haben hier etwas zu erledigen.\pUnd ich kann es gar nicht ausstehen, wenn mir jemand versucht, bei meinen Angelegenheiten dumm zu kommen.\pVerstanden, Kindchen?\pZieh' Leine!"
str_5:
    .autostring 34 2 "Was ist hier denn los?\pSind wir etwa zu spät?"
str_6:
    .autostring 34 2 "Nein, ihr kommt gerade rechtzeitig."
str_7:
    .autostring 34 2 "Ich hab den Kommandanten von Team Violet gefunden, nachdem wir gesucht habenDOTS"
str_8:
    .autostring 34 2 "Oder wohl eherDOTSTEXT_DELAY_SHORT\pDie Kommandantin."
str_9:
    .autostring 34 2 "Und diese Frau hat meinen Vater entführt!"
str_10:
    .autostring 34 2 "Entführt?\pDas ist ja zum Schießen!\pDenkst du Göre etwa, dass-"
str_11:
    .autostring 34 2 "B-Bitte, helft mir!\pDiese fürchterliche Frau hetzt mich schon seit Tagen durch die Region!\pI-Ich glaube, sie wird mir etwas antunDOTS"
str_11_2:
    .autostring 34 2 "Huh?"
str_12:
    .autostring 34 2 "Ach, halt den Rand, Primus!"
str_13:
    .autostring 34 2 "Und was diesen Kindergarten hier anbelangtDOTS\pWas glaub ihr Gören, was ihr tut?\pIhr mischt euch in Dinge ein, die euch nichts angehen!\pWenn ihr nicht sofot abschwirrt, mach ich euch die Hölle heiß, ihr Bälger!"
str_14:
    .autostring 34 2 "Wie kann man nur so mit Kindern reden?\pLassen Sie sofot den Professor gehen und verschwinden Sie aus meinem Wald!"
str_15:
    .autostring 34 2 "Na sieh einer an, du bist doch die Arenaleiterin von Kranzdorf, oder?\pSoll mir deine kleine Rasselbande hier etwa Angst machen?\pDu sorgst dich so sehr um deinen geliebten Wald, was?"
str_16:
    .autostring 34 2 "Vipitis!\nFlammewurf, los!"
str_17:
    .autostring 34 2 "M-Mein Wald!\pNein!\nMein schöner Wald!"
str_18:
    .autostring 34 2 "Das hast du jetzt davon, mir dumm zu kommen.\pViel Spaß dabei, deinen ach so schönen Wald zu retten!"
str_19:
    .autostring 34 2 "Oh nein!\pWas wird denn jetzt aus meinem Vater?"
str_20:
    .autostring 34 2 "Und der Kranzwald steht in FlammenDOTS"
str_21:
    .autostring 34 2 "Diese verfluchte Hexe!\pWas fällt ihr ein!\pErst meinen und jetzt Elises Vater!"
str_22:
    .autostring 34 2 "Hey Leute!\pJetzt reißt euch mal zusammen!"
str_23:
    .autostring 34 2 "Wenn wir jetzt den Kopf in den Sand stecken, kommen wir auch nicht weiter."
str_24:
    .autostring 34 2 "Felix hat RechtDOTS"
str_25:
    .autostring 34 2 "Wir werden diese Kommandantin auf keinen Fall damit durchkommen lassen.\pAber wir können auch den Wald nicht einfach abbrennen lassen.\pAlso machen wir es so.\pRosalie und ich versuchen hier, das Feuer in den Griff zu kriegen.\pRIVAL und PLAYER, ihr beiden gebt dieser Kommandantin eins auf den Deckel und befreit Professor Primus."
str_26:
    .autostring 34 2 "Das hört sich nach einem guten Plan-"
str_27:
    .autostring 34 2 "Alles klar!\pDer zeig ich schon, wo's lang geht!"
str_28:
    .autostring 34 2 "Deinen Vater habe ich im Handumdrehen wieder befreit!"
str_29:
    .autostring 34 2 "Jetzt warte doch mal, RIVALDOTS"
str_30:
    .autostring 34 2 "Immer das gleiche mit ihmDOTS"
str_31:
    .autostring 34 2 "Aber der Plan steht!\pRosalie und ich versuchen, das Feuer in den Griff zu bekommen.\pUnd du PLAYER unterstützt RIVAL.\pWenn er alleine gegen sie antritt, könnte das ins Auge gehenDOTS"
str_32:
    .autostring 34 2 "Mit der Hilfe unserer Pokémon können wir vielleicht etwas gegen die Flammen ausrichten.\pAm Besten setzen wir starke Wasser-Angriffe ein."
str_33:
    .autostring 34 2 "Das klingt vernünftig.\pLass uns keine Zeit verlieren!"
str_34:
    .autostring 34 2 "Und los, Aquawelle!"
str_35:
    .autostring 34 2 "Alles klar Schlurp, gehen wir's an!"
str_36:
    .autostring 34 2 "Bitte PLAYER, beeil dich!\pWer weiß, was diese Frau meinem Vater antut!"
.elseif
.endif

.global ow_script_silvania_forest_rin_1

ow_script_silvania_forest_rin_1:
    lockall
    loadpointer 0 str_37
    show_mugshot MUGSHOT_RIN MUGSHOT_RIGHT emotion=MUGSHOT_ANGRY message_type=MSG_KEEPOPEN mask_name=1
    loadpointer 0 str_38
    show_mugshot MUGSHOT_PRIMUS MUGSHOT_LEFT message_type=MSG_KEEPOPEN
    closeonkeypress
    setvar 0x8004 2
    special SPECIAL_SET_TARGET_NPC_TO_VAR
    faceplayer
    setvar 0x8004 1
    special SPECIAL_SET_TARGET_NPC_TO_VAR
    faceplayer
    sound 0x15
    applymovement 1 mov_exclam
    applymovement 2 mov_exclam
    waitmovement 0
    checksound
    loadpointer 0 str_39
    show_mugshot MUGSHOT_RIN MUGSHOT_RIGHT emotion=MUGSHOT_ANGRY message_type=MSG_KEEPOPEN hide_mugshot=0 mask_name=1
    update_mugshot_emotion MUGSHOT_NORMAL
    applymovement 1 mov_fr
    waitmovement 0
    loadpointer 0 str_40
    callstd MSG_KEEPOPEN
    setvar 0x8004 1
    special SPECIAL_SET_TARGET_NPC_TO_VAR
    faceplayer
    setvar BATTLE_SONG_OVERRIDE MUS_KAMPF_GEGEN_ARENALEITER_HOENN
    setvar LASTTALKED 1
    trainerbattlecont 0x1 0x4c 0x0 str_41 str_42 rin_battle_cont
    hide_mugshot
rin_battle_cont:
    setvar BATTLE_SONG_OVERRIDE 0
    loadpointer 0 str_43
    show_mugshot MUGSHOT_RIN MUGSHOT_RIGHT emotion=MUGSHOT_SHOCKED message_type=MSG_KEEPOPEN hide_mugshot=0
    update_mugshot_emotion MUGSHOT_NORMAL
    loadpointer 0 str_44
    callstd MSG_KEEPOPEN
    update_mugshot_emotion MUGSHOT_ANGRY
    loadpointer 0 str_45
    callstd MSG_KEEPOPEN
    closeonkeypress
    hide_mugshot
    npc_move_to 1 0x41 0x13
    fadescreen 1
    hidesprite 50
    hidesprite 51
    hidesprite 1
    setflag SILVANIA_FOREST_RIN
    fadesong VERTANIA_WALD_AND_BEERENFORST_AND_MUSTERBUSCHWALD_AND_DIGDAS_HOHLE_AND_SEESCHAUMINSELN
    playsong2 VERTANIA_WALD_AND_BEERENFORST_AND_MUSTERBUSCHWALD_AND_DIGDAS_HOHLE_AND_SEESCHAUMINSELN
    fadescreen 0
    setvar 0x8004 2
    special SPECIAL_SET_TARGET_NPC_TO_VAR
    faceplayer
    loadpointer 0 str_46
    show_mugshot MUGSHOT_PRIMUS MUGSHOT_RIGHT message_type=MSG
    // Show Elise
    clearflag (19 | 0x8000)
    showsprite 55
    applymovement 55 mov_4u
    waitmovement 0
    sound 0x15
    applymovement 55 mov_exclam
    waitmovement 0
    loadpointer 0 str_47
    show_mugshot MUGSHOT_ELISE MUGSHOT_RIGHT message_type=MSG emotion=MUGSHOT_SHOCKED
    npc_move_to 2 0x41 0xc
    applymovement 2 mov_fd
    applymovement 0xFF mov_fd
    waitmovement 0
    loadpointer 0 str_48
    show_mugshot MUGSHOT_PRIMUS MUGSHOT_RIGHT message_type=MSG
    applymovement 2 mov_fu
    waitmovement 0
    loadpointer 0 str_49
    show_mugshot MUGSHOT_ELISE MUGSHOT_RIGHT message_type=MSG emotion=MUGSHOT_SAD
    clearflag (20 | 0x8000)
    clearflag (21 | 0x8000)
    showsprite 53
    showsprite 54
    applymovement 53 mov_4u
    applymovement 54 mov_4u
    waitmovement 0
    loadpointer 0 str_50
    show_mugshot MUGSHOT_FELIX MUGSHOT_RIGHT message_type=MSG
    sound 0x15
    applymovement 54 mov_exclam
    waitmovement 0
    checksound
    applymovement 54 mov_3u_fast
    waitmovement 0
    applymovement 0xFF mov_fr
    waitmovement 0
    loadpointer 0 str_51
    show_mugshot MUGSHOT_FELIX MUGSHOT_RIGHT message_type=MSG emotion=MUGSHOT_SHOCKED
    pause 64
    loadpointer 0 str_52
    show_mugshot MUGSHOT_FELIX MUGSHOT_RIGHT message_type=MSG emotion=MUGSHOT_SHOCKED
    pause 32
    loadpointer 0 str_53
    show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT message_type=MSG_KEEPOPEN emotion=MUGSHOT_BEATEN
    loadpointer 0 str_54
    show_mugshot MUGSHOT_FELIX MUGSHOT_RIGHT message_type=MSG_KEEPOPEN emotion=MUGSHOT_SHOCKED
    loadpointer 0 str_55
    show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT message_type=MSG_KEEPOPEN emotion=MUGSHOT_BEATEN
    loadpointer 0 str_56
    show_mugshot MUGSHOT_FELIX MUGSHOT_RIGHT message_type=MSG_KEEPOPEN emotion=MUGSHOT_ANGRY hide_mugshot=0
    update_mugshot_emotion MUGSHOT_NORMAL
    loadpointer 0 str_57
    callstd MSG_KEEPOPEN
    closeonkeypress
    hide_mugshot
    pause 32
    clearflag (22 | 0x8000)
    hidesprite 52
    showsprite 56
    pause 32
    loadpointer 0 str_58
    show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT message_type=MSG emotion=MUGSHOT_BEATEN
    pause 32
    applymovement 0xFF mov_fd
    applymovement 56 mov_fd
    applymovement 54 mov_fd
    loadpointer 0 str_59
    show_mugshot MUGSHOT_ROSALIE MUGSHOT_RIGHT message_type=MSG emotion=MUGSHOT_SHOCKED
    applymovement 53 mov_u_and_look_arround
    waitmovement 0
    loadpointer 0 str_60
    show_mugshot MUGSHOT_ROSALIE MUGSHOT_RIGHT message_type=MSG emotion=MUGSHOT_SAD
    applymovement 54 mov_fl
    waitmovement 0
    pause 32
    loadpointer 0 str_61
    show_mugshot MUGSHOT_FELIX MUGSHOT_RIGHT message_type=MSG_KEEPOPEN emotion=MUGSHOT_SCARED
    loadpointer 0 str_62
    show_mugshot MUGSHOT_ROSALIE MUGSHOT_RIGHT message_type=MSG emotion=MUGSHOT_SAD
    pause 32
    sound 80
    checksound
    pause 32
    sound 0x15
    applymovement 53 mov_exclam
    applymovement 54 mov_exclam
    waitmovement 0
    checksound
    loadpointer 0 str_63
    show_mugshot MUGSHOT_FELIX MUGSHOT_RIGHT message_type=MSG emotion=MUGSHOT_SHOCKED
    pause 32
    sound 80
    checksound
    pause 32
    clearflag FLAG_SILVANIA_FOREST_BURNING
    clearflag FLAG_SILVANIA_FOREST_HYDRO_PUMP_0
    clearflag FLAG_SILVANIA_FOREST_HYDRO_PUMP_1
    setweather MAP_WEATHER_RAIN
    pause 64
    loadpointer 0 str_64
    show_mugshot MUGSHOT_ROSALIE MUGSHOT_RIGHT message_type=MSG emotion=MUGSHOT_HAPPY
    pause 32
    callasm silvania_forest_white_blend_map_reload
    pause 256
    setvar VAR_MAP_TRANSITION_FADING_DELAY 0 // Set by the asm function to 8 for a smoother transition effect
    loadpointer 0 str_65
    show_mugshot MUGSHOT_ROSALIE MUGSHOT_RIGHT message_type=MSG_KEEPOPEN emotion=MUGSHOT_HAPPY
    loadpointer 0 str_66
    show_mugshot MUGSHOT_PRIMUS MUGSHOT_RIGHT message_type=MSG_KEEPOPEN emotion=MUGSHOT_RUMINATIVE
    applymovement 54 mov_fd
    loadpointer 0 str_67
    show_mugshot MUGSHOT_FELIX MUGSHOT_RIGHT message_type=MSG_KEEPOPEN emotion=MUGSHOT_HAPPY
    loadpointer 0 str_68
    show_mugshot MUGSHOT_ROSALIE MUGSHOT_RIGHT message_type=MSG_KEEPOPEN
    loadpointer 0 str_69
    show_mugshot MUGSHOT_ELISE MUGSHOT_RIGHT message_type=MSG_KEEPOPEN emotion=MUGSHOT_ANNOYED
    applymovement 54 mov_fr
    loadpointer 0 str_70
    show_mugshot MUGSHOT_FELIX MUGSHOT_RIGHT message_type=MSG_KEEPOPEN emotion=MUGSHOT_SHOCKED hide_mugshot=0
    applymovement 54 mov_fl
    applymovement 0xFF mov_fr
    waitmovement 0
    loadpointer 0 str_71
    update_mugshot_emotion MUGSHOT_NORMAL
    callstd MSG_KEEPOPEN
    applymovement 54 mov_fr
    loadpointer 0 str_72
    callstd MSG_KEEPOPEN
    closeonkeypress
    hide_mugshot
    applymovement 53 mov_1l
    waitmovement 0
    applymovement 53 mov_fr
    waitmovement 0
    applymovement 54 mov_4d
    applymovement 56 mov_4d_very_slow
    waitmovement 54
    applymovement 54 mov_fu
    waitmovement 56
    applymovement 54 mov_3d
    applymovement 56 mov_3d_very_slow
    waitmovement 56
    hidesprite 54
    hidesprite 56
    applymovement 0xFF mov_fd
    waitmovement 0
    setvar 0x8004 53
    special SPECIAL_SET_TARGET_NPC_TO_VAR
    faceplayer
    loadpointer 0 str_73
    show_mugshot MUGSHOT_ROSALIE MUGSHOT_RIGHT message_type=MSG
    applymovement 53 mov_1r
    waitmovement 0
    applymovement 53 mov_6d
    waitmovement 0
    hidesprite 53
    applymovement 55 mov_1r
    waitmovement 0
    applymovement 55 mov_1u
    waitmovement 0
    loadpointer 0 str_74
    show_mugshot MUGSHOT_ELISE MUGSHOT_RIGHT message_type=MSG_KEEPOPEN
    loadpointer 0 str_75
    show_mugshot MUGSHOT_PRIMUS MUGSHOT_RIGHT message_type=MSG_KEEPOPEN
    applymovement 55 mov_fl
    waitmovement 0
    loadpointer 0 str_76
    show_mugshot MUGSHOT_ELISE MUGSHOT_RIGHT message_type=MSG_KEEPOPEN emotion=MUGSHOT_RUMINATIVE
    applymovement 2 mov_fr
    waitmovement 0
    loadpointer 0 str_77
    show_mugshot MUGSHOT_PRIMUS MUGSHOT_RIGHT message_type=MSG_KEEPOPEN
    loadpointer 0 str_78
    show_mugshot MUGSHOT_ELISE MUGSHOT_RIGHT message_type=MSG_KEEPOPEN emotion=MUGSHOT_RUMINATIVE
    loadpointer 0 str_79
    show_mugshot MUGSHOT_PRIMUS MUGSHOT_RIGHT message_type=MSG_KEEPOPEN
    loadpointer 0 str_80
    show_mugshot MUGSHOT_ELISE MUGSHOT_RIGHT message_type=MSG_KEEPOPEN emotion=MUGSHOT_RUMINATIVE
    loadpointer 0 str_81
    show_mugshot MUGSHOT_PRIMUS MUGSHOT_RIGHT message_type=MSG_KEEPOPEN emotion=MUGSHOT_SCARED
    applymovement 55 mov_fu
    waitmovement 0
    loadpointer 0 str_82
    show_mugshot MUGSHOT_ELISE MUGSHOT_RIGHT message_type=MSG_KEEPOPEN
    applymovement 55 mov_fl
    waitmovement 0
    loadpointer 0 str_83
    show_mugshot MUGSHOT_ELISE MUGSHOT_RIGHT message_type=MSG_KEEPOPEN
    loadpointer 0 str_84
    show_mugshot MUGSHOT_PRIMUS MUGSHOT_RIGHT message_type=MSG_KEEPOPEN
    applymovement 2 mov_fu
    applymovement 55 mov_fu
    waitmovement 0
    loadpointer 0 str_85
    show_mugshot MUGSHOT_PRIMUS MUGSHOT_RIGHT message_type=MSG_KEEPOPEN
    loadpointer 0 str_86
    show_mugshot MUGSHOT_ELISE MUGSHOT_RIGHT message_type=MSG
    applymovement 2 mov_6d
    applymovement 55 mov_6d
    waitmovement 0
    hidesprite 2
    hidesprite 55
    setflag SILVANIA_FOREST_RIN
    @// setflag FLAG_PROFESSOR_TANN_GONE
    @// setflag FLAG_ELISE_GONE
    @// clearflag FLAG_PROFESSOR_TANN_GONE_IN_DESERT_TENT
    releaseall
    end

mov_4d_very_slow:
    .byte STEP_DOWN_VERY_SLOW, STEP_DOWN_VERY_SLOW, STEP_DOWN_VERY_SLOW, STEP_DOWN_VERY_SLOW, STOP
mov_3d_very_slow:
    .byte STEP_DOWN_VERY_SLOW, STEP_DOWN_VERY_SLOW, STEP_DOWN_VERY_SLOW, STOP
mov_3u_fast:
    .byte STEP_UP_FAST, STEP_UP_FAST, STEP_UP_FAST, LOOK_RIGHT, STOP
mov_u_and_look_arround:
    .byte STEP_UP, STEP_UP, STEP_UP, PAUSE_16, PAUSE_16, LOOK_RIGHT_DELAYED, PAUSE_16, PAUSE_16, LOOK_LEFT_DELAYED, PAUSE_16, PAUSE_16, LOOK_UP_DELAYED, STOP

.ifdef LANG_GER
str_37:
    .autostring 34 2 "Was soll das heißen, der Stein ist nicht hier?\pIst das nicht der Zeitwald?\pWo sollte der verfluchte Stein denn sonst sein?"
str_38:
    .autostring 34 2 "Beruhige dich.\pWenn der Text, die in diesen Schrein graviert ist, der Wahrheit entspricht, macht das die Unternehmung zwar komplizierter, aber nicht unmöglich.\pDer Tesserakt-"
str_39:
    .autostring 34 2 "Du schon wieder!"
str_40:
    .autostring 34 2 "Deinem kleinen Freund hier hab ich schon gezeigt, was es bedeutet, sich mit uns anzulegen."
str_41:
    .autostring 34 2 "Ihr Gören fangt an mir gewaltig auf die Nerven zu gehen.\pUnd ich habe hier leider auch nicht das gefunden, was ich gehofft hatte.\pPech für dich, Kindchen!\pMit Rin, einer Kommandantin von Team Violet, sollte man sich nicht anlegen!\pJetzt werde ich meinen ganzen Frust an dir auslassen!"
str_42:
    .autostring 34 2 "U-Unmöglich!\pIch habe mich von einem Kind besiegen lassen?"
str_43:
    .autostring 34 2 "Wie lächerlich!\pSo eine Demütigung, von einem Kind besiegt zu werden."
str_44:
    .autostring 34 2 "Aber was soll's?\pDas, wonach ich auf der Suche bin, finde ich in diesem Wald sowieso nicht."
str_45:
    .autostring 34 2 "Wage es ja nicht, mir noch einmal in die Quere zu kommen, verstanden?"
str_46:
    .autostring 34 2 "Vielen Dank, dass du mich vor dieser Frau gerettet hast!\pIch weiß wirklich nicht, was ich ohne deine Hilfe getan hätteDOTS"
str_47:
    .autostring 34 2 "Papa!\pGeht es dir gut?"
str_48:
    .autostring 34 2 "Elise!\pBin ich froh, dich zu sehen, Kleines!\pDank der Hilfe von PLAYER geht es mir gut.\pEr hat diese schreckliche Frau vertrieben!"
str_49:
    .autostring 34 2 "Ist das wahr, PLAYER?\pIch kann dir wirklich nicht genug dankenDOTS"
str_50:
    .autostring 34 2 "Sehr gut, das Feuer hätten wir erledigt-"
str_51:
    .autostring 34 2 "Hey, RIVAL!\pIst bei dir alles in Ordnung?"
str_52:
    .autostring 34 2 "RIVAL!\pJetzt sag doch was!\pRIVAL, hey!"
str_53:
    .autostring 34 2 "DOTS DOTS DOTSTEXT_DELAY_SHORT\nDOTS DOTS DOTSTEXT_DELAY_SHORT\pIchDOTSTEXT_DELAY_SHORT\nDOTS DOTS DOTSTEXT_DELAY_SHORT"
str_54:
    .autostring 34 2 "W-Was ist denn passiert?\pWer hat dich so zugerichtet?"
str_55:
    .autostring 34 2 "DieseDOTS\nDOTSKommandantin ist verflixt stark DOTS"
str_56:
    .autostring 34 2 "Dann ist sie dafür verantwortlich!"
str_57:
    .autostring 34 2 "KommDOTS\pIch helfe dir hoch, RIVAL."
str_58:
    .autostring 34 2 "D-DankeDOTS\nDOTS DOTS DOTS"
str_59:
    .autostring 34 2 "Es sieht so aus, als hätte diese schreckliche Frau auch hier den Wald in Brand gesteckt!"
str_60:
    .autostring 34 2 "Und um ehrlich zu sein, haben sich die Flammen viel zu stark ausgebreitet, als dass wir mit unseren Pokémon noch etwas ausrichten könntenDOTS"
str_61:
    .autostring 34 2 "DOTS DOTS DOTS\nDOTS DOTS DOTS\pDas sieht nicht gut ausDOTS"
str_62:
    .autostring 34 2 "Was sollen wir den jetzt bloß machen?"
str_63:
    .autostring 34 2 "Ist das etwa?"
str_64:
    .autostring 34 2 "Regen!\nDas ist Regen!\pEs fängt an zu regnen!"
str_65:
    .autostring 34 2 "Der Regen löscht das Feuer im Wald!"
str_66:
    .autostring 34 2 "Was für ein seltsamer ZufallDOTS"
str_67:
    .autostring 34 2 "Damit hat sich die Sache mit dem Feuer erledigt!\pDas ist doch fantastisch, oder nicht, Rosalie?"
str_68:
    .autostring 34 2 "Ja, du hast Recht.\pEs ist fast so, als hätte die Natur selbst den Waldbrand gelöschtDOTS"
str_69:
    .autostring 34 2 "DOTS DOTS DOTS"
str_70:
    .autostring 34 2 "Und jetzt sehen wir, dass wir dich wieder auf die Beine bringen, RIVAL!\pIch bringe dich zum nächsten Pokéstop!"
str_71:
    .autostring 34 2 "PLAYER!\nDanke für deine Hilfe!\pOhne dich hätten wir diese Kommandantin vielleicht gar nicht stoppen können.\pUnd auch wenn sie uns letztlich durch die Lappen gegangen istDOTS\pKonnten wir immerhin den Wald beschützen.\pUnd früher oder später kriegen wir diese Team Violet Leute schon noch klein!"
str_72:
    .autostring 34 2 "Komm mit, RIVAL.\pJetzt werden wir dir und deinen Pokémon erst einmal etwas Erhohlung verschaffen."
str_73:
    .autostring 34 2 "PLAYER!\pAuch ich muss mich bei dir bedanken.\pDu hast diese grässliche Frau vertrieben.\pDer Wald und ich stehen tief in deiner Schuld.\pDu und deine Pokémon haben mich schwer beeindruckt.\pJetzt, wo sich die Lage beruhigt hat, willst du mich sicher zu einem Arenakampf herausfordern.\pDiese Herausforderung nehme ich nur allzu gerne an.\pKomm in meine Arena und zeige mir, wie du eine Team Violet Kommandantin besiegt hast."
str_74:
    .autostring 34 2 "Du hast vermutlich genug von den ganzen Danksagungen, aber natürlich müssen auch mein Vater und ich uns bei dir bedanken.\pWer weiß, was meinem Papa passiert wäre, wenn du nicht gewesen wärst!"
str_75:
    .autostring 34 2 "Dem ist nichts hinzuzufgen.\pDu hast mich wirklich aus einer misslichen Lage befreit."
str_76:
    .autostring 34 2 "Weißt du, PapaDOTS\pIch frage mich, was diese Kommandantin eigentlich von dir gewollt hatDOTS"
str_77:
    .autostring 34 2 "Nun, ähmDOTS\pNaja, sie hat wohl geglaubt, dass ich ihr helfen kann, den Zeitstein hier ausfinding zu machenDOTS"
str_78:
    .autostring 34 2 "Was soll denn das sein, dieser Zeitstein?"
str_79:
    .autostring 34 2 "Das ist gar nicht so einfach zu erklären.\pZumal dieser Zeitstein vermutlich nicht einmal existiertDOTS\pDer Legende nach handelt es sich dabei um ein Objekt, das außerhalb der Zeit existiert und dadurch Vergangenheit, Gegenwart und Zukunft miteinander gewissermaßen verbindet."
str_80:
    .autostring 34 2 "Das hört sich wirklich absurd an.\pWie eines der Märchen, die du mir früher immer vorgelesen hast.\pUnd wie kommen diese Leute überhaupt auf den Gedanken, dass du etwas über irgendeinen sagenumwobenen Stein wissen könntest?\pWäre es nicht viel logischer, anzunehmen, dass zum Beispiel Professor Tann etwas darüber weiß?"
str_81:
    .autostring 34 2 "Ä-Äh!\nNaja!\pIch nehme an, dass sich diese Leute auch an Professor Tann gewendet haben?"
str_82:
    .autostring 34 2 "Richtig!\pErinnerst du dich, PLAYER?\pDeswegen haben sie vermutlich Professor Tann in seinem Labor angegriffen!"
str_83:
    .autostring 34 2 "Wir Forscher sollten in diesen Zeiten besonders vorsichtig sein, meinst du nicht auch, Papa?"
str_84:
    .autostring 34 2 "Da hast du sicher nicht Unrecht, Elise."
str_85:
    .autostring 34 2 "PLAYER!\nWir wollen dich wirklich nicht länger mit unserem Gerede aufhalten.\pDanke für alles.\pUnd so dankbar ich dir auch für meine Rettung bin, solltest du dich in Zukunft nicht so leichtfertig in Gefahr begeben, ja?\pDu hast ja gesehen, was mit deinem Freund passiert istDOTS\pPass auf dich auf, PLAYER!"
str_86:
    .autostring 34 2 "Mach's gut, PLAYER!"
.elseif LANG_EN
.endif

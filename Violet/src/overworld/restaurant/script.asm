.include "overworld_script.s"
.include "callstds.s"
.include "vars.s"
.include "ordinals.s"
.include "flags.s"
.include "pathfinding.s"
.include "constants/restaurant_trainers.s"

.global ow_script_restaurant_waiter
.global ow_script_restaurant_trainer_0
.global ow_script_restaurant_trainer_1
.global ow_script_restaurant_trainer_2
.global ow_script_restaurant_trainer_3
.global ow_script_restaurant_trainer_4
.global ow_script_restaurant_trainer_5
.global ow_script_restaurant_trainer_6
.global ow_script_restaurant_trainer_7

ow_script_restaurant_trainer_0:
    trainerbattlestd 0, (RESTAURANT_TRAINER_BASE + 0), 0, str_before_0, str_after_0
    loadpointer 0 str_later_0
    callstd MSG_FACE
    end

ow_script_restaurant_trainer_1:
    trainerbattlestd 0, (RESTAURANT_TRAINER_BASE + 1), 0, str_before_1, str_after_1
    loadpointer 0 str_later_1
    callstd MSG_FACE
    end

ow_script_restaurant_trainer_2:
    trainerbattlestd 0, (RESTAURANT_TRAINER_BASE + 2), 0, str_before_2, str_after_2
    loadpointer 0 str_later_2
    callstd MSG_FACE
    end

ow_script_restaurant_trainer_3:
    trainerbattlestd 0, (RESTAURANT_TRAINER_BASE + 3), 0, str_before_3, str_after_3
    loadpointer 0 str_later_3
    callstd MSG_FACE
    end

ow_script_restaurant_trainer_4:
    trainerbattlestd 0, (RESTAURANT_TRAINER_BASE + 4), 0, str_before_4, str_after_4
    loadpointer 0 str_later_4
    callstd MSG_FACE
    end

ow_script_restaurant_trainer_5:
    trainerbattlestd 0, (RESTAURANT_TRAINER_BASE + 5), 0, str_before_5, str_after_5
    loadpointer 0 str_later_5
    callstd MSG_FACE
    end

ow_script_restaurant_trainer_6:
    trainerbattlestd 0, (RESTAURANT_TRAINER_BASE + 6), 0, str_before_6, str_after_6
    loadpointer 0 str_later_6
    callstd MSG_FACE
    end

ow_script_restaurant_trainer_7:
    trainerbattlestd 0, (RESTAURANT_TRAINER_BASE + 7), 0, str_before_7, str_after_7
    loadpointer 0 str_later_7
    callstd MSG_FACE
    end

ow_script_restaurant_waiter:
    lockall
    faceplayer
    loadpointer 0 str_waiter_ask
    callstd MSG_YES_NO
    compare LASTRESULT 0
    gotoif EQUAL no_restaurant
    setvar 0x8008 0 @ keep track of the money spent if the menu is aborted
	setflag TRANS_DISABLE
	clearflag TRANS_PALETTE_FETCH
	showmoney 0 0 0

    loadpointer 0 str_ask_starter
	callstd MSG_KEEPOPEN
	callasm restaurant_menu_starters_new
	waitstate
    compare LASTRESULT 0xFFFF
    gotoif EQUAL no_restaurant_hide_money
    sound 0x41
    updatemoney 0x0 0x0 0x0
	closeonkeypress
    copyvar VAR_RESTAURANT_STARTER LASTRESULT

    loadpointer 0 str_ask_main
	callstd MSG_KEEPOPEN
	callasm restaurant_menu_mains_new
	waitstate
    compare LASTRESULT 0xFFFF
    gotoif EQUAL no_restaurant_hide_money
    sound 0x41
    updatemoney 0x0 0x0 0x0
	closeonkeypress
    copyvar VAR_RESTAURANT_LEVEL LASTRESULT

    loadpointer 0 str_ask_dessert
	callstd MSG_KEEPOPEN
	callasm restaurant_menu_desserts_new
	waitstate
    compare LASTRESULT 0xFFFF
    gotoif EQUAL no_restaurant_hide_money
    sound 0x41
    updatemoney 0x0 0x0 0x0
	closeonkeypress
    copyvar VAR_RESTAURANT_TYPE LASTRESULT

    hidemoney
    clearflag TRANS_DISABLE
    loadpointer 0 str_seat_player
    callstd MSG

    npc_move_to 0xFF 7 2 waitmovement=1
    applymovement 0xFF mov_fr
    waitmovement 0
    fadescreen 1
    pause 32
    callasm restaurant_randomize
    callasm restaurant_update_sprites
    pause 32
    fadescreen 0
    loadpointer 0 str_battle
    callstd MSG
    release
    end
no_restaurant_hide_money:
    hidemoney
no_restaurant:
    loadpointer 0 str_end
    callstd MSG
    release
    end

.ifdef LANG_GER
str_waiter_ask:
    .autostring 34 2 "Willkommen im Pokéstop-Restaurant.\pHier können die Gäste gegeneinander kämpfen.\pDarf ich Ihnen einen Tisch anbieten?"
str_ask_starter:
    .autostring 34 2 "Welche Vorspeise darf ich Ihnen bringen?"
str_ask_main:
    .autostring 34 2 "Welche Hauptspeise darf ich Ihnen bringen?"
str_ask_dessert:
    .autostring 34 2 "Welche Nachspeise darf ich Ihnen bringen?"
str_seat_player:
    .autostring 34 2 "Ausgezeichnete Wahl!\pBitte nehmen Sie Platz.\pSie erhalten Ihre Speisen in Kürze."
str_end:
    .autostring 34 2 "Ich verstehe.\pWenn Sie bei uns speisen möchten, kommen Sie gerne auf mich zu."
str_battle:
    .autostring 34 2 "Das Menü hat ausgezeichnet geschmeckt!\pNun ist es Zeit, gegen die anderen Gäste zu kämpfen."
str_before_0:
    .autostring 34 2 "Mhm, diese Vorspeise schmeckt wirklich total lecker!"
str_after_0:
    .autostring 34 2 "Der Kampf war noch besser als die Vorspeise!"
str_later_0:
    .autostring 34 2 "Wenn ich mich entscheiden müsste, würde ich die Vorspeise noch einmal bestellen."
str_before_1:
    .autostring 34 2 "Ist es nicht toll, dass man hier bei einem guten Essen kämpfen kann?"
str_after_1:
    .autostring 34 2 "Bei so gutem Essen macht mir das Verlieren nichts ausDOTS"
str_later_1:
    .autostring 34 2 "Ich würde gerne noch einmal hierher kommen, um zu kämpfen."
str_before_2:
    .autostring 34 2 "Pass auf, ich bin schon ganz vollgefressenDOTS"
str_after_2:
    .autostring 34 2 "Aua, mein Bauch tut wehDOTS"
str_later_2:
    .autostring 34 2 "Wieso habe ich so viel gegessenDOTS"
str_before_3:
    .autostring 34 2 "Der Kellner ist ganz schon unhöflich, findest du nicht?"
str_after_3:
    .autostring 34 2 "Ich denke, ich muss den Kellner noch einmal antanzen lassen."
str_later_3:
    .autostring 34 2 "Wenn der Kellner weiterhin so unhöflich ist, werde ich ihn auch herausfordern müssen."
str_before_4:
    .autostring 34 2 "Ich habe lange nicht mehr so gut gegessen."
str_after_4:
    .autostring 34 2 "Ich habe mich so satt gegessen, dass ich nicht mehr kämpfen kannDOTS"
str_later_4:
    .autostring 34 2 "Bei so gutem Essen, muss man ordentlich zugreifen."
str_before_5:
    .autostring 34 2 "Ein Kampf?\nNa gut, danach werde ich aber einen Verdauungsspaziergang machen."
str_after_5:
    .autostring 34 2 "Zeit für einen VerdauungsspaziergangDOTS"
str_later_5:
    .autostring 34 2 "Ich denke, ich werde nun meinen Verdauungsspaziergang machen."
str_before_6:
    .autostring 34 2 "Ich warte nun schon eine ganze Weile auf mein Essen.\pWie wäre es in der Zwischenzeit mit einem Kampf?"
str_after_6:
    .autostring 34 2 "Kommt mein Essen denn bald? Ich habe HungerDOTS"
str_later_6:
    .autostring 34 2 "Ich hoffe, dass mein Essen bald kommtDOTS"
str_before_7:
    .autostring 34 2 "Ich komme jeden Tag, um hier zu essen und zu kämpfen."
str_after_7:
    .autostring 34 2 "Glückwunsch zum Sieg und guten Appetit!"
str_later_7:
    .autostring 34 2 "Ich freue mich schon auf mein nächstes Essen hier!"
.elseif LANG_EN
.endif

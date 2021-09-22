.include "overworld_script.s"
.include "callstds.s"
.include "flags.s"
.include "items.s"
.include "vars.s"
.include "ordinals.s"

.global ow_script_route_4_cave_south_trainer_0
.global ow_script_route_4_cave_south_trainer_1
.global ow_script_route_4_cave_south_trainer_2
.global ow_script_route_4_cave_south_trainer_3
.global ow_script_route_4_cave_south_trainer_4
.global ow_script_route_4_cave_south_trainer_5
.global ow_script_route_4_cave_south_trainer_6
.global ow_script_route_4_cave_south_trainer_7
.global ow_script_route_4_cave_south_trainer_8
.global ow_script_route_4_cave_south_painter
.global ow_script_route_4_south_cave_revo

ow_script_route_4_cave_south_trainer_0:
    trainerbattlestd 0 0x79 0 str_before_0 str_after_0
    loadpointer 0 str_later_0
    callstd MSG_FACE
    end
ow_script_route_4_cave_south_trainer_1:
    trainerbattlestd 0 0x7a 0 str_before_1 str_after_1
    loadpointer 0 str_later_1
    callstd MSG_FACE
    end
ow_script_route_4_cave_south_trainer_2:
    trainerbattlestd 0 0x7c 0 str_before_2 str_after_2
    loadpointer 0 str_later_2
    callstd MSG_FACE
    end
ow_script_route_4_cave_south_trainer_3:
    trainerbattlestd 0 0x1eb 0 str_before_3 str_after_3
    loadpointer 0 str_later_3
    callstd MSG_FACE
    end
ow_script_route_4_cave_south_trainer_4:
    trainerbattlestd 0 0x1ec 0 str_before_4 str_after_4
    loadpointer 0 str_later_4
    callstd MSG_FACE
    end
ow_script_route_4_cave_south_trainer_5:
    trainerbattlestd 0 0x1ed 0 str_before_5 str_after_5
    loadpointer 0 str_later_5
    callstd MSG_FACE
    end
ow_script_route_4_cave_south_trainer_6:
    trainerbattlestd 0 0x1ee 0 str_before_6 str_after_6
    loadpointer 0 str_later_6
    callstd MSG_FACE
    end
ow_script_route_4_cave_south_trainer_7:
    trainerbattlestd 0 0x1ef 0 str_before_7 str_after_7
    loadpointer 0 str_later_7
    callstd MSG_FACE
    end
ow_script_route_4_cave_south_trainer_8:
    trainerbattlestd 0 0x1f0 0 str_before_8 str_after_8
    loadpointer 0 str_later_8
    callstd MSG_FACE
    end
ow_script_route_4_cave_south_painter:
    lock
    faceplayer
    trainerbattlecont 1 0x1ca 0 str_painter_before str_painter_after painter_after
painter_after:
    lock
    loadpointer 0 str_painter_give
    callstd MSG_KEEPOPEN
    fanfare 258
    loadpointer 0 str_got_wallpaper
    callstd MSG_KEEPOPEN
    waitfanfare
    loadpointer 0 str_after_wallpaper
    callstd MSG_KEEPOPEN
    closeonkeypress
    fadescreen 1
    hidesprite LASTTALKED
    fadescreen 0
    release
    end

ow_script_route_4_south_cave_revo:
    lock
    faceplayer
    trainerbattlecont 1 0x1f1 0 str_revo_before str_revo_after revo_later
revo_later:
    loadpointer 0 str_revo_defeated
    callstd MSG_KEEPOPEN
    copyvarifnotzero 0x8000 ITEM_TM10
    copyvarifnotzero 0x8001 1
    callstd ITEM_OBTAIN
    compare LASTRESULT 0x0
    gotoif EQUAL ow_script_no_room_for_giveitem
    loadpointer 0 str_revo_leave
    callstd MSG
    fadescreen 1
    hidesprite LASTTALKED
    fadescreen 1
    releaseall
    end

.ifdef LANG_GER
str_before_0:
    .autostring 34 2 "Ich trainiere hier den lieben langen Tag!\pMeine Schläge können sogar Felsen zerschmettern!"
str_after_0:
    .autostring 34 2 "ÄhDOTS\nWas?\pD-Du hast mich einfach so besiegt?"
str_later_0:
    .autostring 34 2 "Meine Schläge können Felsen zerschmettern, aber du hast mich zertrümmertDOTS"
str_before_1:
    .autostring 34 2 "So viele talentlose Kämpfer hier!\pDabei habe nur ich eine wirkliche Chance, als Manuels Schülerin in seiner Arena aufgenommen zu werden."
str_after_1:
    .autostring 34 2 "Warte!\nDas bedeutet nicht, dass ich kein Talent zur Kämpferin hätteDOTS"
str_later_1:
    .autostring 34 2 "M-Meinst du ich bin nicht talentiert genug, um in Manuels Arena aufgenommen zu werden?"
str_before_2:
    .autostring 34 2 "Tritt!\nSchlag!\pDuck dich nicht weg, Feigling!"
str_after_2:
    .autostring 34 2 "Huah!\nIch bin zu Boden gegangen?"
str_later_2:
    .autostring 34 2 "Tritt!\nSchlag!\pIch habe mich weggeduckt, ich FeiglingDOTS"
str_before_3:
    .autostring 34 2 "Muskelkraft und Willensstärke!\pDamit werde ich dich in die Knie zwingen!"
str_after_3:
    .autostring 34 2 "Nein, warte!\nIch bin doch stärker als duDOTS"
str_later_3:
    .autostring 34 2 "Du bist mir wirklich überlegen, sowohl physisch als auch mentalDOTS"
str_before_4:
    .autostring 34 2 "Hast du dir einmal meine Oberarme angesehen?\pMit dir nehme ich es leicht auf!"
str_after_4:
    .autostring 34 2 "Wie?\pDabei bist du doch so schmächtigDOTS"
str_later_4:
    .autostring 34 2 "Unerhört, dass ich von so einem schmächtigen Kind besiegt wurdeDOTS"
str_before_5:
    .autostring 34 2 "Ich habe mein Pokémon in verschiedenen Kampfsportarten trainiert.\pDa kannst du nichts entgegensetzen!"
str_after_5:
    .autostring 34 2 "A-Aber mein ganzes TrainingDOTS"
str_later_5:
    .autostring 34 2 "Fünf Kampfsportarten habe ich meinem Pokémon beigebracht und trotzdem konntest du es besiegenDOTS"
str_before_6:
    .autostring 34 2 "Es ist geradezu lästig, dass sich alle Arten von Kämpferinnen hier tummeln.\pDie wollen doch alle nur ein Stück von Manuel ab!"
str_after_6:
    .autostring 34 2 "W-Was meinst du, dass ich auch nur auf Manuel aus wäre?"
str_later_6:
    .autostring 34 2 "Unerhört, dass du mir unterstellst, ich sei nur wegen Manuel hierDOTS\pAber man kann nicht leugnen, dass seine Muskeln sehr ästhetisch sindDOTS"
str_before_7:
    .autostring 34 2 "Ich weiß bereits, was du vorhast, bevor du überhaupt auf irgendeinen Gedanken kommst.\pVersuch doch ruhig, mich zu überlisten!"
str_after_7:
    .autostring 34 2 "Ich habe meine Niederlage kommen sehen, aber konnte nichts unternehmenDOTS"
str_later_7:
    .autostring 34 2 "Versteh' mich nicht falschDOTS\pIch wusste, was auf mich zukam, aber ich war gegen deine Stärke einfach machtlos."
str_before_8:
    .autostring 34 2 "Irgendwie habe ich mich hier verirrtDOTS\pEigentlich sollte ich jetzt in Kaskada sein!\pSo ein Mist aber auch!"
str_after_8:
    .autostring 34 2 "Toll!\pErst zu spät und dann dasDOTS"
str_later_8:
    .autostring 34 2 "Wo soll ich denn jetzt hingehen?\pWie komme ich bloß nach KaskadaDOTS"
str_painter_before:
    .autostring 34 2 "Oh, du hast mich erwischt!\pIch bin es leibhaftig!\pKaum zu fassen, nicht?\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pWie bitte?\nDu kennst mich gar nicht?\pIch bin eine große Künsterlin.\pWas fällt dir ein, mein Talent so zu missachten?"
str_painter_after:
    .autostring 34 2 "Meine PinselstricheDOTS\pSie waren nicht sauber genugDOTS"
str_painter_give:
    .autostring 34 2 "W-warte!\pIch bin eine großartige Künstlerin, das musst du mir glauben!\pIch werde dir eines meiner Bilder geben, ja?\pDann kannst du mein Talent nicht mehr bestreiten!"
str_got_wallpaper:
    .autostring 34 2 "PLAYER erhält ein Poképad-Motiv!"
str_after_wallpaper:
    .autostring 34 2 "Dieses Gemälde zeigt die drei Gründerväter der Pokémon-Liga.\pEs ist an Theatralik und Atmosphäre kaum zu überbieten, nicht wahr?\pEs ist mein großes Meisterwerk.\pIch hoffe doch sehr, dass dich zu ebenso großen Taten inspiriert!"
str_revo_before:
    .autostring 34 2 "W-Wie habe ich mich denn hierher verlaufen?\pEben war ich noch bei Albus und den anderen, und jetzt bin ich hier.\pNa egal!\pJetzt musst du herhalten!"
str_revo_after:
    .autostring 34 2 "N-Nein!\nDas sollte so nicht seinDOTS"
str_revo_defeated:
    .autostring 34 2 "O-OhDOTS\pEntschuldige bitte, dass ich dich so angegangen habe.\pIch war wohl etwas frustriert, dass ich mich verlaufen habe.\pAber ich werde schon zurecht kommen.\pNimm das bitte als eine Entschuldigung, ja?"
str_revo_leave:
    .autostring 34 2 "Ich muss dringend die anderen findenDOTS\pWo sind sie nur geblieben?\pJetzt bloß keine Zeit verlierenDOTS"
.elseif LANG_EN
.endif
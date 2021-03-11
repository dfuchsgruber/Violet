.include "overworld_script.s"
.include "callstds.s"
.include "vars.s"

.global ow_script_route_4_cave_south_trainer_0
.global ow_script_route_4_cave_south_trainer_1
.global ow_script_route_4_cave_south_trainer_2
.global ow_script_route_4_cave_south_painter

ow_script_route_4_cave_south_trainer_0:
    trainerbattlestd 0 0x79 0 str_before_0 str_after_0
    loadpointer 0 str_after_0
    callstd MSG_FACE
    end
ow_script_route_4_cave_south_trainer_1:
    trainerbattlestd 0 0x7a 0 str_before_1 str_after_1
    loadpointer 0 str_after_1
    callstd MSG_FACE
    end
ow_script_route_4_cave_south_trainer_2:
    trainerbattlestd 0 0x7c 0 str_before_2 str_after_2
    loadpointer 0 str_after_2
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

.ifdef LANG_GER
str_before_0:
    .autostring 34 2 "Ich trainiere hier den lieben langen Tag!\pMeine Schläge können sogar Felsen zerschmettern!"
str_after_0:
    .autostring 34 2 "ÄhDOTS\nWas?\pD-Du hast mich einfach so besiegt?"
str_before_1:
    .autostring 34 2 "So viele talentlose Kämpfer hier!\pDabei habe nur ich eine wirkliche Chance, als Manuels Schülerin in seiner Arena aufgenommen zu werden."
str_after_1:
    .autostring 34 2 "Warte!\nDas bedeutet nicht, dass ich kein Talent zur Kämpferin hätteDOTS"
str_before_2:
    .autostring 34 2 "Tritt!\nSchlag!\pDuck dich nicht weg, Feigling!"
str_after_2:
    .autostring 34 2 "Huah!\nIch bin zu Boden gegangen?"
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
.elseif LANG_EN
.endif
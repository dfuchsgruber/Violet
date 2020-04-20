.include "overworld_script.s"
.include "callstds.s"
.include "mugshot.s"
.include "movements.s"
.include "specials.s"
.include "ordinals.s"

.global ow_script_blackbeard_ship_cells_lucky

ow_script_blackbeard_ship_cells_lucky:
    lock
    faceplayer
    loadpointer 0 str_0
    show_mugshot MUGSHOT_LUCKY alignment=MUGSHOT_RIGHT message_type=MSG mask_name=0
    setvar 0x8004 1
    setvar 0x8005 0xB
    setvar 0x8006 0x8
    special SPECIAL_NPC_MOVE_TO
    waitmovement 0
    pause 16
    sound 9
    hidesprite 1
    checksound
    release
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Klasse, Kindchen!\pIch bin dir was schuldig!\pWie war gleich dein Name?\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pPLAYER also, gut!\pIch schätze mal, dass die Piraten auch dir die Pokémon und einige andere Dinge abgeknöpft haben.\pWenn wir von diesem Schiff runter wollen, müssen wir uns diese Dinge wiederbeschaffen.\pZufälligerweiseDOTS\nDOTSkenne ich mich hier etwas aus.\pDas Lager müsste sich im Deck unter uns befinden.\pDa finden wir, was man uns gestohlen hat.\pAber auf dem Weg dahin müssen wir vorsichtig sein.\pWenn uns die Piraten entdecken, landen wir gleich wieder hier in unseren Zellen."

.elseif LANG_EN
.endif
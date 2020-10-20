.include "overworld_script.s"
.include "callstds.s"
.include "ordinals.s"
.include "flags.s"
.include "items.s"
.include "vars.s"

.global ow_script_laubdorf_indoor_2_person_0
.global ow_script_laubdorf_indoor_2_person_1
.global ow_script_laubdorf_indoor_2_person_2

ow_script_laubdorf_indoor_2_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end
ow_script_laubdorf_indoor_2_person_1:
    loadpointer 0 str_1
    callstd MSG_FACE
    end
ow_script_laubdorf_indoor_2_person_2:
    checkflag FLAG_LAUBDORF_LAHMRAUCH
    gotoif EQUAL lahmrauch_received
    lock
    faceplayer
    loadpointer 0 str_lahmrauch_ask
    callstd MSG_YES_NO
    compare LASTRESULT 0
    gotoif EQUAL dont_give_lahmrauch
    loadpointer 0 str_give_lahmrauch
    callstd MSG_KEEPOPEN
    copyvarifnotzero 0x8000 ITEM_LAHMRAUCH
    copyvarifnotzero 0x8001 0x1
    callstd ITEM_OBTAIN
    setflag FLAG_LAUBDORF_LAHMRAUCH
lahmrauch_received:
    loadpointer 0 str_lahmrauch_received
    callstd MSG_FACE
    end
dont_give_lahmrauch:
    loadpointer 0 str_dont_give_lahmrauch
    callstd MSG_KEEPOPEN
    release
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Manchmal schlüpfen aus Eiern Baby-Pokémon.\pIch habe gehört, dass die Eltern dafür ein bestimmtes Item tragen müssen."
str_1:
    .autostring 34 2 "Viele professionelle Pokémon-Züchter versenden die geschlüpften Pokémon im Wundertausch.\pOft haben diese Pokémon hohes Potential."
str_lahmrauch_received:
    .autostring 34 2 "Lahmrauch lässt den Träger langsamer werden.\pAußerdem habe ich gehört, dass Relaxo dieses Item zur Zucht benötigen."
str_lahmrauch_ask:
    .autostring 34 2 "Fühlst du dich auch manchmal so dösig und träge?\pEin wundervolles Gefühl, nicht wahr?"
str_dont_give_lahmrauch:
    .autostring 34 2 "Was für ein Jammer!\nJemand der immer in Eile ist, kann das Leben gar nicht genießenDOTS"
str_give_lahmrauch:
    .autostring 34 2 "Eine gute Antwort!\nDie Lethargie ist eine Tugend!"

.elseif LANG_EN
str_0:
    .autostring 34 2 "Sometimes baby Pokémon hatch from eggs.\pI once heard, that the parents need to hold certain item for this to happen."
str_1:
    .autostring 34 2 "Many professional Pokémon Breeders send the hatched Pokémon on the Wondertrade.\pOften these Pokémon have great potential."
str_lahmrauch_received:
    .autostring 34 2 "Full Incense makes its holder very slow.\pAlso, I heard that Snorlax need them for breeding."
str_lahmrauch_ask:
    .autostring 34 2 "Don't you also feel drowzy sometimes?\pA wonderful feeling, right?"
str_dont_give_lahmrauch:
    .autostring 34 2 "What a shame!\pSomeone who is always in a hurry can't possibly enjoy lifeDOTS"
str_give_lahmrauch:
    .autostring 34 2 "Well spoken!\nLethargy is a virtue!"
.endif
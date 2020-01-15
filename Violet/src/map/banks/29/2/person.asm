.include "overworld_script.s"
.include "callstds.s"
.include "flags.s"
.include "items.s"
.include "vars.s"
.include "ordinals.s"

.global ow_script_route_7_person_5
.global ow_script_route_7_person_everstone
.global ow_script_route_7_person_6
.global ow_script_route_7_person_7
.global ow_script_route_7_person_8
.global ow_script_route_7_person_9

ow_script_route_7_person_5:
    loadpointer 0 str_5
    callstd MSG_FACE
    end
ow_script_route_7_person_everstone:
    checkflag FLAG_ROUTE_7_EVERSTONE
    gotoif EQUAL everstone_done
    lock
    faceplayer
    loadpointer 0 str_everstone_give
    callstd MSG_KEEPOPEN
    copyvarifnotzero 0x8000 ITEM_EWIGSTEIN
	copyvarifnotzero 0x8001 1
	callstd ITEM_OBTAIN
    compare LASTRESULT 0
    gotoif EQUAL everstone_no_space
    setflag FLAG_ROUTE_7_EVERSTONE
everstone_done:
    loadpointer 0 str_everstone_done
    callstd MSG_FACE
    end
everstone_no_space:
    loadpointer 0 str_no_space
    callstd MSG_FACE
    end
ow_script_route_7_person_6:
    loadpointer 0 str_6
    callstd MSG_FACE
    end
ow_script_route_7_person_7:
    loadpointer 0 str_7
    callstd MSG_FACE
    end
ow_script_route_7_person_8:
    loadpointer 0 str_8
    callstd MSG_FACE
    end
ow_script_route_7_person_9:
    loadpointer 0 str_9
    callstd MSG_FACE
    end


.ifdef LANG_GER
str_5:
    .autostring 34 2 "Ich wünschte ich könnte mir das Schloss Ardeal aus der Nähe ansehen, aber keines meiner Pokémon beherrscht die Vm SurferDOTS"
str_everstone_give:
    .autostring 34 2 "Trauerst du nicht auch manchmal deinen Pokémon hinterher, bevor sie sich entwickelt haben?\pNun, ich habe mir meine Augen wundgeweint, als mein niedliches Karpador sich weiterentwickelt hat.\pDir muss so etwas nicht passieren.\pNimm dieses Item."
str_no_space:
    .autostring 34 2 "Du hast dafür gar keinen Platz!\pKomm wieder, wenn du das Item auch aufnehmen kannst."
str_everstone_done:
    .autostring 34 2 "Der Ewigstein verhindert, dass das Pokémon, welches ihn trägt, sich entwickelt.\pSo kannst du deine Liebsten bei dir behaltenDOTS\pFür immer!"
str_6:
    .autostring 34 2 "Mein Vater hat mir viel vom ehemaligen Champion Lucius erzählt.\pEr hat mir gesagt, dass Lucius sich einen erbitterten Kampf mit einem legendären Pokémon geliefert haben soll!"
str_7:
    .autostring 34 2 "Ich träume davon, eines Tages für die Laz. Corp. zu arbeiten.\pDort hat man eine Chance, die Welt wirklich zu verändern!"
str_8:
    .autostring 34 2 "Wenn doch nur eines meiner Pokémon Stärke beherrschen würdeDOTS\pDann könnte ich mir das Schloss Ardeal aus der Nähe ansehen!"
str_9:
    .autostring 34 2 "Ich besuche abwechselnd im Wochentakt Haweiland und das Schloss Ardeal.\pNur nach Inferior habe ich mich noch nicht vorgewagtDOTS\pEs ist aber auch heiß dort im Norden, beim VulcanoDOTS"
.elseif LANG_EN
str_5:
    .autostring 34 2 "I wish I could take a closer look at the castle Ardeal, but none of my Pokémon knows the Hm SurferDOTS"
str_everstone_give:
    .autostring 34 2 "Don't you also sometimes miss your Pokémon in the stage before they had evovled?\pWell, I cried a lot when my cute little Magikarp finally evovled.\pBut you don't have to go through that.\pTake this item."
str_no_space:
    .autostring 34 2 "You don't have any space for that!\pCome back once you have room to take the item."
str_everstone_done:
    .autostring 34 2 "The everstone prevents any Pokémon holding it from evolving.\pThis way you can keep your beloved ones with youDOTS\pForever!"
str_6:
    .autostring 34 2 "My father told me a lot about the former champion Lucius.\pHe said that Lucius once had a very fierce fight with a legendary Pokémon!"
str_7:
    .autostring 34 2 "My dream is to work for the Laz. Corp. one day.\pOnly there you get the chance to really make a difference!"
str_8:
    .autostring 34 2 "If only one of my Pokémon knew the move StrengthDOTS\pThen I could take closer look at the castle Ardeal!"
str_9:
    .autostring 34 2 "Every other week I switch between visiting Haweiland and the castle Ardeal\pOnly to Inferior I never dared to goDOTS\pIt really is freaking hot near that VulcanoDOTS"
.endif
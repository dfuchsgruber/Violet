
.include "overworld_script.s"
.include "flags.s"
.include "items.s"
.include "callstds.s"

.global ow_script_haweiland_bait_vendor
ow_script_haweiland_bait_vendor:
    setflag TRANS_DISABLE
    lock
    faceplayer
    preparemsg str_0
    waitmsg
    pokemart3 mart sell_default_items=0
    loadpointer 0x0 str_1
    callstd MSG_KEEPOPEN
    clearflag TRANS_DISABLE
    release
    end

mart:
    .hword ITEM_KOEDER, ITEM_GOLDKOEDER, 0

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Ich verkaufe Köder, mit denen du starke Pokémon angeln kannst.\pSieh dir mein Sortiment ruhig an!"
str_1:
    .autostring 34 2 "Komm jederzeit wieder.\pWenn du starke Pokémon angeln möchtest, solltest du Köder verwenden."

.elseif LANG_EN
str_0:
    .autostring 34 2 "I sell baits you can catch strong Pokémon with.\pLook my broad range of baits!"
str_1:
    .autostring 34 2 "Come again whenever you want to.\pIf you want to fish for strong Pokémon you should use a bait."

.endif
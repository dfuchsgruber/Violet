.include "callstds.s"
.include "overworld_script.s"
.include "vars.s"
.include "ordinals.s"
.include "flags.s"
.include "mugshot.s"

.global ow_script_route_5_clouds_person_0
.global ow_script_route_5_clouds_person_1
.global ow_script_route_5_clouds_icarus

ow_script_route_5_clouds_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end
ow_script_route_5_clouds_person_1:
    loadpointer 0 str_1
    callstd MSG_FACE
    end
ow_script_route_5_clouds_icarus:
    checkflag FLAG_ROUTE_5_CLOUD_ARIADOS_DEFEATED
    gotoif EQUAL make_cloud
    loadpointer 0 str_2
    show_mugshot MUGSHOT_ICARUS hide_mugshot=0 message_type=MSG_KEEPOPEN
    yesnobox 23 7
    compare LASTRESULT 1
    gotoif EQUAL icarus_down
    loadpointer 0 str_4
    callstd MSG
    hide_mugshot
    release
    end
icarus_down:
    loadpointer 0 str_3
    callstd MSG
    hide_mugshot
    warpmuted 3 23 0xFF 0xe 0x7
    waitstate
    release
    end
make_cloud:
    lock
    faceplayer
    call ow_script_route_5_icarus_receive_cloud
    closeonkeypress
    hide_mugshot
    fadescreen 1
    hidesprite LASTTALKED
    hidesprite 19
    fadescreen 0
    release
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Ich erforsche diese schwebenden Inseln schon mein halbes Leben lang.\pIch frage mich, wieso diese Insel von Käfer-Pokémon geradezu überrannt wurdeDOTS"
str_1:
    .autostring 34 2 "Diese Spinnennetze machen mich ganz kirreDOTS\pEgal wo man hinsieht, ist man von ihnen umgeben!\pMan fühlt sich einfach unwohlDOTS"
str_2:
    .autostring 34 2 "Wenn du willst, dass ich dir eine Wolke webe, musst du mir den Wolkenfaden schon beschaffen.\pOder willst du etwa, dass ich dich wieder auf den Boden bringe?"
str_3:
    .autostring 34 2 "Ganz wie du möchtest.\pHalt' dich gut fest, es geht abwärts!"
str_4:
    .autostring 34 2 "Sehr gut!\pDann mal los, oder?\pManche der Käfer-Pokémon in dieser Höhle sind in der Lage, den seltenen Wolkengarn herzustellen."
.elseif LANG_EN
.endif
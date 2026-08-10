.include "overworld_script.s"
.include "callstds.s"
.include "flags.s"
.include "ordinals.s"
.include "vars.s"
.include "items.s"

.global ow_script_route_4_clouds_swamp_house_inside_person_0
.global ow_script_route_4_clouds_swamp_house_inside_person_1

ow_script_route_4_clouds_swamp_house_inside_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end

ow_script_route_4_clouds_swamp_house_inside_person_1:
    checkflag FLAG_ROUTE_4_CLOUDS_POISON_GEM
    gotoif EQUAL got_gem
    lock
    faceplayer
    loadpointer 0x0 str_before_give_gem
    callstd MSG_KEEPOPEN
    copyvarifnotzero 0x8000 ITEM_GIFTJUWEL
    copyvarifnotzero 0x8001 1
    callstd ITEM_OBTAIN
    compare LASTRESULT 0x0
    gotoif EQUAL ow_script_no_room_for_giveitem
got_gem:
    lock
    faceplayer
    loadpointer 0x0 str_after_give_gem
    callstd MSG_KEEPOPEN
    setflag FLAG_ROUTE_4_CLOUDS_POISON_GEM
    release
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Hier in den Sümpfen scheint es kaum antike Ruinen zu geben.\pVermultich hat die antike Zivilisation diesen Ort wegen der giftigen Dämpfe gemieden."
str_before_give_gem:
    .autostring 34 2 "Vor einigen Tage hab ich in den Sümpfen einen seltsamen Edelstein gefunden.\pSieh in dir mal anDOTS"
str_after_give_gem:
    .autostring 34 2 "Dieser Edelstein ist mehr suspekt, ich bin froh, ihn los geworden zu sein."
.elseif LANG_EN
str_0:
    .autostring 34 2 "There seem to be hardly any ancient ruins in the swamps.\pPresumably, the ancient civilization avoided this place because of the poisonous fumes."
str_before_give_gem:
    .autostring 34 2 "A few days ago, I found a strange gemstone in the swamps.\pTake a look at itDOTS"
str_after_give_gem:
    .autostring 34 2 "This gemstone is rather suspicious, I'm glad to be rid of it."
.endif
.include "overworld_script.s"
.include "callstds.s"
.include "items.s"
.include "flags.s"
.include "vars.s"
.include "ordinals.s"
.include "sav_keys.s"
.include "specials.s"

.global ow_script_route_7_legendary_fishermans_house_person_0
.global ow_script_route_7_legendary_fishermans_house_person_1
.global ow_script_route_7_legendary_fishermans_house_person_2
.global ow_script_route_7_legendary_fishermans_house_person_3
.global ow_script_route_7_legendary_fishermans_house_legendary_fisherman

ow_script_route_7_legendary_fishermans_house_person_0:
    loadpointer 0 str_0
    callstd MSG_FACE
    end
ow_script_route_7_legendary_fishermans_house_person_1:
    loadpointer 0 str_1
    callstd MSG_FACE
    end
ow_script_route_7_legendary_fishermans_house_person_2:
    loadpointer 0 str_2
    callstd MSG_FACE
    end
ow_script_route_7_legendary_fishermans_house_person_3:
    loadpointer 0 str_3
    callstd MSG_FACE
    end
ow_script_route_7_legendary_fishermans_house_legendary_fisherman:
    checkflag FLAG_ROUTE_7_LEGENDARY_FISHERMAN_RECEIVED_SHINING_BAIT
    gotoif EQUAL done
    lock
    faceplayer
    loadpointer 0 str_legendary_fisherman
    setvar 0x8000 1
    special SPECIAL_NAME_SHOW
    loadpointer 0 str_before
    callstd MSG_KEEPOPEN
    savcomparekey SAV_KEY_FISHING_ENCOUNTERS 5
    gotoif LESS not_enough
    loadpointer 0 str_enough
    callstd MSG_KEEPOPEN
    special SPECIAL_NAME_DELETE
    copyvarifnotzero 0x8000 ITEM_LEUCHTKOEDER
    copyvarifnotzero 0x8001 1
    callstd ITEM_OBTAIN
    loadpointer 0 str_after
    callstd MSG_KEEPOPEN
    setflag FLAG_ROUTE_7_LEGENDARY_FISHERMAN_RECEIVED_SHINING_BAIT
done:
    loadpointer 0 str_legendary_fisherman
    setvar 0x8000 1
    special SPECIAL_NAME_SHOW
    loadpointer 0 str_done
    callstd MSG_FACE
    special SPECIAL_NAME_DELETE
    end

not_enough:
    loadpointer 0 str_not_enough
    callstd MSG_FACE
    special SPECIAL_NAME_DELETE
    end



.ifdef LANG_GER
str_0:
    .autostring 34 2 "Der legendäre Angler ist eine Ikone!\pEr hat jedes Pokémon, das sich im Ozean herumtreibt, eigens geangelt und aufgezogen.\pJeder Angler kann nur davon träumen, eines Tages wie er zu sein."
str_1:
    .autostring 34 2 "Es heißt, der legendäre Angler sei auf einem Boot für drei Jahre herumgetrieben, ehe er Land gefunden hätte.\pNiemand außer ihm hätte so etwas überleben können!"
str_2:
    .autostring 34 2 "Auf seinen Reisen soll der legendäre Angler sogar herausgefunden haben, wo sich Atlantea, die legendäre Stadt befindet!"
str_3:
    .autostring 34 2 "Der legendäre Angler ist ein hervorragender Trainer.\pEs heißt, dass er der einzige Mensch ist, den der Pirat Blackbeard wirklich fürchtet."
str_done:
    .autostring 34 2 "Es gibt immer einen Grund, die Angelrute auszuwerfen und zu sehen, welches Geschöpf anbeißt.\pDas Angeln steckt wie das Leben voller Überraschungen."
str_before:
    .autostring 34 2 "Ich bin der, den viele den legendären Angler nennen.\pIch habe in meinem Leben viel erlebt und gesehen, und immer hatte ich eine Angelroute dabei.\pHast du das Zeug zu einem richtigen Angler?"
str_not_enough:
    .autostring 34 2 "Noch hast du nicht ansatzweise bewiesen, dass dir das Angeln eine Herzensangelegenheit ist.\pÜbe viel, und wenn du denkst, ein wahrer Meister im Angeln zu sein, werden wir uns erneut unterhalten."
str_enough:
    .autostring 34 2 "Wahrlich!\pDu bist ein Angler durch und durch.\pJemandem wie dich kann ich etwas sehr Besonders guten Gewissens anvertrauen."
str_after:
    .autostring 34 2 "Dies ist der wertvollste aller Köder, denn er lockt gezielt schillerende Pokémon an.\pIn meinem ganzen Leben habe ich nur ein oder zwei davon gesehen, aber ich bin sicher, dass er in deinen Händen gut aufgehoben ist."
str_legendary_fisherman:
    .string "Legendärer Angler"

.elseif LANG_EN
str_0:
    .autostring 34 2 "The legendary fisherman is an icon!\pHe caught every Pokémon living in the ocean by himself and raised it afterwards.\pEvery fisherman can only aspire to become like him one day."
str_1:
    .autostring 34 2 "It is said that the legendary fisherman wandered arround the sea for three years until he finally found an island.\pNobody but him could have endured such an adventure."
str_2:
    .autostring 34 2 "On his journeys the legendary fisherman is supposed to have even found the legendary city of Atlantea!"
str_3:
    .autostring 34 2 "The legendary fisherman is a brilliant trainer.\pPeople say that he is the only man on earth that the pirate Blackbeard really fears to this very day."
str_done:
    .autostring 34 2 "There always is a reason to throw the rod into the ocean and see what creature bites.\pFishing is like life, full of surprises."
str_before:
    .autostring 34 2 "I am the one that people call the legendary fisherman.\pI have gone through a lot of adventures over my lifetime, and always I had my rod with me.\pAre you ought to be a fisherman by heart?"
str_not_enough:
    .autostring 34 2 "HmmDOTS\nYou have not yet proven that fishing is what your heart truly desires.\pPractice a lot and even more and return to me, when you think that you have mastered the craft of fishing.\pWe will talk again once this time has come."
str_enough:
    .autostring 34 2 "Truly!\pYou are a fisherman through and through!\pWithout any hesitation I can award you with this."
str_after:
    .autostring 34 2 "This is the most valuable of all baits, as it attracts shiny Pokémon.\pIn my entire life I only saw one or two of those, but I am sure that you will make good use of it."

str_legendary_fisherman:
    .string "Legendary Fisherman"
.endif
.include "overworld_script.s"
.include "callstds.s"
.include "ordinals.s"
.include "vars.s"
.include "flags.s"
.include "specials.s"

.global ow_script_laubdorf_daycare_outside

ow_script_laubdorf_daycare_outside:
    special 0x187
    compare LASTRESULT 2
    gotoif EQUAL end_outside
    special 0x188
    lock
    faceplayer
    special SPECIAL_DAYCARE_BUFFER_NAMES
    special2 LASTRESULT SPECIAL_DAYCARE_GET_STATE
    compare LASTRESULT 1
    gotoif EQUAL outside_egg_in_daycare
    compare LASTRESULT 2
    gotoif EQUAL outside_one_pokemon_in_daycare
    compare LASTRESULT 3
    gotoif EQUAL outside_two_pokemon_in_daycare
    loadpointer 0 str_outside_no_pokemon_in_daycare
    callstd MSG_KEEPOPEN
end_outside:
    release
    end

outside_egg_in_daycare:
    loadpointer 0 str_outside_egg_in_daycare
    callstd MSG_YES_NO
    compare LASTRESULT 1
    gotoif EQUAL take_egg
    loadpointer 0 str_outside_confirm_reject_egg
    callstd MSG_YES_NO
    compare LASTRESULT 1
    gotoif EQUAL take_egg
    loadpointer 0 str_outside_egg_rejected
    callstd MSG_KEEPOPEN
    clearflag FLAG_DAYCARE_EGG_SPAWNED
    special SPECIAL_DAYCARE_REMOVE_EGG
    release
    end

take_egg:
    special2 LASTRESULT SPECIAL_INCUBATOR_HAS_EMPTY_SLOT
    compare LASTRESULT 1
    gotoif EQUAL egg_into_incubator
    special2 LASTRESULT SPECIAL_PLAYER_PARTY_RECOUNT
    compare LASTRESULT 6
    gotoif EQUAL no_space
    special SPECIAL_DAYCARE_OBTAIN_EGG
    fanfare 0x101
    loadpointer 0 str_received_egg
    callstd MSG_KEEPOPEN
    waitfanfare
    closeonkeypress
    goto egg_received

egg_into_incubator:
    special SPECIAL_DAYCARE_OBTAIN_EGG_INTO_INCUBATOR
    fanfare 0x101
    loadpointer 0 str_received_egg
    callstd MSG_KEEPOPEN
    waitfanfare
    loadpointer 0 str_into_incubator
    callstd MSG_KEEPOPEN
    closeonkeypress
egg_received:
    loadpointer 0 str_take_care_of_egg
    callstd MSG_KEEPOPEN
    clearflag FLAG_DAYCARE_EGG_SPAWNED
    release
    end

no_space:
    loadpointer 0 str_no_space
    callstd MSG_KEEPOPEN
    release
    end

outside_one_pokemon_in_daycare:
    special SPECIAL_DAYCARE_BUFFER_NAMES
    loadpointer 0 str_outside_one_pokemon_in_daycare
    callstd MSG_KEEPOPEN
    release
    end

outside_two_pokemon_in_daycare:
    special SPECIAL_DAYCARE_BUFFER_NAMES
    loadpointer 0 str_outside_two_pokemon_in_daycare
    callstd MSG_KEEPOPEN
    special SPECIAL_DAYCARE_BUFFER_COMPATIBILITY_STRING
    special SPECIAL_PRINT_BUFFERED_TEXT
    waitmsg
    waitkeypress
    release
    end

.ifdef LANG_GER
str_outside_no_pokemon_in_daycare:
    .autostring 34 2 "Ich kümmere mich mit meiner Frau um die Pokémon in der Pension.\pWenn wir Pokémon für dich aufziehen sollen, sprich am Besten mit meiner Frau."
str_outside_egg_in_daycare:
    .autostring 34 2 "Ach, du bist es!\pAls wir deine Pokémon aufgezogen haben, durften wir eine Überrasschung erleben.\pDeine Pokémon haben nun ein Ei!\pMöchtest du es haben?"
str_outside_confirm_reject_egg:
    .autostring 34 2 "Bist du sicher?\pWenn du es nicht nimmst, werde ich es behalten.\pOder möchtest du das Ei doch haben?"
str_outside_egg_rejected:
    .autostring 34 2 "Dann werde ich das Ei behalten."
str_received_egg:
    .autostring 34 2 "PLAYER hat das Ei vom Pensionsleiter erhalten!"
str_into_incubator:
    .autostring 34 2 "PLAYER platziert es im Inkubator."
str_no_space:
    .autostring 34 2 "Du hast keinen Platz für das Ei!\pKomm wieder, wenn du Platz geschaffen hast.\pIch passe solange darauf auf."
str_outside_one_pokemon_in_daycare:
    .autostring 34 2 "Ach, du bist es!\nSchön, dich zu sehen.\pDeinem BUFFER_1 geht es sehr gut."
str_outside_two_pokemon_in_daycare:
    .autostring 34 2 "Ach, du bist es!\nSchön, dich zu sehen.\pDeine Pokémon BUFFER_1 und BUFFER_2 entwickeln sich prächtig."
str_take_care_of_egg:
    .autostring 34 2 "Pass gut darauf auf!"

.elseif LANG_EN
str_outside_no_pokemon_in_daycare:
    .autostring 34 2 "Together with my wife I raise Pokémon here in the daycare.\pIf I should raise one of your Pokémon, speak to my wife."
str_outside_egg_in_daycare:
    .autostring 34 2 "Oh, it's you!\pWhile raising your Pokémon we were suprised.\pYour Pokémon now have an egg!\pDo you want to have it?"
str_outside_confirm_reject_egg:
    .autostring 34 2 "Are you sure?\pIf you don't take the egg, I will.\pOr do you want to have it?"
str_outside_egg_rejected:
    .autostring 34 2 "Then I will keep the egg."
str_received_egg:
    .autostring 34 2 "PLAYER has received the egg from the daycare man!"
str_into_incubator:
    .autostring 34 2 "PLAYER puts it into the incubator."
str_no_space:
    .autostring 34 2 "You have no space for the egg.\pCome again, if you have made room for it.\pI will look after the egg meanwhile."
str_outside_one_pokemon_in_daycare:
    .autostring 34 2 "Oh, it's you!\pNice to see you.\pYour BUFFER_1 is doing very well!"
str_outside_two_pokemon_in_daycare:
    .autostring 34 2 "Oh, it's you!\pNice to see you.\pYour Pokémon BUFFER_1 and BUFFER_2 are doing very well!"
str_take_care_of_egg:
    .autostring 34 2 "Take care of it!"

.endif
.include "callstds.s"
.include "flags.s"
.include "vars.s"
.include "ordinals.s"
.include "overworld_script.s"
.include "move_tutor.s"
.include "movements.s"

.global ow_script_beach_house_move_tutor
ow_script_beach_house_move_tutor:
    lock
    faceplayer
    loadpointer 0x0 str_0
    callstd MSG_KEEPOPEN
    call move_tutor_item_check
    compare LASTRESULT 0
    gotoif NOT_EQUAL can_pay
    closeonkeypress
    release
    end


can_pay:
    applymovement LASTTALKED mov_exclam
    waitmovement 0x0
    lock
    faceplayer
    loadpointer 0x0 str_can_pay
    callstd MSG_YES_NO
    compare LASTRESULT 0x1
    gotoif LESS abort
    loadpointer 0x0 str_choose_pokemon
    callstd MSG
    setflag TRANS_DISABLE
    clearflag TRANS_PALETTE_FETCH
    setvar 0x8005 MOVE_TUTOR_DELEGATOR
    call ow_script_move_tutor_do
    clearflag TRANS_DISABLE
    compare LASTRESULT 0x0
    gotoif EQUAL abort
    call ow_script_move_tutor_pay_items
    loadpointer 0x0 str_move_tutor_pay_items
    callstd MSG
    end


abort:
    loadpointer 0x0 str_bye
    callstd MSG_KEEPOPEN
    closeonkeypress
    release
    end

mov_exclam:
    .byte SAY_EXCLAM, STOP


.ifdef LANG_GER
str_0:
    .autostring 34 2 "Wenn meine Frau wüsste, dass ich mich hier herumtreibeDOTS\pAber ich habe einfach einen Delegator zuhause zurück gelassen.\pWenn du mir drei Minipilze oder einen Riesenpilz bringst, kann ich einem deiner Pokémon die Attacke Delegator beibringen."
str_can_pay:
    .autostring 34 2 "Hervorragend!\pDu hast BUFFER_2-mal\nBUFFER_1 dabei!\pMöchtest du, dass ich einem deiner Pokémon Delegator beibringe?"
str_choose_pokemon:
    .autostring 34 2 "Welchen deiner Pokémon soll ich Delegator beibringen?"
str_bye:
    .autostring 34 2 "Ganz wie du meinst.\pMir hat der Delegator schon viele glückliche Stunden im Strandhaus beschertDOTS"
.elseif LANG_EN
str_0:
    .autostring 34 2 "If my wife knew I was lurking arround hereDOTS\pBut I simply left a substitute back at home and sneaked in here.\pIf you can bring me three Tiny Mushroom or one Big Mushroom I can teach one of your Pokémon Substitute."
str_can_pay:
    .autostring 34 2 "Very well!\pYou have BUFFER_2-times\nBUFFER_1 with you!\pDo you want me to learn one of your Pokémon Substitute?"
str_choose_pokemon:
    .autostring 34 2 "Which Pokémon should learn Substitute?"
str_bye:
    .autostring 34 2 "As you like.\pFor me, Substitute gave me many happy hours here in the beach houseDOTS"
.endif

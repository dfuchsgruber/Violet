.include "callstds.s"
.include "flags.s"
.include "vars.s"
.include "ordinals.s"
.include "overworld_script.s"
.include "move_tutor.s"
.include "movements.s"

.global ow_script_bluetenbach_clouds_move_tutor
ow_script_bluetenbach_clouds_move_tutor:
    lock
    faceplayer
    setvar 0x8004 MOVE_TUTOR_FOKUSSTOSS
    callasm move_tutor_set_flag
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
    setvar 0x8005 MOVE_TUTOR_FOKUSSTOSS
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
    .autostring 34 2 ".TEXT_DELAY_SHORT.TEXT_DELAY_SHORT.TEXT_DELAY_SHORT .TEXT_DELAY_SHORT.TEXT_DELAY_SHORT.TEXT_DELAY_SHORT\n.TEXT_DELAY_SHORT.TEXT_DELAY_SHORT.TEXT_DELAY_SHORT .TEXT_DELAY_SHORT.TEXT_DELAY_SHORT.TEXT_DELAY_SHORT\pAn diesem Ort gelingt es mir, mich ganz und gar zu fokussieren.\pDie Kraft, die einem ein solcher Fokus gibtDOTS\pIch kann sie einem deiner Pokémon zeigen.\pIm Gegenzug für drei Minipilize oder einen Riesenpilz bringe ich einem deiner Pokémon den Angriff Fokusstoß bei."
str_can_pay:
    .autostring 34 2 "Hervorragend!\pDu hast BUFFER_2-mal\nBUFFER_1 dabei!\pMöchtest du, dass ich einem deiner Pokémon Fokusstoß beibringe?"
str_choose_pokemon:
    .autostring 34 2 "Welchen deiner Pokémon soll ich Fokusstoß beibringen?"
str_bye:
    .autostring 34 2 "Ganz wie du meinst.\pDu unterschätzt wohl die Kraft, die ein Fokusstoß aufbringen kann.\pAber das ist dein Problem."
.elseif LANG_EN
.endif

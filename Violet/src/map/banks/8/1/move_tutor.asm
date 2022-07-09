.include "callstds.s"
.include "flags.s"
.include "vars.s"
.include "ordinals.s"
.include "overworld_script.s"
.include "move_tutor.s"
.include "movements.s"

.global ow_script_kaskada_clouds_move_tutor
ow_script_kaskada_clouds_move_tutor:
    lock
    faceplayer
    setvar 0x8004 MOVE_TUTOR_DRACHENPULS
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
    setvar 0x8005 MOVE_TUTOR_DRACHENPULS
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
    .autostring 34 2 "Ich bin ein Schüler von Lucius, dem ehemaligen Champion.\pGemeinsam mit Dany von den Top Vier habe ich die Kunst, Drachenpokémon zu beherrschen, erlernt.\pWenn du mir drei Minipilze oder einen Riesenpilz bringst, kann ich einem deiner Pokémon die Attacke Drachenpuls bebringen."
str_can_pay:
    .autostring 34 2 "Hervorragend!\pDu hast BUFFER_2-mal\nBUFFER_1 dabei!\pMöchtest du, dass ich einem deiner Pokémon Drachenpuls beibringe?"
str_choose_pokemon:
    .autostring 34 2 "Welchen deiner Pokémon soll ich Drachenpuls beibringen?"
str_bye:
    .autostring 34 2 "Wie unklug von dir!\pSowohl Dany von den Top Vier als auch Lucius, der ehemalige Champion, halten hohe Stücke auf diesen Angriff!"
.elseif LANG_EN
str_0:
    .autostring 34 2 "I am an apparentice of Lucius, the former champ.\pTogether with Dany I have mastered the art of controlling dragon pokémon.\pIf you can bring me three Tiny Mushrooms or one Big Mushroom I can learn on of your pokémon the move Dragon Pulse."
str_can_pay:
    .autostring 34 2 "Very well!\pYou have BUFFER_2-times\nBUFFER_1 with you!\pDo you want me to learn one of your pokémon Dragon Pulse?"
str_choose_pokemon:
    .autostring 34 2 "Which pokémon should learn dragon pulse?"
str_bye:
    .autostring 34 2 "What a poor choice.\pDany of the Elite Four as well as Lucius the former champ very much favored this move."
.endif

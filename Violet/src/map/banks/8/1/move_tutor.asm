.include "callstds.s"
.include "flags.s"
.include "vars.s"
.include "ordinals.s"
.include "overworld_script.s"
.include "movements.s"
.include "items.s"

.global ow_script_kaskada_clouds_move_tutor
ow_script_kaskada_clouds_move_tutor:
    checkflag FLAG_ITEM_TM_DRAGON_PULSE
    gotoif EQUAL done
    lock
    faceplayer
    loadpointer 0 str_0
    callstd MSG_KEEPOPEN
    copyvarifnotzero 0x8000 ITEM_TM58
    copyvarifnotzero 0x8001 1
    callstd ITEM_OBTAIN
    compare LASTRESULT 0x0
    gotoif EQUAL no_room_for_item
    setflag FLAG_ITEM_TM_DRAGON_PULSE
    release
    end
done:
    loadpointer 0 str_bye
    callstd MSG_FACE
    end
no_room_for_item:
    loadpointer 0 str_no_room_for_item
    callstd MSG_KEEPOPEN
    release
    end


.ifdef LANG_GER
str_0:
    .autostring 34 2 "Ich bin ein Schüler von Lucius, dem ehemaligen Champion.\pGemeinsam mit Dany von den Top Vier habe ich die Kunst, Drachenpokémon zu beherrschen, erlernt."
str_bye:
    .autostring 34 2 "Drachenpuls ist eine mächtige Attacke, die die Aura eines Drachenpokémon kanalisiert.\pNutze sie mit Bestimmung!"
str_no_room_for_item:
    .autostring 34 2 "Du hast keinen Platz im Beutel.\pKomm wieder, wenn du Platz hast."
.elseif LANG_EN
str_0:
    .autostring 34 2 "I am a student of Lucius, the former Champion.\pTogether with Dany of the Elite Four, I have learned the art of mastering Dragon Pokémon."
str_bye:
    .autostring 34 2 "Dragon Pulse is a powerful move that channels the aura of a Dragon Pokémon.\pUse it with purpose!"
str_no_room_for_item:
    .autostring 34 2 "You have no room in your bag.\pCome back when you have room."  
.endif

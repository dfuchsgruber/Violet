.include "callstds.s"
.include "flags.s"
.include "vars.s"
.include "ordinals.s"
.include "overworld_script.s"
.include "move_tutor.s"
.include "movements.s"

make_move_tutor_std move_tutor str_0 str_bye

.global ow_script_kaskada_clouds_move_tutor
ow_script_kaskada_clouds_move_tutor:
    call move_tutor
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "Ich bin ein Schüler von Lucius, dem ehemaligen Champion.\pGemeinsam mit Dany von den Top Vier habe ich die Kunst, Drachenpokémon zu beherrschen, erlernt.\pWenn du mir BUFFER_1x Minipilz oder BUFFER_2x Riesenpilz bringst, kann ich einem deiner Pokémon die Attacke BUFFER_3 bebringen."
str_bye:
    .autostring 34 2 "Wie unklug von dir!\pSowohl Dany von den Top Vier als auch Lucius, der ehemalige Champion, halten hohe Stücke auf diesen Angriff!"
.elseif LANG_EN
str_0:
    .autostring 34 2 "I am a student of Lucius, the former Champion.\pTogether with Dany of the Elite Four, I have learned the art of controlling Dragon Pokémon.\pIf you bring me BUFFER_1x Tiny Mushroom or BUFFER_2x Big Mushroom, I can teach one of your Pokémon the move BUFFER_3."
str_bye:
    .autostring 34 2 "How foolish of you!\pBoth Dany of the Elite Four and Lucius, the former Champion, hold this move in high regard!"     
.endif

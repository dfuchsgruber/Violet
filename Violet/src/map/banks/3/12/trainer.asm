.include "overworld_script.s"
.include "callstds.s"

.global ow_script_route_11_trainer_0
.global ow_script_route_11_trainer_1
.global ow_script_route_11_trainer_2
.global ow_script_route_11_trainer_3
.global ow_script_route_11_trainer_4
.global ow_script_route_11_trainer_5
.global ow_script_route_11_trainer_6
.global ow_script_route_11_trainer_7
.global ow_script_route_11_trainer_8
.global ow_script_route_12_trainer_couple

ow_script_route_11_trainer_0:
    trainerbattlestd 0 0xe1 0 str_trainer0_challange str_trainer0_defeat
    loadpointer 0 str_trainer0_defeat
    callstd MSG_FACE
    end
ow_script_route_11_trainer_1:
    trainerbattlestd 0 0xe2 0 str_trainer1_challange str_trainer1_defeat
    loadpointer 0 str_trainer1_defeat
    callstd MSG_FACE
    end
ow_script_route_11_trainer_2:
    trainerbattlestd 0 0xe3 0 str_trainer2_challange str_trainer2_defeat
    loadpointer 0 str_trainer2_defeat
    callstd MSG_FACE
    end
ow_script_route_11_trainer_3:
    trainerbattlestd 0 0xe4 0 str_trainer3_challange str_trainer3_defeat
    loadpointer 0 str_trainer3_defeat
    callstd MSG_FACE
    end
ow_script_route_11_trainer_4:
    trainerbattlestd 0 0xe5 0 str_trainer4_challange str_trainer4_defeat
    loadpointer 0 str_trainer4_defeat
    callstd MSG_FACE
    end
ow_script_route_11_trainer_5:
    trainerbattlestd 0 0xe6 0 str_trainer5_challange str_trainer5_defeat
    loadpointer 0 str_trainer5_defeat
    callstd MSG_FACE
    end
ow_script_route_11_trainer_6:
    trainerbattlestd 0 0xe7 0 str_trainer6_challange str_trainer6_defeat
    loadpointer 0 str_trainer6_defeat
    callstd MSG_FACE
    end
ow_script_route_11_trainer_7:
    trainerbattlestd 0 0xe8 0 str_trainer7_challange str_trainer7_defeat
    loadpointer 0 str_trainer7_defeat
    callstd MSG_FACE
    end
ow_script_route_11_trainer_8:
    trainerbattlestd 0 0xe9 0 str_trainer8_challange str_trainer8_defeat
    loadpointer 0 str_trainer8_defeat
    callstd MSG_FACE
    end
ow_script_route_12_trainer_couple:
    trainerbattledouble 4 0x17d 0 str_trainer9_challange str_trainer9_defeat str_cant_battle9
    loadpointer 0 str_trainer9_defeat
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_trainer0_challange:
    .autostring 34 2 "Weiter südlich liegt ein Friedhof.\pSo unheimlich, wie es dort ist, bleibe ich lieder im NordenDOTS"
str_trainer0_defeat:
    .autostring 34 2 "Hast du keine Angst vor Geistern?"
str_trainer1_challange:
    .autostring 34 2 "Ich laufe hier schon den ganzen Tag!"
str_trainer1_defeat:
    .autostring 34 2 "ArghDOTS\nMeine Beine!"
str_trainer2_challange:
    .autostring 34 2 "Ich bin bekannt als die beste Schwimmerin meines Heimatdorfes!"
str_trainer2_defeat:
    .autostring 34 2 "Hier in Theto ist die Schwimmer-Konkurrenz sehr groß."
str_trainer3_challange:
    .autostring 34 2 "Wenn ich beim Schwimmen doch nur Musik hören könnte."
str_trainer3_defeat:
    .autostring 34 2 "Ein Orchester auf hoher See, das wäre doch etwas, nicht?"
str_trainer4_challange:
    .autostring 34 2 "Fühlst du die Geister der Verstorbenen in der Luft?"
str_trainer4_defeat:
    .autostring 34 2 "UffDOTS\nIch bin wohl erschaudertDOTS"
str_trainer5_challange:
    .autostring 34 2 "Auf Ceometria lebt die größte aller Wahrsagerinen.\pMan kann so viel von ihr lernen!"
str_trainer5_defeat:
    .autostring 34 2 "Ich seheDOTS\nDOTSdass auch du ihr begegnen wirst."
str_trainer6_challange:
    .autostring 34 2 "Die Meere sind gefährlich.\pNicht zuletzt wegen den Piraten, die hier ihr Unwesen treiben."
str_trainer6_defeat:
    .autostring 34 2 "Ich habe gehört, dass der Pirat Blackbeard auch Gefangene nimmtDOTS"
str_trainer7_challange:
    .autostring 34 2 "Die Meere sind gefährlich.\pNicht zuletzt wegen den Piraten, die hier ihr Unwesen treiben."
str_trainer7_defeat:
    .autostring 34 2 "Ich habe gehört, dass der Pirat Blackbeard auch Gefangene nimmtDOTS"
str_trainer8_challange:
    .autostring 34 2 "Die Pokémon, die hier beißen, sind verflucht.\pDa ist der Reiz beim Angeln gleich viel größer!"
str_trainer8_defeat:
    .autostring 34 2 "Da hat mich wohl das Unglück der Pokémon verfolgtDOTS"
str_trainer9_challange:
    .autostring 34 2 "Mein Partner und ich haben unsere Pokémon gemeinsam trainiert!\pDas macht uns als Duo unschlagbar!"
str_trainer9_defeat:
    .autostring 34 2 "Hast du deine Pokémon etwa auch gemeinsam trainiert?"
str_cant_battle9:
    .autostring 34 2 "Unsere Pokémon sind es gewohnt, als Team zu kämpfen.\pAlleine treten wir nicht an!"
.elseif LANG_EN
str_trainer0_challange:
    .autostring 34 2 "A little bit more south is a cemeteray.\pSince it is very frightening there I will stay northDOTS"
str_trainer0_defeat:
    .autostring 34 2 "Are you not afraid of ghosts?"
str_trainer1_challange:
    .autostring 34 2 "I kept running here all day!"
str_trainer1_defeat:
    .autostring 34 2 "ArghDOTS\nMy legs!"
str_trainer2_challange:
    .autostring 34 2 "I am known as the best swimmer in my home village!"
str_trainer2_defeat:
    .autostring 34 2 "Here in Theto the swimmer competition is very rough."
str_trainer3_challange:
    .autostring 34 2 "If only I could hear music while swimming."
str_trainer3_defeat:
    .autostring 34 2 "An orchestra on the oceans, that would be something, right?"
str_trainer4_challange:
    .autostring 34 2 "Do you feel the ghosts of people already passed?"
str_trainer4_defeat:
    .autostring 34 2 "UffDOTS\nSeems like I cringedDOTS"
str_trainer5_challange:
    .autostring 34 2 "On Ceometria the greatest of all furtune tellers lives.\pOne can learn so much from her!"
str_trainer5_defeat:
    .autostring 34 2 "I forseeDOTS\nDOTSthat also you will meet her."
str_trainer7_challange:
    .autostring 34 2 "The sea is dangerous.\pNot to speak of the pirates that roam here."
str_trainer7_defeat:
    .autostring 34 2 "I heard that the pirate Blackbeard also takes captives."
str_trainer8_challange:
    .autostring 34 2 "The Pokémon that bite here are cursed.\pThat makes fishing even more interesting!"
str_trainer8_defeat:
    .autostring 34 2 "Seems like the spell that was cast upon the water here has found me as wellDOTS"
.endif
.include "overworld_script.s"
.include "callstds.s"

.global ow_script_haweiland_cargo_hall_trainer_0
.global ow_script_haweiland_cargo_hall_trainer_1
.global ow_script_haweiland_cargo_hall_trainer_2
.global ow_script_haweiland_cargo_hall_trainer_3

ow_script_haweiland_cargo_hall_trainer_0:
    trainerbattlestd 0 0x135 0 str_trainer0_challange str_trainer0_defeat
    loadpointer 0 str_trainer0_defeat
    callstd MSG_FACE
    end
ow_script_haweiland_cargo_hall_trainer_1:
    trainerbattlestd 0 0x136 0 str_trainer1_challange str_trainer1_defeat
    loadpointer 0 str_trainer1_defeat
    callstd MSG_FACE
    end
ow_script_haweiland_cargo_hall_trainer_2:
    trainerbattlestd 0 0x137 0 str_trainer2_challange str_trainer2_defeat
    loadpointer 0 str_trainer2_defeat
    callstd MSG_FACE
    end
ow_script_haweiland_cargo_hall_trainer_3:
    trainerbattlestd 0 0x138 0 str_trainer3_challange str_trainer3_defeat
    loadpointer 0 str_trainer3_defeat
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_trainer0_challange:
    .autostring 34 2 "Das Herz eines Piraten schlägt für die Freiheit!\pAlso steht es uns frei, das zu nehmen, was wir an uns reißen wollen!"
str_trainer0_defeat:
    .autostring 34 2 "Auch eine Niederlage kann einen Piraten nicht in Ketten legen!"
str_trainer1_challange:
    .autostring 34 2 "Seit ich Blackbeards Crew beigetreten bin, kann ich tun und lassen, was immer ich möchte!"
str_trainer1_defeat:
    .autostring 34 2 "Lass mich in Ruhe!\pIch muss mich vor dir nicht rechtfertigen!"
str_trainer2_challange:
    .autostring 34 2 "Bist du auch einer dieser Revolutionäre, die uns für ihre Sache einspannen wollen?\pVergiss es!"
str_trainer2_defeat:
    .autostring 34 2 "Blackbeard wird sich der Revolution nicht anschließen!\pNiemalsDOTS"
str_trainer3_challange:
    .autostring 34 2 "Ist es nicht höchst komfortabel, wenn andere Leute nach den Dingen suchen, die du haben möchtest?\pGenau deswegen sind wir hier!"
str_trainer3_defeat:
    .autostring 34 2 "Der Kapitän weiß genau, was er möchte.\pUnd du wirst ihn nicht davon abhalten, es zu bekommen!"
.elseif LANG_EN
str_trainer0_challange:
    .autostring 34 2 "A pirate's heart only beats for his own freedom!\pSo I am free to take whatever I desire!"
str_trainer0_defeat:
    .autostring 34 2 "A single defeat will never put a pirate into chains!"
str_trainer1_challange:
    .autostring 34 2 "Ever since I joined Blackbeard's crew I can do whatever I like!"
str_trainer1_defeat:
    .autostring 34 2 "Leave me alone!\pI don't have to justify myself in front of you!"
str_trainer2_challange:
    .autostring 34 2 "Are you also one of those reovlutionaries who want to employ us for their cause?\pForget about it!"
str_trainer2_defeat:
    .autostring 34 2 "Blackbeard won't ever join the revolutionary movement!\pNever everDOTS"
str_trainer3_challange:
    .autostring 34 2 "Isn't it most comfortable when other people put effort into searching those things you want to obtain?\pThat's exactly why we're here!"
str_trainer3_defeat:
    .autostring 34 2 "The captain knows exactly what he wants.\pAnd you won't stop him in getting it!"
.endif
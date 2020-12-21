.include "callstds.s"
.include "overworld_script.s"

.global ow_script_tafelberg_lapis_cave_trainer_0
.global ow_script_tafelberg_lapis_cave_trainer_1
.global ow_script_tafelberg_lapis_cave_trainer_2
.global ow_script_tafelberg_lapis_cave_trainer_3
.global ow_script_tafelberg_lapis_cave_trainer_4


ow_script_tafelberg_lapis_cave_trainer_0:
    trainerbattlestd 0x0 0x6b 0x0 str_before0 str_after0
    loadpointer 0x0 str_after0
    callstd MSG_FACE
    end
ow_script_tafelberg_lapis_cave_trainer_1:
    trainerbattlestd 0x0 0x1b6 0x0 str_before1 str_after1
    loadpointer 0x0 str_after1
    callstd MSG_FACE
    end
ow_script_tafelberg_lapis_cave_trainer_2:
    trainerbattlestd 0x0 0x1b7 0x0 str_before2 str_after2
    loadpointer 0x0 str_after2
    callstd MSG_FACE
    end
ow_script_tafelberg_lapis_cave_trainer_3:
    trainerbattlestd 0x0 0x1b8 0x0 str_before3 str_after3
    loadpointer 0x0 str_after3
    callstd MSG_FACE
    end
ow_script_tafelberg_lapis_cave_trainer_4:
    trainerbattlestd 0x0 0x1b9 0x0 str_before4 str_after4
    loadpointer 0x0 str_after0
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_before0:
    .autostring 34 2 "Ein Vogel muss seine Schwingen ausbreiten können!\pIch will mich frei fühlen!"
str_after0:
    .autostring 34 2 "Was ist schon eine Niederlage, wenn in Freiheit lebt?"
str_before1:
    .autostring 34 2 "Meine Eltern haben mir verboten, in Kaskada ins Teehaus zu gehen.\pAlso bin ich ganz einfach weggelaufen!"
str_after1:
    .autostring 34 2 "Na gut, vielleicht sollte ich doch wieder zurück nach Hause gehenDOTS"
str_before2:
    .autostring 34 2 "Was?\nNoch so ein junges Balg?\pDie Jugend von heute weiß wohl gar nicht mehr, welche Bedeutung das Wort Respekt haben sollte."
str_after2:
    .autostring 34 2 "Was für eine Frechheit!\pBehandelt man so etwa einen alten Mann?"
str_before3:
    .autostring 34 2 "Ich war für eine zeitlang die Schülerin des berühmten Arenaleiters Manuel!\pDu weißt ja gar nicht, in was du hier 'rein geraten bist!"
str_after3:
    .autostring 34 2 "Ja gut, ich gebe es zuDOTS\pIch war zu schwach für das erbamlungslose Training eines ArenaleitersDOTS"
str_before4:
    .autostring 34 2 "Mein guter Freund war einmal ein Matrose wie ich.\pDann hat er sich den Blackberad Piraten angeschlossen.\pJetzt musst du meine Wut darüber ausbaden!"
str_after4:
    .autostring 34 2 "Entschuldige bitte, Kindchen.\pIch weiß nicht, was über mich gekommen istDOTS"

.elseif LANG_EN
.endif
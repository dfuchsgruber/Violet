.include "overworld_script.s"
.include "callstds.s"

.global ow_script_route_5_trainer_0
.global ow_script_route_5_trainer_1
.global ow_script_route_5_trainer_2
.global ow_script_route_5_trainer_3
.global ow_script_route_5_trainer_4
.global ow_script_route_5_trainer_5
.global ow_script_route_5_trainer_6
.global ow_script_route_5_trainer_7
.global ow_script_route_5_trainer_8
.global ow_script_route_5_trainer_9
.global ow_script_route_5_twins

ow_script_route_5_trainer_0:
    trainerbattlestd 0 0x16c 0 str_before0 str_after0
    loadpointer 0 str_after0
    callstd MSG_FACE
    end
ow_script_route_5_trainer_1:
    trainerbattlestd 0 0x85 0 str_before_1 str_after_1
    loadpointer 0 str_after_1
    callstd MSG_FACE
    end
ow_script_route_5_trainer_2:
    trainerbattlestd 0 0x86 0 str_before_2 str_after_2
    loadpointer 0 str_after_2
    callstd MSG_FACE
    end
ow_script_route_5_trainer_3:
    trainerbattlestd 0 0x87 0 str_before_3 str_after_3
    loadpointer 0 str_after_3
    callstd MSG_FACE
    end
ow_script_route_5_trainer_4:
    trainerbattlestd 0 0x88 0 str_before_4 str_after_4
    loadpointer 0 str_after_4
    callstd MSG_FACE
    end
ow_script_route_5_trainer_5:
    trainerbattlestd 0 0x8b 0 str_before_5 str_after_5
    loadpointer 0 str_after_5
    callstd MSG_FACE
    end
ow_script_route_5_trainer_6:
    trainerbattlestd 0 0x1d1 0 str_before_6 str_after_6
    loadpointer 0 str_after_6
    callstd MSG_FACE
    end
ow_script_route_5_trainer_7:
    trainerbattlestd 0 0x1d2 0 str_before_7 str_after_7
    loadpointer 0 str_after_7
    callstd MSG_FACE
    end
ow_script_route_5_trainer_8:
    trainerbattlestd 0 0x1d3 0 str_before_8 str_after_8
    loadpointer 0 str_after_8
    callstd MSG_FACE
    end
ow_script_route_5_trainer_9:
    trainerbattlestd 0 0x1d4 0 str_before_9 str_after_9
    loadpointer 0 str_after_9
    callstd MSG_FACE
    end

ow_script_route_5_twins:
    trainerbattledouble 4 0x16d 0 str_befored str_afterd str_cant_battled
    loadpointer 0 str_afterd
    callstd MSG_FACE
    end

.ifdef LANG_GER
str_before0:
    .autostring 34 2 "Mein Leben dreht sich nur um Pokémon!\pEinen Maniac wie mich kannst du gar nicht schlagen!"
str_after0:
    .autostring 34 2 "Wie konntest du mich besiegen?\pIch weiß doch alles über Pokémon!"
str_befored:
    .autostring 34 2 "Meine Schwester und ich können die Sätze derDOTS\pDOTSjeweils anderen beenden.\pOb uns dasDOTS\pDOTSim Kampf etwas nützt?"
str_afterd:
    .autostring 34 2 "Wir habenDOTS\pDOTSverloren, Schwester!"
str_cant_battled:
    .autostring 34 2 "Wir kämpfen nur zu zweit, musst du wissen!"
str_before_1:
    .autostring 34 2 "In diesen Ruinen hier findet man sicherlich viele Schätze!\pAber die gehören alle mir!"
str_after_1:
    .autostring 34 2 "Na gut, wenn du darauf bestehst, kannst du etwas von den Schätzen hier abhaben, denke ich."
str_before_2:
    .autostring 34 2 "Hab etwas Nachsicht mit einem alten Mann, ja?"
str_after_2:
    .autostring 34 2 "Das nennst du Nachsicht?\pDie Jugend heutzutageDOTS"
str_before_3:
    .autostring 34 2 "Ich bin wie geschaffen für das Kämpfen!\pMeine Pokémon werden dich im Handumdrehen besiegt haben!"
str_after_3:
    .autostring 34 2 "Das nennst du einen Kampf?\pIch habe mir nicht einmal wirklich Mühe gegebenDOTS"
str_before_4:
    .autostring 34 2 "Meine Freunde finden meine Pokémon eklig.\pAber das ist mir egal, denn ein Käfer-Pokémon ist unschlagbar!"
str_after_4:
    .autostring 34 2 "W-Was?\nDu hast meine schönen Pokémon besiegt?"
str_before_5:
    .autostring 34 2 "Ich habe mich auf einen Moment wie diesen bestens vorbereitet!\pLos, lass uns kämpfen!"
str_after_5:
    .autostring 34 2 "All die Büffelei umsonstDOTS"
str_before_6:
    .autostring 34 2 "Deine Gedanken sind wie ein offenes Buch.\pJede Taktik, die du dir überlegt hast, ist gegen mich wirklungslos!"
str_after_6:
    .autostring 34 2 "M-Moment!\pIch konnte deine Gedanken wohl nicht richtig hörenDOTS"
str_before_7:
    .autostring 34 2 "Einem Angler wirft man schon einmal abfällige Blicke zu.\pDas macht mich wirklich wütend!"
str_after_7:
    .autostring 34 2 "Das Angeln ist überhaupt nichts, für das man sich schämen müsste!"
str_before_8:
    .autostring 34 2 "Für mich zählt am Ende des Tages, wie viele Pokémon ich aus dem Wasser gezogen habe.\pUnd ich sage dir, heute habe ich wirklich einen Lauf!"
str_after_8:
    .autostring 34 2 "Wie auch immer!\nDiese Niederlage lässt mich heute gänzlich kalt!"
str_before_9:
    .autostring 34 2 "Hey!\nWas fällt dir eine meine Ruhe so zu stören?"
str_after_9:
    .autostring 34 2 "Jetzt bin ich wirklich schlecht gelauntDOTS\pVielen dank auch!"
.elseif LANG_EN
.endif